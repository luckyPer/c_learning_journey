#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

#define maxsize 999
//113

typedef struct 
{
    int data;
    struct BtNode *lchild;
    struct BtNode *rchild;
}BtNode;

typedef struct LinkList
{
    char data;
    struct LinkList *next;
}LinkList;


//5求两个编号的最近公共结点 
//默认j> i
int getAncestor(int i, int j)
{
    while(j != i)
    {
        if (i > j)
        {
            i = i/2;
        }
        else
        {
            j = j/2;
        }
    }
    return i; 
}

//page 126

//16
void createTreeLink(BtNode *root, BtNode *head)
{
    if (root)
    {       
        BtNode *r = head;
        BtNode *stack[maxsize];
        BtNode *p = root;
        int top = -1;
        
        while (p || top != -1)
        {
            while (p->lchild)
            {
                stack[++top] = p;
                p = p->lchild;       
            }
            if (top != -1)
            {
                p = stack[--top];
                if (p->lchild == NULL && p->rchild == NULL)
                {
                    r->rchild = p;
                    r = p;
                }
                p = p->rchild;
            }
        }
    }
}


//17
bool JudgeSimiliarTree(BtNode *t1, BtNode *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return 1;
    }
    else if (t1 == NULL || t2 ==NULL)
    {
        return 0;
    }
    int l = JudgeSimiliarTree(t1->lchild, t2->lchild);
    int r = JudgeSimiliarTree(t1->rchild, t2->rchild);
    return l && r;
}


//18
int getWPL(BtNode *root)
{
    int wpl = 0, level = 0;
    if (!root)
    {
        return wpl;
    }
    BtNode *que[maxsize];
    BtNode *p;
    int rear = -1,front = -1, last = 0;
    que[++rear] = root;
    while (rear != front)
    {
        p = que[++front];
        if (!p->lchild && !p->rchild)
        {
            wpl += level * p->data;
        }       
        if (p->lchild)
        {
            que[++rear] = p->lchild;
        }
        if (p->rchild)
        {
            que[++rear]  = p->rchild;
        }
        if (last == front)
        {
            level ++;
            last = rear;
        }  
    }
    return wpl;
}


//20
int i =0;
int getOperation(BtNode *root, char *str)
{
    int A, B;
    if(root->lchild && root->lchild)
    {
        A = getOperation(root->lchild, str);
        B = getOperation(root->rchild, str);
        return op(A, B, root->data);
    }
    else
    {
        return root->data +'-';
    } 
}

int op(int A, int B, char op)
{
    int re;
    switch (op)
    {
    case '*':
        re = A * B;
        break;
    case '/':
        re = A / B;
        break;
    case '-':
        re = A - B;
        break;
    case '+':
        re = A + B;
        break;
    }
    return re;
}