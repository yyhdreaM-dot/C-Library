#include <string.h>
int romanToInt(char* s) {
    //数组映射
    int map[256] = {0};
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int i;
    int num = 0;
    //左边大于等于右边相加 左边小于右边相减
    for(i = 0;i < strlen(s);i++)
    {
        //字母不可以直接比较大小 应转化为相应数字进行比较
        int num1 = map[s[i]];
        int num2 = map[s[i + 1]];
        if(num1 >= num2)
        num += num1;
        else num -= num1;
    }
    return num;
}
