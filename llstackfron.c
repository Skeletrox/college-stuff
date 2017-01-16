#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
	int data;
	struct node *link;
}Node;

Node *first = NULL;

Node *Push ();

Node *Pop ();

void Display ();

int main()
{
	int chc = 0;
	do
	{
		printf ("\n1. Push\n2.Pop\n3. Display\n4. Exit\nEnter choice: ");
		scanf ("%d", &chc);
		switch (chc)
		{
			case 1 : first = Push(first);
					 break;
			case 2 : first = Pop(first);
					 break;
			case 3 : Display(first);
					 break;
			case 4 : return 0;
			default: printf ("\nWrong choice bro\n");
		}
	}while (1);
	return 1;

}

Node *Push (Node *f)
{
	Node *new = NULL;
	new = (Node *) malloc (sizeof(Node));
	new -> link = f;
	printf ("\nEnter data to push to stack\n");
	scanf ("%d", &new -> data);
	return new;
}

Node *Pop (Node *f)
{
	Node *new = f;
	if (new == NULL)
	{
		printf ("\nEmpty stack\n");
		return NULL;
	}
	new = new -> link;
	free(f);
	return new;
}

void Display(Node *f)
{
	Node *new = f;
	if (new == NULL)
	{
		printf ("\nEmpty Stack\n");
		return;
	}
	if (new -> link != NULL)
	{
		Display (new -> link);
	}
	printf ("%d\t", new -> data);
	return;
}