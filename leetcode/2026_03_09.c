////3130. 找出所有稳定的二进制数组 II
//
//const int MOD = 1E9 + 7;
//int numberOfStableArrays(int zero, int one, int limit)
//{
//    int f[zero + 1][one + 1][2];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i <= fmin(limit, zero); i++)
//    {
//        f[i][0][0] = 1;
//    }
//    for (int j = 0; j <= fmin(limit, one); j++)
//    {
//        f[0][j][1] = 1;
//    }
//    for (int i = 0; i < zero; i++)
//    {
//        for (int j = 0; j < one; j++)
//        {
//            f[i + 1][j + 1][0] = i >= limit ? MOD - f[i - limit][j + 1][1] : 0;
//            f[i + 1][j + 1][0] = (1ll * f[i + 1][j + 1][0] + f[i][j + 1][0] + f[i][j + 1][1]) % MOD;
//            f[i + 1][j + 1][1] = j >= limit ? MOD - f[i + 1][j - limit][0] : 0;
//            f[i + 1][j + 1][1] = (1ll * f[i + 1][j + 1][1] + f[i + 1][j][0] + f[i + 1][j][1]) % MOD;
//        }
//    }
//    return (1ll * f[zero][one][0] + f[zero][one][1]) % MOD;
//}
//
////3129. 找出所有稳定的二进制数组 I    
//
//const int MOD = 1E9 + 7;
//int numberOfStableArrays(int zero, int one, int limit)
//{
//    int f[zero + 1][one + 1][2];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i <= fmin(limit, zero); i++)
//    {
//        f[i][0][0] = 1;
//    }
//    for (int j = 0; j <= fmin(limit, one); j++)
//    {
//        f[0][j][1] = 1;
//    }
//    for (int i = 0; i < zero; i++)
//    {
//        for (int j = 0; j < one; j++)
//        {
//            f[i + 1][j + 1][0] = i >= limit ? MOD - f[i - limit][j + 1][1] : 0;
//            f[i + 1][j + 1][0] = (1ll * f[i + 1][j + 1][0] + f[i][j + 1][0] + f[i][j + 1][1]) % MOD;
//            f[i + 1][j + 1][1] = j >= limit ? MOD - f[i + 1][j - limit][0] : 0;
//            f[i + 1][j + 1][1] = (1ll * f[i + 1][j + 1][1] + f[i + 1][j][0] + f[i + 1][j][1]) % MOD;
//        }
//    }
//    return (1ll * f[zero][one][0] + f[zero][one][1]) % MOD;
//}
//
////LCR 164. 破解闯关密码
//
//int cmp(const void* e1, const void* e2)
//{
//    char* s1 = *(char**)e1, * s2 = *(char**)e2;
//    int n = strlen(s1), m = strlen(s2);
//    char t1[m + n + 1], t2[m + n + 1];
//    strcpy(t1, s1); strcpy(t2, s2);
//    strcat(t1, s2); strcat(t2, s1);
//    return strcmp(t1, t2);
//}
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* crackPassword(int* password, int passwordSize)
//{
//    int n = passwordSize, m = 0;
//    char** nums = (char**)malloc(sizeof(char*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        nums[i] = (char*)malloc(sizeof(char) * 10);
//        int j = 0, x = password[i];
//        if (x == 0) nums[i][j++] = '0';
//        while (x)
//        {
//            nums[i][j++] = x % 10 + '0';
//            x /= 10;
//        }
//        nums[i][j] = '\0';
//        reverse(nums[i], 0, j - 1);
//        m += j;
//    }
//    qsort(nums, n, sizeof(char*), cmp);
//    char* ans = (char*)malloc(sizeof(char) * (m + 1));
//    ans[0] = '\0';
//    for (int i = 0; i < n; i++)
//    {
//        strcat(ans, nums[i]);
//    }
//    ans[m] = '\0';
//    return ans;
//}
//
////784. 字母大小写全排列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** letterCasePermutation(char* s, int* returnSize)
//{
//    int capacity = 8, n = strlen(s);
//    char** ans = (char**)malloc(sizeof(char*) * capacity);
//    *returnSize = 0;
//    void dfs(int i)
//    {
//        ans[*returnSize] = (char*)malloc(sizeof(char) * (n + 1));
//        strcpy(ans[(*returnSize)++], s);
//        if (*returnSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (char**)realloc(ans, sizeof(char*) * capacity);
//        }
//        for (int j = i; j < n; j++)
//        {
//            if (isalpha(s[j]))
//            {
//                s[j] ^= ' ';
//                dfs(j + 1);
//                s[j] ^= ' ';
//            }
//        }
//    }
//    dfs(0);
//    return ans;
//}
//
