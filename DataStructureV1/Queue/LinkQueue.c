#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN sizeof(struct LinkQueueNode)

//为方便操作, 队列的链式结构 始终有一个头结点, 并且 front 始终指向它
typedef int ElementType;
typedef struct LinkQueueNode
{
    ElementType Data;
    struct LinkQueueNode *Next;
}LinkQueueNode, *LQNode;

typedef struct LinkQueue
{
    LQNode front;
    LQNode rear;
}LinkQueue;

LinkQueue * initQueue()
{
    LinkQueue *lq;
    lq->front = lq->rear = (LQNode*)malloc(LEN);
    lq->front->Next = NULL;
    return lq;
}

void push(LinkQueue *lq, ElementType X)
{
    LQNode P;
    P->Data = X;
    P->Next = NULL;
    lq->rear->Next = P;
    lq->rear = P;
}

// Caution: 链式队列中只有一个结点的时候, 要修改rear 结点指向front
void pop(LinkQueue *lq, ElementType X)
{
    if(lq->front == lq->rear) return false;
    LQNode P = lq->front->Next;
    X = P->Data;
    lq->front = lq->front->Next;
    if(lq->front->Next == lq->rear) lq->rear = lq->front;
    free(P);
}

