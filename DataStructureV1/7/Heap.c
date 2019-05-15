#include <stdio.h>
#include <stdlib.h>

void BuildMaxHeap(int arr[], int len)
{
    int i;
    for ( i = len/2; i > 0; i--)
    {
        AjdustDown(arr, i, len);
    }
}

void AjdustDown(int arr[], int k, int len)
{
    arr[0] = arr[k];
    int i;
    for ( i = 2*k; i <= len; i *= 2)
    {
        if(i<len && arr[i] < arr[i+1])
        {
            i++;
        }
        if(arr[k] >= arr[i])
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

void HeapSort(int arr[], int len)
{
    //初始建堆
    BuildMaxHeap(arr, len);
    for (int i = len; i > 1; i--)
    {
        //和顶堆元素交换
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        AjdustDown(arr, 1, i-1);    //把剩下的n-1个元素整理成堆
    }
    
}