////2200. 找出数组中的所有 K 近邻下标
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int numKey = 0, n = 0;
//    for (int i = 0; i < numsSize + k; i++)
//    {
//        if (i < numsSize)
//            numKey += (nums[i] == key);
//        if (i < k)
//            continue;
//
//        if (numKey)
//            ans[n++] = i - k;
//
//        if (i >= 2 * k)
//            numKey -= (nums[i - 2 * k] == key);
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2951. 找出峰值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findPeaks(int* mountain, int mountainSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * (mountainSize - 2));
//    int n = 0;
//    for (int i = 1; i < mountainSize - 1; i++)
//    {
//        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
//            ans[n++] = i;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2670. 找出不同元素数目差数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize)
//{
//    int cnt[51] = { 0 };
//    int prefix[numsSize];
//    prefix[0] = 1;
//    cnt[nums[0]] = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        prefix[i] = prefix[i - 1];
//        if (0 == cnt[nums[i]])
//            prefix[i]++;
//
//        cnt[nums[i]]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int suffix[numsSize];
//    --cnt[nums[0]];
//    suffix[0] = prefix[numsSize - 1] - (cnt[nums[0]] == 0);
//    ans[0] = prefix[0] - suffix[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        suffix[i] = suffix[i - 1];
//        cnt[nums[i]]--;
//
//        if (0 == cnt[nums[i]])
//            suffix[i]--;
//
//        ans[i] = prefix[i] - suffix[i];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
////3315. 构造最小位运算数组 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minBitwiseArray(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (0 == (nums[i] & 1))
//            ans[i] = -1;
//        else
//        {
//            int t = ~nums[i];
//            ans[i] = nums[i] ^ ((t & -t) >> 1);
//        }
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
