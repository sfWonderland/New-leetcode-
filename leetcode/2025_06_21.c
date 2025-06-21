////3085. 成为 K 特殊字符串需要删除的最少字符数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minimumDeletions(char* word, int k)
//{
//    int cnt[26] = { 0 }, n = 0;
//    for (; word[n]; n++)
//    {
//        cnt[word[n] - 'a']++;
//    }
//    qsort(cnt, 26, sizeof(int), cmp);
//    int max_save = 0, s = 0, right = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        int base = cnt[i];
//        while (right < 26 && cnt[right] <= base + k)
//        {
//            s += cnt[right];
//            right++;
//        }
//        max_save = fmax(max_save, s + (26 - right) * (base + k));
//        s -= base;
//    }
//    return n - max_save;
//}
//
////2829. k-avoiding 数组的最小总和
//
//int minimumSum(int n, int k)
//{
//    int m = fmin(k / 2, n);
//    return (m * (m + 1) + (2 * k + n - m - 1) * (n - m)) / 2;
//}
//
////319. 灯泡开关
//
//int bulbSwitch(int n)
//{
//    return sqrt(n);
//}
//
////2579. 统计染色格子数
//
//long long coloredCells(int n)
//{
//    return 2l * n * n - 2l * n + 1l;
//}
//
