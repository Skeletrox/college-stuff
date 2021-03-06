/*Math Assignment! Generates matrix given eigenvalues, by asking you for eigenvectors [or generates a set of random eigenvectors with values 0 to 9]
Coded by the man hiself, Sriram Ramaswamy
In Codeblocks IDE running in Windows 10
On April 1, 2016, 2110 hrs
Copyright (c) Sriram Ramaswamy
Seriously, if you're from my class and you end up copying this and submitting as your own assignment you're a good-for-nothing idiot. A lot of work (?) went into making this.
*/




#include <stdio.h>
#include <time.h>
#include <float.h>

int eigen[5], i, j, k, l, n, flag=1;
float eigmat[5][5], vecmat[5][5], vecinv[5][5], interm[5][5], matrix[5][5], veccpy[5][5];

void invert(float a[5][5], float inv[5][5])
{
    flag=1;
    float setval;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if (i==j)
                inv[i][j]=1;
            else
                inv[i][j]=0;
        }
    for (i=0;i<n;i++)   //We're performing row operations for each row
    {
        setval = a[i][i];
        if (setval != 0)
        {
            for (j=0;j<n;j++)   //We're currently editing the values in the same row as the element
            {
                inv[i][j] = inv[i][j]/setval;
                a[i][j] = a[i][j]/setval;
            }
            //Time to edit values for other rows
            for (k=0;k<n;k++)
                if (k!=i)
                {
                    setval = a[k][i];
                    for (l=0;l<n;l++)
                    {
                        inv[k][l] = inv[k][l] - setval*inv[i][l];
                        a[k][l] = a[k][l] - setval*a[i][l];
                    }
            }
        }
        else
        {
            flag = 0;
            printf ("\nWhoops! Eigenvector matrix is sigular!\n");
            return;
        }
    }
  return;
}

    void gen_eigvet()
    {
        char c;
        printf ("\nGenerate random Eigenvectors? [y/n]:\t");
        scanf (" %c", &c);
        if (c=='y'||c=='Y')
        {
            srand(time(NULL));
            for (j=0;j<n;j++)
            {
              printf ("\nGenerating random Eigenvector %d:\n", j+1);
              for (i=0;i<n;i++)
              {
                vecmat[j][i] = rand()%10;
                veccpy[j][i] = vecmat[j][i];
                printf ("%.2f\n", vecmat[j][i]);
              }
            }
        }
        else if (c=='n'||c=='N')
        {
            for (j=0;j<n;j++)
            {
                printf ("\nEnter Eigenvector %d\n", j+1);
                for (i=0;i<n;i++)
                {
                    scanf ("%d", &vecmat[j][i]);
                }
                veccpy[j][i] = vecmat[j][i];
            }
        }
        else
        {
            gen_eigvet();
        }
}

void mul(float a[5][5], float b[5][5], float c[5][5])
{
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            c[i][j] = 0;
            for (k=0;k<n;k++)
                c[i][j] += a[i][k]*b[k][j];
        }
    }
}

void main()
{
    printf ("\nEnter the number of eigenvalues\t");
    scanf ("%d", &n);
    if (n>0 && n<6)
    {
        printf ("\nEnter the eigenvalues\n");
        for (i=0;i<n;i++)
        {
            scanf ("%f", &eigmat[i][i]);
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i!=j)
                {
                    eigmat[i][j]=0;
                }
            }
        }
        do
        {
            gen_eigvet();
            invert(vecmat, vecinv);
        }while (!(flag));
        mul(veccpy, eigmat, interm);
        mul(interm, vecinv, matrix);
        printf ("\nThe required matrix\n");
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                printf ("%.2f\t", matrix[i][j]);
            }
            printf ("\n");
        }
    }
    else
        printf ("\nNot feasible to find/verify Eigenvalues\n");
    return;
}
