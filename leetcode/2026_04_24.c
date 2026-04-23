//// LCR 074. 合并区间
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = intervalsSize;
//    qsort(intervals, n, sizeof(int*), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * (n + 1));
//    *returnColumnSizes = (int*)malloc(sizeof(int*) * n);
//    int pos = 0;
//    ans[pos] = (int*)malloc(sizeof(int) * 2);
//    ans[pos][0] = -1; ans[pos++][1] = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (intervals[i][1] < ans[pos - 1][1])
//            continue;
//        if (intervals[i][0] > ans[pos - 1][1])
//        {
//            ans[pos] = (int*)malloc(sizeof(int) * 2);
//            (*returnColumnSizes)[pos - 1] = 2;
//            ans[pos++][0] = intervals[i][0];
//        }
//        ans[pos - 1][1] = intervals[i][1];
//    }
//    *returnSize = pos - 1;
//    return ans + 1;
//}
//
//// LCR 075. 数组的相对排序   
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
//{
//    int max = 0;
//    for (int i = 0; i < arr1Size; i++)
//    {
//        if (max < arr1[i])
//            max = arr1[i];
//    }
//    int cnt[max + 1];
//    memset(cnt, 0, sizeof(cnt));
//    for (int i = 0; i < arr1Size; i++)
//    {
//        cnt[arr1[i]]++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * arr1Size);
//    int pos = 0;
//    for (int i = 0; i < arr2Size; i++)
//    {
//        while (cnt[arr2[i]])
//        {
//            ans[pos++] = arr2[i];
//            cnt[arr2[i]]--;
//        }
//    }
//    for (int i = 0; i <= max; i++)
//    {
//        while (cnt[i])
//        {
//            ans[pos++] = i;
//            cnt[i]--;
//        }
//    }
//    *returnSize = pos;
//    return ans;
//}
//
//// LCR 076. 数组中的第 K 个最大元素
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void push(int* heap, int* heapSize, int n, int x)
//{
//    if (*heapSize < n)
//    {
//        heap[*heapSize] = x;
//        up(heap, *heapSize);
//        (*heapSize)++;
//    }
//    else if (heap[0] < x)
//    {
//        heap[0] = x;
//        down(heap, 0, n);
//    }
//}
//
//int findKthLargest(int* nums, int numsSize, int k)
//{
//    int heap[k];
//    int pos = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        push(heap, &pos, k, nums[i]);
//    }
//    return heap[0];
//}
//
//// LCR 078. 合并 K 个升序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//void up(struct ListNode** heap, int i)
//{
//    struct ListNode* x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j]->val <= x->val)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void down(struct ListNode** heap, int i, int n)
//{
//    struct ListNode* x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1]->val < heap[j]->val)
//            j++;
//
//        if (heap[j]->val >= x->val)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    struct ListNode** heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
//    int heapSize = 0;
//    for (int i = 0; i < listsSize; i++)
//    {
//        if (lists[i])
//        {
//            heap[heapSize] = lists[i];
//            up(heap, heapSize);
//            heapSize++;
//        }
//    }
//    if (heapSize == 1)
//        return heap[0];
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    while (heapSize)
//    {
//        cur->next = heap[0];
//        cur = heap[0];
//        if (heap[0]->next)
//        {
//            heap[0] = heap[0]->next;
//        }
//        else
//        {
//            heap[0] = heap[--heapSize];
//        }
//        down(heap, 0, heapSize);
//    }
//    cur->next = NULL;
//    return dummy->next;
//}
//
