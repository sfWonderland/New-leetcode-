////3779. 得到互不相同元素的最少操作次数
//
//int minOperations(int* nums, int numsSize)
//{
//    bool cnt[100001] = { 0 };
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (cnt[nums[i]])
//            return i / 3 + 1;
//        else
//            cnt[nums[i]] = true;
//    }
//    return 0;
//}
//
//// LCP 02. 分式化简   
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//int* fraction(int* cont, int contSize, int* returnSize)
//{
//    int x = 1, y = 0;
//    for (int i = contSize - 1; i >= 0; i--)
//    {
//        y += cont[i] * x;
//        swap(&x, &y);
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = x, ans[1] = y;
//    *returnSize = 2;
//    return ans;
//}
//
//
//// LCP 07. 传递信息
//
//int numWays(int n, int** relation, int relationSize, int* relationColSize, int k)
//{
//    int grid[n][n];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < relationSize; i++)
//    {
//        int x = relation[i][0], y = relation[i][1];
//        grid[x][len[x]++] = y;
//    }
//
//    int dfs(int i, int t)
//    {
//        if (t == k)
//            return i == n - 1;
//
//        int res = 0;
//        for (int j = 0; j < len[i]; j++)
//        {
//            res += dfs(grid[i][j], t + 1);
//        }
//        return res;
//    }
//    return dfs(0, 0);
//}
//
//int numWays(int n, int** relation, int relationSize, int* relationColSize, int k)
//{
//    int f[k + 1][n];
//    memset(f, 0, sizeof(f));
//    f[0][0] = 1;
//    for (int i = 1; i <= k; i++)
//    {
//        for (int j = 0; j < relationSize; j++)
//        {
//            int x = relation[j][0], y = relation[j][1];
//            f[i][y] += f[i - 1][x];
//        }
//    }
//    return f[k][n - 1];
//}
//
////LCP 33. 蓄水
//
//int storeWater(int* bucket, int bucketSize, int* vat, int vatSize)
//{
//    int maxK = 0;
//    for (int i = 0; i < vatSize; i++)
//    {
//        maxK = fmax(maxK, vat[i]);
//    }
//    if (maxK == 0)
//        return 0;
//
//    int res = INT_MAX;
//    // 蓄水次数
//    for (int k = 1; k <= maxK && k < res; k++)
//    {
//        int t = 0;
//        for (int i = 0; i < bucketSize; i++)
//        {
//            // 升级次数
//            t += fmax(0, (vat[i] + k - 1) / k - bucket[i]);
//        }
//        res = fmin(res, t + k);
//    }
//    return res;
//}
//
