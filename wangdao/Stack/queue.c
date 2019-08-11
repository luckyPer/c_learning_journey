#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 999


//page  81
typedef struct Stack
{
    int data[maxsize];
    int top;
}Stack;

typedef struct QNode
{
    int data[maxsize];
    int rear;
    int front;
    int tag;
}Queue;


//1
bool EnqueueTag(Queue *Q, int X)
{
    if ((Q->rear + 1) % maxsize != Q->front)
    {
        Q->data[Q->rear] = X;   
        Q->rear = (Q->rear + 1) % maxsize;
    }
    else
    {
        if (Q->tag == 1)
        {
           return false;
        }
        Q->data[Q->rear] = X;   
        Q->rear = (Q->rear + 1) % maxsize;
        Q->tag = 1;
    }
    return true;
}

bool DequeueTag(Queue *Q, int *X)
{
    if (Q->rear == Q->front && Q->tag == 0)
    {
        return false;
    }
    if (Q->tag == 1)
    {
        Q->tag = 0;
    }
    
    X = Q->data[Q->front];
    Q->front = (Q->front + 1) % maxsize;
    return true;
}

//2
void Push(Stack *S, int X);
void Pop(Stack *S, int *X);
bool StackEmpty(Stack *S);
bool StackOverflow(Stack *S);

void Enqueue(Queue *Q, int X);
void Dequeue(Queue *Q, int *X);
bool QueueEmpty(Queue *Q);

void reverse(Queue *Q, Stack *S)
{
    int X;
    while (!QueueEmpty(Q))
    {        
        Dequeue(Q, &X);
        Push(S, &X);
    }
    while (!StackEmpty(S))
    {
        Pop(S, X);
        Enqueue(Q, &X);
    }
}
