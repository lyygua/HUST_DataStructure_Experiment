
//status InitList(SqList& L);//����һ���յ����Ա�
//status DestroyList(SqList& L);//�������Ա�L���ͷ�����Ԫ�صĿռ�
//status ClearList(SqList&L);//ɾ�����Ա�L�е�����Ԫ��
//status ListEmpty(SqList L);//�ж����Ա�L�Ƿ�Ϊ��
//int ListLength(SqList L);//�������Ա�L�ĳ���
//status GetElem(SqList L,int i,ElemType& e);//��ȡ���Ա�L�ĵ�i��Ԫ�أ�������e��
//status LocateElem(SqList L,ElemType e);//����Ԫ��e�����Ա�L�е�λ����Ų�
//status PriorElem(SqList L,ElemType cur,ElemType&pre_e);//��ȡ���Ա�L��Ԫ��e��ǰ����������pre��
//status NextElem(SqList L,ElemType cur,ElemType&next_e);//��ȡ���Ա�LԪ��e�ĺ�̣�������next��
//status ListInsert(SqList&L,int i,ElemType e);//��Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ
//status ListDelete(SqList&L,int i,ElemType& e);//ɾ�����Ա�L�ĵ�i��Ԫ��
//status ListTrabverse(SqList L);//������ʾ���Ա��е�Ԫ��
//status SaveList(SqList L,char FileName[]);//���Ա�L�ĵ�Ԫ��д��FileName�ļ���
//status LoadList(SqList &L,char FileName[]);//��FileName�ļ��е����ݶ��뵽���Ա�L��
//status AddList(LISTS &Lists,char ListName[]);//��Lists������һ������ΪListName�Ŀ����Ա�
//status RemoveList(LISTS &Lists,char ListName[]);// Lists��ɾ��һ������ΪListName�����Ա�
//int LocateList(LISTS Lists,char ListName[]);// ��Lists�в���һ������ΪListName�����Ա�

status InitList(SqList& L){// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
    if(L.elem==NULL){
        L.elem=(ElemType*)malloc(100*sizeof(ElemType));
        if(!L.elem) return INFEASIBLE;
        L.length=0;
        L.listsize=100;
        return OK;
    }else{
        return INFEASIBLE;
    }
}

status DestroyList(SqList& L)// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        free(L.elem);
        L.elem=NULL;
        L.length=0;
        L.listsize=0;
        return OK;
    }
}

status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        L.length=0;
        return OK;
    }
}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else if(L.length==0){
        return TRUE;
    }else{
        return FALSE;
    }
}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        return L.length;
    }
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else if(i>=L.length||i<=0){
        return ERROR;
    }else{
        e=L.elem[i-1];
        return OK;
    }

}

status LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }
    int i=0;
    for(i=0;i<L.length;i++){
        if(e==L.elem[i]){
            return i+1;
        }
    }
    return ERROR;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        int i=0;
        for(i=0;i<L.length;i++){
            if(e==L.elem[i]){
                if(i==0){
                    return ERROR;
                }else{
                    pre=L.elem[i-1];
                    return OK;
                }
            }
        }
        return ERROR;
    }
}

status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
     if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        int i=0;
        for(i=0;i<L.length;i++){
            if(e==L.elem[i]){
                if(i==L.length-1){
                    return ERROR;
                }else{
                    next=L.elem[i+1];
                    return OK;
                }
            }
        }
        return ERROR;
    }
}

status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else if(i<=0||i>L.length+1){
        return ERROR;
    }
    if(L.length>=L.listsize){
        ElemType* newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) return ERROR;
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    int j;
    if(L.length==0){
        L.elem[L.length]=e;
        L.length++;
        return OK;
    }
    for(j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else if(i<1||i>L.length){
        return ERROR;
    }else{
        e=L.elem[i-1];
        int j;
        for(j=i-1;j<L.length-1;j++){
            L.elem[j]=L.elem[j+1];
        }
        L.length--;
        return OK;
    }
}

status ListTrabverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }
    int i=0;
    if(L.length==0){
        return OK;
    }
    for(i;i<L.length-1;i++){
        printf("%d ",L.elem[i]);
    }
    printf("%d",L.elem[i]);
    return OK;
}

status  SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }
    FILE *fout;
    fout=fopen(FileName,"w+");
    int i;
    for(i=0;i<L.length;i++){
        fprintf(fout,"%d ",L.elem[i]);
    }
    fclose(fout);
    return OK;
}
status  LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem!=NULL){
        return INFEASIBLE;
    }
    if(L.elem==NULL){
        L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
        if(!L.elem) return INFEASIBLE;
        L.length=0;
        L.listsize=LIST_INIT_SIZE; 
    }
    FILE *fin;
    int i=0;
    fin=fopen(FileName,"r+");
    while(fscanf(fin,"%d",&L.elem[i])!=EOF && fin!=NULL){
        i++,L.length++;
        if(L.length>=L.listsize){
            ElemType* newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
            if(!newbase) return ERROR;
            L.elem=newbase;
            L.listsize+=LISTINCREMENT;
        }
    }
    
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
    Lists.elem[Lists.length].L.elem=NULL;
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

