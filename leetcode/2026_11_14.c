//// 3364. 最小正和子数组
//
//int minimumSumSubarray(int* nums, int numsSize, int l, int r)
//{
//    int n = numsSize, ans = INT_MAX;
//    int pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[i + 1] = pre[i] + nums[i];
//    }
//    for (int i = l; i <= n; i++)
//    {
//        for (int d = l; d <= r && d <= i; d++)
//        {
//            if (pre[i] - pre[i - d] <= 0)
//                continue;
//            ans = fmin(ans, pre[i] - pre[i - d]);
//        }
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
