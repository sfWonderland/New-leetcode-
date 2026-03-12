////1415. 长度为 n 的开心字符串中字典序第 k 小的字符串
//
//char* getHappyString(int n, int k)
//{
//    int size = 3 << (n - 1);
//    if (size < k)
//        return "";
//    k--;
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[n] = '\0';
//    ans[0] = (k >> (n - 1)) + 'a';
//    //printf("%d ", k);
//    k -= (ans[0] - 'a') << (n - 1);
//    //printf("%d ", k);
//    for (int i = 0; i < n - 1; i++)
//    {
//        bool t = (k >> (n - 2 - i)) & 1;
//        //printf("%d ", t);
//        if (t) ans[i + 1] = 'c' - (ans[i] == 'c');
//        else ans[i + 1] = 'a' + (ans[i] == 'a');
//    }
//    return ans;
//}
//
////2007. 从双倍数组中还原原数组    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* findOriginalArray(int* changed, int changedSize, int* returnSize)
//{
//    *returnSize = 0;
//    if (changedSize % 2)
//        return NULL;
//
//    HashItem* cnt = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < changedSize; i++)
//    {
//        HASH_FIND_INT(cnt, &changed[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = changed[i];
//            p->val = 0;
//            HASH_ADD_INT(cnt, key, p);
//        }
//        p->val++;
//    }
//    int key = 0;
//    HASH_FIND_INT(cnt, &key, p);
//    if (p && p->val % 2)
//        return NULL;
//    int n = HASH_COUNT(cnt);
//    int vals[n];
//    int pos = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        vals[pos++] = p->key;
//    }
//    qsort(vals, n, sizeof(int), cmp);
//    int* ans = (int*)malloc(sizeof(int) * changedSize / 2);
//    int pos2 = 0;
//    for (int i = 0; i < n; i++)
//    {
//        HashItem* p1 = NULL, * p2 = NULL;
//        int cnt1 = 0, cnt2 = 0;
//        int key = vals[i];
//        HASH_FIND_INT(cnt, &key, p1);
//        if (p1) cnt1 = p1->val;
//        key *= 2;
//        HASH_FIND_INT(cnt, &key, p2);
//        if (p2) cnt2 = p2->val;
//
//        if (cnt2 < cnt1) return NULL;
//
//        if (p2) p2->val -= cnt1;
//        if (p1->key == 0)
//            cnt1 /= 2;
//        while (cnt1)
//        {
//            ans[pos2++] = p1->key;
//            cnt1--;
//        }
//    }
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    *returnSize = pos2;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findOriginalArray(int* changed, int changedSize, int* returnSize)
//{
//    *returnSize = 0;
//    if (changedSize % 2)
//        return NULL;
//
//    int n = changedSize, m = changedSize / 2, max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (max < changed[i])
//            max = changed[i];
//    }
//    int cnt[max + 1];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < n; i++)
//    {
//        cnt[changed[i]]++;
//    }
//    if (cnt[0] % 2) return NULL;
//    int* ans = (int*)malloc(sizeof(int) * m);
//    int pos = 0;
//    while (cnt[0])
//    {
//        ans[pos++] = 0;
//        cnt[0] -= 2;
//    }
//    for (int i = 1; i <= max; i++)
//    {
//        if (!cnt[i]) continue;
//        if (i * 2 > max || cnt[2 * i] < cnt[i])
//            return NULL;
//        cnt[2 * i] -= cnt[i];
//        while (cnt[i])
//        {
//            ans[pos++] = i;
//            cnt[i]--;
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
////2165. 重排数字的最小值
//
//long long smallestNumber(long long num)
//{
//    if (!num) return 0;
//    bool neg = 0;
//    if (num < 0)
//    {
//        neg = true;
//        num = -num;
//    }
//    int cnt[10] = { 0 };
//    int n = neg;
//    while (num)
//    {
//        cnt[num % 10]++;
//        num /= 10;
//        n++;
//    }
//    char* s = (char*)malloc(sizeof(char) * (n + 1));
//    s[n] = '\0';
//    int initial = 0, multi = 1, pos = 0;
//    if (neg)
//    {
//        s[pos++] = '-';
//        initial = 9;
//        multi = -1;
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        int x = initial + multi * i;
//        while (cnt[x])
//        {
//            s[pos++] = x + '0';
//            cnt[x]--;
//        }
//    }
//    //printf("%s\n", s);
//    if (s[0] == '0')
//    {
//        int j = 0;
//        while (s[j] == '0')
//            j++;
//        s[0] = s[j];
//        s[j] = '0';
//    }
//    long long ans = 0;
//    for (int j = neg; j < n; j++)
//    {
//        ans *= 10;
//        ans += s[j] - '0';
//    }
//    if (neg) ans = -ans;
//    free(s);
//    return ans;
//}
//
////2177. 找到和为给定整数的三个连续整数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//long long* sumOfThree(long long num, int* returnSize)
//{
//    *returnSize = 0;
//    if (num % 3)
//        return NULL;
//
//    long long* ans = (long long*)malloc(sizeof(long long) * 3);
//    ans[0] = num / 3 - 1;
//    ans[1] = ans[0] + 1;
//    ans[2] = ans[1] + 1;
//    *returnSize = 3;
//    return ans;
//}
//
