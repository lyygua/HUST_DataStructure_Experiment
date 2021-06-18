#pragma once 
status strcopy(char a[],char b[]);
//复制字符串 
status CreateBiTree(BiTree &T,Def definition[]);
//status MyCreateBiTree(BiTree &T,TElemType definition[]);
status ClearBiTree(BiTree &T);
//将二叉树设置成空，并删除所有结点，释放结点空间
int BiTreeDepth(BiTree T);
//求二叉树T的深度
BiTNode* LocateNode(BiTree T,KeyType e);
//查找结点
status Assign(BiTree &T,KeyType e,TElemType value);
//实现结点赋值。
BiTNode* GetSibling(BiTree T,KeyType e);
//实现获得兄弟结点
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
//插入结点。
status initstack(SqStack &s);
//初始化栈 
status gettop(SqStack &s,BiTree &e);
//获取栈顶元素 
status push(SqStack &s,BiTree e);
//栈顶元素出栈 
status pop(SqStack &s,BiTree &e);
//入栈 
status stackempty(SqStack &s);
//判断栈是否为空 
status findtheright(BiTree &T,BiTree &p);
//找二叉树最右结点 
status DeleteNode(BiTree &T,KeyType e);
//删除结点
void visit(BiTree T);
//访问函数，输出结点的关键字和内容 
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
//递归实现先序遍历二叉树T
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
//递归实现中序遍历二叉树T
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
//非递归实现 后序遍历二叉树T
status enqueue(SqQueue &q,BiTree e);
//入队列 
status dequeue(SqQueue &q,BiTree &e);
//出队列 
status queueempty(SqQueue q);
//判空 
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));
//按层遍历二叉树T
status Create_BiTree(BiTree &T,Def definition[]); 
//创建二叉树 
status enqueue(SqQue &q,Que e);
//进入队列 
status dequeue(SqQue &q,Que &e);
//出队 
status queueempty(SqQue q);
//队列判空 
status MyLevelOrderTraverse(BiTree T,FILE* out);
//按层保存二叉树，由按层遍历二叉树改进而来 
status SaveBiTree(BiTree T, char FileName[]);
//将二叉树的结点数据写入到文件FileName中
status LoadBiTree(BiTree &T, char FileName[]);
//读入文件FileName的结点数据，创建二叉树
status AddList(LISTS &Lists,char ListName[]);
//在Lists中增加一个名称为ListName的空线性表
status RemoveList(LISTS &Lists,char ListName[]);
// Lists中删除一个名称为ListName的线性表
int LocateList(LISTS Lists,char ListName[]);
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
