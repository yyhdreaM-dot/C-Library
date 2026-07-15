/*qsort -- 库函数
    头文件为 stdlib.h
    void qsort(void* base,//待排序数据中的第一个元素地址
                size_t num,//待排数据元素个数
                size_t size,//待排数据中一个元素的大小，单位是字节
                int (*cmp)(const void*, const void*)//用来比较待排数据中的两个元素的函数
                //const void*表示一个万能指针 指向的数据只读、不可修改,能接收任意类型变量的地址    
                //返回类型为int >0表示第一个元素大于第二个元素
                            // <0表示第一个元素小于第二个元素
                            // =0表示两个元素相等
    );*/
#include <stdio.h>
#include <stdlib.h>
void print_arr(int* arr,int sz)
{
    int i;
    for(i = 0;i < sz;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int cmp_int(const void* e1,const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int main()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr,sz);
    //排序
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    //打印
    print_arr(arr,sz);
    return 0;
}
