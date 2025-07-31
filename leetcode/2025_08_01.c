////877. 石子游戏
//
//bool stoneGame(int* piles, int pilesSize)
//{
//    int f[pilesSize + 1][pilesSize + 1];
//    for (int i = 0; i <= pilesSize; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            f[i][j] = 0;
//        }
//    }
//    for (int i = 0; i < pilesSize; i++)
//    {
//        for (int j = i; j < pilesSize; j++)
//        {
//            f[i][j + 1] = fmax(-f[i][j] + piles[j], -f[i + 1][j + 1] + piles[i]);
//        }
//    }
//    return f[0][pilesSize] > 0;
//}
//
//bool stoneGame(int* piles, int pilesSize)
//{
//    return 1;
//}
//
////486. 预测赢家
//
//int* arr;
//
//int dfs(int i, int l)
//{
//    if (i < 0)
//        return 0;
//
//    return fmax(arr[i + l] - dfs(i - 1, l), arr[l] - dfs(i - 1, l + 1));
//}
//
//bool predictTheWinner(int* nums, int numsSize)
//{
//    arr = nums;
//    int s = dfs(numsSize - 1, 0);
//    return s >= 0;
//}
//
//bool predictTheWinner(int* nums, int numsSize)
//{
//    int f[numsSize + 1][numsSize + 1];
//    for (int i = 0; i <= numsSize; i++)
//    {
//        f[0][i] = 0;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < numsSize - i; j++)
//        {
//            f[i + 1][j] = fmax(nums[i + j] - f[i][j], nums[j] - f[i][j + 1]);
//        }
//    }
//
//    return f[numsSize][0] >= 0;
//}
//
////2256. 最小平均差
//
//int minimumAverageDifference(int* nums, int numsSize)
//{
//    long long prefix[numsSize], suffix[numsSize];
//    prefix[0] = nums[0], suffix[numsSize - 1] = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        prefix[i] = prefix[i - 1] + nums[i];
//    }
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        suffix[i] = suffix[i + 1] + nums[i + 1];
//    }
//    int mn = INT_MAX, idx = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int a = prefix[i] / (i + 1);
//        int b = suffix[i] / fmax(1, numsSize - 1 - i);
//        int t = abs(a - b);
//        if (mn > t)
//        {
//            mn = t;
//            idx = i;
//        }
//    }
//    return idx;
//}
//
//int minimumAverageDifference(int* nums, int numsSize)
//{
//    long long suf = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf += nums[i];
//    }
//    long long pre = 0;
//    int mn = suf, idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        suf -= nums[i];
//        pre += nums[i];
//        int s = fmax(1, numsSize - i - 1);
//        int t = abs(pre / (i + 1) - suf / s);
//        if (mn > t)
//        {
//            mn = t;
//            idx = i;
//        }
//    }
//    return idx;
//}
//
////2270. 分割数组的方案数
//
//int waysToSplitArray(int* nums, int numsSize)
//{
//    long long total = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        total += nums[i];
//    }
//    long long pre = 0;
//    int ans = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        pre += nums[i];
//        ans += 2 * pre >= total;
//    }
//    return ans;
//}
//
