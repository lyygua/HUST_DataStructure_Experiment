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
	
	int m;//记录多线性表操作的是第几个表 
   	int n;//多线性表个数和传值变量 
   	KeyType e;
   	TElemType c;
   	int LR;
	int op=1;//循环控制变量 
	int target=0;//判断是否是多线性表操作 
	int i=0,j=0;//函数定位或添加或删除变量 
	int tar=0;//函数返回值标记 
	//int ans;
	
	char FileName[]="C:\\Users\\Luo Yuyang\\Desktop\\data.txt";
	char name[30];
	
	while(op){
		system("cls");	printf("\n\n");
		if(target==1){
			printf("现在操作的二叉树是第%d个\n",m);
			printf("二叉树数据如下：\n");
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
		printf("          15. 进入森林操作\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~15]:");
		scanf("%d",&op);
    	switch(op){
	   	case 1:/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，如果有相同的关键字，返回ERROR。*/
			if(T){
				printf("二叉树已存在\n");
				getchar();getchar();
				break;
			}
			i=0;
			printf("请输入序列为二叉树带空子树的先序遍历结点序列，当关键字为0时，输入结束\n"); 
			do {
				scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
			} while (definition[i++].pos);
			tar=CreateBiTree(T,definition);
			if (tar==OK){
				printf("创建成功，先序遍历和中序遍历如下：\n");
    			PreOrderTraverse(T,visit);
    			printf("\n");
    			InOrderTraverse(T,visit);
			}
			else printf("创建失败");
			getchar();getchar();
			break;
		 	
	   	case 2://将二叉树设置成空，并删除所有结点，释放结点空间
			if(ClearBiTree(T)==OK) printf("二叉树清空成功！\n");
			else printf("二叉树清空失败！\n");    
			if(target==1){
				RemoveList(Lists,Lists.elem[m-1].name);
				target=0;
			} 
		 	getchar();getchar();
		 	break;
		 	
	   	case 3://求二叉树T的深度
	   		tar=BiTreeDepth(T);
			printf("二叉树的深度为：%d\n",tar);   
		 	getchar();getchar();
		 	break;
		 	
	   	case 4://查找结点
			printf("请输入结点的关键字：\n");
		 	scanf("%d",&e);
		 	p=LocateNode(T,e);
		 	if(!p){
		 		printf("查找失败\n");
			 }else{
			 	visit(p);
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 5://实现结点赋值。
	   		printf("请输入修改结点的关键字：\n");
		 	scanf("%d",&e);
		 	printf("请输入关键字和内容：\n");
		 	scanf("%d %s",&c.key,c.others);
		 	tar=Assign(T,e,c);
		 	if(!tar){
		 		printf("赋值失败，可能是关键字重复或不存在\n");
			 }else{
			 	printf("赋值成功\n");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://实现获得兄弟结点
	   		printf("请输入关键字：\n");
		 	scanf("%d",&e);
		 	p=GetSibling(T,e);
		 	if(!p){
		 		printf("没找到兄弟结点\n");
			 }else{
			 	visit(p);
			 }
			getchar();getchar();
			break;
			
	   	case 7://插入结点
		 	printf("请输入树中结点的关键字：\n");
		 	scanf("%d",&e);
		 	printf("请输入待插入结点关键字和内容：\n");
		 	scanf("%d %s",&c.key,c.others);
		 	printf("请输入插入的位置（0-左 1-右 -1-根）:");
		 	scanf("%d",&LR);
		 	tar=InsertNode(T,e,LR,c);
		 	if(!tar){
		 		printf("插入失败");
			 }else{
			 	printf("插入成功");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://删除结点
		 	printf("请输入想删除结点的关键字:");
		 	scanf("%d",&e);
		 	tar=DeleteNode(T,e);
		 	if(!tar){
		 		printf("未找到结点\n");
			}else{
				printf("删除成功\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 9://先序遍历二叉树T
		 	if(!PreOrderTraverse(T,visit)){
		 		printf("二叉树为空\n");
			 }
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://中序遍历二叉树T
	   		if(!InOrderTraverse(T,visit)){
		 		printf("二叉树为空\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://后序遍历二叉树T(非递归实现 )
		 	if(!PostOrderTraverse(T,visit)){
		 		printf("二叉树为空\n");
			}
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://按层遍历二叉树T
		 	if(!LevelOrderTraverse(T,visit)){
		 		printf("二叉树为空\n");
			}
			getchar();getchar();
		 	break;
		 	
		case 13://将二叉树的结点数据写入到文件FileName中
		 	tar=SaveBiTree(T,FileName);
		 	if(tar==OK){
		 		printf("写入到文件成功！\n");
			}else{
				printf("写入失败，二叉树不存在\n");
			}
			getchar();getchar();
		 	break;
		case 14://读入文件FileName的结点数据，创建二叉树
			tar=LoadBiTree(T,FileName);
			if(tar==OK){
				printf("数据读入到二叉树成功！\n");
			}else{
				printf("读入失败，二叉树已存在！\n");
			}
			getchar();getchar();
		 	break;
		case 15://进入森林操作 
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
				printf("    	  3. LocateTreee    4. 操作Tree      \n");
				printf("    	  5. 显示Tree     0. Return\n");
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~5]:");
				scanf("%d",&op);
				
				switch(op){
					case 1://AddList(LISTS &Lists,char ListName[])在Lists中增加一个名称为ListName的空线性表
						printf("请输入二叉树个数：\n");
						scanf("%d", &n);
						while(n--){
							printf("请输入二叉树名称：\n");
    						scanf("%s",name);
   							AddList(Lists,name);
							i=0;
							printf("请输入序列为二叉树带空子树的先序遍历结点序列，当关键字为0时，输入结束\n"); 
							do {
								scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
							} while (definition[i++].pos);
							tar=CreateBiTree(Lists.elem[Lists.length-1].L,definition);
							if (tar==OK){
							printf("创建成功\n");
							}
							else printf("关键字不唯一\n");
   						}
   						printf("多二叉树如下：\n");
   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							PreOrderTraverse(Lists.elem[n].L,visit);
        					putchar('\n');
   						}
						getchar();getchar();
		 				break;
		 	
					case 2://RemoveList(LISTS &Lists,char ListName[])Lists中删除一个名称为ListName的线性表
						printf("请输入想删除的二叉树的名称：\n");
						scanf("%s",name);
   						if (RemoveList(Lists,name)==OK){
   							printf("删除后的二叉树表如下：\n");
	   						for(n=0;n<Lists.length;n++){
   							printf("%s ",Lists.elem[n].name);
   							PreOrderTraverse(Lists.elem[n].L,visit);
        					putchar('\n');
   							}
   						}else{
							printf("删除失败");
						}
						getchar();getchar();
		 				break;
		 				
					case 3://LocateList(LISTS Lists,char ListName[])在Lists中查找一个名称为ListName的线性表
						printf("请输入想查找的二叉树的名称：\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("查找的二叉树如下：\n");
   							printf("%s ",Lists.elem[n-1].name);
   							PreOrderTraverse(Lists.elem[n-1].L,visit);
         					putchar('\n');
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 4://操作选中的线性表 
						printf("请输入想要进行操作的二叉树的名称：\n");
						scanf("%s",name);
   						if (n=LocateList(Lists,name)){
   							printf("查找的二叉树如下：\n");
   							printf("%s ",Lists.elem[n-1].name);
   							PreOrderTraverse(Lists.elem[n-1].L,visit);
         					putchar('\n');
         					T=Lists.elem[n-1].L;
         					target=1;
         					m=n;
   						}else {
			  				 printf("查找失败");
						}
						getchar();getchar();
		 				break;
		 			case 5://显示多线性表 
		 				if(Lists.length==0){
		 					printf("多二叉树为空。");
						}else{
							printf("多二叉树如下：\n");
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
	printf("欢迎下次再使用本系统！\n");
}



