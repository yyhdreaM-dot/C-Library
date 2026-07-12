#include <stdio.h>

int Add(int x,int y)
{
    return x + y;
}

int Sub(int x,int y)
{
    return x - y;
}
int main()
{
    int (*pf1)(int ,int) = Add;
    int (*pf2)(int ,int) = Sub;
    int (*pfArr[2])(int ,int) = {pf1,pf2};
    //等价于 int (*pfArr[2])(int ,int) = {Add,Sub};
    //pfArr就是一个函数指针数组
    //函数指针数组可以存放多个同类型的函数指针
    return 0;
}
