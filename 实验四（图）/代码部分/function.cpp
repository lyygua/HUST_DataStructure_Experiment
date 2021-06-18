#include "def.h"
#include "stdio.h"
#include "stdlib.h"
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,j,one,two,target=0;
    do {//先创建顶点信息，保存在顶点顺序表中 
        if(i>20){
            return ERROR;
        }
        G.vertices[i].data=V[i];
        G.vertices[i].firstarc=NULL;
    } while (V[i++].key!=-1);
    G.vexnum=i-1;
    if(G.vexnum>20){
        return ERROR;
    }
    for(i=0;i<G.vexnum-1;i++){//遍历，如果存在两个顶点的关键字相同，则报错 
        for(j=i+1;j<G.vexnum;j++){
            if(G.vertices[i].data.key==G.vertices[j].data.key){
                return ERROR;
            }
        }
    }
    i=0;
    while (VR[i][0]!=-1) {
        ArcNode *p;
        for(j=0;j<G.vexnum;j++){//找弧的一端 
            if (VR[i][0]==G.vertices[j].data.key)
            {
                one=j; 
                break;
            }
        }
        if(j==G.vexnum){
            return ERROR;
        }
        for(j=0;j<G.vexnum;j++){//找弧的另一端 
            if (VR[i][1]==G.vertices[j].data.key)
            {
               two=j; 
               break;
             }
        }
        if(j==G.vexnum){
            return ERROR;
        }
        p=(ArcNode*)malloc(sizeof(ArcNode));//创建邻接表，首插法 
        p->adjvex=two;p->nextarc=G.vertices[one].firstarc;G.vertices[one].firstarc=p;  
        p=(ArcNode*)malloc(sizeof(ArcNode));    
        p->adjvex=one;p->nextarc=G.vertices[two].firstarc;G.vertices[two].firstarc=p;  
        i++;
    } 
    return OK;
    /********** End **********/
}

status DestroyGraph(ALGraph &G)
/*销毁无向图G*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    ArcNode *p;
    int i=0;
    for(i;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p){
            G.vertices[i].firstarc=p->nextarc;
            free(p);
            p=G.vertices[i].firstarc;
        }
    }
    G.vexnum=0,G.arcnum=0;
    return OK;

    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==u){
            return i;
        }
    }
    return -1;
    /********** End **********/
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,j=0;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==u){//被查找顶点
            break;
        }
    }
    for(j;j<G.vexnum;j++){//是否有相同值
        if(G.vertices[j].data.key==value.key){
            break;
        }
    }
    if(i==G.vexnum){
        return ERROR;
    }
    if(j<G.vexnum&&i!=j){
        return ERROR;
    }
    G.vertices[i].data=value;
    return OK;
    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,j=0;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==u){//被查找顶点
            break;
        }
    }
    if(i>=G.vexnum){
        return ERROR;
    }
    if(G.vertices[i].firstarc!=NULL){
        return G.vertices[i].firstarc->adjvex;
    }
    return ERROR;

    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,j=0;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==v){//被查找顶点
            break;
        }
    }
    if(i==G.vexnum){
        return -1;
    }
    for(j;j<G.vexnum;j++){
        if(G.vertices[j].data.key==w){//被查找顶点
            break;
        }
    }
    if(j==G.vexnum){
        return -1;
    }
    ArcNode* p=G.vertices[i].firstarc;
    while(p){
        if(p->nextarc!=NULL&&p->adjvex==j){
            return p->nextarc->adjvex;
        }
        p=p->nextarc;
    }
    return -1;
    /********** End **********/
}

status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==v.key){
            return ERROR;
        }
    }
    if(G.vexnum+1>20){
        return ERROR;
    }
    G.vertices[G.vexnum].data=v;
    G.vertices[G.vexnum].firstarc=NULL;
    G.vexnum++;
    return OK;

    /********** End **********/
}

status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    ArcNode *p,*q;
    int i=0,j=0,num=0,pos;
    for(i;i<G.vexnum;i++){
        if(G.vertices[i].data.key==v){//被查找顶点
            break;
        }
    }
    if(i>=G.vexnum){
        return ERROR;
    }
    p=G.vertices[i].firstarc;
    while(p){
        num++;
        G.vertices[i].firstarc=p->nextarc;
        pos=p->adjvex;
        q=G.vertices[pos].firstarc;
        free(p);
        if(q->adjvex==i){
            G.vertices[pos].firstarc=q->nextarc;
            free(q);
        }else{
            p=q->nextarc;
            while(p->nextarc){
                if(p->adjvex==i){
                    q->nextarc=p->nextarc;
                    free(p);
                    break;
                }
            }
            q->nextarc=p->nextarc;
            free(p);
        }
        p=G.vertices[i].firstarc;
    }
    G.arcnum-=num;
    for(j=i;j<G.vexnum-1;j++){
        G.vertices[j]=G.vertices[j+1];
    }
    G.vexnum--;
    if(G.vexnum==0){
        return ERROR;
    }
    for(j=0;j<G.vexnum;j++){
        p=G.vertices[j].firstarc;
        while(p){
            if(p->adjvex>i){
                p->adjvex--;
            }
            p=p->nextarc;
        }
    }
    return OK;
    /********** End **********/
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,one,two;
    ArcNode* p=NULL;

    for(i=0;i<G.vexnum;i++){
        if(G.vertices[i].data.key==v){
            one=i;
            break;
        }
    }
    if(i==G.vexnum){
        return ERROR;
    }
    for(i=0;i<G.vexnum;i++){
        if(G.vertices[i].data.key==w){
            two=i;
            break;
        }
    }
    if(i==G.vexnum){
        return ERROR;
    }
    p=G.vertices[one].firstarc;
    while(p){
        if(p->adjvex==two){
            return ERROR;
        }
        p=p->nextarc;
    }

    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=two;p->nextarc=G.vertices[one].firstarc;G.vertices[one].firstarc=p;  
    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=one;p->nextarc=G.vertices[two].firstarc;G.vertices[two].firstarc=p;  
    return OK;
    

    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,one,two;
    int tar=0;
    ArcNode* p=NULL,*q=NULL;

    for(i=0;i<G.vexnum;i++){//找第一个顶点的序号
        if(G.vertices[i].data.key==v){
            one=i;
            break;
        }
    }
    if(i==G.vexnum){
        return ERROR;
    }
    for(i=0;i<G.vexnum;i++){//找第二个顶点的序号
        if(G.vertices[i].data.key==w){
            two=i;
            break;
        }
    }
    if(i==G.vexnum){
        return ERROR;
    }
    p=q=G.vertices[one].firstarc;
    while(q){
        if(G.vertices[one].firstarc->adjvex==two){//第一个节点是
            G.vertices[one].firstarc=p->nextarc;
            free(p);
            tar=1;
            break;
        }else{//不是第一个顶点
            q=p->nextarc;
            if(q==NULL){
                return  ERROR;
            }
            if(q->adjvex==two){
                p->nextarc=q->nextarc;
                free(q);
                tar=1;
                break;
            }
        }
        p=p->nextarc;
        q=q->nextarc;
    }
    if(tar==0){
        return ERROR;
    }else{
        G.arcnum--;
    }
    tar=0;
    p=q=G.vertices[two].firstarc;
    while(q){
        if(G.vertices[two].firstarc->adjvex==one){//第一个节点是
            G.vertices[two].firstarc=p->nextarc;
            free(p);
            tar=1;
            break;
        }else{//不是第一个顶点
            q=p->nextarc;
            if(q==NULL){
                return ERROR;
            }
            if(q->adjvex==one){
                p->nextarc=q->nextarc;
                free(q);
                tar=1;
                break;
            }
        }
        p=p->nextarc;
        q=q->nextarc;
    }
    if(tar==0){
        return ERROR;
    }else{
        G.arcnum--;
    }
    return OK;


    /********** End **********/
}

int visited[20];
void (* visitfunc)(VertexType);
void DFS(ALGraph &G,int v){
    ArcNode* p;
    visited[v]=1;
    
    visitfunc(G.vertices[v].data);
    p=G.vertices[v].firstarc;
    for(p;p!=NULL;p=p->nextarc){
        if(!visited[p->adjvex]){
            DFS(G,p->adjvex);
        }
    }
}
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i;
    visitfunc=visit;
    for(i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    for(i=0;i<G.vexnum;i++){
        if(!visited[i]){
            DFS(G,i);
        }
    }
    return OK;
    /********** End **********/
}

status initqueue(SqQueue& q){//初始化队列 
    q.base=(int *)malloc(sizeof(int)*20);
    q.front=q.rear=0;
    return OK;
}

status enqueue(SqQueue& q,int i){//入队操作 
    if((q.rear+1)%20==q.front) return ERROR;
    q.base[q.rear]=i;
    q.rear=(q.rear+1)%20;
    return OK;
}

status dequeue(SqQueue& q,int &i){//出队操作 
    if(q.front==q.rear) return ERROR;
    i=q.base[q.front];
    q.front=(q.front+1)%20;
    return OK;
}

status queueempty(SqQueue& q){//判断队列是否为空 
    if(q.front==q.rear) return 1;
    return 0;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i=0,u=0;
    int visited[20];
    SqQueue q;
    ArcNode* p;
    for(i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    initqueue(q);
    for(i=0;i<G.vexnum;i++){
        if(!visited[i]){
            visited[i]=1;
            visit(G.vertices[i].data);
            enqueue(q,i);
            while(!queueempty(q)){
                dequeue(q,u);
                for(p=G.vertices[i].firstarc;p!=NULL;p=p->nextarc){
                    if(!visited[p->adjvex]){
                        visit(G.vertices[p->adjvex].data);
                        visited[p->adjvex]=1;
                        enqueue(q,p->adjvex);
                    }
                }
            }
        }
    }
    return OK;

    /********** End **********/
}

void swap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE*f=fopen(FileName,"w");//打开文件
    int i,j,arcnum;
    ArcNode  *p;
    KeyType VR[100][2],i_key,p_key;
    int VA[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//弧数组
    for(i = 0 ; i < G.vexnum ; i++)
    	for(j = 0 ; j < G.vexnum ; j++)
    		VA[i][j] = 0;
    for(i = 0 ; i < G.vexnum ; i++){
    	fprintf(f,"%d ",G.vertices[i].data.key);
    	fprintf(f,"%s ",G.vertices[i].data.others);
	}
	fprintf(f,"-1 null ");
	j = 0;
	for(i = 0 ; i < G.vexnum ; i++){
    	p = G.vertices[i].firstarc;
    	while(p){
    		if(!VA[i][p->adjvex]){
    			VA[i][p->adjvex] = 1;
    			VA[p->adjvex][i] = 1;
    			i_key = G.vertices[i].data.key;
    			p_key = G.vertices[p->adjvex].data.key;
    			VR[j][0] = i_key > p_key ? p_key : i_key;
    			VR[j][1] = i_key > p_key ? i_key : p_key;
    			j++;
			}//if未访问弧，则将弧数据写入弧数组 
			p = p->nextarc;
		}//while遍历表结点 
	}//for遍历头结点
	arcnum = j;
	//printf("%d\n",arcnum);
	for(i = 0;i < arcnum-1;i++){
		for(j = 0;j < arcnum-i-1;j++){
			if(VR[j][0] > VR[j+1][0]){
				swap(VR[j][0],VR[j+1][0]);
				swap(VR[j][1],VR[j+1][1]);
			}
			else if(VR[j][0] == VR[j+1][0]){
				if(VR[j][1] > VR[j+1][1]){
					swap(VR[j][0],VR[j+1][0]);
					swap(VR[j][1],VR[j+1][1]);
				}
			}
		}
	}//冒泡排序弧 
	for(i = 0;i<arcnum;i++){
		fprintf(f,"%d %d ",VR[i][0],VR[i][1]);
	} 
	fprintf(f,"-1 -1 ");
	fclose(f);
	return OK; 
    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
     int i=0;
    FILE* fin;
    fin=fopen(FileName,"r");
    if(fin==NULL) exit(-1);
    VertexType V[30];
    KeyType VR[30][2];
    do{
        fscanf(fin,"%d%s",&V[i].key,V[i].others);
    }while(V[i++].key!=-1);
    i=0;
    do{
        fscanf(fin,"%d%d",&VR[i][0],&VR[i][1]);
    }while(VR[i++][0]!=-1);
    if(CreateCraph(G,V,VR)==ERROR) return ERROR;
    fclose(fin);
    return OK;
    /********** End 2 **********/
}

status AddGraph(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    int i=0;
    while(ListName[i]!='\0'){
        Lists.elem[Lists.length].name[i]=ListName[i];
        i++;
    }
    Lists.elem[Lists.length].name[i]='\0';
    Lists.elem[Lists.length].L.vexnum=0;
    Lists.length+=1;
    Lists.listsize=20;
    return 1;
}

status RemoveGraph(LISTS &Lists,char ListName[])
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

int LocateGraph(LISTS Lists,char ListName[])
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

void view(ALGraph& G){
	int i=0;
	ArcNode* p;
	for(i=0;i<G.vexnum;i++)
	{
    	p=G.vertices[i].firstarc;
     	printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
     	while (p)
     	{
        	printf(" %d",p->adjvex);
         	p=p->nextarc;
    	}
     	printf("\n");
	}
}
