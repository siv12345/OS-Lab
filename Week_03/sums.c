#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void childProcess(int n, int arr[n])
{
    int s = 0;
    puts("Partial sum from child:");
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
        printf("%d\n", s);
    }
}

void parentProcess(int n, int arr[n])
{
    int prod = 1;
    puts("Partial product from parent:");
    for (int i = 0; i < n; i++)
    {
        prod = prod * arr[i];
        printf("%d\n", prod);
    }
}

int main()
{
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the array elements: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    pid_t pid = fork();
    pid == 0 ? childProcess(n, arr) : parentProcess(n, arr);
    return 0;
}