////3289. 数字小镇中的捣蛋鬼
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getSneakyNumbers(int* nums, int numsSize, int* returnSize)
//{
//    long long cnt[2] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i] / 63] ^= 1l << (nums[i] % 63);
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    int t = 0;
//    for (int i = 0; i < numsSize - 2; i++)
//    {
//        if ((cnt[i / 63] & (1l << (i % 63))) == 0)
//            ans[t++] = i;
//    }
//    *returnSize = 2;
//    return ans;
//}
//
////2966. 划分数组并满足最大差限制
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * numsSize / 3);
//    for (int i = 0; i < numsSize / 3; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * 3);
//        if (nums[i * 3] + k < nums[i * 3 + 2])
//        {
//            *returnSize = 0;
//            return NULL;
//        }
//        for (int j = 0; j < 3; j++)
//        {
//            ans[i][j] = nums[i * 3 + j];
//        }
//    }
//    *returnSize = numsSize / 3;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize / 3);
//    for (int i = 0; i < numsSize / 3; i++)
//    {
//        (*returnColumnSizes)[i] = 3;
//    }
//    return ans;
//}
//
////1828. 统计一个圆中点的数目
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int* ans = (int*)calloc(sizeof(int), queriesSize);
//
//    for (int j = 0; j < queriesSize; j++)
//    {
//        int x = queries[j][0];
//        int y = queries[j][1];
//        int r = queries[j][2];
//        for (int i = 0; i < pointsSize; i++)
//        {
//            int xi = points[i][0] - x;
//            int yi = points[i][1] - y;
//            if (xi * xi + yi * yi <= r * r)
//                ans[j]++;
//        }
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////2956. 找到两个数组中的公共元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    int cnt[100] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        cnt[nums1[i] - 1] = 1;
//    }
//    for (int i = 0; i < nums2Size; i++)
//    {
//        cnt[nums2[i] - 1] += 2;
//    }
//    int* ans = (int*)calloc(sizeof(int), 2);
//    for (int i = 0; i < nums1Size; i++)
//    {
//        ans[0] += cnt[nums1[i] - 1] > 1;
//    }
//    for (int i = 0; i < nums2Size; i++)
//    {
//        ans[1] += cnt[nums2[i] - 1] & 1;
//    }
//    *returnSize = 2;
//    return ans;
//}
//
