#include<stdio.h>
int stack[20];                   // for max size of stack 
int top = -1;                   // declare stack and its top pointer to be used during postfix 

void push(int x)                   // Function to push the element from the stack
{
    stack[++top] = x;
}

int pop()                          // Function to pop the element from the stack
{
    return stack[top--];
}

int main()                           // Main function
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression: ");
    scanf("%s", exp);                // Input Postfix Expression from the user
    e = exp;
    while(*e != '\0')                // While loop
    {
        if(isdigit(*e))
        {
            num = *e-48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)               // Switch statement
            {
                case '+':
                    n3 = n1+n2; break;
                case '-':
                    n3 = n2-n1; break;
                case '*':
                    n3 = n1*n2; break;
                case '/':
                    n3 = n2/n1; break;
            }                      // Switch closed
            push(n3);
        }                          // Else closed
        e++;
    }                              // While Loop closed
    printf("The result of expression %s = %d\n", exp, pop());
    return 0;
}