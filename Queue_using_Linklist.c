#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front,*rear;

void enqueue()
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        int n;
        printf("Enter the element:");
        scanf("%d",&n);
        ptr->data = n;
        if(front == NULL)
        {
            front = rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}

void dequeue()
{    
    int item;
    struct node *ptr;
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    else 
    {   
        item = front->data;
        ptr = front;
        front = front->next;
        free(ptr);
        printf("Element deleted %d\n", item);
    }
}

void display()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        ptr = front;
        printf("Elments in Queue:\n");
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } 
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nSelect the Operation\n");
        printf("--------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf ("Invalid choice\n");
        }
    }
    return 0;
}