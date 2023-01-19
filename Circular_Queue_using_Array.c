#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];             // Array decleration
int front = -1;
int rear = -1;

void enqueue()            // function to insert an element
{
    int item;
    printf("Enter the element\n");
    scanf("%d", &item);
    if ((rear+1)%N == front)           // condition to check queue is full
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) // condition to check queue is empty
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%N;
    }
    queue[rear] = item;
}

void dequeue()                         // function to delete an element
{
    if (front == -1 && rear == -1)     // condition to check queue is empty
    {
        printf("Queue Underflow\n");
    }
    else if (front == rear)
    {
        printf("Deleted item is: %d", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted item is: %d", queue[front]);
        front = (front+1)%N;
    }
}

void display()                          // function to display an element
{
    int i = front;
    if (front == -1 && rear == -1)      // condition to check queue is empty
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the Queue are :\n");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i+1)%N;
        }
        printf("%d", queue[rear]);
        printf("\n");
    }
}

void peek()                            // function to display front most element
{
    if (front == -1 && rear == -1)     // condition to check queue is empty
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The front element is %d\n", queue[front]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nSelect the Operation\n");
        printf("-----------------");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}