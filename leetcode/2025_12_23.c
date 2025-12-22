////2054. 两个最好的不重叠活动
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] - (*(int**)e2)[1];
//}
//int lower_bound(int** st, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (st[mid][0] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int maxTwoEvents(int** events, int eventsSize, int* eventsColSize)
//{
//    int n = eventsSize;
//    int** st = (int**)malloc(sizeof(int*) * (n + 1));
//    st[0] = (int*)malloc(sizeof(int) * 2);
//    st[0][0] = 0, st[0][1] = 0;
//    int k = 1, ans = 0;
//    qsort(events, n, sizeof(int*), cmp);
//    for (int i = 0; i < n; i++)
//    {
//        int start_time = events[i][0], value = events[i][2];
//        int j = lower_bound(st, k, start_time) - 1;
//        ans = fmax(ans, st[j][1] + value);
//        if (value > st[k - 1][1])
//        {
//            st[k] = (int*)malloc(sizeof(int) * 2);
//            st[k][0] = events[i][1];
//            st[k++][1] = value;
//        }
//    }
//    for (int i = 0; i < k; i++)
//    {
//        free(st[i]);
//    }
//    free(st);
//    return ans;
//}
//
////989. 数组形式的整数加法
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    int n = fmax(5, numSize);
//    int* ans = (int*)malloc(sizeof(int) * (n + 1));
//    int d = n + 1 - numSize;
//    for (int i = 0; i < d; i++)
//    {
//        ans[i] = 0;
//    }
//    for (int i = 0; i < numSize; i++)
//    {
//        ans[i + d] = num[i];
//    }
//    int j = n;
//    while (k)
//    {
//        ans[j--] += k % 10;
//        k /= 10;
//    }
//    for (int i = n; i > 0; i--)
//    {
//        if (ans[i] > 9)
//        {
//            ans[i - 1]++;
//            ans[i] %= 10;
//        }
//    }
//    d = 0;
//    for (int i = 0; ans[i] == 0; i++)
//    {
//        d++;
//    }
//
//    *returnSize = n + 1 - d;
//    return ans + d;
//}
//
////2047. 句子中的有效单词数
//
//bool isAlpha(char c)
//{
//    return (c >= 'a' && c <= 'z');
//}
//bool isDigit(char c)
//{
//    return (c >= '0' && c <= '9');
//}
//int countValidWords(char* sentence)
//{
//    int n = 0;
//    for (char* s = strtok(sentence, " "); s; s = strtok(NULL, " "))
//    {
//        printf("%s\n", s);
//        int m = strlen(s);
//        if (m == 1)
//        {
//            n += !(isDigit(s[0]) || s[0] == '-');
//            continue;
//        }
//        if (!isAlpha(s[0]))
//            continue;
//        bool flag = true;
//        bool k = true;
//        for (int i = 1; i < m - 1 && flag; i++)
//        {
//            if (!isAlpha(s[i]))
//            {
//                if (s[i] == '-' && k)
//                {
//                    flag = isAlpha(s[i + 1]);
//                    k = 0;
//                }
//                else
//                    flag = false;
//            }
//        }
//        if (!flag || isDigit(s[m - 1]) || s[m - 1] == '-')
//            continue;
//        n++;
//    }
//    return n;
//}
//
////2053. 数组中第 K 个独一无二的字符串
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//char* kthDistinct(char** arr, int arrSize, int k)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < arrSize; i++)
//    {
//        HASH_FIND_STR(cnt, arr[i], pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = arr[i];
//            pEntry->val = 1;
//            HASH_ADD_STR(cnt, key, pEntry);
//        }
//        else
//            pEntry->val++;
//    }
//    HashItem* tmp = NULL;
//    char* ans = "";
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        if (pEntry->val > 1)
//            continue;
//
//        if (k == 1)
//            ans = pEntry->key;
//
//        k--;
//        free(pEntry);
//    }
//    return ans;
//}
//
