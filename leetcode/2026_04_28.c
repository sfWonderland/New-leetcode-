//// LCR 095. 最长公共子序列
//
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int memo[m][n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int j)
//    {
//        if (i < 0 || j < 0)
//            return 0;
//
//        if (memo[i][j] != 0x3f3f3f3f)
//            return memo[i][j];
//
//        if (text1[i] == text2[j])
//            memo[i][j] = 1 + dfs(i - 1, j - 1);
//        else
//            memo[i][j] = fmax(dfs(i - 1, j), dfs(i, j - 1));
//
//        return memo[i][j];
//    }
//    return dfs(m - 1, n - 1);
//}
//
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        f[i][0] = 0;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        f[0][i] = 0;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = text1[i] == text2[j] ? 1 + f[i][j] : fmax(f[i][j + 1], f[i + 1][j]);
//        }
//    }
//    return f[m][n];
//}
//
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < m; i++)
//    {
//        int pre = 0;
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = text1[i] == text2[j] ? 1 + pre : fmax(f[j + 1], f[j]);
//            pre = tmp;
//        }
//    }
//    return f[n];
//}
//
//// LCR 096. 交错字符串   
//
//bool isInterleave(char* s1, char* s2, char* s3)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//    int len = strlen(s3);
//    if (len != m + n)
//        return false;
//    int memo[m + 1][n + 1];
//    memset(memo, 0x3f, sizeof(memo));
//    bool dfs(int i, int j)
//    {
//        if (i < 0 && j < 0)
//            return true;
//
//        if (memo[i + 1][j + 1] != 0x3f3f3f3f)
//            return memo[i + 1][j + 1];
//
//        bool res = false;
//        if (i >= 0 && s1[i] == s3[i + j + 1])
//            res |= dfs(i - 1, j);
//
//        if (j >= 0 && s2[j] == s3[i + j + 1])
//            res |= dfs(i, j - 1);
//
//        memo[i + 1][j + 1] = res;
//        return res;
//    }
//    return dfs(m - 1, n - 1);
//}
//
//bool isInterleave(char* s1, char* s2, char* s3)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//    int len = strlen(s3);
//    if (len != m + n)
//        return false;
//    bool f[m + 1][n + 1];
//    memset(f, 0, sizeof(f));
//    f[0][0] = true;
//    for (int i = 0; i <= m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            int p = i + j - 1;
//            if (i > 0)
//                f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
//            if (j > 0)
//                f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
//        }
//    }
//
//    return f[m][n];
//}
//
//// LCR 099. 最小路径和
//
//int minPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int memo[m][n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int j)
//    {
//        if (i == 0 && j == 0)
//            return grid[i][j];
//
//        if (i < 0 || j < 0)
//            return INT_MAX / 2;
//
//        if (memo[i][j] != 0x3f3f3f3f)
//            return memo[i][j];
//        memo[i][j] = fmin(dfs(i - 1, j), dfs(i, j - 1)) + grid[i][j];
//        return memo[i][j];
//    }
//    return dfs(m - 1, n - 1);
//}
//
//int minPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        f[i][0] = INT_MAX / 2;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        f[0][i] = INT_MAX / 2;
//    }
//    f[0][1] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = fmin(f[i][j + 1], f[i + 1][j]) + grid[i][j];
//        }
//    }
//    return f[m][n];
//}
//
//int minPathSum(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int f[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        f[i] = INT_MAX / 2;
//    }
//    f[0] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[j + 1] = fmin(f[j + 1], f[j]) + grid[i][j];
//        }
//        f[0] = INT_MAX / 2;
//    }
//    return f[n];
//}
//
//// LCR 100. 三角形最小路径和
//
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
//{
//    int n = triangleSize;
//    int memo[n][n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int j)
//    {
//        if (i == n - 1)
//            return triangle[i][j];
//
//        if (memo[i][j] != 0x3f3f3f3f)
//            return memo[i][j];
//
//        memo[i][j] = fmin(dfs(i + 1, j), dfs(i + 1, j + 1)) + triangle[i][j];
//        return memo[i][j];
//    }
//    return dfs(0, 0);
//}
//
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
//{
//    int n = triangleSize;
//    int f[n][n];
//    for (int i = 0; i < n; i++)
//    {
//        f[n - 1][i] = triangle[n - 1][i];
//    }
//    for (int i = n - 2; i >= 0; i--)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            f[i][j] = fmin(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
//        }
//    }
//    return f[0][0];
//}
//
