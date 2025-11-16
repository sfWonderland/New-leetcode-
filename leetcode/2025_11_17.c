////646. 最长数对链
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] - (*(int**)e2)[1];
//}
//int findLongestChain(int** pairs, int pairsSize, int* pairsColSize)
//{
//    qsort(pairs, pairsSize, sizeof(int*), cmp);
//    int ans = 0, max_r = -10000;
//    for (int i = 0; i < pairsSize; i++)
//    {
//        if (pairs[i][0] > max_r)
//        {
//            ans++;
//            max_r = pairs[i][1];
//        }
//    }
//    return ans;
//}
//
////2406. 将区间分为最少组数
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp2(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minGroups(int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    qsort(intervals, intervalsSize, sizeof(int*), cmp);
//    HashItem* diff = NULL;
//    HashItem* pEntry = NULL;
//    for (int i = 0; i < intervalsSize; i++)
//    {
//        int l = intervals[i][0], r = intervals[i][1] + 1;
//        HASH_FIND_INT(diff, &l, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = l;
//            pEntry->val = 1;
//            HASH_ADD_INT(diff, key, pEntry);
//        }
//        else
//            pEntry->val++;
//
//        HASH_FIND_INT(diff, &r, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = r;
//            pEntry->val = -1;
//            HASH_ADD_INT(diff, key, pEntry);
//        }
//        else
//            pEntry->val--;
//    }
//    HASH_SORT(diff, cmp2);
//    int ans = 0, sum = 0;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, diff, pEntry, tmp)
//    {
//        sum += pEntry->val;
//        ans = fmax(ans, sum);
//        free(pEntry);
//    }
//    return ans;
//}
//
////上下车模型
//int minGroups(int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    int diff[1000002] = { 0 };
//    int max = 0;
//    for (int i = 0; i < intervalsSize; i++)
//    {
//        diff[intervals[i][0]]++;
//        diff[intervals[i][1] + 1]--;
//        max = fmax(max, intervals[i][1] + 1);
//    }
//    int ans = 0, sum = 0;
//    for (int i = 0; i < max; i++)
//    {
//        ans = fmax(ans, sum += diff[i]);
//    }
//    return ans;
//}
//
////452. 用最少数量的箭引爆气球
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[1] > (*(int**)e2)[1] ? 1 : -1;
//}
//int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
//{
//    qsort(points, pointsSize, sizeof(int*), cmp);
//    int ans = 1, max_r = points[0][1];
//    for (int i = 1; i < pointsSize; i++)
//    {
//        if (points[i][0] > max_r)
//        {
//            ans++;
//            max_r = points[i][1];
//        }
//    }
//    return ans;
//}
//
////757. 设置交集大小至少为2
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] == (*(int**)e2)[0] ? (*(int**)e2)[1] - (*(int**)e1)[1] : (*(int**)e1)[0] - (*(int**)e2)[0];
//    //按左端点升序，右端点降序
//}
//int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    int n = intervalsSize;
//    qsort(intervals, n, sizeof(int*), cmp);
//    int ans = 2, cur = intervals[n - 1][0], nxt = intervals[n - 1][0] + 1;
//    for (int i = n - 2; i >= 0; i--)
//    {
//        //大区间包含小区间
//        if (intervals[i][1] >= nxt)
//            continue;
//        //不相交区间，重新贪心取左端点和左端点右一个单位点为判断点
//        else if (intervals[i][1] < cur)
//        {
//            ans += 2;
//            cur = intervals[i][0];
//            nxt = intervals[i][0] + 1;
//        }
//        //相交不重合区间，取原左判断点为右判断点，取左端点为新的左判断点
//        else
//        {
//            ans++;
//            nxt = cur;
//            cur = intervals[i][0];
//        }
//    }
//    return ans;
//}
//
