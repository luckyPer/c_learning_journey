#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

#define maxsize 99
#define INF 9999999

/*
 *@description: 邻接矩阵
 *@date: 2019-06-13 19:44:57
*/
typedef struct 
{
    int no;
    char info;
}VexTexType;    //顶点类型

 //图的邻接矩阵类型
typedef struct 
{
    int edges[maxsize][maxsize];
    int n, e;
    VexTexType vex[maxsize];
}MGrapgh;  


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
    int count; //统计顶点当前的入度
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


/*
 *@description:普利姆最小代价生成树算法. key: lowcost数组(与v0相关的边的权值) 和 vest数组, 
 用v0来初始化这两个数组, 把v0加入树中. 外层loop,  内层再又两个loop, 第一个loop找lowcost数组里比min小的值, 
 找到顶点 index后, 各种赋值. 最后一个loop 在跟新lowcost 
 *@params1: 无向图, 邻接矩阵类型
 *@params2: 当前顶点
 *@params3: sum总和
 *@date: 2019-06-14 19:51:18
*/
void prim(MGrapgh G, int v0, int *sum)
{
    int lowcost[maxsize], vset[maxsize];
    int i,j,k,v,min;
    v = v0;
    for (i = 0; i < G.n; i++)
    {
        vset[i] = 0;
        lowcost[i] = G.edges[v0][i];
    }
    vset[v] = 1;
    sum = 0;
    for (i = 0; i < G.n-1; i++)
    {
        for (j = 0; j< G.n; j++)
        {
            min = INF;
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }            
        }
        v = k;
        vset[v] = 1;
        sum += min;
        for (j = 0; j < G.n; j++)
        {
            if (vset[j] == 0 && G.edges[v][j] < lowcost[j])
            {
                lowcost[j] = G.edges[v][j];
            }        
        }      
    }   
}

//图: 反应两节点间和权值的关系
typedef struct 
{
    int w; //权重
    int a, b; //a b 的两个顶点
}Road;

Road road[maxsize]; 
int parent[maxsize];//并查集数组

/*
 *@description:并查集中查找根节点
 *@params1: 当前节点index
 *@return: 当前节点index对应的根节点
 *@date: 2019-06-15 20:13:12
*/
int getRoot(int a)
{
    while (a != parent[a])
    {
        a = parent[a];
    }
    return a;
} 

/*
 *@description: 初始化parent, 和road(按照权值由小到大排序), loop(边的个数), 取得对应的a b边, 再并查集, 如果 a ,b不相等,则能够加入
 *@params1: 无向图, 邻接矩阵类型
 *@params2: sum总和
 *@params3: road数组 数据结构
 *@date: 2019-06-15 20:20:17
*/
void Kruskal(MGrapgh g, int *sum, Road road[])
{
    int i = 0;
    int a,b;
    sum = 0;
    for ( i = 0; i < g.n; i++)
    {
        parent[i] = i;
    }
    sort(road, g.e);
    for ( i = 0; i < g.e; i++)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b)
        {
            parent[a] = b;
            sum += road[i].w;
        }     
    }  
}


//迪杰斯特拉算法: 图中某一顶点到其余各边的最短路径
/*
 *@description: 初始化三个数组:
 dist: v0 到vi 的最短权值, 没有则为无穷
 path: 最短路径上 vi 的前一个顶点, 没有则为 -1
 set: 0;
 把 v0 放入, loop 
 loop 找到vet[i] 为 0, v0 与 vi 的最小权值, 把此vi 设置为v, 放入路径中
 再loop vet[j] 为 0,比较 dist[i] + g,edges[i][j] (当前loop 中的顶点) < dist[j], 则跟新dist  ,path
 *@params1: 邻接矩阵
 *@params2: v0: 某一个顶点
 *@params3: dist: v0 到vi 的最短权值
 *@params3: path: 最短路径上 vi 的前一个顶点
 *@date: 2019-06-16 20:02:03
*/
void Dijkestra(MGrapgh g, int v0, int dist[], int path[])
{
    int set[maxsize];
    int i = 0, j=0;
    int min;
    int v;
    for ( i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v0][i];
        set[i] = 0;
        if (g.edges[v0][i] < INF)
        {
            path[i] = v0;
        }
        else
        {
            path[i] = -1;
        }        
    }
    set[v0] = 1;
    path[v0] = -1;
    for ( i = 0; i < g.n-1; i++)
    {
        min = INF;
        for ( j = 0; j < g.n; j++)
        {
            if(dist[j] < min && set[j] == 0)
            {
                v = j;
                min = dist[j];
            }
        }
        set[v] = 1;
        for ( j = 0; j < g.n; j++)
        {
            if(set[j] == 0 && dist[v] + g.edges[v][j] < dist[j])
            {
                dist[j] = dist[v] + g.edges[v][j];
                path[j] = v;
            }
        }       
    }   
}

/*弗洛伊德算法求解 某一顶点(任意) 到其余各边的最短路径
 *@description: 设置两个矩阵 A, path, A 用来存放任意两个顶点最短路径的长度, path 存放 两顶点间最短路径上要经过的顶点(中间顶点). 两个loop 初始化 A, path. 三层loop A[i][j] > A[i][k] + A[k][j]
 *@params1: 邻接矩阵
 *@params2: 最短路径进过的顶点, 初始值为-1
 *@date: 2019-06-17 20:49:44
*/
void Floyad(MGrapgh g, int path[][maxsize])
{
    int i,j,k;
    int A[maxsize][maxsize];
    for ( i = 0; i < g.n; i++)
    {
        for ( j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            path[i][j] = -1;
        }
        
    }
    
    for ( k = 0; k < g.n; k++)
    {
         for ( i = 0; i < g.n; i++)
        {
            for ( j = 0; j < g.n; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }              
            }
        }
    }  
}

/*AOV NETWORK */
// typedef struct 
// {
//     char data;
//     int count; //统计顶点当前的入度
//     ArcNode *firstarc;
// }VNode;

/*拓扑排序
 *@description: 需要一个栈, 一个for loop, 把入度为0 的顶点入栈. 若栈不为空, 则出栈, 顶点号赋予 i, 计数加一, 
 把顶点i 的第一条边赋予p, while loop, 顶点指向的边的入度减一, 
 *@params1: 邻接表
 *@return: 计数 n = 领接表的顶点数 return 1
 *@date: 2019-06-17 21:11:02
*/
int TopSort(AGrapgh *g)
{
    int i,j,n = 0;
    ArcNode *p = NULL;
    int stack[maxsize]; int top = -1;
    for ( i = 0; i < g->n; i++)
    {
        if (g->ArcList[i].count == 0)
        {
            stack[++top] = i;
        }
    }
    while (top != -1)
    {
        i = stack[top--];
        ++n;
        p = g->ArcList[i].fristNode;
        while (p)
        {
            j = p->adjvex;
            (g->ArcList[j].count)--;
            if (g->ArcList[j].count == 0)
            {
                stack[++top] = j;
            }
            p = p->nextArc;
        }
    }
    if (n == g->n)
    {
        return 1;
    }
    return 0;
}