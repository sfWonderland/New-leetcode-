////3693. 爬楼梯 II
//
//int climbStairs(int n, int* costs, int costsSize)
//{
//    // int dfs(int i)
//    // {
//    //     if(i == 0)
//    //     return 0;
//
//    //     int ret = INT_MAX / 2;
//    //     for(int j = 1; j <= fmin(3, i); j++)
//    //     {
//    //         ret = fmin(ret, costs[i - 1] + j * j + dfs(i - j));
//    //     }
//    //     return ret;
//    // }
//    int f[n + 1];
//    for (int i = 0; i < n; i++)
//    {
//        f[i + 1] = INT_MAX / 2;
//    }
//    f[0] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= fmin(3, 1); j++)
//            f[i] = fmin(f[i], costs[i - 1] + j * j + f[i - j]);
//    }
//    return f[n];
//}
//
//int climbStairs(int n, int* costs, int costsSize)
//{
//    int dp[3] = { 0 };
//    for (int i = 0; i < costsSize; i++)
//    {
//        int dp0 = costs[i] + fmin(fmin(dp[0] + 1, dp[1] + 4), dp[2] + 9);
//        dp[2] = dp[1];
//        dp[1] = dp[0];
//        dp[0] = dp0;
//    }
//    return dp[0];
//}
//
////3418. 机器人可以获得的最大金币数
//
//int maximumAmount(int** coins, int coinsSize, int* coinsColSize)
//{
//    // int dfs(int i, int j, int k)
//    // {
//    //     if(i < 0 || j < 0)
//    //     return INT_MIN / 2;
//
//    //     if(i == 0 && j == 0)
//    //     {
//    //         if(k > 0)
//    //         return fmax(coins[0][0], 0);
//    //     }
//
//    //     int a = coins[i][j] + fmax(dfs(i - 1, j, k), dfs(i, j - 1, k));
//    //     if(k > 0 && coins[i][j] < 0)
//    //     return fmax(a, fmax(dfs(i - 1, j, k - 1), dfs(i, j - 1, k - 1)));
//
//    //     return a;
//    // }    
//    // return dfs(coinsSize - 1, coinsColSize[0] - 1, 2);
//    int m = coinsSize, n = coinsColSize[0];
//    int f[m + 1][n + 1][3];
//    for (int i = 0; i <= m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            for (int k = 0; k < 3; k++)
//            {
//                f[i][j][k] = INT_MIN / 2;
//            }
//        }
//    }
//    f[0][1][0] = 0;
//    f[0][1][1] = 0;
//    f[0][1][2] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            for (int k = 0; k < 3; k++)
//            {
//                f[i + 1][j + 1][k] = coins[i][j] + fmax(f[i][j + 1][k], f[i + 1][j][k]);
//                if (k && coins[i][j] < 0)
//                {
//                    f[i + 1][j + 1][k] = fmax(f[i + 1][j + 1][k],
//                        fmax(f[i][j + 1][k - 1], f[i + 1][j][k - 1]));
//                }
//            }
//        }
//    }
//    return f[m][n][2];
//}
//
//int maximumAmount(int** coins, int coinsSize, int* coinsColSize)
//{
//    int m = coinsSize, n = coinsColSize[0];
//    int f[n + 1][3];
//
//    for (int j = 0; j <= n; j++)
//    {
//        for (int k = 0; k < 3; k++)
//        {
//            f[j][k] = INT_MIN / 2;
//        }
//    }
//    f[1][0] = 0, f[1][1] = 0, f[1][2] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            for (int k = 2; k >= 0; k--) //倒序
//            {
//                f[j + 1][k] = coins[i][j] + fmax(f[j + 1][k], f[j][k]);
//                if (k && coins[i][j] < 0)
//                {
//                    f[j + 1][k] = fmax(f[j + 1][k], fmax(f[j + 1][k - 1], f[j][k - 1]));
//                }
//            }
//        }
//    }
//    return f[n][2];
//}
//
////1035. 不相交的线
//
//int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    // int dfs(int i, int j)
//    // {
//    //     if(i < 0 || j < 0)
//    //     return 0;
//
//    //     if(nums1[i] == nums2[j])
//    //     return fmax(dfs(i - 1, j - 1) + 1, fmax(dfs(i - 1, j), dfs(i, j - 1)));
//    //     else
//    //     return fmax(dfs(i - 1, j), dfs(i, j - 1));
//    // }    
//    // return dfs(nums1Size - 1, nums2Size - 1);
//    int m = nums1Size, n = nums2Size;
//    int f[m + 1][n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = nums1[i] == nums2[j] ? f[i][j] + 1 : fmax(f[i][j + 1], f[i + 1][j]);
//        }
//    }
//    return f[m][n];
//}
//
//int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    // int dfs(int i, int j)
//    // {
//    //     if(i < 0 || j < 0)
//    //     return 0;
//
//    //     if(nums1[i] == nums2[j])
//    //     return fmax(dfs(i - 1, j - 1) + 1, fmax(dfs(i - 1, j), dfs(i, j - 1)));
//    //     else
//    //     return fmax(dfs(i - 1, j), dfs(i, j - 1));
//    // }    
//    // return dfs(nums1Size - 1, nums2Size - 1);
//    int m = nums1Size, n = nums2Size;
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < m; i++)
//    {
//        int pre = 0;
//        for (int j = 0; j < n; j++)
//        {
//            int tmp = f[j + 1];
//            f[j + 1] = nums1[i] == nums2[j] ? pre + 1 : fmax(f[j + 1], f[j]);
//            pre = tmp;
//        }
//    }
//    return f[n];
//}
//
////1567. 乘积为正数的最长子数组长度
//
//int getMaxLen(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int f[n][2];
//    memset(f, 0, sizeof(f));
//    if (nums[0] > 0)
//        f[0][0] = 1;
//    if (nums[0] < 0)
//        f[0][1] = 1;
//    int ans = f[0][0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//        {
//            if (f[i - 1][1] > 0)
//                f[i][1] = f[i - 1][1] + 1;
//
//            f[i][0] = f[i - 1][0] + 1;
//        }
//        if (nums[i] < 0)
//        {
//            if (f[i - 1][1] > 0)
//                f[i][0] = f[i - 1][1] + 1;
//
//            f[i][1] = f[i - 1][0] + 1;
//        }
//        ans = fmax(ans, f[i][0]);
//    }
//    return ans;
//}
//
