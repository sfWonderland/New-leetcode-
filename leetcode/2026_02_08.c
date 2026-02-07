////100985. 统计主导元素下标数
//
//int dominantIndices(int* nums, int numsSize)
//{
//    int sum = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] > sum / (numsSize - 1 - i))
//            ans++;
//
//        sum -= nums[i + 1];
//    }
//    return ans;
//}
//
////100984. 合并相邻且相等的元素    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//long long* mergeAdjacent(int* nums, int numsSize, int* returnSize)
//{
//    long long* ans = (long long*)malloc(sizeof(long long) * numsSize);
//    int idx = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (idx >= 0 && nums[i] == ans[idx])
//        {
//            ans[idx] *= 2;
//            while (idx > 0 && ans[idx - 1] == ans[idx])
//            {
//                ans[--idx] *= 2;
//            }
//        }
//        else
//            ans[++idx] = nums[i];
//    }
//    *returnSize = idx + 1;
//    return ans;
//}
//
////100982. 开销小于等于 K 的子数组数目
//
//long long countSubarrays(int* nums, int numsSize, long long k)
//{
//    // 双单调队列
//    int max_q[numsSize], min_q[numsSize];
//    // 队列底和队列顶
//    int max_h = 0, max_t = -1;
//    int min_h = 0, min_t = -1;
//    long long ans = 0;
//    int r = 0;
//    //固定左端点，扩展右端点
//    for (int l = 0; l < numsSize; l++)
//    {
//        // 只要不碰到边界或是超出花费，可以一直拓展右边界
//        while (r < numsSize)
//        {
//            // 储存最大值的最大单调队列，小于等于当前元素的出栈
//            while (max_h <= max_t && nums[max_q[max_t]] <= nums[r])
//                max_t--;
//            //当前元素入栈
//            max_q[++max_t] = r;
//            // 储存最小值的最大单调队列，大于等于当前元素的出栈
//            while (min_h <= min_t && nums[min_q[min_t]] >= nums[r])
//                min_t--;
//            //当前元素入栈
//            min_q[++min_t] = r;
//
//            // 当前队列最大值和最小值，取队列底
//            int max_val = nums[max_q[max_h]];
//            int min_val = nums[min_q[min_h]];
//            // 当前花费
//            long long cost = 1LL * (max_val - min_val) * (r - l + 1);
//            // 超出花费，新入栈元素出栈
//            if (cost > k)
//            {
//                if (max_t >= max_h && max_q[max_t] == r)
//                    max_t--;
//                if (min_t >= min_h && min_q[min_t] == r)
//                    min_t--;
//                break;
//            }
//            else
//                r++;
//        }
//        ans += r - l;
//
//        // 超出队列左端点的队列底部出队
//        if (max_h <= max_t && max_q[max_h] == l)
//            max_h++;
//        if (min_h <= min_t && min_q[min_h] == l)
//            min_h++;
//    }
//    return ans;
//}
//
////539. 最小时间差
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findMinDifference(char** timePoints, int timePointsSize)
//{
//    int n = timePointsSize;
//    int times[n];
//    for (int i = 0; i < n; i++)
//    {
//        times[i] = (timePoints[i][0] * 10 + timePoints[i][1]) * 60
//            + timePoints[i][3] * 10 + timePoints[i][4];
//    }
//    qsort(times, n, sizeof(int), cmp);
//    int ans = 1440 + times[0] - times[n - 1];
//    for (int i = 0; i < n - 1; i++)
//    {
//        int d = times[i + 1] - times[i];
//        if (d < ans)
//            ans = d;
//    }
//    return ans;
//}
//
