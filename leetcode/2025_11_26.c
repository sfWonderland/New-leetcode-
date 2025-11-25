////2435. 矩阵中和能被 K 整除的路径
//
//const int mod = 1e9 + 7;
//int dfs(int** grid, int i, int j, int k, int r)
//{
//    if (i < 0 || j < 0)
//        return 0;
//
//    if (i == 0 && j == 0)
//        return (r + grid[i][j]) % k == 0;
//
//    return 1ll * (dfs(grid, i - 1, j, k, (r + grid[i][j]) % k) + dfs(grid, i, j - 1, k, (r + grid[i][j]) % k)) % mod;
//}
//int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k)
//{
//    return dfs(grid, gridSize - 1, gridColSize[0] - 1, k, 0);
//}
//
//const int mod = 1e9 + 7;
//int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k)
//{
//    int f[gridSize + 1][gridColSize[0] + 1][k];
//    for (int i = 0; i < gridSize + 1; i++)
//    {
//        for (int j = 0; j < k; j++)
//            f[i][0][j] = 0;
//    }
//    for (int i = 0; i < gridColSize[0] + 1; i++)
//    {
//        for (int j = 0; j < k; j++)
//            f[0][i][j] = 0;
//    }
//    f[0][1][0] = 1;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[0]; j++)
//        {
//            for (int l = 0; l < k; l++)
//            {
//                int new_r = (l + grid[i][j]) % k;
//                f[i + 1][j + 1][l] = 1ll * (f[i][j + 1][new_r] + f[i + 1][j][new_r]) % mod;
//            }
//        }
//    }
//    return f[gridSize][gridColSize[0]][0];
//}
//
////3679. 使库存平衡的最少丢弃次数
//
//int minArrivalsToDiscard(int* arrivals, int arrivalsSize, int w, int m)
//{
//    int cnt[100001] = { 0 };
//    int left = -1, ans = 0;
//    for (int i = 0; i < arrivalsSize; i++)
//    {
//        if (cnt[arrivals[i]] == m)
//        {
//            arrivals[i] = 0;
//            ans++;
//        }
//        else
//            cnt[arrivals[i]]++;
//
//        if (i < w - 1)
//            continue;
//
//        cnt[arrivals[i - w + 1]]--;
//    }
//    return ans;
//}
//
////3643. 垂直翻转子矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes)
//{
//    for (int i = y; i < y + k; i++)
//    {
//        int up = x, down = x + k - 1;
//        while (up < down)
//        {
//            swap(&grid[up][i], &grid[down][i]);
//            up++; down--;
//        }
//    }
//    *returnSize = gridSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
//    for (int i = 0; i < gridSize; i++)
//    {
//        (*returnColumnSizes)[i] = gridColSize[0];
//    }
//    return grid;
//}
//
////3708. 最长斐波那契子数组
//
//int longestSubarray(int* nums, int numsSize)
//{
//    int ans = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int j = fmin(i + 2, numsSize - 1);
//        for (; j < numsSize; j++)
//        {
//            if (nums[j] != nums[j - 1] + nums[j - 2])
//                break;
//        }
//        ans = fmax(ans, j - i);
//    }
//    return ans;
//}
//
//int longestSubarray(int* nums, int numsSize)
//{
//    int ans = 2, count = 2;
//    for (int i = 2; i < numsSize; i++)
//    {
//        if (nums[i] == nums[i - 1] + nums[i - 2])
//        {
//            count++;
//            ans = fmax(count, ans);
//        }
//        else
//            count = 2;
//    }
//    return ans;
//}
//
