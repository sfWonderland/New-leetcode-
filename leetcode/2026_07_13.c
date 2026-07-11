//// 210. 课程表 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
//{
//    int n = numCourses;
//    // 记录入度
//    int edge[n];
//    memset(edge, 0, sizeof(edge));
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        len[i] = 0;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < prerequisitesSize; i++)
//    {
//        int x = prerequisites[i][0], y = prerequisites[i][1];
//        grid[y][len[y]++] = x;
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//        edge[x]++;
//    }
//    // 将入度为0的点加入队列
//    int* queue = (int*)malloc(sizeof(int) * numCourses);
//    int rear = 0, front = 0;
//    for (int i = 0; i < numCourses; i++)
//    {
//        if (edge[i] == 0)
//            queue[rear++] = i;
//    }
//    int* ans = (int*)malloc(sizeof(int) * numCourses);
//    int ansSize = 0;
//    while (rear > front)
//    {
//        int cur = queue[front++];
//        ans[ansSize++] = cur;
//        for (int i = 0; i < len[cur]; i++)
//        {
//            int x = grid[cur][i];
//            edge[x]--;
//            if (edge[x] == 0)
//                queue[rear++] = x;
//        }
//    }
//    bool empty = true;
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//        if (edge[i])
//            empty = false;
//    }
//    free(grid);
//    free(capacity);
//    free(len);
//    *returnSize = empty ? ansSize : 0;
//    return ans;
//}
//
