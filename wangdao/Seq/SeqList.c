#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int arr[8] = {1,3,3,4,25,25,25,405};
    deleteRepeated(arr,8);
    return 0;
}
// //page 18

// //global 
int arr[];
int count;

//1
void deleteMinNum()
{
    int min;
    if (count == 0)
    {
        printf("Null");
        exit(0);
    }
    min = 0;
    for (int i = 1; i < count; i++)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
    }
    arr[min] = arr[count-1];
    count--;
}

//2
void reverse(int *arr, int count)
{
    int temp;
    for (int i = 0; i < count/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[count-i-1];
        arr[count-i] = temp;
    }  
}

//3
void deleteX(int X)
{
    int i;
    int k = 0;
    for ( i = 0; i < count; i++)
    {   
        if(arr[i] == X)
        {
            k++;
        }
        else
        {
            arr[i-k] = arr[i];
        }
    }
    count = count-k;
}

//4
//数组有序
void deleteSFromT(int s, int t, int *arr, int count)
{
    int i;
    int k =0;
    if(s >= t || count == 0)
    {
        return;
    }
    for ( i = 0; i < count; i++)
    {
        if (arr[i] >= s && arr[i] <= t)
        {
            k++;
        }
        else
        {
            arr[i-k] = arr[i];
        }
    }
}


//5
//数组无序
void deleteSFromTNoneSeq(int s, int t, int *arr, int count)
{
    int i;
    int k =0;
    if(s >= t || count == 0)
    {
        return;
    }
    for ( i = 0; i < count; i++)
    {
        if (arr[i] >= s && arr[i] <= t)
        {
            k++;
        }
        else
        {
            arr[i-k] = arr[i];
        }
    }
}


//6
void deleteRepeated(int *arr, int count)
{
    int i;
    int k = 0;
    // for (i = 1; i < count; i++)
    // {
    //     if (arr[k] != arr[i])
    //     {          
    //         arr[++k] = arr[i];
    //     }
    // }
    int pre = arr[0];
    for ( i = 1; i < count; i++)
    {
        if (arr[i] == pre)
        {
            k++;
        }
        else 
        {
            arr[i-k] = arr[i];
        }
        pre = arr[i];
    }  
}

//7
void merge(int *arr1, int count1,int *arr2, int count2, int *C)
{ 
    int i = 0,j = 0;
    int clen = 0;
    while (i < count1 && j < count2)
    {
        if (arr[i] <= arr[j])
        {
            C[clen++] = arr1[i++];
        }
        else
        {
            C[clen++] = arr2[j++];
        }
    }
    while (i < count1)
    {
        C[clen++] = arr1[i++];
    }
    while (j < count2)
    {
        C[clen++] = arr2[j++];
    } 
}

//8
void reverseFromAtoB(int *arr, int A, int B)
{
    int temp;
    int i;
    for ( i = 0; i < (B-A+1)/2; i++)
    {
        temp = arr[A+i];
        arr[A+i] = arr[B-i];
        arr[B-i] = temp;
    }  
}

void exchange(int *arr, int m, int n)
{
    reverseFromAtoB(arr,0,m-1);
    reverseFromAtoB(arr,m,n-1);
    reverse(arr,m+n);
}

//9
void BSearchAndInsert(int *arr, int n, int X)
{
    int i;
    int mid;
    int low =0;
    int high = n;
    while (low < high)
    {
        mid = (high + low)/2;
        if (arr[mid] >= X)
        {
            high = mid -1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    if (arr[mid] == X && mid != n-1)
    {
        arr[mid] = arr[mid+1];
        arr[mid+1] = X;
    }
    else
    {
        for ( i = n-1; i > high ; i++)
        {
            arr[i+1] = arr[i];
        }
        arr[mid] = X;
    }
}


//10
//先逆前p个元素, 和p 到n-1 的元素
//再整体逆值
void converse(int *arr, int n , int p)
{
    reverseFromAtoB(arr, 0, p-1);
    reverseFromAtoB(arr, p, n-1);
    reverseFromAtoB(arr, 0, n-1);
}


//11
int getMID(int A[],int B[], int n)
{
    int res;
    int C[2*n];
    int i=0,j=0;
    int k=0 ;
    while (i< n && j < n)
    {
        if (A[i] <= B[j])
        {
           C[k++] =  A[i++]; 
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (i< n)
    {
        C[k++] =  A[i++]; 
    }
    while (j< n)
    {
        C[k++] =  B[j++];
    }
    res = C[n+1];
}

//13
int getMininteger(int A[], int n)
{
    int *B = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            B[A[i]-1] = 1;
        }
    }
    int i ;
    for ( i = 0; i < n; i++)
    {
        if (B[i] == 0)
        {
            break;
        }
    }
    return i+1;
}