#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct LinkList
{
    char data;
    struct LinkList *next;
}LinkList;

typedef struct DoubleLinkList
{
    int data;
    struct DoubleLinkList *leftLink;
    struct DoubleLinkList *rightLink;
}DoubleLinkList;


//链表逆值, 逆值 q->next 到 q 之间的结点
    // while(p->next != q)
    // {
    //     t = p->next;
    //     p->next = t->next;
    //     t->next = q->next;
    //     q->next = t;
    // }

//去链表最大值
void getMax(LinkList *head)
{   
    LinkList *s = head->next, *q;  
    int max;
    if (!s)
    {
        return;
    }
    max = s->data;
    q = s;
    while (s->next)
    {
        if(max < s->data)
        {
            max = s->data;
            q = s;
        }   
        s = s->next;
    }
} 

void scanWordCreateList()
{   LinkList *head, *s;
    int n;
    char word;
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    scanf("&n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &word);
        s = s->next;
        while (s)
        {
            if (word == s->data)
            {
                break;
            }
            s= s->next;            
        }
        if(s == NULL)
        {
            s = (LinkList * )malloc(sizeof(LinkList));
            s->data = word;
            s->next = head->next;
            head->next = s;         
        }             
    } 
}


//求双链表中最大的结点,并移至到最前边
void getMaxAndPutFront(DoubleLinkList *head)
{
    DoubleLinkList *p = head->rightLink, *s = p;
    int max = p->data;
    while (p->rightLink)
    {
        if(max < p->data)
        {
            max = p->data;
            s = p;
        }
        p = p->leftLink;
    }
    DoubleLinkList *l = s->leftLink;
    DoubleLinkList *r = s->rightLink;
    l->rightLink = r;
    if(r)
    {
        r->leftLink = l;
    }
    s->rightLink = head->rightLink;
    s->leftLink = head;
    head->rightLink = s;
    s->rightLink->leftLink = s;
}

//归并 尾插法
//归并, 两个数组,都是升序排列好的
void mergeR(LinkList *head1, LinkList *head2, LinkList **head)
{
    LinkList *p = head1->next;
    LinkList *q = head2->next;
    LinkList *r = head;
    
    while (p && q)
    {
        if (p->data < q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = r->next;
            q = q->next;
        
        }              
    }
    if (p)
    {
        r->next = p;
    }
    if (q)
    {
        r->next = q;
    }
    r->next = NULL;
}

//归并 头插法
//归并, 两个数组,都是升序排列好的
void mergeH (LinkList *head1, LinkList *head2, LinkList *head)
{
    LinkList *p = head1->next;
    LinkList *q = head2->next;
    LinkList *s;
    head = head1;
    head->next = NULL;
    
    while (p && q)
    {
        if (p->data < q->data)
        {
            s = p;
            s->next = head->next;
            head->next = s;
            p = p->next;
        }
        else
        {
            s= q;
            s->next = head->next;
            head->next = s;
            q = q->next;
        }              
    }
    while (p)
    {   
        s = p;
        s->next = head->next;
        head->next = s;
        p = p->next;
    }
    while (q)
    {   
        s= q;
        s->next = head->next;
        head->next = s;
        q = q->next;
    }  
}