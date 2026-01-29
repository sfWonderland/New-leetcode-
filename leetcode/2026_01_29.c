////1334. 阈值距离内邻居最少的城市
//
//int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
//{
//    int f[n + 1][n][n];
//    memset(f, 0, sizeof(f));
//    void setGrid(int value[][n])
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                value[i][j] = INT_MAX / 2;
//                //printf("%d ", value[i][j]);
//            }
//            //printf("\n");
//        }
//
//        for (int i = 0; i < edgesSize; i++)
//        {
//            int x = edges[i][0], y = edges[i][1];
//            value[x][y] = edges[i][2];
//            value[y][x] = edges[i][2];
//        }
//    }
//
//    setGrid(f[0]);
//
//
//    for (int k = 0; k < n; k++)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                int tmp = f[i][k] + f[k][j];
//                if (tmp < f[i][j])
//                    f[i][j] = tmp;
//                //printf("%d ", f[k][i][j]);
//            }
//            //printf("\n");
//        }
//        //printf("\n");
//    }
//    int ans = 0, min = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        int cnt = 0;
//        for (int j = 0; j < n; j++)
//        {
//            if (j != i && f[n][i][j] <= distanceThreshold)
//                cnt++;
//        }
//        if (cnt <= min)
//        {
//            min = cnt;
//            ans = i;
//        }
//    }
//    return ans;
//}
//
//int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
//{
//    const int INF = 0x3f3f3f3f3f;
//    int f[n][n];
//    memset(f, 0x3f, sizeof(f));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        f[x][y] = edges[i][2];
//        f[y][x] = edges[i][2];
//    }
//
//    for (int k = 0; k < n; k++)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            if (f[i][k] == INF)
//                continue;
//            for (int j = 0; j < n; j++)
//            {
//                int tmp = f[i][k] + f[k][j];
//                if (tmp < f[i][j])
//                    f[i][j] = tmp;
//            }
//        }
//    }
//    int ans = 0, min = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        int cnt = 0;
//        for (int j = 0; j < n; j++)
//        {
//            if (j != i && f[i][j] <= distanceThreshold)
//                cnt++;
//        }
//        if (cnt <= min)
//        {
//            min = cnt;
//            ans = i;
//        }
//    }
//    return ans;
//}
//
////2976. 转换字符串的最小成本 I    
//
//long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize)
//{
//    const int INF = 0x3f3f3f3f3f;
//    int f[26][26];
//    memset(f, 0x3f, sizeof(f));
//    for (int i = 0; i < 26; i++)
//    {
//        f[i][i] = 0;
//    }
//
//    for (int i = 0; i < originalSize; i++)
//    {
//        int x = original[i] - 'a';
//        int y = changed[i] - 'a';
//        f[x][y] = fmin(cost[i], f[x][y]);
//    }
//
//    for (int k = 0; k < 26; k++)
//    {
//        for (int i = 0; i < 26; i++)
//        {
//            // 巨大优化
//            if (f[i][k] == INF)
//                continue;
//            for (int j = 0; j < 26; j++)
//            {
//                int tmp = f[i][k] + f[k][j];
//                if (tmp < f[i][j])
//                    f[i][j] = tmp;
//            }
//        }
//    }
//
//    int n = strlen(source);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (source[i] == target[i])
//            continue;
//
//        int x = source[i] - 'a';
//        int y = target[i] - 'a';
//        if (f[x][y] == INF)
//            return -1;
//
//        ans += f[x][y];
//    }
//    return ans;
//}
//
////2642. 设计可以求最短路径的图类
//
//const int INF = 0x3f3f3f3f;
//
//typedef struct
//{
//    int** grid;
//    int n;
//} Graph;
//
//
//Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    Graph* obj = (Graph*)malloc(sizeof(Graph));
//    obj->grid = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        obj->grid[i] = (int*)malloc(sizeof(int) * n);
//        for (int j = 0; j < n; j++)
//        {
//            obj->grid[i][j] = i == j ? 0 : 0x3f3f3f3f;
//        }
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0];
//        int y = edges[i][1];
//        obj->grid[x][y] = edges[i][2];
//    }
//    for (int k = 0; k < n; k++)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            if (obj->grid[i][k] == INF)
//                continue;
//            for (int j = 0; j < n; j++)
//            {
//                int tmp = obj->grid[i][k] + obj->grid[k][j];
//                if (tmp < obj->grid[i][j])
//                    f[i][j] = tmp;
//                obj->grid[i][j] = tmp;
//            }
//        }
//    }
//
//    obj->n = n;
//    return obj;
//}
//
//void graphAddEdge(Graph* obj, int* edge, int edgeSize)
//{
//    int x = edge[0], y = edge[1], value = edge[2];
//    if (obj->grid[x][y] <= value)
//        return;
//    for (int i = 0; i < obj->n; i++)
//    {
//        for (int j = 0; j < obj->n; j++)
//        {
//            obj->grid[i][j] = fmin(obj->grid[i][j],
//                obj->grid[i][x] + value + obj->grid[y][j]);
//        }
//    }
//}
//
//int graphShortestPath(Graph* obj, int node1, int node2)
//{
//    return obj->grid[node1][node2] == INF ? -1 : obj->grid[node1][node2];
//}
//
//void graphFree(Graph* obj)
//{
//    for (int i = 0; i < obj->n; i++)
//    {
//        free(obj->grid[i]);
//    }
//    free(obj->grid);
//    free(obj);
//}
//
///**
// * Your Graph struct will be instantiated and called as such:
// * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
// * graphAddEdge(obj, edge, edgeSize);
//
// * int param_2 = graphShortestPath(obj, node1, node2);
//
// * graphFree(obj);
//*/
//
////743. 网络延迟时间
//
//int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
//{
//    const int INF = 0x3f3f3f3f;
//    int grid[n][n];
//    memset(grid, 0x3f, sizeof(grid));
//    for (int i = 0; i < timesSize; i++)
//    {
//        int x = times[i][0] - 1, y = times[i][1] - 1, w = times[i][2];
//        grid[x][y] = w;
//    }
//
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//    int dis[n];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[k - 1] = 0;
//    while (1)
//    {
//        int ans = 0;
//        int x = -1;
//        for (int i = 0; i < n; i++)
//        {
//            if (dis[i] < INF)
//                ans = fmax(ans, dis[i]);
//            if (vis[i])
//                continue;
//            if (x == -1 || dis[i] < dis[x])
//                x = i;
//        }
//
//        if (x == -1)
//            return ans;
//
//        if (dis[x] == INF)
//            return -1;
//
//        vis[x] = true;
//        for (int y = 0; y < n; y++)
//        {
//            int new_dis = dis[x] + grid[x][y];
//            if (dis[y] > new_dis)
//                dis[y] = new_dis;
//        }
//    }
//    return -1;
//}
//
//struct Node
//{
//    int x;
//    int wt;
//    struct Node* next;
//};
//
//void up(int heap[][2], int i)
//{
//    int x = heap[i][1], wt = heap[i][0];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j][0] <= wt)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i][1] = x;
//    heap[i][0] = wt;
//}
//
//void down(int heap[][2], int i, int n)
//{
//    int x = heap[i][1], wt = heap[i][0];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1][0] < heap[j][0])
//            j++;
//        if (heap[j][0] >= wt)
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        i = j;
//    }
//    heap[i][1] = x;
//    heap[i][0] = wt;
//}
//
//int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
//{
//    const int INF = 0x3f3f3f3f;
//    struct Node* grid[n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < timesSize; i++)
//    {
//        int x = times[i][0] - 1, y = times[i][1] - 1, w = times[i][2];
//        struct Node* nxt = grid[x];
//        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
//        new->x = y;
//        new->wt = w;
//        new->next = nxt;
//        grid[x] = new;
//    }
//
//    int dis[n];
//    memset(dis, 0x3f, sizeof(dis));
//    dis[k - 1] = 0;
//    int heap[1000][2];
//    int heapSize = 0;
//    heap[heapSize][0] = 0;
//    heap[heapSize++][1] = k - 1;
//    while (heapSize)
//    {
//        int wt = heap[0][0], x = heap[0][1];
//        heap[0][0] = heap[heapSize - 1][0];
//        heap[0][1] = heap[--heapSize][1];
//        down(heap, 0, heapSize);
//        if (wt > dis[x])
//            continue;
//
//        int ans = 0;
//        for (struct Node* cur = grid[x]; cur != NULL; cur = cur->next)
//        {
//            int y = cur->x;
//            int new_dis = wt + cur->wt;
//            if (new_dis < dis[y])
//            {
//                dis[y] = new_dis;
//                heap[heapSize][0] = new_dis;
//                heap[heapSize++][1] = y;
//                up(heap, heapSize - 1);
//            }
//        }
//    }
//    int mx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (dis[i] == INF)
//            return -1;
//        if (mx < dis[i])
//            mx = dis[i];
//    }
//    return mx;
//}
//
