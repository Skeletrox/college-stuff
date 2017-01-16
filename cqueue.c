#include <stdio.h>

void EnQueue (int *);
void DeQueue (int *);
void Display(int *);
int IsFull();
int IsEmpty();

int front = -1, rear = -1;

int main()
{
	int cirQueue[5] = {0}, choice = 0;
	do
	{
		printf ("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1 : EnQueue (cirQueue);
					 break;
			case 2 : DeQueue (cirQueue);
					 break;
			case 3 : Display (cirQueue);
					 break;
			case 4 : return 0;
			default: printf ("\nY U GIVE WRONG INPUT\n");
		}
	}while (1);
	return 2;
}

int IsFull()
{
	if ((front == rear && rear != -1) || (front == -1 && rear == 4))
	{
		return 1;
	}
	return 0;
}

int IsEmpty()
{
	if (front % 5 == rear % 5 && front == -1)
	{
		return 1;
	}
	return 0;
}

void EnQueue (int* q)
{
	if (IsFull())
	{
		printf ("\nQueue full!\n");
		return;
	}
	rear = (rear + 1) % 5;
	printf ("\nEnter the number to be added!\t");
	scanf ("%d", &q[rear]);
	printf ("\nAdded %d to location %d\n", q[rear], rear);
	return;
}

void DeQueue (int* q)
{
	if (IsEmpty())
	{
		printf ("\nQueue empty!!!\n");
		return;
	}
	front = (front + 1) % 5;
	if (front == rear)
	{
		printf ("\nDeQueued %d and thus the queue is now empty!\n", q[front]);
		front = rear = -1;
		return;
	}
	printf ("\nDeQueued %d\n", q[front]);
	return;
}

void Display(int* q)
{
	int i = front;
	if (IsEmpty())
	{
		printf ("\nCannot display empty queue\n");
		return;
	}
	do
	{
		i = (i + 1) % 5;
		printf ("%d \t", q[i]);
	}while (i != rear);
	return;
}