/*
Program that checks if state transition table is proper for input string
DFA Checker v1.0, coded by the man himself, Sriram Ramaswamy
March 19, 2016, 7:17 PM
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int table[20][20], n, r, init, final[20], iscorr, i, j, currstate;
	char string[50], chartable[20], current, flag;
	printf ("\nEnter the number of states\t");
	scanf ("%d", &n);
	printf ("\nEnter the number of letters in language\t");
	scanf ("%d", &r);
	printf ("\nEnter the letters of the language\n");
	for (i=0;i<r;i++)
		scanf (" %c", &chartable[i]);		//Creates a character table for future use to ensure no illegal characters are used
	/*
	 Alright. A small backstory.
	 I tried another approach to the below code, where before starting the state transition table for a certain row, the program would ask if the selected state was
	 the final, and then ask D(state, letter) each time before input, but figured that was too slow and tedious.
	 The user would have written the table down somewhere already, so let him/her input as a table!
	 */
	printf ("\nEnter array of finality: 1 for final state and 0 otherwise\n");
	for (i=0;i<n;i++)
	{
		scanf ("%d", &final[i]);
		if (final[i]!= 1 && final[i] != 0)
		{
			printf ("\nGet lost\n");
			exit(0);
		}
	}
	printf ("\nEnter the state transition table\n");
	for(i=0;i<n;i++)
		for (j=0;j<r;j++)
			scanf ("%d", &table[i][j]);
	while(1)
	{
		printf ("\nEnter the string to process\n");
		scanf ("%s", string);
		currstate=0;
		for (i=0;string[i]!='\0';i++)
		{
			current = string[i];
			for (j=0;j<r;j++)
			{
				if (chartable[j]==current)
					break;
			}
			if (j==r)
			{
				printf ("Illegal character encountered\n");
				break;
			}
			currstate = table[currstate][j];
			if (final[currstate])
				iscorr=1;
			else
				iscorr=0;
		}
		if (iscorr)
			printf ("\nSaid string is accepted\n");
		else
			printf ("\nSaid string is rejected\n");
		printf ("\nEnter n to exit, any other character to continue\t");
		scanf (" %c", &flag);
		if (flag=='n')
			break;
	}
}
