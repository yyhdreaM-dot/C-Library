#include <stdio.h>
int main()
{
   int a = 10;
   int* pa = &a;

   char ch = 'a';
   char* pch = &ch;

   int arr[10] = {0};
   int (*parr)[10] = &arr;//取出数组的地址
   //&arr是数组的地址 arr是数组首元素的地址
   //parr是指向数组的指针 存放的是数组的地址

   //int (*pf)(int , int) = &Add;
   int (*pf)(int , int) = Add;//Add == pf
   //pf是一个函数指针变量 函数指针是一种指向函数的指针 存放的是函数的地址
   //函数指针类型的定义应与指向的函数类型一致 括号内声明函数的变量类型与个数也与函数保持一致
   int ret = (*pf)(3,5);//调用函数指针所指向的函数
   //int ret = Add(3,5);
   //int ret = pf(3,5);
   //这三种调用方式完全等价 但第二种方式未利用函数指针
   return 0;
}
int Add(int x,int y)
{
    return x+y;
}
