////3085. ��Ϊ K �����ַ�����Ҫɾ���������ַ���
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
////2829. k-avoiding �������С�ܺ�
//
//int minimumSum(int n, int k)
//{
//    int m = fmin(k / 2, n);
//    return (m * (m + 1) + (2 * k + n - m - 1) * (n - m)) / 2;
//}
//
////319. ���ݿ���
//
//int bulbSwitch(int n)
//{
//    return sqrt(n);
//}
//
////2579. ͳ��Ⱦɫ������
//
//long long coloredCells(int n)
//{
//    return 2l * n * n - 2l * n + 1l;
//}
//
