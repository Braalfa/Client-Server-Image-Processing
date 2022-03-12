
#include <semaphore.h>
#include <fcntl.h>
#include <stdio.h>
int main(void){
    sem_t* serverSem = sem_open("serverSem", 0);

    if (serverSem == SEM_FAILED)
    {
        perror("[sem_open] Failed\n");
        return 1;
    }
    if (sem_post(serverSem) < 0)
    {
        printf("[sem_post] Failed\n");
        return 1;
    }
}