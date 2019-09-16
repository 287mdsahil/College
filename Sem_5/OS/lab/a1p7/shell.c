#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showPrompt()
{
    printf("\x1B[32mBcseIII\x1B[34m@\x1B[31mSahil $ \x1B[0m");
}

void getCommand(char str[100])
{
    scanf("%[^\n]%*c", str);
};

int main()
{
    system("clear");
    while (1)
    {
        showPrompt();
        char command[100];
        getCommand(command);
        if(strcmp(command,"exit")==0)
            break;
        else
        {

        }
        
    }
    return 0;
}