#include <stdio.h> 
#include <stdlib.h>
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
  
sem_t mutex,wrt,*s1,*s2; 
int *a;
int *reader;


void reads(void* arg) 
{ 
    sem_wait(&mutex); 
    *reader++;
    sem_post(&mutex);

    if(*reader==1)
        sem_wait(&wrt);

    printf("Read Process: a=%d\n",*a);
    sleep(2);

    sem_wait(&mutex);
    *reader--;
    sem_post(&mutex); 
    
    if(*reader==0)
        sem_post(&wrt);
}
void writer(void* arg) 
{ 
    sem_wait(&wrt);
    sem_wait(&mutex);
    printf("Writter running\n");
    (*a)++;
    sleep(1);
    sem_post(&wrt); 
    sem_post(&mutex);
}


int main() 
{ 
    printf("Enter no of readers:");
    int r;
    scanf("%d",&r);
    printf("Enter no of  writers:");
    int w;
    scanf("%d",&w);
    
    void* ptr=mmap(NULL,2*sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,0,0);
    void* ptr2=mmap(NULL,2*sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,0,0);
    
    a=ptr;
    printf("Enter a value:");
    scanf("%d",a);
    printf("Inital value of a=%d\n",*a);
    reader=ptr+1;
    *reader=0;

    s1=ptr2;
    s2=ptr2+1;
    mutex=*s1;
    wrt=*s2;

    if(sem_init(&mutex,1,1)!=0)
        printf("Error");
    if(sem_init(&wrt,1,1)!=0)
        printf("Error");

    pid_t pid[r];
    pid_t pid_wrt[w];
      
    printf("----------------------------------\n");
    if(fork()==0)
    {
        for(int i=0;i<r;i++)
        {
            pid[i]=fork();
            if(pid[i]==0)
            {
                reads(NULL);
                exit(0);
            }
            else if(pid[i]>0)
            {
                wait(NULL);
            }
            else
            {
                printf("Fork Failed");
		exit(0);
            } 
        }
	// exit the child of the main mother
	exit(0);
    }
    else
    {       
        for(int i=0;i<w;i++)
        {
            pid_wrt[i]=fork();
            if(pid_wrt[i]==0)
            {
                writer(NULL);
                exit(0);
            }
            else if(pid_wrt[i]>0)
            {
                wait(NULL);
            }
            else
            {
                printf("Fork Failed");
		exit(0);
            } 
        }
    }
    int status1=0;
    int status2=0;
    int pidp;

    while((pidp = waitpid(-1, &status1,0)) != -1);

    printf("----------------------------------\n");
    printf("Final value of a=%d\n",(*a));
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
