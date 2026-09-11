//// 4044. 统计好循环移位的数量
//
//int countGoodRotations(int* nums, int numsSize)
//{
//    int n = numsSize, ans = 0;
//    long long sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += i < n / 2 ? nums[i] : -nums[i];
//        // printf("%d ", sum);
//    }
//    // printf("\n");
//    if (sum > 0) ans++;
//    for (int i = 0; i < n - 1; i++)
//    {
//        sum += 2 * (nums[(n / 2 + i) % n] - nums[i]);
//        // printf("%d ", sum);
//        if (sum > 0) ans++;
//    }
//    // printf("\n");
//    return ans;
//}
//
