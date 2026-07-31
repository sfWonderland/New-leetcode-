//// 851. 喧闹和富有
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize)
//{
//    int n = quietSize;
//    bool grid[n][n];
//    memset(grid, 0, sizeof(grid));
//    int cnt[n]; // 入度 richer -> poorer
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < richerSize; i++)
//    {
//        int x = richer[i][0];
//        int y = richer[i][1];
//        grid[x][y] = true;
//        cnt[y]++;
//    }
//    int queue[n];
//    int rear = 0, front = 0;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = i;
//        if (cnt[i] == 0)
//            queue[rear++] = i;
//    }
//    while (rear > front)
//    {
//        int x = queue[front++];
//        for (int y = 0; y < n; y++)
//        {
//            if (grid[x][y])
//            {
//                if (quiet[ans[x]] < quiet[ans[y]])
//                    ans[y] = ans[x];
//                if (--cnt[y] == 0)
//                    queue[rear++] = y;
//            }
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
