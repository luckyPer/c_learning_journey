#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 500

typedef char ElemType;
typedef struct BiTree
{
    ElemType Data;
    struct BiTree *lchild, *rchild;
}BiTree, *PBiTree;

typedef struct Stack
{
    ElemType data[MaxSize];
    int top;
};
void PushStack(struct Stack *p, PBiTree T) {}
void PopStack(struct Stack *p, PBiTree T) {}
void GetStack(struct Stack *p, PBiTree T) {}
bool IsEmptyStack(struct Stack *p) {}
struct Stack * initStack()
{
    struct Stack * s;
    return s; 
}

struct Queue
{
    ElemType Data[MaxSize];
    int front, rear;
};
void PushQueue(struct Queue *q, PBiTree T) {}
void PopQueue(struct Queue *q, PBiTree T) {}
void GetQueue(struct Queue *q, PBiTree T) {}
bool IsEmptyQueue(struct Queue *q) {}
struct Queue * initQueue()
{
    struct Queue * q;
    return q; 
}

// 二叉树遍历 (递归)

//先序递归
void PreOrder(PBiTree T) {
    if(T) {
        printf("%C", T->Data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序递归
void InOrder(PBiTree T) {
    if(T) {
        InOrder(T->lchild);
        printf("%C", T->Data);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(PBiTree T) {
    if(T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%C", T->Data);
    }
}


//二叉树遍历 (非递归) 

//非递归先序遍历
void PreOrderTraverse(PBiTree T) {
    PBiTree P = T;
    struct Stack *s = initStack();
    while (P || !IsEmptyStack(s))
    {
        while (P)
        {
            printf("%C", P->Data);
            PushStack(s, P);
            P = P->lchild;
        }
        if(!IsEmptyStack(s))
        {
            PopStack(s, P);
            P = P->rchild;
        }
    }    
}

//非递归中序遍历
void InOrderTraverse(PBiTree T) {
    PBiTree P = T;
    struct Stack *s = initStack();
    while (P || !IsEmptyStack(s))
    {
        while (P)
        {
            PushStack(s, P);
            P = P->lchild;
        }
        if(!IsEmptyStack(s))
        {
            PopStack(s, P);
            printf("%C", P->Data);
            P = P->rchild;
        }
    }   
}

//非递归后序遍历
void PostOrderTraverse(PBiTree T) {
    PBiTree P = T, r  = NULL;
    struct Stack *S = initStack();
    while (P || !IsEmptyStack(S))
    {
        if(P)
        {
            PushStack(S, P);
            P = P->lchild;
        }
        else 
        {
            GetStack(S, P);
            if(P->rchild && P->rchild != r)
            {
                P = P->rchild;
            }
            else 
            {
                PopStack(S, P);
                printf("%C", P->Data);
                r = P;
                P = NULL;
            }
        }
    }   
}

//层序遍历
void LevelOrder(PBiTree T) {
    PBiTree P = T, r  = NULL;
    struct Queue *Q = initQueue();
    PushQueue(Q, P);
    while (!IsEmptyQueue(Q))
    {
        PopQueue(Q, P);       
        printf("%C", P->Data);
        if (P->lchild)
        {
            PushQueue(Q, P->lchild);
        }
        if (P->rchild)
        {
            PushQueue(Q, P->rchild);
        }               
    }   
}