////2685. 统计完全连通分量的数量
//
//int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize)
//{
//    int grid[n][n];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][len[x]++] = y;
//        grid[y][len[y]++] = x;
//    }
//
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//    int ans = 0, v, e;
//    void dfs(int x)
//    {
//        vis[x] = true;
//        v++;
//        e += len[x];
//
//        for (int j = 0; j < len[x]; j++)
//        {
//            int y = grid[x][j];
//            if (!vis[y])
//                dfs(y);
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (!vis[i])
//        {
//            v = 0;
//            e = 0;
//            dfs(i);
//            ans += (e == v * (v - 1));
//        }
//    }
//    return ans;
//}
//
////2192. 有向无环图中一个节点的所有祖先    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** getAncestors(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes)
//{
//    int grid[n][n];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][len[x]++] = y;
//    }
//
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * (n - 1));
//        (*returnColumnSizes)[i] = 0;
//    }
//
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//
//    void dfs(int x, int cur)
//    {
//        vis[x] = true;
//        if (x != cur)
//            ans[x][(*returnColumnSizes)[x]++] = cur;
//        for (int j = 0; j < len[x]; j++)
//        {
//            int y = grid[x][j];
//            if (!vis[y])
//            {
//                dfs(y, cur);
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        //printf("%d %d\n", i, vis[i]);
//        if (!vis[i])
//        {
//            dfs(i, i);
//            memset(vis, 0, sizeof(vis));
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3243. 新增道路查询后的最短距离 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int grid[n][n - 1];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < n - 1; i++)
//    {
//        grid[i][len[i]++] = i + 1;
//    }
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//
//    int bfs()
//    {
//        int queue[n];
//        int front = 0, rear = 0;
//        queue[rear++] = 0;
//        vis[0] = true;
//        int ret = 0;
//        while (rear > front)
//        {
//            ret++;
//            int start = front;
//            front = rear;
//            for (int i = start; i < front; i++)
//            {
//                int x = queue[i];
//                for (int j = 0; j < len[x]; j++)
//                {
//                    int y = grid[x][j];
//                    if (y == n - 1)
//                        return ret;
//                    if (!vis[y])
//                    {
//                        vis[y] = true;
//                        queue[rear++] = y;
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans[i] = n;
//        int x = queries[i][0], y = queries[i][1];
//        grid[x][len[x]++] = y;
//        ans[i] = fmin(bfs(), ans[i]);
//        memset(vis, 0, sizeof(vis));
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////1311. 获取你好友已观看的视频
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    char* key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int cmp(HashItem* e1, HashItem* e2)
//{
//    return e1->val == e2->val ? strcmp(e1->key, e2->key) : e1->val - e2->val;
//}
//char** watchedVideosByFriends(char*** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize)
//{
//    int n = watchedVideosSize;
//    int grid[n][n - 1];
//    int len[n];
//    memset(len, 0, sizeof(len));
//    for (int i = 0; i < friendsSize; i++)
//    {
//        for (int j = 0; j < friendsColSize[i]; j++)
//        {
//            grid[i][len[i]++] = friends[i][j];
//        }
//    }
//
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//
//    int queue[n];
//    int front = 0, rear = 0;
//    queue[rear++] = id;
//    vis[id] = true;
//    int l = 0;
//    while (rear > front && l < level)
//    {
//        l++;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = queue[i];
//            for (int j = 0; j < len[x]; j++)
//            {
//                int y = grid[x][j];
//                if (!vis[y])
//                {
//                    vis[y] = true;
//                    queue[rear++] = y;
//                }
//            }
//        }
//    }
//    HashItem* cnt = NULL;
//    for (int i = front; i < rear; i++)
//    {
//        int x = queue[i];
//        for (int j = 0; j < watchedVideosColSize[x]; j++)
//        {
//            char* video = watchedVideos[x][j];
//            HashItem* p = NULL;
//            HASH_FIND_STR(cnt, video, p);
//            if (p == NULL)
//            {
//                p = (HashItem*)malloc(sizeof(HashItem));
//                p->key = video;
//                p->val = 0;
//                HASH_ADD_STR(cnt, key, p);
//            }
//            p->val++;
//        }
//    }
//    HASH_SORT(cnt, cmp);
//    int capacity = 64;
//    char** ans = (char**)malloc(sizeof(char*) * capacity);
//    *returnSize = 0;
//    HashItem* p = NULL;
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, cnt, p, tmp)
//    {
//        if (*returnSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (char**)realloc(ans, sizeof(char*) * capacity);
//        }
//        ans[(*returnSize)++] = p->key;
//        HASH_DEL(cnt, p);
//        free(p);
//    }
//    return ans;
//}
//
