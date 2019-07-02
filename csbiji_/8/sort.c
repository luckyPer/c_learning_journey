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

//快速排序: 递归算法(通常选第一作为枢轴)
/*
 *@description: i = low, j = high, 若i< j, 选取i位置的元素作为枢轴, while loop.
 while loop, 从 j 向前找第一个不大于枢轴的元素(i<j) 时, 把 j的元素赋值给i 的
 while loop, 从 i 向后找第一个 大于枢轴的元素(i<j) 时, 把 i的元素赋值给j 的
 此时mid 为 i , 枢轴值赋值给i
 递归quickSort
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-07-02 22:33:12
*/
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


///堆排序: 
//堆: 完全二叉树, 非叶子结点值不大于(不小于) 其左右孩子的值
//数组下标从0 开始
/*
 *@description: i: low(父节点), j: 根据i 的第一个非叶子节点
 暂存low 位置的元素, 如果第一个非叶子节点的小于等于 high, while loop
 改变j 的位置(j < high , arr[j] 小于后一个元素) j++
 low 位置元素 < j位置的元素, 调整堆: i
 *@date: 2019-07-02 22:18:02
*/
void Sift(int arr[], int low, int high)
{
    int i = low;
    int j = i*2+1; 
    int temp = arr[i];
    while (j <= high)
    {
        if (j < high && arr[j] < arr[j+1])
        {
            j++;
        }
        if (temp < arr[j])
        {
            arr[i] = arr[j];
            i = j;
            j = i*2 + 1;
        }
    }
    arr[i] = temp;
}

void heapSort(int arr[], int n)
{
    int i, temp;
    //建立初始堆
    for ( i = n/2-1; i >=0; i--)
    {
        Sift(arr, i, n-1);
    }
    //把第一次建成的堆, 第一个元素放到数组的最后一位, 在进行 n-1 次 Silt ; 
    for ( i = n-1; i >0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp; 
        Sift(arr, 0, i-1);
    }
}



//二路归并排序
void MergeSort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

/*
 *@description: 从low 到 mid,  mid+1 到 high 两段有序的序列归并成一段有序序列
 开两个数组, 对应的arr 的index 复制进去
    left[mid - low + 1];
    right[high -mid];
 最后把整个arr 变得有序
 *@date: 2019-07-02 22:02:02
*/
void merge(int arr[], int low, int mid, int high)
{
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high -mid;
    int left[n1];
    int right[n2];
    for ( i = 0; i < n1; i++)
    {
        left[i] = arr[low+i];
    }
    for ( j = 0; i < n2; j++)
    {
        right[j] = arr[mid+1+j];
    }
    i =0; j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (right[j] < left[i])
        {
            arr[k] = right[j++];
        }
        else
        {
            arr[k] = left[i++];
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }   
}