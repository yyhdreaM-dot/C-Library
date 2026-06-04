#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
//定义学生信息 
typedef struct{
	char no[8];//8位学号 
	char name[20];//姓名 
	int price;//成绩 
}Student; 
//定义顺序表
typedef struct{
	Student elem[MAXSIZE];//定义顺序表的最大存储空间 
	int length;//顺序表的长度 
}SqList;
//顺序表初始化
void initList(SqList *L)
{
	L->length = 0;//此时顺序表长度为零 
 } 
//添加学生信息 
int appendElem(SqList *L,char no[8],char name[20],int price)
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表已满！\n");
		return 0;
	}
	strcpy(L->elem[L->length].no,no);
	strcpy(L->elem[L->length].name,name);
	L->elem[L->length].price = price;
	L->length++;
	return 1;
 } 
//根据姓名查找学生信息并返回学号和成绩
int findElem(SqList *L,char name[20])
{
	if(L->length == 0)
	{
		printf("空表\n");
		return 0;
	 } 
	int i,found = 0;
	for(i = 0;i < L->length;i++)
	{
		if(strcmp(L->elem[i].name,name) == 0)
		{
			printf("该学生的学号为：%s\n",L->elem[i].no);
			printf("该学生的成绩为：%d\n",L->elem[i].price);
			found = 1;
			break;
		}
	}
	if(found == 0)
	{
		printf("未找到该学生\n");
	}
	return 0;
 } 
//插入学生信息
int insertElem(SqList *L,int pos,char no[8],char name[20],int price) 
{
	if(L->length >= MAXSIZE)
	{
		printf("顺序表已满！\n");
		return 0;
	}
	if(pos < 1 || pos > L->length+1)
	{
		printf("输入错误\n");
		return 0;
	}
	if(pos <= L->length+1)
	{
		int i;
		for(i = L->length-1;i > pos-1;i--)
		{
			strcpy(L->elem[i+1].no,L->elem[i].no);
			strcpy(L->elem[i+1].name,L->elem[i].name);
			L->elem[i+1].price = L->elem[i].price;
		}
		strcpy(L->elem[pos-1].no,no);
		strcpy(L->elem[pos-1].name,name);
		L->elem[pos-1].price = price;
		L->length++;
		return 1;
	 } 
}
//根据位置返回学生信息
void  getElem(SqList *L,int pos)
{
	int found = 0;
	if(L->length == 0)
	{
		printf("空表\n");
	 } 
	if(pos < 1 || pos > L->length)
	{
		printf("输入错误\n");
	}
	int i;
	for(i = 0;i < L->length;i++)
	{
		if(i == pos-1)
		{
			printf("该学生的学号为：%s\n",L->elem[i].no);
			printf("该学生的姓名为：%s\n",L->elem[i].name);
			printf("该学生的成绩为：%d\n",L->elem[i].price);
			found = 1; 
		}
	}
	if(found == 0)
	{
		printf("未找到该学生\n");
	}
}
//删除学生信息
int deleteElem(SqList *L,int pos)
{
	if(L->length == 0)
	{
		printf("空表\n");
		return 0;
	 } 
	if(pos < 1 || pos > L->length)
	{
		printf("输入错误\n");
		return 0;
	}
	int i;
	for(i = pos-1;i < L->length;i++)
	{
		strcpy(L->elem[i].no,L->elem[i+1].no);
		strcpy(L->elem[i].name,L->elem[i+1].name);
		L->elem[i].price = L->elem[i+1].price;
	}
	L->length--;
	return 1;
 } 
//遍历
void listElem(SqList *L)
{
	int i;
	for(i = 0;i < L->length;i++)
	{
		printf("学号：%s\n",L->elem[i].no);
		printf("姓名：%s\n",L->elem[i].name);
		printf("成绩：%d\n",L->elem[i].price);
	}
 } 
int main()
{
	SqList list;
	initList(&list);
	char no[8];
	char name[20];
	int price;
	printf("1.输入学生个数和信息\n");
	printf("2.根据姓名查找学生学号和成绩\n");
	printf("3.插入学生信息\n");
	printf("4.根据输入位置返回学生的学号，姓名，成绩\n");
	printf("5.删除指定位置的学生信息\n");
	printf("6.统计表中学生个数\n"); 
	printf("0.退出程序\n"); 
	while(1)
	{
		printf("请输入0~6中的一个数字：\n");
		int num;
		scanf("%d",&num);
		if(num == 0)break;
		else if(num == 1)//输入学生个数和信息 
		{
			printf("请输入学生个数：\n");
			int stuCount;
			scanf("%d",&stuCount);
			if(stuCount>MAXSIZE)
			{
				printf("学生个数超过最大容量\n");
				continue;
			}
			printf("请逐个输入学生信息：\n");
			int i;
			for(i = 0;i < stuCount;i++)
			{
				printf("请输入第%i个学生信息：\n",i+1);
				scanf("%s %s %d",no,name,&price);
				appendElem(&list,no,name,price);
			}
			printf("输入后的顺序表为：\n"); 
			listElem(&list);
			printf("\n"); 
		}
		else if(num == 2)//根据学生姓名查找并返回学号和成绩 
		{
			printf("请输入学生姓名\n");
			scanf("%s",name);
			findElem(&list,name);
	 	}
	 	else if(num == 3)//插入学生信息 
	 	{
	 		printf("请输入要插入的位置：\n");
	 		int pos;
	 		scanf("%d",&pos);
	 		printf("请输入要插入的学生信息：\n");
	 		scanf("%s %s %d",no,name,&price);
	 		insertElem(&list,pos,no,name,price);
	 		printf("插入后的顺序表为：\n"); 
	 		listElem(&list);
	 		printf("\n"); 
		 }
		 else if(num == 4)//输入位置返回学生信息 
		 {
		 	printf("请输入指定位置：\n");
		 	int pos;
		 	scanf("%d",&pos);
		 	getElem(&list,pos);
		 }
		 else if(num == 5)//删除指定位置的学生信息
		 {
		 	printf("请输入指定位置：\n");
			int pos;
			scanf("%d",&pos);
			deleteElem(&list,pos); 
			printf("删除后的顺序表为：\n"); 
			listElem(&list);
	 		printf("\n"); 
		 }
		 else if(num == 6)//统计表中学生个数
		 {
		 	printf("表中学生个数为：%d\n",list.length);
		  } 
     }
	return 0;
 } 
