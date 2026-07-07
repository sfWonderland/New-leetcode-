//// 3532. 针对图的路径存在性查询 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int id[n];
//    id[0] = 0;
//    for (int i = 1; i < n; i++)
//    {
//        id[i] = id[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
//    }
//    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int x = queries[i][0];
//        int y = queries[i][1];
//        ans[i] = id[x] == id[y];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
