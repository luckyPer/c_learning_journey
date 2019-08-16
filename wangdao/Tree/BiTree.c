#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>


//113

typedef struct 
{
    int data;
    struct BtNode *lchild;
    struct BtNode *rchild;
}BtNode;


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