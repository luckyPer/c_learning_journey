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