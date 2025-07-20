////1749. 任意子数组和的绝对值的最大值
//
//int maxAbsoluteSum(int* nums, int numsSize)
//{
//    int f[numsSize + 1][2];
//    int max = INT_MIN, min = INT_MAX;
//    f[0][0] = 0; f[0][1] = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        f[i + 1][0] = fmax(f[i][0], 0) + nums[i];
//        f[i + 1][1] = fmin(f[i][1], 0) + nums[i];
//        max = fmax(max, f[i + 1][0]);
//        min = fmin(min, f[i + 1][1]);
//    }
//    max = abs(max), min = abs(min);
//    return max > min ? max : min;
//}
//
////1191. K 次串联后最大子数组之和
//
//#define mod 1000000007
//int maxSubArray(int* nums, int numsSize, int repeat)
//{
//    int pre = 0, max = 0;
//    for (int i = 0; i < numsSize * repeat; i++)
//    {
//        pre = fmax(pre, 0) + nums[i % numsSize];
//        max = fmax(max, pre);
//    }
//    return max;
//}
//int kConcatenationMaxSum(int* arr, int arrSize, int k)
//{
//    if (k == 1)
//        return maxSubArray(arr, arrSize, 1);
//
//    long long ans = maxSubArray(arr, arrSize, 2);
//    int sum = 0;
//    for (int i = 0; i < arrSize; i++)
//    {
//        sum += arr[i];
//    }
//    ans += 1ll * fmax(sum, 0) * (k - 2);
//    return ans % mod;
//}
//
////918. 环形子数组的最大和
//
//int maxSubarraySumCircular(int* nums, int numsSize)
//{
//    int sum = 0, pre1 = 0, pre2 = 0, max = INT_MIN, min = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        pre1 = fmax(pre1, 0) + nums[i];
//        pre2 = fmin(pre2, 0) + nums[i];
//        max = fmax(max, pre1);
//        min = fmin(min, pre2);
//    }
//    return min == sum ? max : fmax(max, sum - min);
//}
//
////2321. 拼接数组的最大分数
//
//int maximumsSplicedArray(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int sum1 = 0, sum2 = 0;
//    int pre1 = 0, pre2 = 0, max = 0, min = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        sum1 += nums1[i];
//        sum2 += nums2[i];
//        pre1 = fmax(pre1, 0) + nums2[i] - nums1[i];
//        max = fmax(max, pre1);
//        pre2 = fmin(pre2, 0) + nums2[i] - nums1[i];
//        min = fmin(min, pre2);
//    }
//    return fmax(max + sum1, sum2 - min);
//}
//
