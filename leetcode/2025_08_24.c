////239. 滑动窗口最大值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
//{
//    int n = numsSize;
//    int* queue = (int*)malloc(sizeof(int) * n);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int bottom = 0, top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        while (top >= bottom && nums[queue[top]] <= nums[i])
//            top--;
//        queue[++top] = i;
//        if (i - queue[bottom] >= k)
//            bottom++;
//        if (i >= k - 1)
//            ans[i - k + 1] = nums[queue[bottom]];
//    }
//    *returnSize = n - k + 1;
//    return ans;
//}
//
////1438. 绝对差不超过限制的最长连续子数组
//
//int longestSubarray(int* nums, int numsSize, int limit)
//{
//    int n = numsSize;
//    int* max_q = (int*)malloc(sizeof(int) * n);
//    int* min_q = (int*)malloc(sizeof(int) * n);
//    int min_bottom = 0, min_top = -1;
//    int max_bottom = 0, max_top = -1;
//    int ans = 0, left = 0;
//    for (int i = 0; i < numsSize; ++i)
//    {
//        while (max_top >= max_bottom && nums[max_q[max_top]] <= nums[i])
//            max_top--;
//        max_q[++max_top] = i;
//        while (min_top >= min_bottom && nums[min_q[min_top]] >= nums[i])
//            min_top--;
//        min_q[++min_top] = i;
//
//        while (nums[max_q[max_bottom]] - nums[min_q[min_bottom]] > limit)
//        {
//            left++;
//            if (max_q[max_bottom] < left)
//                max_bottom++;
//            if (min_q[min_bottom] < left)
//                min_bottom++;
//        }
//
//        ans = fmax(ans, i - left + 1);
//    }
//    return ans;
//}
//
////2398. 预算内的最多机器人数目
//
//int maximumRobots(int* chargeTimes, int chargeTimesSize, int* runningCosts, int runningCostsSize, long long budget)
//{
//    int n = chargeTimesSize;
//    int* max_q = (int*)malloc(sizeof(int) * n);
//    int max_bottom = 0, max_top = -1;
//    int ans = 0, left = 0;
//    long long sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        while (max_top >= max_bottom && chargeTimes[max_q[max_top]] <= chargeTimes[i])
//            max_top--;
//        max_q[++max_top] = i;
//        sum += runningCosts[i];
//        while (max_top >= max_bottom && chargeTimes[max_q[max_bottom]] + (i - left + 1) * sum > budget)
//        {
//            if (max_q[max_bottom] == left)
//                max_bottom++;
//            sum -= runningCosts[left++];
//        }
//
//        ans = fmax(ans, i - left + 1);
//    }
//    return ans;
//}
//
////LCR 098. 不同路径
//
//int uniquePaths(int m, int n)
//{
//    int f[n + 1];
//    for (int i = 0; i < n + 1; i++)
//    {
//        f[i] = 0;
//    }
//    f[1] = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[j + 1] += f[j];
//        }
//    }
//    return f[n];
//}
//
