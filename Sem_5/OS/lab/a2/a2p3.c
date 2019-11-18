#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<semaphore.h>
#include<sys/stat.h>
#include<fcntl.h>
typedef struct shared_buffer{
	int arr[25];
	int pid[25];
	int aStart;
	int aEnd;
	int total;
} ShBuf;

void produce(ShBuf *samp)
{	
	int temp=(rand()%80)+1;
	samp->arr[samp->aEnd%25]=temp;
	printf("produced %d at index %d\n",temp,samp->aEnd);
	samp->pid[samp->aEnd%25]=getpid();
	(samp->aEnd)=((samp->aEnd)+1)%25;
	sleep(1);

	sem_t *sem = sem_open("a2p3", 0);
	sem_post(sem);
}

void consume(ShBuf *samp)
{
	sem_t *sem = sem_open("a2p3",0);
	sem_wait(sem);
	
	sleep(1);
	printf("consumed %d at index %d\n",samp->arr[samp->aStart],samp->aStart);
	samp->total = samp->total + samp->arr[samp->aStart];
	(samp->aStart)=((samp->aStart)+1)%25;
}

void execution(ShBuf *samp,int p,int c)
{
	pid_t pr=fork();
	if(pr == 0)
	{
		sem_open("a2p3", O_CREAT, 0644, 0);
		pid_t pchild = fork();
		//create producers
		if(pchild==0)
		{
			for(int i=0;i<p;i++)
			{
				pid_t pchildchild = fork();
				if(pchildchild==0)
				{
					srand(getpid());
					produce(samp);
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}
			exit(0);
		}
		//create consumers
		else
		{

			for(int i=0;i<c;i++)
			{
				pid_t pchildchild = fork();
				if(pchildchild==0)
				{
					consume(samp);
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}

		}
		int status = 0;
		pid_t wpid;
		while ((wpid = wait(&status)) > 0);
		exit(0);
	}
	else
	{
		// wait for child processes to exit
		int status = 0;
		pid_t wpid;
		while ((wpid = wait(&status)) > 0);
		sem_unlink("a2p3");
	}
}


int main()
{
	int prod,cons;
	time_t t;
	srand(t);
	
	printf("No. of Producers: ");
	scanf("%d",&prod);
	printf("No. of Consumers: ");
	scanf("%d",&cons);
	
	ShBuf *sample;
	int shmid_samp=shmget(262,sizeof(ShBuf),0666|IPC_CREAT);
	if(shmid_samp==-1)
	{
		perror("Shared Memory");
		return 1;
	}
	
	sample=shmat(shmid_samp,NULL,0);
	if(sample==(void*)-1)
	{
		perror("Shared Memory Attach");
		return 1;
	}
	
	//sample->aStart = 0;
	//sample->aEnd = 0;
	execution(sample,prod,cons);

	printf("\n\nTotal Value by Consumers: %d\n",sample->total);
	shmdt(sample);
	shmctl(shmid_samp,IPC_RMID,NULL);
}
