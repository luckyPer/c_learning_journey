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
    A = A-1;
    int temp;
    int i;
    for ( i = A; i < B; i++)
    {
        temp = arr[i];
        arr[i] = arr[B-i-1];
        arr[B-i-1] = temp;
    }  
}

void exchange(int *arr, int m, int n)
{
    reverseFromAtoB(arr,1,m-1);
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