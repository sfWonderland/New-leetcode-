////1600. 王位继承顺序
//
//typedef struct
//{
//    char* key;
//    int capacity;
//    char** val;
//    int valSize;
//    UT_hash_handle hh;
//}Inheritance;
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}Death;
//
//typedef struct
//{
//    Inheritance* edges;
//    Death* dead;
//    char* king;
//} ThroneInheritance;
//
//
//ThroneInheritance* throneInheritanceCreate(char* kingName)
//{
//    ThroneInheritance* obj = (ThroneInheritance*)malloc(sizeof(ThroneInheritance));
//    obj->edges = NULL;
//    obj->dead = NULL;
//    obj->king = kingName;
//    return obj;
//}
//
//void throneInheritanceBirth(ThroneInheritance* obj, char* parentName, char* childName)
//{
//    Inheritance* p1 = NULL;
//    HASH_FIND_STR(obj->edges, parentName, p1);
//    if (p1 == NULL)
//    {
//        p1 = (Inheritance*)malloc(sizeof(Inheritance));
//        p1->key = parentName;
//        p1->capacity = 64;
//        p1->val = (char**)malloc(sizeof(char*) * p1->capacity);
//        p1->valSize = 0;
//        HASH_ADD_STR(obj->edges, key, p1);
//    }
//    p1->val[p1->valSize++] = childName;
//    if (p1->valSize >= p1->capacity)
//    {
//        p1->capacity *= 2;
//        p1->val = (char**)realloc(p1->val, sizeof(char*) * p1->capacity);
//    }
//}
//
//void throneInheritanceDeath(ThroneInheritance* obj, char* name)
//{
//    Death* p1 = (Death*)malloc(sizeof(Death));
//    p1->key = name;
//    HASH_ADD_STR(obj->dead, key, p1);
//}
//
//char** throneInheritanceGetInheritanceOrder(ThroneInheritance* obj, int* retSize)
//{
//    int cap = 64;
//    char** ans = (char**)malloc(sizeof(char*) * cap);
//    int idx = 0;
//    void dfs(char* name)
//    {
//        Death* p1 = NULL;
//        HASH_FIND_STR(obj->dead, name, p1);
//        if (p1 == NULL)
//            ans[idx++] = name;
//
//        if (idx >= cap)
//        {
//            cap *= 2;
//            ans = (char**)realloc(ans, sizeof(char*) * cap);
//        }
//
//        Inheritance* p2 = NULL;
//        HASH_FIND_STR(obj->edges, name, p2);
//        if (p2)
//        {
//            for (int i = 0; i < p2->valSize; i++)
//            {
//                dfs(p2->val[i]);
//            }
//        }
//    }
//
//    dfs(obj->king);
//    *retSize = idx;
//    return ans;
//}
//
//void throneInheritanceFree(ThroneInheritance* obj)
//{
//    Inheritance* p1 = NULL, * tmp1 = NULL;
//    HASH_ITER(hh, obj -> edges, p1, tmp1)
//    {
//        HASH_DEL(obj->edges, p1);
//        free(p1->val);
//        free(p1);
//    }
//    Death* p2 = NULL, * tmp2 = NULL;
//    HASH_ITER(hh, obj -> dead, p2, tmp2)
//    {
//        HASH_DEL(obj->dead, p2);
//        free(p2);
//    }
//}
//
///**
// * Your ThroneInheritance struct will be instantiated and called as such:
// * ThroneInheritance* obj = throneInheritanceCreate(kingName);
// * throneInheritanceBirth(obj, parentName, childName);
//
// * throneInheritanceDeath(obj, name);
//
// * char** param_3 = throneInheritanceGetInheritanceOrder(obj, retSize);
//
// * throneInheritanceFree(obj);
//*/
//
////1599. 经营摩天轮的最大利润    
//
//int minOperationsMaxProfit(int* customers, int customersSize, int boardingCost, int runningCost)
//{
//    if (runningCost > 4 * boardingCost)
//        return -1;
//    int ans = -1, wait = 0, sum = 0, max = 0, turns = 0;
//    for (int i = 0; i < customersSize; i++)
//    {
//        wait += customers[i];
//        int onset = fmin(4, wait);
//        sum += onset * boardingCost - runningCost;
//        wait -= onset;
//        turns++;
//        if (sum > max)
//        {
//            ans = turns;
//            max = sum;
//        }
//    }
//    while (wait > 0)
//    {
//        int onset = fmin(4, wait);
//        sum += onset * boardingCost - runningCost;
//        wait -= onset;
//        turns++;
//        if (sum > max)
//        {
//            ans = turns;
//            max = sum;
//        }
//    }
//    return ans;
//}
//
//int minOperationsMaxProfit(int* customers, int customersSize, int boardingCost, int runningCost)
//{
//    if (runningCost > 4 * boardingCost)
//        return -1;
//    int ans = -1, wait = 0, sum = 0, max = 0, turns = 0;
//    for (int i = 0; i < customersSize; i++)
//    {
//        wait += customers[i];
//        int onset = fmin(4, wait);
//        sum += onset * boardingCost - runningCost;
//        wait -= onset;
//        turns++;
//        if (sum > max)
//        {
//            ans = turns;
//            max = sum;
//        }
//    }
//    int onsets = wait / 4;
//    sum += onsets * (4 * boardingCost - runningCost);
//    turns += onsets;
//    if (sum > max)
//    {
//        ans = turns;
//        max = sum;
//    }
//    wait -= onsets * 4;
//    sum += wait * boardingCost - runningCost;
//    if (sum > max)
//    {
//        ans = ++turns;
//        max = sum;
//    }
//    return ans;
//}
//
////1615. 最大网络秩
//
//int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize)
//{
//    int connect[n][n];
//    memset(connect, 0, sizeof(connect));
//    int cnt[n];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < roadsSize; i++)
//    {
//        int x = roads[i][0];
//        int y = roads[i][1];
//        connect[x][y] = 1;
//        connect[y][x] = 1;
//        cnt[x]++;
//        cnt[y]++;
//    }
//    int ans = 0;
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            ans = fmax(cnt[i] + cnt[j] - connect[i][j], ans);
//        }
//    }
//    return ans;
//}
//
////1640. 能否连接形成数组
//
//int** tmp;
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1;
//    int b = *(int*)e2;
//    return tmp[a][0] - tmp[b][0];
//}
//bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize)
//{
//    int idx[piecesSize];
//    for (int i = 0; i < piecesSize; i++)
//    {
//        idx[i] = i;
//    }
//    tmp = pieces;
//    qsort(idx, piecesSize, sizeof(int), cmp);
//    for (int i = 0; i < arrSize; )
//    {
//        int l = 0, r = piecesSize - 1;
//        while (l <= r)
//        {
//            int mid = (l + r) / 2;
//            if (pieces[idx[mid]][0] >= arr[i])
//                r = mid - 1;
//            else
//                l = mid + 1;
//        }
//        //printf("%d\n", l);
//        if (l >= piecesSize || pieces[idx[l]][0] != arr[i])
//            return false;
//        int len = piecesColSize[idx[l]];
//        //printf("%d %d\n", i, len);
//        for (int j = 1; j < len; j++)
//        {
//            if (arr[i + j] != pieces[idx[l]][j])
//                return false;
//        }
//        i += len;
//    }
//    return true;
//}
//
