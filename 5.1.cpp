#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int num;
    std::cin >> num;
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        num += 10;
        printf("%d\n", num);
    }
    else
    {
        num += 100;
        printf("%d\n", num);
    }
    return 0;
}