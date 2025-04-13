#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
int num = 0;
pthread_mutex_t mutex;
void *funca_num(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *funcb_num(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main()
{
    pthread_t p1, p2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p1, NULL, funca_num, NULL);
    pthread_create(&p2, NULL, funcb_num, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("%d", num);
    return 0;
}