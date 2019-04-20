#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 静态分配

#define initSize  100
#define maxSize 10000
typedef int ElementType;
typedef struct 
{
    ElementType data[initSize];
    ElementType length;
}SeqList1;

//动态分配

typedef struct SeqList2
{
    ElementType *data;
    ElementType Maxsize, length;
}SeqList2;


int main(int argc, char const *argv[])
{
    SeqList2 l2;
    l2.data = (ElementType *)malloc(sizeof(ElementType) * initSize);
    
}

bool InsertList(SeqList2 *l2, int index)
{
    bool flag = false;
    if(index < 1 || index > l2->length+1) 
        return flag;
    if(l2->length >= maxSize)
        return flag;
    for(int j = l2->length; j >=index ;j++)
    {
        l2->data[j] = l2->data[j-1];
    }
    l2->data[index - 1] = "ele";  
    l2->length ++;
    flag = true;
    return flag;
}

bool DeleteList(SeqList2 *l2, int index)
{
    bool flag = false;
    for(int j = index; j < l2->length ;j++)
    {
        l2->data[j-1] = l2->data[j];
    }
    l2->length--;
    flag = true;   
    return flag;
}


