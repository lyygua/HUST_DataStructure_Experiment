#pragma once 
#include "def.h"
#include "stdio.h"
#include "stdlib.h"
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
status DestroyGraph(ALGraph &G);
/*销毁无向图G*/
int LocateVex(ALGraph G,KeyType u);
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
status PutVex(ALGraph &G,KeyType u,VertexType value); 
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
int FirstAdjVex(ALGraph G,KeyType u);
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
int NextAdjVex(ALGraph G,KeyType v,KeyType w);
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
status InsertVex(ALGraph &G,VertexType v); 
//在图G中插入顶点v，成功返回OK,否则返回ERROR
status DeleteVex(ALGraph &G,KeyType v); 
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
status InsertArc(ALGraph &G,KeyType v,KeyType w);
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
void visit(VertexType v);//访问函数 
void DFS(ALGraph &G,int v);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
status initqueue(SqQueue& q);//初始化队列 
status enqueue(SqQueue& q,int i);//入队操作 
status dequeue(SqQueue& q,int &i);//出队操作 
status queueempty(SqQueue& q);//判断队列是否为空 
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
void swap(int &a,int &b);//交换数值
status SaveGraph(ALGraph G, char FileName[]);
//将图的数据写入到文件FileName中
status LoadGraph(ALGraph &G, char FileName[]);
//读入文件FileName的图数据，创建图的邻接表 
status AddGraph(LISTS &Lists,char ListName[]);
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
status RemoveGraph(LISTS &Lists,char ListName[]);
// Lists中删除一个名称为ListName的线性表
int LocateGraph(LISTS Lists,char ListName[]);
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
void view(ALGraph& G);
