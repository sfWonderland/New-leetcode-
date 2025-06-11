////2657. 找到两个数组的前缀公共数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize)
//{
//    int* ans = (int*)calloc(sizeof(int), ASize);
//    long long fre1 = 0, fre2 = 0;
//    for (int i = 0; i < ASize; i++)
//    {
//        fre1 |= (long long)1 << A[i];
//        fre2 |= (long long)1 << B[i];
//        long long fre = fre1 & fre2;
//        ans[i] = 0;
//        while (fre)
//        {
//            ans[i]++;
//            fre &= fre - 1;
//        }
//    }
//    *returnSize = ASize;
//    return ans;
//}
//
////1310. 子数组异或查询
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int* pre = (int*)malloc(sizeof(int) * (arrSize + 1));
//    pre[0] = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        pre[i + 1] = arr[i] ^ pre[i];
//    }
//    int* ans = (int*)calloc(sizeof(int), queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans[i] = pre[queries[i][1] + 1] ^ pre[queries[i][0]];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////2683. 相邻值的按位异或
//
//bool doesValidArrayExist(int* derived, int derivedSize)
//{
//    int ans = 0;
//    for (int i = 0; i < derivedSize; i++)
//    {
//        ans ^= derived[i];
//    }
//    return ans == 0;
//}
//
////1829. 每个查询的最大异或值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize)
//{
//    int* xor = (int*)malloc(sizeof(int) * numsSize);
//    xor [0] = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        xor [i] = xor [i - 1] ^ nums[i];
//    }
//    int dest = (1 << maximumBit) - 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] = dest ^ xor [numsSize - 1 - i];
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize)
//{
//    int xor = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        xor ^= nums[i];
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int dest = (1 << maximumBit) - 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[i] = dest^ xor;
//        xor ^= nums[numsSize - 1 - i];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
