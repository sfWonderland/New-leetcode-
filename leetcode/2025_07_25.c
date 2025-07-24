////1289. 下降路径最小和 II
//
//int dfs(int i, int j, int n, int** grid, int** cache)
//{
//    if (i == 0)
//        return grid[i][j];
//    if (cache[i][j] != INT_MAX)
//        return cache[i][j];
//
//    int min = INT_MAX;
//    for (int k = 0; k < n; k++)
//    {
//        if (k == j)
//            continue;
//        if (cache[i - 1][k] == INT_MAX)
//        {
//            cache[i - 1][k] = dfs(i - 1, k, n, grid, cache);
//        }
//        min = fmin(cache[i - 1][k], min);
//    }
//    cache[i][j] = min + grid[i][j];
//    return cache[i][j];
//}
//int minFallingPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridSize;
//    int ret = 20000;
//    int** cache = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * n);
//        for (int j = 0; j < n; j++)
//        {
//            cache[i][j] = INT_MAX;
//        }
//    }
//    for (int i = 0; i < n; i++)
//        ret = fmin(ret, dfs(n - 1, i, n, grid, cache));
//    return ret;
//}
//
//int minFallingPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridSize;
//    int ret = 20000;
//    for (int i = 0; i < n; i++)
//    {
//        f[0][i] = grid[0][i];
//    }
//    for (int i = 1; i < n; i++)
//    {
//        t j = 0; j < n; j++)
//        {
//            int min = INT_MAX;
//            for (int k = 0; k < n; k++)
//            {
//                if (k == j)
//                    continue;
//                min = fmin(min, f[i - 1][k]);
//            }
//            f[i][j] = min + grid[i][j];
//        }
//    }
//    for (int i = 0; i < n; i++)
//        ret = fmin(ret, f[n - 1][i]);
//    return ret;
//}
//
//int minFallingPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridSize;
//    for (int i = n - 2; i >= 0; i--)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int min = INT_MAX;
//            for (int k = 0; k < n; k++)
//            {
//                if (k != j)
//                    min = fmin(grid[i + 1][k], min);
//            }
//            grid[i][j] += min;
//        }
//    }
//    int ret = 20000;
//    for (int i = 0; i < n; i++)
//        ret = fmin(ret, grid[0][i]);
//    return ret;
//}
//
////2304. 网格中的最小路径代价
//
//int dfs(int i, int j, int row, int col, int** grid, int** moveCost, int** cache)
//{
//    int x = grid[i][j];
//    if (i == row - 1)
//        return x;
//    if (cache[i][j] != -1)
//        return cache[i][j];
//    int min = INT_MAX;
//    for (int k = 0; k < col; k++)
//    {
//        if (cache[i + 1][k] == -1)
//            cache[i + 1][k] = dfs(i + 1, k, row, col, grid, moveCost, cache);
//        min = fmin(min, cache[i + 1][k] + x + moveCost[x][k]);
//    }
//    cache[i][j] = min;
//    return cache[i][j];
//}
//int minPathCost(int** grid, int gridSize, int* gridColSize, int** moveCost, int moveCostSize, int* moveCostColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int** cache = (int**)malloc(sizeof(int*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * col);
//        for (int j = 0; j < col; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    int ret = INT_MAX;
//    for (int i = 0; i < col; i++)
//    {
//        int x = dfs(0, i, row, col, grid, moveCost, cache);
//        ret = fmin(ret, x);
//    }
//    return ret;
//}
//
//int minPathCost(int** grid, int gridSize, int* gridColSize, int** moveCost, int moveCostSize, int* moveCostColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int f[row][col];
//    for (int i = row - 2; i >= 0; i--)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            int min = INT_MAX, x = grid[i][j];
//            for (int k = 0; k < col; k++)
//            {
//                min = fmin(grid[i + 1][k] + moveCost[x][k], min);
//            }
//            grid[i][j] += min;
//        }
//    }
//    int ret = INT_MAX;
//    for (int i = 0; i < col; i++)
//    {
//        ret = fmin(ret, grid[0][i]);
//    }
//    return ret;
//}
//
////2684. 矩阵中移动的最大次数
//
//int row, col, ans;
//int** grids;
//void dfs(int i, int j)
//{
//    ans = fmax(ans, j);
//    if (ans == col - 1)
//        return;
//    for (int k = fmax(0, i - 1); k < fmin(i + 2, row); k++)
//    {
//        if (grids[k][j + 1] > grids[i][j])
//        {
//            dfs(k, j + 1);
//        }
//    }
//    grids[i][j] = 0;
//}
//int maxMoves(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize, col = gridColSize[0];
//    grids = grid;
//    ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        dfs(i, 0);
//    }
//    return ans;
//}
//
////3487. 删除后的最大子数组元素和
//
//int maxSum(int* nums, int numsSize)
//{
//    bool exist[201] = { false };
//    int sum = 0, max = -101;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        max = fmax(max, x);
//        if (x < 0 || exist[x + 100])
//            continue;
//
//        sum += x;
//        exist[x + 100] = true;
//    }
//    return max <= 0 ? max : sum;
//}
//
