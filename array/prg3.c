#include <stdio.h>

int main()
{
    // Declare the variable
    int a;
    int arr[100];
    int temp = 0;
    // Read the variable from STDIN
    scanf("%d", &a);
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = i + 1; j < a; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 1; i < a; i++)
    {
        if((arr[i] - arr[i - 1]) > 1)
        {
            printf("\nMissing element is %d\n", i);
        }
    }
    // Output the variable to STDOUT
    
    // Note that you need to explicitly return 0 in main() function,
    // otherwise your solution won't get accepted
    return 0;
}

