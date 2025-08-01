////516. 最长回文子序列
//
//int longestPalindromeSubseq(char* s)
//{
//    int n = strlen(s);
//    int f[n][n];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 1; i >= 0; i--)
//    {
//        f[i][i] = 1;
//        for (int j = i + 1; j < n; j++)
//        {
//            if (s[i] == s[j])
//                f[i][j] = f[i + 1][j - 1] + 2;
//            else
//                f[i][j] = fmax(f[i + 1][j], f[i][j - 1]);
//        }
//    }
//    return f[0][n - 1];
//}
//
//int longestPalindromeSubseq(char* s)
//{
//    int n = strlen(s);
//    int f[n];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 1; i >= 0; i--)
//    {
//        f[i] = 1;
//        int pre = 0; //f[i + 1][i];
//        for (int j = i + 1; j < n; j++)
//        {
//            int tmp = f[j];
//            if (s[i] == s[j])
//                f[j] = pre + 2;
//            else
//                f[j] = fmax(f[j], f[j - 1]);
//            pre = tmp;
//        }
//    }
//    return f[n - 1];
//}
//
////1039. 多边形三角剖分的最低得分
//
//int minScoreTriangulation(int* values, int valuesSize)
//{
//    int n = valuesSize;
//    int f[n][n];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 3; i >= 0; i--)
//    {
//        for (int j = i + 2; j < n; j++)
//        {
//            int res = INT_MAX;
//            for (int k = i + 1; k < j; k++)
//            {
//                res = fmin(res, f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
//            }
//            f[i][j] = res;
//        }
//    }
//    return f[0][n - 1];
//}
//
////375. 猜数字大小 II
//
//int getMoneyAmount(int n)
//{
//    int f[n + 1][n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 1; i > 0; i--)
//    {
//        f[i][i + 1] = i;
//        for (int j = i + 2; j <= n; j++)
//        {
//            int res = j + f[i][j - 1];
//            for (int k = i; k < j; k++)
//            {
//                res = fmin(res, fmax(f[i][k - 1], f[k + 1][j]) + k);
//            }
//            f[i][j] = res;
//        }
//    }
//    return f[1][n];
//}
//
////1312. 让字符串成为回文串的最少插入次数
//
//int minInsertions(char* s)
//{
//    int n = strlen(s);
//    int f[n][n];
//    memset(f, 0, sizeof(f));
//    for (int i = n - 1; i >= 0; i--)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (s[i] == s[j])
//                f[i][j] = f[i + 1][j - 1];
//            else
//                f[i][j] = fmin(f[i + 1][j], f[i][j - 1]) + 1;
//        }
//    }
//    return f[0][n - 1];
//}
//
