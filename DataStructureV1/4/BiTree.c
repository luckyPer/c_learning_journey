#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef char ElemType;
typedef struct BiTree
{
    ElemType Data;
    struct BiTree *lchild, *rchild;
}BiTree, *PBiTree;


// 二叉树遍历 (递归)

//先序递归
void PreOrder(PBiTree T) {
    if(T) {
        printf("%C", T->Data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序递归
void InOrder(PBiTree T) {
    if(T) {
        InOrder(T->lchild);
        printf("%C", T->Data);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(PBiTree T) {
    if(T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%C", T->Data);
    }
}


//二叉树遍历 (非递归) 