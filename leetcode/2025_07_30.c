////3573. 买卖股票的最佳时机 V
//
//int* nums;
//int dfs(int i, int k, int hold)
//{
//    if (k < 0)
//        return INT_MIN / 2;
//    if (i < 0)
//        return hold ? INT_MIN / 2 : 0;
//    if (hold == 0)
//        return fmax(fmax(dfs(i - 1, k, 0), dfs(i - 1, k, 1) + nums[i]), dfs(i - 1, k - 1, -1) - nums[i]);
//    else if (hold == -1)
//        return fmax(dfs(i - 1, k, -1), dfs(i - 1, k, 0) + nums[i]);
//    else
//        return fmax(dfs(i - 1, k, 1), dfs(i - 1, k - 1, 0) - nums[i]);
//}
//long long maximumProfit(int* prices, int pricesSize, int k)
//{
//    nums = prices;
//    return dfs(pricesSize - 1, k, 0);
//}
//
//long long maximumProfit(int* prices, int pricesSize, int k)
//{
//    long long f[pricesSize + 1][k + 2][3];
//    for (int i = 0; i < pricesSize + 1; i++)
//    {
//        f[i][0][0] = LLONG_MIN / 2;
//        f[i][0][1] = LLONG_MIN / 2;
//        f[i][0][2] = LLONG_MIN / 2;
//    }
//    for (int j = 1; j <= k + 1; j++)
//    {
//        f[0][j][0] = LLONG_MIN / 2;
//        f[0][j][1] = 0;
//        f[0][j][2] = LLONG_MIN / 2;
//    }
//    for (int i = 0; i < pricesSize; i++)
//    {
//        int p = prices[i];
//        for (int j = 0; j < k + 1; j++)
//        {
//            f[i + 1][j + 1][0] = fmax(f[i][j + 1][0], f[i][j + 1][1] + p);
//            f[i + 1][j + 1][1] = fmax(fmax(f[i][j + 1][1], f[i][j + 1][2] + p), f[i][j][0] - p);
//            f[i + 1][j + 1][2] = fmax(f[i][j + 1][2], f[i][j][1] - p);
//        }
//    }
//    return f[pricesSize][k + 1][1];
//}
//
//long long maximumProfit(int* prices, int pricesSize, int k)
//{
//    long long f[k + 2][3];
//    f[0][0] = LLONG_MIN / 2; f[0][1] = LLONG_MIN / 2; f[0][2] = LLONG_MIN / 2;
//    for (int j = 1; j <= k + 1; j++)
//    {
//        f[j][0] = LLONG_MIN / 2; f[j][1] = 0; f[j][2] = LLONG_MIN / 2;
//    }
//    for (int i = 0; i < pricesSize; i++)
//    {
//        int p = prices[i];
//        for (int j = k; j >= 0; j--)
//        {
//            f[j + 1][0] = fmax(f[j + 1][0], f[j + 1][1] + p);
//            f[j + 1][1] = fmax(fmax(f[j + 1][1], f[j + 1][2] + p), f[j][0] - p);
//            f[j + 1][2] = fmax(f[j + 1][2], f[j][1] - p);
//        }
//    }
//    return f[k + 1][1];
//}
//
////714. 买卖股票的最佳时机含手续费
//
//int* nums;
//int cost;
//
//int dfs(int i, int hold)
//{
//    if (i < 0)
//        return hold ? INT_MIN / 2 : 0;
//    if (hold)
//        return fmax(dfs(i - 1, 1), dfs(i - 1, 0) - nums[i] - cost);
//    else
//        return fmax(dfs(i - 1, 0), dfs(i - 1, 1) + nums[i]);
//}
//int maxProfit(int* prices, int pricesSize, int fee)
//{
//    nums = prices;
//    cost = fee;
//    return dfs(pricesSize - 1, 0);
//}
//
//int maxProfit(int* prices, int pricesSize, int fee)
//{
//    int f[pricesSize + 1][2];
//    f[0][0] = 0, f[0][1] = INT_MIN / 2;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        f[i + 1][0] = fmax(f[i][0], f[i][1] + prices[i]);
//        f[i + 1][1] = fmax(f[i][1], f[i][0] - prices[i] - fee);
//    }
//    return f[pricesSize][0];
//}
//
//int maxProfit(int* prices, int pricesSize, int fee)
//{
//    int f0 = 0, f1 = INT_MIN / 2;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        f0 = fmax(f0, f1 + prices[i]);
//        f1 = fmax(f1, f0 - prices[i] - fee);
//    }
//    return f0;
//}
//
////2786. 访问数组中的位置使分数最大
//
//int* arr;
//int cost;
//int n;
//long long** f;
//
//long long dfs(int i, int j)
//{
//    if (i > n)
//        return 0;
//    if (f[i][j] != -1)
//        return f[i][j];
//
//    if (arr[i] % 2 == j)
//    {
//        if (f[i + 1][j] == -1)
//            f[i + 1][j] = dfs(i + 1, j);
//
//        f[i][j] = f[i + 1][j] + arr[i];
//        return f[i][j];
//    }
//
//    if (f[i + 1][j] == -1)
//        f[i + 1][j] = dfs(i + 1, j);
//    if (f[i + 1][j ^ 1] == -1)
//        f[i + 1][j ^ 1] = dfs(i + 1, j ^ 1);
//
//    f[i][j] = fmax(f[i + 1][j], f[i + 1][j ^ 1] - cost + arr[i]);
//    return f[i][j];
//}
//long long maxScore(int* nums, int numsSize, int x)
//{
//    arr = nums;
//    cost = x;
//    n = numsSize - 1;
//    f = (long long**)malloc(sizeof(long long*) * (numsSize + 1));
//    for (int i = 0; i <= numsSize; i++)
//    {
//        f[i] = (long long*)malloc(sizeof(long long) * 2);
//        f[i][0] = f[i][1] = -1;
//    }
//    return dfs(0, nums[0] % 2);
//}
//
//long long maxScore(int* nums, int numsSize, int x)
//{
//    long long f[numsSize + 1][2];
//    f[numsSize][0] = f[numsSize][1] = 0;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        int v = nums[i];
//        int r = v % 2;
//        f[i][r ^ 1] = f[i + 1][r ^ 1];
//        f[i][r] = fmax(f[i + 1][r], f[i + 1][r ^ 1] - x) + v;
//    }
//
//    return f[0][nums[0] % 2];
//}
//
//long long maxScore(int* nums, int numsSize, int x)
//{
//    long long f[2] = { 0 };
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        int r = nums[i] % 2;
//        f[r] = fmax(f[r], f[r ^ 1] - x) + nums[i];
//    }
//
//    return f[nums[0] % 2];
//}
//
////1911. 最大交替子序列和
//
//int* arr;
//int n;
//
//long long dfs(int i, int j)
//{
//    if (i == n)
//        return 0;
//    long long t = j % 2 ? -1 : 1;
//    return fmax(dfs(i + 1, j), dfs(i + 1, j + 1) + t * arr[i]);
//}
//long long maxAlternatingSum(int* nums, int numsSize)
//{
//    arr = nums;
//    n = numsSize;
//    return dfs(0, 0);
//}
//
//long long maxAlternatingSum(int* nums, int numsSize)
//{
//    long long f[numsSize + 1][numsSize + 1];
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        f[numsSize][i] = 0;
//    }
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        for (int j = 0; j < numsSize; j++)
//        {
//            long long t = j % 2 ? -1 : 1;
//            f[i][j] = fmax(f[i + 1][j], f[i + 1][j + 1] + t * nums[i]);
//        }
//    }
//    return f[0][0];
//}
//
//long long maxAlternatingSum(int* nums, int numsSize)
//{
//    long long f0 = 0, f1 = 0;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        int x = nums[i];
//        f0 = fmax(fmax(f0, f1 + x), x);
//        f1 = fmax(f1, f0 - x);
//    }
//    return fmax(f0, f1);
//}
//
