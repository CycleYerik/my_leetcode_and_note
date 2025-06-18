// tcp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>          // close()
#include <arpa/inet.h>       // sockaddr_in, inet_ntoa()

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // 1. 创建 socket，AF_INET 表示 IPv4，SOCK_STREAM 表示 TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. 配置服务器地址结构体
    server_addr.sin_family = AF_INET;                // 使用 IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;        // 监听所有本地 IP
    server_addr.sin_port = htons(PORT);              // 设置监听端口

    // 3. 绑定 socket 和 IP/端口
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 4. 监听端口，允许最多 5 个等待连接
    if (listen(server_fd, 5) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // 5. 等待客户端连接
    client_addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd < 0) {
        perror("accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // 6. 接收客户端数据
    bytes_received = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // 添加字符串结束符
    printf("Received from client: %s\n", buffer);

    // 7. 发送回复消息
    const char *reply = "Message received by server";
    send(client_fd, reply, strlen(reply), 0);

    // 8. 关闭连接
    close(client_fd);
    close(server_fd);

    return 0;
}
