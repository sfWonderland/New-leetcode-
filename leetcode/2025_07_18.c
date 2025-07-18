////518. 零钱兑换 II
//
//int dfs(int i, int c, int* nums)
//{
//    if (i < 0)
//        return c == 0;
//
//    if (c < nums[i])
//        return dfs(i - 1, c, nums);
//
//    return dfs(i - 1, c, nums) + dfs(i, c - nums[i], nums);
//}
//int change(int amount, int* coins, int coinsSize)
//{
//    return dfs(coinsSize - 1, amount, coins);
//}
//
//int change(int amount, int* coins, int coinsSize)
//{
//    int f[amount + 1];
//    bool valid[amount + 1];
//    memset(f, 0, sizeof(f));
//    memset(valid, false, sizeof(valid));
//    f[0] = 1;
//    valid[0] = true;
//    for (int i = 0; i < coinsSize; i++)
//    {
//        for (int j = coins[i]; j <= amount; j++)
//            valid[j] |= valid[j - coins[i]];
//    }
//    if (!valid[amount])
//        return 0;
//    for (int i = 0; i < coinsSize; i++)
//    {
//        for (int j = coins[i]; j <= amount; j++)
//            f[j] = f[j] + f[j - coins[i]];
//    }
//    return f[amount];
//}
//
////2787. 将一个数字表示成幂的和的方案数
//
//#define mod 1000000007
//int numberOfWays(int n, int x)
//{
//    int m = pow(n + 1, 1.0 / x);
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 1; i <= m; i++)
//    {
//        int y = pow(i, x);
//        for (int j = n; j >= y; j--)
//        {
//            f[j] = (f[j] + f[j - y]) % mod;
//        }
//    }
//    return f[n];
//}
//
////416. 分割等和子集
//
//bool canPartition(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    if (sum % 2)
//        return false;
//    sum /= 2;
//
//    bool f[sum + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = true;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = sum; j >= nums[i]; j--)
//        {
//            f[j] |= f[j - nums[i]];
//        }
//    }
//    return f[sum];
//}
//
////2915. 和为目标值的最长子序列的长度
//
//int dfs(int i, int c, int* nums)
//{
//    if (i < 0)
//        return c == 0 ? 0 : INT_MIN;
//
//    if (c < nums[i])
//        return dfs(i - 1, c, nums);
//
//    return fmax(dfs(i - 1, c, nums), dfs(i - 1, c - nums[i], nums) + 1);
//}
//
//int lengthOfLongestSubsequence(int* nums, int numsSize, int target)
//{
//    int ans = dfs(numsSize - 1, target, nums);
//    return ans > 0 ? ans : -1;
//}
//
//int lengthOfLongestSubsequence(int* nums, int numsSize, int target)
//{
//    int f[target + 1];
//    for (int i = 1; i <= target; i++)
//    {
//        f[i] = INT_MIN;
//    }
//    f[0] = 0;
//    int s = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        s = fmin(s + nums[i], target);
//        for (int j = s; j >= nums[i]; j--)
//        {
//            f[j] = fmax(f[j], f[j - nums[i]] + 1);
//        }
//    }
//    return f[target] > 0 ? f[target] : -1;
//}
//
//
