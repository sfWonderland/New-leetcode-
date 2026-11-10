//// 210. ¿Î³Ì±í II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
//{
//    int n = numCourses;
//    int* cnt = (int*)malloc(sizeof(int) * n);
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        len[i] = 0;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        cnt[i] = 0;
//    }
//    for (int i = 0; i < prerequisitesSize; i++)
//    {
//        int x = prerequisites[i][0], y = prerequisites[i][1];
//        grid[y][len[y]++] = x;
//        if (len[y] == capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//        cnt[x]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int rear = 0, front = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (cnt[i]) continue;
//        ans[rear++] = i;
//    }
//    while (rear > front)
//    {
//        int x = ans[front++];
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            cnt[y]--;
//            if (cnt[y]) continue;
//            ans[rear++] = y;
//        }
//    }
//    *returnSize = front < n ? 0 : n;
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(grid);
//    free(capacity);
//    free(len);
//    free(cnt);
//    return ans;
//}
//
