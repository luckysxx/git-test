#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    // 打开文件（如果不存在则创建，权限为644）
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        // 子进程写入
        const char *child_msg = "Child writing to the file.\n";
        for (int i = 0; i < 5; i++)
        {
            write(fd, child_msg, strlen(child_msg));
        }
        close(fd);
        exit(0);
    }
    else
    {
        // 父进程写入
        const char *parent_msg = "Parent writing to the file.\n";
        for (int i = 0; i < 5; i++)
        {
            write(fd, parent_msg, strlen(parent_msg));
        }
        close(fd);
        wait(NULL); // 等待子进程结束
    }

    return 0;
}