//#define _CRT_SECURE_NO_WARNINGS
//
////1365.有多少小于当前数字的数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
//{
//    int h[101] = { 0 };
//    int* ret = (int*)malloc(sizeof(int) * numsSize);
//    memset(ret, 0, sizeof(ret));
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret[i] = nums[i];
//    }
//
//    qsort(nums, numsSize, sizeof(int), cmp);
//
//    int sum = 0;
//    int smaller = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != nums[smaller])
//        {
//            h[nums[i]] = sum;
//            smaller = i;
//        }
//        sum++;
//    }
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret[i] = h[ret[i]];
//    }
//
//    *returnSize = numsSize;
//    return ret;
//}
//
////2389. 和有限的最长子序列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int binarySearch(int* arr, int arrSize, int target)
//{
//    int left = 1;
//    int right = arrSize;
//    while (left < right)
//    {
//        int mid = (right - left) / 2 + left;
//        if (arr[mid] > target)
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int sum[numsSize + 1];
//    sum[0] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum[i + 1] = nums[i] + sum[i];
//    }
//
//    *returnSize = queriesSize;
//    int* ret = (int*)malloc(sizeof(int) * queriesSize);
//
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ret[i] = binarySearch(sum, numsSize + 1, queries[i]) - 1;
//    }
//
//    return ret;
//}
//
////1380.矩阵中的幸运数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
//{
//    int* luckyNum = (int*)malloc(sizeof(int));
//    int rowMax = 0;
//    int k = 0;
//    for (int i = 0; i < matrixSize; i++)
//    {
//        int index = 0;
//        for (int j = 1; j < *matrixColSize; j++)
//        {
//            if (matrix[i][index] > matrix[i][j])
//                index = j;
//        }
//        if (rowMax < matrix[i][index])
//        {
//            rowMax = matrix[i][index];
//            k = index;
//        }
//    }
//
//    for (int i = 0; i < matrixSize; i++)
//    {
//        if (rowMax < matrix[i][k])
//        {
//            *returnSize = 0;
//            return NULL;
//        }
//    }
//
//    *returnSize = 1;
//    luckyNum[0] = rowMax;
//    return luckyNum;
//}
//
