//// 1563. й╞вссно╥ V
//
//int stoneGameV(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int s[n + 1];
//    s[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        s[i + 1] = s[i] + stoneValue[i];
//    }
//    int memo[n + 1][n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            memo[i][j] = -1;
//        }
//    }
//    int dfs(int i, int j)
//    {
//        if (j - i == 0) return 0;
//        if (memo[i][j] != -1) return memo[i][j];
//        int res = 0;
//        for (int k = i + 1; k < j; k++)
//        {
//            int sum_l = s[k] - s[i];
//            int sum_r = s[j] - s[k];
//            int score = 0;
//            if (sum_l < sum_r)
//                score = dfs(i, k) + sum_l;
//            else if (sum_l > sum_r)
//                score = dfs(k, j) + sum_r;
//            else
//                score = fmax(dfs(i, k) + sum_l, dfs(k, j) + sum_r);
//
//            res = fmax(score, res);
//        }
//        memo[i][j] = res;
//        return res;
//    }
//    return dfs(0, n);
//}
//
//int stoneGameV(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int s[n + 1];
//    s[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        s[i + 1] = s[i] + stoneValue[i];
//    }
//    int f[n][n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 2; i >= 0; i--)
//    {
//        for (int j = i + 1; j <= n; j++)
//        {
//            for (int k = i + 1; k < j; k++)
//            {
//                int sum_l = s[k] - s[i];
//                int sum_r = s[j] - s[k];
//                int score = 0;
//                if (sum_l < sum_r)
//                    score = f[i][k] + sum_l;
//                else if (sum_l > sum_r)
//                    score = f[k][j] + sum_r;
//                else
//                    score = fmax(f[i][k] + sum_l, f[k][j] + sum_r);
//
//                f[i][j] = fmax(score, f[i][j]);
//            }
//        }
//    }
//    return f[0][n];
//}
//
//int stoneGameV(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int s[n + 1];
//    s[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        s[i + 1] = s[i] + stoneValue[i];
//    }
//    int f[n][n + 1];
//    memset(f, 0, sizeof(f));
//    int suf_max[n + 1][n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            suf_max[i][j] = INT_MIN;
//        }
//    }
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf_max[i][i + 1] = -s[i];
//        int pre_max = 0;
//        int k = i + 1;
//        for (int j = i + 2; j <= n; j++)
//        {
//            while (s[k] - s[i] <= s[j] - s[k])
//            {
//                pre_max = fmax(pre_max, f[i][k] + s[k]);
//                k++;
//            }
//            int q = s[k - 1] - s[i] == s[j] - s[k - 1] ? k - 1 : k;
//            f[i][j] = fmax(pre_max - s[i], suf_max[q][j] + s[j]);
//            suf_max[i][j] = fmax(suf_max[i + 1][j], f[i][j] - s[i]);
//        }
//    }
//    return f[0][n];
//}
//
//int stoneGameV(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int s[n + 1];
//    s[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        s[i + 1] = s[i] + stoneValue[i];
//    }
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    int suf_max[n + 1][n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            suf_max[i][j] = INT_MIN;
//        }
//    }
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf_max[i][i + 1] = -s[i];
//        int pre_max = 0;
//        int k = i + 1;
//        for (int j = i + 2; j <= n; j++)
//        {
//            while (s[k] - s[i] <= s[j] - s[k])
//            {
//                pre_max = fmax(pre_max, f[k] + s[k]);
//                k++;
//            }
//            int q = s[k - 1] - s[i] == s[j] - s[k - 1] ? k - 1 : k;
//            f[j] = fmax(pre_max - s[i], suf_max[q][j] + s[j]);
//            suf_max[i][j] = fmax(suf_max[i + 1][j], f[j] - s[i]);
//        }
//    }
//    return f[n];
//}
//
