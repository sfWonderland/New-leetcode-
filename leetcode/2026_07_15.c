//// 2392. 给定条件下构造矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//bool getNum(int* res, int n, int** edges, int edgesSize)
//{
//    int m = edgesSize;
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    int* len = (int*)malloc(sizeof(int) * n);
//    int* cnt = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//        cnt[i] = 0;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int x = edges[i][0] - 1, y = edges[i][1] - 1;
//        grid[x][len[x]++] = y;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        cnt[y]++;
//    }
//    int* queue = (int*)malloc(sizeof(int) * n);
//    int rear = 0, front = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (cnt[i] == 0)
//            queue[rear++] = i;
//    }
//    int k = 0;
//    while (rear > front)
//    {
//        int x = queue[front++];
//        res[x] = k++;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            if (--cnt[y] == 0)
//                queue[rear++] = y;
//        }
//    }
//    bool valid = true;
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//        if (cnt[i])
//        {
//            valid = false;
//            break;
//        }
//    }
//    free(grid);
//    free(capacity);
//    free(len);
//    free(cnt);
//    free(queue);
//    return valid;
//}
//int** buildMatrix(int k, int** rowConditions, int rowConditionsSize, int* rowConditionsColSize, int** colConditions, int colConditionsSize, int* colConditionsColSize, int* returnSize, int** returnColumnSizes)
//{
//    int* kRow = (int*)malloc(sizeof(int) * k);
//    int* kCol = (int*)malloc(sizeof(int) * k);
//    if (!getNum(kRow, k, rowConditions, rowConditionsSize)
//        || !getNum(kCol, k, colConditions, colConditionsSize))
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * k);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//    {
//        ans[i] = (int*)calloc(sizeof(int), k);
//        (*returnColumnSizes)[i] = k;
//    }
//    for (int i = 0; i < k; i++)
//    {
//        int x = kRow[i], y = kCol[i];
//        ans[x][y] = i + 1;
//    }
//    *returnSize = k;
//    return ans;
//}
//
