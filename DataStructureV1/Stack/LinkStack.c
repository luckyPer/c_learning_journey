#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initSize  1000
#define maxSize sizeof(struct StackNode)

typedef int ElementType;

typedef struct StackNode
{   
    ElementType Data;
    struct StackNode *Next;     //栈顶指针
}StackNode , *SNode;        //链栈节点

typedef struct LinkStack
{
    SNode top;   //栈顶指针
    int count;
}LinkStack;  //链栈

LinkStack * InitStack()
{
    LinkStack *LS;
    LS = (LinkStack *)malloc(maxSize);
    LS->count = 0;
    LS->top = NULL;
    return LS;
}

bool PushStack(LinkStack *Ls, ElementType X)
{
    SNode p = (SNode)malloc(maxSize);
    p->Data = X;
    p->Next = Ls->top;
    Ls->top = p;
    Ls->count ++;
    return true;
}

bool PopStack(LinkStack *Ls, ElementType *X)
{
    if(Ls->top == NULL) return false;
    SNode p = (SNode)malloc(maxSize);
    p = Ls->top;
    X = Ls->top->Data;
    Ls->top = Ls->top->Next;
    Ls->count--;
    free(p);
    return true;
}

