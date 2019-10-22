#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void showPrompt()
{
    printf("\x1B[32mBcseIII\x1B[34m@\x1B[31mSahil $ \x1B[0m");
}

void getCommand(char str[100])
{
    scanf("%[^\n]%*c", str);
};

void parseCommand(char str[100])
{
    char *command;
    command = strtok (str," ");

    if(strcmp("exit",command)==0)
    {
        exit(0);
    }
    char *pch;
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }
}

int main()
{
    system("clear");
    while (1)
    {
        showPrompt();
        char command[100];
        getCommand(command);
        parseCommand(command);
    }
    return 0;
}