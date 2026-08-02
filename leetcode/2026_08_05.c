//// 4006. 统计有效前缀数目
//
//int countValidPrefixes(char* s)
//{
//    int diff = 0, ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        diff += s[i] - '0' ? -1 : 1;
//        if (abs(diff) <= 1)
//            ans++;
//    }
//    return ans;
//}
//
//// 4007. 栅栏的最宽宽度    
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//double total = 0;
//void add(HashItem** cnt, int x, int c)
//{
//    HashItem* p0 = NULL;
//    HASH_FIND_INT(*cnt, &x, p0);
//    if (p0 == NULL)
//    {
//        p0 = (HashItem*)malloc(sizeof(HashItem));
//        p0->key = x;
//        p0->val = 0;
//        HASH_ADD_INT(*cnt, key, p0);
//    }
//    p0->val += c;
//}
//int maximumWidth(int* planks, int planksSize)
//{
//    clock_t start = clock();
//    int n = planksSize, m = 0;
//    HashItem* cnt = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        HashItem* p1 = NULL;
//        HASH_FIND_INT(cnt, &planks[i], p1);
//        if (p1 == NULL)
//        {
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = planks[i];
//            p1->val = 0;
//            HASH_ADD_INT(cnt, key, p1);
//            m++;
//        }
//        p1->val++;
//    }
//    HashItem* cnt_pair = NULL;
//    HashItem* p0 = NULL, * tmp0 = NULL;
//    HASH_ITER(hh, cnt, p0, tmp0)
//    {
//        int x = p0->key, cnt1 = p0->val;
//        add(&cnt_pair, x, cnt1);
//        add(&cnt_pair, 2 * x, cnt1 / 2);
//        HashItem* p1 = NULL, * tmp1 = NULL;
//        HASH_ITER(hh, cnt, p1, tmp1)
//        {
//            int y = p1->key, cnt2 = p1->val;
//            if (y > x)
//                add(&cnt_pair, x + y, fmin(cnt1, cnt2));
//        }
//    }
//    HASH_ITER(hh, cnt, p0, tmp0)
//    {
//        HASH_DEL(cnt, p0);
//        free(p0);
//    }
//    int ans = 0;
//    HashItem* p1 = NULL, * tmp1 = NULL;
//    HASH_ITER(hh, cnt_pair, p1, tmp1)
//    {
//        // printf("%d %d\n", p1 -> key, p1 -> val);
//        ans = fmax(ans, p1->val);
//        HASH_DEL(cnt_pair, p1);
//        free(p1);
//    }
//    clock_t end = clock();
//    total += 1000.0 * (end - start) / CLOCKS_PER_SEC;
//    printf("%lfms", total);
//    return ans;
//}
//
//typedef struct
//{
//    int key;
//    int val;
//}Pair;
//double total = 0;
//int cmp1(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return (*(Pair*)e1).key - (*(Pair*)e2).key;
//}
//int maximumWidth(int* planks, int planksSize)
//{
//    clock_t start = clock();
//    int n = planksSize, m = 0;
//    qsort(planks, n, sizeof(int), cmp1);
//    int cnt[n][2];
//    cnt[m][0] = planks[0];
//    cnt[m++][1] = 1;
//    for (int i = 1; i < n; i++)
//    {
//        if (planks[i] != planks[i - 1])
//        {
//            cnt[m][0] = planks[i];
//            cnt[m++][1] = 0;
//        }
//        cnt[m - 1][1]++;
//    }
//    int mm = m * (m + 3) / 2;
//    Pair cnt_pair[mm];
//    int k = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int x = cnt[i][0], cnt1 = cnt[i][1];
//        cnt_pair[k].key = x;
//        cnt_pair[k++].val = cnt1;
//        if (cnt1 > 1)
//        {
//            cnt_pair[k].key = x * 2;
//            cnt_pair[k++].val = cnt1 / 2;
//        }
//        for (int j = i + 1; j < m; j++)
//        {
//            int y = cnt[j][0], cnt2 = cnt[j][1];
//            cnt_pair[k].key = y + x;
//            cnt_pair[k++].val = fmin(cnt1, cnt2);
//        }
//    }
//    qsort(cnt_pair, k, sizeof(Pair), cmp2);
//    int len = 0;
//    for (int i = 1; i < k; i++)
//    {
//        if (cnt_pair[i].key != cnt_pair[i - 1].key)
//        {
//            cnt_pair[++len].key = cnt_pair[i].key;
//            cnt_pair[len].val = cnt_pair[i].val;
//        }
//        else
//            cnt_pair[len].val += cnt_pair[i].val;
//    }
//    int ans = 0;
//    for (int i = 0; i <= len; i++)
//    {
//        // printf("%d %d\n", cnt_pair[i].key, cnt_pair[i].val);
//        if (ans < cnt_pair[i].val)
//            ans = cnt_pair[i].val;
//    }
//    clock_t end = clock();
//    total += 1000.0 * (end - start) / CLOCKS_PER_SEC;
//    printf("%lfms", total);
//    return ans;
//}
//
//// 4008. 击败所有怪物的最小初始强度
//
//long long minInitialStrength(int* monsters, int monstersSize, int** boosts, int boostsSize, int* boostsColSize)
//{
//    int n = monstersSize;
//    long long dx[n + 1];
//    memset(dx, 0, sizeof(dx));
//    for (int i = 0; i < boostsSize; i++)
//    {
//        int left = boosts[i][0];
//        int right = boosts[i][1] + 1;
//        int boost = boosts[i][2];
//        dx[left] += boost;
//        dx[right] -= boost;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        dx[i] += dx[i - 1];
//    }
//    long long ans = 0, sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int limit = fmax(0, monsters[i] - dx[i]);
//        if (limit) ans = sum + limit;
//        sum += monsters[i];
//    }
//    return ans;
//}
//
