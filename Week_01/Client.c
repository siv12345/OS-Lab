#include <stdio.h>
#include "Header.h"

int main(int argc, char const *argv[])
{
    puts("enter the arr count");
    int count;
    scanf("%d", &count);
    puts("enter elements of arr");
    int arr[4];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }
    puts("Input arr is");
    print_arr(count, arr);
    reverse_arr(count, arr);
    puts("Reversed arr is");
    print_arr(count, arr);
    return 0;
}
