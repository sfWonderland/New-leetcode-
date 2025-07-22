////120. 三角形最小路径和
//
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
//{
//    int f[triangleSize + 1][triangleSize + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = triangleSize - 1; i >= 0; i--)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            f[i][j] = fmin(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
//        }
//    }
//    return f[0][0];
//}
//
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
//{
//    int f[triangleSize + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = triangleSize - 1; i >= 0; i--)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            f[j] = fmin(f[j], f[j + 1]) + triangle[i][j];
//        }
//    }
//    return f[0];
//}
//
////3393. 统计异或值为给定值的路径数目
//
//int dfs(int i, int j, int k, int** grid)
//{
//    if (i == 0 && j == 0)
//        return k == grid[i][j];
//    if (i < 0 || j < 0)
//        return 0;
//
//    k ^= grid[i][j];
//    return dfs(i - 1, j, k, grid) + dfs(i, j - 1, k, grid);
//}
//int countPathsWithXorValue(int** grid, int gridSize, int* gridColSize, int k)
//{
//    int row = gridSize, col = gridColSize[0];
//    return dfs(row - 1, col - 1, k, grid);
//}
//
//int countPathsWithXorValue(int** grid, int gridSize, int* gridColSize, int k)
//{
//    int row = gridSize, col = gridColSize[0];
//    long long f[row + 1][col + 1][16];
//    memset(f, 0, sizeof(f));
//    f[0][1][0] = 1;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            int val = grid[i][j];
//            for (int x = 0; x < 16; x++)
//                f[i + 1][j + 1][x] = (f[i][j + 1][x ^ val] + f[i + 1][j][x ^ val]) % 1000000007;
//        }
//    }
//    return f[row][col][k];
//}
//
////931. 下降路径最小和
//
//int dfs(int i, int j, int** grid, int** cache)
//{
//    if (i == 0)
//        return grid[i][j];
//
//    if (j < 0 || j > n)
//        return 10000;
//
//    if (cache)
//        return fmin(dfs(i - 1, j - 1, grid))
//}
//int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int n = matrixSize;
//    int** cache = (int**)malloc(sizeof(int*) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        memset(cache[i], 0, sizeof(cache[i]));
//    }
//    int ret = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        ret = fmin(ret, dfs(n - 1, i, matrix, cache));
//    }
//    return ret;
//}
//
//int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int n = matrixSize;
//    int f[n + 2];
//    memset(f, 0, sizeof(f));
//
//    f[0] = 10001;
//    f[n + 1] = 10001;
//
//    for (int i = 0; i < n; i++)
//    {
//        int pre = f[0];
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = fmin(fmin(pre, f[j + 1]), f[j + 2]) + matrix[i][j];
//            pre = tmp;
//        }
//    }
//    int ret = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        ret = fmin(ret, f[i + 1]);
//    }
//    return ret;
//}
//
////3603. 交替方向的最小路径代价 II
//
//long long dfs(int i, int j, int** grid)
//{
//    if (i < 0 || j < 0)
//        return LLONG_MAX;
//    if (i == 0 && j == 0)
//        return 1;
//
//    return fmin(dfs(i - 1, j, grid), dfs(i, j - 1, grid)) + grid[i][j] + 1ll * (i + 1) * (j + 1);
//}
//long long minCost(int m, int n, int** waitCost, int waitCostSize, int* waitCostColSize)
//{
//    return dfs(m - 1, n - 1, waitCost) - waitCost[m - 1][n - 1];
//}
//
//long long minCost(int m, int n, int** waitCost, int waitCostSize, int* waitCostColSize)
//{
//    long long f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//            f[i][j] = LLONG_MAX;
//    }
//    f[0][1] = -waitCost[0][0];
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = fmin(f[i][j + 1], f[i + 1][j]) + 1ll * (i + 1) * (j + 1) + waitCost[i][j];
//        }
//    }
//    return f[m][n] - waitCost[m - 1][n - 1];
//}
//
//long long minCost(int m, int n, int** waitCost, int waitCostSize, int* waitCostColSize)
//{
//    long long f[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        f[i] = LLONG_MAX;
//    }
//    f[1] = -waitCost[0][0];
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[j + 1] = fmin(f[j + 1], f[j]) + 1ll * (i + 1) * (j + 1) + waitCost[i][j];
//        }
//    }
//    return f[n] - waitCost[m - 1][n - 1];
//}
//
