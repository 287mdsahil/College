#include <stdio.h>
#include <unistd.h>

int main()
{
    float sleepTime;
    int niter;
    printf("Enter the sleep interval in seconds: ");
    scanf("%f", &sleepTime);
    printf("Enter the number of iterations: ");
    scanf("%d",&niter);

    int pid = fork();
    switch (pid)
    {
    case -1:
        printf("Child process creation unsuccessful\n");
        break;

    default:
        for (int i = 0; i < niter; i++)
        {
            printf("PId: %d Iteration: %d\n", pid, i+1);
            sleep(sleepTime);
        }
        break;
    }
    return 0;
}