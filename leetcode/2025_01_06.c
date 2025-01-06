#define _CRT_SECURE_NO_WARNINGS

//136.只出现一次的数字

int singleNumber(int* nums, int numsSize) 
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    return ret;
}

