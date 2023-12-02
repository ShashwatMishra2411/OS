#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;
int stock = 0;
int count  = 100;
int rc = 0;

void* view(void* vid){
    int id = *((int*)vid);
    while(count>=0){
        sem_wait(&mutex);
        rc++;
        if(rc == 1)
        sem_wait(&wrt);
        sem_post(&mutex);

        printf("Person P%d is viewing the stock\n", id);
        sem_wait(&mutex);
        rc--;
        printf("Person P%d left\n", id);
        if(rc == 0)
        sem_post(&wrt);
        sem_post(&mutex);
        count --;
    }
    return NULL;
    
}

void* edit(void* eid){
    int id = *((int*)eid);
    while(count>=0){
        sem_wait(&wrt);
        stock++;
        printf("Person P%d updated the stocks\n", id);
        sem_post(&wrt);
        printf("Person P%d left\n", id);
        count --;
    }
    
}

int main(){
    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_t p1, p2;
    int id1 = 1, id2 = 2;

    pthread_create(&p1, NULL, view, (void*)&id1);
    pthread_create(&p2, NULL, view, (void*)&id2);

    pthread_create(&p1, NULL, edit, (void*)&id1);
    pthread_create(&p2, NULL, edit, (void*)&id2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}