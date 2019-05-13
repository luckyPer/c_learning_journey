#include <stdio.h>
#include <stdlib.h>


//最好时间复杂度: o(n)
//最坏时间复杂度: o(n^2)
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            int flag = 0;
            if (arr[j] < arr[j-1])
            {            
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                flag = 1; 
            }
            if(flag == 0) break;
        }
    }
    
}

//返回枢轴piovt最终index
int QuiteExchange(int arr[], int low, int high)
{
    int pivot = arr[0];
    while (low < high)
    {
        while (low < high && arr[pivot] <= arr[high])
        {
            --high;
        }
        arr[low] = arr[high];
        while (low < high && arr[pivot] >= arr[low])
        {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = arr[pivot];
    return low;
}

//不稳定的排序方法
//最好时间复杂度: o(nlogn)
//最坏时间复杂度: o(n^2)
void QuiteSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex =  QuiteExchange(arr, low, high);
        QuiteSort(arr, low, pivotIndex-1);   
        QuiteSort(arr, pivotIndex+1, high);   
    }
}