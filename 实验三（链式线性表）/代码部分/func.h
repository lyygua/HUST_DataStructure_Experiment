//#include "def.h"

status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
   if(L!=NULL){
       return INFEASIBLE;
    }
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//��ʼ��ͷ�ڵ�

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


//�����Ա�������� 
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
    InitList(Lists.elem[Lists.length].L);
    Lists.length+=1;
    Lists.listsize=10;
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





