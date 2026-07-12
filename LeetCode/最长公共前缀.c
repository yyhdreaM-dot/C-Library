#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
    return "";

    char* pre = strs[0];
    int preLen = strlen(pre);
    int i,j;
    for(i = 0;i < strsSize;i++)
    {
        j = 0;
        while(pre[j] == strs[i][j] && pre[j] != '\0' && strs[i][j] != '\0')
        {
            j++;
        }
        if(j < preLen)
        preLen = j;
        if(preLen == 0)
        return "";
    }
    char* res = (char*)malloc(sizeof(char) * (preLen + 1));
    for(i = 0;i < preLen;i++)
    {
        res[i] = pre[i];
    }
    res[preLen] = '\0';
    return res;
}
