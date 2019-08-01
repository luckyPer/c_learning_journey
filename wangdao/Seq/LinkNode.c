#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct LinkNode
{
    int data;
    struct LinkNode *next; 
}LinkNode;

//
void DeleteX(LinkNode *L, int X)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
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
}