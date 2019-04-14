#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN sizeof(struct linkList)

struct linkList
{
    int data;
    struct linkList *next, *prev;   
};

void AddlinkList(int index)
{
    int j = 1;
    struct linkList *head = (struct linkList*)malloc(LEN);
    struct linkList *s, *r;
    s = head->next;
    while(s && j < index)
    {
        j++;
        s = s->next;
    }
    r->next = s->next;
    s->next->prev = r;
    r->prev = s;
    s->next = r;
}


//core code
void AddlinkList(int index)
{
    int j = 1;
    struct linkList *head = (struct linkList*)malloc(LEN);
    struct linkList *s, *r = (struct linkList*)malloc(LEN);
    //a1  ->  a2  ->  a2 
    //s    <-  r    <-   
    r = s->next;
    s->next = r->next;
    r->next->prev = s;
    free(r);
}