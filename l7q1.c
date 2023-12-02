#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t semaphore;

int count = 0;

void* process(void *tid){
    // Entry Section
    int id = *((int*)tid);
    while(count<10)
    {
    sem_wait(&semaphore);
    // Critical Section
    count++;
    printf("Process %d entered critical section.\n", id);
    printf("Count = %d\n", count);
    // Exit Section
    sem_post(&semaphore);
    usleep(100000);
    }
    return NULL;
}

int main(){
    sem_init(&semaphore, 0, 1);

    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t1, NULL, process, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore);
    return 0;
}