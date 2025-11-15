////3234. 统计 1 显著的字符串的数量
//
//// 0 的个数小于sqrt(n)，所以枚举0；
//// 枚举右端点， 记录0的下标；
//// 若子串中0的个数的平方大于子串长度，退出循环
//int numberOfSubstrings(char* s)
//{
//    int n = strlen(s);
//    int* zeros = (int*)malloc(sizeof(int) * (n + 1));
//    zeros[0] = -1;
//    int idx = 1, ans = 0, tot1 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '0')
//        {
//            zeros[idx++] = i;
//        }
//        else
//        {
//            tot1++;
//            ans += i - zeros[idx - 1];
//        }
//
//        for (int j = idx - 1; j > 0 && (idx - j) * (idx - j) <= tot1; j--)
//        {
//            int p = zeros[j - 1], q = zeros[j];
//            int cnt0 = idx - j;
//            int cnt1 = i - q + 1 - cnt0;
//            ans += fmax(0, q - fmax(cnt0 * cnt0 - cnt1, 0) - p);
//        }
//    }
//    free(zeros);
//    return ans;
//}
//
////2285. 道路的最大总重要性
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maximumImportance(int n, int** roads, int roadsSize, int* roadsColSize)
//{
//    int* cnt = (int*)calloc(sizeof(int), n);
//    for (int i = 0; i < roadsSize; i++)
//    {
//        cnt[roads[i][0]]++;
//        cnt[roads[i][1]]++;
//    }
//    qsort(cnt, n, sizeof(int), cmp);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans += 1ll * (i + 1) * cnt[i];
//    }
//    free(cnt);
//    return ans;
//}
//
////3016. 输入单词需要的最少按键次数 II
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minimumPushes(char* word)
//{
//    int n = strlen(word);
//    int* cnt = (int*)calloc(sizeof(int), 26);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[word[i] - 'a']++;
//    }
//    qsort(cnt, 26, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < 26 && cnt[i]; i++)
//    {
//        ans += cnt[i] * (i / 8 + 1);
//    }
//    return ans;
//}
//
////2931. 购买物品的最大开销
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maxSpending(int** values, int valuesSize, int* valuesColSize)
//{
//    int m = valuesSize, n = valuesColSize[0];
//    int* nums = (int*)malloc(sizeof(int) * m * n);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            nums[i * n + j] = values[i][j];
//        }
//    }
//    qsort(nums, m * n, sizeof(int), cmp);
//    long long ans = 0;
//    for (int i = 0; i < m * n; i++)
//    {
//        ans += 1ll * (i + 1) * nums[i];
//    }
//    free(nums);
//    return ans;
//}
//
