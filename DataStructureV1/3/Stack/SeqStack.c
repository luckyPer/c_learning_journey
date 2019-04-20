#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initSize  1000
#define maxSize sizeof(struct SeqStack)

typedef int ElementType;
typedef struct SeqStack 
{
    ElementType Data[initSize];
    int top;    //栈顶指针
};

typedef struct SeqStack *Node;

bool StackIsEmpty(Node S)
{
    bool flag = true;
    if(S->top == -1) return flag;
    return !flag;
}

bool PushStack(ElementType X, Node S)
{
    if(S->top == maxSize) return false;
    else S->Data[++S->top] = X; return true; 
}

bool PopStack(ElementType X, Node S)
{
    if(StackIsEmpty(S))
        return false;
    else 
    {
        X = S->Data[S->top--];
        return true;
    }
}