#include <stdio.h>
int factorial(int num)        // user defined function
{
    if (num==0 || num==1)
    {
        return 1;
    }
    else
    {
        return num*factorial(num-1);    // Recursive call
    }    
}

int main()
{
    int num;
    printf("Enter a number\n");      // Input from the user
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, factorial(num));      // Printing answer
    return 0;
}