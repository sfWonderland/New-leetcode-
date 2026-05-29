//// 2017. Õ¯∏Ò”Œœ∑
//
//long long gridGame(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridColSize[0];
//    long long pre[2][n + 1], suf[2][n + 1];
//    pre[0][0] = pre[1][0] = suf[0][n] = suf[1][n] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[0][i + 1] = pre[0][i] + grid[0][i];
//        pre[1][i + 1] = pre[1][i] + grid[1][i];
//        suf[0][n - 1 - i] = suf[0][n - i] + grid[0][n - 1 - i];
//        suf[1][n - 1 - i] = suf[1][n - i] + grid[1][n - 1 - i];
//        // printf("%lld %lld %lld %lld\n", pre[0][i + 1], pre[1][i + 1], suf[0][n - 1 - i], suf[1][n - 1 - i]);
//    }
//    long long ans = LLONG_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        ans = fmin(ans, fmax(suf[0][i + 1], pre[1][i]));
//        // printf("%lld %lld %lld\n", suf[0][i + 1], pre[1][i], ans);
//    }
//    return ans;
//}
//
//long long gridGame(int** grid, int gridSize, int* gridColSize)
//{
//    int n = gridColSize[0];
//    long long suf1 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        suf1 += grid[0][i];
//    }
//    long long ans = LLONG_MAX;
//    long long pre2 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        suf1 -= grid[0][i];
//        long long max = pre2 > suf1 ? pre2 : suf1;
//        if (ans > max)
//            ans = max;
//        pre2 += grid[1][i];
//    }
//    return ans;
//}
//
