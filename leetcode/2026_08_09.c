//// 1140. й╞вссно╥ II
//
//int stoneGameII(int* piles, int pilesSize)
//{
//    if (pilesSize == 1)
//        return piles[0];
//    int n = pilesSize, sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += piles[i];
//    }
//    int memo[n][n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int m)
//    {
//        if (i == n) return 0;
//        if (memo[i][m] != 0x3f3f3f3f)
//            return memo[i][m];
//        int diff = INT_MIN, sum = 0;
//        int limit = fmin(2 * m, n - i);
//        for (int x = 1; x <= limit; x++)
//        {
//            // printf("%d %d %d %d\n", i, x, i + x - 1, n);
//            sum += piles[i + x - 1];
//            diff = fmax(sum - dfs(i + x, fmax(m, x)), diff);
//        }
//        memo[i][m] = diff;
//        return diff;
//    }
//    int diff = dfs(0, 1);
//    // printf("%d %d\n", sum, diff);
//    return (sum + diff) / 2;
//}
//
//int stoneGameII(int* piles, int pilesSize)
//{
//    if (pilesSize == 1)
//        return piles[0];
//    int n = pilesSize, suffix[n + 1];
//    suffix[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suffix[i] = suffix[i + 1] + piles[i];
//    }
//    int memo[n][n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i, int m)
//    {
//        if (i + m * 2 >= n) return suffix[i];
//        if (memo[i][m] != 0x3f3f3f3f)
//            return memo[i][m];
//        int mn = INT_MAX;
//        for (int x = 1; x <= 2 * m; x++)
//        {
//            // printf("%d %d %d %d\n", i, x, i + x - 1, n);
//            mn = fmin(dfs(i + x, fmax(m, x)), mn);
//        }
//        memo[i][m] = suffix[i] - mn;
//        return suffix[i] - mn;
//    }
//    // printf("%d %d\n", sum, diff);
//    return dfs(0, 1);
//}
//
//int stoneGameII(int* piles, int pilesSize)
//{
//    if (pilesSize == 1)
//        return piles[0];
//    int n = pilesSize, sum = 0;
//    int f[n + 1][n];
//    memset(f[n], 0, sizeof(f[n]));
//    for (int i = n - 1; i >= 0; i--)
//    {
//        sum += piles[i];
//        for (int m = 1; m < i / 2 + 2; m++)
//        {
//            if (i + m * 2 >= n)
//                f[i][m] = sum;
//            else
//            {
//                int mn = INT_MAX;
//                for (int x = 1; x <= m * 2; x++)
//                {
//                    int d = fmax(m, x);
//                    mn = fmin(mn, f[i + x][d]);
//                }
//                f[i][m] = sum - mn;
//            }
//        }
//    }
//
//    return f[0][1];
//}
//
