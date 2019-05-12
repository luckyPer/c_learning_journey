#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void InsertSort(int arr[], int n)
{
    int i,j;
    for (i = 2; i < n; i++)     //数组从2开始, 第0位是用作临时标志位, 第1位是默认为有序的
    {
        if(arr[i] < arr[i-1])   //当前i 与前一位比较
        {
            arr[0] = arr[i];    //做临时标志位
            for (j = i-1; arr[0] < arr[j]; --j)
            {
                arr[j+1] = arr[j];  //向后移位
            }
            arr[j+1] = arr[0];
        }
    }
    
}