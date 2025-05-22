////1561. 你可以获得的最大硬币数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maxCoins(int* piles, int pilesSize)
//{
//    qsort(piles, pilesSize, sizeof(int), cmp);
//    int left = 1, right = pilesSize - 1, ans = 0;
//    while (left + 1 <= right)
//    {
//        ans += piles[left];
//        left += 2; right--;
//    }
//    return ans;
//}
//
////3301. 高度互不相同的最大塔高和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maximumTotalSum(int* maximumHeight, int maximumHeightSize)
//{
//    qsort(maximumHeight, maximumHeightSize, sizeof(int), cmp);
//    long long ans = maximumHeight[0];
//    for (int i = 1; i < maximumHeightSize; i++)
//    {
//        maximumHeight[i] = fmin(maximumHeight[i], maximumHeight[i - 1] - 1);
//        ans += maximumHeight[i];
//        if (maximumHeight[i] <= 0)
//            return -1;
//    }
//    return ans;
//}
//
////945. 使数组唯一的最小增量
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minIncrementForUnique(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int moves = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] <= nums[i - 1])
//        {
//            moves += nums[i - 1] + 1 - nums[i];
//            nums[i] = nums[i - 1] + 1;
//        }
//    }
//    return moves;
//}
//
////1846. 减小和重新排列数组后的最大元素
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    arr[0] = 1;
//    for (int i = 1; i < arrSize; i++)
//    {
//        arr[i] = fmin(arr[i - 1] + 1, arr[i]);
//    }
//    return arr[arrSize - 1];
//}
//
