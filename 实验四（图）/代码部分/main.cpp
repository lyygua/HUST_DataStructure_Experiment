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
	
	int m;//��¼�����Ա�������ǵڼ����� 
   	int n;//�����Ա�����ʹ�ֵ���� 
   	KeyType u;
	int op=1;//ѭ�����Ʊ��� 
	int target=0;//�ж��Ƿ��Ƕ����Ա���� 
	int i=0,j=0,v,w;//������λ����ӻ�ɾ������ 
	int tar=0;//��������ֵ��� 
	
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	char name[30];
	
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("���ڲ�����ͼ�ǵ�%d��\n",m);
			printf("ͼ�������£�\n");
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
				printf("ͼ���£�\n");
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
		printf("          15. �����ͼ����\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d",&op);
		i=0;
    	switch(op){
	   	case 1:/*����V��VR����ͼG������OK�����V��VR����ȷ������ERROR*/
	   		printf("��������Ϊ�������У��Թؼ���Ϊ-1��Ϊ�������\n");
			do {
    			scanf("%d%s",&V[i].key,V[i].others);
			} while(V[i++].key!=-1);
			i=0;
			printf("��������Ϊ��ϵ�����У��Թؼ���Ϊ-1��Ϊ�������\n");
			do {
    			scanf("%d%d",&VR[i][0],&VR[i][1]);
   			} while(VR[i++][0]!=-1);
			if (CreateCraph(G,V,VR)==ERROR) printf("�������ݴ��޷�����");
			else {
				printf("��������ͼ���£�\n");
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
		 	
	   	case 2:/*��������ͼG*/
			if(DestroyGraph(G)==OK) printf("����ͼ���ٳɹ���\n");
			else printf("����ͼ����ʧ�ܣ�\n");    
			if(target==1){
				RemoveGraph(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3://����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
	   		printf("������ؼ��֣�");
	   		scanf("%d",&u);   
			i=LocateVex(G,u);
			if (i!=-1)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("����ʧ��"); 
		 	getchar();getchar();
		 	break;
		 	
	   	case 4://����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
	   		printf("������ؼ��֣�");
			scanf("%d",&u);  
			printf("�������޸ĺ�Ĺؼ��ֺ����ݣ�"); 
			scanf("%d%s",&value.key,value.others);
			i=PutVex(G,u,value);
			if (i==OK)
   				for(i=0;i<G.vexnum;i++)
     			printf(" %d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("��ֵ����ʧ��");
		 	getchar();getchar();
		 	break;
		 	
	   	case 5://����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
	   		printf("������ؼ��֣�");
	   		scanf("%d",&u);   
			i=FirstAdjVex(G,u);
			if (i!=0)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("����ʧ��");
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
	   		printf("�����������ؼ��֣�");
	   		scanf("%d%d",&v,&w);   
			i=NextAdjVex(G,v,w);
			if (i!=-1)
				printf("%d %s",G.vertices[i].data.key,G.vertices[i].data.others);
			else
				printf("����һ�ڽӶ���");
			getchar();getchar();
			break;
			
	   	case 7://��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
	   		printf("��������붥��Ĺؼ��ֺ����ݣ�");
		 	scanf("%d%s",&value.key,value.others);
			i=InsertVex(G,value);
			if (i==OK){
				printf("ͼ���£�\n");
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
			}else printf("�������ʧ��");
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
	   		printf("������ؼ��֣�");
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
			else printf("ɾ���������ʧ��");
					 	getchar();getchar();
					 	break;
					 	
		case 9://��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
			printf("�����������ؼ��֣�");
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
			else printf("���뻡����ʧ��");
			getchar();getchar();
			break;
					 	
		case 10://��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
			printf("�����������ؼ��֣�");
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
			else printf("ɾ��������ʧ��");
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
		 	DFSTraverse(G,visit);
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
		 	if(G.vexnum==0){
		 		printf("ͼΪ��\n");
			}else  BFSTraverse(G,visit);
			getchar();getchar();
		 	break;
		 	
		case 13://��ͼ������д�뵽�ļ�FileName��
		 	tar=SaveGraph(G,FileName);
		 	if(tar==OK){
		 		printf("д�뵽�ļ��ɹ���\n");
			}else{
				printf("д��ʧ��\n");
			}
			getchar();getchar();
		 	break;
		case 14://�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
			tar=LoadGraph(G,FileName);
			if(tar==OK){
				printf("���ݶ��뵽ͼ�ɹ���\n");
			}else{
				printf("����ʧ�ܣ�\n");
			}
			getchar();getchar();
		 	break;
		case 15://�������� 
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
				printf("    	  3. LocateGraph    4. ����Graph      \n");
				printf("    	  5. ��ʾGraph     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    ��ѡ����Ĳ���[0~5]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])��Lists������һ������ΪListName�Ŀ����Ա�
						printf("������ͼ������\n");
						scanf("%d", &n);
						while(n--){
							printf("������ͼ���ƣ�\n");
    						scanf("%s",name);
   							AddGraph(Lists,name);
							i=0;
							printf("��������Ϊ�������У��Թؼ���Ϊ-1��Ϊ�������\n");
							do {
    							scanf("%d%s",&V[i].key,V[i].others);
							} while(V[i++].key!=-1);
							i=0;
							printf("��������Ϊ��ϵ�����У��Թؼ���Ϊ-1��Ϊ�������\n");
							do {
    							scanf("%d%d",&VR[i][0],&VR[i][1]);
   							} while(VR[i++][0]!=-1);
							tar=CreateCraph(Lists.elem[Lists.length-1].L,V,VR);
							if (tar==OK){
								printf("�����ɹ�\n");
							}
							else printf("�ؼ��ֲ�Ψһ\n");
   						}
   						printf("��ͼ���£�\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s\n",Lists.elem[n].name);
   							G=Lists.elem[n].L;
   							view(G);
							putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists��ɾ��һ������ΪListName�����Ա�
						printf("��������ɾ����ͼ�����ƣ�\n");
						scanf("%s",name);
   						if (RemoveGraph(Lists,name)==OK){
   							printf("ɾ����Ķ�ͼ���£�\n");
	   						for(n=0;n<Lists.length;n++){
   								printf("%s\n",Lists.elem[n].name);
   								G=Lists.elem[n].L;
   								view(G);
								putchar('\n');
   							}
   						}else{
							printf("ɾ��ʧ��");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])��Lists�в���һ������ΪListName�����Ա�
						printf("����������ҵ�ͼ�����ƣ�\n");
						scanf("%s",name);
   						if (n=LocateGraph(Lists,name)){
   							printf("���ҵ�ͼ���£�\n");
   							printf("%s\n",Lists.elem[n-1].name);
   								G=Lists.elem[n-1].L;
   								view(G);
								putchar('\n');
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 4://����ѡ�е����Ա� 
						printf("��������Ҫ���в�����ͼ�����ƣ�\n");
						scanf("%s",name);
   						if (n=LocateGraph(Lists,name)){
   							printf("���ҵ�ͼ���£�\n");
   							printf("%s\n",Lists.elem[n-1].name);
   							view(Lists.elem[n-1].L);
         					putchar('\n');
         					G=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 5://��ʾ�����Ա� 
		 				if(Lists.length==0){
		 					printf("��ͼΪ�ա�");
						}else{
							printf("��ͼ���£�\n");
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
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}



