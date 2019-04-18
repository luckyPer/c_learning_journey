#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initSize 500

typedef int ElementType;
typedef struct SqQueue
{
    ElementType Data;
    int front, rear;    //记录头指针和尾指针, 其中尾指针尾元素的index + 1的位置, 防止为空的时候front 和rear 在一起
}SqQueue;   //会造成假溢出, 假溢出是指实际有剩余空间, 但rear指针已经到最后了, 使得无法再push, 是由于顺序队列的结构所造成的

//循环队列, 防止假溢出的情况, 形成首尾相连的情况
//入队: rear = (rear + 1)% maxsize
//出队: front = (front + 1)% maxsize
//队列满判定条件: ( rear + 1) % maxsize == front
//队列中元素个数: (rear - front + maxsize) % maxsize 
typedef struct CricleQueue
{
    ElementType Data[initSize];
    int front, rear; 
}CricleQueue;

bool push(CricleQueue *CQ, ElementType X)
{
    int maxsize = sizeof(initSize);
    if((CQ->rear + 1) % maxsize == CQ->front) return false;
    CQ->Data[CQ->rear] = X;
    CQ->rear = (CQ->rear + 1) % maxsize;
    return true;
}

bool pop(CricleQueue *CQ, ElementType X)
{
    int maxsize = sizeof(CQ);
    CricleQueue *p = CQ;
    if(CQ->rear == CQ->front) return false;
    X = CQ->Data[CQ->front];
    CQ->front = (CQ->front + 1) % maxsize;
    return true;
}

