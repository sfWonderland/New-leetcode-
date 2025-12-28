////3788. 分割的最大得分
//
//long long maximumScore(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long* suf = (long long*)malloc(sizeof(long long) * n);
//    suf[n - 1] = nums[n - 1];
//    for (int i = n - 2; i >= 0; i--)
//    {
//        suf[i] = fmin(suf[i + 1], nums[i]);
//    }
//    long long pre = nums[0], ans = nums[0] - suf[1];
//    for (int i = 1; i < n - 1; i++)
//    {
//        pre += nums[i];
//        ans = fmax(ans, pre - suf[i + 1]);
//    }
//    return ans;
//}
//
////3789. 采购的最小花费
//
//long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
//{
//    long long ans = 0;
//    if (need1 < need2)
//    {
//        int tmp1 = need1, tmp2 = cost1;
//        need1 = need2; cost1 = cost2;
//        need2 = tmp1; cost2 = tmp2;
//    }
//    if (costBoth <= cost1 + cost2)
//    {
//        ans += 1ll * need2 * costBoth;
//        need1 -= need2;
//        if (costBoth <= cost1)
//            ans += 1ll * costBoth * need1;
//        else
//            ans += 1ll * cost1 * need1;
//    }
//    else
//        ans = 1ll * need2 * cost2 + 1ll * need1 * cost1;
//
//    return ans;
//}
//
////100948. 最小全 1 倍数
//
//int minAllOneMultiple(int k)
//{
//    if (k % 2 == 0 || k % 5 == 0)
//        return -1;
//    int ans = 1;
//    long long n = 1;
//    while (n % k)
//    {
//        long long b = n % k;
//        n = b * 10 + 1;
//        ans++;
//    }
//    return ans;
//}
//
////3791. 给定范围内平衡整数的数目
//
//long long countBalancedUpTo(long long num)
//{
//    int n = 0;
//    long long tmp = num;
//    while (tmp)
//    {
//        n++;
//        tmp /= 10;
//    }
//    int* digits = (int*)malloc(sizeof(int) * n);
//    tmp = num;
//    int k = 0;
//    while (tmp)
//    {
//        digits[n - 1 - k] = tmp % 10;
//        k++;
//        tmp /= 10;
//    }
//    long long** vis = (long long**)malloc(sizeof(long long*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        vis[i] = (long long*)malloc(sizeof(long long) * (18 * n + 1));
//        for (int j = 0; j <= 18 * n; j++)
//        {
//            vis[i][j] = -400;
//        }
//    }
//    long long dfs(int i, int diff, bool limit)
//    {
//        if (i == n)
//            return !diff;
//
//        if (!limit && vis[i][diff + 9 * n] != -400)
//            return vis[i][diff + 9 * n];
//
//        int up = limit ? digits[i] : 9;
//        long long tot = 0;
//        for (int j = 0; j < up + 1; j++)
//        {
//            int new_diff = diff;
//            if ((n - i) % 2 == 0)
//                new_diff -= j;
//            else
//                new_diff += j;
//
//            tot += dfs(i + 1, new_diff, limit && j == up);
//        }
//
//        if (!limit)
//            vis[i][diff + 9 * n] = tot;
//
//        return tot;
//    }
//    return dfs(0, 0, true);
//}
//long long countBalanced(long long low, long long high)
//{
//    return countBalancedUpTo(high) - countBalancedUpTo(low - 1);
//}
//
