////377. 组合总和 Ⅳ.
//
//int dfs(int target, int* nums, int numsSize, int* cache)
//{
//    if (target == 0)
//        return 1;
//
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int c = target - nums[i];
//        if (c >= 0)
//        {
//            if (-1 == cache[c])
//                cache[c] = dfs(c, nums, numsSize, cache);
//
//            sum += cache[c];
//        }
//    }
//    return sum;
//}
//int combinationSum4(int* nums, int numsSize, int target)
//{
//    int cache[target + 1];
//    for (int i = 0; i <= target; i++)
//    {
//        cache[i] = -1;
//    }
//    return dfs(target, nums, numsSize, cache);
//}
//
////213. 打家劫舍 II
//
//int dfs(int left, int right, int* nums)
//{
//    int f[3] = { 0 };
//    for (int i = left; i < right; i++)
//    {
//        f[0] = fmax(f[1], f[2] + nums[i]);
//        f[2] = f[1];
//        f[1] = f[0];
//    }
//    return f[0];
//}
//int rob(int* nums, int numsSize)
//{
//    return fmax(dfs(1, numsSize, nums), dfs(2, numsSize - 1, nums) + nums[0]);
//}
//
////.
//
//
//
////2466. 统计构造好字符串的方案数
//
//#define mod 1000000007;
//
//int countGoodStrings(int low, int high, int zero, int one)
//{
//    int f[high + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    int ans = 0;
//    for (int i = 1; i <= high; i++)
//    {
//        if (i >= zero) f[i] = f[i - zero];
//        if (i >= one) f[i] = (f[i] + f[i - one]) % mod;
//        if (i >= low) ans = (ans + f[i]) % mod;
//    }
//    return ans;
//}
//
////LCP 17. 速算机器人
//
//int calculate(char* s)
//{
//    int x = 1, y = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] - 'A')
//            y = 2 * y + x;
//        else
//            x = 2 * x + y;
//    }
//    return x + y;
//}
//
