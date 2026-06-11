//// 410. 分割数组的最大值
//
//int splitArray(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[i + 1] = pre[i] + nums[i];
//    }
//    int f[n][k];
//    for (int i = 0; i < n; i++)
//    {
//        f[i][0] = pre[i + 1];
//        for (int t = 1; t < k; t++)
//        {
//            int res = INT_MAX;
//            for (int j = i; j >= t; j--)
//            {
//                res = fmin(res, fmax(f[j - 1][t - 1], pre[i + 1] - pre[j]));
//            }
//            f[i][t] = res;
//        }
//    }
//    return f[n - 1][k - 1];
//}
//
//int splitArray(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int mx = 0, sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        mx = fmax(mx, nums[i]);
//        sum += nums[i];
//    }
//
//    int check(int mx)
//    {
//        int cnt = 1, s = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (s + nums[i] <= mx)
//            {
//                s += nums[i];
//                continue;
//            }
//
//            if (cnt == k || nums[i] > mx)
//                return false;
//
//            cnt++;
//            s = nums[i];
//        }
//        return true;
//    }
//
//    int left = mx - 1, right = sum;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (check(mid))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
