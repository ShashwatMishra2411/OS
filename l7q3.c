#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t odd_semaphore, even_semaphore;

int n = 10;
int x = 1;

void* odd(void* arg){
    for(int i = 0 ;i<(int)n/2;i++){
        sem_wait(&odd_semaphore);
        printf("%d ", x);
        x++;
        sem_post(&even_semaphore);
    }
    
    return NULL;
}

void* even(void* arg){
    for(int i = 0 ;i<(int)n/2;i++){
        sem_wait(&even_semaphore);
        printf("%d ", x);
        x++;
        sem_post(&odd_semaphore);
    }
            return NULL;
}

int main(){
    sem_init(&odd_semaphore, 0, 1);
    sem_init(&even_semaphore, 0, 0);
    pthread_t o, e;
    
    pthread_create(&o, NULL, odd, NULL);
    pthread_create(&e, NULL, even, NULL);

    pthread_join(o, NULL);
    pthread_join(e, NULL);

    sem_destroy(&odd_semaphore);
    sem_destroy(&even_semaphore);

    printf("\n");
    return 0;
}