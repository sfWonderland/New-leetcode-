////3606. 优惠券校验器
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** c;
//char** b;
//int cmp(const void* e1, const void* e2)
//{
//    int x = *(int*)e1;
//    int y = *(int*)e2;
//    int diff = strcmp(b[x], b[y]);
//    return diff ? diff : strcmp(c[x], c[y]);
//}
//char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize)
//{
//    c = code;
//    b = businessLine;
//    int n = codeSize;
//    int* index = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        index[i] = i;
//    }
//    qsort(index, n, sizeof(int), cmp);
//    char** ans = (char**)malloc(sizeof(char*) * n);
//    *returnSize = 0;
//    for (int k = 0; k < n; k++)
//    {
//        int i = index[k];
//        if (!isActive[i]) continue;
//
//        char* business = businessLine[i];
//        if (strcmp(business, "electronics") && strcmp(business, "grocery") && strcmp(business, "pharmacy") && strcmp(business, "restaurant"))
//            continue;
//
//        int m = strlen(code[i]);
//        if (!m) continue;
//
//        for (int j = 0; j < m; j++)
//        {
//            char c = code[i][j];
//            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'))
//                continue;
//
//            isActive[i] = false;
//            break;
//        }
//        if (isActive[i])
//            ans[(*returnSize)++] = code[i];
//    }
//    return ans;
//}
//
////2375. 根据模式串构造最小数字
//
//char* smallestNumber(char* pattern)
//{
//    int i = 0, n = strlen(pattern);
//    char cur = '1';
//    char* ans = (char*)calloc(n + 2, sizeof(char));
//    while (i < n)
//    {
//        if (i && pattern[i] == 'I')
//            ++i;
//        for (; i < n && pattern[i] == 'I'; ++i)
//            ans[i] = cur++;
//        int i0 = i; // D的起点
//        while (i < n && pattern[i] == 'D')
//            ++i;
//        for (int j = i; j >= i0; --j)
//            ans[j] = cur++;
//    }
//    ans[n + 1] = '\0';
//    return ans;
//}
//
//void reverse(char* ans, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = ans[l];
//        ans[l++] = ans[r];
//        ans[r--] = tmp;
//    }
//}
//char* smallestNumber(char* pattern)
//{
//    int i = 0, n = strlen(pattern);
//    char* ans = (char*)malloc(sizeof(char) * (n + 2));
//    for (int i = 0; i < n + 1; i++)
//    {
//        ans[i] = i + '1';
//    }
//    while (i < n)
//    {
//        if (pattern[i] == 'I')
//            ++i;
//
//        int i0 = i; // D的起点
//        while (i < n && pattern[i] == 'D')
//            ++i;
//        reverse(ans, i0, i);
//    }
//    ans[n + 1] = '\0';
//    return ans;
//}
//
////2182. 构造限制重复的字符串
//
//char* repeatLimitedString(char* s, int repeatLimit)
//{
//    int cnt[26] = { 0 };
//    int n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int j = 0;
//    for (int i = 25; i >= 0; i--)
//    {
//        if (cnt[i] == 0)
//            continue;
//        int cnt_a = repeatLimit;
//        while (cnt_a && cnt[i])
//        {
//            s[j++] = i + 'a';
//            cnt_a--;
//            cnt[i]--;
//        }
//        while (cnt[i])
//        {
//            int k = i - 1;
//            while (k >= 0 && cnt[k] == 0)
//                k--;
//            if (k < 0)
//                break;
//            else
//            {
//                s[j++] = k + 'a';
//                cnt[k]--;
//            }
//            int cnt_a = repeatLimit;
//            while (cnt_a && cnt[i])
//            {
//                s[j++] = i + 'a';
//                cnt_a--;
//                cnt[i]--;
//            }
//        }
//        //printf("%s\n", s);
//    }
//    s[j] = '\0';
//    return s;
//}
//
////738. 单调递增的数字
//
//int monotoneIncreasingDigits(int n)
//{
//    if (n < 10)
//        return n;
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    while (1)
//    {
//        int i = 1;
//        while (i < m && s[i] >= s[i - 1])
//            i++;
//        if (i == m)
//            return atoi(s);
//
//        if (s[i - 1] > '0')
//            s[i - 1]--;
//        else
//        {
//            s[i - 2]--;
//            s[i - 1] = '9';
//        }
//        for (; i < m; i++)
//        {
//            s[i] = '9';
//        }
//    }
//    return -1;
//}
//
//int monotoneIncreasingDigits(int n)
//{
//    if (n < 10)
//        return n;
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int j = n;
//    for (int i = m - 1; i > 0; i--)
//    {
//        if (s[i] >= s[i - 1])
//            continue;
//
//        s[i - 1]--;
//        j = i;
//    }
//    while (j < m)
//    {
//        s[j++] = '9';
//    }
//    return atoi(s);
//}
//
