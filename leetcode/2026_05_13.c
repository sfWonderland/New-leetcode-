//// 面试题 08.01. 三步问题
//
//#define MOD 1000000007
//int waysToStep(int n)
//{
//    if (n == 1) return 1;
//    if (n == 2) return 2;
//    if (n == 3) return 4;
//    int f1 = 1, f2 = 2, f3 = 4, f4 = 7;
//    for (int i = 5; i <= n; i++)
//    {
//        f1 = f2;
//        f2 = f3;
//        f3 = f4;
//        f4 = ((f1 + f2) % MOD + f3) % MOD;
//    }
//    return f4;
//}
//
//// 面试题 08.02. 迷路的机器人    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** pathWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    int m = obstacleGridSize, n = obstacleGridColSize[0];
//    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
//        return NULL;
//    bool f[m][n];
//    memset(f, 0, sizeof(f));
//    f[0][0] = 1;
//    for (int i = 1; i < m; i++)
//    {
//        if (!obstacleGrid[i][0] && f[i - 1][0])
//            f[i][0] = 1;
//    }
//    for (int i = 1; i < n; i++)
//    {
//        if (!obstacleGrid[0][i] && f[0][i - 1])
//            f[0][i] = 1;
//    }
//    for (int i = 1; i < m; i++)
//    {
//        for (int j = 1; j < n; j++)
//        {
//            if (!obstacleGrid[i][j])
//            {
//                f[i][j] = f[i - 1][j] | f[i][j - 1];
//            }
//        }
//    }
//    if (!f[m - 1][n - 1])
//        return false;
//    int** ans = (int**)malloc(sizeof(int*) * (m + n - 1));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (m + n - 1));
//    for (int i = 0; i < m + n - 1; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * 2);
//        (*returnColumnSizes)[i] = 2;
//    }
//    void dfs(int i, int j)
//    {
//        ans[i + j][0] = i;
//        ans[i + j][1] = j;
//        if (i == 0 && j == 0)
//            return;
//
//        if (i > 0 && f[i - 1][j])
//            dfs(i - 1, j);
//        else
//            dfs(i, j - 1);
//    }
//    dfs(m - 1, n - 1);
//    *returnSize = m + n - 1;
//    return ans;
//}
//
//// 面试题 08.03. 魔术索引
//
//int findMagicIndex(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i == nums[i])
//            return i;
//    }
//    return -1;
//}
//
//// 面试题 08.05. 递归乘法
//
//int multiply(int A, int B)
//{
//    if (A == 0 || B == 0)
//        return 0;
//    if (A > B)
//    {
//        int tmp = A;
//        A = B;
//        B = tmp;
//    }
//    int half = multiply(A, B / 2);
//    return B & 1 ? A + half + half : half + half;
//}
//
