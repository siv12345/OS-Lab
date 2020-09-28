#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void childProc(int count)
{
    int x = 0;
    int y = 1;
    int z = 0;

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", z);
        x = y;
        y = z;
        z = x + y;
    }
}

int parentProc()
{
    return 0;
}

int main(int argc, char const *argv[])
{
    int terms = atoi(argv[1]);
    int arr[terms];

    pid_t pid = fork();
    pid == 0 ? childProc(terms) : parentProc();

    return 0;
}