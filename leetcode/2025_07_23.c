////1717. 删除子字符串的最大得分
//
//int maximumGain(char* s, int x, int y)
//{
//    char c_a = 'a', c_ b = 'b';
//    if (x < y)
//    {
//        c_a = 'b'; c_ b = 'a';
//        int tmp = x;
//        x = y;
//        y = tmp;
//    }
//
//    int ans = 0, n = strlen(s);
//    for (int i = 0; i < n;)
//    {
//        while (i < n && s[i] > 'b') i++;
//
//        int cnt_a = 0, cnt_b = 0;
//        while (i < n && s[i] <= 'b')
//        {
//            if (s[i] == c_a)
//                cnt_a++;
//            else
//            {
//                if (cnt_a > 0)
//                {
//                    cnt_a--;
//                    ans += x;
//                }
//                else
//                    cnt_b++;
//            }
//            i++;
//        }
//        ans += fmin(cnt_a, cnt_b) * y;
//    }
//    return ans;
//}
//
////152. 乘积最大子数组
//
//int maxProduct(int* nums, int numsSize)
//{
//    int max = INT_MIN, multi = 1, left = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        multi *= nums[i];
//        if (multi >= 0)
//        {
//            max = fmax(multi, max);
//            if (multi == 0)
//            {
//                left = i + 1;
//                multi = 1;
//            }
//        }
//        else
//        {
//            int t = multi, l = left;
//            while (l < i && t < 0)
//            {
//                t /= nums[l];
//                l++;
//            }
//            if (t >= max)
//                max = t;
//        }
//    }
//    return max;
//}
//
////64. 最小路径和
//
//int minPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int f[row][col];
//    memset(f, 0, sizeof(f));
//    f[0][0] = grid[0][0];
//    for (int i = 1; i < row; i++)
//    {
//        f[i][0] = f[i - 1][0] + grid[i][0];
//    }
//    for (int i = 1; i < col; i++)
//    {
//        f[0][i] = f[0][i - 1] + grid[0][i];
//    }
//    int ans = 0;
//    for (int i = 1; i < row; i++)
//    {
//        for (int j = 1; j < col; j++)
//        {
//            f[i][j] = fmin(f[i - 1][j], f[i][j - 1]) + grid[i][j];
//        }
//    }
//    return f[row - 1][col - 1];
//}
//
//int minPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int f[col];
//    memset(f, 0, sizeof(f));
//    f[0] = grid[0][0];
//    for (int i = 1; i < col; i++)
//    {
//        f[i] = f[i - 1] + grid[0][i];
//    }
//    int ans = 0;
//    for (int i = 1; i < row; i++)
//    {
//        f[0] += grid[i][0];
//        for (int j = 1; j < col; j++)
//        {
//            f[j] = fmin(f[j], f[j - 1]) + grid[i][j];
//        }
//    }
//    return f[col - 1];
//}
////.
//
//int dfs(int row, int col, int** grid)
//{
//    if (grid[row][col])
//        return 0;
//
//    if (row + col == 0)
//        return 1;
//
//    if (row + col == row)
//        return dfs(row - 1, col, grid);
//
//    if (row + col == col)
//        return dfs(row, col - 1, grid);
//
//    return dfs(row - 1, col, grid) + dfs(row, col - 1, grid);
//}
//int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize)
//{
//    return dfs(gridSize - 1, gridColSize[0] - 1, grid);
//}
//
//int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int f[row + 1][col + 1];
//    memset(f, 0, sizeof(f));
//    f[0][1] = 1;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] == 0)
//                f[i + 1][j + 1] = f[i][j + 1] + f[i + 1][j];
//        }
//    }
//    return f[row][col];
//}
//
//int uniquePathsWithObstacles(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int f[col + 1];
//    memset(f, 0, sizeof(f));
//    f[1] = 1;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            f[j + 1] = grid[i][j] ? 0 : f[j + 1] + f[j];
//        }
//    }
//    return f[col];
//}
//
