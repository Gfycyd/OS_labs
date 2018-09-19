//
// Created by Катя on 19.09.2018.
//
#include <pthread.h>
#include <stdio.h>
void *threadFunc(void *arg)
{
    int i = (int) arg;
    printf("Thread: %i\n", i);
    pthread_exit(0);
    return NULL;
}

void main(void)
{
    int n = 8;
    pthread_t pth[n];	// this is our thread identifier
    int i = 0;
    while(i < 8)
    {
        pthread_create(&pth[i],NULL,threadFunc,(void *) i);
        pthread_join(pth[i],NULL);
        i++;
    }
}