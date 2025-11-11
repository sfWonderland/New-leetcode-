////2132. 用邮票贴满网格图
//
//bool possibleToStamp(int** grid, int gridSize, int* gridColSize, int stampHeight, int stampWidth)
//{
//    int m = gridSize, n = gridColSize[0];
//    int s[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        memset(s[i], 0, sizeof(s[i]));
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + grid[i][j];
//        }
//    }
//    int d[m + 2][n + 2];
//    for (int i = 0; i <= m + 1; i++)
//    {
//        memset(d[i], 0, sizeof(d[i]));
//    }
//    for (int i2 = stampHeight; i2 <= m; i2++)
//    {
//        for (int j2 = stampWidth; j2 <= n; j2++)
//        {
//            int i1 = i2 - stampHeight + 1;
//            int j1 = j2 - stampWidth + 1;
//            if (s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1] == 0)
//            {
//                d[i1][j1]++;
//                d[i2 + 1][j1]--;
//                d[i1][j2 + 1]--;
//                d[i2 + 1][j2 + 1]++;
//            }
//        }
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
//            if (grid[i][j] == 0 && d[i + 1][j + 1] == 0)
//                return false;
//        }
//    }
//    return true;
//}
//
////2536. 子矩阵元素加 1
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes)
//{
//    int d[n + 2][n + 2];
//    for (int i = 0; i <= n + 1; i++)
//    {
//        memset(d[i], 0, sizeof(d[i]));
//    }
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int i1 = queries[i][0] + 1;
//        int j1 = queries[i][1] + 1;
//        int i2 = queries[i][2] + 1;
//        int j2 = queries[i][3] + 1;
//        d[i2 + 1][j2 + 1]++;
//        d[i1][j1]++;
//        d[i1][j2 + 1]--;
//        d[i2 + 1][j1]--;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * n);
//        (*returnColumnSizes)[i] = n;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            d[i + 1][j + 1] += d[i][j + 1] + d[i + 1][j] - d[i][j];
//            ans[i][j] = d[i + 1][j + 1];
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2244. 完成所有任务需要的最少轮数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minimumRounds(int* tasks, int tasksSize)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < tasksSize; i++)
//    {
//        HASH_FIND_INT(hash, &tasks[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = tasks[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        if (pEntry->val == 1)
//            return -1;
//
//        ans += (pEntry->val + 2) / 3;
//        free(pEntry);
//    }
//    return ans;
//}
//
////2870. 使数组为空的最少操作次数
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minOperations(int* nums, int numsSize)
//{
//    HashItem* hash = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < numsSize; i++)
//    {
//        HASH_FIND_INT(hash, &nums[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = nums[i];
//            pEntry->val = 1;
//            HASH_ADD_INT(hash, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    int ans = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, hash, pEntry, tmp)
//    {
//        if (pEntry->val == 1)
//            return -1;
//
//        ans += (pEntry->val + 2) / 3;
//        free(pEntry);
//    }
//    return ans;
//}
//
