#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initSize  100
#define maxSize sizeof(struct SeqList)

typedef int ElementType;
typedef struct SeqList *list;

typedef struct SeqList
{
    ElementType Data[initSize];
    int Length;
};


list MakeEmpty()
{
    list node;
    node = (list)malloc(maxSize);
    node->Length = -1;
    return node;
}

int Find(ElementType X, list node)
{
    int i = 0;
    while(i <= node->Length && node->Data[i] != X)
    {
        i++;
    }
    if(i > node->Length) return -1;
    else return i;
}

void Insert(ElementType X, int index, list node)
{
    int i = 0;
    for(i = node->Length; index >= i; i--)
    {
        node->Data[i+1] = node->Data[i];
    }
    node->Data[index-1] = X;
    node->Length ++;
}

void Delete(int index, list node)
{
    int i = 0;
    for(i = index; i <= node->Length; i--)
    {
        node->Data[i-1] = node->Data[i];
    }
    node->Length --;
}

int main(int argc, char const *argv[])
{
    return 0;
}

