#pragma once 
status strcopy(char a[],char b[]);
//�����ַ��� 
status CreateBiTree(BiTree &T,Def definition[]);
//status MyCreateBiTree(BiTree &T,TElemType definition[]);
status ClearBiTree(BiTree &T);
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
int BiTreeDepth(BiTree T);
//�������T�����
BiTNode* LocateNode(BiTree T,KeyType e);
//���ҽ��
status Assign(BiTree &T,KeyType e,TElemType value);
//ʵ�ֽ�㸳ֵ��
BiTNode* GetSibling(BiTree T,KeyType e);
//ʵ�ֻ���ֵܽ��
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
//�����㡣
status initstack(SqStack &s);
//��ʼ��ջ 
status gettop(SqStack &s,BiTree &e);
//��ȡջ��Ԫ�� 
status push(SqStack &s,BiTree e);
//ջ��Ԫ�س�ջ 
status pop(SqStack &s,BiTree &e);
//��ջ 
status stackempty(SqStack &s);
//�ж�ջ�Ƿ�Ϊ�� 
status findtheright(BiTree &T,BiTree &p);
//�Ҷ��������ҽ�� 
status DeleteNode(BiTree &T,KeyType e);
//ɾ�����
void visit(BiTree T);
//���ʺ�����������Ĺؼ��ֺ����� 
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
//�ݹ�ʵ���������������T
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
//�ݹ�ʵ���������������T
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
//�ǵݹ�ʵ�� �������������T
status enqueue(SqQueue &q,BiTree e);
//����� 
status dequeue(SqQueue &q,BiTree &e);
//������ 
status queueempty(SqQueue q);
//�п� 
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));
//�������������T
status Create_BiTree(BiTree &T,Def definition[]); 
//���������� 
status enqueue(SqQue &q,Que e);
//������� 
status dequeue(SqQue &q,Que &e);
//���� 
status queueempty(SqQue q);
//�����п� 
status MyLevelOrderTraverse(BiTree T,FILE* out);
//���㱣����������ɰ�������������Ľ����� 
status SaveBiTree(BiTree T, char FileName[]);
//���������Ľ������д�뵽�ļ�FileName��
status LoadBiTree(BiTree &T, char FileName[]);
//�����ļ�FileName�Ľ�����ݣ�����������
status AddList(LISTS &Lists,char ListName[]);
//��Lists������һ������ΪListName�Ŀ����Ա�
status RemoveList(LISTS &Lists,char ListName[]);
// Lists��ɾ��һ������ΪListName�����Ա�
int LocateList(LISTS Lists,char ListName[]);
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
