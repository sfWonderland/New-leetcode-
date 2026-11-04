//// 1283. 使结果不超过阈值的最小除数
//
//bool check(int* nums, int n, int div, int target)
//{
//    for (int i = 0; i < n; i++)
//    {
//        target -= (nums[i] + div - 1) / div;
//    }
//    return target >= 0;
//}
//int smallestDivisor(int* nums, int numsSize, int threshold)
//{
//    int n = numsSize, mx = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        mx = mx < nums[i] ? nums[i] : mx;
//    }
//
//    int left = 1, right = mx;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (check(nums, n, mid, threshold))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
