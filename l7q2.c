#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t inc_semaphore, dec_semaphore;

int x = 0;

void* inc(void* arg){
    for(int i = 0 ;i<5;i++){
        sem_wait(&inc_semaphore);
        x++;
        printf("x_inc = %d\n", x);
        sem_post(&dec_semaphore);
    }
    
    return NULL;
}

void* dec(void* arg){
    for(int i = 0 ;i<5;i++){
        sem_wait(&dec_semaphore);
        x--;
        printf("x_dec = %d\n", x);
        sem_post(&inc_semaphore);
    }
            return NULL;
}

int main(){
    sem_init(&inc_semaphore, 0, 1);
    sem_init(&dec_semaphore, 0, 0);
    pthread_t i, d;
    
    pthread_create(&i, NULL, inc, NULL);
    pthread_create(&d, NULL, dec, NULL);

    pthread_join(i, NULL);
    pthread_join(d, NULL);

    sem_destroy(&inc_semaphore);
    sem_destroy(&dec_semaphore);

    printf("x_final = %d\n", x);
    return 0;
}