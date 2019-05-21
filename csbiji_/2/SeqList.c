#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef struct SeqList
{
    int data[MaxSize];
    int lenght;
}SeqList;

//顺序表逆值
void reserveNumber(SeqList *s)
{
    int i,j,temp;
    for (i = 0, j = s->lenght - 1; i < j; i++, j--)
    {
        temp = s->data[i];
        s->data[i] = s->data[j];
        s->data[j] = temp;
    }
}

//求最大值
void getMax(SeqList *s)
{
    int max = s->data[0];
    int maxId = 0;
    for (int i = 0; i < s->lenght; i++)
    {
        if (max < s->data[i])
        {
            max = s->data[i];
            maxId = i;
        }        
    }
    
}

//归并, 两个数组,都是升序排列好的
void meger(int arr1[], int n1, int arr2[], int n2)
{
    int i,j,k;
    int result[n1+n2];
    for (i = 0, j = 0, k = 0; i < n1 && j < n2; k++)
    {
        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i++];
        }
        else
        {
            result[k] = arr1[j++];
        }       
    }
    while (i<n1)
    {
        result[k] = arr1[i++];
    }
    while (j<n2)
    {
        result[k] = arr1[j++];
    }
}

//划分, 就是选一个元素当枢轴

// 1 用第一个元素充当枢轴, 要求 划分成左右两部分, 左边部分要小于枢轴, 右边部分要大于枢轴, 并且枢轴位于中间
void divideByFirst(int arr[], int n)
{
    int pivot = arr[0];
    int low = 0;
    int high = n - 1;
    while (low < high)
    {   
        while (low < high && arr[high] <= pivot) high--;
        if (low < high)
        {
            arr[low] = arr[high];
            low ++;
        }
        while (low < high && arr[low] >= pivot) low++;    
        if (low < high)
        {
            arr[high] = arr[low];
            high --;
        }     
    }  
    arr[low] = pivot; 
}