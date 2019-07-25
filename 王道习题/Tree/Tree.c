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