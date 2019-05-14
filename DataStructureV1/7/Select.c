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


//初建堆
void BuildMaxHeap(int arr[], int length)
{
    for (int i = length/2; i > 0; i--)
    {
        AdjustDown(arr, i, length);
    }
}

//调成大顶锥型
void AdjustDown(int arr[], int k, int length)
{
    arr[0] = arr[k];
    for (int i = 2*k; i <= length; i *=2)
    {
        if (i < length && arr[i] < arr[i+1])
        {
            i++;
        }
        if(arr[0] >= arr[i]) 
        {
            break;
        }
        else 
        {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

void QiuckSort(int arr[], int length)
{
    BuildMaxHeap(arr, length);
    for (int i = length; i > 1; i--)
    {
        //数组第一个换到最后, 再调剩余的i-1结点
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        AdjustDown(arr, 1, i-1);
    }   
}
