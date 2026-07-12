/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for(i = 0;i < numsSize;i++)
    {
        for(j = i+1;j < numsSize;j++)
        {
            if(nums[i] + nums[j] == target){
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;//为returnSize赋值 返回int类型数据的个数
                return ret;
            }
        }
    }
    *returnSize == 0;returnSize为零说明未找到 指针为空
    return NULL;
}
