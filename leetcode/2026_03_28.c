////3137. K 周期字符串需要的最少操作次数
//
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int minimumOperationsToMakeKPeriodic(char* word, int k)
//{
//    int n = strlen(word) / k;
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    int max = 1;
//    for (int i = 0; i < n; i++)
//    {
//        int l = i * k;
//        char tmp = word[l + k];
//        word[l + k] = '\0';
//        HASH_FIND_STR(cnt, word + l, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = (char*)malloc(sizeof(char) * (k + 1));
//            strcpy(p1->key, word + l);
//            p1->val = 1;
//            HASH_ADD_STR(cnt, key, p1);
//        }
//        else
//        {
//            p1->val++;
//            max = fmax(max, p1->val);
//        }
//        word[l + k] = tmp;
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    return n - max;
//}
//
////3160. 所有球里面不同颜色的数目    
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
//int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p1 = NULL;
//    HashItem* balls = NULL;
//    HashItem* p2 = NULL;
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    int count = 0;
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int x = queries[i][0], col = queries[i][1];
//        HASH_FIND_INT(cnt, &col, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = col;
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        p1->val++;
//        if (p1->val == 1)
//            count++;
//
//        HASH_FIND_INT(balls, &x, p2);
//        if (p2)
//        {
//            int col_pre = p2->val;
//            HASH_FIND_INT(cnt, &col_pre, p1);
//            if (p1)
//            {
//                p1->val--;
//            }
//            if (p1->val == 0)
//                count--;
//            p2->val = col;
//        }
//        else
//        {
//            p2 = (HashItem*)malloc(sizeof(HashItem));
//            p2->key = x;
//            p2->val = col;
//            HASH_ADD_INT(balls, key, p2);
//        }
//        ans[i] = count;
//    }
//
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p1, tmp)
//    {
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    HASH_ITER(hh, balls, p2, tmp)
//    {
//        HASH_DEL(balls, p2);
//        free(p2);
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////3163. 压缩字符串 III
//
//char* compressedString(char* word)
//{
//    int n = strlen(word);
//    char* ans = (char*)malloc(sizeof(char) * (2 * n + 1));
//    int pos = 0, left = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (word[i] != word[i + 1])
//        {
//            int m = i - left;
//            int k = m / 9;
//            int rem = m % 9;
//            for (; k > 0; k--)
//            {
//                ans[pos++] = '9';
//                ans[pos++] = word[i];
//            }
//            if (rem)
//            {
//                ans[pos++] = '0' + rem;
//                ans[pos++] = word[i];
//            }
//            left = i;
//        }
//    }
//    ans[pos] = '\0';
//    return ans;
//}
//
////3178. 找出 K 秒后拿着球的孩子
//
//int numberOfChild(int n, int k)
//{
//    int turn = k / (n - 1);
//    int left = k - turn * (n - 1);
//    return turn & 1 ? n - 1 - left : left;
//}
//
