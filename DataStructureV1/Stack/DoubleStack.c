#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initSize  1000
#define maxSize sizeof(struct DoubleStack)

typedef struct DoubleStack *Node;
typedef int ElementType;
typedef struct DoubleStack
{
    ElementType Data[initSize];
    int top1;   //1号栈底, 当 top1 == -1 时 为空
    int top2;   //2号栈底, 当 top2 == maxSize 时 为空
};

bool IsEmptyDoubleStack(Node S)
{
    if(S->top1 + 1 == S->top2) return false;
    return true;
}

bool PushDoubleStack(ElementType X, Node S, int StackNum)
{
    if(IsEmptyDoubleStack(S)) return false;
    if(StackNum == 1)
    {
        S->Data[++S->top1] = X;
    }
    else 
    {
        S->Data[--S->top2] = X;
    }
    return true;
}