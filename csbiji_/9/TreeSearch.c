#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>


/** 二叉排序树 */
//若左子树存在, 则左子树的key < 根的key, 右子树大于 根的key
typedef struct 
{
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;    
}BTNode;


/*
 *@description: 查找关键字, 递归方式
 *@params1: 二叉排序树
 *@params2: key
 *@return: key所在节点
 *@date: 2019-06-22 20:14:44
*/
BTNode * BTSearch(BTNode *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        if (p->key == key)
        {
            return p;
        }
        else if (key < p->key)
        {
            return BTSearch(p->lchild, key);
        }
        else
        {
            return BTSearch(p->rchild, key);            
        }        
    }    
}

/*
 *@description: 二叉排序树插入
 *@params1: 二叉排序树
 *@params2: key
 *@return: 0 1
 *@date: 2019-06-22 20:43:11
*/
int BSTInsert(BTNode *p, int key)
{
    if (p == NULL)
    {
        p = (BTNode*)malloc(sizeof(BTNode));
        p->lchild = NULL;
        p->rchild = NULL;
        return 1;
    }
    else
    {
        if (key == p->key)
        {
            return 0;
        }
        else if (key < p->key)
        {
            BSTInsert(p->lchild, key);
        }
        else
        {
            BSTInsert(p->rchild, key);            
        }
    }
}

/*
 *@description: 构造二叉排序树
 *@params1: 二叉排序树
 *@params2: key数组
 *@params3: 数组长度
 *@date: 2019-06-22 20:47:32
*/
void createBST(BTNode *P, int KEY[], int n)
{
    for (int i = 0; i < n; i++)
    {
        BSTInsert(&P, KEY[i]);
    }  
}