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
 *@description: 二叉树非递归 先 序遍历. 需要一个栈 ---- 从根节点开始, 入栈一个节点, 不停地执行以下操作: 若栈不为空, 就出栈一个元素,
 并且访问该元素, 然后把左右孩子入栈(非空判断, 注意顺序 :右孩子先, 左孩子后)
 *@params1: BtNode : 二叉树
 *@return: Void
 *@date: 2019-06-04 21:31:26
*/
void PreOrderNoneR(BTNode *bt)
{
    if (bt)
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
}

/*
实质: 求出先序遍历序列, 后序遍历序列, 再把后序遍历序列改为逆后序遍历序列, 然后再逆序打印出逆后序序列即可
其中用到两个栈, 第一个栈stack1 用来辅助做逆后序遍历, 再把遍历结果序列压入第二个stack2 
 *@description:二叉树非递归 后 序遍历.---- 从根节点开始, 入栈一个节点, 不停地执行以下操作: 若栈不为空, 就出栈一个元素,
 并且访问该元素, 然后把左右孩子入栈(非空判断, 注意顺序 :左孩子先, 右孩子后)
 *@params1: BtNode : 二叉树
 *@return: Void
 *@date: 2019-06-04 21:49:51
*/
// void PostOrderNoneR(BTNode *bt)
// {
//     if (bt)
//     {
//         //定义两个栈
//         BTNode *stack1[maxsize];
//         BTNode *stack2[maxsize];
//         int top1 = -1;
//         int top2 = -1;
//         stack1[++top1] = bt;
//         BTNode *p = NULL;
//         while (top1 != -1)
//         {
//             p = stack1[top1--];
//             stack2[top2++] = p;
//             if (p->lchild)
//             {
//                 stack1[++top1] = p->lchild;
//             }
//             if (p->rchild)
//             {
//                 stack1[++top1] = p->rchild;
//             }
//         }
//         while (top2 != -1)
//         {
//             p = stack2[top2--];
//             visit(p);
//         }       
//     }    
// }
/*
 *@description: 二叉树非递归 后 序遍历
一个栈, 两个指针, p = bt, r = 指向最近访问过的节点
先访问左子树
当左子树为空时
p = stack[top] p 取栈第一个元素
若右子树存在, 且未被访问过, 转向右,右入栈, 在走到最左
若右子树为空, 访问栈第一个结点, r=p,记录最近访问过的结点, 重置p
 *@date: 2019-08-09 19:57:59
*/
void PostOrderNoneR(BTNode *bt)
{
    BTNode *p = bt;
    BTNode *r;
    BTNode *stack[maxsize];
    int top = -1;
    while (p || top != -1)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->lchild;
        }
        else
        {
            p = stack[top];
            if (p->rchild && p->rchild != r)
            {
                p = p->rchild;
                stack[++top] = p;
                p = p->lchild;
            }
            else
            {
                p = stack[top--];
                visit(p);
                r = p;
                p = NULL;
            }      
        }  
    }  
}




/*
 *@description: 中序遍历二叉树 非递归, 需要一个栈.  从根节点开始 ,沿着左子树路径一直全部入栈. 
 若栈不为空,  则出栈并访问出栈元素, 在指向右孩子. loop
 *@params1: BtNode : 二叉树
 *@return: Void
 *@date: 2019-06-05 19:34:46
*/
void inorderNoneR(BTNode *BT)
{
    BTNode *stack[maxsize];
    int top = -1;
    BTNode *p = NULL;
    p = BT;
    while (top != -1 || p)
    {
        while (p)
        {
            stack[++top] = p;
            p = p->lchild;
        }
        if (top != -1)
        {
            p = stack[top--];
            visit(p);
            p = p->rchild;
        }      
    }    
}

/*
 *@description: 层次遍历二叉树, 需要一个队列. 先从根结点入队, 若队列不为空, 把队列第一个元素 出队, 
 左右孩子不为空的话, 左右孩子入队列, loop   
 *@params1: BtNode : 二叉树
 *@return: Void
 *@date: 2019-06-05 19:56:54
*/
void level(BTNode *BT)
{
    if (BT == NULL)
    {
        return;
    }    
    BTNode *que[maxsize];
    BTNode *p = NULL;
    int rear = 0;
    int front = 0;
    
    rear = (rear + 1) % maxsize;
    que[rear] = BT;
    while (front != rear)
    {
        front = (front + 1) % maxsize;
        p = que[front];
        visit(p);
        if (p->lchild)
        {
            rear = (rear + 1) % maxsize;
            que[rear] = p->lchild;
        }
        if (p->rchild)
        {
            rear = (rear + 1) % maxsize;
            que[rear] = p->rchild;
        }
    }
}