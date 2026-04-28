//// LCR 104. 组合总和 Ⅳ
//
//int combinationSum4(int* nums, int numsSize, int target)
//{
//    int n = numsSize;
//    int memo[target + 1];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int target)
//    {
//        if (target == 0)
//            return 1;
//
//        int sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int new_target = target - nums[i];
//            if (new_target >= 0)
//            {
//                if (memo[new_target] == 0x3f3f3f3f)
//                {
//                    memo[new_target] = dfs(new_target);
//                }
//
//                sum += memo[new_target];
//            }
//        }
//        return sum;
//    }
//    return dfs(target);
//}
//
//int combinationSum4(int* nums, int numsSize, int target)
//{
//    int n = numsSize;
//    unsigned long long f[target + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 1; i <= target; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int k = i - nums[j];
//            if (k >= 0)
//            {
//                f[i] += f[k];
//            }
//        }
//    }
//    return f[target];
//}
//
//// LCR 103. 零钱兑换   
//
//int coinChange(int* coins, int coinsSize, int amount)
//{
//    int memo[amount + 1];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int target)
//    {
//        if (target < 0)
//            return 0x3f3f3f3f;
//
//        if (target == 0)
//            return 0;
//
//        if (memo[target] != 0x3f3f3f3f)
//            return memo[target];
//        for (int i = 0; i < coinsSize; i++)
//        {
//            if (target >= coins[i])
//                memo[target] = fmin(dfs(target - coins[i]) + 1, memo[target]);
//        }
//        return memo[target];
//    }
//    int res = dfs(amount);
//    return res >= 0x3f3f3f3f ? -1 : res;
//}
//
//int coinChange(int* coins, int coinsSize, int amount)
//{
//    int f[amount + 1];
//    f[0] = 0;
//    for (int i = 1; i <= amount; i++)
//    {
//        f[i] = 0x3f3f3f3f;
//        for (int j = 0; j < coinsSize; j++)
//        {
//            if (i >= coins[j])
//            {
//                f[i] = fmin(f[i - coins[j]] + 1, f[i]);
//            }
//        }
//    }
//    return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
//}
//
//// LCR 102. 目标和
//
//int findTargetSumWays(int* nums, int numsSize, int target)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    target += sum;
//    if (target < 0 || target % 2)
//        return 0;
//
//    target /= 2;
//
//    int f[target + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = target; j >= nums[i]; j--)
//        {
//            f[j] += f[j - nums[i]];
//        }
//    }
//    return f[target];
//}
//
//// LCR 101. 分割等和子集
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
//
//    sum /= 2;
//
//    bool f[sum + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
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
