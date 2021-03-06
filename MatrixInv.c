/*
Program that calculates the inverse of a matrix. Uses row modification method because the solutions online are useless and wrong.
So much hardwork went into making this, [I know, right] and finally got to know my calculator *might* be making mistakes while calculating inverses of matrices. [Thank you, Wolfram Alpha, for not letting me down... again!]

Anyway, here she is. The first step before I end up coding my assignment: Generating a matrix from Eigen Values.
Coded by: The man himself, Sriram Ramaswamy
In: CodeBlocks IDE running in Windows 10
On: 31 March 2016, 1825 hrs
Update: Changed defunct logic that checks for singularity of the matrix
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float matrix[10][10], inverse[10][10], setval;
    int i, j, k, l, n;
    printf ("\nEnter the order of matrix\t");
    scanf ("%d", &n);
    printf ("\nEnter the matrix\n");
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            scanf ("%f", &matrix[i][j]);
            if (i==j)
                inverse[i][j]=1;
            else
                inverse[i][j]=0;
        }
    for (i=0;i<n;i++)   
    {
       //We're performing row operations for each row
        setval = matrix[i][i];
        if (setval==0)
        {
            printf ("\nSingular Matrix\n");
            exit(0);
        }
        for (j=0;j<n;j++)   //We're currently editing the values in the same row as the element
        {

            inverse[i][j] = inverse[i][j]/setval;
            matrix[i][j] = matrix[i][j]/setval;
        }
        //Time to edit values for other rows
        for (k=0;k<n;k++)
            if (k!=i)
            {
                setval = matrix[k][i];
                for (l=0;l<n;l++)
                {
                    inverse[k][l] = inverse[k][l] - setval*inverse[i][l];
                    matrix[k][l] = matrix[k][l] - setval*matrix[i][l];
                }
            }
    }
    printf ("\nThe inverse matrix is \n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf ("%.2f\t", inverse[i][j]);
        printf ("\n");
    }
}
