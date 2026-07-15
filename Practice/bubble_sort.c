#include <stdio.h>

void bubble_sort(int* arr,int sz)
{
    int i;
    for(i = 0;i < sz;i++)
    {
        int j;
        for(j = 0;j < sz-i;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tem;
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    }
}

print_arr(int* arr,int sz)
{
    int i;
    for(i = 0;i < sz;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr,sz);
    bubble_sort(arr,sz);
    print_arr(arr,sz);
    return 0;
}
