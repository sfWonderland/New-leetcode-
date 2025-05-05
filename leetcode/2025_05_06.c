////1920. 基于排列构建数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // int* buildArray(int* nums, int numsSize, int* returnSize) 
// // {
// //     int* ans = (int*)malloc(sizeof(int) * numsSize);
// //     memset(ans, 0, sizeof(int) * numsSize);
// //     for(int i = 0; i < numsSize; ++i)
// //     {
// //         ans[i] = nums[nums[i]];
// //     }    
// //     *returnSize = numsSize;
// //     return ans;
// // }
//int* buildArray(int* nums, int numsSize, int* returnSize)
//{
//    for (int i = 0; i < numsSize; ++i)
//    {
//        int x = nums[i];
//        if (x < 0)
//            continue;
//
//        int cur = i;
//        while (nums[cur] != i)
//        {
//            int nxt = nums[cur];
//            nums[cur] = ~nums[nxt];
//            cur = nxt;
//        }
//        nums[cur] = ~x;
//    }
//    for (int i = 0; i < numsSize; ++i)
//    {
//        nums[i] = ~nums[i];
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////1248. 统计「优美子数组」
//
//int numberOfSubarrays(int* nums, int numsSize, int k)
//{
//    int ans = 0, left[2] = { 0 }, sum[2] = { 0 };
//    for (int i = 0; i < numsSize; ++i)
//    {
//        if (nums[i] & 1)
//        {
//            ++sum[0];
//            ++sum[1];
//        }
//
//        while (sum[0] >= k)
//        {
//            sum[0] -= nums[left[0]] & 1;
//            ++left[0];
//        }
//        while (sum[1] > k)
//        {
//            sum[1] -= nums[left[1]] & 1;
//            ++left[1];
//        }
//        ans += left[0] - left[1];
//    }
//    return ans;
//}
//
////713. 乘积小于 K 的子数组
//
//int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
//{
//    int ans = 0, left = 0, multi = 1;
//    for (int right = 0; right < numsSize; right++)
//    {
//        multi *= nums[right];
//
//        while (left <= right && multi >= k)
//        {
//            multi /= nums[left];
//            ++left;
//        }
//        ans += right - left + 1;
//    }
//    return ans;
//}
//
////2553. 分割数组中数字的数位
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int t = nums[left];
//        nums[left++] = nums[right];
//        nums[right--] = t;
//    }
//}
//int* separateDigits(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 6 * numsSize);
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int t = nums[i], left = n;
//        while (t)
//        {
//            ans[n++] = t % 10;
//            t /= 10;
//        }
//        reverse(ans, left, n - 1);
//    }
//    *returnSize = n;
//    return ans;
//}
//
