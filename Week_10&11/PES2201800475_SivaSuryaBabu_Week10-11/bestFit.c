#include <stdio.h>

void main()
{
	int frag[20], b[20], p[20], i, j, nb, np, tp, low = 9999;
	static int barr[20], parr[20];
	printf("\nMemory Management -> Best Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d", &nb);
	printf("Enter the number of processes:");
	scanf("%d", &np);
	printf("\nEnter the size of the blocks:-\n");
	for (i = 1; i <= nb; i++)
	{
		printf("Block no.%d:", i);
		scanf("%d", &b[i]);
	}
	printf("\nEnter the size of the processes :-\n");
	for (i = 1; i <= np; i++)
	{
		printf("Process no.%d:", i);
		scanf("%d", &p[i]);
	}
	for (i = 1; i <= np; i++)
	{
		for (j = 1; j <= nb; j++)
		{
			if (barr[j] != 1)
			{
				tp = b[j] - p[i];
				if (tp >= 0)
					if (low > tp)
					{
						parr[i] = j;
						low = tp;
					}
			}
		}
		frag[i] = low;
		barr[parr[i]] = 1;
		low = 10000;
	}
	printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
	for (i = 1; i <= np && parr[i] != 0; i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parr[i], b[parr[i]], frag[i]);
}