#include "def.h"
#include "func.h"

int main(){
	LinkList L=NULL;
	LISTS Lists;
	Lists.length=0;
	
	int m;//��¼�����Ա�������ǵڼ����� 
   	int n,e;//�����Ա�����ʹ�ֵ���� 
	int op=1;//ѭ�����Ʊ��� 
	int target=0;//�ж��Ƿ��Ƕ����Ա���� 
	int i=0,j=0;//������λ����ӻ�ɾ������ 
	int tar=0;//��������ֵ��� 
	
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	char name[30];
	
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("���ڲ����ı��ǵ�%d��\n",m);
			printf("���Ա��������£�\n");
			ListTrabverse(L);
			printf("\n");
		}
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       8. PriorElem\n");
		printf("    	  2. DestroyList    9. NextElem \n");
		printf("    	  3. ClearList      10. ListInsert\n");
		printf("    	  4. ListEmpty      11. ListDelete\n");
		printf("    	  5. ListLength     12. ListTrabverse\n");
		printf("    	  6. GetElem        13. SaveList\n");
		printf("    	  7. LocateElem     14. LoadList\n");
		printf("          15. ��������Ա����\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d",&op);
    	switch(op){
	   	case 1://InitList(LinkList &L)�Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
		 	if(InitList(L)==OK) printf("���Ա����ɹ���\n");
		    else printf("���Ա���ʧ�ܣ�\n");
		 	getchar();getchar();
		 	break;
		 	
	   	case 2://DestroyList(LinkList &L)������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
		 	if(DestroyList(L)==OK) printf("���Ա����ٳɹ���\n");
			else printf("���Ա�����ʧ�ܣ�\n");    
			if(target==1){
				RemoveList(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3://ClearList(LinkList &L)������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
	   		if(ClearList(L)==OK) printf("���Ա���ճɹ���\n");
	   		else printf("���Ա����ʧ�ܣ�\n");      
		 	getchar();getchar();
		 	break;
		 	
	   	case 4://ListEmpty(LinkList L)������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��	
			tar=ListEmpty(L);
		 	if(tar==TRUE) printf("���Ա�Ϊ�գ�\n");
	   		else if(tar==FALSE) printf("���Ա�Ϊ�գ�\n"); 
			else printf("���Ա����ڣ�\n");   
		 	getchar();getchar();
		 	break;
		 	
	   	case 5://ListLength(LinkList L)������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
	   		i=0;
	   		i=ListLength(L);
		 	if(i==-1) printf("���Ա����ڣ�\n");
	   		else printf("���Ա�ĳ���Ϊ%d��\n",i);     
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://GetElem(LinkList L,int i,ElemType &e)������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
	   		printf("���������ȡ��Ԫ�ص�λ��:\n��������0������ȡ\n");
	   		scanf("%d",&i);
	   		while(i){
	   			tar=GetElem(L,i,j);
	   			if(tar==OK){
				   printf("���Ա�ĵ�%dλ��%d\n",i,j);
				}else if(tar==INFEASIBLE){
					printf("���Ա����ڣ�\n");
					break; 
				}else{
					printf("�����λ�ò��Ϸ�������������\n");
				}
				printf("���������ȡ��Ԫ�ص�λ��,��������0������ȡ:\n");
				scanf("%d",&i);
			}
			printf("��ȡ����\n");
			getchar();getchar();
			break;
			
	   	case 7://LocateElem(LinkList L,ElemType e)������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
		 	printf("����������ҵ�Ԫ�أ�\n");
		 	scanf("%d",&i);
		 	j=LocateElem(L,i);
		 	if(j==INFEASIBLE){
		 		printf("���Ա����ڣ�\n");
			}else if(j==ERROR){
				printf("δ�ҵ���Ԫ�أ�\n");
			}else{
				printf("Ԫ��%d��λ���ڵ�%d��\n",i,j);
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://PriorElem(LinkList L,ElemType e,ElemType &pre)������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
		 	printf("�����������ǰ����Ԫ�أ�\n");
			scanf("%d",&i);
			tar=PriorElem(L,i,j);
			if(tar==OK){
				printf("Ԫ��%d��ǰ����%d\n",i,j);
			}else if(tar==ERROR){
				printf("Ԫ��%dû��ǰ��Ԫ��\n");
			}else{
				printf("���Ա����ڣ�\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 9://NextElem(LinkList L,ElemType e,ElemType &next)������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
		 	printf("����������Һ�̵�Ԫ�أ�\n");
			scanf("%d",&i);
			tar=NextElem(L,i,j);
			if(tar==OK){
				printf("Ԫ��%d�ĺ����%d\n",i,j);
			}else if(tar==ERROR){
				printf("Ԫ��û�к��\n");
			}else{
				printf("���Ա�Ϊ�գ�\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://ListInsert(LinkList &L,int i,ElemType e)������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
			printf("����������Ԫ�أ�\n");
			scanf("%d",&j);
			printf("���������Ԫ�ص�λ�ã�\n");
			scanf("%d",&i);
			tar=ListInsert(L,i,j);
			if(tar==OK){
				printf("����ɹ���\n");
			}else if(tar==ERROR){
				printf("����λ�ò���ȷ��\n");
			}else{
				printf("���Ա����ڣ�\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://ListDelete(LinkList &L,int i,ElemType &e)������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
		 	printf("������ɾ��Ԫ�ص�λ�ã�\n");
			scanf("%d",&i); 
			tar=ListDelete(L,i,j);
			if(tar==OK){
				printf("ɾ���ɹ���\n");
			}else if(tar==ERROR){
				printf("ɾ��λ�ò���ȷ��\n");
			}else{
				printf("���Ա����ڣ�\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://ListTraverse(LinkList L)������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
		 	tar=ListTrabverse(L);
		 	if(tar==OK){
		 		printf("����ɹ���\n");	
			}else{
				printf("���Ա����ڣ�\n");	
			}
			getchar();getchar();
		 	break;
		 	
		case 13://SaveList(LinkList L,char FileName[])������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
		 	tar=SaveList(L,FileName);
		 	if(tar==OK){
		 		printf("д�뵽�ļ��ɹ���\n");
			}else{
				printf("д��ʧ�ܣ����Ա�����\n");
			}
			getchar();getchar();
		 	break;
		case 14://LoadList(LinkList &L,char FileName[])������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
			tar=LoadList(L,FileName);
			if(tar==OK){
				printf("���ݶ��뵽���Ա�ɹ���\n");
			}else{
				printf("����ʧ�ܣ����Ա��Ѵ��ڣ�\n");
			}
			getchar();getchar();
		 	break;
		case 15:
			if(target==1){
					Lists.elem[m-1].L=L;
					target=0;
				}
			while(op){
				system("cls");	printf("\n\n");
				printf("      Menu for Linear Table On Sequence Structure \n");
				printf("-------------------------------------------------\n");
				printf("    	  1. AddList       2. RemoveList\n");
				printf("    	  3. LocateList    4. ����List      \n");
				printf("    	  5. ��ʾLists     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    ��ѡ����Ĳ���[0~5]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])��Lists������һ������ΪListName�Ŀ����Ա�
						printf("����������Ա������\n");
						scanf("%d", &n);
						while(n--){
							printf("���������Ա����ƣ�\n");
    						scanf("%s",name);
   							AddList(Lists,name);
   							printf("���������Ա�Ԫ�����ݣ�(��������0����)\n");
      						scanf("%d",&e);
      						while (e){
      							ListInsert(Lists.elem[Lists.length-1].L,ListLength(Lists.elem[Lists.length-1].L)+1,e);
      							scanf("%d",&e);
      						}
   						}
   						printf("�����Ա����£�\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							ListTrabverse(Lists.elem[n].L);
        					putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists��ɾ��һ������ΪListName�����Ա�
						printf("��������ɾ�������Ա�����ƣ�\n");
						scanf("%s",name);
   						if (RemoveList(Lists,name)==OK){
   							printf("ɾ����Ķ����Ա����£�\n");
	   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							ListTrabverse(Lists.elem[n].L);
        					putchar('\n');
   							}
   						}else{
							printf("ɾ��ʧ��");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])��Lists�в���һ������ΪListName�����Ա�
						printf("����������ҵ����Ա�����ƣ�\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("���ҵ����Ա����£�\n");
   							printf("%s ",Lists.elem[n-1].name);
   							ListTrabverse(Lists.elem[n-1].L);
         					putchar('\n');
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 4://����ѡ�е����Ա� 
						printf("��������Ҫ���в��������Ա�����ƣ�\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("���ҵ����Ա����£�\n");
   							printf("%s ",Lists.elem[n-1].name);
   							ListTrabverse(Lists.elem[n-1].L);
         					putchar('\n');
         					L=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("����ʧ��");
						}
						getchar();getchar();
		 				break;
		 			case 5://��ʾ�����Ա� 
		 				if(Lists.length==0){
		 					printf("�����Ա�Ϊ�ա�");
						}else{
							printf("�����Ա����£�\n");
							for(n=0;n<Lists.length;n++){
   								printf("%s ",Lists.elem[n].name);
   								ListTrabverse(Lists.elem[n].L);
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



