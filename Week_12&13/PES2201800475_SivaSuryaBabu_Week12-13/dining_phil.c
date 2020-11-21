#include <stdio.h>
#include <stdlib.h>
#define n 5
int donePhil = 0, i;
struct fork
{
    int taken;
} forkAvb[n];
struct philosp
{
    int left;
    int right;
} pstat[n];
void goForDinner(int pID)
{
    if (pstat[pID].left == 10 && pstat[pID].right == 10)
        printf("Philosopher %d completed his dinner\n", pID + 1);
    else if (pstat[pID].left == 1 && pstat[pID].right == 1)
    {
        printf("Philosopher %d completed his dinner\n", pID + 1);
        pstat[pID].left = pstat[pID].right = 10;
        int oFork = pID - 1;
        if (oFork == -1)
            oFork = (n - 1);
        forkAvb[pID].taken = forkAvb[oFork].taken = 0;
        printf("Philosopher %d released fork %d and fork %d\n", pID + 1, pID + 1, oFork + 1);
        donePhil++;
    }
    else if (pstat[pID].left == 1 && pstat[pID].right == 0)
    {
        if (pID == (n - 1))
        {
            if (forkAvb[pID].taken == 0)
            {
                forkAvb[pID].taken = pstat[pID].right = 1;
                printf("Fork %d taken by philosopher %d\n", pID + 1, pID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for fork %d\n", pID + 1, pID + 1);
            }
        }
        else
        {
            int dpID = pID;
            pID -= 1;
            if (pID == -1)
                pID = (n - 1);
            if (forkAvb[pID].taken == 0)
            {
                forkAvb[pID].taken = pstat[dpID].right = 1;
                printf("Fork %d taken by Philosopher %d\n", pID + 1, dpID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for Fork %d\n", dpID + 1, pID + 1);
            }
        }
    }
    else if (pstat[pID].left == 0)
    { //nothing taken yet
        if (pID == (n - 1))
        {
            if (forkAvb[pID - 1].taken == 0)
            {
                forkAvb[pID - 1].taken = pstat[pID].left = 1;
                printf("Fork %d taken by philosopher %d\n", pID, pID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for fork %d\n", pID + 1, pID);
            }
        }
        else
        {
            if (forkAvb[pID].taken == 0)
            {
                forkAvb[pID].taken = pstat[pID].left = 1;
                printf("Fork %d taken by Philosopher %d\n", pID + 1, pID + 1);
            }
            else
            {
                printf("Philosopher %d is waiting for Fork %d\n", pID + 1, pID + 1);
            }
        }
    }
}
int main()
{
    for (i = 0; i < n; i++)
        forkAvb[i].taken = pstat[i].left = pstat[i].right = 0;
    while (donePhil < n)
    {
        for (i = 0; i < n; i++)
            goForDinner(i);
        printf("\nTill now num of philosophers completed dinner are %d\n\n", donePhil);
    }
    return 0;
}