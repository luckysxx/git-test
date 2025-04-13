#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <time.h>
#include <netinet/in.h>
#include <sys/time.h>
using namespace std;
int main()
{
    int sockfd, n;
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char TIME[4096];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET6;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 所有ip
    servaddr.sin_port = htons(13);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 1024);

    while (1)
    {
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);

        ticks = time(NULL);
        snprintf(TIME, sizeof(TIME), "%.24s\r\n", ctime(&ticks));
        write(connfd, TIME, strlen(TIME));

        close(connfd);
    }
}