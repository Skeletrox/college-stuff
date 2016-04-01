/*Analysis of merge sort
  This is one program that CANNOT be executed in Windows as easily as in Linux, prettu much because this requires a HUGE stack size [else you'll end up with segmentation faults and stack overflows]
  If you're running this in Linux use 
  ulimit -s unlimited
  which basically sets the stack size to infinity, thus enabling more recursions.
  Coded by the man himself, Sriram Ramaswamy in GCC running in Kali Linux on VMWare Workstation Pro.
  Coded on 1 April 2016, at 1420 hrs
  */



#include <stdio.h>
#include <time.h>

void merge(int a[], int l[], int r[], int n)
{
	int i=0, j=0, k=0, ls;
	ls = n/2;
	while (i<ls && j<n-ls)
	{
		if (l[i] < r[j])
		{
			a[k] = l[i];
			k++;
			i++;
		}
		else
		{
			a[k] = r[j];
			k++;
			j++;
		}
	}
	while (i<ls)
	{
		a[k] = l[i];
		k++;
		i++;
	}
	while (j<n-ls)
	{
		a[k] = r[j];
		k++;
		j++;
	}
}
void mergesort(int a[], int n)
{
	int lsize, rsize, left[100000], right[100000], i, j;
	if (n>1)
	{
		lsize = n/2;
		rsize = n-lsize;
		for (i=0;i<lsize;i++)
			left[i] = a[i];
		for (j=0;j<rsize;j++)
			right[j] = a[i++];
		mergesort (left, lsize);
		mergesort (right, rsize);
		merge (a, left, right, n);
	}
}
void main()
{
	int array[200000], i, n;
	clock_t start, end, total;
	srand(time(NULL));
	for (n=20000;n<=200000;n+=10000)
	{
		for (i=0;i<n;i++)
			array[i] = rand();
		start = clock();
		mergesort(array, n);
		end = clock();
		total = (double) (end-start);
		printf ("---------------------------------------------\nThe time for %d elements is %ld\n", n, total);
	}
}
