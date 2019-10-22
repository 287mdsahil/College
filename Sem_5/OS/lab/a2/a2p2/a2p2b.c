#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>    /* For O_* constants */

int main()
{

    // const char *shmname = "a2p2b";
    // int memcheck = shm_open(shmname, O_RDWR | O_CREAT, 0777);
    // if (memcheck == -1)
    // {
    //     printf("Unable to create shared memory!\n");
    //     exit(1);
    // }
    // shm_unlink(shmname);

    //sem_t *semaphore = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    int *iterLock = mmap(NULL, sizeof(int), PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *iterLock = -1;

    //initialize semaphore
    //sem_init(semaphore,1,1);
    sem_t *semaphore = sem_open("a2p2b_semaphore", O_CREAT, 0644, 1);

    //initialize iterLock

    float sleepTime;
    int niter;
    printf("Enter the sleep interval in seconds: ");
    scanf("%f", &sleepTime);
    printf("Enter the number of iterations: ");
    scanf("%d", &niter);

    int pid = fork();
    switch (pid)
    {
    case -1:
        printf("Child process creation unsuccessful\n");
        break;

    case 0:
        for (int i = 0; i < niter; i++)
        {
            (*iterLock)++;
            sem_t *sem = sem_open("a2p2b_semaphore", 0);

            sem_wait(sem);

            printf("Iteration:%d\tPId:%d\n", i + 1, pid);
            sleep(sleepTime);

            sem_post(sem);
        }
        break;

    default:
        for (int i = 0; i < niter; i++)
        {
            sem_t *sem = sem_open("a2p2b_semaphore", 0);
            int flag = 0;

            if (*iterLock < i)
            {
                sem_wait(sem);
                flag = 1;
            }

            printf("Iteration:%d\tPId:%d\n", i + 1, pid);
            sleep(sleepTime);

            if (flag)
                sem_post(sem);
        }
        break;
    }
    return 0;
}