#pragma once 
#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1	
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
    KeyType  key;
    char others[20];
} VertexType; //顶点类型定义


typedef struct ArcNode {         //表结点类型定义
   	int adjvex;              //顶点位置编号 
    struct ArcNode  *nextarc;	   //下一个表结点指针
} ArcNode;

typedef struct VNode{				//头结点及其数组类型定义
   	VertexType data;       	//顶点信息
    ArcNode *firstarc;      	 //指向第一条弧
} VNode,AdjList[MAX_VERTEX_NUM];

typedef  struct {  //邻接表的类型定义
    AdjList vertices;     	 //头结点数组
    int vexnum,arcnum;   	  //顶点数、弧数
    GraphKind  kind;        //图的类型
} ALGraph;

typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;

typedef struct{  //森林的管理表定义
    struct { 
		char name[30];
    	ALGraph L;	
	} elem[20];
    int length;
    int listsize;
 }LISTS;

