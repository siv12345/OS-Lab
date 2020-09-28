// Shortest Job First Scheduling
#include <stdio.h>

int main()
{
    printf("Shortest job first scheduling\n");
    // Getting number of jobs
    int jobs = 0;
    printf("Enter Number of Jobs\n");
    scanf("%d", &jobs);
    int arr[jobs][4];

    printf("\n");
    // Taking user input for burst time
    for (int i = 0; i < jobs; i++)
    {
        arr[i][0] = i + 1;

        printf("Enter Burst time of %d process ", i + 1);
        scanf("%d", &arr[i][1]);

        arr[i][2] = 0;
        arr[i][3] = 0;
    }
    printf("\n");

    int temp = 0,
        temp1 = 0;
    // Sorting the burst time in ascending order
    for (int i = 0; i < jobs; i++)
    {
        for (int j = i + 1; j < jobs; j++)
        {
            if (arr[j][1] < arr[i][1])
            {
                temp = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = temp;

                temp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = temp;
            }
        }
    }

    // Calculating waiting time arr[x][2]
    // Waiting time is the previous waiting time + previous burst time
    for (int i = 0; i < jobs; i++)
    {
        if (i == 0)
        {
            arr[i][2] = 0;
        }
        else
        {
            arr[i][2] = arr[i - 1][2] + arr[i - 1][1];
        }
    }

    // Calculating TAT
    // tat = current burst time + waiting time
    for (int i = 0; i < jobs; i++)
    {
        arr[i][3] = arr[i][1] + arr[i][2];
    }

    // Printing the array
    printf("Job \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < jobs; i++)
    {
        printf("%d \t %d \t\t %d \t\t %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
    }

    // Calculating Avg waiting time
    float awt = 0;
    for (size_t i = 0; i < jobs; i++)
    {
        awt += arr[i][2];
    }
    awt /= jobs;

    printf("Average waiting time is %f\n", awt);

    // Calculating avg tat
    float atat = 0;
    for (size_t i = 0; i < jobs; i++)
    {
        atat += arr[i][3];
    }
    atat /= jobs;

    printf("Average turnaround time is %f\n", atat);

    return 0;
}
