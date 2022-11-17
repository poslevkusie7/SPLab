#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int numbers[], int array_size)
{
    int i, j;
    int temp;
    for (i = 0; i < array_size - 1; i++)
    {
        for (j = 0; j < array_size - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    
    char **arr = argv + 1;
    int n = argc - 1;
    int *numbers = (int *)calloc(n, sizeof(int));
    printf("Original array:");
    
    for (int i = 0; i < n; ++i)
    {
        printf(" %s", arr[i]);
        numbers[i] = atoi(arr[i]);
    }
    
    printf("\n");
    
    bubbleSort(numbers, n);
    
    printf("Sorted array:");
    for (int i = 0; i < n; ++i)
        printf(" %d", numbers[i]);
    printf("\n");
    free(numbers);
    return 0;
}