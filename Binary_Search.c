#include <stdio.h>
int binary(int arr[], int x, int low, int high);
int main(void)
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the Array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",  &arr[i]);
    }
    int x;
    printf("Enter the element to be search\n");
    scanf("%d", &x);
    int result = binary(arr, x, 0, n-1);
    if (result == -1)
    {
        printf("Element is not present in array\n");
    }
    else
    {
        printf("Element %d is present at index %d", x, result);
    }
    return 0;
}

int binary(int arr[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low+(high-low)/2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return binary(arr, x, low, mid-1);
        }
        else
        {
            return binary(arr, x, mid + 1, high);
        }
    }
    return -1;
}