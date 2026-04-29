//// LCR 105. 岛屿的最大面积
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int dfs(int** grid, int x, int y, int m, int n)
//{
//    grid[x][y] = 2;
//    int size = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dir[i][0];
//        int my = y + dir[i][1];
//
//        if (mx < 0 || mx >= m || my < 0 || my >= n || grid[mx][my] != 1)
//            continue;
//
//        size += dfs(grid, mx, my, m, n);
//    }
//    return size;
//}
//int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j] == 1)
//                ans = fmax(ans, dfs(grid, i, j, m, n));
//        }
//    }
//    return ans;
//}
//
//// LCR 107. 01 矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = matSize, n = matColSize[0];
//    int queue[m * n][2];
//    int rear = 0, front = 0;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//        for (int j = 0; j < n; j++)
//        {
//            if (!mat[i][j])
//            {
//                queue[rear][0] = i;
//                queue[rear++][1] = j;
//            }
//            else
//            {
//                mat[i][j] = INT_MAX;
//            }
//        }
//    }
//    while (rear > front)
//    {
//        int x = queue[front][0];
//        int y = queue[front++][1];
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dir[i][0];
//            int my = y + dir[i][1];
//
//            if (mx < 0 || mx >= m || my < 0 || my >= n || mat[mx][my] <= mat[x][y] + 1)
//                continue;
//
//            mat[mx][my] = mat[x][y] + 1;
//            queue[rear][0] = mx;
//            queue[rear++][1] = my;
//        }
//    }
//    *returnSize = m;
//    return mat;
//}
//
//// LCR 110. 所有可能的路径
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* len;
//int* path;
//int pathSize;
//void dfs(int** graph, int graphSize, int* graphColSize, int i)
//{
//    path[pathSize++] = i;
//    if (i == graphSize - 1)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * pathSize);
//        len[ansSize] = pathSize;
//        memcpy(ans[ansSize], path, sizeof(int) * pathSize);
//        ansSize++;
//        return;
//    }
//
//    for (int j = 0; j < graphColSize[i]; j++)
//    {
//        dfs(graph, graphSize, graphColSize, graph[i][j]);
//        pathSize--;
//    }
//}
//int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)
//{
//    ans = (int**)malloc(sizeof(int*) * 8000);
//    len = (int*)malloc(sizeof(int) * 8000);
//    ansSize = 0;
//    path = (int*)malloc(sizeof(int) * graphSize);
//    pathSize = 0;
//    dfs(graph, graphSize, graphColSize, 0);
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
//// LCR 116. 省份数量
//
//int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
//{
//    int n = isConnectedSize;
//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
//    int ans = 0;
//    void dfs(int i)
//    {
//        vis[i] = true;
//        for (int j = 0; j < n; j++)
//        {
//            if (isConnected[i][j] && !vis[j])
//            {
//                dfs(j);
//            }
//        }
//    }
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
