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
			printf("现在操作的表是%s",Lists.elem[m-1].name);
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
		printf("          15. 进入多线性表操作\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~15]:");
		scanf("%d",&op);
    	switch(op){
	   	case 1:
		 	if(InitList(L)==OK) printf("线性表创建成功！\n");
		    else printf("线性表创建失败！\n");
		 	getchar();getchar();
		 	break;
		 	
	   	case 2:
		 	if(DestroyList(L)==OK) printf("线性表销毁成功！\n");
			else printf("线性表销毁失败！\n");    
			if(target==1){
				RemoveList(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3:
	   		if(ClearList(L)==OK) printf("线性表清空成功！\n");
	   		else printf("线性表清空失败！\n");      
		 	getchar();getchar();
		 	break;
		 	
	   	case 4:
		 	if(ListEmpty(L)==TRUE) printf("线性表为空！\n");
	   		else printf("线性表不为空！\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 5:
	   		i=0;
	   		i=ListLength(L);
		 	if(i==-1) printf("线性表不存在！\n");
	   		else printf("线性表的长度为%d！\n",i);     
		 	getchar();getchar();
		 	break;
		 	
	   	case 6:
	   		printf("请输入想获取的元素的位置:\n输入数字0结束获取\n");
	   		scanf("%d",&i);
	   		while(i){
	   			tar=GetElem(L,i,j);
	   			if(tar==OK){
				   printf("线性表的第%d位是%d\n",i,j);
				}else if(tar==INFEASIBLE){
					printf("线性表不存在！\n");
					break; 
				}else{
					printf("输入的位置不合法，请重新输入\n");
				}
				printf("请输入想获取的元素的位置,输入数字0结束获取:\n");
				scanf("%d",&i);
			}
			printf("获取结束\n");
			getchar();getchar();
			break;
			
	   	case 7://LocateElem(SqList L,ElemType e)
		 	printf("请输入想查找的元素：\n");
		 	scanf("%d",&i);
		 	j=LocateElem(L,i);
		 	if(j==INFEASIBLE){
		 		printf("线性表不存在！\n");
			}else if(j==ERROR){
				printf("未找到该元素！\n");
			}else{
				printf("元素%d的位置在第%d个\n",i,j);
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 8:
		 	printf("请输入想查找前驱的元素：\n");
			scanf("%d",&i);
			tar=PriorElem(L,i,j);
			if(tar==OK){
				printf("元素%d的前驱是%d\n",i,j);
			}else if(tar==ERROR){
				printf("元素%d没有前驱元素\n");
			}else{
				printf("线性表不存在！\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 9://NextElem(SqList L,ElemType e,ElemType &next)如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
		 	printf("请输入想查找后继的元素：\n");
			scanf("%d",&i);
			tar=NextElem(L,i,j);
			if(tar==OK){
				printf("元素%d的后继是%d\n",i,j);
			}else if(tar==ERROR){
				printf("元素没有后继\n");
			}else{
				printf("线性表为空！\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://ListInsert(SqList &L,int i,ElemType e)如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
			printf("请输入插入的元素：\n");
			scanf("%d",&j);
			printf("请输入插入元素的位置：\n");
			scanf("%d",&i);
			tar=ListInsert(L,i,j);
			if(tar==OK){
				printf("插入成功！\n");
			}else if(tar==ERROR){
				printf("插入位置不正确！\n");
			}else{
				printf("线性表不存在！\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://ListDelete(SqList &L,int i,ElemType &e)如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
		 	printf("请输入删除元素的位置：\n");
			scanf("%d",&i); 
			tar=ListDelete(L,i,j);
			if(tar==OK){
				printf("删除成功！\n");
			}else if(tar==ERROR){
				printf("删除位置不正确！\n");
			}else{
				printf("线性表不存在！\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://ListTrabverse(SqList L)如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
		 	tar=ListTrabverse(L);
		 	if(tar==OK){
		 		printf("输出成功！\n");	
			}else{
				printf("线性表不存在！\n");	
			}
			getchar();getchar();
		 	break;
		 	
		case 13://SaveList(SqList L,char FileName[])如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
		 	tar=SaveList(L,FileName);
		 	if(tar==OK){
		 		printf("写入到文件成功！\n");
			}else{
				printf("写入失败，线性表不存在\n");
			}
			getchar();getchar();
		 	break;
		case 14://LoadList(SqList &L,char FileName[])如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
			tar=LoadList(L,FileName);
			if(tar==OK){
				printf("数据读入到线性表成功！\n");
			}else{
				printf("读入失败，线性表已存在！\n");
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
				printf("    	  3. LocateList    4. 操作List      \n");
				printf("    	  5. 显示Lists     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~4]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])在Lists中增加一个名称为ListName的空线性表
						printf("请输入多线性表个数：\n");
						scanf("%d", &n);
						while(n--){
							printf("请输入线性表名称：\n");
    						scanf("%s",name);
   							AddList(Lists,name);
   							printf("请输入线性表元素数据：\n");
      						scanf("%d",&e);
      						while (e){
      							ListInsert(Lists.elem[Lists.length-1].L,Lists.elem[Lists.length-1].L.length+1,e);
      							scanf("%d",&e);
      						}
   						}
   						printf("多线性表如下：\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							ListTrabverse(Lists.elem[n].L);
        					putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists中删除一个名称为ListName的线性表
						printf("请输入想删除的线性表的名称：\n");
						scanf("%s",name);
   						if (RemoveList(Lists,name)==OK){
   							printf("删除后的多线性表如下：\n");
	   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							ListTrabverse(Lists.elem[n].L);
        					putchar('\n');
   							}
   						}else{
							printf("删除失败");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])在Lists中查找一个名称为ListName的线性表
						printf("请输入想查找的线性表的名称：\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("查找的线性表如下：\n");
   							printf("%s ",Lists.elem[n-1].name);
   							ListTrabverse(Lists.elem[n-1].L);
         					putchar('\n');
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 4://操作选中的线性表 
						printf("请输入想要进行操作的线性表的名称：\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("查找的线性表如下：\n");
   							printf("%s ",Lists.elem[n-1].name);
   							ListTrabverse(Lists.elem[n-1].L);
         					putchar('\n');
         					L=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 5://显示多线性表 
		 				printf("多线性表如下：\n");
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
	printf("欢迎下次再使用本系统！\n");
}



