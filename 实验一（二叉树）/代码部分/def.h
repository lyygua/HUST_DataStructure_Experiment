#pragma once 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXQSIZE 100

typedef int status;
typedef int KeyType;
 
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //二叉树结点类型定义

typedef struct BiTNode{  //二叉链表结点的定义
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct{  //森林的管理表定义
    struct { 
		char name[30];
    	BiTree L;	
	} elem[20];
    int length;
    int listsize;
 }LISTS;

typedef struct {
    int pos;
    TElemType data;
} Def;

typedef struct{
    int pos;
    BiTree tree;
}Que;

typedef struct{
    Que* base;
    int front;
    int rear;
}SqQue;

typedef struct{
    BiTree* base;
    BiTree* top;
    int stacksize;
}SqStack;

typedef struct{
    BiTree* base;
    int front;
    int rear;
}SqQueue;
