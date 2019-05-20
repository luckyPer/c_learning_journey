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
