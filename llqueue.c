#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}Node;

void EnQueue (Node **, Node **);
void DeQueue (Node **, Node **);
void Display (Node *, Node *);

int main()
{
	Node *front = NULL, *rear = NULL;
	int chc = 0;
	do
	{
		printf ("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice:\t");
		scanf ("%d", &chc);
		switch (chc)
		{
			case 1 : EnQueue(&front, &rear);
					 break;
			case 2 : DeQueue(&front, &rear);
					 break;
			case 3 : Display(front, rear);
					 break;
			case 4 : return 0;
			default: printf ("\nWong choice\n");
		}
	}while (1);
	return 2;
}

void EnQueue (Node **f, Node **r)
{
	Node *first = NULL, *new = NULL;
	int data = 0;
	new = (Node *) malloc (sizeof(Node));
	printf ("\nEnter the value to enter in queue\t");
	scanf ("%d", &data);
	new -> data = data;
	new -> link = NULL;
	if ((*f) == NULL)			//Initial condition
	{
		(*f) = new;
		(*r) = (*f);
		return;
	}
	first = *f;
	if (first -> link == NULL)
	{
		(*f) -> link = new;
		return;
	}
	while (first -> link != NULL)
	{
		first = first -> link;
	}
	first -> link = new;
	*r = new;
	return;
}

void DeQueue (Node **f, Node **r)
{
	Node *temp = NULL, *temp2 = NULL;
//	printf ("%d %d\n", (*f==NULL?1:0), (*r==NULL?1:0));
	if (*f == *r && *f != NULL) //Only one element
	{
		//temp = *f;
		//temp2 = *r;
		//free (temp);
		//free (temp2);
		*f = NULL;
		*r = NULL;
		return;
	}
	if (*f == NULL)
	{
		printf ("\nEmpty Queue\n");
		return;
	}
	temp = *f;
	(*f) = (*f) -> link;
	free(temp);
	return;
}

void Display(Node *f, Node *r)
{
	Node *temp = NULL;
	if (f == NULL)
	{
		printf ("\nEmpty Queue\n");
		return;
	}
	temp = f;
	do
	{
		printf ("%d\t", temp -> data);
		temp = temp -> link;
	}while (temp != NULL);
	return;
}