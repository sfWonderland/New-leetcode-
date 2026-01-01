////2801. 统计范围内的步进数字数目
//
//const int MOD = 1e9 + 7;
//int countSteppingNumbers(char* low, char* high)
//{
//    int n = strlen(high);
//    int n1 = strlen(low);
//    if (n1 < n)
//    {
//        low = (char*)realloc(low, sizeof(char) * (n + 1));
//        for (int i = n; i >= n - n1; i--)
//        {
//            low[i] = low[i - n + n1];
//        }
//        for (int i = 0; i < n - n1; i++)
//        {
//            low[i] = '0';
//        }
//    }
//    int** memo = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (int*)malloc(sizeof(int) * 10);
//        memset(memo[i], -1, sizeof(int) * 10);
//    }
//    int dfs(int i, int pre, bool limit_low, bool limit_high, bool isNum)
//    {
//        if (i == n)
//            return isNum;
//
//        if (isNum && !limit_high && !limit_low && memo[i][pre] != -1)
//            return memo[i][pre];
//
//        int lo = limit_low ? low[i] - '0' : 0;
//        int hi = limit_high ? high[i] - '0' : 9;
//        int res = 0;
//        if (!isNum && !lo)
//            res = dfs(i + 1, 0, true, false, false);
//        for (int j = isNum ? lo : fmax(lo, 1); j <= hi; j++)
//        {
//            if (!isNum || (abs(pre - j) == 1))
//            {
//                res = (res + dfs(i + 1, j, limit_low && j == lo, limit_high && j == hi, true)) % MOD;
//            }
//        }
//        if (!limit_high && !limit_low && isNum)
//            memo[i][pre] = res;
//        return res;
//    }
//    return dfs(0, 0, true, true, false);
//}
//
////2999. 统计强大整数的数目
//
//long long numberOfPowerfulInt(long long start, long long finish, int limit, char* s)
//{
//    char* high = (char*)malloc(sizeof(char) * 17);
//    sprintf(high, "%lld", finish);
//    int n = strlen(high);
//    char* low = (char*)malloc(sizeof(char) * (n + 1));
//    sprintf(low, "%lld", start);
//    int m = strlen(low);
//    for (int i = n; i >= n - m; i--)
//    {
//        low[i] = low[i - n + m];
//    }
//    for (int i = 0; i < n - m; i++)
//    {
//        low[i] = '0';
//    }
//    int diff = n - strlen(s);
//    long long* memo = (long long*)malloc(sizeof(long long) * n);
//    memset(memo, -1, sizeof(long long) * n);
//    long long dfs(int i, bool limit_low, bool limit_high)
//    {
//        if (i == n)
//            return 1;
//
//        if (!limit_high && !limit_low && memo[i] != -1)
//            return memo[i];
//
//        int lo = limit_low ? low[i] - '0' : 0;
//        int hi = limit_high ? high[i] - '0' : 9;
//        long long res = 0;
//        if (i < diff)
//        {
//            for (int j = lo; j <= fmin(hi, limit); j++)
//            {
//                res += dfs(i + 1, limit_low && j == lo, limit_high && j == hi);
//            }
//        }
//        else
//        {
//            int x = s[i - diff] - '0';
//            if (x >= lo && x <= hi)
//                res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
//        }
//        if (!limit_high && !limit_low)
//            memo[i] = res;
//        return res;
//    }
//    return dfs(0, true, true);
//}
//
////2827. 范围中美丽整数的数目
//
//int numberOfBeautifulIntegers(int low, int high, int k)
//{
//    char* up = (char*)malloc(sizeof(char) * 11);
//    sprintf(up, "%d", high);
//    int n = strlen(up);
//    char* down = (char*)malloc(sizeof(char) * (n + 1));
//    sprintf(down, "%d", low);
//    int d = n - strlen(down);
//    for (int i = n; i >= d; i--)
//    {
//        down[i] = down[i - d];
//    }
//    for (int i = 0; i < d; i++)
//    {
//        down[i] = '0';
//    }
//    int*** memo = (int***)malloc(sizeof(int**) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (int**)malloc(sizeof(int*) * 20);
//        for (int j = 0; j < 20; j++)
//        {
//            memo[i][j] = (int*)malloc(sizeof(int) * k);
//            memset(memo[i][j], -1, sizeof(int) * k);
//        }
//    }
//    int dfs(int i, int diff, int mod, bool limit_low, bool limit_high, bool isNum)
//    {
//        if (i == n)
//            return isNum && (diff == 9) && (mod == 0);
//
//        if (isNum && !limit_low && !limit_high && memo[i][diff][mod] != -1)
//            return memo[i][diff][mod];
//
//        int lo = limit_low ? down[i] - '0' : 0;
//        int hi = limit_high ? up[i] - '0' : 9;
//
//        int res = 0;
//        if (!isNum && !lo)
//            res = dfs(i + 1, diff, mod, true, false, false);
//        for (int j = isNum ? lo : fmax(lo, 1); j <= hi; j++)
//        {
//            int d = j % 2 ? 1 : -1;
//            int new_mod = (mod * 10 + j) % k;
//            res += dfs(i + 1, diff + d, new_mod, limit_low && j == lo, limit_high && j == hi, true);
//        }
//        if (isNum && !limit_low && !limit_high)
//            memo[i][diff][mod] = res;
//        return res;
//    }
//    return dfs(0, 9, 0, true, true, false);
//}
//
////3519. 统计逐位非递减的整数
//
//const int MOD = 1e9 + 7;
//// 2 ^ k == 10 ^ 100; k 为最大位数
//// k * ln2 == 100 * ln10 == 100 * (ln2 + ln5)
//// k = 100 * (1 + ln5 / ln2) > 332
//// 故 k = 333;
//const int MAX_LEN = 333;
//void reverse(int* nums, int l, int r)
//{
//    while (l < r)
//    {
//        int tmp = nums[l];
//        nums[l++] = nums[r];
//        nums[r--] = tmp;
//    }
//}
//void trans(int* nums, int* n, char* s, int b)
//{
//    int i = 0, j = 0;
//    s = (char*)realloc(s, sizeof(char) * (MAX_LEN + 1));
//    int len = strlen(s);
//    while (len)
//    {
//        int k = 0, rem = 0;
//        char* nxt_s = (char*)malloc(sizeof(char) * (MAX_LEN + 1));
//        for (int i = 0; i < len; i++)
//        {
//            rem = rem * 10 + s[i] - '0';
//            int q = rem / b;
//            if (q || k > 0)
//                nxt_s[k++] = q + '0';
//
//            rem = rem % b;
//        }
//        nxt_s[k] = '\0';
//        //printf("%d ", j);
//        nums[j++] = rem;
//        //printf("%s %s\n", s, nxt_s);
//        strcpy(s, nxt_s);
//        len = k;
//    }
//    reverse(nums, 0, j - 1);
//    *n = j;
//}
//int countNumbers(char* l, char* r, int b)
//{
//    int* high = (int*)malloc(sizeof(int) * 333);
//    int n = 0;
//    trans(high, &n, r, b);
//    printf("%d ", n);
//    int* low = (int*)malloc(sizeof(int) * n);
//    int m = 0;
//    trans(low, &m, l, b);
//    int d = n - m;
//    if (d)
//    {
//        for (int i = n - 1; i >= d; i--)
//        {
//            low[i] = low[i - d];
//        }
//        for (int i = 0; i < d; i++)
//        {
//            low[i] = 0;
//        }
//    }
//    int** memo = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (int*)malloc(sizeof(int) * b);
//        memset(memo[i], -1, sizeof(int) * b);
//    }
//    int dfs(int i, int pre, bool limit_low, bool limit_high)
//    {
//        if (i == n)
//            return 1;
//
//        if (!limit_low && !limit_high && memo[i][pre] != -1)
//            return memo[i][pre];
//
//        int lo = limit_low ? low[i] : 0;
//        int hi = limit_high ? high[i] : b - 1;
//        long long res = 0;
//        for (int j = fmax(lo, pre); j <= hi; j++)
//        {
//            res += dfs(i + 1, j, limit_low && j == lo, limit_high && j == hi);
//        }
//        res %= MOD;
//        if (!limit_low && !limit_high)
//            memo[i][pre] = res;
//        return res;
//    }
//    return dfs(0, 0, true, true);
//}
//
