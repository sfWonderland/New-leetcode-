////3202. 找出有效子序列的最大长度 II
//
//int maximumLength(int* nums, int numsSize, int k)
//{
//    int f[k][k];
//    memset(f, 0, sizeof(f));
//    int mx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i] % k;
//        for (int y = 0; y < k; y++)
//        {
//            f[y][x] = f[x][y] + 1;
//            mx = fmax(f[y][x], mx);
//        }
//    }
//    return mx;
//}
//
//int maximumLength(int* nums, int numsSize, int k)
//{
//    int mx = 0;
//    for (int m = 0; m < k; m++) //(sub[i - 1] + sub[i]) % k
//    {
//        int f[k];
//        memset(f, 0, sizeof(f));
//        for (int i = 0; i < numsSize; i++)
//        {
//            int x = nums[i] % k;
//            f[x] = f[(m - x + k) % k] + 1;
//            mx = fmax(f[x], mx);
//        }
//    }
//    return mx;
//}
//
//
////494. 目标和
//
//int dfs(int* nums, int i, int c)
//{
//    if (i < 0)
//        return c == 0;
//
//    if (c < nums[i])
//        return dfs(nums, i - 1, c);
//
//    return dfs(nums, i - 1, c) + dfs(nums, i - 1, c - nums[i]);
//}
//int findTargetSumWays(int* nums, int numsSize, int target)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//
//    target += sum;
//    if (target % 2 || target < 0)
//        return 0;
//    target /= 2;
//
//    return dfs(nums, numsSize - 1, target);
//}
//
//int findTargetSumWays(int* nums, int numsSize, int target)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//
//    target += sum;
//    if (target % 2 || target < 0)
//        return 0;
//    target /= 2;
//
//    int f[numsSize + 1][target + 1];
//    memset(f, 0, sizeof(f));
//    f[0][0] = 1;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < target + 1; j++)
//        {
//            if (j < nums[i])
//                f[i + 1][j] = f[i][j];
//            else
//                f[i + 1][j] = f[i][j] + f[i][j - nums[i]];
//        }
//    }
//    return f[numsSize][target];
//}
//
//int findTargetSumWays(int* nums, int numsSize, int target)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//
//    target += sum;
//    if (target % 2 || target < 0)
//        return 0;
//    target /= 2;
//
//    int f[2][target + 1];
//    memset(f, 0, sizeof(f));
//    f[0][0] = 1;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < target + 1; j++)
//        {
//            if (j < nums[i])
//                f[(i + 1) % 2][j] = f[i % 2][j];
//            else
//                f[(i + 1) % 2][j] = f[i % 2][j] + f[i % 2][j - nums[i]];
//        }
//    }
//    return f[numsSize % 2][target];
//}
//
//int findTargetSumWays(int* nums, int numsSize, int target)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//
//    target += sum;
//    if (target % 2 || target < 0)
//        return 0;
//    target /= 2;
//
//    int f[target + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = target; j >= nums[i]; j--)
//        {
//            f[j] = f[j] + f[j - nums[i]];
//        }
//    }
//
//    return f[target];
//}
//
////322. 零钱兑换
//
//long long dfs(int* nums, int i, int c)
//{
//    if (i < 0)
//        return c == 0 ? 0 : INT_MAX;
//
//    if (c < nums[i])
//        return dfs(nums, i - 1, c);
//
//    return fmin(dfs(nums, i - 1, c), dfs(nums, i, c - nums[i]) + 1);
//}
//int coinChange(int* coins, int coinsSize, int amount)
//{
//    long long ans = dfs(coins, coinsSize - 1, amount);
//    return ans < INT_MAX ? ans : -1;
//}
//
//int coinChange(int* coins, int coinsSize, int amount)
//{
//    long long f[amount + 1];
//    for (int i = 0; i <= amount; i++)
//    {
//        f[i] = INT_MAX;
//    }
//    f[0] = 0;
//    for (int i = 0; i < coinsSize; i++)
//    {
//        for (int j = coins[i]; j <= amount; j++)
//        {
//            f[j] = fmin(f[j], f[j - coins[i]] + 1);
//        }
//    }
//    return f[amount] < INT_MAX ? f[amount] : -1;
//}
//
////279. 完全平方数
//
//int dfs(int i, int c)
//{
//    if (i == 1)
//        return c;
//
//    if (i * i > c)
//        return dfs(i - 1, c);
//
//    return fmin(dfs(i - 1, c), dfs(i, c - i * i) + 1);
//}
//int numSquares(int n)
//{
//    int i = sqrt(n);
//    return dfs(i, n);
//}
//
//int dfs(int i, int c)
//{
//    if (i == 1)
//        return c;
//
//    if (i * i > c)
//        return dfs(i - 1, c);
//
//    return fmin(dfs(i - 1, c), dfs(i, c - i * i) + 1);
//}
//int numSquares(int n)
//{
//    long long f[n + 1];
//    for (int i = 0; i < n + 1; i++)
//    {
//        f[i] = INT_MAX;
//    }
//    f[0] = 0;
//    for (int i = 1; i * i <= n; i++)
//    {
//        for (int j = i * i; j <= n; j++)
//        {
//            f[j] = fmin(f[j], f[j - i * i] + 1);
//        }
//    }
//    return f[n];
//}
//
