////2044. 统计按位或能得到最大值的子集数目
//
//int target;
//int* arr;
//
//int dfs(int i, int n)
//{
//    if (i < 0)
//        return n == target;
//
//    return dfs(i - 1, n | arr[i]) + dfs(i - 1, n);
//}
//int countMaxOrSubsets(int* nums, int numsSize)
//{
//    target = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        target |= nums[i];
//    }
//
//    arr = nums;
//
//    return dfs(numsSize - 1, 0);
//}
//
////309. 买卖股票的最佳时机含冷冻期
//
//int maxProfit(int* prices, int pricesSize)
//{
//    int f[pricesSize + 2][2];
//    f[0][0] = 0, f[0][1] = INT_MIN / 2;
//    f[1][0] = 0, f[1][1] = INT_MIN / 2;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        f[i + 2][0] = fmax(f[i + 1][0], f[i + 1][1] + prices[i]);
//        f[i + 2][1] = fmax(f[i + 1][1], f[i][0] - prices[i]);
//    }
//    return f[pricesSize + 1][0];
//}
//
//int maxProfit(int* prices, int pricesSize)
//{
//    int a = 0, b = INT_MIN / 2, pre = 0;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        int tmp = a;
//        a = fmax(a, b + prices[i]);
//        b = fmax(b, pre - prices[i]);
//        pre = tmp;
//    }
//    return a;
//}
//
////188. 买卖股票的最佳时机 IV
//
//int* nums;
//
//int dfs(int i, int k, bool hold)
//{
//    if (k < 0)
//        return INT_MIN / 2;
//    if (i < 0)
//        return hold ? INT_MIN / 2 : 0;
//
//    if (hold)
//        return fmax(dfs(i - 1, k, 1), dfs(i - 1, k, 0) - nums[i]);
//    else
//        return fmax(dfs(i - 1, k, 0), dfs(i - 1, k - 1, 1) + nums[i]);
//}
//
//int maxProfit(int k, int* prices, int pricesSize)
//{
//    nums = prices;
//    return dfs(pricesSize - 1, k, 0);
//}
//
//int maxProfit(int k, int* prices, int pricesSize)
//{
//    int f[pricesSize + 1][k + 2][2]; // k = -1, 0, 1, ... k.
//    for (int i = 0; i < pricesSize + 1; i++)
//    {
//        for (int j = 0; j < k + 2; j++)
//        {
//            f[i][j][0] = INT_MIN / 2;
//            f[i][j][1] = INT_MIN / 2;
//        }
//    }
//    for (int i = 1; i < k + 2; i++)
//        f[0][i][0] = 0;
//
//    for (int i = 0; i < pricesSize; i++)
//    {
//        for (int j = 0; j < k + 1; j++)
//        {
//            f[i + 1][j + 1][0] = fmax(f[i][j + 1][0], f[i][j + 1][1] + prices[i]);
//            f[i + 1][j + 1][1] = fmax(f[i][j + 1][1], f[i][j][0] - prices[i]);
//        }
//    }
//
//    return f[pricesSize][k + 1][0];
//}
//
//int maxProfit(int k, int* prices, int pricesSize)
//{
//    int f[k + 2][2]; // k = -1, 0, 1, ... k.
//    f[0][0] = INT_MIN / 2, f[0][1] = INT_MIN / 2;
//    for (int j = 1; j < k + 2; j++)
//    {
//        f[j][0] = 0;
//        f[j][1] = INT_MIN / 2;
//    }
//
//    for (int i = 0; i < pricesSize; i++)
//    {
//        for (int j = k; j >= 0; j--)
//        {
//            f[j + 1][0] = fmax(f[j + 1][0], f[j + 1][1] + prices[i]);
//            f[j + 1][1] = fmax(f[j + 1][1], f[j][0] - prices[i]);
//        }
//    }
//
//    return f[k + 1][0];
//}
//
////123. 买卖股票的最佳时机 III
//
//int* nums;
//
//int dfs(int i, int k, bool hold)
//{
//    if (k < 0)
//        return INT_MIN / 2;
//
//    if (i < 0)
//        return hold ? INT_MIN / 2 : 0;
//
//    if (hold)
//        return fmax(dfs(i - 1, k, 1), dfs(i - 1, k, 0) - nums[i]);
//    else
//        return fmax(dfs(i - 1, k, 0), dfs(i - 1, k - 1, 1) + nums[i]);
//}
//int maxProfit(int* prices, int pricesSize)
//{
//    nums = prices;
//    return dfs(pricesSize - 1, 2, 0);
//}
//
//int maxProfit(int* prices, int pricesSize)
//{
//    int f[4][2];
//    for (int i = 0; i < 4; i++)
//    {
//        f[i][0] = 0;
//        f[i][1] = INT_MIN / 2;
//    }
//    f[0][0] = INT_MIN / 2;
//
//    for (int i = 0; i < pricesSize; i++)
//    {
//        for (int j = 2; j >= 0; j--)
//        {
//            f[j + 1][0] = fmax(f[j + 1][0], f[j + 1][1] + prices[i]);
//            f[j + 1][1] = fmax(f[j + 1][1], f[j][0] - prices[i]);
//        }
//    }
//    return f[3][0];
//}
//
