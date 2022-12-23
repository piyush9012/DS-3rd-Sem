#include <stdio.h>
int factorial(int num)
{
    if (num==0 || num==1)
    {
        return 1;
    }
    else
    {
        return num*factorial(num-1);
    }    
}

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    printf("The factorial of %d is %d", num, factorial(num));   
    return 0;
}