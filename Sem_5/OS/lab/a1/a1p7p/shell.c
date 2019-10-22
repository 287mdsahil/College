#include <dirent.h>
#include <pwd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "text-styles.h"


#define SCREEN_CLEARING_TEXT "\x1b[H\x1b[2J"
#define SHELL_ARGS_ERROR_CODE -4
#define SHELL_EXEC_SUCCESS_CODE -5
#define SHELL_EXEC_FAILURE_CODE -9
#define SHELL_FORK_ERROR_CODE -10
#define SHELL_EXIT_CODE -1234
#define TOKEN_DELIMITERS " \t\r\n"


char** tokenize_string(char *str);
void   free_token_list(char **token_list);
void   show_prompt(char *user, char *pwd);
void   show_error(char *msg);
void   show_warning(char *msg);
char*  read_line(void);
int    delegate_utlity(char **token_list);
int    execute_builtin(char **arg_list, bool background, int (*func)(char**, bool));
int    execute_bash_builtin(char **arg_list, bool background);
int    shell_loop(void);

int    _builtin_create_dir(char **arg_list, bool background);
int    _builtin_edit_file(char **arg_list, bool background);
char** _get_file_info(char *filename);
void   _free_file_info_list(char **file_info_list);
int    _builtin_info_one_file(char *filename);
int    _builtin_info_all_files();
int    _builtin_info(char **arg_list, bool background);
int    _builtin_exit(char **arg_list, bool background);
int    _builtin_clear(char **arg_list, bool background);


int NUM_BUILTIN_CMD = 5;
char *BUILTIN_CMD_NAMES[] = {"dirnew", "editfile", "info", "exitnewshell", "clrscr"};
int (*BUILTIN_FUNC[])(char**, bool) = {&_builtin_create_dir, &_builtin_edit_file, &_builtin_info, &_builtin_exit, &_builtin_clear};


char** tokenize_string(char *str) {
    int idx, max_size;
    char *rem, *token, *to_free, **token_list;
    to_free = rem = strdup(str);
    idx = 0; max_size = 2; token_list = malloc(max_size * sizeof(char*));
    
    if (!token_list) return NULL;    

    while ( (token = strsep(&rem, TOKEN_DELIMITERS)) ) {
        if (token[0] == '\0') continue; // empty

        // resize if required
        if (idx == max_size) {
            max_size *= 2;
            token_list = realloc(token_list, max_size * sizeof(char*));
            if (!token_list) return NULL;
        }

        token_list[idx++] = strdup(token);
    }

    // resize to required size + 1
    token_list = realloc(token_list, (idx+1) * sizeof(char*));
    if (!token_list) return NULL;
    token_list[idx] = NULL; // terminate by NULL

    free(to_free);

    return token_list;
}

void free_token_list(char **token_list) {
    if (!token_list) return;

    char *to_free; int i = 0;
    while ((to_free = token_list[i++])) {
        free(to_free);
    }
    free(token_list);
}

void show_prompt(char *user, char *pwd) {
    printf("%s%sBCSE III@%s%s%s:%s%s%s$ ", ANSI_STYLE_BOLD, ANSI_COLOR_GREEN, user, ANSI_RESET, 
                                           ANSI_STYLE_BOLD, ANSI_COLOR_BLUE, pwd, ANSI_RESET);
}

void show_error(char *msg) {
    printf("%s%s[ERR] %s%s\n", ANSI_STYLE_BOLD, ANSI_COLOR_RED, msg, ANSI_RESET);
}

void show_warning(char *msg) {
    printf("%s%s[WARN] %s%s\n", ANSI_STYLE_BOLD, ANSI_COLOR_YELLOW, msg, ANSI_RESET);
}

char* read_line(void) {
    char *buffer = NULL;
    size_t len = 0;
    ssize_t exit_code = getline(&buffer, &len, stdin);
    if (exit_code == -1) {
        free(buffer);
        buffer = NULL;
    }
    return buffer;
}

int delegate_utility(char **token_list) {
    if (!token_list || !token_list[0]) {
        return SHELL_ARGS_ERROR_CODE;
    }
    
    // TODO: make this part a function
    // check last token for presence of '&' (background execution flag)
    // NULL it out if present, and set background var to true
    int i; bool background = false; for (i = 0; token_list[i]; ++i); --i;
    if (strcmp(token_list[i], "&") == 0) {
        free(token_list[i]); token_list[i] = NULL; background = true;
    }

    if (!token_list[0]) {
        return SHELL_ARGS_ERROR_CODE;
    }

    int exit_code; // bool match = false;
    // check with builtins
    for (i = 0; i < NUM_BUILTIN_CMD; ++i) {
        if (strcmp(BUILTIN_CMD_NAMES[i], token_list[0]) == 0) {
            // match = true;
            exit_code = execute_builtin(token_list, background, BUILTIN_FUNC[i]);
            return exit_code;
        }
    }

    // others i.e. bash builtins
    exit_code = execute_bash_builtin(token_list, background);
    return exit_code;
}

int execute_builtin(char **arg_list, bool background, int (*func)(char**, bool)) {
    int exit_code = func(arg_list, background);
    return exit_code;
}

int execute_bash_builtin(char **arg_list, bool background) {   
    int exit_code;  

    pid_t pid_child = fork();

    if (pid_child == -1) {
        show_warning("Could not create child thread");
        return SHELL_FORK_ERROR_CODE;
    }
    else if (pid_child == 0) {
        if (!background) {
            exit_code = execvp(arg_list[0], arg_list);
            if (exit_code == -1) {
                show_warning("Could not execute command, SIGKILL initiated");
            }
            kill(getpid(), SIGKILL);
        }
        else {
            pid_t pid_grandchild = fork();

            if (pid_grandchild == -1) { show_warning("Could not create grandchild thread, SIGKILL initiated"); }
            else if (pid_grandchild == 0) { 
                exit_code = execvp(arg_list[0], arg_list);
                if (exit_code == -1) {
                    show_warning("Could not execute command, SIGKILL initiated");
                }
                kill(getpid(), SIGKILL);
            }
            kill(getpid(), SIGKILL); 
        }
    }
    else {
        waitpid(pid_child, NULL, 0);
    }
    return SHELL_EXEC_SUCCESS_CODE;
}

int shell_loop(void) {
    int exit_code;
    char *user, *pwd, *line, **token_list;

    // TODO: try to use POSIX functions instead of env vars
    user = getenv("USER"); pwd = getenv("PWD");
    
    do {
        show_prompt(user, pwd);
        line = read_line();

        if (!line) {
            show_error("Could not read from STDIN");
            return EXIT_FAILURE;
        }

        token_list = tokenize_string(line);
        
        if (!token_list) {
            show_error("Could not allocate memory for token list");
            free(line);
            return EXIT_FAILURE;        
        }

        exit_code = delegate_utility(token_list);
        // exit code handler ?

        // free line, token_list
        free(line); line = NULL; 
        free_token_list(token_list); token_list = NULL;
    } while (exit_code != SHELL_EXIT_CODE);

    return EXIT_SUCCESS;
}

int _builtin_create_dir(char **arg_list, bool background) {
    if (!arg_list[1] || arg_list[2]) {
        show_warning("[dirnew] requires exactly 1 argument");
        return SHELL_EXEC_FAILURE_CODE;    
    }
    
    int exit_code;
    if (!background) {
        exit_code = mkdir(arg_list[1], 0700);
        if (exit_code == -1) {
            show_warning("Could not create new directory");
            return SHELL_EXEC_FAILURE_CODE;
        }
        else {
            return SHELL_EXEC_SUCCESS_CODE;
        }
    }

    pid_t pid_child = fork();

    if (pid_child == -1) {
        show_warning("Could not create child thread");
        return SHELL_FORK_ERROR_CODE;
    }
    else if (pid_child == 0) {
        pid_t pid_grandchild = fork();

        if (pid_grandchild == -1) { show_warning("Could not create grandchild thread, SIGKILL initiated"); }
        else if (pid_grandchild == 0) {
            exit_code = mkdir(arg_list[1], 0700);
            if (exit_code == -1) {
                show_warning("Could not create new directory, SIGKILL initiated");
            }
            kill(getpid(), SIGKILL);
        }
        kill(getpid(), SIGKILL);
    }
    else {
        waitpid(pid_child, NULL, 0);
    }

    return SHELL_EXEC_SUCCESS_CODE;
}

int _builtin_edit_file(char **arg_list, bool background) {
    if (arg_list[1] && arg_list[2]) {
        show_warning("[editfile] takes either 1 argument or no arguments");
        return SHELL_EXEC_FAILURE_CODE;
    }
    if (background) {
        show_warning("Cannot run [editfile] in background mode");
        return SHELL_EXEC_FAILURE_CODE;
    }
    free(arg_list[0]);
    arg_list[0] = strdup("vi");
    int exit_code = execute_bash_builtin(arg_list, background);
    return exit_code;
}

char** _get_file_info(char *filename) {
    if (!filename) return NULL;

    if (access(filename, F_OK) == -1) return NULL;

    char actualpath[1024];
    char *ptr;
    ptr = realpath(filename, actualpath);

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    char date[10];
    strftime(date, 20, "%d-%m-%y", localtime(&(st.st_mtime)));

    uid_t owner = st.st_uid;
    struct passwd *pwd;
    pwd = getpwuid(owner);

    // printf("Absolute path: %s\n", ptr);
    // printf("Size of file: %d bytes\n", size);
    // printf("Last Modified: %s\n", date);
    // printf("Owner: %s\n", pwd->pw_name);

    char **info = malloc(4 * sizeof(char*));
    info[0] = strdup(pwd->pw_name);
    char size_str[100]; sprintf(size_str, "%d", size); info[1] = strdup(size_str);
    info[2] = strdup(date);
    info[3] = strdup(ptr);
    return info;
}

void _free_file_info_list(char **file_info_list) {
    if (!file_info_list) return;

    char *to_free; int i = 0;
    while ((to_free = file_info_list[i++])) {
        free(to_free);
    }
    free(file_info_list);
}

int _builtin_info_one_file(char *filename) {
    char **info = _get_file_info(filename);

    if (info == NULL) {
        show_warning("Could not retrieve file details");
        return SHELL_EXEC_FAILURE_CODE;
    }

    printf("%-30s%-20s%-20s%s\n", "Owner Name", "Size(in bytes)", "Last Modified", "Absolute Path");
    printf("%-30s%-20s%-20s%s\n", info[0], info[1], info[2], info[3]);
    _free_file_info_list(info);
    return SHELL_EXEC_SUCCESS_CODE;
}

int _builtin_info_all_files() {    
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    printf("%-30s%-20s%-20s%s\n", "Owner Name", "Size(in bytes)", "Last Modified", "Absolute Path");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type != DT_REG) continue;

            char **info = _get_file_info(dir->d_name);
            if (info) {
                printf("%-30s%-20s%-20s%s\n", info[0], info[1], info[2], info[3]);
                _free_file_info_list(info);
            }
            else {
                show_warning("Could not retrieve file details");
            }
        }
        closedir(d);
        return SHELL_EXEC_SUCCESS_CODE;
    }
    return SHELL_EXEC_FAILURE_CODE;
}

int _builtin_info(char **arg_list, bool background) {
    if (arg_list[1] && arg_list[2]) {
        show_warning("[info] takes either 1 argument or no arguments");
        return SHELL_EXEC_FAILURE_CODE;
    }

    int exit_code;

    // info for single file
    if (arg_list[1]) {
        if (!background) {
            exit_code = _builtin_info_one_file(arg_list[1]);
            return exit_code;
        }
        
        pid_t pid_child = fork();
        if (pid_child == -1) {
            show_warning("Could not create child thread");
            return SHELL_FORK_ERROR_CODE;
        }
        else if (pid_child == 0) {
            pid_t pid_grandchild = fork();

            if (pid_grandchild == -1) { show_warning("Could not create grandchild thread, SIGKILL initiated"); }
            else if (pid_grandchild == 0) {
                exit_code = _builtin_info_one_file(arg_list[1]);
                if (exit_code != SHELL_EXEC_SUCCESS_CODE) {
                    show_warning("Could not create display file details, SIGKILL initiated");
                }
                kill(getpid(), SIGKILL);
            }
            kill(getpid(), SIGKILL);
        }
        else {
            waitpid(pid_child, NULL, 0);
            return SHELL_EXEC_SUCCESS_CODE;
        }
    }

    // info for all files
    if (!background) {
        exit_code = _builtin_info_all_files();
        return exit_code;
    }

    pid_t pid_child = fork();
    if (pid_child == -1) {
        show_warning("Could not create child thread");
        return SHELL_FORK_ERROR_CODE;
    }
    else if (pid_child == 0) {
        pid_t pid_grandchild = fork();

        if (pid_grandchild == -1) { show_warning("Could not create grandchild thread, SIGKILL initiated"); }
        else if (pid_grandchild == 0) {
            exit_code = _builtin_info_all_files();
            if (exit_code != SHELL_EXEC_SUCCESS_CODE) {
                show_warning("Could not create display file details, SIGKILL initiated");
            }
            kill(getpid(), SIGKILL);
        }
        kill(getpid(), SIGKILL);
    }
    else {
        waitpid(pid_child, NULL, 0);
        return SHELL_EXEC_SUCCESS_CODE;
    }

    return SHELL_EXEC_SUCCESS_CODE;
}

int _builtin_exit(char **arg_list, bool background) {
    if (arg_list[1]) {
        show_warning("[exitnewshell] does not accept arguments, arguments ignored");    
    }
    if (background) {
        show_warning("Cannot run [exitnewshell] in background mode");
        return SHELL_EXEC_FAILURE_CODE;
    }
    return SHELL_EXIT_CODE;
}

int _builtin_clear(char **arg_list, bool background) {
    if (background) {
        show_warning("Cannot run [clrscr] in background mode");
        return SHELL_EXEC_FAILURE_CODE;
    }
    printf(SCREEN_CLEARING_TEXT);
    return SHELL_EXEC_SUCCESS_CODE;
}

int main(void) {
    int exit_code = shell_loop();

    return exit_code;
}