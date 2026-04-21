//// LCR 061. 查找和最小的 K 对数字
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//
//void up(int* heap, int** nums, int i)
//{
//    int sum = heap[i];
//    int x = nums[i][0], y = nums[i][1];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= sum)
//            break;
//
//        heap[i] = heap[j];
//        nums[i][0] = nums[j][0];
//        nums[i][1] = nums[j][1];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = sum;
//    nums[i][0] = x, nums[i][1] = y;
//}
//
//void down(int* heap, int** nums, int i, int n)
//{
//    int sum = heap[i];
//    int x = nums[i][0], y = nums[i][1];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] <= sum)
//            break;
//
//        heap[i] = heap[j];
//        nums[i][0] = nums[j][0];
//        nums[i][1] = nums[j][1];
//        i = j;
//    }
//    heap[i] = sum;
//    nums[i][0] = x, nums[i][1] = y;
//}
//
//void push(int* sum, int** nums, int* size, int n, int x, int y)
//{
//    if (*size < n)
//    {
//        nums[*size] = (int*)malloc(sizeof(int) * 2);
//        nums[*size][0] = x;
//        nums[*size][1] = y;
//        sum[*size] = x + y;
//        up(sum, nums, *size);
//        (*size)++;
//    }
//    else
//    {
//        sum[0] = x + y;
//        nums[0][0] = x, nums[0][1] = y;
//        down(sum, nums, 0, n);
//    }
//}
//int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
//{
//    int* sum = (int*)malloc(sizeof(int) * k);
//    int** nums = (int**)malloc(sizeof(int*) * k);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
//    int size = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        for (int j = 0; j < nums2Size; j++)
//        {
//            if (size == k && sum[0] <= nums1[i] + nums2[j])
//                break;
//            push(sum, nums, &size, k, nums1[i], nums2[j]);
//        }
//    }
//    *returnSize = size;
//    for (int i = 0; i < size; i++)
//    {
//        (*returnColumnSizes)[i] = 2;
//        // printf("%d %d %d\n", nums[i][0], nums[i][1], sum[i]);
//    }
//    free(sum);
//    return nums;
//}
//
//// LCR 067. 数组中两个数的最大异或值   
//
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int findMaximumXOR(int* nums, int numsSize)
//{
//    int high_bit = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i])
//            high_bit = fmax(high_bit, 31 - __builtin_clz(nums[i]));
//    }
//    int ans = 0, mask = 0;
//    HashItem* seen = NULL;
//    for (int i = high_bit; i >= 0; i--)
//    {
//        mask |= 1 << i;
//        int new_ans = ans | (1 << i);
//        for (int j = 0; j < numsSize; j++)
//        {
//            int x = nums[j] & mask;
//            int key = x ^ new_ans;
//            HashItem* p = NULL;
//            HASH_FIND_INT(seen, &key, p);
//            if (p)
//            {
//                ans = new_ans;
//                break;
//            }
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = x;
//            HASH_ADD_INT(seen, key, p);
//        }
//
//        HashItem* p = NULL, * tmp = NULL;
//        HASH_ITER(hh, seen, p, tmp)
//        {
//            HASH_DEL(seen, p);
//            free(p);
//        }
//    }
//    return ans;
//}
//
////LCR 068. 搜索插入位置
//
//int searchInsert(int* nums, int numsSize, int target)
//{
//    if (nums[0] > target)
//        return 0;
//    if (nums[numsSize - 1] < target)
//        return numsSize;
//    int left = 0, right = numsSize - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= target)
//            right--;
//        else
//            left++;
//    }
//    return left;
//}
//
////LCR 069. 山脉数组的峰顶索引
//
//int peakIndexInMountainArray(int* arr, int arrSize)
//{
//    int left = 0, right = arrSize;
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] > arr[mid + 1])
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
