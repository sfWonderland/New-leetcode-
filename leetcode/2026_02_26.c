////1743. 从相邻元素对还原数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int a;
//    int b;
//    UT_hash_handle hh;
//}HashItem;
//int* restoreArray(int** adjacentPairs, int adjacentPairsSize, int* adjacentPairsColSize, int* returnSize)
//{
//    int n = adjacentPairsSize;
//    HashItem* cnt = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        int x = adjacentPairs[i][0], y = adjacentPairs[i][1];
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &x, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = x;
//            p1->a = y;
//            p1->b = INT_MAX;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        else
//            p1->b = y;
//
//        HASH_FIND_INT(cnt, &y, p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = y;
//            p1->a = x;
//            p1->b = INT_MAX;
//            HASH_ADD_INT(cnt, key, p1);
//        }
//        else
//            p1->b = x;
//    }
//    HashItem* p = cnt;
//    while (p->b != INT_MAX)
//        p = p->hh.next;
//
//    int* ans = (int*)malloc(sizeof(int) * (n + 1));
//    ans[0] = p->key;
//    int k = 1;
//    while (k <= n)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &ans[k - 1], p1);
//        HashItem* p2 = NULL;
//        HASH_FIND_INT(cnt, &(p1->a), p2);
//        ans[k++] = p2 ? p1->a : p1->b;
//        HASH_DEL(cnt, p1);
//        free(p1);
//    }
//    free(cnt);
//    *returnSize = n + 1;
//    return ans;
//}
//
////1781. 所有子字符串美丽值之和    
//
//int beautySum(char* s)
//{
//    int ans = 0, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        int cnt[26] = { 0 };
//        int max = 0;
//        for (int j = i; j < n; j++)
//        {
//            cnt[s[j] - 'a']++;
//            max = fmax(max, cnt[s[j] - 'a']);
//            int min = n;
//            for (int k = 0; k < 26; k++)
//            {
//                if (cnt[k] && cnt[k] < min)
//                    min = cnt[k];
//            }
//            ans += max - min;
//        }
//    }
//    return ans;
//}
//
////1806. 还原排列的最少操作步数
//
//int reinitializePermutation(int n)
//{
//    // 不需要考虑所有元素，当一个元素变回初始值时，其他的所有元素也会变回对应的初始值
//    // 代码只考虑i = 1 的元素回到原来位置的过程
//    int x = n / 2, ans = 1;
//    while (x != 1)
//    {
//        x = x & 1 ? (x + n - 1) / 2 : x / 2;
//        ans++;
//    }
//    return ans;
//}
//
////1860. 增长的内存泄露
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* memLeak(int memory1, int memory2, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 3);
//    int time = 1;
//    while (memory1 >= time || memory2 >= time)
//    {
//        if (memory1 >= memory2)
//            memory1 -= time;
//        else
//            memory2 -= time;
//
//        time++;
//    }
//    ans[0] = time; ans[1] = memory1; ans[2] = memory2;
//    *returnSize = 3;
//    return ans;
//}
//
