
//status InitList(SqList& L);//构造一个空的线性表
//status DestroyList(SqList& L);//销毁线性表L，释放数据元素的空间
//status ClearList(SqList&L);//删除线性表L中的所有元素
//status ListEmpty(SqList L);//判断线性表L是否为空
//int ListLength(SqList L);//返回线性表L的长度
//status GetElem(SqList L,int i,ElemType& e);//获取线性表L的第i个元素，保存在e中
//status LocateElem(SqList L,ElemType e);//查找元素e在线性表L中的位置序号并
//status PriorElem(SqList L,ElemType cur,ElemType&pre_e);//获取线性表L中元素e的前驱，保存在pre中
//status NextElem(SqList L,ElemType cur,ElemType&next_e);//获取线性表L元素e的后继，保存在next中
//status ListInsert(SqList&L,int i,ElemType e);//将元素e插入到线性表L的第i个元素之前
//status ListDelete(SqList&L,int i,ElemType& e);//删除线性表L的第i个元素
//status ListTrabverse(SqList L);//依次显示线性表中的元素
//status SaveList(SqList L,char FileName[]);//线性表L的的元素写到FileName文件中
//status LoadList(SqList &L,char FileName[]);//将FileName文件中的数据读入到线性表L中
//status AddList(LISTS &Lists,char ListName[]);//在Lists中增加一个名称为ListName的空线性表
//status RemoveList(LISTS &Lists,char ListName[]);// Lists中删除一个名称为ListName的线性表
//int LocateList(LISTS Lists,char ListName[]);// 在Lists中查找一个名称为ListName的线性表

status InitList(SqList& L){// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
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

status DestroyList(SqList& L)// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        L.length=0;
        return OK;
    }
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        return L.length;
    }
}

status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
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
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
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

