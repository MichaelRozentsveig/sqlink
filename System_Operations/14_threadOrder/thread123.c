#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

int check = 0;
sem_t mutex;
void * printABC(void * arg)
{     
    printf("%c ",*((char*)arg));
    fflush(stdout);
    sem_post(&mutex);
}

int main()
{
    int status;
    int i=0;
    int j=0;
    pthread_t tid[3];
    void *status1;
    char abc [3]="abc";
    sem_init(&mutex, 0, 1);
    while (1)
    {  
        status = pthread_create(&tid[i%3],NULL, printABC, &abc[i%3]);
        sem_wait(&mutex); 
        i++;
    }    
    for(j=0;j<3;j++)
    {
        pthread_join(tid[j], NULL);
    }    
    sem_destroy(&mutex);
}