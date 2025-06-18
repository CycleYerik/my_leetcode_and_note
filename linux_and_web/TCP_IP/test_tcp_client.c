// tcp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>          // close()
#include <arpa/inet.h>       // sockaddr_in, inet_pton()

#define SERVER_IP "127.0.0.1"  // 本机 IP，实际应用中替换为服务器地址
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // 1. 创建 socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. 配置服务器地址结构体
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("invalid address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // 3. 连接服务器
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Connected to server %s:%d\n", SERVER_IP, SERVER_PORT);

    // 4. 发送消息
    const char *message = "Hello, TCP Server!";
    send(sockfd, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // 5. 接收服务器回复
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // 字符串结束符
    printf("Received from server: %s\n", buffer);

    // 6. 关闭连接
    close(sockfd);

    return 0;
}
