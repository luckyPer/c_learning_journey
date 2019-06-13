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
 *@description:图的深度优先遍历. 先定义一个全局的visit数组(类似于flag的作用, 以免重复访问), 初始值都为0
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
    p = G->ArcList[v].fristNode;    //指向顶点index为v对应的第一条边
    while (p)
    {
        if(visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextArc;
    }
}