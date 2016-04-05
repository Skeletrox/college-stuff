/* Quick Sort Analysis
   Coded by the man himself, Sriram Ramaswamy in GCC running in Kali Linux on VMWare Workstation Pro on 5 April, 2045 hrs
   Doesn't need such a huge stack as merge sort analysis I believe, haven't tested on Windows, would love your results :p
*/
#include <stdio.h>
#include <time.h>
void quicksort (int arr[], int low, int high)
{
	int pivot, i, j, temp;
	if (low < high)
	{
		pivot = (low+high)/2;
		i = low;
		j = high;
		while (i<j)
		{
			while ((arr[i] <= arr[pivot]) && (i<high))
				i++;
			while (arr[j] > arr[pivot])
				j--;
			if (i<j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quicksort (arr, low, j-1);
		quicksort (arr, j+1, high);
	}
}

void main()
{
	int arr[200000], i, n;
	time_t start, end, total;
	srand(time(NULL));
	for (n=20000;n<=200000;n+=20000)
	{
		for (i=0;i<n;i++)
			arr[i]=rand();
		start=clock();
		quicksort (arr, 0, n-1);
		end=clock();
		total=(double) end-start;
		printf ("\nTime taken for %d elements is %ld\n", n, total);
	}
}
