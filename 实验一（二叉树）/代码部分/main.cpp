#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "def.h"
#include "function.h"

int main(){
	BiTree T=NULL;
	BiTree p,q;
	LISTS Lists;
	Lists.length=0;
	Def definition[100];
	
	int m;//��¼�����Ա�������ǵڼ����� 
   	int n;//�����Ա�����ʹ�ֵ���� 
   	KeyType e;
   	TElemType c;
   	int LR;
	int op=1;//ѭ�����Ʊ��� 
	int target=0;//�ж��Ƿ��Ƕ����Ա���� 
	int i=0,j=0;//������λ����ӻ�ɾ������ 
	int tar=0;//��������ֵ��� 
	//int ans;
	
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	char name[30];
	
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("���ڲ����Ķ������ǵ�%d��\n",m);
			printf("�������������£�\n");
			PreOrderTraverse(T,visit);
			printf("\n");
		}
		printf("      Menu for Linear Table On Binery Tree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. CreateBiTree    8. DeleteNode\n");
		printf("    	  2. ClearBiTree     9. PreOrderTraverse \n");
		printf("    	  3. BiTreeDepth     10. InOrderTraverse\n");
		printf("    	  4. LocateNode      11. PostOrderTraverse\n");
		printf("    	  5. Assign          12. LevelOrderTraverse\n");
		printf("    	  6. GetSibling      13. SaveBiTree\n");
		printf("    	  7. InsertNode      14. LoadBiTree\n");
		printf("          15. ����ɭ�ֲ���\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d",&op);
    	switch(op){
	   	case 1:/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK���������ͬ�Ĺؼ��֣�����ERROR��*/
			if(T){
				printf("�������Ѵ���\n");
				getchar();getchar();
				break;
			}
			i=0;
			printf("����������Ϊ�����������������������������У����ؼ���Ϊ0ʱ���������\n"); 
			do {
				scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
			} while (definition[i++].pos);
			tar=CreateBiTree(T,definition);
			if (tar==OK){
				printf("�����ɹ����������������������£�\n");
    			PreOrderTraverse(T,visit);
    			printf("\n");
    			InOrderTraverse(T,visit);
			}
			else printf("����ʧ��");
			getchar();getchar();
			break;
		 	
	   	case 2://�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
			if(ClearBiTree(T)==OK) printf("��������ճɹ���\n");
			else printf("���������ʧ�ܣ�\n");    
			if(target==1){
				RemoveList(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3://�������T�����
	   		tar=BiTreeDepth(T);
			printf("�����������Ϊ��%d\n",tar);   
		 	getchar();getchar();
		 	break;
		 	
	   	case 4://���ҽ��
			printf("��������Ĺؼ��֣�\n");
		 	scanf("%d",&e);
		 	p=LocateNode(T,e);
		 	if(!p){
		 		printf("����ʧ��\n");
			 }else{
			 	visit(p);
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 5://ʵ�ֽ�㸳ֵ��
	   		printf("�������޸Ľ��Ĺؼ��֣�\n");
		 	scanf("%d",&e);
		 	printf("������ؼ��ֺ����ݣ�\n");
		 	scanf("%d %s",&c.key,c.others);
		 	tar=Assign(T,e,c);
		 	if(!tar){
		 		printf("��ֵʧ�ܣ������ǹؼ����ظ��򲻴���\n");
			 }else{
			 	printf("��ֵ�ɹ�\n");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://ʵ�ֻ���ֵܽ��
	   		printf("������ؼ��֣�\n");
		 	scanf("%d",&e);
		 	p=GetSibling(T,e);
		 	if(!p){
		 		printf("û�ҵ��ֵܽ��\n");
			 }else{
			 	visit(p);
			 }
			getchar();getchar();
			break;
			
	   	case 7://������
		 	printf("���������н��Ĺؼ��֣�\n");
		 	scanf("%d",&e);
		 	printf("�������������ؼ��ֺ����ݣ�\n");
		 	scanf("%d %s",&c.key,c.others);
		 	printf("����������λ�ã�0-�� 1-�� -1-����:");
		 	scanf("%d",&LR);
		 	tar=InsertNode(T,e,LR,c);
		 	if(!tar){
		 		printf("����ʧ��");
			 }else{
			 	printf("����ɹ�");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://ɾ�����
		 	printf("��������ɾ�����Ĺؼ���:");
		 	scanf("%d",&e);
		 	tar=DeleteNode(T,e);
		 	if(!tar){
		 		printf("δ�ҵ����\n");
			}else{
				printf("ɾ���ɹ�\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 9://�������������T
		 	if(!PreOrderTraverse(T,visit)){
		 		printf("������Ϊ��\n");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://�������������T
	   		if(!InOrderTraverse(T,visit)){
		 		printf("������Ϊ��\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://�������������T(�ǵݹ�ʵ�� )
		 	if(!PostOrderTraverse(T,visit)){
		 		printf("������Ϊ��\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://�������������T
		 	if(!LevelOrderTraverse(T,visit)){
		 		printf("������Ϊ��\n");
			}
			getchar();getchar();
		 	break;
		 	
		case 13://���������Ľ������д�뵽�ļ�FileName��
		 	tar=SaveBiTree(T,FileName);
		 	if(tar==OK){
		 		printf("д�뵽�ļ��ɹ���\n");
			}else{
				printf("д��ʧ�ܣ�������������\n");
			}
			getchar();getchar();
		 	break;
		case 14://�����ļ�FileName�Ľ�����ݣ�����������
			tar=LoadBiTree(T,FileName);
			if(tar==OK){
				printf("���ݶ��뵽�������ɹ���\n");
			}else{
				printf("����ʧ�ܣ��������Ѵ��ڣ�\n");
			}
			getchar();getchar();
		 	break;
		case 15://����ɭ�ֲ��� 
			if(target==1){
					Lists.elem[m-1].L=T;
					target=0;
			}else{
				ClearBiTree(T);
			}
			while(op){
				system("cls");	printf("\n\n");
				printf("      Menu for Linear Table On Sequence Structure \n");
				printf("-------------------------------------------------\n");
				printf("    	  1. AddTree       2. RemoveTree\n");
				printf("    	  3. LocateTreee    4. ����Tree      \n");
				printf("    	  5. ��ʾTree     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    ��ѡ����Ĳ���[0~5]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])��Lists������һ������ΪListName�Ŀ����Ա�
						printf("�����������������\n");
						scanf("%d", &n);
						while(n--){
							printf("��������������ƣ�\n");
    						scanf("%s",name);
   							AddList(Lists,name);
							i=0;
							printf("����������Ϊ�����������������������������У����ؼ���Ϊ0ʱ���������\n"); 
							do {
								scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
							} while (definition[i++].pos);
							tar=CreateBiTree(Lists.elem[Lists.length-1].L,definition);
							if (tar==OK){
							printf("�����ɹ�\n");
							}
							else printf("�ؼ��ֲ�Ψһ\n");
   						}
   						printf("����������£�\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							PreOrderTraverse(Lists.elem[n].L,visit);
        					putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists��ɾ��һ������ΪListName�����Ա�
						printf("��������ɾ���Ķ����������ƣ�\n");
						scanf("%s",name);
   						if (RemoveList(Lists,name)==OK){
   							printf("ɾ����Ķ����������£�\n");
	   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							PreOrderTraverse(Lists.elem[n].L,visit);
        					putchar('\n');
   							}
   						}else{
							printf("ɾ��ʧ��");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])��Lists�в���һ������ΪListName�����Ա�
						printf("����������ҵĶ����������ƣ�\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("���ҵĶ��������£�\n");
   							printf("%s ",Lists.elem[n-1].name);
   							PreOrderTraverse(Lists.elem[n-1].L,visit);
         					putchar('\n');
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 4://����ѡ�е����Ա� 
						printf("��������Ҫ���в����Ķ����������ƣ�\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("���ҵĶ��������£�\n");
   							printf("%s ",Lists.elem[n-1].name);
   							PreOrderTraverse(Lists.elem[n-1].L,visit);
         					putchar('\n');
         					T=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 5://��ʾ�����Ա� 
		 				if(Lists.length==0){
		 					printf("�������Ϊ�ա�");
						}else{
							printf("����������£�\n");
							for(n=0;n<Lists.length;n++){
   								printf("%s ",Lists.elem[n].name);
   								PreOrderTraverse(Lists.elem[n].L,visit);
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



