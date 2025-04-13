#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#define MAX 50
int num = 0;
pthread_rwlock_t rwlock;

void *read_num(void *arg)
{
    for (int i = 0; i < MAX; i++)
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("Thread read, id=%lu, number=%d\n", pthread_self(), num);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 5);
    }
    return NULL;
}
void *write_num(void *arg)
{
    for (int i = 0; i < MAX; i++)
    {
        pthread_rwlock_rdlock(&rwlock);
        num++;
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 5);
    }
    return NULL;
}
int main()
{
    pthread_t p1[5], p2[3];
    pthread_rwlock_init(&rwlock, NULL);
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&p1[i], NULL, read_num, NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&p2[i], NULL, write_num, NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(p1[i], NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(p2[i], NULL);
    }
    pthread_rwlock_destroy(&rwlock);
    return 0;
}