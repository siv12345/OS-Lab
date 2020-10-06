// To run the code type make in the pwd
#include <stdio.h>

int main()
{
    printf("Round Robin Scheduling\n");
    // Getting number of jobs
    int jobs = 0;
    printf("Enter Number of Processes\n");
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

    int quantum = 0;
    printf("Enter Time Quantum\n");
    scanf("%d", &quantum);
    printf("\n");

    int tmp[jobs];
    for (int i = 0; i < jobs; i++)
        tmp[i] = arr[i][1];
    int ttime = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < jobs; i++)
        {
            if (tmp[i] > 0)
            {
                done = 0;
                if (tmp[i] > quantum)
                {
                    ttime += quantum;
                    tmp[i] -= quantum;
                }
                else
                {
                    ttime += tmp[i];
                    arr[i][2] = ttime - arr[i][1];
                    tmp[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    // Calculating TAT
    // tat = current burst time + waiting time
    for (int i = 0; i < jobs; i++)
    {
        arr[i][3] = arr[i][1] + arr[i][2];
    }

    // Printing the array
    printf("Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < jobs; i++)
    {
        printf("P%d \t\t %d \t\t %d \t\t %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
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
