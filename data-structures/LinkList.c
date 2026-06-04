#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义学生信息 
typedef struct{
	char no[8];//8位学号 
	char name[20];//姓名 
	int price;//成绩 
}Student; 
//声明链表 
typedef struct LNode{
     Student data;       //数据域
     struct LNode *next;   //指针域
}LNode;
//初始化链表 
LNode* initList()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	return head; //返回头指针 
 } 
//用尾插法插入数据
LNode* get_tail(LNode* L)//获取尾部数据
{
	LNode* p = L;//使p指向链表头指针 
	while(p->next != NULL)
	{
		p = p->next; 
	 }
	return p; 
 } 
LNode* insertTail(LNode* tail,char* no,char* name,int price){
	LNode* p = (LNode*)malloc(sizeof(LNode));
	strcpy(p->data.no,no);
	strcpy(p->data.name,name);
	p->data.price = price;
	tail->next = p;
	p->next = NULL;
	return p;//把新的尾部传出 便于添加下一个元素
}
//根据姓名查找学生信息并返回学号和成绩
int findNode(LNode* L,char* name)
{
	LNode* p = L->next;
	if(p == NULL)
	{
		printf("此链表为空！\n");
		return 0;
	}
	int found = 0;
	while(p != NULL)
	{
		if(strcmp(p->data.name,name) == 0)
		{
			printf("该学生的学号为：%s\n",p->data.no);
			printf("该学生的成绩为：%d\n",p->data.price);
			found = 1;
		}
		p = p->next; 
	}
	if(found == 0)
	{
		printf("未找到该学生\n");
	}
}
//插入学生信息
int insertNode(LNode* L,int pos,char* no,char* name,int price)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	strcpy(p->data.no,no);
	strcpy(p->data.name,name);
	p->data.price = price;
	int i = 0;
	LNode* q = L;
	while(i < pos-1) //找到要插入位置的前驱节点 
	{
		q = q->next; 
		if(q == NULL)
		{
			printf("输入错误\n");
			return 0;  
		}
		i++;
	}
	p->next = q->next;
	q->next = p;
	return 0;
}
//根据位置返回学生信息
int getNode(LNode* L,int pos)
{
	int i = 0;
	LNode* p = L;
	if(p->next == NULL)
		{
			printf("此链表为空！\n");
			return 0;  
		}
	while(i < pos) //找到存储要返回学生信息的节点 
	{
		p = p->next; 
		if(p == NULL)
		{
			printf("输入错误\n");
			return 0;  
		}
		i++;
	}
	printf("该学生的学号为：%s\n",p->data.no);
	printf("该学生的姓名为：%s\n",p->data.name);
	printf("该学生的成绩为：%d\n",p->data.price);
	return 1;
}
//删除学生信息
int deleteNode(LNode* L,int pos)
{
	int i = 0;
	LNode* p = L;
	if(p->next == NULL)
		{
			printf("此链表为空！\n");
			return 0;  
		}

	while(i < pos-1)//找到要删除位置的前驱节点
	{
		p = p->next;
		if(p == NULL)
		{
			printf("输入错误\n");
			return 0;
		}
		i++;
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
 } 
//计算并返回学生个数
int Node_num(LNode* L)
{
	LNode* p = L->next;
	if(p == NULL)
	{
		return 0; 
	}
	int i = 0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
 } 
//遍历
void listList(LNode* L)
{
	LNode* p = L->next;
	while(p != NULL)
	{
		printf("学号：%s\n",p->data.no);
		printf("姓名：%s\n",p->data.name);
		printf("成绩：%d\n",p->data.price);
		p = p->next;
	}
 } 
//释放链表
void freeNode(LNode* L)
{
	LNode* p = L->next;
	LNode* q = (LNode*)malloc(sizeof(LNode));
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	printf("链表内存已释放！\n"); 
 } 
int main()
{
	LNode* LinkList = initList();//初始化一个链表
	char no[8];
	char name[20];
	int price;
	printf("1.输入学生个数和信息\n");
	printf("2.根据姓名查找学生学号和成绩\n");
	printf("3.插入学生信息\n");
	printf("4.根据输入位置返回学生的学号，姓名，成绩\n");
	printf("5.删除指定位置的学生信息\n");
	printf("6.统计表中学生个数\n"); 
	printf("0.退出程序并释放空间\n"); 
	while(1)
	{	
		printf("请输入0~6中的一个数字：\n");
		int num;
		scanf("%d",&num);
		if(num == 0)
		{
			freeNode(LinkList);
			break;
		}
		else if(num == 1)//输入学生个数和信息
		{
			int stuCount;
			printf("请输入学生个数：\n");
			scanf("%d",&stuCount);
			int i;
			printf("请逐个输入学生信息：\n");
			LNode* tail= get_tail(LinkList);//用来存储尾指针
			for(i = 1;i <= stuCount;i++)
			{
				printf("请输入第%d个学生的信息：\n",i);
				scanf("%s %s %d",no,name,&price);
				tail = insertTail(tail,no,name,price);
			}
			printf("输入后的链表为：\n");
			listList(LinkList);
		}
		else if(num == 2)//根据学生姓名查找并返回学号和成绩 
		{
			printf("请输入学生姓名：\n");
			scanf("%s",name);
			findNode(LinkList,name); 
		 } 
		else if(num == 3)//插入学生信息
		{
			printf("请输入要插入的位置：\n");
			int pos;
	 		scanf("%d",&pos);
	 		printf("请输入要插入的学生信息：\n");
	 		scanf("%s %s %d",no,name,&price);
	 		insertNode(LinkList,pos,no,name,price);
	 		printf("插入后的链表为：\n");
	 		listList(LinkList);
		 }
		else if(num == 4)//输入位置返回学生信息
		 {
		 	printf("请输入指定位置：\n");
		 	int pos;
		 	scanf("%d",&pos);
		 	getNode(LinkList,pos); 
		  } 
		else if(num == 5)//删除指定位置的学生信息
		{
			printf("请输入指定位置：\n");
			int pos;
			scanf("%d",&pos);
			deleteNode(LinkList,pos);
			printf("删除后的链表为：\n");
	 		listList(LinkList);
		}
		else if(num == 6)//统计表中学生个数
		{
			printf("表中学生个数为：%d\n",Node_num(LinkList));
		 } 
	 } 
	return 0;
}
