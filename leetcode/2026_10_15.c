//// LCR 059. 数据流中的第 K 大元素
//
//typedef struct
//{
//    int* heap;
//    int n;
//    int k;
//} KthLargest;
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0) break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j]) j++;
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void push(int* heap, int* n, int k, int x)
//{
//    if (*n < k)
//    {
//        heap[*n] = x;
//        up(heap, (*n)++);
//        return;
//    }
//    if (heap[0] < x)
//    {
//        heap[0] = x;
//        down(heap, 0, k);
//    }
//}
//
//KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
//{
//    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
//    obj->heap = (int*)malloc(sizeof(int) * k);
//    obj->n = 0;
//    obj->k = k;
//    for (int i = 0; i < numsSize; i++)
//    {
//        push(obj->heap, &obj->n, obj->k, nums[i]);
//    }
//    return obj;
//}
//
//int kthLargestAdd(KthLargest* obj, int val)
//{
//    push(obj->heap, &obj->n, obj->k, val);
//    return obj->heap[0];
//}
//
//void kthLargestFree(KthLargest* obj)
//{
//    free(obj->heap);
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
