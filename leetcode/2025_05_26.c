////1509. 三次操作后最大值与最小值的最小差
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minDifference(int* nums, int numsSize)
//{
//    if (numsSize <= 4)
//        return 0;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int min = INT_MAX;
//    for (int i = 0; i < 4; i++)
//    {
//        min = fmin(min, nums[numsSize - 4 + i] - nums[i]);
//    }
//    return min;
//}
//
////3397. 执行操作后不同元素的最大数量
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxDistinctElements(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    nums[0] -= k;
//    for (int i = 1; i < numsSize; i++)
//    {
//        nums[i] = fmin(fmax(nums[i] - k, nums[i - 1] + 1), nums[i] + k);
//    }
//    int n = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > nums[i - 1])
//            n++;
//    }
//    return n;
//}
//
////1877. 数组中最大数对和的最小值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minPairSum(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < numsSize / 2; i++)
//    {
//        ans = fmax(ans, nums[i] + nums[numsSize - 1 - i]);
//    }
//    return ans;
//}
//
////881. 救生艇
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int numRescueBoats(int* people, int peopleSize, int limit)
//{
//    qsort(people, peopleSize, sizeof(int), cmp);
//    int ans = 0, right = peopleSize - 1;
//    for (int i = 0; i <= right; i++)
//    {
//        if (i != right && people[i] + people[right] <= limit)
//            right--;
//        ans++;
//    }
//    return ans;
//}
//
