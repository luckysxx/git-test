#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
typedef struct Task
{
} Task;

typedef struct ThreadPool
{
    Task *taskQ;
    int queueCapacity; // 容量
    int queueSize;     // 当前任务个数
    int queueFront;    // 队头
    int queueRear;     // 队尾

    pthread_t managerID;
    pthread_t *threadIDs;
    int minnum;
    int maxnum;
    int busynum;
    int livenum;
    int exitnum;
    pthread_mutex_t mutexpool;
    pthread_mutex_t mutexbusy;
    pthread_cond_t notFull;
    pthread_cond_t notEmpty;

    bool shutdown;
} ThreadPool;
ThreadPool *threadPoolCreate(int min, int max, int queueSize)
{
    ThreadPool *pool = (ThreadPool *)malloc(sizeof(ThreadPool));
    if (pool == NULL)
    {
        fprintf(stderr, "malloc threadpool fail\n");
        return NULL;
    }

    pool->threadIDs = (pthread_t *)malloc(sizeof(pthread_t) * max);
    if (pool->threadIDs == NULL)
    {
        fprintf(stderr, "malloc threadIDs failed");
        return NULL;
    }
    bzero(pool->threadIDs, sizeof(pthread_t) * max);
    pool->minnum = min;
    pool->maxnum = max;
    pool->busynum = 0;
    pool->livenum = min;
    pool->exitnum = 0;

    if (pthread_mutex_init(&pool->mutexpool, NULL) != 0)
        return NULL;
}
int main()
{
    return 0;
}