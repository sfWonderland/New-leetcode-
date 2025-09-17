////1162. 地图分析
//
//typedef struct
//{
//    int x;
//    int y;
//}graph;
//int maxDistance(int** grid, int gridSize, int* gridColSize)
//{
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    int m = gridSize, n = gridColSize[0];
//    graph queue[m * n];
//    int top = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j])
//            {
//                queue[top].x = i;
//                queue[top++].y = j;
//            }
//        }
//    }
//    if (top == 0) return -1;
//    bool hasOcean = false;
//    int bottom = 0;
//    int x0 = 0, y0 = 0;
//    while (top > bottom)
//    {
//        x0 = queue[bottom].x;
//        y0 = queue[bottom++].y;
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x0 + dx[i];
//            int my = y0 + dy[i];
//            if (mx < 0 || mx >= m || my < 0 || my >= n || grid[mx][my])
//                continue;
//
//            grid[mx][my] = grid[x0][y0] + 1;
//            hasOcean = true;
//            queue[top].x = mx;
//            queue[top++].y = my;
//        }
//    }
//    if (!hasOcean) return -1;
//    return grid[x0][y0] - 1;
//}
//
////542. 01 矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
//{
//    row = matSize, col = matColSize[0];
//    int queue[row * col][2];
//    int top = 0;
//    *returnSize = row;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
//    for (int i = 0; i < row; i++)
//    {
//        (*returnColumnSizes)[i] = col;
//        for (int j = 0; j < col; j++)
//        {
//            if (!mat[i][j])
//            {
//                queue[top][0] = i;
//                queue[top++][1] = j;
//            }
//            else
//                mat[i][j] = INT_MAX;
//        }
//    }
//    int bottom = 0;
//    while (top > bottom)
//    {
//        int x = queue[bottom][0];
//        int y = queue[bottom++][1];
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dx[i];
//            int my = y + dy[i];
//            if (mx < 0 || mx >= row || my < 0 || my >= col || mat[mx][my] <= mat[x][y] + 1)
//                continue;
//            mat[mx][my] = mat[x][y] + 1;
//            queue[top][0] = mx;
//            queue[top++][1] = my;
//        }
//    }
//    return mat;
//}
//
////994. 腐烂的橘子
//
//int orangesRotting(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    int queue[m * n][2];
//    int top = 0;
//    int zeros = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j] == 2)
//            {
//                queue[top][0] = i;
//                queue[top++][1] = j;
//            }
//            else if (!grid[i][j])
//                zeros++;
//        }
//    }
//    if (zeros == m * n) return 0;
//    if (!top) return -1;
//    int bottom = 0;
//    int time = 0;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int i = start; i < bottom; i++)
//        {
//            int x = queue[i][0];
//            int y = queue[i][1];
//            for (int j = 0; j < 4; j++)
//            {
//                int mx = x + dx[j];
//                int my = y + dy[j];
//                if (mx < 0 || mx >= m || my < 0 || my >= n || grid[mx][my] != 1)
//                    continue;
//
//                grid[mx][my] += 1;
//                queue[top][0] = mx;
//                queue[top++][1] = my;
//            }
//        }
//        time++;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j] == 1)
//                return -1;
//        }
//    }
//
//    return time - 1;
//}
//
////1765. 地图中的最高点
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = isWaterSize, n = isWaterColSize[0];
//    int queue[m * n][2];
//    int top = 0;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//        for (int j = 0; j < n; j++)
//        {
//            if (isWater[i][j])
//            {
//                isWater[i][j] = 0;
//                queue[top][0] = i;
//                queue[top++][1] = j;
//            }
//            else
//                isWater[i][j] = INT_MAX;
//        }
//    }
//    int dx[4] = { -1, 1, 0, 0 };
//    int dy[4] = { 0, 0, -1, 1 };
//    int bottom = 0;
//    while (top > bottom)
//    {
//        int x = queue[bottom][0];
//        int y = queue[bottom++][1];
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dx[i];
//            int my = y + dy[i];
//            if (mx < 0 || mx >= m || my < 0 || my >= n || isWater[mx][my] <= isWater[x][y] + 1)
//                continue;
//
//            isWater[mx][my] = isWater[x][y] + 1;
//            queue[top][0] = mx;
//            queue[top++][1] = my;
//        }
//    }
//    *returnSize = m;
//    return isWater;
//}
//
