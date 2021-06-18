#include "def.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
status strcopy(char a[],char b[]){//复制字符串 
    int i=0;
    for(i=0;b[i]!='\0';i++){
        a[i]=b[i];
    }
    a[i]='\0';
    return OK;
}
status CreateBiTree(BiTree &T,Def definition[])//创建二叉树 
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       	p[j]->data=definition[i].data;
       	p[j]->lchild=NULL;
       	p[j]->rchild=NULL;
       	if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   	else      p[j/2]->lchild=p[j];
       	i++;
    }
    T=p[1];
    return OK;
}

//status MyCreateBiTree(BiTree &T,TElemType definition[])
///*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
//如果有相同的关键字，返回ERROR。*/
//{
//    static int i=0;
//    static int num[20];
//    int j=0;//数组循环变量
//    static int sum=0;//统计key的变量
//    int tar;
//    
//    if(T){
//    	return ERROR;
//	}
//
//    if(definition[i].key==0){
//        T=NULL;
//        i++;
//        return OK;
//    }else{
//        //先判断关键字是否重复
//        for(j=0;j<sum;j++){
//            if(definition[i].key==num[j]){
//                return ERROR;
//            }
//        }
//        num[j]=definition[i].key;
//        sum++;
//        //创建树
//        if(!(T=(BiTree)malloc(sizeof(BiTNode)))){
//            exit(OVERFLOW);
//        }
//        T->data.key=definition[i].key;
//        strcopy(T->data.others,definition[i].others);
//        i++;
//        if(!CreateBiTree(T->lchild,definition)){
//            return ERROR;
//        }
//        if(!CreateBiTree(T->rchild,definition)){
//            return ERROR;
//        }
//    }
//    return OK;
//}

status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    if(T==NULL){
        return OK;
    }else{
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        free(T);
        T=NULL;
        return OK;
    }
}

status InitTree(BiTree &T){//初始化二叉树 
	if(T){
		ClearBiTree(T);
	}
	T=(BiTree)malloc(sizeof(BiTNode));
	T->lchild=NULL;
	T->rchild=NULL;
	T->data.key=0;
	return OK;
}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    int lh=0,rh=0;
    
    if(T==NULL){
        return 0;
    }else{
        lh=BiTreeDepth(T->lchild);
        rh=BiTreeDepth(T->rchild);
        return (lh>rh)?(lh+1):(rh+1);
    }
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    BiTree p;
    if(T==NULL){
        return NULL;
    }
    p=LocateNode(T->lchild,e);
    if(p){
        return p;
    }
    p=LocateNode(T->rchild,e);
    if(p){
        return p;
    }
    if(T->data.key==e){
        return T;
    }
    return NULL;
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。
{
    BiTree p,q;
    p=LocateNode(T,e);
    if(!p){//关键字不存在
        return ERROR;
    }
    q=LocateNode(T,value.key);
    if(q!=NULL&&p!=q){//关键字重复
        return ERROR;
    }else{
        p->data=value;
        return OK;
    }
}

BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    if(T==NULL){
        return NULL;
    }

    BiTree p,q;
    if(T->lchild&&T->lchild->data.key==e){
        return T->rchild;
    }else if(T->rchild&&T->rchild->data.key==e){
        return T->lchild;
    }else{
        p=GetSibling(T->lchild,e);
        q=GetSibling(T->rchild,e);
        if(p==NULL&&q==NULL){
            return NULL;
        }else{
            return (p==NULL)?q:p;
        }
    }
}


status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)//插入结点。
{
    BiTree p,q,r;
    
    if(c.key==e){//关键字重复 
        return ERROR;
    }

    p=(BiTree)malloc(sizeof(BiTNode));
    p->data=c;
    p->lchild=NULL;
    p->rchild=NULL;

    if(LR==-1){//作为根节点 
        p->rchild=T;
        T=p;
        return OK;
    }

    q=LocateNode(T,e);
    if(!q){//结点不存在 
        return ERROR;
    }
    if(c.key==e){//关键字重复 
        return ERROR;
    }
    if(LR==0){//作为左孩子 
        p->rchild=q->lchild;
        q->lchild=p;
        return OK;
    }else{//作为右孩子 
        p->rchild=q->rchild;
        q->rchild=p;
        return OK;
    }
}

status initstack(SqStack &s){//初始化栈 
    s.base=(BiTree*)malloc(sizeof(BiTree)*20);
    s.top=s.base;
    s.stacksize=20;
    return OK;
}

status gettop(SqStack &s,BiTree &e){//获取栈顶元素 
    if(s.top==s.base) return ERROR;
    e=*(s.top-1);
    return OK;
}

status push(SqStack &s,BiTree e){//栈顶入栈 
    if(s.top-s.base>=s.stacksize){
        s.base=(BiTree*)realloc(s.base,(s.stacksize+10)*sizeof(BiTree));
        if(!s.base) exit(OVERFLOW);
        s.top=s.base+s.stacksize;
        s.stacksize+=10;
    }
    *s.top++ = e;
    return OK;
}

status pop(SqStack &s,BiTree &e){//出栈 
    if(s.top==s.base) return ERROR;
    e=*--s.top;
    return OK;
}

status stackempty(SqStack &s){//栈判空 
    if(s.top==s.base) return OK;//1
    return ERROR;
}

status findtheright(BiTree &T,BiTree &p){//查找最右结点 
    p=T;
    while(p->rchild){
        p=p->rchild;
    }
    return OK;
}

status DeleteNode(BiTree &T,KeyType e)//删除结点。
{
    SqStack s;
    initstack(s);
    BiTree p=T,pre=NULL;
    BiTree q;
    BiTree* tar=NULL;//标记p是q的左还是右节点


    if(T->data.key==e){
        if(T->lchild==NULL&&T->rchild==NULL){//叶子节点 
            free(T);
            T=NULL;
            return OK;
        }else if(T->lchild&&T->rchild){//有左和右孩子 
            findtheright(T->lchild,p);
            p->rchild=T->rchild;
            p=T;
            T=T->lchild;
            free(p);
            return OK;
        }else{//只有一个孩子 
            p=T->lchild?T->lchild:T->rchild;
            free(T);
            T=p;
            return OK;
        }
    }

    
    while(p||!stackempty(s)){
        if(p){
            push(s,p);
            p=p->lchild;
        }else{
            gettop(s,p);
            if(p->rchild!=NULL&&(pre!=p->rchild)){
                p=p->rchild;
            }else{
                pop(s,p);
                if(p->data.key==e){
                    break;
                }
                pre=p;
                p=NULL;
            }
        }
    }
    if(!p) return ERROR;

    gettop(s,q);//p是找到的结点，q是p的父亲节点
    tar=(p==q->lchild?(&q->lchild):(&q->rchild));

    if(p->lchild==NULL&&p->rchild==NULL){
        free(p);
        *tar=NULL;
        return OK;
    }else if(p->lchild&&p->rchild){
        BiTree RightNode;
        *tar=p->lchild;
        findtheright(p->lchild,RightNode);
        RightNode->rchild=p->rchild;
        free(p);
        p=NULL;
        return OK;
    }else{
        *tar=(p->lchild?p->lchild:p->rchild);
        free(p);
        p=NULL;
        return OK;
    }
    return OK;
}

void visit(BiTree T)//访问函数，输出结点的关键字和内容 
{
    printf(" %d,%s",T->data.key,T->data.others);
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    if(T==NULL){
        return 0;
    }
    visit(T);
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    return OK;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    if(T==NULL){
        return 0;
    }

    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))//非递归实现 
//后序遍历二叉树T
{
    SqStack s;
    initstack(s);
    BiTree p=T,pre=NULL;
    int tar=0;
    
    if(T==NULL){
    	return ERROR;
	}

    while(p||!stackempty(s)){
        if(p){
            push(s,p);
            p=p->lchild;
        }else{
            gettop(s,p);
            if(p->rchild!=NULL&&(pre!=p->rchild)){
                p=p->rchild;
            }else{
                pop(s,p);
                visit(p);
                pre=p;
                p=NULL;
            }
        }
    }
    return OK;
}

status enqueue(SqQueue &q,BiTree e){//入队 
    if((q.rear+1)%MAXQSIZE==q.front) return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

status dequeue(SqQueue &q,BiTree &e){//出队 
    if(q.front==q.rear) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}

status queueempty(SqQueue q){//队列判空 
    if(q.front==q.rear) return OK;
    return ERROR;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    SqQueue q;
    BiTree p;
    q.base=(BiTree*)malloc(sizeof(BiTree)*MAXQSIZE);
    q.front=0;
    q.rear=0;
    
    if(T==NULL){
    	return ERROR;
	}

    enqueue(q,T);
    while(!queueempty(q)){
        dequeue(q,p);
        if(p->lchild){
            enqueue(q,p->lchild);
        }
        if(p->rchild){
            enqueue(q,p->rchild);
        }
        visit(p);
    }
    return OK;
}

status Create_BiTree(BiTree &T,Def definition[])//通过数组创造二叉树 
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	p[j]=(BiTNode *)malloc(sizeof(BiTNode));
        p[j]->data=definition[i].data;
        p[j]->lchild=NULL;
        p[j]->rchild=NULL;
        if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	    else      p[j/2]->lchild=p[j];
        i++;
    }
    T=p[1];
    return OK;
}

status enqueue(SqQue &q,Que e){//入队 
    if((q.rear+1)%MAXQSIZE==q.front) return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

status dequeue(SqQue &q,Que &e){//出队 
    if(q.front==q.rear) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}
status queueempty(SqQue q){//队列判空 
    if(q.front==q.rear) return OK;
    return ERROR;
}

status MyLevelOrderTraverse(BiTree T,FILE* out)//按层保存二叉树，由按层遍历二叉树改进而来 
{
    SqQue q;
    q.base=(Que*)malloc(sizeof(Que)*MAXQSIZE);
    q.front=0;
    q.rear=0;

    Que e,p;
    e.tree=T;
    e.pos=1;

    enqueue(q,e);
    while(!queueempty(q)){
        dequeue(q,e);
        if(e.tree->lchild){
            p.pos=e.pos*2;
            p.tree=e.tree->lchild;
            enqueue(q,p);
        }
        if(e.tree->rchild){
            p.pos=e.pos*2+1;
            p.tree=e.tree->rchild;
            enqueue(q,p);
        }
        fprintf(out,"%d %d %s ",e.pos,e.tree->data.key,e.tree->data.others);
    }
    fprintf(out,"0 0 NULL");
    return OK;
}


status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    if(T==NULL){
        return ERROR;
    }
    
    static FILE* out;
    int i=1;
    out=fopen(FileName,"r+");
    if(out==NULL) exit(-1);
    MyLevelOrderTraverse(T,out);
    fclose(out);
    return OK;
}
status LoadBiTree(BiTree &T, char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    int i=0;
    FILE* fin;
    Def def[100];
    fin=fopen(FileName,"r");
    if(fin==NULL) exit(-1);
    
    if(T){
    	return ERROR;
	}
    do {
	    fscanf(fin,"%d %d %s ",&def[i].pos,&def[i].data.key,def[i].data.others);
    } while (def[i++].pos);
    Create_BiTree(T,def);
    fclose(fin);
    return OK;
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    int i=0;
    while(ListName[i]!='\0'){
        Lists.elem[Lists.length].name[i]=ListName[i];
        i++;
    }
    Lists.elem[Lists.length].name[i]='\0';
    Lists.elem[Lists.length].L=NULL;
    InitTree(Lists.elem[Lists.length].L);
    Lists.length+=1;
    Lists.listsize=20;
    return 1;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    int i,j;
    int tar;
    for(i=0;i<Lists.length;i++){
        tar=1;
        for(j=0;Lists.elem[i].name[j]!='\0';j++){
           if(Lists.elem[i].name[j]!=ListName[j]){
               tar=0;
               break;
           }
        }
        if(tar==0){
            continue;
        }
        if(tar==1){
            break;
        }
    }
    if(tar==0){
        return ERROR;
    }else{
        if(i==Lists.length-1){
            Lists.length--;
            return OK;
        }else{
            int p=i;
            for(p;p<Lists.length-1;p++){
                Lists.elem[p]=Lists.elem[p+1];
            }
            Lists.length--;
            return OK;
        }
    }
}

int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    int i,j;
    int tar;
    for(i=0;i<Lists.length;i++){
        tar=1;
        for(j=0;Lists.elem[i].name[j]!='\0';j++){
           if(Lists.elem[i].name[j]!=ListName[j]){
               tar=0;
               break;
           }
        }
        if(tar==0){
            continue;
        }
        if(tar==1){
            break;
        }
    }
    if(tar==0){
        return 0;
    }else{
        return i+1;
    }
} 
