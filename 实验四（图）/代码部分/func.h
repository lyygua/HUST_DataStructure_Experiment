#pragma once 
#include "def.h"
#include "stdio.h"
#include "stdlib.h"
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
status DestroyGraph(ALGraph &G);
/*��������ͼG*/
int LocateVex(ALGraph G,KeyType u);
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
status PutVex(ALGraph &G,KeyType u,VertexType value); 
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
int FirstAdjVex(ALGraph G,KeyType u);
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
int NextAdjVex(ALGraph G,KeyType v,KeyType w);
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
status InsertVex(ALGraph &G,VertexType v); 
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
status DeleteVex(ALGraph &G,KeyType v); 
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
status InsertArc(ALGraph &G,KeyType v,KeyType w);
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
void visit(VertexType v);//���ʺ��� 
void DFS(ALGraph &G,int v);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
status initqueue(SqQueue& q);//��ʼ������ 
status enqueue(SqQueue& q,int i);//��Ӳ��� 
status dequeue(SqQueue& q,int &i);//���Ӳ��� 
status queueempty(SqQueue& q);//�ж϶����Ƿ�Ϊ�� 
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
void swap(int &a,int &b);//������ֵ
status SaveGraph(ALGraph G, char FileName[]);
//��ͼ������д�뵽�ļ�FileName��
status LoadGraph(ALGraph &G, char FileName[]);
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ� 
status AddGraph(LISTS &Lists,char ListName[]);
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
status RemoveGraph(LISTS &Lists,char ListName[]);
// Lists��ɾ��һ������ΪListName�����Ա�
int LocateGraph(LISTS Lists,char ListName[]);
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
void view(ALGraph& G);
