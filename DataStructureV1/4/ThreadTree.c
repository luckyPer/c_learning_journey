#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 500

typedef char ElemType;
typedef struct ThreadTree
{
    ElemType Data;
    struct ThreadTree *lchild, *rchild;
    int ltag, rtag;
}ThreadTree, *PThreadTree;

//中序遍历初始化线索二叉树
void initThreadTree(PThreadTree p, PThreadTree pre) {
    if(p)
    {
        initThreadTree(p->lchild, pre);
        if(p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre && pre->rchild == NULL)
        {
            pre->rchild = pre;
            pre->rtag = 1;
        }
        pre = p;
        initThreadTree(p->rchild, pre);

    }
}

//中序遍历线索二叉树
void InOrderThreadTree(PThreadTree T) {
    PThreadTree P = T;
    while (P)
    {
        while (P->ltag == 0)
        {
            P = P->lchild;
        }     
        printf("%C", P->Data);
        while (P->rchild && P->rtag == 1)
        {
            P = P->rchild;
            printf("%C", P->Data);
        }
        P = P->lchild;
    }
}