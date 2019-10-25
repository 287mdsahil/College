#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int producer();
int consumer();

int main()
{
    int p, c;
    printf("Enter the number of producers: ");
    scanf("%d", &p);
    printf("Enter the number of consumers: ");
    scanf("%d", &c);

    //validate p and c
    if (p < 1 || c < 1)
    {
        printf("No of producers and consumers should be >= 1\n");
        exit(0);
    }

    // divide into producers and consumers (create 1 producer and 1 consumer)
    for(int i=1;i<2;i++)
    {
        int pid = fork();
        printf("%d %d\n",getpid(),pid);
    }
    // switch (pid)
    // {
    // case -1:
    //     printf("Unable to create child process\n");
    //     exit(0);

    // //child process
    // case 0:
    // {
    //     //make producers
    //     for(int i=1;i<p;i++)
    //     {

    //     }
    //     break;
    // }

    // //parent process
    // default:
    // {
    //     //make consumers
    //     for(int i=1;i<c;i++)
    //     {

    //     }
    //     break;
    // }
    // }

    return 0;
}