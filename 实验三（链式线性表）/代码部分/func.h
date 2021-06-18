//#include "def.h"

status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L!=NULL){
        return INFEASIBLE;
    }else{
        L=(LinkList)malloc(sizeof(LNode));
        L->next=NULL;
        return OK;
    }
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p;
        p=L->next;
        while(p!=NULL){
            free(L);
            L=p;
            p=L->next;
        }
        L=NULL;
        return OK;
    }
}

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p,q;
        p=L->next;
        while(p!=NULL){
            q=p->next;
            L->next=q;
            free(p);
            p=q;
        }
        return OK;
    }
}

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }
    if(L->next==NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        int length=0;
        LinkList p;
        p=L->next;
        while(p!=NULL){
            length++;
            p=p->next;
        }
        return length;
    }
}

status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p;
        p=L->next;
        if(i<1){
            return ERROR;
        }
        while(p!=NULL){
            i--;
            if(i==0){
                e=p->data;
                return OK;
            }
            p=p->next;
        }
        return ERROR;
    }
}

status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        int i=1;
        LinkList p;
        p=L->next;
        while(p!=NULL){
            if(e==p->data){
                return i;
            }
            p=p->next;
            i++;
        }
        return ERROR;
    }
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
     if(L==NULL){
        return INFEASIBLE;
    }else{
        //int i=1;
        LinkList p,q;
        p=L;
        q=p->next;
        while(q!=NULL){
            if((e==q->data)){
                if(q==L->next){
                    return ERROR;
                }else{
                    pre=p->data;
                    return OK;
                }
            }
            p=q;
            q=q->next;
        }
        return ERROR;
    }
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
     if(L==NULL){
        return INFEASIBLE;
    }else{
       LinkList p;
       p=L->next;
       while(p!=NULL){
           if(e==p->data){
               if(p->next==NULL){
                   return ERROR;
               }else{
                   next=p->next->data;
                   return OK;
               }
           }
           p=p->next;
       }
       return ERROR;
    }
}

status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p;
        p=L;
        while(p!=NULL){
            i--;
            if(i==0){
                LinkList q;
                q=(LinkList)malloc(sizeof(LNode));
                q->data=e;
                q->next=p->next;
                p->next=q;
                return OK;
            }
            p=p->next;
        }
        return ERROR;
    }
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p,q;
        p=L;
        while(p->next!=NULL){
            i--;
            if(i==0){
                q=p->next;
                e=q->data;
                p->next=q->next;
                free(q);
                return OK;
            }
            p=p->next;
        }
        return ERROR;
    }
}

status ListTrabverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }else{
        LinkList p;
        p=L->next;
        if(p==NULL){
            return OK;
        }
        while(p->next!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d",p->data);
        return OK;
    }
}

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(L==NULL){
        return INFEASIBLE;
    }
    FILE *fout;
    LinkList p;
    p=L->next;
    fout=fopen(FileName,"w+");
    while(p!=NULL){
        fprintf(fout,"%d ",p->data);
        p=p->next;
    }
    fclose(fout);
    return OK;
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
   if(L!=NULL){
       return INFEASIBLE;
    }
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//初始化头节点

    FILE *fin;
    fin=fopen(FileName,"r+");
    LinkList p=(LinkList)malloc(sizeof(LNode));
    p->next=NULL;
    LinkList q=L;

    while(fscanf(fin,"%d",&(p->data))!=EOF&&fin!=NULL){
        q->next=p;
        q=p;
        p=(LinkList)malloc(sizeof(LNode));
        p->next=NULL;
    }
    
    fclose(fin);
    return OK;
}


//多线性表操作函数 
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
    InitList(Lists.elem[Lists.length].L);
    Lists.length+=1;
    Lists.listsize=10;
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





