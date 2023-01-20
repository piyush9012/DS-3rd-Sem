#include <stdio.h>
#include <stdlib.h>

struct node                // Declaration of node
{
	int data;
	struct node *next;
};
struct node *front = -1;
struct node *rear = -1;

void enqueue()      // Function to insert the element
{
	int item;
	printf("Enter the element\n");
	scanf("%d", &item);
	struct node *new;   // Declaration of pointer of node
	new = (struct node *)malloc(sizeof(struct node)); // Allocation of memeory to new node
	new->data = item;
	new->next = 0;
	if(rear == -1)    // Check whether Queue is empty or not
	{
		front = rear = new;
		rear->next = front;
	}
	else
	{
		rear->next = new;
		rear = new;
		new->next = front;
	}
}

void dequeue()      // Function to delete the element
{
	int item;
	struct node *temp;      // Declaration of pointer of node
	temp = front;
	if(front==-1 && rear==-1)    // Check whether Queue is empty or not
	{
		printf("Queue is empty\n");
	}
	else if(front == rear)   // Check if the queue has only one element
	{
		
		item = front->data;
		front = rear = -1;
		free(temp);
		printf("Element deleted is %d\n", item);
	}
	else
	{
		item = front->data;
		front = front->next;
		rear->next = front;
		free(temp);
		printf("Element deleted is %d\n", item);
	}
}

void peek()       // Function to display the front of the queue
{
	if(front==-1 && rear==-1)     // Check whether Queue is empty or not
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The front element is %d\n", front->data);
	}
}

void display()       // Function to display the queue
{
	struct node *temp;
	if(front==-1 && rear==-1)      // Check whether Queue is empty or not
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp = front;
		printf("Elements in Queue:\n");
        	while(temp->next != front)
        	{
            		printf("%d\t", temp->data);
            		temp = temp->next;
        	}
        	printf("%d", temp->data);
	}
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nSelect the Operation\n");
        printf("--------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf ("Invalid choice\n");
        }
    }
    return 0;
}