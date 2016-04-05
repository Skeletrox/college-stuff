#include <stdio.h>

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
        printf ("\n----------------------\nSorted array is \n");
        for (i=low;i<high;i++)
            printf ("%d\t", arr[i]);
    }

}

void main()
{
    int arr[20], i, n;
    printf ("\nEnter array size\t");
    scanf ("%d", &n);
    printf ("\nEnter the array\n");
    for (i=0;i<n;i++)
        scanf ("%d", &arr[i]);
    quicksort (arr, 0, n-1);
    printf ("\nSorted array is \n");
    for (i=0;i<n;i++)
        printf ("%d\t", arr[i]);
}
