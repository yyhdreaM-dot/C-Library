#include <stdio.h>
#include <stdlib.h>
//二叉树结点结构 
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 
//建立二叉树（前序输入，#表示空）
void CreateBiTree(BiTree *T){
	char ch;
	scanf(" %c",&ch);
	if(ch == '#'){
		*T = NULL;
	}
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));//递归输入 
	}
} 
//中序遍历
void InOrder(BiTree T){
	if(T){
		InOrder(T->lchild);
		printf("%c",T->data);
		InOrder(T->rchild);
	}
} 
//前序遍历
void PreOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 
//后序遍历
void PostOrder(BiTree T){
	if(T){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
} 
//计算二叉树深度
int Depth(BiTree T){
	if(!T) return 0;
	int leftDepth = Depth(T->lchild);
	int rightDepth = Depth(T->rchild);
	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;//加上根节点 
} 
//统计结点总数 
int NodeCount(BiTree T){
	if(!T)return 0;
	return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
} 
//统计叶子结点个数
int LeafCount(BiTree T){
	if(!T) return 0;
	//左右结点都为空即为叶子节点 
	if(!T->lchild && !T->rchild) return 1;
	return LeafCount(T->lchild) + LeafCount(T->rchild); 
} 
//统计度为一的结点个数 
int OneDegreeCount(BiTree T){
	if(!T) return 0;
	int cnt = 0;
	if((T->lchild && !T->rchild) || (!T->lchild && T->rchild)) cnt = 1;
	return cnt + OneDegreeCount(T->lchild) + OneDegreeCount(T->rchild);
} 
//输出每个叶子结点到根的路径 
void PrintPath(BiTree T,char path[],int len){
	if(!T);
	path[len++] = T->data;
	//到达叶子结点,输出路径 
	if(!T->lchild && !T->rchild){
		int i;
		for(i = 0;i < len;i++){
			printf("%c",path[i]);
		}	
		printf("\n");
	} 
	else{
		PrintPath(T->lchild,path,len);
		PrintPath(T->rchild,path,len);
	}
} 
//主函数
int main(){
	BiTree T;
	printf("请按前序输入二叉树（#代表空结点）：\n");
	CreateBiTree(&T);
	printf("\n前序遍历：");
	PreOrder(T); 
	printf("\n中序遍历："); 
	InOrder(T);
	printf("\n后序遍历：");
	PostOrder(T);
	printf("\n二叉树深度：%d\n",Depth(T));
	printf("结点总数：%d\n",NodeCount(T));
	printf("叶子结点数：%d\n",LeafCount(T));
	printf("度为一的结点数：%d\n",OneDegreeCount(T));
	printf("叶子到根的路径:");
	char path[100];
	PrintPath(T,path,0); 
	return 0;
} 
