#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//page 38
typedef struct LinkNode
{
    int data;
    struct LinkNode *next; 
}LinkNode;

//1 Recursion
void DeleteX(LinkNode *L, int X)
{
    if (L == NULL)
    {
        return;
    }
    if (L->data == X)
    {
        LinkNode *S = L;
        L = L->next;
        free(S);
        DeleteX(L,X); 
    }   
    else
    {
        DeleteX(L->next,X); 
    }    
}


//2 None Recursion
void deleteXNoneRecursion(LinkNode *l, int X)
{
    LinkNode *s;
    LinkNode *p = l;
    while (p->next!=NULL)
    {
        if (p->next->data == X)
        {
            s = p->next;
            p->next = s->next;
            free(s);
        }
        else
        {
            p = p->next;
        }        
    }
}


//3
void reversePrint(LinkNode  *p)
{
    if (p->next == NULL)
    {
        printf(p->data);
    }
    reversePrint(p->next);
}


//4
void deleteMIN(LinkNode *head)
{
    LinkNode *min = head;
    LinkNode *pre = head;
    LinkNode *p = head->next;
    while (p != NULL)
    {
        if (min ->next->data > p->data)
        {
            min = pre;
        }
        pre = pre->next;
        p = p->next;
    }
    p = min->next;
    min->next = min->next->next;
    free(p);
}


//5
void reverseLinkNode(LinkNode *head)
{
    LinkNode *r;
    LinkNode *p = head ->next;
    head ->next = NULL;
    while (p)
    {
        r = p->next;
        p ->next = head->next;
        head ->next = p;
        p = r;
    }
}

//6
void ascendLinkeNode(LinkNode *head)
{
    LinkNode *pre;
    LinkNode *p = head->next;
    LinkNode *r = p->next;
    p->next = NULL; //断链
    p = r;
    while (p)
    {
        r = p->next;
        pre = head;
        while (pre ->next && pre->next->data < p->data)
        {
            //找到插入p 结点的合适位置: 1. pre 到达 链表末尾, p 就插在 pre 之后
                                    //2. pre 到达 最后一个 比 p 小的位置 
            pre = pre ->next;
        }
        p->next = pre ->next;
        pre ->next = p;
        p = r;
    }
}


//7
void deleteFromAToB(LinkNode *head, int A, int B)
{
    LinkNode *p = head->next;
    LinkNode *pre = head;
    LinkNode *r;
    while (p)
    {
        if (p->data > A && p->data < B)
        {
            r = p;
            p = p->next;
            pre->next = p;
            free(r);
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    } 
}

//8

//9
void ascendPrinf(LinkNode *head)
{
    LinkNode *p = head->next;
    LinkNode *pre;
    LinkNode *r  = p->next;
    p->next = NULL;
    p = r;
    while (p)
    {
        r = p->next;
        pre = head;
        while (pre->next && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    p = head->next;
    while (p)
    {
        printf(p->data);
        r = p;
        p = p->next;
        head->next = p;
        free(r);
    } 
}


//10
void split(LinkNode *A)
{
    LinkNode *B = (LinkNode*)malloc(sizeof(LinkNode));
    B->next = NULL;
    LinkNode *p = A;
    LinkNode *q;
    LinkNode *r;
    while (p->next)
    {
        if (p->next->data % 2 == 0)
        {
            q = p->next;
            p->next = p->next->next;
            q->next = NULL;
            B ->next = q;
        }
        else
        {
            p = p->next;
        }    
    }
}

//11?

//12 链表题设有序
void deleteSameNode(LinkNode *head)
{
    LinkNode *p;
    LinkNode *pre = head;   
    while (pre->next)
    {   
        if (pre->data == NULL)
        {
            break;
        }       
        if (pre->data == pre->next->data)
        {
            p = pre->next;
            pre->next = pre->next->next;
            free(p);
        }
        else
        {
            pre = pre->next;
        }    
    }   
}

//13


//14
void getCommonEle(LinkNode *A, LinkNode *B, LinkNode*C)
{
    LinkNode *a = A->next,*b = B->next;
    LinkNode *q,*r;
    r = C;
    while (a && b)
    {
        if (a->data < b->data)
        {
            a = a->next;
        }
        else if (b->data < a->data)
        {
            b = b->next;
        }
        else
        {
            q = (LinkNode *) malloc(sizeof(LinkNode));
            q->data = a->data;
            r->next = q; 
            r = q;
            a = a->next;
            b = b->next;
        }       
    }    
}