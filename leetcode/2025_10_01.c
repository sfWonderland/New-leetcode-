////1046. 最后一块石头的重量
//
//void HeapAdjust(int* nums, int k, int len)
//{
//    nums[0] = nums[k];
//    for (int i = 2 * k; i <= len; i *= 2)
//    {
//        if (i < len && nums[i + 1] < nums[i])
//            i++;
//        if (nums[i] >= nums[0])
//            break;
//        else
//        {
//            nums[k] = nums[i];
//            k = i;
//        }
//    }
//    nums[k] = nums[0];
//}
//void BuildMinHeap(int* nums, int len)
//{
//    for (int i = len / 2; i > 0; i--)
//    {
//        HeapAdjust(nums, i, len);
//    }
//}
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void HeapSort(int* nums, int len)
//{
//    BuildMinHeap(nums, len);
//    for (int i = len; i > 1; i--)
//    {
//        swap(&nums[1], &nums[i]);
//        HeapAdjust(nums, 1, i - 1);
//    }
//}
//int lastStoneWeight(int* stones, int stonesSize)
//{
//    int n = stonesSize;
//    int* nums = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        nums[i + 1] = stones[i];
//    }
//    while (n > 1)
//    {
//        HeapSort(nums, n);
//        int x = 2;
//        if (x < n && nums[x] < nums[x + 1])
//        {
//            x++;
//        }
//        nums[x] = nums[1] - nums[x];
//        nums[1] = nums[n--];
//        nums[x] = nums[x] ? nums[x] : nums[n--];
//    }
//    return nums[1];
//}
//
////3264. K 次乘运算后的最终数组 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize)
//{
//    while (k--)
//    {
//        int min = 0;
//        for (int i = 1; i < numsSize; i++)
//        {
//            if (nums[min] > nums[i])
//                min = i;
//        }
//        nums[min] *= multiplier;
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////2558. 从数量最多的堆取走礼物
//
//void HeapAdjust(int* nums, int k, int len)
//{
//    int tmp = nums[k];
//    for (int i = 2 * k + 1; i < len; i = 2 * i + 1)
//    {
//        if (i < len - 1 && nums[i + 1] < nums[i])
//            i++;
//        if (nums[i] >= tmp)
//            break;
//        else
//        {
//            nums[k] = nums[i];
//            k = i;
//        }
//    }
//    nums[k] = tmp;
//}
//void BuildMinHeap(int* nums, int len)
//{
//    for (int i = len / 2 - 1; i >= 0; i--)
//    {
//        HeapAdjust(nums, i, len);
//    }
//}
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void HeapSort(int* nums, int len)
//{
//    BuildMinHeap(nums, len);
//    for (int i = len - 1; i > 0; i--)
//    {
//        swap(&nums[0], &nums[i]);
//        HeapAdjust(nums, 0, i);
//    }
//}
//long long pickGifts(int* gifts, int giftsSize, int k)
//{
//    HeapSort(gifts, giftsSize);
//    while (k--)
//    {
//        gifts[0] = sqrt(gifts[0]);
//        HeapSort(gifts, giftsSize);
//    }
//    long long ans = 0;
//    for (int i = 0; i < giftsSize; i++)
//    {
//        ans = ans + gifts[i];
//    }
//    return ans;
//}
//
////3684. 至多 K 个不同元素的最大和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int* maxKDistinct(int* nums, int numsSize, int k, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int x = -1, idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (x == nums[i])
//            continue;
//
//        nums[idx++] = nums[i];
//        x = nums[i];
//    }
//    *returnSize = fmin(idx, k);
//    return nums;
//}
//
