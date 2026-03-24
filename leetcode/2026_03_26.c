////2937. 使三个字符串相等
//
//int findMinimumOperations(char* s1, char* s2, char* s3)
//{
//    int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3);
//    int n = fmin(n1, fmin(n2, n3));
//    for (int i = 0; i < n; i++)
//    {
//        if (s1[i] != s2[i] || s1[i] != s3[i] || s2[i] != s3[i])
//        {
//            if (i < 1)
//                return -1;
//
//            return n1 + n2 + n3 - 3 * i;
//        }
//    }
//    return n1 + n2 + n3 - 3 * n;
//}
//
////2981. 找出出现至少三次的最长特殊子字符串 I    
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maximumLength(char* s)
//{
//    int n = strlen(s), cnt = 0;
//    int m = fmax(3, n / 2);
//    int groups[26][m];
//    memset(groups, 0, sizeof(groups));
//    int len[26] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        cnt++;
//        if (i + 1 == n || s[i] != s[i + 1])
//        {
//            int j = s[i] - 'a';
//            groups[j][len[j]++] = cnt;
//            cnt = 0;
//        }
//    }
//
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (groups[i][0] == 0)
//            continue;
//
//        qsort(groups[i], len[i], sizeof(int), cmp);
//        int cnt1 = groups[i][0], cnt2 = groups[i][1], cnt3 = groups[i][2];
//        //printf("%c %d %d %d\n", i + 'a', cnt1, cnt2, cnt3);
//        ans = fmax(ans, fmax(cnt1 - 2, fmax(fmin(cnt1 - 1, cnt2), cnt3)));
//    }
//    return ans ? ans : -1;
//}
//
////3014. 输入单词需要的最少按键次数 I
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minimumPushes(char* word)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; word[i]; i++)
//    {
//        cnt[word[i] - 'a']++;
//    }
//    qsort(cnt, 26, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < 26 && cnt[i]; i++)
//    {
//        ans += (i / 8 + 1) * cnt[i];
//    }
//    return ans;
//}
//
////3042. 统计前后缀下标对 I
//
//int countPrefixSuffixPairs(char** words, int wordsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < wordsSize - 1; i++)
//    {
//        int m = strlen(words[i]);
//        for (int j = i + 1; j < wordsSize; j++)
//        {
//            int n = strlen(words[j]);
//            if (n < m)
//                continue;
//
//            if (strncmp(words[j], words[i], m) || strncmp(words[j] + n - m, words[i], m))
//                continue;
//
//            ans++;
//        }
//    }
//    return ans;
//}
//
