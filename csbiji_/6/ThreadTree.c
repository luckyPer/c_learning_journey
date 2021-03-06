#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *rchild, *lchild;
    int ltag, rtag;   
}ThreadNode;

/*
 *@description: 构造中序线索二叉树 ,递归化过程. 
 *@params1: p 二叉树
 *@params2: pre 指向中序遍历上一个刚访问过的结点, 初始值wei空
 *@return: Void
 *@date: 2019-06-06 19:26:23
*/
void InThread(ThreadNode *p, ThreadNode *pre)
{
    if (p)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }   
}

/*
 *@description: 先序线索化二叉树
 *@params1: 
 *@params2: 
 *@return: 
 *@date: 2019-06-06 20:04:38
*/
void PreThread(ThreadNode *p, ThreadNode *pre) 
{
    if (p)
    {
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && p->rchild == NULL)
        {
            p->rchild = pre;
            p->rtag = 1;
        }
        pre = p;
        if (p->ltag == 0)
        {
            PreThread(p->lchild, pre);
        }
        if (p->rtag == 0)
        {
            PreThread(p->rchild, pre);    
        } 
    }   
}