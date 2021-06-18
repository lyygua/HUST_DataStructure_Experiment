#include "def.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
status strcopy(char a[],char b[]){//�����ַ��� 
    int i=0;
    for(i=0;b[i]!='\0';i++){
        a[i]=b[i];
    }
    a[i]='\0';
    return OK;
}
status CreateBiTree(BiTree &T,Def definition[])//���������� 
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
///*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
//�������ͬ�Ĺؼ��֣�����ERROR��*/
//{
//    static int i=0;
//    static int num[20];
//    int j=0;//����ѭ������
//    static int sum=0;//ͳ��key�ı���
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
//        //���жϹؼ����Ƿ��ظ�
//        for(j=0;j<sum;j++){
//            if(definition[i].key==num[j]){
//                return ERROR;
//            }
//        }
//        num[j]=definition[i].key;
//        sum++;
//        //������
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
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
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

status InitTree(BiTree &T){//��ʼ�������� 
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
//�������T�����
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
//���ҽ��
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
//ʵ�ֽ�㸳ֵ��
{
    BiTree p,q;
    p=LocateNode(T,e);
    if(!p){//�ؼ��ֲ�����
        return ERROR;
    }
    q=LocateNode(T,value.key);
    if(q!=NULL&&p!=q){//�ؼ����ظ�
        return ERROR;
    }else{
        p->data=value;
        return OK;
    }
}

BiTNode* GetSibling(BiTree T,KeyType e)
//ʵ�ֻ���ֵܽ��
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


status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)//�����㡣
{
    BiTree p,q,r;
    
    if(c.key==e){//�ؼ����ظ� 
        return ERROR;
    }

    p=(BiTree)malloc(sizeof(BiTNode));
    p->data=c;
    p->lchild=NULL;
    p->rchild=NULL;

    if(LR==-1){//��Ϊ���ڵ� 
        p->rchild=T;
        T=p;
        return OK;
    }

    q=LocateNode(T,e);
    if(!q){//��㲻���� 
        return ERROR;
    }
    if(c.key==e){//�ؼ����ظ� 
        return ERROR;
    }
    if(LR==0){//��Ϊ���� 
        p->rchild=q->lchild;
        q->lchild=p;
        return OK;
    }else{//��Ϊ�Һ��� 
        p->rchild=q->rchild;
        q->rchild=p;
        return OK;
    }
}

status initstack(SqStack &s){//��ʼ��ջ 
    s.base=(BiTree*)malloc(sizeof(BiTree)*20);
    s.top=s.base;
    s.stacksize=20;
    return OK;
}

status gettop(SqStack &s,BiTree &e){//��ȡջ��Ԫ�� 
    if(s.top==s.base) return ERROR;
    e=*(s.top-1);
    return OK;
}

status push(SqStack &s,BiTree e){//ջ����ջ 
    if(s.top-s.base>=s.stacksize){
        s.base=(BiTree*)realloc(s.base,(s.stacksize+10)*sizeof(BiTree));
        if(!s.base) exit(OVERFLOW);
        s.top=s.base+s.stacksize;
        s.stacksize+=10;
    }
    *s.top++ = e;
    return OK;
}

status pop(SqStack &s,BiTree &e){//��ջ 
    if(s.top==s.base) return ERROR;
    e=*--s.top;
    return OK;
}

status stackempty(SqStack &s){//ջ�п� 
    if(s.top==s.base) return OK;//1
    return ERROR;
}

status findtheright(BiTree &T,BiTree &p){//�������ҽ�� 
    p=T;
    while(p->rchild){
        p=p->rchild;
    }
    return OK;
}

status DeleteNode(BiTree &T,KeyType e)//ɾ����㡣
{
    SqStack s;
    initstack(s);
    BiTree p=T,pre=NULL;
    BiTree q;
    BiTree* tar=NULL;//���p��q�������ҽڵ�


    if(T->data.key==e){
        if(T->lchild==NULL&&T->rchild==NULL){//Ҷ�ӽڵ� 
            free(T);
            T=NULL;
            return OK;
        }else if(T->lchild&&T->rchild){//������Һ��� 
            findtheright(T->lchild,p);
            p->rchild=T->rchild;
            p=T;
            T=T->lchild;
            free(p);
            return OK;
        }else{//ֻ��һ������ 
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

    gettop(s,q);//p���ҵ��Ľ�㣬q��p�ĸ��׽ڵ�
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

void visit(BiTree T)//���ʺ�����������Ĺؼ��ֺ����� 
{
    printf(" %d,%s",T->data.key,T->data.others);
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
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
//�������������T
{
    if(T==NULL){
        return 0;
    }

    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))//�ǵݹ�ʵ�� 
//�������������T
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

status enqueue(SqQueue &q,BiTree e){//��� 
    if((q.rear+1)%MAXQSIZE==q.front) return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

status dequeue(SqQueue &q,BiTree &e){//���� 
    if(q.front==q.rear) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}

status queueempty(SqQueue q){//�����п� 
    if(q.front==q.rear) return OK;
    return ERROR;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
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

status Create_BiTree(BiTree &T,Def definition[])//ͨ�����鴴������� 
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

status enqueue(SqQue &q,Que e){//��� 
    if((q.rear+1)%MAXQSIZE==q.front) return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

status dequeue(SqQue &q,Que &e){//���� 
    if(q.front==q.rear) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}
status queueempty(SqQue q){//�����п� 
    if(q.front==q.rear) return OK;
    return ERROR;
}

status MyLevelOrderTraverse(BiTree T,FILE* out)//���㱣����������ɰ�������������Ľ����� 
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
//���������Ľ������д�뵽�ļ�FileName��
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
//�����ļ�FileName�Ľ�����ݣ�����������
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
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
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
// Lists��ɾ��һ������ΪListName�����Ա�
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
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
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
