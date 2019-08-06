#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//page 247


//6
int Binary_Search(int arr[], int low, int high, int key)
{
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

Binary_Search_Recursion(int arr[], int low, int high, int key)
{
    int mid = (low + high)/2;
    if (low > high) return -1;
    if (arr[mid] == key) return mid;
    else if(arr[mid] < key) Binary_Search_Recursion(arr, mid+1, high, key);
    else Binary_Search_Recursion(arr, low, mid-1, key);
}

//7
void SeqFreq(int arr[], int n, int key)
{
    int temp = 0;
    int i;
    for ( i = 0; i < n; i++)
    {
        if (i == 0)
        {
            return;
        }
        if(arr[i] == key)
        {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
}