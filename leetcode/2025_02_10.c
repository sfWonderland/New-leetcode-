//#define _CRT_SECURE_NO_WARNINGS
//
////1399.统计最大组的数目
//
//int digitSum(int n)
//{
//    int sum = n % 10;
//    while (n > 9)
//    {
//        n /= 10;
//        sum += n % 10;
//    }
//    return sum;
//}
//int countLargestGroup(int n)
//{
//    int h[36] = { 0 };
//    int max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int m = digitSum(i + 1);
//        h[m - 1]++;
//        if (max < h[m - 1])
//            max = h[m - 1];
//    }
//    //printf("max = %d\n", max);
//    int ret = 0;
//    for (int i = 0; i < 36; i++)
//    {
//        if (max == h[i])
//            ret++;
//    }
//    return ret;
//}
//
////1403.非递增顺序的最小子序列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int* minSubsequence(int* nums, int numsSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max += nums[i];
//        if (max > sum / 2)
//        {
//            *returnSize = i + 1;
//            break;
//        }
//    }
//    return nums;
//}