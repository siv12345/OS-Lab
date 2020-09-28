#include <stdio.h>

void print_arr(int count, int arr[count])
{
    for (int i = 0; i < count; i++)
        printf("%d", arr[i]);
    puts("");
}

void reverse_arr(int count, int arr[count])
{
    for (int i = 0; i < count / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[count - i - 1];
        arr[count - i - 1] = temp;
    }
}