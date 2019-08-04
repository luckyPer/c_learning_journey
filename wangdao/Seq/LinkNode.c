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

typedef struct DBLinkNode
{
    int data;
    struct DBLinkNode *left; 
    struct DBLinkNode *right; 
}DBLinkNode;

typedef struct SLinkNode
{
    int data;
    struct SLinkNode *next; 
}SLinkNode;

int main(int argc, char const *argv[])
{
    struct LinkNode *head = (LinkNode*)malloc(sizeof(LinkNode));;
    struct LinkNode *a = (LinkNode*)malloc(sizeof(LinkNode));;
    a->data = 1;
    struct LinkNode *b = (LinkNode*)malloc(sizeof(LinkNode));;
    b->data = 2525;
    a->next = b;
    head ->next = a;
    // while (head)
    // {
    //     head = head->next;
    //     printf("%d\n",head->data);
    // }
    LinkNode *p = head;
    p ->next = NULL;
        while (head)
    {
        head = head->next;
        printf("%d\n",head->data);
    }
    return 0;
}


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

//15
//两个链表升序, 
//时间复杂度 O(A+B)  
//空间: O(1)
void Union(LinkNode *A, LinkNode *B)
{
    LinkNode *pa = A->next;
    LinkNode *pb = B->next;
    LinkNode *pre = A;
    LinkNode *r;
    while (pa && pb)
    {
        if(pa->data == pb->data)
        {
            pre->next = pa;
            pre = pa;
            pa = pa->next;
            r = pb;
            pb = pb->next;
            free(r);
        }
        else if(pa->data < pb->data)
        {
            r = pa;
            pa = pa->next;
            free(r);
        }
        else
        {
            r = pb;
            pb = pb->next;
            free(r);
        }        
    }
    while (pa)
    {
        r = pa;
        pa = pa->next;
        free(r);
    }
    while (pb)
    {
        r = pb;
        pb = pb->next;
        free(r);
    }
    pre->next = NULL;   
}


//16
void judge(DBLinkNode *head)
{
    DBLinkNode *tail = head->left;
    DBLinkNode *p = head->right;
   
    while (tail != p && tail != p->right)
    {
        if (tail->data == p->data)
        {
            tail = tail->left;
            p = p->right;
        }
        else
        {
            break;
        }     
    }   
}

//18
void connectTS(SLinkNode *h1, SLinkNode *h2)
{
    if(h1->next == h1 || h2->next == h2) return;

    SLinkNode *p1 = h1;
    SLinkNode *p2 = h2;
    while (p2->next != h1)
    {
        p2 = p2->next;
    }
    p1 ->next = p2->next;
    while (p2->next != h2)
    {
        p2 = p2->next;
    }
    p2->next = h1;
}

void deleteMin(SLinkNode *head)
{
    SLinkNode *p = head;
    SLinkNode *minPre;
    SLinkNode *min;
    while (p->next != head)
    {
        minPre = p;
        min = p->next;
        while (p->next != head)
        {
            if (p->next->data < min->data)
            {
                min = p->next;
                minPre = p;
            }
            p = p->next;
        }
        minPre->next = minPre->next->next;
        free(min);
    }
    free(head);
}

//21
void getKPosition(LinkNode *list, int k)
{
    int len = 0;
    int resP = 0;
    LinkNode *p = list->next;
    while (p)
    {
        len ++;
        p = p->next;
    }
    resP = len - k +1;
    if(resP > 0)
    {
        int i = 1;
        p = list->next;
        while (p)
        {
            if(i == resP) 
            {
                printf(p);
            }
            i++;
        }    
    }
    else
    {
        printf("error");
    }
}

//21 one time loop
void getKPosition(LinkNode *list, int k)
{
    LinkNode *p = list->next;
    LinkNode *q = list->next;
    int count =0;
    while (p)
    {
        if (count < k)
        {
            count++;
        }
        else
        {
            q = q->next;
        }
        p = p->next;
    }
    if(count < k) return;
    else
    {
        printf(q);
    }   
}


//22
void getSameTail(LinkNode* str1, LinkNode* str2)
{
    LinkNode *p1 = str1->next;
    LinkNode *p2 = str2->next;
    LinkNode *r;
    while (p1)
    {
        while (p2)
        {
            if(p1->data == p2->data)
            {
                r = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                p2 = p2->next;
                r = NULL;
            }
        }
        p1 = p1->next;
        p2 = str2->next;
    } 
}


//23

