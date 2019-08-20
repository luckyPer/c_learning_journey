#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

#define maxsize 999
//113

typedef struct 
{
    int data;
    struct BtNode *lchild;
    struct BtNode *rchild;
}BtNode;

typedef struct LinkList
{
    char data;
    struct LinkList *next;
}LinkList;


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

//page 126

//16
void createTreeLink(BtNode *root, BtNode *head)
{
    if (root)
    {       
        BtNode *r = head;
        BtNode *stack[maxsize];
        BtNode *p = root;
        int top = -1;
        
        while (p || top != -1)
        {
            while (p->lchild)
            {
                stack[++top] = p;
                p = p->lchild;       
            }
            if (top != -1)
            {
                p = stack[--top];
                if (p->lchild == NULL && p->rchild == NULL)
                {
                    r->rchild = p;
                    r = p;
                }
                p = p->rchild;
            }
        }
    }
}


//17
bool JudgeSimiliarTree(BtNode *t1, BtNode *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return 1;
    }
    else if (t1 == NULL || t2 ==NULL)
    {
        return 0;
    }
    int l = JudgeSimiliarTree(t1->lchild, t2->lchild);
    int r = JudgeSimiliarTree(t1->rchild, t2->rchild);
    return l && r;
}


//18
int getWPL(BtNode *root)
{
    int wpl = 0, level = 0;
    if (!root)
    {
        return wpl;
    }
    BtNode *que[maxsize];
    BtNode *p;
    int rear = -1,front = -1, last = 0;
    que[++rear] = root;
    while (rear != front)
    {
        p = que[++front];
        if (!p->lchild && !p->rchild)
        {
            wpl += level * p->data;
        }       
        if (p->lchild)
        {
            que[++rear] = p->lchild;
        }
        if (p->rchild)
        {
            que[++rear]  = p->rchild;
        }
        if (last == front)
        {
            level ++;
            last = rear;
        }  
    }
    return wpl;
}


//20
int i =0;
int getOperation(BtNode *root, char *str)
{
    int A, B;
    if(root->lchild && root->lchild)
    {
        A = getOperation(root->lchild, str);
        B = getOperation(root->rchild, str);
        return op(A, B, root->data);
    }
    else
    {
        return root->data +'-';
    } 
}

int op(int A, int B, char op)
{
    int re;
    switch (op)
    {
    case '*':
        re = A * B;
        break;
    case '/':
        re = A / B;
        break;
    case '-':
        re = A - B;
        break;
    case '+':
        re = A + B;
        break;
    }
    return re;
}


//page 152

typedef struct 
{
    int data;
    CSNode *firstChild;
    CSNode *nextSilbling;
}CSNode;

// 5 递归求孩子兄弟表示法森林的叶子节点个数
int getleaves(CSNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->firstChild == NULL)
    {
        return 1 + getleaves(root->nextSilbling);
    }
    else
    {
        return getleaves(root->firstChild) + getleaves(root->nextSilbling);
    }
}


// 6 递归求孩子兄弟表示法树的深度

/// 注意最后的if 条件
int getdeep(CSNode *root)
{
    int ld, rd;
    if (root == NULL)
    {
        return 0;
    }
    ld = getdeep(root->firstChild);
    rd = getdeep(root->nextSilbling);
    if (ld + 1 > rd)
    {
        return ld + 1;
    }
    else
    {
        return rd;
    }   
}



/*----------------------------*/
//page 169
typedef struct BSTree
{
    int key;
    struct BSTree *lchild;
    struct BSTree *rchild;
}BSTree;


//6 判定是否为二×排序树
bool IsBSTree(BSTree *bst)
{
    BSTree *temp;
    if (bst == NULL)
    {
        return true;
    }
    else if (bst->lchild == NULL && bst->rchild ==NULL )
    {
        return true;
    }
    else if (bst->lchild && ! bst->rchild)
    {
        temp = bst->lchild;
        if (bst->key > temp->key)
        {
            return IsBSTree(bst->lchild);
        }
        else
        {
            return false;
        }
    }
    else if (!bst->lchild &&  bst->rchild)
    {
        temp = bst->rchild;
        if (bst->key < temp->key)
        {
            return IsBSTree(bst->rchild);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (bst->key < bst->lchild->key && (bst->key > bst->rchild->key))
        {
            return IsBSTree(bst->lchild) && IsBSTree(bst->rchild); 
        }
        else
        {
            return false;
        }        
    }     
}


//7 求出 指定节点 在二叉排序树中的层序
int getLevel(BSTree *bt, int key)
{
    int level = 0;
    BSTree *p = bt;
    while (p)
    {
        level ++;
        if (p->key == key)
        {
            break;
        }
        else if (key < p->key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return level;    
}


//8 判断平衡二叉树
/*
base case: 节点为空 ,true
case 1: 左右子树高度绝对值大于1 ,不是平和二叉树
case 2: 左右子树都是 平衡二叉树使
*/  
bool IsBlancedTree(BSTree *bt)
{
    if (bt == NULL)
    {
        return true;
    }
    int lh = getHeight(bt->lchild);
    int rh = getHeight(bt->rchild);
    if (abs(lh - rh) > 1)
    {
        return false;
    }
    return IsBlancedTree(bt->lchild) && IsBlancedTree(bt->rchild);
}

int getHeight(BSTree *bt)
{
    if (bt == NULL)
    {
        return 0;
    }
    int lh = getHeight(bt->lchild);
    int rh = getHeight(bt->rchild);
    return (lh > rh) ? lh + 1 : rh + 1;
}

//9 求出二叉排序树最大的关键字
BSTree *getMax(BSTree *bt)
{
    BSTree *p = bt;
    while (p)
    {
        if (p->rchild)
        {
            p = p->rchild;
        }
    }
    return p;
}


//10 求出在二叉排序树中不小于 k 的关键字, 从大到小
void getBiggerKVal(BSTree *bt, int k)
{
    BSTree *p = bt;
    int stack[maxsize];
    int top = -1;
    while (p)
    {
        if (k > p->key)
        {
            p = p->rchild;
        }
        else
        {
            stack[++top] = p->key;
        }
    }
    while (top != -1)
    {
        printf(stack[top--]);
    } 
}


//12 递归得到 第k 小的结点
typedef struct BSTreeCount
{
    int key;
    int count; //以该节点为根的 子结点个数
    struct BSTreeCount *lchild;
    struct BSTreeCount *rchild;
}BSTreeCount;

void getLastK(BSTreeCount *bt, int k)
{
    if (k < 1 || k > bt->count)
    {
        return NULL;
    } 
    if (bt->lchild ==NULL)
    {
        if (bt->count == 1)
        {
            return bt;
        }
        else
        {
            return getLastK(bt->rchild, k-1);
        }      
    }
    else{
        if (bt->lchild->count == k-1)
        {
            return bt;
        }
        if (bt->lchild->count > k)
        {
            return getLastK(bt->lchild, k);
        }
        if (bt->lchild->count < k-1)
        {   
            return getLastK(bt->rchild, k-bt->lchild->count-1);
        }
    }  
}
 