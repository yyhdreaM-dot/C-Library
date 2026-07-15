#include <stdio.h>

int Add(int x,int y)
{
    return x + y;
}

int Sub(int x,int y)
{
    return x - y;
}

int Mul(int x,int y)
{
    return x * y;
}

int Div(int x,int y)
{
    if(y == 0)
    return 0;
    return x / y;
}

void Menu()
{
    printf("***************菜单****************\n");
    printf("*****1.加法             2.减法*****\n");
    printf("*****3.乘法             4.除法*****\n");
    printf("***************0.退出**************\n");
}

int Calc(int(*pf)(int , int))
{
    int x,y;
    printf("请输入两个操作数：\n");
    scanf("%d %d",&x,&y);
    return pf(x,y);
}

int main()
{
    int input;
    printf("请选择：\n");
    scanf("%d",&input);
    switch(input)
    {
        case 1:
        {
            int ret = Calc(Add);
            printf("%d",ret);
            break;
        }
        case 2:
        {
            int ret = Calc(Sub);
            printf("%d",ret);
            break;
        }
        case 3:
        {
            int ret = Calc(Mul);
            printf("%d",ret);
            break;
        }
        case 4:
        {
            int ret = Calc(Div);
            printf("%d",ret);
            break;
        }
        case 0:
        {
            printf("退出\n");
            break;
        }
        default:
        {
            printf("输入错误\n");
            break;
        }
    }
    return 0;
}
