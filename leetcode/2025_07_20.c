////1143. 最长公共子序列
//
//int dfs(int i, int j, char* text1, char* text2, int** cache)
//{
//    if (i < 0 || j < 0)
//        return 0;
//
//    if (text1[i] == text2[j])
//    {
//        if (cache[i + 1][j + 1] == -1)
//            cache[i + 1][j + 1] = dfs(i - 1, j - 1, text1, text2, cache) + 1;
//
//        return cache[i + 1][j + 1];
//    }
//
//    if (cache[i][j + 1] == -1)
//        cache[i][j + 1] = dfs(i - 1, j, text1, text2, cache);
//    if (cache[i + 1][j] == -1)
//        cache[i + 1][j] = dfs(i, j - 1, text1, text2, cache);
//
//    return fmax(cache[i][j + 1], cache[i + 1][j]);
//}
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int** cache = (int**)malloc(sizeof(int*) * (m + 1));
//    for (int i = 0; i <= m; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j <= n; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return dfs(m - 1, n - 1, text1, text2, cache);
//}
//
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int f[m + 1][n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = text1[i] == text2[j] ? f[i][j] + 1 : fmax(f[i][j + 1], f[i + 1][j]);
//        }
//    }
//
//    return f[m][n];
//}
//
//int longestCommonSubsequence(char* text1, char* text2)
//{
//    int m = strlen(text1);
//    int n = strlen(text2);
//    int f[2][n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[(i + 1) % 2][j + 1] = text1[i] == text2[j] ? f[i % 2][j] + 1 : fmax(f[i % 2][j + 1], f[(i + 1) % 2][j]);
//        }
//    }
//
//    return f[m % 2][n];
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
//            f[j + 1] = text1[i] == text2[j] ? pre + 1 : fmax(f[j + 1], f[j]);
//            pre = tmp;
//        }
//    }
//
//    return f[n];
//}
//
////72. 编辑距离
//
//int dfs(int i, int j, char* word1, char* word2, int** cache)
//{
//    if (i < 0)
//        return j + 1;
//    if (j < 0)
//        return i + 1;
//    if (word1[i] == word2[j])
//    {
//        if (cache[i + 1][j + 1] < 0)
//            cache[i + 1][j + 1] = dfs(i - 1, j - 1, word1, word2, cache);
//    }
//    else
//    {
//        if (cache[i + 1][j + 1] < 0)
//            cache[i + 1][j + 1] = fmin(fmin(dfs(i - 1, j, word1, word2, cache), dfs(i, j - 1, word1, word2, cache)), dfs(i - 1, j - 1, word1, word2, cache)) + 1;
//    }
//    return cache[i + 1][j + 1];
//}
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//    int** cache = (int**)malloc(sizeof(int*) * (m + 1));
//    for (int i = 0; i <= m; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j <= n; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return dfs(m - 1, n - 1, word1, word2, cache);
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        f[i][0] = i;
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        f[0][i] = i;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = word1[i] == word2[j] ? f[i][j] : fmin(fmin(f[i][j + 1], f[i + 1][j]), f[i][j]) + 1;
//        }
//    }
//    return f[m][n];
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//    int f[2][n + 1];
//    for (int j = 0; j <= n; j++)
//    {
//        f[0][j] = j;
//    }
//    memset(f[1], 0, sizeof(f[1]));
//    f[1][0] = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[(i + 1) % 2][j + 1] = word1[i] == word2[j] ? f[i % 2][j] : fmin(fmin(f[i % 2][j + 1], f[(i + 1) % 2][j]), f[i % 2][j]) + 1;
//        }
//        f[i % 2][0] = i + 2;
//    }
//    return f[m % 2][n];
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//    int f[n + 1];
//    for (int j = 0; j <= n; j++)
//    {
//        f[j] = j;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int pre = f[0];
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = word1[i] == word2[j] ? pre : fmin(fmin(f[j + 1], f[j]), pre) + 1;
//            pre = tmp;
//        }
//        f[0]++;
//    }
//    return f[n];
//}
//
////583. 两个字符串的删除操作
//
//int dfs(int i, int j, char* word1, char* word2, int** cache)
//{
//    if (i < 0)
//        return j + 1;
//    if (j < 0)
//        return i + 1;
//    if (word1[i] == word2[j])
//    {
//        if (cache[i + 1][j + 1] == -1)
//            cache[i + 1][j + 1] = dfs(i - 1, j - 1, word1, word2, cache);
//    }
//    else
//    {
//        if (cache[i][j + 1] == -1)
//            cache[i][j + 1] = dfs(i - 1, j, word1, word2, cache);
//        if (cache[i + 1][j] == -1)
//            cache[i + 1][j] = dfs(i, j - 1, word1, word2, cache);
//
//        cache[i + 1][j + 1] = fmin(cache[i][j + 1], cache[i + 1][j]) + 1;
//    }
//    return cache[i + 1][j + 1];
//}
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//
//    int** cache = (int**)malloc(sizeof(int*) * (m + 1));
//    for (int i = 0; i <= m; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j <= n; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return dfs(m - 1, n - 1, word1, word2, cache);
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        f[i][0] = i;
//    }
//    for (int j = 0; j <= n; j++)
//    {
//        f[0][j] = j;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = word1[i] == word2[j] ? f[i][j] : fmin(f[i][j + 1], f[i + 1][j]) + 1;
//        }
//    }
//    return f[m][n];
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//
//    int f[2][n + 1];
//
//    for (int j = 0; j <= n; j++)
//    {
//        f[0][j] = j;
//    }
//    memset(f[1], 0, sizeof(f[1]));
//    f[1][0] = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[(i + 1) % 2][j + 1] = word1[i] == word2[j] ? f[i % 2][j] : fmin(f[i % 2][j + 1], f[(i + 1) % 2][j]) + 1;
//        }
//        f[i % 2][0] += 2;
//    }
//    return f[m % 2][n];
//}
//
//int minDistance(char* word1, char* word2)
//{
//    int m = strlen(word1);
//    int n = strlen(word2);
//
//    int f[n + 1];
//
//    for (int j = 0; j <= n; j++)
//    {
//        f[j] = j;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int pre = f[0];
//        f[0]++;
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = word1[i] == word2[j] ? pre : fmin(f[j + 1], f[j]) + 1;
//            pre = tmp;
//        }
//    }
//    return f[n];
//}
//
////712. 两个字符串的最小ASCII删除和
//
//int dfs(int i, int j, char* s1, char* s2, int** cache)
//{
//    if (i < 0)
//    {
//        int sum = 0;
//        for (int k = j; k >= 0; k--)
//        {
//            sum += s2[k];
//        }
//        return sum;
//    }
//    if (j < 0)
//    {
//        int sum = 0;
//        for (int k = i; k >= 0; k--)
//        {
//            sum += s1[k];
//        }
//        return sum;
//    }
//    if (s1[i] == s2[j])
//    {
//        if (cache[i + 1][j + 1] == -1)
//            cache[i + 1][j + 1] = dfs(i - 1, j - 1, s1, s2, cache);
//    }
//    else
//    {
//        if (cache[i][j + 1] == -1)
//            cache[i][j + 1] = dfs(i - 1, j, s1, s2, cache);
//        if (cache[i + 1][j] == -1)
//            cache[i + 1][j] = dfs(i, j - 1, s1, s2, cache);
//
//        cache[i + 1][j + 1] = fmin(cache[i][j + 1] + s1[i], cache[i + 1][j] + s2[j]);
//    }
//    return cache[i + 1][j + 1];
//}
//int minimumDeleteSum(char* s1, char* s2)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//
//    int** cache = (int**)malloc(sizeof(int*) * (m + 1));
//    for (int i = 0; i <= m; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j <= n; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return dfs(m - 1, n - 1, s1, s2, cache);
//}
//
//int minimumDeleteSum(char* s1, char* s2)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//
//    int f[m + 1][n + 1];
//    f[0][0] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        f[i + 1][0] = f[i][0] + s1[i];
//    }
//    for (int j = 0; j < n; j++)
//    {
//        f[0][j + 1] = f[0][j] + s2[j];
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = s1[i] == s2[j] ? f[i][j] : fmin(f[i][j + 1] + s1[i], f[i + 1][j] + s2[j]);
//        }
//    }
//    return f[m][n];
//}
//
//int minimumDeleteSum(char* s1, char* s2)
//{
//    int m = strlen(s1);
//    int n = strlen(s2);
//
//    int f[n + 1];
//    f[0] = 0;
//    for (int j = 0; j < n; j++)
//    {
//        f[j + 1] = f[j] + s2[j];
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int pre = f[0];
//        f[0] += s1[i];
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = s1[i] == s2[j] ? pre : fmin(f[j + 1] + s1[i], f[j] + s2[j]);
//            pre = tmp;
//        }
//    }
//    return f[n];
//}
//
