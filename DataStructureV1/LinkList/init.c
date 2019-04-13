#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN sizeof(struct linkList1)

struct linkList1
{
    int data;
    struct linkList1 *next;   
};


void AddHeadLinkList(struct linkList1 *l1) {
    int x = 0;
    l2 = (struct linkList1*)malloc(LEN);
    struct linkList1 *s;
    l1->next = NULL;
    scanf("%d", &x);
    while(true){
        s = (struct linkList1*)malloc(LEN);
        s->data = x;
        s->next = l1->next;
        l1->next = s;
        scanf("%d", &x);
    }
}

void AddEndLinkList(struct linkList1 *l2)
{
    int x= 0;
    l2 = (struct linkList1*)malloc(LEN);
    struct linkList1 *s, *r=l2;
    while(true){
        scanf("%d", &x);
        s = (struct linkList1*)malloc(LEN);
        s->data = x;
        r->next = s;
        s = r;
        scanf("%d", &x);
    }   
    r->next = NULL;
}

void SearchLinkListNode(struct linkList1 *l2){
    int intLintNodeData = 1;
    struct linkList1 *s;
    s = l2; // 假设来 中有数据 且有 int data = 1 的数据

    while(s != NULL && s->data != intLintNodeData){
        s = s->next;
    }
}

void InsertLinkListNodeByIndex(struct linkList1 *l2, int index)
{
    index = 5;
    int j = 0 + 1;
    struct linkList1 *s = l2, *r;
    if(index <=0) return;
    while(s != NULL)
    {
        if(j == index)
        {
            r->next = s->next;
            s->next = r;
            break;
        }
        j++;
        s = s->next;
    }
}