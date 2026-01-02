////3352. 统计小于 N 的 K 可约简整数
//
//const int MOD = 1e9 + 7;
//int countKReducibleNumbers(char* s, int k)
//{
//    int n = strlen(s);
//    int** memo = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (int*)malloc(sizeof(int) * n);
//        memset(memo[i], -1, sizeof(int) * n);
//    }
//    int count(int x)
//    {
//        int res = 0;
//        while (x)
//        {
//            x &= (x - 1);
//            res++;
//        }
//        return res;
//    }
//    int dfs(int i, int left1, bool limit)
//    {
//        if (i == n)
//            return !limit && left1 == 0;
//
//        if (!limit && memo[i][left1] != -1)
//            return memo[i][left1];
//
//        int up = limit ? s[i] - '0' : 1;
//        int res = 0;
//        for (int j = 0; j <= fmin(up, left1); j++)
//        {
//            res = (res + dfs(i + 1, left1 - j, limit && j == up) % MOD);
//        }
//        if (!limit)
//            memo[i][left1] = res;
//        return res;
//    }
//    long long ans = 0;
//    int f[n];
//    memset(f, 0, sizeof(int) * n);
//    for (int i = 1; i < n; i++)
//    {
//        f[i] = f[count(i)] + 1;
//        if (f[i] <= k)
//            ans += dfs(0, i, true);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        free(memo[i]);
//    }
//    free(memo);
//    return ans % MOD;
//}
//
////3621. 位计数深度为 K 的整数数目 I    
//
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//long long popcountDepth(long long n, int k)
//{
//    if (k == 0)
//        return 1;
//    char* s = (char*)malloc(sizeof(char) * 52);
//    int m = 0;
//    while (n)
//    {
//        s[m++] = (n & 1);
//        n >>= 1;
//    }
//    if (k == 1)
//        return m - 1;
//    reverse(s, 0, m - 1);
//    s[m] = '\0';
//    long long** memo = (long long**)malloc(sizeof(long long*) * (m + 1));
//    for (int i = 0; i < m; i++)
//    {
//        memo[i] = (long long*)malloc(sizeof(long long) * (m + 1));
//        memset(memo[i], -1, sizeof(long long) * (m + 1));
//    }
//    int count(int x)
//    {
//        int res = 0;
//        while (x)
//        {
//            x &= (x - 1);
//            res++;
//        }
//        return res;
//    }
//    long long dfs(int i, int left1, bool limit)
//    {
//        if (i == m)
//            return left1 == 0;
//
//        if (!limit && memo[i][left1] != -1)
//            return memo[i][left1];
//
//        int up = limit ? s[i] : 1;
//        long long res = 0;
//        for (int j = 0; j <= fmin(up, left1); j++)
//        {
//            res += dfs(i + 1, left1 - j, limit && j == up);
//        }
//        if (!limit)
//            memo[i][left1] = res;
//        return res;
//    }
//    long long ans = 0;
//    int f[m + 1];
//    memset(f, 0, sizeof(int) * (m + 1));
//    for (int i = 1; i <= m; i++)
//    {
//        f[i] = f[count(i)] + 1;
//        if (f[i] == k)
//            ans += dfs(0, i, true);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        free(memo[i]);
//    }
//    free(memo);
//    free(s);
//    return ans;
//}
//
////3490. 统计美丽整数的数目
//
//typedef struct
//{
//    long long key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int beautifulNumbers(int l, int r)
//{
//    char* high = (char*)malloc(sizeof(char) * 11);
//    sprintf(high, "%d", r);
//    int n = strlen(high);
//    char* low = (char*)malloc(sizeof(char) * (n + 1));
//    sprintf(low, "%d", l);
//    int d = n - strlen(low);
//    for (int i = n; i >= d; i--)
//    {
//        low[i] = low[i - d];
//    }
//    for (int i = 0; i < d; i++)
//    {
//        low[i] = '0';
//    }
//    HashItem* memo = NULL;
//    int dfs(int i, int m, int s, bool limit_low, bool limit_high)
//    {
//        if (i == n)
//            return s && m % s == 0;
//
//        long long mask = (1ll * m << 32) | (i << 16) | s;
//        HashItem* pEntry = NULL;
//        if (!limit_low && !limit_high)
//        {
//            HASH_FIND(hh, memo, &mask, sizeof(long long), pEntry);
//            if (pEntry)
//                return pEntry->val;
//        }
//
//        int lo = limit_low ? low[i] - '0' : 0;
//        int hi = limit_high ? high[i] - '0' : 9;
//        int res = 0;
//        if (s == 0 && !lo)
//        {
//            res = dfs(i + 1, 1, 0, true, false);
//        }
//        for (int j = s ? lo : fmax(lo, 1); j <= hi; j++)
//        {
//            res += dfs(i + 1, m * j, s + j, limit_low && j == lo, limit_high && j == hi);
//        }
//        if (!limit_low && !limit_high)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = mask;
//            pEntry->val = res;
//            HASH_ADD(hh, memo, key, sizeof(long long), pEntry);
//        }
//        return res;
//    }
//    return dfs(0, 1, 0, true, true);
//}
//
////926. 将字符串翻转到单调递增
//
//int minFlipsMonoIncr(char* s)
//{
//    int n = strlen(s);
//    int suf[n + 1];
//    suf[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf[i] = suf[i + 1] + s[i] - '0';
//    }
//    int ans = n, pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans = fmin(n - i - suf[i] + pre, ans);
//        pre += s[i] - '0';
//    }
//    ans = fmin(pre - suf[n], ans);
//    return ans;
//}
//
//int minFlipsMonoIncr(char* s)
//{
//    int n = strlen(s);
//    int f[n + 1][2];
//    f[0][0] = f[0][1] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        f[i + 1][0] = f[i][0] + s[i] - '0';
//        f[i + 1][1] = fmin(f[i][0], f[i][1]) + '1' - s[i];
//    }
//    return fmin(f[n][0], f[n][1]);
//}
//
