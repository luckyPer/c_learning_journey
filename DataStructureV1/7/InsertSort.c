#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//直接插入排序
//最好时间负载度  n
//最坏时间负载度: n^2
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

//折半插入排序
//最好时间复杂度: nlogn
//最坏时间复杂度: n^2
void  HalfInsertSort(int arr[], int n)
{
    int i,j,low,mid,high;
    for (int i = 2; i < n; i++)
    {
        arr[0] = arr[i];
        low = 1;
        high = i-1;
        while (low <= high)
        {
            mid = (high + low)/2;
            if (arr[0] < arr[mid])
            {
                high = mid -1;
            }
            else 
            {
                low = mid + 1;
            }
        }
		for (j = i-1; j >= high+1; --j)
		{
			arr[j+1] = arr[j];
		}
		arr[high +1 ] = arr[0];
    }    
}

//希尔排序
//最好时间复杂度: n^1.3
//最坏时间复杂度: n^2
void ShellSort(int arr[], int n)
{
	//增量是 dk
	int dk,i,j;
	for (dk = n/2; dk >= 1; dk = dk/2)
	{
		for (i = dk + 1; i <= n; ++i)
		{
			if(arr[i] < arr[i-dk])
			{
				arr[0] = arr[i];
				for (j = i - dk; j > 0 && arr[0] < arr[j]; j -= dk)
				{
					arr[j+dk] = arr[j];
				}
				arr[j+dk] = arr[0];
			}
		}		
	}	
}