#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	6

char *messages[NUM_THREADS];

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;

    Sleep(1);
printf("Thread %d: %s\n", tid, messages[tid]);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    messages[0] = "Hello World00";
    messages[1] = "Hello World11";
    messages[2] = "Hello World22";

    messages[3] = "Hello World33";
    messages[4] = "Hello World44";
    messages[5] = "Hello World55";

    for(t=0; t<NUM_THREADS; t++)
    {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
