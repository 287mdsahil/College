#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAXLEN 100
//#define DEBUG

struct Job
{
	int id;
	int priority;
	int arrival_time;

	int next_alloted_runtime;

	//even indices for cpu burst and odd for io bursts
	int bursts[100];

	// no of bursts ( always an even number )
	int nbursts;

	//index of burst till where its executed
	// 0 means its nothing executed
	int executed_index;

	// flag variable, represents the state
	// 0 means waiting
	// 1 means ready
	// 2 means executing
	// 3 means terminated
	int state;
};

struct Job createJob(char jobstr[MAXLEN], int len)
{
    struct Job njob;
#ifdef DEBUG
    printf("\ncreating job:\n");
    printf("jobstr : %s\n",jobstr);
#endif

    njob.id = atoi(strtok(jobstr," "));
    njob.priority = atoi(strtok(NULL," "));
    njob.arrival_time = njob.next_alloted_runtime = atoi(strtok(NULL," "));

    njob.nbursts = 0;
    char *sburst;
    while( (sburst = strtok(NULL, " ") ) != NULL)
    {
	int burst = atoi(sburst);
	njob.bursts[njob.nbursts++] = burst;
    }

#ifdef DEBUG
    printf("id : %d\n",njob.id);
    printf("priority : %d\n",njob.priority);
    printf("arrival_time : %d\n",njob.arrival_time);
    for(int i=0;i<njob.nbursts;i++)
	    printf("%d ",njob.bursts[i]);
    printf("\n");
#endif

    return njob;
}

int readFile(struct Job jobs[MAXLEN])
{
    FILE *fJobProfile;
    fJobProfile = fopen("job_profile.txt", "r");

    char jobstr[MAXLEN];
    char c;
    int ix = 0;
    int jobInd = 0;

    c = fgetc(fJobProfile);
    while (c != EOF)
    {
        if (c == '-')
        {
            jobstr[ix] = '\0';
#ifdef DEBUG
            printf("\ncreated jobstr: %s\n", jobstr);
#endif
            jobs[jobInd++] = createJob(jobstr, ix);
            c = fgetc(fJobProfile);
            c = fgetc(fJobProfile);
            ix = 0;
        }
        else
        {
            jobstr[ix++] = c;
        }
        c = fgetc(fJobProfile);
    }
    return jobInd;
}

int menu()
{
    printf("\nMENU:\n");
    printf("1. FCFS\n");
    printf("2. Non-preemptive Priority Scheduling\n");
    printf("3. Round Robin Scheduling\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void displayResults(struct Job[], int[], int[], int);
int FCFS(struct Job[], int[], int[], int);
int Priority(struct Job[], int[], int[], int);
int RoundRobin(struct Job[], int[], int[], int);

int main()
{
    while (1)
    {
	struct Job jobs[MAXLEN];
	int n_jobs = readFile(jobs);

    	int waiting_times[n_jobs];
    	int turn_around_times[n_jobs];
        int choice = menu();
        switch (choice)
        {
        case 1:
	    FCFS(jobs, waiting_times, turn_around_times, n_jobs);
	    displayResults(jobs, waiting_times, turn_around_times, n_jobs);
	    break;
        case 2:
	    Priority(jobs, waiting_times, turn_around_times, n_jobs);
	    displayResults(jobs, waiting_times, turn_around_times, n_jobs);
            break;
        case 3:
	    RoundRobin(jobs, waiting_times, turn_around_times, n_jobs);
	    displayResults(jobs, waiting_times, turn_around_times, n_jobs);
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}

void displayResults(struct Job jobs[], int waiting_times[], int turn_around_times[], int n_jobs)
{
	for(int i=0;i<n_jobs;i++)
	{
		printf("\nJob id:%d\n", jobs[i].id);
		printf("Waiting time:%d\n", waiting_times[i]);
		printf("Turn around time:%d\n", turn_around_times[i]);
	}
}



// First come first served scheduler
int FCFS(struct Job jobs[], int waiting_times[], int turn_around_times[], int n_jobs)
{
	
	// the ready queue
	struct Queue readyQueue;
	queue_init(&readyQueue);

	// initaite waiting times and turn around times
	for(int i=0;i<n_jobs;i++)
	{
		waiting_times[i] = 0;
		turn_around_times[i] = 0;
	}

	// holds time left for io burst to complete
	int waiting_for_io[n_jobs];
	for(int i=0;i<n_jobs;i++)
		waiting_for_io[i]=0;

	int executed[n_jobs];
	for(int i=0;i<n_jobs;i++)
		executed[i]=0;

	// holds index of job currently executing
	int executing=-1;
	int timeleft = 0;

	// clock
	int t=0;
	while(1)
	{
		//debug
		//printf("time:%d\n",t);
		
		// enqueue the arriving processes
		for(int i=0;i<n_jobs;i++)
			if(jobs[i].next_alloted_runtime == t)
			{
				jobs[i].state = 1;
				queue_enqueue(i,&readyQueue);
			}

		//debug
		//printf("executing :%d timeleft:%d ",executing,timeleft);

		// if no job is being executed
		if(executing == -1)
		{
			//debug
			//printf("executing:%d\n",executing);

			//check the ready queue
			if(!queue_isempty(&readyQueue))
			{
				// check the status of the next process
				if(jobs[queue_head(&readyQueue)].next_alloted_runtime <= t)
				{
					executing = queue_head(&readyQueue);
					jobs[executing].state = 2;
					queue_dequeue(&readyQueue);
					timeleft = jobs[executing].bursts[jobs[executing].executed_index];
				}
			}
		}
		// if job is being executed
		else
		{
			//debug
			//printf("executing:%d timeleft:%d executed_index:%d\n",executing,timeleft,jobs[executing].executed_index);
	
			timeleft--;
			// if current burst is done
			if(timeleft == 0)
			{
				jobs[executing].executed_index++;
				jobs[executing].next_alloted_runtime = t + 1 + jobs[executing].bursts[jobs[executing].executed_index];
				jobs[executing].state = 0;
				if(jobs[executing].executed_index >= jobs[executing].nbursts - 2)
				{
					//terminate
					jobs[executing].state = 3;
					executed[executing] = 1;
					turn_around_times[executing] = 1 + t + jobs[executing].bursts[jobs[executing].executed_index + 1] - jobs[executing].arrival_time;
				}

				//increment io burst index
				jobs[executing].executed_index++;
				executing = -1;
			}
		}


		for(int i=0;i<n_jobs;i++)
			if(i!=executing && jobs[i].state == 1)
				waiting_times[i]++;
		


		//debug
		/*
		printf("executed list: ");
		for(int i=0;i<n_jobs;i++)
		{
			printf("%d ",executed[i]);
		}
		printf("\n");
		*/

		// exit if all jobs executed
		int allExecuted = 1;
		for(int i=0;i<n_jobs;i++)
		{
			if(executed[i]==0)
			{
				allExecuted = 0;
				break;
			}
		}
		if(allExecuted)
			break;

		//if(t>1100)
		//	break;
		//increment clock
		t++;
	}

	return 0;
}



void Priority_queue_enqueue(int val, struct Queue *q, struct Job jobs[])
{
	struct Node *node;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->val = val;
	node->next = NULL;

	struct Node *cur = q->head;
	
	if(queue_isempty(q))
	{
		queue_enqueue(val,q);
		return;
	}
	
	struct Node *curnext = cur->next;
	while( curnext != NULL && jobs[curnext->val].priority <= jobs[val].priority)
	{
		struct Node *dummy = curnext;
		curnext = curnext->next;
		cur = dummy;
	}

	//insertion
	cur->next = node;
	node->next = curnext;
}

// Non preemeptive priority scheduling
int Priority(struct Job jobs[], int waiting_times[], int turn_around_times[], int n_jobs)
{
	
	// the ready queue
	struct Queue readyQueue;
	queue_init(&readyQueue);

	// initaite waiting times and turn around times
	for(int i=0;i<n_jobs;i++)
	{
		waiting_times[i] = 0;
		turn_around_times[i] = 0;
	}

	// holds time left for io burst to complete
	int waiting_for_io[n_jobs];
	for(int i=0;i<n_jobs;i++)
		waiting_for_io[i]=0;

	int executed[n_jobs];
	for(int i=0;i<n_jobs;i++)
		executed[i]=0;

	// holds index of job currently executing
	int executing=-1;
	int timeleft = 0;

	// clock
	int t=0;
	while(1)
	{
		//debug
		//printf("time:%d\n",t);
		
		// enqueue the arriving processes
		for(int i=0;i<n_jobs;i++)
			if(jobs[i].next_alloted_runtime == t)
			{
				jobs[i].state = 1;
				Priority_queue_enqueue(i,&readyQueue,jobs);
			}

		//debug
		//printf("executing :%d timeleft:%d ",executing,timeleft);

		// if no job is being executed
		if(executing == -1)
		{
			//debug
			//printf("executing:%d\n",executing);

			//check the ready queue
			if(!queue_isempty(&readyQueue))
			{
				// check the status of the next process
				if(jobs[queue_head(&readyQueue)].next_alloted_runtime <= t)
				{
					executing = queue_head(&readyQueue);
					jobs[executing].state = 2;
					queue_dequeue(&readyQueue);
					timeleft = jobs[executing].bursts[jobs[executing].executed_index];
				}
			}
		}
		// if job is being executed
		else
		{
			//debug
			//printf("executing:%d timeleft:%d executed_index:%d\n",executing,timeleft,jobs[executing].executed_index);
	
			timeleft--;
			// if current burst is done
			if(timeleft == 0)
			{
				jobs[executing].executed_index++;
				jobs[executing].next_alloted_runtime = t + 1 + jobs[executing].bursts[jobs[executing].executed_index];
				jobs[executing].state = 0;
				if(jobs[executing].executed_index >= jobs[executing].nbursts - 2)
				{
					//terminate
					jobs[executing].state = 3;
					executed[executing] = 1;
					turn_around_times[executing] = 1 + t + jobs[executing].bursts[jobs[executing].executed_index + 1] - jobs[executing].arrival_time;
				}

				//increment io burst index
				jobs[executing].executed_index++;
				executing = -1;
			}
		}


		for(int i=0;i<n_jobs;i++)
			if(i!=executing && jobs[i].state == 1)
				waiting_times[i]++;
		


		//debug
		/*
		printf("executed list: ");
		for(int i=0;i<n_jobs;i++)
		{
			printf("%d ",executed[i]);
		}
		printf("\n");
		*/

		// exit if all jobs executed
		int allExecuted = 1;
		for(int i=0;i<n_jobs;i++)
		{
			if(executed[i]==0)
			{
				allExecuted = 0;
				break;
			}
		}
		if(allExecuted)
			break;

		//if(t>1100)
		//	break;
		//increment clock
		t++;
	}

	return 0;
}



// Round robin scheduling
int RoundRobin(struct Job jobs[], int waiting_times[], int turn_around_times[], int n_jobs)
{
	
	// the ready queue
	struct Queue readyQueue;
	queue_init(&readyQueue);

	// initaite waiting times and turn around times
	for(int i=0;i<n_jobs;i++)
	{
		waiting_times[i] = 0;
		turn_around_times[i] = 0;
	}

	// holds time left for io burst to complete
	int waiting_for_io[n_jobs];
	for(int i=0;i<n_jobs;i++)
		waiting_for_io[i]=0;

	int executed[n_jobs];
	for(int i=0;i<n_jobs;i++)
		executed[i]=0;

	// holds index of job currently executing
	int executing=-1;
	int timeleft = 0;
	int timesliceleft = 0;

	// clock
	int t=0;
	while(1)
	{
		//debug
		//printf("time:%d\n",t);
		
		// enqueue the arriving processes
		for(int i=0;i<n_jobs;i++)
			if(jobs[i].next_alloted_runtime == t)
			{
				jobs[i].state = 1;
				queue_enqueue(i,&readyQueue);
			}

		//debug
		//printf("executing :%d timeleft:%d ",executing,timeleft);

		// if no job is being executed
		if(executing == -1)
		{
			//debug
			//printf("executing:%d\n",executing);

			//check the ready queue
			if(!queue_isempty(&readyQueue))
			{
				// check the status of the next process
				if(jobs[queue_head(&readyQueue)].next_alloted_runtime <= t)
				{
					executing = queue_head(&readyQueue);
					jobs[executing].state = 2;
					queue_dequeue(&readyQueue);
					timeleft = jobs[executing].bursts[jobs[executing].executed_index];
					timesliceleft = 20;
				}
			}
		}
		// if job is being executed
		else
		{
			//debug
			//printf("executing:%d timeleft:%d executed_index:%d\n",executing,timeleft,jobs[executing].executed_index);
	
			timeleft--;
			timesliceleft--;
			// if current burst is done
			if(timeleft == 0)
			{
				jobs[executing].executed_index++;
				jobs[executing].next_alloted_runtime = t + 1 + jobs[executing].bursts[jobs[executing].executed_index];
				jobs[executing].state = 0;
				if(jobs[executing].executed_index >= jobs[executing].nbursts - 2)
				{
					//terminate
					jobs[executing].state = 3;
					executed[executing] = 1;
					turn_around_times[executing] = 1 + t + jobs[executing].bursts[jobs[executing].executed_index + 1] - jobs[executing].arrival_time;
				}

				//increment io burst index
				jobs[executing].executed_index++;
				executing = -1;
			}
			else if(timesliceleft == 0)
			{
				jobs[executing].bursts[jobs[executing].executed_index] = jobs[executing].bursts[jobs[executing].executed_index] - 20;
				jobs[executing].next_alloted_runtime = t + 1;
				jobs[executing].state = 1;

				//increment io burst index
				executing = -1;

			}
		}


		for(int i=0;i<n_jobs;i++)
			if(i!=executing && jobs[i].state == 1)
				waiting_times[i]++;
		


		//debug
		/*
		printf("executed list: ");
		for(int i=0;i<n_jobs;i++)
		{
			printf("%d ",executed[i]);
		}
		printf("\n");
		*/

		// exit if all jobs executed
		int allExecuted = 1;
		for(int i=0;i<n_jobs;i++)
		{
			if(executed[i]==0)
			{
				allExecuted = 0;
				break;
			}
		}
		if(allExecuted)
			break;

		//if(t>1100)
		//	break;
		//increment clock
		t++;
	}

	return 0;
}
