#include <stdio.h>
#include <stdlib.h>

void SelectSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n-1; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(arr[min != i]) 
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }     
    }
}


