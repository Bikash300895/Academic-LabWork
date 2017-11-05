#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS	4

struct data
{	
	int	thread_id;
	int start;
	int end;
	
};

struct data d[NUM_THREADS+2];

void *BusyWork(void *t)
{
    int i;
    long tid;
    double result=0.0;
    //sleep(1);

    struct data *d;
    d = (struct data *) t;

    //tid = (struct data)t;
    printf("Thread %d starting...\n",d->thread_id);
    for (i=d->start; i<d->end; i++)
    {
        result = result + i;
    }
    printf("Thread %d done. Result = %lf\n",d->thread_id, result);
    pthread_exit((void*) &d);
}

int main (int argc, char *argv[])
{
    pthread_t thread[NUM_THREADS];
    pthread_attr_t attr;
    int rc;
    long t;
    void *status;

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(t=1; t<=NUM_THREADS; t++)
    {
    	d[t-1].thread_id = t-1;
    	d[t-1].start = t * 10 + 1;
    	d[t-1].end = d[t-1].start + 10;

        printf("Main: creating thread %ld\n", t);
        rc = pthread_create(&thread[t], &attr, BusyWork, (void *)&d[t-1]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    /* Free attribute and wait for the other threads */
    pthread_attr_destroy(&attr);
    for(t=0; t<NUM_THREADS; t++)
    {
        rc = pthread_join(thread[t], &status);
        if (rc)
        {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
    }
    printf("Main: program completed. Exiting.\n");
    //pthread_exit(NULL);
}

