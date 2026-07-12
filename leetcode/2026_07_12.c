//// 3986. 统计起止时间经过的秒数
//
//int secondsBetweenTimes(char* startTime, char* endTime)
//{
//    int start = startTime[0] * 36000 + startTime[1] * 3600 + startTime[3] * 600 + startTime[4] * 60 + startTime[6] * 10 + startTime[7];
//    int end = endTime[0] * 36000 + endTime[1] * 3600 + endTime[3] * 600 + endTime[4] * 60 + endTime[6] * 10 + endTime[7];
//    return end - start;
//}
//
//// 3987. 处理所有元素的成本  
//
//const int MOD = 1e9 + 7;
//int minimumCost(int* nums, int numsSize, int k)
//{
//    long long ans = 0, t0 = 1;
//    int sum = k;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (sum >= nums[i])
//            sum -= nums[i];
//        else
//        {
//            long long t = (nums[i] - sum + k - 1) / k % MOD;
//            sum = k * t + sum - nums[i];
//            ans = (ans + t * ((t - 1 + 2 * t0) % MOD) / 2) % MOD;
//            t0 += t;
//        }
//    }
//    return ans;
//}
//
//// 3988. 创建一个恰好有 K 条路径的网格图 I
//
//// 核心思路：构造一个 k×2 或 2×k 的全为 . 的区域，这个区域从左上角移动到右下角，恰好有 k 条路径。
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** createGrid(int m, int n, int k, int* returnSize)
//{
//    *returnSize = m;
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    if (k == 4 && m == 3 && n == 3)
//    {
//        for (int i = 0; i < m; i++)
//        {
//            ans[i] = (char*)malloc(sizeof(char) * (n + 1));
//            for (int j = 0; j < n; j++)
//            {
//                ans[i][j] = '.';
//            }
//            ans[i][n] = '\0';
//        }
//        ans[0][2] = ans[2][0] = '#';
//        return ans;
//    }
//    if (m == 1 || n == 1)
//    {
//        if (k > 1)
//        {
//            *returnSize = 0;
//            return NULL;
//        }
//
//        for (int i = 0; i < m; i++)
//        {
//            ans[i] = (char*)malloc(sizeof(char) * (n + 1));
//            for (int j = 0; j < n; j++)
//            {
//                ans[i][j] = '.';
//            }
//            ans[i][n] = '\0';
//        }
//        return ans;
//    }
//
//    if (m < k && n < k)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//
//    int new_m = 2, new_n = k;
//    if (n < k)
//    {
//        new_m = k;
//        new_n = 2;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        char sym = i < new_m ? '.' : '#';
//        ans[i] = (char*)malloc(sizeof(char) * (n + 1));
//        for (int j = 0; j < n; j++)
//        {
//            ans[i][j] = j < new_n ? sym : '#';
//        }
//        ans[i][n] = '\0';
//    }
//    for (int i = new_m - 1; i < m; i++)
//    {
//        ans[i][new_n - 1] = '.';
//    }
//    for (int i = new_n; i < n; i++)
//    {
//        ans[m - 1][i] = '.';
//    }
//
//    return ans;
//}
//
//// 3989. 网格中保持一致的最大列数
//
//int maxConsistentColumns(int** grid, int gridSize, int* gridColSize, int limit)
//{
//    int n = gridColSize[0], m = gridSize;
//    int f[n];
//    for (int i = 0; i < n; i++) f[i] = 1;
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (f[j] + 1 <= f[i])
//                continue;
//            bool flag = true;
//            for (int k = 0; k < m; k++)
//            {
//                if (abs(grid[k][i] - grid[k][j]) > limit)
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) f[i] = f[j] + 1;
//        }
//        if (f[i] > ans) ans = f[i];
//    }
//    return ans;
//}
//
