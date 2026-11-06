//// 3824. 减小数组使其满足条件的最小 K 值
//
//bool check(int* nums, int n, int k)
//{
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += (nums[i] + k - 1) / k;
//        if (1ll * sum > 1ll * k * k)
//            return false;
//    }
//    return true;
//}
//int minimumK(int* nums, int numsSize)
//{
//    int left = 1, right = 1e5;
//    while (left <= right)
//    {
//        long long mid = (left + right) / 2;
//        if (check(nums, numsSize, mid))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
