////LCR 089. 打家劫舍
//
//int rob(int* nums, int numsSize)
//{
//    int f0 = 0, f1 = 0, f2 = 0;;
//    for (int i = 0; i < numsSize; i++)
//    {
//        f2 = fmax(f1, f0 + nums[i]);
//        f0 = f1;
//        f1 = f2;
//    }
//    return f2;
//}
//
////LCR 090. 打家劫舍 II
//
//int rob0(int* nums, int l, int r)
//{
//    int f0 = 0, f1 = 0, f2 = 0;;
//    for (int i = l; i <= r; i++)
//    {
//        f2 = fmax(f1, f0 + nums[i]);
//        f0 = f1;
//        f1 = f2;
//    }
//    return f2;
//}
//int rob(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//        return 0;
//    if (numsSize == 1)
//        return nums[0];
//    if (numsSize == 2)
//        return fmax(nums[0], nums[1]);
//    return fmax(rob0(nums, 1, numsSize - 1), rob0(nums, 2, numsSize - 2) + nums[0]);
//}
//
////3171. 找到按位或最接近 K 的子数组
//
//int minimumDifference(int* nums, int numsSize, int k)
//{
//    int ans = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        ans = fmin(ans, abs(x - k));
//        for (int j = i - 1; j >= 0 && nums[j] != (nums[j] | x); j--)
//        {
//            nums[j] |= x;
//            ans = fmin(ans, abs(nums[j] - k));
//        }
//    }
//    return ans;
//}
//
////2411. 按位或最大的最小子数组长度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* smallestSubarrays(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        ans[i] = 1;
//        for (int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j--)
//        {
//            nums[j] |= x;
//            ans[j] = i - j + 1;
//        }
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
