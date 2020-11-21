#include <stdio.h>

int findLRU(int time[], int n)
{
	int i, minimum = time[0], pos = 0;
	for (i = 1; i < n; ++i)
	{
		if (time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
int main()
{
	int nframes, npages, frames[10], pages[30], ctr = 0, time[10], f1, f2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &nframes);
	printf("Enter number of pages: ");
	scanf("%d", &npages);
	printf("Enter reference string: ");
	for (i = 0; i < npages; ++i)
	{
		scanf("%d", &pages[i]);
	}
	for (i = 0; i < nframes; ++i)
	{
		frames[i] = -1;
	}
	for (i = 0; i < npages; ++i)
	{
		f1 = f2 = 0;
		for (j = 0; j < nframes; ++j)
		{
			if (frames[j] == pages[i])
			{
				ctr++;
				time[j] = ctr;
				f1 = f2 = 1;
				break;
			}
		}
		if (f1 == 0)
		{
			for (j = 0; j < nframes; ++j)
			{
				if (frames[j] == -1)
				{
					ctr++;
					faults++;
					frames[j] = pages[i];
					time[j] = ctr;
					f2 = 1;
					break;
				}
			}
		}
		if (f2 == 0)
		{
			pos = findLRU(time, nframes);
			ctr++;
			faults++;
			frames[pos] = pages[i];
			time[pos] = ctr;
		}
		printf("\n");
		for (j = 0; j < nframes; ++j)
		{
			printf("%d\t", frames[j]);
		}
	}
	printf("\n\nTotal Page Faults = %d", faults);
	return 0;
}