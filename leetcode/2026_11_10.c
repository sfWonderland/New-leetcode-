//// 1971. 寻找图中是否存在路径
//
//bool dfs(int** grid, int* len, bool* vis, int source, int dest)
//{
//    if (source == dest) return true;
//    vis[source] = true;
//    for (int i = 0; i < len[source]; i++)
//    {
//        int y = grid[source][i];
//        if (!vis[y] && dfs(grid, len, vis, y, dest))
//            return true;
//    }
//    return false;
//}
//bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination)
//{
//    if (source == destination) return true;
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 64;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        grid[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//    }
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    bool ans = dfs(grid, len, vis, source, destination);
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(grid);
//    free(len);
//    free(capacity);
//    return ans;
//}
//
//int find(int* parent, int x)
//{
//    int root = x;
//    while (parent[root] > 0)
//    {
//        root = parent[root];
//    }
//    while (x != root)
//    {
//        int tmp = parent[x];
//        parent[x] = root;
//        x = tmp;
//    }
//
//    return root;
//}
//void Union(int* parent, int a, int b)
//{
//    int root1 = find(parent, a);
//    int root2 = find(parent, b);
//    if (parent[root1] < parent[root2])
//    {
//        parent[root1] += parent[root2];
//        parent[root2] = root1;
//    }
//    else
//    {
//        parent[root2] += parent[root1];
//        parent[root1] = root2;
//    }
//}
//bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination)
//{
//    int parent[n];
//    for (int i = 0; i < n; i++)
//    {
//        parent[i] = -1;
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int a = edges[i][0];
//        int b = edges[i][1];
//        if (find(parent, a) != find(parent, b))
//            Union(parent, a, b);
//    }
//    return find(parent, source) == find(parent, destination);
//}
//
