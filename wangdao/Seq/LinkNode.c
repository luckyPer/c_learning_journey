#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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