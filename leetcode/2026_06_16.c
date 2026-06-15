//// 650. Á½¸ö¼üµÄ¼üÅÌ
//
//int minSteps(int n)
//{
//    // letters on notebook / paste board
//    int f[n + 1][n + 1];
//    memset(f, 0x3f, sizeof(f));
//    f[1][0] = 0, f[1][1] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        int min = INT_MAX;
//        // Paste
//        for (int j = 0; j <= i / 2; j++)
//        {
//            f[i][j] = f[i - j][j] + 1;
//            min = fmin(min, f[i][j]);
//        }
//        // Copy All
//        f[i][i] = min + 1;
//    }
//
//    int ans = INT_MAX;
//    // differnt paste board num
//    for (int i = 0; i <= n; i++)
//    {
//        ans = fmin(ans, f[n][i]);
//    }
//    return ans;
//}
//
//int minSteps(int n)
//{
//    int ans = 0;
//    for (int i = 2; i * i <= n; i++)
//    {
//        while (n % i == 0)
//        {
//            ans += i;
//            n /= i;
//        }
//    }
//
//    if (n != 1)
//        ans += n;
//
//    return ans;
//}
//
