////3750. 最少反转次数得到翻转二进制字符串
//
//////190. 颠倒二进制位
//uint32_t reverseBits(uint32_t n)
//{
//    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
//    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
//    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
//    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
//    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
//
//    return n;
//}
//int minimumFlips(int n)
//{
//    int rev = reverseBits(n) >> __builtin_clz(n);
//    return __builtin_popcount(n ^ rev);
//}
//
////3663. 出现频率最低的数字
//
//int getLeastFrequentDigit(int n)
//{
//    int cnt[10] = { 0 };
//    while (n)
//    {
//        cnt[n % 10]++;
//        n /= 10;
//    }
//    int ans = 10, min = 10;
//    for (int i = 0; i < 10; i++)
//    {
//        if (!cnt[i])
//            continue;
//
//        if (cnt[i] < min)
//        {
//            ans = i;
//            min = cnt[i];
//        }
//        else if (min == cnt[i])
//            ans = fmin(ans, i);
//    }
//    return ans;
//}
//
////3664. 两个字母卡牌游戏
//
//void cal(int* cnt, int n, int x, int* pairs, int* left)
//{
//    int sum = 0, mx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i != x)
//        {
//            sum += cnt[i];
//            mx = fmax(mx, cnt[i]);
//        }
//    }
//    *pairs = fmin(sum / 2, sum - mx);
//    *left = sum - (*pairs) * 2;
//}
//int score(char** cards, int cardsSize, char x)
//{
//    int cnt1[10] = { 0 };
//    int cnt2[10] = { 0 };
//    for (int i = 0; i < cardsSize; i++)
//    {
//        if (cards[i][0] == x)
//            cnt1[cards[i][1] - 'a']++;
//        if (cards[i][1] == x)
//            cnt2[cards[i][0] - 'a']++;
//    }
//    // for(int i = 0; i < 10; i++)
//    // {
//    //     printf("%d ", cnt1[i]);
//    // }
//    // printf("\n");
//    // for(int i = 0; i < 10; i++)
//    // {
//    //     printf("%d ", cnt2[i]);
//    // }
//    // printf("\n");
//    int pairs1 = 0, left1 = 0;
//    int pairs2 = 0, left2 = 0;
//    cal(cnt1, 10, x - 'a', &pairs1, &left1);
//    cal(cnt2, 10, x - 'a', &pairs2, &left2);
//
//    //printf("%d %d %d %d\n", pairs1, left1, pairs2, left2);
//    int ans = pairs1 + pairs2;
//    int cnt_xx = cnt1[x - 'a'];
//    if (cnt_xx > 0)
//    {
//        int mn = fmin(cnt_xx, left1 + left2);
//        ans += mn;
//        cnt_xx -= mn;
//    }
//
//    if (cnt_xx > 0)
//        ans += fmin(cnt_xx / 2, pairs1 + pairs2);
//
//    return ans;
//}
//
////3665. 统计镜子反射路径数目
//
//const int mod = 1e9 + 7;
//int uniquePaths(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int dfs(int i, int j, int dir) // dir = 1 up dir = 0 right
//    {
//        if (i < 0 || j < 0)
//            return 0;
//
//        if (i == 0 && j == 0)
//            return 1;
//
//        if (grid[i][j] == 1)
//        {
//            if (dir)
//                return dfs(i, j - 1, 0);
//            else
//                return dfs(i - 1, j, 1);
//        }
//
//        return dfs(i, j - 1, 0) + dfs(i - 1, j, 1);
//    }
//    int f[m + 1][n + 1][2];
//    memset(f, 0, sizeof(f));
//    f[0][1][0] = f[0][1][1] = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j])
//            {
//                f[i + 1][j + 1][0] = f[i][j + 1][1];
//                f[i + 1][j + 1][1] = f[i + 1][j][0];
//            }
//            else
//            {
//                f[i + 1][j + 1][0] = (f[i + 1][j][0] + f[i][j + 1][1]) % mod;
//                f[i + 1][j + 1][1] = (f[i + 1][j][0] + f[i][j + 1][1]) % mod;
//            }
//        }
//    }
//    return f[m][n][0];
//}
//
//// int dfs(int** grid, int i, int j, int dir) // dir = 1 up dir = 0 right
//// {
////     if(i < 0 || j < 0)
////     return 0;
//
////     if(i == 0 && j == 0)
////     return 1;
//
////     if(grid[i][j] == 1)
////     {
////         if(dir)
////         return dfs(i, j - 1, 0);
////         else
////         return dfs(i - 1, j, 1);
////     }
//
////     return dfs(i, j - 1, 0) + dfs(i - 1, j, 1);
//// }
//const int mod = 1e9 + 7;
//int uniquePaths(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int f[n + 1][2];
//    memset(f, 0, sizeof(f));
//    f[1][0] = f[1][1] = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j])
//            {
//                f[j + 1][0] = f[j + 1][1];
//                f[j + 1][1] = f[j][0];
//            }
//            else
//            {
//                f[j + 1][0] = (f[j][0] + f[j + 1][1]) % mod;
//                f[j + 1][1] = (f[j][0] + f[j + 1][1]) % mod;
//            }
//        }
//    }
//    return f[n][0];
//}
//
