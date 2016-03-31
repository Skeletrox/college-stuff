/*Selection Sort Analyzer
Coded by the man himself, Sriram Ramaswamy
In: GCC running in Kali Linux running in a VMWare Workstation Pro
On: 31-Mar-2016, 10:48 PM*/
#include <stdio.h>
#include <time.h>

void main()
{
	int a[200000], n=20000, pos, i, j, min;
	clock_t start, end, total;
	while (n<=200000)
	{
		for (i=0;i<n;i++)
			a[i]=rand();
		start = clock();
		for(i=0;i<n;i++)
		{
			min = a[i];
			pos = i;
			for (j=i+1;j<n;j++)
				if (a[j] < min)
				{
					min = a[j];
					pos = j;
				}
				a[pos] = a[i];
			a[i] = min;
		}
		end = clock();
		total = (double) (end-start);
		printf ("\nThe time taken is %ld for %d elements\n", total, n);
		n+=20000;
	}
}

