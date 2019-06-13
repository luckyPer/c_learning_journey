#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxsize 99

/*
 *@description: 邻接矩阵
 *@date: 2019-06-13 19:44:57
*/
typedef struct 
{
    int no;
    char info;
}VexTexType;    //顶点类型

typedef struct 
{
    int edges[maxsize][maxsize];
    int n, e;
    VexTexType vex[maxsize];
}MGrapgh;   //图的邻接矩阵类型


/*
 *@description: 邻接表
 *@date: 2019-06-13 19:49:31
*/
typedef struct 
{
    int adjvex; //边指向结点的index
    struct ArcNode *nextArc;
}ArcNode;

typedef struct
{
    char data;
    struct ArcNode *fristNode;
}VNode;

typedef struct
{
    VNode ArcList[maxsize];
    int n, e;
}AGrapgh;

/*
 *@description: 打印结点信息index
 *@date: 2019-06-13 19:58:57
*/
PrintfV(int v)
;
/*
 *@description:图的深度搜索遍历.  先定义一个全局的visit数组(类似于flag的作用, 以免重复访问), 初始值都为0.
 此为递归算法, 先访问第一个结点, 再指向顶点index为v对应的第一条边, 若不为空, 进入循环. 循环中若当前边还未被访问,
 递归调用DFS. 最后当前边在指向下一条边.
 *@params1: 图的邻接表链式结构
 *@params2: 起点的index
 *@date: 2019-06-13 19:53:52
*/
int visit[maxsize];
void DFS(AGrapgh *G, int v)
{
    ArcNode *p;
    visit[v] = 1;
    PrintfV(v);
    p = G->ArcList[v].fristNode;    
    while (p)
    {
        if(visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextArc;
    }
}


/*
 *@description: 图的广度搜索遍历. 需要一个循环队列, 先访问第一个结点, 把这个结点入队列, 若队列不为空,出队, 
 指向出队结点(实质是存的是index的第一条边, 若此第一条边未被访问过, 则进队, 访问. p都要指向p的下一条边.
 *@params1: 图的邻接表链式结构
 *@params2: 起点的index
 *@params3: visit数组
 *@date: 2019-06-13 20:13:48
*/
void BFS(AGrapgh *G, int v, int visit[])
{
    ArcNode *p;
    int que[maxsize], front = 0, rear = 0;
    int queFornt;
    PrintfV(v);
    visit[v] = 1;
    rear = (rear + 1) % maxsize;
    que[rear] = v;
    while (rear != front)
    {
        front = (front + 1) % maxsize;
        queFornt = que[front];
        p = G->ArcList[queFornt].fristNode;
        while (p)
        {
            if (visit[p->adjvex] == 0)
            {
                PrintfV(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) %maxsize;
                que[rear] = p->adjvex;
            }           
            p = p->nextArc;
        }    
    }  
}