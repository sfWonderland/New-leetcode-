//// 1027. 最长等差数列
//
//int longestArithSeqLength(int* nums, int numsSize)
//{
//    int ans = 0, n = numsSize;
//    int f[n][1001];
//    memset(f, 0, sizeof(f));
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = i - 1; j >= 0; j--)
//        {
//            int d = nums[i] - nums[j] + 500;
//            if (f[i][d] == 0)
//            {
//                f[i][d] = f[j][d] + 1;
//                ans = fmax(ans, f[i][d]);
//            }
//        }
//    }
//    return ans + 1;
//}
//
