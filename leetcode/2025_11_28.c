////2872. 可以被 K 整除连通块的最大数目
//
//int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k)
//{
//    int** tree = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        tree[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        tree[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            tree[x] = (int*)realloc(tree[x], sizeof(int) * capacity[x]);
//        }
//        tree[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            tree[y] = (int*)realloc(tree[y], sizeof(int) * capacity[y]);
//        }
//    }
//    int ans = 0;
//    long long dfs(int x, int fa)
//    {
//        long long sum = values[x];
//        for (int i = 0; i < len[x]; i++)
//        {
//            if (tree[x][i] != fa)
//                sum += dfs(tree[x][i], x);
//        }
//        ans += sum % k == 0;
//        return sum;
//    }
//    dfs(0, -1);
//    return ans;
//}
//
////1971. 寻找图中是否存在路径
//
//bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination)
//{
//    int** route = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        route[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
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
//    bool dfs(int sr, int dest)
//    {
//        if (sr == dest)
//            return true;
//        vis[sr] = true;
//        for (int i = 0; i < len[sr]; i++)
//        {
//            if (!vis[route[sr][i]] && dfs(route[sr][i], dest))
//                return true;
//        }
//        return false;
//    }
//    return dfs(source, destination);
//}
//
////1306. 跳跃游戏 III
//
//bool canReach(int* arr, int arrSize, int start)
//{
//    bool* vis = (bool*)calloc(sizeof(bool), arrSize);
//    bool dfs(int x)
//    {
//        if (arr[x] == 0)
//            return true;
//        vis[x] = true;
//        bool a = false, b = false;
//        if (x + arr[x] < arrSize && !vis[x + arr[x]])
//            a = dfs(x + arr[x]);
//        if (x - arr[x] >= 0 && !vis[x - arr[x]])
//            b = dfs(x - arr[x]);
//        //printf("%d %d %d\n", x, a, b);
//        return a | b;
//    }
//    return dfs(start);
//}
//
////2316. 统计无向图中无法互相到达点对数
//
//long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    int** route = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)calloc(sizeof(int), n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        route[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
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
//    int dfs(int x)
//    {
//        vis[x] = true;
//        int size = 1;
//        for (int i = 0; i < len[x]; i++)
//        {
//            if (!vis[route[x][i]])
//                size += dfs(route[x][i]);
//        }
//        return size;
//    }
//    long long ans = 0;
//    for (int i = 0, total = 0; i < n; i++)
//    {
//        if (!vis[i])
//        {
//            int size = dfs(i);
//            ans += 1ll * size * total;
//            total += size;
//        }
//    }
//    return ans;
//}
//
