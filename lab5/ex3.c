#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 77

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void* consumer(void*);
void* producer(void*);

void* producer(void *t)
{
    int i;
    for (i=0; i<MAX; i++) {
        printf("In producer count is %d\n", count);

        pthread_mutex_lock(&count_mutex);
        count++;
        if (count == MAX) {
            pthread_cond_signal(&count_threshold_cv);
        }
        
        pthread_mutex_unlock(&count_mutex);
    }
    pthread_exit(NULL);
}

void* consumer(void *t)
{
    pthread_mutex_lock(&count_mutex);
    while (count<MAX) {
        pthread_cond_wait(&count_threshold_cv, &count_mutex);
        printf("In conusmer count is %d\n", count);

    }
    printf("full stack count is %d\n", count);
    count += 125;
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t con, pro;
    
    pthread_create(&con, NULL, consumer, NULL);
    pthread_create(&pro, NULL, producer, NULL);
    
    pthread_join(con, NULL);
    pthread_join(pro, NULL);
    return 0;
}
