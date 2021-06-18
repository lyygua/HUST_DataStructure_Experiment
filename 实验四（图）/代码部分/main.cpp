#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "def.h"
#include "func.h"

int main(){
	ALGraph G;
	VertexType V[30],value;
	KeyType VR[100][2];
	LISTS Lists;
	Lists.length=0;
	ArcNode *p;
	
	int m;//记录多线性表操作的是第几个表 
   	int n;//多线性表个数和传值变量 
   	KeyType u;
	int op=1;//循环控制变量 
	int target=0;//判断是否是多线性表操作 
	int i=0,j=0,v,w;//函数定位或添加或删除变量 
	int tar=0;//函数返回值标记 
	
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	char name[30];
	
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("现在操作的图是第%d个\n",m);
			printf("图内容如下：\n");
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
			printf("\n");
		}else{
			if(G.vexnum!=0){
				printf("图如下：\n");
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
		}
		printf("      Menu for Linear Table On Binery Tree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateCraph    8. DeleteVex\n");
		printf("    	  2. DestroyGraph   9. InsertArc \n");
		printf("    	  3. LocateVex      10. DeleteArc\n");
		printf("    	  4. ModifyVex      11. DFSTraverse\n");
		printf("    	  5. FirstAdjVex    12. BFSTraverse\n");
		printf("    	  6. NextAdjVex     13. SaveGraph\n");
		printf("    	  7. InsertVex      14. LoadGraph\n");
		printf("          15. 进入多图操作\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~15]:");
		scanf("%d",&op);
		i=0;
    	switch(op){
	   	case 1:/*根据V和VR构造图G并返回OK，如果V和VR不正确，返回ERROR*/
	   		printf("输入序列为顶点序列，以关键字为-1作为结束标记\n");
			do {
    			scanf("%d%s",&V[i].key,V[i].others);
			} while(V[i++].key!=-1);
			i=0;
			printf("输入序列为关系对序列，以关键字为-1作为结束标记\n");
			do {
    			scanf("%d%d",&VR[i][0],&VR[i][1]);
   			} while(VR[i++][0]!=-1);
			if (CreateCraph(G,V,VR)==ERROR) printf("输入数据错，无法创建");
			else {
				printf("创建出的图如下：\n");
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
			getchar();getchar();
			break;
		 	
	   	case 2:/*销毁无向图G*/
			if(DestroyGraph(G)==OK) printf("无向图销毁成功！\n");
			else printf("无向图销毁失败！\n");    
			if(target==1){
				RemoveGraph(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3://根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
	   		printf("请输入关键字：");
	   		scanf("%d",&u);   
			i=LocateVex(G,u);
			if (i!=-1)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("查找失败"); 
		 	getchar();getchar();
		 	break;
		 	
	   	case 4://根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
	   		printf("请输入关键字：");
			scanf("%d",&u);  
			printf("请输入修改后的关键字和内容："); 
			scanf("%d%s",&value.key,value.others);
			i=PutVex(G,u,value);
			if (i==OK)
   				for(i=0;i<G.vexnum;i++)
     			printf(" %d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("赋值操作失败");
		 	getchar();getchar();
		 	break;
		 	
	   	case 5://根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
	   		printf("请输入关键字：");
	   		scanf("%d",&u);   
			i=FirstAdjVex(G,u);
			if (i!=0)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("查找失败");
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
	   		printf("请输入两个关键字：");
	   		scanf("%d%d",&v,&w);   
			i=NextAdjVex(G,v,w);
			if (i!=-1)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("无下一邻接顶点");
			getchar();getchar();
			break;
			
	   	case 7://在图G中插入顶点v，成功返回OK,否则返回ERROR
	   		printf("请输入插入顶点的关键字和内容：");
		 	scanf("%d%s",&value.key,value.others);
			i=InsertVex(G,value);
			if (i==OK){
				printf("图如下：\n");
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
			}else printf("插入操作失败");
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
	   		printf("请输入关键字：");
		 	scanf("%d",&v);
			i=DeleteVex(G,v);
			if (i==OK) {
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
			else printf("删除顶点操作失败");
					 	getchar();getchar();
					 	break;
					 	
		case 9://在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
			printf("请输入两个关键字：");
			scanf("%d%d",&v,&w);
			i=InsertArc(G,v,w);
			if (i==OK) {
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
			else printf("插入弧操作失败");
			getchar();getchar();
			break;
					 	
		case 10://在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
			printf("请输入两个关键字：");
			scanf("%d%d",&v,&w);
			i=DeleteArc(G,v,w);
			if (i==OK) {
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
			else printf("删除弧操作失败");
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
		 	DFSTraverse(G,visit);
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
		 	if(G.vexnum==0){
		 		printf("图为空\n");
			}else  BFSTraverse(G,visit);
			getchar();getchar();
		 	break;
		 	
		case 13://将图的数据写入到文件FileName中
		 	tar=SaveGraph(G,FileName);
		 	if(tar==OK){
		 		printf("写入到文件成功！\n");
			}else{
				printf("写入失败\n");
			}
			getchar();getchar();
		 	break;
		case 14://读入文件FileName的图数据，创建图的邻接表
			tar=LoadGraph(G,FileName);
			if(tar==OK){
				printf("数据读入到图成功！\n");
			}else{
				printf("读入失败！\n");
			}
			getchar();getchar();
		 	break;
		case 15://进入多操作 
			if(target==1){
					Lists.elem[m-1].L=G;
					target=0;
					DestroyGraph(G);
			}else{
				DestroyGraph(G);
			}
			while(op){
				system("cls");	printf("\n\n");
				printf("      Menu for Linear Table On Sequence Structure \n");
				printf("-------------------------------------------------\n");
				printf("    	  1. AddGraph       2. RemoveGraph\n");
				printf("    	  3. LocateGraph    4. 操作Graph      \n");
				printf("    	  5. 显示Graph     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~5]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])在Lists中增加一个名称为ListName的空线性表
						printf("请输入图个数：\n");
						scanf("%d", &n);
						while(n--){
							printf("请输入图名称：\n");
    						scanf("%s",name);
   							AddGraph(Lists,name);
							i=0;
							printf("输入序列为顶点序列，以关键字为-1作为结束标记\n");
							do {
    							scanf("%d%s",&V[i].key,V[i].others);
							} while(V[i++].key!=-1);
							i=0;
							printf("输入序列为关系对序列，以关键字为-1作为结束标记\n");
							do {
    							scanf("%d%d",&VR[i][0],&VR[i][1]);
   							} while(VR[i++][0]!=-1);
							tar=CreateCraph(Lists.elem[Lists.length-1].L,V,VR);
							if (tar==OK){
								printf("创建成功\n");
							}
							else printf("关键字不唯一\n");
   						}
   						printf("多图如下：\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s\n",Lists.elem[n].name);
   							G=Lists.elem[n].L;
   							view(G);
							putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists中删除一个名称为ListName的线性表
						printf("请输入想删除的图的名称：\n");
						scanf("%s",name);
   						if (RemoveGraph(Lists,name)==OK){
   							printf("删除后的多图如下：\n");
	   						for(n=0;n<Lists.length;n++){
   								printf("%s\n",Lists.elem[n].name);
   								G=Lists.elem[n].L;
   								view(G);
								putchar('\n');
   							}
   						}else{
							printf("删除失败");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])在Lists中查找一个名称为ListName的线性表
						printf("请输入想查找的图的名称：\n");
						scanf("%s",name);
   						if (n=LocateGraph(Lists,name)){
   							printf("查找的图如下：\n");
   							printf("%s\n",Lists.elem[n-1].name);
   								G=Lists.elem[n-1].L;
   								view(G);
								putchar('\n');
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 4://操作选中的线性表 
						printf("请输入想要进行操作的图的名称：\n");
						scanf("%s",name);
   						if (n=LocateGraph(Lists,name)){
   							printf("查找的图如下：\n");
   							printf("%s\n",Lists.elem[n-1].name);
   							view(Lists.elem[n-1].L);
         					putchar('\n');
         					G=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 5://显示多线性表 
		 				if(Lists.length==0){
		 					printf("多图为空。");
						}else{
							printf("多图如下：\n");
							for(n=0;n<Lists.length;n++){
   								printf("%s\n",Lists.elem[n].name);
   								view(Lists.elem[n].L);
        						putchar('\n');
   							}
						}
						getchar();getchar();
		 				break;
					case 0:
         				break;
				}		
			}
			op=1;
			break;
		}
		}
	printf("欢迎下次再使用本系统！\n");
}



