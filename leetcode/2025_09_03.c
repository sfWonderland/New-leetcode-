////3652. 按策略买卖股票的最佳时机
//
//long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k)
//{
//    int n = strategySize;
//    long long sum[n + 1];
//    long long delta[n + 1];
//    sum[0] = 0;
//    delta[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = sum[i] + prices[i] * strategy[i];
//        delta[i + 1] = delta[i] + prices[i];
//    }
//    long long ans = sum[n];
//    for (int i = 0; i <= n - k; i++)
//    {
//        ans = fmax(sum[n] - sum[i + k] + sum[i] + delta[i + k] - delta[i + k / 2], ans);
//    }
//    return ans;
//}
//
////2909. 元素和最小的山形三元组 II
//
//int minimumSum(int* nums, int numsSize)
//{
//    int suf[numsSize - 1];
//    suf[numsSize - 2] = nums[numsSize - 1];
//    for (int i = numsSize - 2; i > 0; i--)
//    {
//        suf[i - 1] = fmin(suf[i], nums[i]);
//    }
//    int ans = INT_MAX, pre = nums[0];
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        if (nums[i] > pre && nums[i] > suf[i - 1])
//            ans = fmin(ans, pre + nums[i] + suf[i - 1]);
//
//        pre = fmin(pre, nums[i]);
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
////1094. 拼车
//
//bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
//{
//    int dist[1002] = { 0 };
//    int max = 0, min = 1000;
//    for (int i = 0; i < tripsSize; i++)
//    {
//        dist[trips[i][1]] += trips[i][0];
//        dist[trips[i][2]] -= trips[i][0];
//        min = fmin(min, trips[i][1]);
//        max = fmax(max, trips[i][1]);
//    }
//    int sum_max = 0, sum = 0;
//    for (int i = min; i <= max; i++)
//    {
//        sum += dist[i];
//        sum_max = fmax(sum, sum_max);
//        if (sum_max > capacity) return false;
//    }
//    return true;
//}
//
////1109. 航班预订统计
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
//{
//    int* ans = (int*)calloc(sizeof(int), n + 1);
//    for (int i = 0; i < bookingsSize; i++)
//    {
//        ans[bookings[i][0] - 1] += bookings[i][2];
//        ans[bookings[i][1]] -= bookings[i][2];
//    }
//    for (int i = 1; i < n; i++)
//    {
//        ans[i] += ans[i - 1];
//    }
//    *returnSize = n;
//    return ans;
//}
//
