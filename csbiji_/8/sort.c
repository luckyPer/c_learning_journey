#include <stdio.h>
#include <stdlib.h>

void insertSort(int arr[], int n)
{
    int i,j;
    int temp;
    for ( i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i-1;
        while (j >= 0 && temp < arr[j] )
        {
            arr[j+1] = arr[j]; 
            j--;
        }
        arr[j+1] = temp;
    }  
}

//简单选择排序, 找出一个最小的关键字, 与第一个i 交换
void selectSort(int arr[], int n)
{
    int i,j,min;
    int temp;
    for ( i = 0; i < n; i++)
    {
        min = i;
        for ( j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

//冒泡排序
void BubbleSort(int arr[], int n)
{
    int i,j;
    int temp;
    int flag;
    for ( i = n-1; i >= 1; i--)
    {
        flag = 0;
        for ( j = 1; j <= i; j++)
        {
            if (arr[j-1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                flag = 1;
            }
            if (flag == 0)
            {
                return;
            }         
        }      
    }   
}

//希尔排序
void shellSort(int arr[], int n)
{
    int i,j;
    int temp;
    for (int gap = n/2 ; gap > 0; gap/= 2)
    {
        for ( i = gap; i < n; i++)
        {
            temp = arr[i];
            for ( j = i; j>=gap && arr[j-gap] > temp; j-= gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }      
    }   
}

//快速排序: 递归算法
void quickSort(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int temp;
    if (low < high)
    {
        temp = arr[low];
        while(i < j)
        {
            while (i < j && arr[j] >= temp)
            {
                j--;
            }
            if (i < j)
            {
                arr[i] = arr[j];
                i++;
            }
            while (i < j && arr[i] < temp)
            {
                i++;
            }
            if (i < j)
            {
                arr[j] = arr[i];
                j--;
            }
        }
        arr[i] = temp;
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
    }
    
}