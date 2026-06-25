//// 3737. 统计主要元素子数组数目 I
//
//int countMajoritySubarrays(int* nums, int numsSize, int target)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int sum = 0;
//        for (int j = i; j < numsSize; j++)
//        {
//            sum += nums[j] == target;
//            if (sum * 2 > j - i + 1)
//                ans++;
//        }
//    }
//    return ans;
//}
//
