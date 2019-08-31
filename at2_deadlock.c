#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>      

void *thread1(void *data);
void *thread2(void *data);
void *thread3(void *data);
void teste ();

sem_t s;
int global = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER, mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_t Thread1, Thread2, Thread3;

int main(void) {
    
    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);
    pthread_create(&Thread3, NULL, thread3, NULL);

    //now join them
    pthread_join(Thread1, NULL);
    printf("Thread id %ld returned\n", Thread1);
    pthread_join(Thread2, NULL);
    printf("Thread id %ld returned\n", Thread2);
    pthread_join(Thread3, NULL);
    printf("Thread id %ld returned\n", Thread3);

    return 1;
    

}

void *thread1(void *data){
    
    sleep(rand()%10);
    
    pthread_mutex_lock(&mutex1);
    
    global++;
    printf("Thread 1 - Global = %d \n", global);
    pthread_mutex_unlock(&mutex1);   

    pthread_exit(NULL);
}

void *thread2(void *data){
    
sleep(rand()%10);
    
    pthread_mutex_lock(&mutex1);
    
    global++;
    printf("Thread 1 - Global = %d \n", global);
    pthread_mutex_unlock(&mutex1);   

    pthread_exit(NULL);
}

void *thread3(void *data){
sleep(rand()%10);
    
    pthread_mutex_lock(&mutex1);
    
    global++;
    printf("Thread 1 - Global = %d \n", global);
    pthread_mutex_unlock(&mutex1);   

    pthread_exit(NULL);
}

void test (){

}
