#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
	int data;
	struct node *link;
}Node;

Node *Push (Node *);

Node *Pop (Node *);

void Display (Node *);

int main()
{
	Node *first = NULL;
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
	Node *first = f, *temp = NULL, *temp2 = NULL;
	temp = (Node *)malloc(sizeof(Node));
	printf ("\nEnter data to store\t");
	scanf ("%d", &temp -> data);
	temp -> link = NULL;
	if (first == NULL)
	{
		return temp;
	}
	if (first -> link == NULL)
	{
		first -> link = temp;
		return first;
	}
	temp2 = first;
	while (temp2 -> link != NULL)
	{
		temp2 = temp2 -> link;
	}
	temp2 -> link = temp;
	return first;
}

Node *Pop (Node *f)
{
	Node *first = f, *temp = NULL, *temp2 = NULL;
	if (first == NULL)
	{
		printf ("\nEmpty stack LOL\n");
		return NULL;
	}
	temp = first;
	temp2 = temp -> link;
	if (temp -> link == NULL)
	{
		free(temp);
		return NULL;
	}
	while (temp2 -> link != NULL)
	{
		temp = temp2;
		temp2 = temp -> link;
	}
	free(temp2);
	temp -> link = NULL;
	return first;
}

void Display(Node *f)
{
	Node *first = f;
	if (first == NULL)
	{
		printf ("\nEmpty stack\n");
		return;
	}
	while (first != NULL)
	{
		printf ("%d\t", first -> data);
		first = first -> link;
	}
	return;
}