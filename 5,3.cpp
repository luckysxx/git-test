#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("hello\n");
        kill(getppid(), SIGCONT); // 唤醒父进程
    }
    else
    {
        pause(); // 父进程阻塞，等待子进程信号
        printf("goodbye\n");
    }
    return 0;
}