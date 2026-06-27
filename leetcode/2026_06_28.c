//// 764. 最大加号标志
//
//int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize)
//{
//    int grid[n + 2][n + 2];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            grid[i][j] = 1;
//        }
//    }
//    for (int i = 0; i < minesSize; i++)
//    {
//        int x = mines[i][0] + 1;
//        int y = mines[i][1] + 1;
//        grid[x][y] = 0;
//    }
//    int up[n + 2][n + 2];
//    memset(up, 0, sizeof(grid));
//    int down[n + 2][n + 2];
//    memset(down, 0, sizeof(grid));
//    int left[n + 2][n + 2];
//    memset(left, 0, sizeof(grid));
//    int right[n + 2][n + 2];
//    memset(right, 0, sizeof(grid));
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (grid[i][j])
//            {
//                right[i][j] = right[i][j - 1] + 1;
//                down[i][j] = down[i - 1][j] + 1;
//            }
//            if (grid[n + 1 - i][n + 1 - j])
//            {
//                left[n + 1 - i][n + 1 - j] = left[n + 1 - i][n + 2 - j] + 1;
//                up[n + 1 - i][n + 1 - j] = up[n + 2 - i][n + 1 - j] + 1;
//            }
//        }
//    }
//
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            int x1 = left[i][j], x2 = right[i][j];
//            int y1 = up[i][j], y2 = down[i][j];
//            int x = fmin(x1, x2);
//            int y = fmin(y1, y2);
//            int d = fmin(x, y);
//            ans = fmax(ans, d);
//        }
//    }
//    return ans;
//}
//
