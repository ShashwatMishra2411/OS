#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;

int rc = 0;
int shared = 0;
int count = 100;

void* writer(void* wid){
    int id = *((int*)wid);
    while(count >= 0){
        sem_wait(&wrt);
    shared++;
    printf("Writer %d modified value to %d\n", id, shared);
    sem_post(&wrt);
    printf("Writer %d leaves\n", id);
    count --;
    // usleep(100000);
    }
    return NULL;
}

void* reader(void* rid){
    int id = *((int*)rid);
    while(count >= 0){
        sem_wait(&mutex);
        rc++;
        if(rc == 1)
        sem_wait(&wrt);
        sem_post(&mutex);
        printf("Reader %d read value %d\n", id, shared);
        sem_wait(&mutex);
        rc--;
        printf("Reader %d leaves\n", id);
        if(rc == 0)
        sem_post(&wrt);
        sem_post(&mutex);
        count --;
        // usleep(200000);
    }
    
    return NULL;
}

int main(){
    int nr, nw;
    printf("Enter number of readers: ");
    scanf("%d", &nr);
    printf("Enter number of writers: ");
    scanf("%d", &nw);
    pthread_t readers[nr], writers[nw];
    int reader_ids[nr], writer_ids[nw];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (int i = 0; i < nr; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < nw; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for threads to finish (in practice, you may need to use a signal to terminate)
    for (int i = 0; i < nr; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < nw; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}