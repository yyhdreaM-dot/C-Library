#include <stdio.h>
//1.
void (* signal(int, void(*)(int)))(int);
//意义上等价于  void(*)(int) signal(int, void(*)(int)); 但语法上不允许这样写

//1.signal和()先结合，说明signal是一个函数名
//2.signal函数的第一个参数类型为int 第二个参数类型为函数指针
//3.该函数指针指向一个参数为int 返回类型为void的函数
//4.signal函数的返回类型也是一个函数指针
//5.这个函数指针也指向一个参数为int 返回类型为void的函数
//signal是一个函数的声明

//2.
//typedef 对类型的重定义(重命名)
typedef void(*pfun_t)(int);//对void(*)(int)的函数指针类型重命名为pfun_t
//错误写法：typedef void(*)(int) pfun_t;
pfun_t signal(int , pfun_t);

//这两种写法等价
int main()
{
  
    return 0;
}
