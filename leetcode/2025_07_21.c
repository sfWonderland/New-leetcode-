////97. 交错字符串
//
//int dfs(int i, int j, char* s1, char* s2, char* s3, int** cache)
//{
//
//    if (i < 0)
//    {
//        if (j < 0)
//            return true;
//        for (int k = j; k >= 0; k--)
//        {
//            if (s2[k] != s3[k])
//                return false;
//        }
//        return true;
//    }
//    if (j < 0)
//    {
//        for (int k = i; k >= 0; k--)
//        {
//            if (s1[k] != s3[k])
//                return false;
//        }
//        return true;
//    }
//    if ((s1[i] != s3[i + j + 1]) && (s2[j] != s3[i + j + 1]))
//        return false;
//    if (s1[i] == s3[i + j + 1])
//    {
//        if (cache[i][j + 1] == -1)
//            cache[i][j + 1] = dfs(i - 1, j, s1, s2, s3, cache);
//    }
//    if (s2[j] == s3[i + j + 1])
//    {
//        if (cache[i + 1][j] == -1)
//            cache[i + 1][j] = dfs(i, j - 1, s1, s2, s3, cache);
//    }
//    cache[i + 1][j + 1] = fmax(cache[i][j + 1], cache[i + 1][j]);
//    return cache[i + 1][j + 1];
//}
//bool isInterleave(char* s1, char* s2, char* s3)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//    int l = strlen(s3);
//    if (m + n != l)
//        return false;
//    int** cache = (int**)malloc(sizeof(int*) * (m + 1));
//    for (int i = 0; i <= m; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j <= n; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return dfs(m - 1, n - 1, s1, s2, s3, cache);
//}
//
//bool isInterleave(char* s1, char* s2, char* s3)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//    int l = strlen(s3);
//    if (m + n != l)
//        return false;
//    bool f[m + 1][n + 1];
//    memset(f, 0, sizeof(f));
//    f[0][0] = true;
//    for (int i = 0; i < m; i++)
//    {
//        f[i + 1][0] = (s1[i] == s3[i]) & f[i][0];
//    }
//    for (int j = 0; j < n; j++)
//    {
//        f[0][j + 1] = (s2[j] == s3[j]) & f[0][j];
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] |= s1[i] == s3[i + j + 1] ? f[i][j + 1] : 0;
//            f[i + 1][j + 1] |= s2[j] == s3[i + j + 1] ? f[i + 1][j] : 0;
//        }
//    }
//    return f[m][n];
//}
//
//bool isInterleave(char* s1, char* s2, char* s3)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//    int l = strlen(s3);
//    if (m + n != l)
//        return false;
//
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = true;
//    for (int j = 0; j < n; j++)
//    {
//        f[j + 1] = (s2[j] == s3[j]) & f[j];
//    }
//    for (int i = 0; i < m; i++)
//    {
//        f[0] = f[0] && s1[i] == s3[i];
//        for (int j = 0; j < n; j++)
//        {
//            f[j + 1] = s1[i] == s3[i + j + 1] && f[j + 1] || s2[j] == s3[i + j + 1] && f[j];
//        }
//    }
//    return f[n];
//}
//
////1458. 两个子序列的最大点积
//
//int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int f[nums1Size][nums2Size];
//    for (int i = 0; i < nums1Size; i++)
//    {
//        for (int j = 0; j < nums2Size; j++)
//        {
//            int x = nums1[i] * nums2[j];
//            f[i][j] = x;
//            if (i > 0)
//                f[i][j] = fmax(f[i - 1][j], f[i][j]);
//            if (j > 0)
//                f[i][j] = fmax(f[i][j - 1], f[i][j]);
//            if (i > 0 && j > 0)
//                f[i][j] = fmax(f[i - 1][j - 1] + x, f[i][j]);
//        }
//    }
//    return f[nums1Size - 1][nums2Size - 1];
//}
//
//int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int f[nums2Size + 1];
//    for (int i = 0; i <= nums2Size; i++)
//    {
//        f[i] = INT_MIN / 2;
//    }
//    for (int i = 0; i < nums1Size; i++)
//    {
//        f[0] = INT_MIN / 2;
//        int pre = f[0];
//        for (int j = 0; j < nums2Size; j++)
//        {
//            int tmp = f[j + 1];
//            int x = nums1[i] * nums2[j];
//            f[j + 1] = fmax(fmax(f[j], f[j + 1]), fmax(pre, 0) + x);
//            pre = tmp;
//        }
//    }
//    return f[nums2Size];
//}
//
////1092. 最短公共超序列
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* shortestCommonSupersequence(char* str1, char* str2)
//{
//    int m = strlen(str1);
//    int n = strlen(str2);
//
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++) f[i][0] = i;
//    for (int i = 1; i <= n; i++) f[0][i] = i;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = str1[i] == str2[j] ? f[i][j] + 1 : fmin(f[i][j + 1], f[i + 1][j]) + 1;
//        }
//    }
//
//    int i = m - 1, j = n - 1;
//    char* ans = (char*)malloc(sizeof(char) * (f[m][n] + 1));
//    ans[f[m][n]] = '\0';
//    int t = 0;
//    while (i >= 0 && j >= 0)
//    {
//        if (str1[i] == str2[j])
//        {
//            ans[t++] = str1[i];
//            i--; j--;
//        }
//        else if (f[i + 1][j + 1] == f[i][j + 1] + 1)
//        {
//            ans[t++] = str1[i];
//            i--;
//        }
//        else
//        {
//            ans[t++] = str2[j];
//            j--;
//        }
//    }
//    while (i >= 0)
//        ans[t++] = str1[i--];
//    while (j >= 0)
//        ans[t++] = str2[j--];
//
//    reverse(ans, 0, f[m][n] - 1);
//    return ans;
//}
//
////2320. 统计放置房子的方式数
//
//#define mod 1000000007
//#define mx 10001
//
//int f[mx];
//bool initialized;
//
//void init()
//{
//    if (initialized)
//        return;
//
//    initialized = true;
//
//    f[0] = 1;
//    f[1] = 2;
//    for (int i = 2; i < mx; i++)
//    {
//        f[i] = (f[i - 1] + f[i - 2]) % mod;
//    }
//}
//int countHousePlacements(int n)
//{
//    init();
//    return 1ll * f[n] * f[n] % mod;
//}
//
////2606. 找到最大开销的子字符串
//
//int maximumCostSubstring(char* s, char* chars, int* vals, int valsSize)
//{
//    int value[26] = { 0 };
//    for (int i = 0; i < 26; i++)
//    {
//        value[i] = i + 1;
//    }
//    for (int i = 0; chars[i]; i++)
//    {
//        value[chars[i] - 'a'] = vals[i];
//    }
//    int n = strlen(s);
//    int f[n + 1];
//    f[0] = 0;
//    int max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        f[i + 1] = fmax(f[i], 0) + value[s[i] - 'a'];
//        max = fmax(f[i + 1], max);
//    }
//    return max;
//}
//
