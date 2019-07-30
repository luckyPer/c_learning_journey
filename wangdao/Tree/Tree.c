#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

typedef struct 
{
    int data;
    struct BtNode *lchild;
    struct BtNode *rchild;
}BtNode;

typedef struct BSTNode
{
    int val;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
}BSTNode;
/*
 *@description: 判断一课二叉树是否是 平衡二叉树
 时间复杂度 nlogN 
 *@params1: BtNode
 *@return: 0/1
 *@date: 2019-07-25 22:38:24
*/
int IsBalenced(BtNode *bt)
{
    if(bt == NULL) return 1;
    int leftHeight = getHeight(bt->lchild);
    int rightHeight = getHeight(bt->rchild);
    if(ads(leftHeight - rightHeight) > 1) return 0;
    return IsBalenced(bt->lchild) && IsBalenced(bt->rchild);
}

int getHeight(BtNode *bt)
{
    if (bt == NULL) return 0;
    int leftHeight = getHeight(bt->lchild);
    int rightHeight = getHeight(bt->rchild);
    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight +1);
}

/*
 *@description: 求出给定二叉排序树的最大值和最小值
 最右下即为最大;
 最左下即为最小.
 *@date: 2019-07-25 22:53:13
*/
int getMax(BSTNode *bst)
{
    while (bst)
    {
        bst = bst->lchild;
    }
    return bst->val;
}

/*
 *@description: 判断二叉树是否为 二叉排序树
 递归中序遍历, 使前一个值要比后一个值小
 *@date: 2019-07-25 22:55:56
*/
int pre;//初始为负无穷
int IsBST(BSTNode *bst)
{
    int b1;
    if (!bst)
    {
        return 1;
    }
    b1 = IsBST(bst->lchild);
    if (b1 != 1 || pre >= b1)
    {
        return 0;
    }
    pre = b1;
    return IsBST(bst->rchild);
}