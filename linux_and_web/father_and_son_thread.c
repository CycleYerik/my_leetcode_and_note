// 用父线程和子线程实现读取文件。每个子线程读取文件的一行并打印，然后结束
// 父线程等待所有子线程结束，然后打印“所有子线程结束”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* read_file(void* arg) {
    FILE* file = (FILE*)arg;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, read_file, NULL);
    pthread_join(tid, NULL);
    printf("所有子线程结束\n");
    return 0;
}
