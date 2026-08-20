//// 417. 太平洋大西洋水流问题
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//void dfs(int x, int y, int** heights, int m, int n, bool** vis)
//{
//    if (vis[x][y]) return;
//    vis[x][y] = true;
//    for (int k = 0; k < 4; k++)
//    {
//        int mx = dir[k][0] + x;
//        int my = dir[k][1] + y;
//        if (mx >= 0 && mx < m && my >= 0 && my < n && heights[mx][my] >= heights[x][y])
//            dfs(mx, my, heights, m, n, vis);
//    }
//}
//int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = heightsSize, n = heightsColSize[0];
//    bool** pacific_vis = (bool**)malloc(sizeof(bool*) * m);
//    bool** atlantic_vis = (bool**)malloc(sizeof(bool*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        pacific_vis[i] = (bool*)calloc(sizeof(bool), n);
//        atlantic_vis[i] = (bool*)calloc(sizeof(bool), n);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        dfs(i, 0, heights, m, n, pacific_vis);
//        dfs(i, n - 1, heights, m, n, atlantic_vis);
//    }
//    for (int j = 0; j < n; j++)
//    {
//        dfs(0, j, heights, m, n, pacific_vis);
//        dfs(m - 1, j, heights, m, n, atlantic_vis);
//    }
//    int** ans = (int**)malloc(sizeof(int*) * m * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
//    *returnSize = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (pacific_vis[i][j] && atlantic_vis[i][j])
//            {
//                ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
//                ans[*returnSize][0] = i;
//                ans[*returnSize][1] = j;
//                (*returnColumnSizes)[(*returnSize)++] = 2;
//            }
//        }
//    }
//    free(pacific_vis);
//    free(atlantic_vis);
//    return ans;
//}
//
