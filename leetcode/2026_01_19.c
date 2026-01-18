////2947. 统计美丽子字符串 I
//
////            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
//bool vow[26] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
//int beautifulSubstrings(char* s, int k)
//{
//    int n = strlen(s), ans = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        int vowel = 0, cons = 0;
//        for (int j = i; j < n - 1; j += 2)
//        {
//            vowel += vow[s[j] - 'a'];
//            cons += 1 - vow[s[j] - 'a'];
//            vowel += vow[s[j + 1] - 'a'];
//            cons += 1 - vow[s[j + 1] - 'a'];
//            if ((vowel == cons) && ((vowel * cons) % k == 0))
//                ans++;
//        }
//    }
//    return ans;
//}
//
////2961. 双模幂运算    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int qpow(int x, int n, int mod)
//{
//    int res = 1;
//    while (n)
//    {
//        if (n & 1)
//            res = res * x % mod;
//
//        x = x * x % mod;
//        n >>= 1;
//    }
//    return res;
//}
//int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize)
//{
//    int n = variablesSize;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    *returnSize = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int a = variables[i][0], b = variables[i][1], c = variables[i][2];
//        int mod = variables[i][3];
//        if (qpow(qpow(a, b, 10), c, mod) == target)
//            ans[(*returnSize)++] = i;
//    }
//    return ans;
//}
//
////2511. 最多可以摧毁的敌人城堡数目
//
//int captureForts(int* forts, int fortsSize)
//{
//    int ans = 0, pre = -1;
//    for (int i = 0; i < fortsSize; i++)
//    {
//        if (forts[i])
//        {
//            if (pre >= 0 && forts[i] != forts[pre])
//                ans = fmax(ans, i - pre - 1);
//
//            pre = i;
//        }
//    }
//    return ans;
//}
//
////3325. 字符至少出现 K 次的子字符串 I
//
//int numberOfSubstrings(char* s, int k)
//{
//    int n = strlen(s), ans = 0;;
//    for (int i = 0; i < n; i++)
//    {
//        int cnt[26] = { 0 };
//        for (int j = i; j < n; j++)
//        {
//            cnt[s[j] - 'a']++;
//            if (cnt[s[j] - 'a'] >= k)
//            {
//                ans += n - j;
//                break;
//            }
//        }
//    }
//    return ans;
//}
//
//int numberOfSubstrings(char* s, int k)
//{
//    int n = strlen(s), ans = 0, left = 0;
//    int cnt[26] = { 0 };
//    for (int right = 0; right < n; right++)
//    {
//        cnt[s[right] - 'a']++;
//        while (cnt[s[right] - 'a'] >= k)
//        {
//            cnt[s[left] - 'a']--;
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//
