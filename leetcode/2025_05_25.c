////1647. 字符频次唯一的最小删除次数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minDeletions(char* s)
//{
//    int hash[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        hash[s[i] - 'a']++;
//    }
//    qsort(hash, 26, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 1; i < 26; i++)
//    {
//        if (hash[i] > 0 && hash[i] >= hash[i - 1])
//        {
//            if (hash[i - 1] > 0)
//            {
//                ans += hash[i] - hash[i - 1] + 1;
//                hash[i] = hash[i - 1] - 1;
//            }
//            else
//            {
//                ans += hash[i];
//                hash[i] = 0;
//            }
//        }
//    }
//    return ans;
//}
//
////2971. 找到最大周长的多边形
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long largestPerimeter(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long parametre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        parametre += nums[i];
//    }
//    //printf("%d/n", parametre);
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (parametre - nums[i] > nums[i])
//            break;
//        else
//            parametre -= nums[i];
//    }
//    return parametre > 0 ? parametre : -1;
//}
//
////2178. 拆分成最多数目的正偶数之和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//long long* maximumEvenSplit(long long finalSum, int* returnSize)
//{
//    long long* ans = NULL;
//    *returnSize = 0;
//    if (finalSum & 1)
//        return ans;
//    int n = sqrt(finalSum) + 1;
//    ans = (long long*)calloc(n, sizeof(long long));
//    for (int i = 2; i <= finalSum; i += 2)
//    {
//        ans[++(*returnSize) - 1] = i;
//        finalSum -= i;
//    }
//    ans[(*returnSize) - 1] += finalSum;
//    return ans;
//}
//
////2567. 修改两个元素的最小分数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minimizeSum(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int min1 = nums[numsSize - 3] - nums[0];
//    int min2 = nums[numsSize - 2] - nums[1];
//    int min3 = nums[numsSize - 1] - nums[2];
//    return fmin(min1, fmin(min2, min3));
//}
//
