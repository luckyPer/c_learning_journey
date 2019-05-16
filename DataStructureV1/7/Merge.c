#include <stdio.h>
#include <stdlib.h>

//暴露接口
void msort(int A[], int low, int high)
{
    int *B = (int *)malloc(high * sizeof(int));
    MergerSort(A, B, low, high);
}

void MergerSort(int A[], int B[], int low, int high)
{
    //分治法
    if (low < high)
    {
        int mid = (low + high)/2;
        MergerSort(A, B, low, mid);
        MergerSort(A, B, mid+1, high);
        Merge(A, B,low,mid,high);
    }  
}
void Merge(int A[], int B[], int low, int mid, int high)
{
    int k,i,j;
    for (k = low; k <= high; k++)   //A 复制到 B中
    {
        B[k] = A[k];
    }
    for (i = low, j = mid+1, k = i; i <=mid && j<=high ; k++)   //一分为二
    {
        if(B[i] <= B[j])    //比较B 左右两边的元素
        {
            A[k] = B[i++];
        }
        else 
        {
            A[k] = B[j++];
        }
    }
    while (i<=mid)  //防止两个数组大小有差异, 没有检测完其中一个
    {
        A[k] = B[i++];
    }
    while (j<=high)
    {
        A[k] = B[j++];
    }    
}
