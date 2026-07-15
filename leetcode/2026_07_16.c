//// 802. 找到最终的安全状态
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize)
//{
//    int n = graphSize;
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    int* queue = (int*)malloc(sizeof(int) * n);
//    int rear = 0, front = 0;
//    int* cnt = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[i] = graphColSize[i];
//        if (cnt[i] == 0)
//            queue[rear++] = i;
//
//        for (int j = 0; j < cnt[i]; j++)
//        {
//            int y = graph[i][j];
//            grid[y][len[y]++] = i;
//            if (len[y] >= capacity[y])
//            {
//                capacity[y] *= 2;
//                grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//            }
//        }
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int ansSize = 0;
//    while (rear > front)
//    {
//        int x = queue[front++];
//        ans[ansSize++] = x;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            if (--cnt[y] == 0)
//                queue[rear++] = y;
//        }
//    }
//    qsort(ans, ansSize, sizeof(int), cmp);
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(capacity);
//    free(len);
//    free(cnt);
//    free(grid);
//    free(queue);
//    *returnSize = ansSize;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize)
//{
//    int n = graphSize;
//    int vis[n];
//    memset(vis, 0, sizeof(vis));
//    int* ans = (int*)malloc(sizeof(int) * n);
//    *returnSize = 0;
//    bool dfs(int i)
//    {
//        if (vis[i])
//            return vis[i] == 2;
//
//        vis[i] = 1;
//        for (int j = 0; j < graphColSize[i]; j++)
//        {
//            int y = graph[i][j];
//            if (vis[y] == 0)
//            {
//                if (!dfs(y))
//                    return false;
//            }
//            else if (vis[y] == 1)
//                return false;
//        }
//        vis[i] = 2;
//        return true;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (vis[i] == 0)
//        {
//            if (dfs(i))
//                ans[(*returnSize)++] = i;
//        }
//        else if (vis[i] == 2)
//            ans[(*returnSize)++] = i;
//    }
//    return ans;
//}
//
