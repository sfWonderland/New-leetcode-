////703. 数据流中的第 K 大元素
//
//typedef struct
//{
//    int* nums;
//    int n;
//    int k;
//} KthLargest;
//
//void swap(int* nums, int i, int j)
//{
//    int tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] < nums[j])
//            j++;
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//
//void HeapUp(int* nums, int i)
//{
//    int x = nums[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//        if (!j)
//            break;
//    }
//    nums[i] = x;
//}
//
//void BuildMinHeap(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//
//void HeapSort(int* nums, int n)
//{
//    BuildMinHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//
//KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
//{
//    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
//    obj->k = k;
//    HeapSort(nums, numsSize);
//    while (numsSize > k)
//    {
//        swap(nums, 0, numsSize - 1);
//        numsSize--;
//        HeapDown(nums, 0, numsSize);
//    }
//    obj->nums = (int*)malloc(sizeof(int) * k);
//    obj->n = fmin(k, numsSize);
//    for (int i = 0; i < obj->n; i++)
//    {
//        obj->nums[i] = nums[i];
//    }
//    return obj;
//}
//
//int kthLargestAdd(KthLargest* obj, int val)
//{
//    if (obj->n < obj->k)
//    {
//        obj->nums[obj->n++] = val;
//        HeapUp(obj->nums, obj->n - 1);
//    }
//    else if (obj->nums[0] < val)
//    {
//        obj->nums[0] = val;
//        HeapDown(obj->nums, 0, obj->k);
//    }
//
//    return obj->nums[0];
//}
//
//void kthLargestFree(KthLargest* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your KthLargest struct will be instantiated and called as such:
// * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
// * int param_1 = kthLargestAdd(obj, val);
//
// * kthLargestFree(obj);
//*/
//
////3275. 第 K 近障碍物查询
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] > nums[j])
//            j++;
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void HeapUp(int* nums, int i)
//{
//    int x = nums[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//        if (!j) break;
//    }
//    nums[i] = x;
//}
//void BuildMaxHeap(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(int* nums, int n)
//{
//    BuildMaxHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//int* resultsArray(int** queries, int queriesSize, int* queriesColSize, int k, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    int* heap = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int x = abs(queries[i][0]) + abs(queries[i][1]);
//        if (i < k)
//        {
//            heap[i] = x;
//            HeapUp(heap, i);
//            ans[i] = i < k - 1 ? -1 : heap[0];
//        }
//        else if (heap[0] > x)
//        {
//            heap[0] = x;
//            HeapDown(heap, 0, k);
//            ans[i] = heap[0];
//        }
//        else
//            ans[i] = heap[0];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////1845. 座位预约管理系统
//
//typedef struct
//{
//    int* heap;
//    int n;
//} SeatManager;
//
//void swap(int* nums, int i, int j)
//{
//    int tmp = nums[i];
//    nums[i] = nums[j];
//    nums[j] = tmp;
//}
//
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] < nums[j])
//            j++;
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//
//void HeapUp(int* nums, int i)
//{
//    int x = nums[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//        if (!j) break;
//    }
//    nums[i] = x;
//}
//
//SeatManager* seatManagerCreate(int n)
//{
//    SeatManager* obj = (SeatManager*)malloc(sizeof(SeatManager));
//    obj->heap = (int*)malloc(sizeof(int) * n);
//    obj->n = n;
//    for (int i = 0; i < n; i++)
//    {
//        obj->heap[i] = i + 1;
//    }
//    return obj;
//}
//
//int seatManagerReserve(SeatManager* obj)
//{
//    int x = obj->heap[0];
//    swap(obj->heap, 0, --obj->n);
//    HeapDown(obj->heap, 0, obj->n);
//    return x;
//}
//
//void seatManagerUnreserve(SeatManager* obj, int seatNumber)
//{
//    obj->heap[obj->n++] = seatNumber;
//    HeapUp(obj->heap, obj->n - 1);
//}
//
//void seatManagerFree(SeatManager* obj)
//{
//    free(obj->heap);
//    free(obj);
//}
//
///**
// * Your SeatManager struct will be instantiated and called as such:
// * SeatManager* obj = seatManagerCreate(n);
// * int param_1 = seatManagerReserve(obj);
//
// * seatManagerUnreserve(obj, seatNumber);
//
// * seatManagerFree(obj);
//*/
//
////面试题 16.01. 交换数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* swapNumbers(int* numbers, int numbersSize, int* returnSize)
//{
//    numbers[0] ^= numbers[1];
//    numbers[1] ^= numbers[0];
//    numbers[0] ^= numbers[1];
//    *returnSize = 2;
//    return numbers;
//}
//
