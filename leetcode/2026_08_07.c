//// 4010. 数对的最大强度
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//long long maxPairStrength(int* nums, int numsSize)
//{
//    int n = numsSize;
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            int d = gcd(nums[i], nums[j]);
//            // printf("%d %d %d\n", nums[i], nums[j], d);
//            ans = fmax(ans, 1ll * nums[i] / d * nums[j] / d);
//        }
//    }
//    return ans;
//}
//
//// 4011. 按奇偶比统计子数组 I    
//
//int countRatioSubarrays(int* nums, int numsSize, int a, int b)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int cnt[2] = { 0 };
//        for (int j = i; j < numsSize; j++)
//        {
//            cnt[nums[j] & 1]++;
//            if (cnt[0] * b - cnt[1] * a <= 0)
//                ans++;
//        }
//    }
//    return ans;
//}
//
//// 4012. 统计每个班次结束后的未完成任务数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int binary(long long* nums, int n, long long x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] > x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int* countTasks(int* tasks, int tasksSize, int* shifts, int shiftsSize, int* returnSize)
//{
//    int n = tasksSize;
//    long long prefix[n + 1];
//    prefix[0] = 0;
//    for (int i = 0; i < tasksSize; i++)
//    {
//        prefix[i + 1] = prefix[i] + tasks[i];
//    }
//    int m = shiftsSize;
//    int* ans = (int*)malloc(sizeof(int) * m);
//    long long worktime = 0;
//    for (int i = 0; i < m; i++)
//    {
//        if (worktime + shifts[i] >= prefix[n])
//        {
//            ans[i] = 0;
//            worktime = 0;
//        }
//        else
//        {
//            int k = binary(prefix, n + 1, worktime + shifts[i]);
//            if (prefix[k] > worktime + shifts[i])
//                k--;
//            ans[i] = n - k;
//            worktime += shifts[i];
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
