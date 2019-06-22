#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

#define maxsize 99

/*
 *@description:顺序查找, 顺序表与链表都适合
 平均查找长度, 成功ASL1: (N+1)/2
              失败ASL2: N
 时间复杂度都为 o(n)
 *@params1: 数组
 *@params2: 数组长度
 *@params2: key
 *@return: key在数组中的下标
 *@date: 2019-06-22 19:57:17
*/
int search(int arr[], int n, int key)
{
    int i =0;
    for ( i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }        
    }
    return 0;
}


/*
 *@description: 折半查找, 要求查找的线性表示有序的, 查找mid
 *@params1: 数组
 *@params2: key
 *@return: key在数组中的下标
 *@date: 2019-06-22 20:04:17
*/
int BSearch(int arr[], int key, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }       
    }  
}

/*
 *@description:  分块查找

 *@date: 2019-06-22 20:10:07
*/
typedef struct 
{
    int maxkey;     //某个块中最大的元素
    int low, high;  //记录某个块中的第一个 和最后一个元素的位置
}indexElem;

indexElem index[maxsize];
