//// 433. 最小基因变化
//
//int minMutation(char* startGene, char* endGene, char** bank, int bankSize)
//{
//    if (!strcmp(startGene, endGene)) return 0;
//    int n = bankSize;
//    int endId = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (endId == -1 && !strcmp(bank[i], endGene))
//            endId = i;
//    }
//    if (endId == -1)
//        return -1;
//    bool** grid = (bool**)malloc(sizeof(bool*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        grid[i] = (bool*)calloc(sizeof(bool), n);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            int diff = 0;
//            for (int k = 0; k < 8 && diff <= 1; k++)
//            {
//                diff += (bank[i][k] != bank[j][k]);
//            }
//            if (diff == 1)
//            {
//                grid[i][j] = true;
//                grid[j][i] = true;
//            }
//        }
//    }
//    int* queue = (int*)malloc(sizeof(int) * n);
//    int rear = 0, front = 0, step = 1;
//    bool* vis = (bool*)calloc(sizeof(bool), n);
//    for (int i = 0; i < n; i++)
//    {
//        int diff = 0;
//        for (int j = 0; j < 8 && diff <= 1; j++)
//        {
//            diff += (bank[i][j] != startGene[j]);
//        }
//        if (diff == 1)
//        {
//            queue[rear++] = i;
//            vis[i] = true;
//        }
//    }
//    while (rear > front && !vis[endId])
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = queue[i];
//            for (int j = 0; j < n; j++)
//            {
//                if (!grid[x][j] || vis[j]) continue;
//                queue[rear++] = j;
//                vis[j] = true;
//            }
//        }
//        step++;
//    }
//    int ans = vis[endId] ? step : -1;
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(grid);
//    free(queue);
//    free(vis);
//    return ans;
//}
//
