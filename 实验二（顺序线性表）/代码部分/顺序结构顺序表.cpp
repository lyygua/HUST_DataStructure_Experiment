#include "def.h"
#include "defin.h"

int main(){
	SqList L;  
	LISTS Lists;
   	int n,e;
   	char name[30];
   	Lists.length=0;
	L.elem=NULL;
	int op=1;
	int target=0;
	int m=0;
	int i=0,j=0;
	int tar=0;
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("���ڲ����ı���%s",Lists.elem[m-1].name);
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
	   	case 1:
		 	if(InitList(L)==OK) printf("���Ա����ɹ���\n");
		    else printf("���Ա���ʧ�ܣ�\n");
		 	getchar();getchar();
		 	break;
		 	
	   	case 2:
		 	if(DestroyList(L)==OK) printf("���Ա����ٳɹ���\n");
			else printf("���Ա�����ʧ�ܣ�\n");    
			if(target==1){
				RemoveList(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3:
	   		if(ClearList(L)==OK) printf("���Ա���ճɹ���\n");
	   		else printf("���Ա����ʧ�ܣ�\n");      
		 	getchar();getchar();
		 	break;
		 	
	   	case 4:
		 	if(ListEmpty(L)==TRUE) printf("���Ա�Ϊ�գ�\n");
	   		else printf("���Ա�Ϊ�գ�\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 5:
	   		i=0;
	   		i=ListLength(L);
		 	if(i==-1) printf("���Ա����ڣ�\n");
	   		else printf("���Ա�ĳ���Ϊ%d��\n",i);     
		 	getchar();getchar();
		 	break;
		 	
	   	case 6:
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
			
	   	case 7://LocateElem(SqList L,ElemType e)
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
		 	
	   	case 8:
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
		 	
	   	case 9://NextElem(SqList L,ElemType e,ElemType &next)������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
		 	
	   	case 10://ListInsert(SqList &L,int i,ElemType e)������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
		 	
	   	case 11://ListDelete(SqList &L,int i,ElemType &e)������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
		 	
	   	case 12://ListTrabverse(SqList L)������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
		 	tar=ListTrabverse(L);
		 	if(tar==OK){
		 		printf("����ɹ���\n");	
			}else{
				printf("���Ա����ڣ�\n");	
			}
			getchar();getchar();
		 	break;
		 	
		case 13://SaveList(SqList L,char FileName[])������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
		 	tar=SaveList(L,FileName);
		 	if(tar==OK){
		 		printf("д�뵽�ļ��ɹ���\n");
			}else{
				printf("д��ʧ�ܣ����Ա�����\n");
			}
			getchar();getchar();
		 	break;
		case 14://LoadList(SqList &L,char FileName[])������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
					Lists.elem[m-1].L.length=L.length;
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
				printf("    ��ѡ����Ĳ���[0~4]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])��Lists������һ������ΪListName�Ŀ����Ա�
						printf("����������Ա������\n");
						scanf("%d", &n);
						while(n--){
							printf("���������Ա����ƣ�\n");
    						scanf("%s",name);
   							AddList(Lists,name);
   							printf("���������Ա�Ԫ�����ݣ�\n");
      						scanf("%d",&e);
      						while (e){
      							ListInsert(Lists.elem[Lists.length-1].L,Lists.elem[Lists.length-1].L.length+1,e);
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
		 				printf("�����Ա����£�\n");
						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							ListTrabverse(Lists.elem[n].L);
        					putchar('\n');
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



