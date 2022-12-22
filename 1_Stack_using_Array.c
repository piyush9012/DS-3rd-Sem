// Program 1: Design and implement a stack and demonstrate its working with necessary inputs.
// The program displays the appropriate message in case of exceptions.

#include <stdio.h>
#include <stdlib.h>
#define size 4

int top = -1;
int arr[size];

void push(); // Function Prototype
void pop();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\nSelect the operation\n");
        printf("-----------------------------\n");
        printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Peek\n 5. Exit\n");
        scanf("%d", &choice);
        switch (choice) // perform task according to choice
        {
        case 1:
            push();
            break; // function calling
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0); // program termination
        default:
            printf("Invalid choice\n");
        }
    }
}

void push() // Push Function
{
    int n;
    if (top == size - 1) // Check if Stack is Full
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d", &n);
        top++;
        arr[top] = n;
    }
}

void pop() // Delete Function
{
    if (top == -1) // Checking Top Value
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Removed element is %d\n", arr[top]);
        top--; // removing element
    }
}

void peek() // Display the top of the stack.
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", arr[top]);
    }
}

void display() // Display Function
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Elements in the stack are:\n");
        for (int i = top; i >= 0; i--) // printing stack values
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}