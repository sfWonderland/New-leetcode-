////822. 翻转卡片游戏
//
//int flipgame(int* fronts, int frontsSize, int* backs, int backsSize)
//{
//    bool forbidden[2001] = { 0 };
//    for (int i = 0; i < frontsSize; i++)
//    {
//        if (fronts[i] == backs[i])
//        {
//            forbidden[fronts[i]] = true;
//        }
//    }
//    int ans = INT_MAX;
//    for (int i = 0; i < frontsSize; i++)
//    {
//        if (!forbidden[fronts[i]]) ans = fmin(ans, fronts[i]);
//        if (!forbidden[backs[i]]) ans = fmin(ans, backs[i]);
//    }
//    return ans == INT_MAX ? 0 : ans;
//}
//
////954. 二倍数对数组    
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(const void* e1, const void* e2)
//{
//    return abs(*(int*)e1) - abs(*(int*)e2);
//}
//bool canReorderDoubled(int* arr, int arrSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* p = NULL;
//    for (int i = 0; i < arrSize; i++)
//    {
//        HASH_FIND_INT(cnt, &arr[i], p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = arr[i];
//            p->val = 0;
//            HASH_ADD_INT(cnt, key, p);
//        }
//        p->val++;
//    }
//    int x = 0;
//    HASH_FIND_INT(cnt, &x, p);
//    if (p && p->val % 2)
//        return false;
//
//    int cntSize = HASH_COUNT(cnt);
//    int vals[cntSize];
//    int pos = 0;
//    HashItem* tmp;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        vals[pos++] = p->key;
//    }
//    qsort(vals, cntSize, sizeof(int), cmp);
//    for (int i = 0; i < cntSize; i++)
//    {
//        int cnt1 = 0, cnt2 = 0;
//        int key = vals[i];
//        HashItem* p1 = NULL, * p2 = NULL;
//
//        HASH_FIND_INT(cnt, &key, p1);
//        if (p1) cnt1 = p1->val;
//        key *= 2;
//        HASH_FIND_INT(cnt, &key, p2);
//        if (p2) cnt2 = p2->val;
//
//        if (cnt2 < cnt1)
//        {
//            HASH_ITER(hh, cnt, p, tmp)
//            {
//                HASH_DEL(cnt, p);
//                free(p);
//            }
//            return false;
//        }
//
//        if (p2) p2->val -= cnt1;
//    }
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    return true;
//}
//
////1525. 字符串的好分割数目
//
//int numSplits(char* s)
//{
//    int n = strlen(s);
//    int cnt1[26] = { 0 };
//    int diff1[n + 1];
//    diff1[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        diff1[i] = (cnt1[s[i] - 'a'] == 0) + diff1[i + 1];
//        cnt1[s[i] - 'a']++;
//    }
//    int diff2 = 0, ans = 0;
//    int cnt2[26] = { 0 };
//    for (int i = 0; i < n - 1; i++)
//    {
//        diff2 += cnt2[s[i] - 'a'] == 0;
//        if (diff2 == diff1[i + 1])
//            ans++;
//        cnt2[s[i] - 'a']++;
//    }
//    return ans;
//}
//
////1861. 旋转盒子
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = boxGridSize, m = boxGridColSize[0];
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (char*)malloc(sizeof(char) * n);
//        (*returnColumnSizes)[i] = n;
//        for (int j = 0; j < n; j++)
//        {
//            ans[i][j] = '.';
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            int c = 0;
//            for (; j < m && boxGrid[i][j] != '*'; j++)
//            {
//                if (boxGrid[i][j] == '#')
//                    c++;
//            }
//            if (j < m)
//                ans[j][n - 1 - i] = '*';
//            for (int k = j - 1; c > 0; k--)
//            {
//                ans[k][n - 1 - i] = '#';
//                c--;
//            }
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
