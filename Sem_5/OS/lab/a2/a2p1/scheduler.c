#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
//#define DEBUG

struct Job
{
    int id;
    int priority;
    int arrival_time;
    int n_cpu_bursts;
    int n_io_bursts;
    int cpu_bursts[MAXLEN];
    int io_bursts[MAXLEN];
};

void printjob(struct Job job)
{
    printf("\nid : %d\n", job.id);
    printf("priority : %d\n", job.priority);
    printf("arrival_time : %d\n", job.arrival_time);
    printf("no of cpu busts : %d\n", job.n_cpu_bursts);
    printf("no of io busts : %d\n", job.n_io_bursts);

    printf("cpu bursts : ");
    for (int i = 0; i < job.n_cpu_bursts; i++)
        printf("%d ", job.cpu_bursts[i]);
    printf("\n");

    printf("io bursts : ");
    for (int i = 0; i < job.n_io_bursts; i++)
        printf("%d ", job.io_bursts[i]);
    printf("\n");
}

struct Job createJob(char jobstr[MAXLEN], int n)
{
    struct Job job;

    char *x = strtok(jobstr, " ");
    sscanf(x, "%d", (&job.id));

    x = strtok(NULL, " ");
    sscanf(x, "%d", (&job.priority));

    x = strtok(NULL, " ");
    sscanf(x, "%d", (&job.arrival_time));

    int cio = 0;
    job.n_cpu_bursts = 0;
    job.n_io_bursts = 0;
    while (1)
    {
        char *c = strtok(NULL, " ");
        if (c == NULL)
            break;
        else if (cio == 0)
        {
            cio = 1;
            job.cpu_bursts[job.n_cpu_bursts++] = atoi(c);
        }
        else if (cio == 1)
        {
            cio = 0;
            job.io_bursts[job.n_io_bursts++] = atoi(c);
        }
    }
    return job;
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
            printf("%s\n", jobstr);
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

void FCFS(struct Job jobs[MAXLEN], int waiting_times[], int turn_around_times[], int n_jobs)
{

    int job_executed[n_jobs];
    for (int i = 0; i < n_jobs; i++)
        job_executed[i] = 0;

    int time = 0;

    while (1)
    {
        //index of the next job to be performed
        int job_index;

        //check if any jobs are left
        int jobs_left_status = 0;
        for (int i = 0; i < n_jobs; i++)
            if (job_executed[i] == 0)
            {
                jobs_left_status = 1;
                job_index = i;
                break;
            }

        //if no jobs are left break
        if (jobs_left_status == 0)
            break;

        //else find the next unexecuted job with the least arrival time
        for (int i = 0; i < n_jobs; i++)
            if (job_executed[i] == 0 && jobs[i].arrival_time < jobs[job_index].arrival_time)
                job_index = i;

        //execute the job
        waiting_times[job_index] = time - jobs[job_index].arrival_time;
        job_executed[job_index] = 1;
        for (int i = 0; i < jobs[job_index].n_cpu_bursts; i++)
            time += jobs[job_index].cpu_bursts[i];
        for (int i = 0; i < jobs[job_index].n_io_bursts; i++)
            time += jobs[job_index].io_bursts[i];
        turn_around_times[job_index] = time - jobs[job_index].arrival_time;
    }
    return;
}

void printResults(struct Job jobs[], int waiting_times[], int turn_around_times[], int n_jobs)
{
    printf("\nRESULTS-------------------------\n");
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for (int i = 0; i < n_jobs; i++)
    {
        printf("\nId: %d\nWaiting Time: %d\nTurnaround Time: %d\n", jobs[i].id, waiting_times[i], turn_around_times[i]);
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turn_around_times[i];
    }

    avg_waiting_time /= n_jobs;
    avg_turnaround_time /= n_jobs;

    printf("\n");
    printf("Average waiting time: %f\n",avg_waiting_time);
    printf("Average turnaround time: %f\n",avg_turnaround_time);
    printf("\n------------------------------------\n");
}

int main()
{
    struct Job jobs[MAXLEN];
    int n_jobs = readFile(jobs);

    for (int i = 0; i < n_jobs; i++)
        printjob(jobs[i]);

    int waiting_times[n_jobs];
    int turn_around_times[n_jobs];

    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            FCFS(jobs, waiting_times, turn_around_times, n_jobs);
            printResults(jobs, waiting_times, turn_around_times, n_jobs);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}