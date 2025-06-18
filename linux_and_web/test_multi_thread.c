#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *function(void *arg);
pthread_mutex_t mutex;
int counter = 0;
int main(int argc, char *argv[])
{
    int rc1,rc2;
     
    char *str1="hello";
    char *str2="world";
    pthread_t thread1,thread2;
 
    pthread_mutex_init(&mutex,NULL);
    if((rc1 = pthread_create(&thread1,NULL,function,str1)))
    {
        fprintf(stdout,"thread 1 create failed: %d\n",rc1);
    }
 
    if(rc2=pthread_create(&thread2,NULL,function,str2))
    {
        fprintf(stdout,"thread 2 create failed: %d\n",rc2);
    }
 
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}

void *function(void *arg)
{
    char *m;
    m = (char *)arg;
    pthread_mutex_lock(&mutex); // 加锁以防止多个线程同时访问共享资源（std
    while(*m != '\0')
    {
        printf("%c",*m);
        fflush(stdout);
        m++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}
