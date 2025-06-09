////2740. 找出分区值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findValueOfPartition(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = INT_MAX;
//    for (int i = 1; i < numsSize; i++)
//    {
//        ans = fmin(nums[i] - nums[i - 1], ans);
//    }
//    return ans;
//}
//
////1033. 移动石子直到连续
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* numMovesStones(int a, int b, int c, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    int arr[3] = { a, b, c };
//    qsort(arr, 3, sizeof(int), cmp);
//    ret[1] = arr[2] - arr[0] - 2;
//    ret[0] = (arr[1] <= arr[0] + 2) || (arr[2] <= arr[1] + 2) ? (arr[2] - arr[0] > 2) : 2;
//    *returnSize = 2;
//    return ret;
//}
//
////3523. 非递减数组的最大长度
//
//int maximumPossibleSize(int* nums, int numsSize)
//{
//    int max = nums[0], ans = numsSize;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (max <= nums[i])
//            max = nums[i];
//        else
//            ans--;
//    }
//    return ans;
//}
//
////1864. 构成交替字符串需要的最小交换次数
//
//int minSwaps(char* s)
//{
//    int test = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        test += (s[i] == '1') ? 1 : -1;
//    }
//    if (abs(test) > 1)
//        return -1;
//    int plan[2] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        if ('1' == s[i])
//            plan[i & 1]++;
//        else
//            plan[(i + 1) & 1]++;
//    }
//    int ans = 0, a = plan[0] & 1, b = plan[1] & 1;
//    if (a)
//        ans = b ? -1 : plan[1] / 2;
//    else
//        ans = b ? plan[0] / 2 : fmin(plan[1], plan[0]) / 2;
//
//    return ans;
//}
//
