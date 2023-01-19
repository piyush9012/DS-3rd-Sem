#include <stdio.h>
#include <stdlib.h>
#define N 5

int front = -1;
int rear = -1;
int queue[N];       // Array decleration

void enqueue()        // function to insert an element
{
    int item;
    printf("Enter the element\n");
    scanf("%d", &item);
    if (rear == N-1)        // condition to check queue is full
    {
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1 && rear == -1)       // condition to check queue is empty
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
    printf("Value inserted\n");
}

void dequeue()           // function to delete an element
{
    if (front == -1 && rear == -1)        // condition to check queue is empty
    {
        printf("Queue Underflow\n");
        return;
    }
    else if (front == rear)
    {
        printf("Value deleted is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
            printf("Value deleted is %d\n", queue[front]);
            front++;        
    }  
}

void peek()         // function to display front most element
{
    if (front == -1 && rear == -1)       // condition to check queue is empty
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The front element is %d\n", queue[front]);
    }
}

void display()         // function to display an element
{
    if (front == -1 && rear == -1)       // condition to check queue is empty
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the Queue are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }  
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nSelect the Operation\n");
        printf("--------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break; 
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}