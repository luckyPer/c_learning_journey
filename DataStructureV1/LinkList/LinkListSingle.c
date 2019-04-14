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
    l1 = (struct linkList1*)malloc(LEN);
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

struct linkList1 *SearchLinkListNodeByIndex(struct linkList1 *l2, int index)
{  
    int j = 0 + 1;
    struct linkList1 *s;
    if(index <= 0) return;
    s = l2->next;
    while(s != NULL && j < index)
    {
        j++;
        s = s->next;
    }
    return s;
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

void deleteLinkListNodeByIndex(struct linkList1 *l2, int index)
{
    int j = 0 + 1;
    struct linkList1 *deleteNode = SearchLinkListNodeByIndex(l2, index);
    struct linkList1 *r = (struct linkList1*)malloc(LEN);
    r = deleteNode->next;
    deleteNode->next = r->next;
    free(r);
}

struct linkList1 *initlinkList1()
{
    int x= 0;
    struct linkList1 *head = (struct linkList1*)malloc(LEN);
    struct linkList1 *s, *r=head;
    while(true){
        printf("input x");
        scanf("%d", &x);
        if(x == 0) break;
        s = (struct linkList1*)malloc(LEN);
        s->data = x;
        r->next = s;
        r = s;
    }   
    r->next = NULL;
    return head;
}
int main(int argc, char const *argv[])
{
    struct linkList1 *mainLinkList = initlinkList1();
    struct linkList1 *SearchLinkListNode = SearchLinkListNodeByIndex(mainLinkList, 2);
    deleteLinkListNodeByIndex(mainLinkList, 2);
    return 0;
}
