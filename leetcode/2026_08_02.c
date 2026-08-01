//// 2050. 并行课程 III
//
//int minimumTime(int n, int** relations, int relationsSize, int* relationsColSize, int* time, int timeSize)
//{
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    // cnt 入度个数， in_vals 各入度时间最大值
//    int capacity[n], len[n], cnt[n], in_vals[n];
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0; cnt[i] = 0; in_vals[i] = time[i];
//    }
//    for (int i = 0; i < relationsSize; i++)
//    {
//        int x = relations[i][0] - 1;
//        int y = relations[i][1] - 1;
//        grid[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        cnt[y]++;
//    }
//    int queue[n];
//    int rear = 0, front = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (cnt[i] == 0)
//            queue[rear++] = i;
//    }
//    while (rear > front)
//    {
//        int x = queue[front++];
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            in_vals[y] = fmax(in_vals[y], in_vals[x] + time[y]);
//            if (--cnt[y] == 0)
//                queue[rear++] = y;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//        ans = fmax(ans, in_vals[i]);
//    }
//    free(grid);
//    return ans;
//}
//
