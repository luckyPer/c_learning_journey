#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

//邻接矩阵表示法
typedef struct 
{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;     //图的当前顶点数和弧数
};


//邻接表法

//顶点表
typedef struct 
{
    VertexType data[MaxVertexNum];
    PVnode firstVert;
}ArcNode, *ArcList[MaxVertexNum];

//表边
typedef struct 
{
    int adjvex;     //该弧所指向的顶点的位置
    VertexType AdjVexData[MaxVertexNum];
    PVnode next;
}VNode, *PVnode;

//图
typedef struct 
{
    ArcList ver;
    int vexnum, edgenum
}ArcGraph;


//十字链表法

//==弧表结点
typedef struct 
{
    int tailvexindex, headvexindex;
    PArcNode headLink, tailLink;    //弧头相同 和弧尾相同
}ArcNode, *PArcNode;

//==顶点表结点
typedef struct 
{
    VertexType data[MaxVertexNum];
    PArcNode firstout, firstin;     //入弧, 出弧
}ArcList, PArcList[MaxVertexNum];

//图
typedef struct Graph
{
    PArcList arclist;
    int vexnum, edgenum;
};


//邻接多重表
//--边表结点
typedef struct 
{
    int ivexindex, jvexindex;
    ArcNode *ivexlink, *jvexlink;
}ArcNode;

//--顶点表结点
typedef struct 
{
    VertexType data[MaxVertexNum];
    ArcNode *firstedge;
}VNode;

//--图表
typedef struct 
{
    VNode arclist[MaxVertexNum];
    int vexnum, edgenum; 
}Graph;




 
