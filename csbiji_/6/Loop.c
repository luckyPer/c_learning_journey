#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxsize 100

typedef struct 
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
}BTNode;

void visit(BTNode *P){}


/*
 *@description: 二叉树非递归先序遍历.---- 从根节点开始, 入栈一个节点, 不停地执行以下操作: 若栈不为空, 就出栈一个元素,
 并且访问该元素, 然后把左右孩子入栈(非空判断, 注意顺序 :右孩子先, 左孩子后)
 *@params1: BtNode : 二叉树
 *@return: Void
 *@date: 2019-06-04 21:31:26
*/
void PreOrderR(BTNode *bt)
{
    BTNode *stack[maxsize];
    int top = -1;
    stack[++top] = bt;
    BTNode *p = NULL;
    while (top != -1)
    {
        p = stack[top--];
        visit(p);
        if (p->rchild)
        {
            stack[++top] = p->rchild;
        }
        if (p->lchild)
        {
            stack[++top] = p->lchild;
        }
    }
}