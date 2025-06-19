////2656. K 个元素的最大和
//
//int maximizeSum(int* nums, int numsSize, int k)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(nums[i], max);
//    }
//    return max * k + (k - 1) * k / 2;
//}
//
////3164. 优质数对的总数 II
//
//long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
//{
//    int cnt[1000001] = { 0 };
//    for (int i = 0; i < nums1Size; i++)
//    {
//        if (nums1[i] % k)
//            continue;
//        int x = nums1[i] / k;
//        for (int j = 1; j * j <= x; j++)
//        {
//            if (x % j)
//                continue;
//
//            cnt[j]++;
//            if (j * j < x)
//                cnt[x / j]++;
//        }
//    }
//
//    long long ans = 0;
//    for (int i = 0; i < nums2Size; i++)
//    {
//        ans += cnt[nums2[i]];
//    }
//    return ans;
//}
//
////3194. 最小元素和最大元素的最小平均值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//double minimumAverage(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    double min = 101;
//    for (int i = 0; i < numsSize / 2; i++)
//    {
//        min = fmin(nums[i] + nums[numsSize - i - 1], min);
//    }
//    return min / 2.0;
//}
//
////3300. 替换为数位和以后的最小元素
//
//int minElement(int* nums, int numsSize)
//{
//    int min = 36;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int t = 0;
//        while (nums[i])
//        {
//            t += nums[i] % 10;
//            nums[i] /= 10;
//        }
//        min = fmin(t, min);
//    }
//    return min;
//}
//
