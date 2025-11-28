////1319. 连通网络的操作次数
//
//int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize)
//{
//    if (connectionsSize < n - 1)
//        return -1;
//
//    int** route = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)calloc(sizeof(int), n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        route[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < connectionsSize; i++)
//    {
//        int x = connections[i][0], y = connections[i][1];
//        route[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            route[x] = (int*)realloc(route[x], sizeof(int) * capacity[x]);
//        }
//        route[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            route[y] = (int*)realloc(route[y], sizeof(int) * capacity[y]);
//        }
//    }
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    void dfs(int x)
//    {
//        if (vis[x])
//            return;
//
//        vis[x] = true;
//        for (int i = 0; i < len[x]; i++)
//        {
//            dfs(route[x][i]);
//        }
//    }
//    int ans = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i])
//        {
//            dfs(i);
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2492. 两个城市间路径的最小分数
//
//int minScore(int n, int** roads, int roadsSize, int* roadsColSize)
//{
//    int** route = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)calloc(sizeof(int), n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        route[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < roadsSize; i++)
//    {
//        int x = roads[i][0] - 1, y = roads[i][1] - 1, z = roads[i][2];
//        route[x][len[x]++] = y * 10000 + z - 1;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            route[x] = (int*)realloc(route[x], sizeof(int) * capacity[x]);
//        }
//        //printf("%d %d\n", len[y] + 1, x * 10000 + z - 1);
//        route[y][len[y]++] = x * 10000 + z - 1;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            route[y] = (int*)realloc(route[y], sizeof(int) * capacity[y]);
//        }
//    }
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    int dfs(int x)
//    {
//        vis[x] = true;
//        int min = 10000;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = route[x][i] / 10000, z = route[x][i] % 10000 + 1;
//            if (!vis[y])
//                z = fmin(dfs(y), z);
//
//            min = fmin(z, min);
//            // printf("%d %d\n", x, min);
//        }
//        return min;
//    }
//    return dfs(0);
//}
//
////3310. 移除可疑的方法
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize)
//{
//    int** route = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)calloc(sizeof(int), n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        route[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < invocationsSize; i++)
//    {
//        int x = invocations[i][0], y = invocations[i][1];
//        route[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            route[x] = (int*)realloc(route[x], sizeof(int) * capacity[x]);
//        }
//    }
//    int* vis = (int*)calloc(sizeof(int), n);
//    void dfs(int x, bool flag)
//    {
//        vis[x] |= 1 << flag;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = route[x][i];
//            if (!(vis[y] & (1 << flag)))
//                dfs(y, flag);
//        }
//    }
//    dfs(k, 1);
//    for (int i = 0; i < n; i++)
//    {
//        if (vis[i] != 2)
//            dfs(i, 0);
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        //printf("%d ", vis[i]);
//        if (vis[i] == 3)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                ans[j] = j;
//            }
//            *returnSize = n;
//            return ans;
//        }
//        if (vis[i] != 2)
//            ans[idx++] = i;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////3649. 完美对的数目
//
////max <= 2 * min
////大致思路：由于取绝对值，下标正反都成立。左式为两个端点到原点的距离之和或者差, 右式为两个端点到原点的最大距离；
////距离之差就是最大距离减去最小距离，比较距离之差和最小的距离，就是比较最大距离和最小距离的二倍，小于则式子1成立；
////很明显距离之和一定更大，而且不小于两个端点到原点的距离，式子2一定成立
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long perfectPairs(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; ++i)
//    {
//        nums[i] = abs(nums[i]);
//    }
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long ans = 0;
//    int left = 0;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        while (nums[left] * 2 < nums[i])
//            left++;
//
//        ans += i - left;
//    }
//    return ans;
//}
//
