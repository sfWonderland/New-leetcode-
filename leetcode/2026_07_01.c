//// 886. 可能的二分法
//
//bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize)
//{
//    int** grid = (int**)malloc(sizeof(int*) * (n + 1));
//    int* capacity = (int*)malloc(sizeof(int) * (n + 1));
//    int* len = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 0; i < dislikesSize; i++)
//    {
//        int x = dislikes[i][0];
//        int y = dislikes[i][1];
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
//    int col[n + 1];
//    memset(col, 0, sizeof(col));
//    bool dfs(int start, int c)
//    {
//        col[start] = c;
//        for (int i = 0; i < len[start]; i++)
//        {
//            int y = grid[start][i];
//            if (col[y] != -c)
//            {
//                if (col[y] == c || (col[y] == 0 && !dfs(y, -c)))
//                    return false;
//            }
//        }
//        return true;
//    }
//    bool ans = true;
//    for (int i = 1; i <= n; i++)
//    {
//        if (col[i] == 0 && !dfs(i, 1))
//        {
//            ans = false;
//            break;
//        }
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        free(grid[i]);
//    }
//    free(grid);
//    free(capacity);
//    free(len);
//    return ans;
//}
//
