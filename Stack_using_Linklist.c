// Program 2: Design and implement a stack (linked list implication) and demonstrate its working
// with necessary inputs. The program displays the appropriate message in case of exceptions.

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
struct node // Initialization of Structure
{
    int val;
    struct node *next;
};
struct node *head; // Top

void push() // Function to Push value in the stack
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not abkle to push the element\n");
    }
    else
    {
        printf("Enter the value\n");
        scanf("%d", &val);
        if (head == NULL)
        {
            ptr->val = val;   // Pushing Value
            ptr->next = NULL; // Set next to NULL
            head = ptr;       // Equating head to next Structure
        }
        else
        {
            ptr->val = val; // Pushing Value
            ptr->next = head;
            head = ptr;
        }
        printf("Item pushed\n");
    }
}

void pop() // Function to Delete Element
{
    int item;
    struct node *ptr; // Temporary Array
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped %d\n", item);
    }
}

void display() // Function to Display Element
{
    struct node *ptr; // Temporary
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Printing stack element: \n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->val); // Display Elements
            printf("\n");
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Select the operation\n");
        printf("-----------------------------\n");
        printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        scanf("%d", &choice); // Input choice from user
        switch (choice)
        {
        case 1:
            push();
            break; // Function Calling
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0); // Program Termination
        default:
            printf("Invalid choice\n");
        }
    }
}