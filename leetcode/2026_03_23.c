////2799. 统计完全子数组的数目
//
//int countCompleteSubarrays(int* nums, int numsSize)
//{
//    int cnt1[2001] = { 0 };
//    int m = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        m += cnt1[nums[i]] == 0;
//        cnt1[nums[i]]++;
//    }
//    int cnt2[2001] = { 0 };
//    int k = 0, left = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        k += cnt2[nums[i]] == 0;
//        cnt2[nums[i]]++;
//        while (k == m)
//        {
//            int out = nums[left];
//            if (--cnt2[out] == 0)
//                k--;
//
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//
//// 2806. 取整购买后的账户余额   
//
//int accountBalanceAfterPurchase(int purchaseAmount)
//{
//    int mod = purchaseAmount % 10;
//    int k = purchaseAmount / 10 + (mod >= 5);
//    return (10 - k) * 10;
//}
//
////2839. 判断通过操作能否让字符串相等 I
//
//bool canBeEqual(char* s1, char* s2)
//{
//    if (s1[0] != s2[0])
//    {
//        if (s1[2] != s2[0])
//            return false;
//
//        char tmp = s1[0];
//        s1[0] = s1[2];
//        s1[2] = tmp;
//    }
//    if (s1[1] != s2[1])
//    {
//        if (s1[3] != s2[1])
//            return false;
//
//        char tmp = s1[1];
//        s1[1] = s1[3];
//        s1[3] = tmp;
//    }
//    return (s1[2] == s2[2]) && (s1[3] == s2[3]);
//}
//
////1594. 矩阵的最大非负积
//
//const int MOD = 1e9 + 7;
//int maxProductPath(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    long long f_max[n], f_min[n];
//
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            long long x = grid[i][j];
//            if (i == 0 && j == 0)
//            {
//                f_max[0] = x, f_min[0] = x;
//                continue;
//            }
//
//            long long res_min = LLONG_MAX;
//            long long res_max = LLONG_MIN;
//
//            if (i > 0)
//            {
//                long long mn = f_min[j], mx = f_max[j];
//                res_min = fmin(mn * x, mx * x);
//                res_max = fmax(mn * x, mx * x);
//            }
//            if (j > 0)
//            {
//                long long mn = f_min[j - 1], mx = f_max[j - 1];
//                res_min = fmin(res_min, fmin(mn * x, mx * x));
//                res_max = fmax(res_max, fmax(mn * x, mx * x));
//            }
//
//            f_min[j] = res_min, f_max[j] = res_max;
//        }
//    }
//
//    long long ans = f_max[n - 1];
//    return ans < 0 ? -1 : ans % MOD;
//}
//
