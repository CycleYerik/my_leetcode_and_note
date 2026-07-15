#include <pthread.h>

#define Q_CAP 8

typedef struct {
    int buf[Q_CAP];
    int head;
    int tail;
    int count;
    pthread_mutex_t mtx;
    pthread_cond_t  not_full;   /* 队列不满 */
    pthread_cond_t  not_empty;    /* 队列不空 */
} bounded_queue_t;

/* 初始化：mutex、cond、head/tail/count */
void bq_init(bounded_queue_t *q)
{
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    pthread_mutex_init(&q->mtx, NULL); //初始化为NULL，如果要配置优先级继承、递归锁等，需要传入pthread_mutexattr_t
    pthread_cond_init(&q->not_full, NULL);
    pthread_cond_init(&q->not_empty, NULL);
}

/* 阻塞：满则 wait(not_full)；写入 val 到 tail；count++；signal(not_empty) */
void bq_put(bounded_queue_t *q, int val)
{
    pthread_mutex_lock(&q->mtx);
    while (q->count == Q_CAP)
    {
        pthread_cond_wait(&q->not_full, &q->mtx); //等待条件变量not_full
    }
    q->buf[q->tail] = val;
    q->tail = (q->tail + 1) % Q_CAP;
    q->count++;
    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->mtx);
}

/* 阻塞：空则 wait(not_empty)；读出 head；count--；signal(not_full)；返回 val */
int bq_get(bounded_queue_t *q)
{
    pthread_mutex_lock(&q->mtx);
    while (q->count == 0)
    {
        pthread_cond_wait(&q->not_empty, &q->mtx); //等待条件变量not_empty
    }
    int val = q->buf[q->head];
    q->head = (q->head + 1) % Q_CAP;
    q->count--;
    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->mtx);
    return val;
}