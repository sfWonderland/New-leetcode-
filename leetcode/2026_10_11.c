//// 912. ÅÅÐòÊý×é
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // QUICK SORT
//#define SWAP(a, b) do {int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//int partition(int* nums, int low, int high)
//{
//    int pos = low + rand() % (high - low + 1);
//    SWAP(nums[low], nums[pos]);
//    int i = low + 1, j = high;
//    while (1)
//    {
//        while (i <= j && nums[i] < nums[low]) i++;
//        while (i <= j && nums[j] > nums[low]) j--;
//        if (i >= j) break;
//        SWAP(nums[i], nums[j]);
//        i++; j--;
//    }
//    SWAP(nums[low], nums[j]);
//    return j;
//}
//void sort(int* nums, int low, int high)
//{
//    bool ordered = true;
//    for (int i = low; i < high && ordered; i++)
//    {
//        if (nums[i] > nums[i + 1])
//            ordered = false;
//    }
//    if (ordered) return;
//    int pos = partition(nums, low, high);
//    sort(nums, low, pos - 1);
//    sort(nums, pos + 1, high);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    srand(time(NULL));
//    sort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
//// Shell sort has a worst-case time complexity of O(n^2), violating the O(n log n) requirement.
//#define SWAP(a, b) do {int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//void sort(int* nums, int n)
//{
//    for (int d = n / 2; d >= 1; d /= 2)
//    {
//        for (int i = d; i < n; i++)
//        {
//            if (nums[i] < nums[i - d])
//            {
//                int tmp = nums[i], j = i - d;
//                for (; j >= 0 && nums[j] > tmp; j -= d)
//                {
//                    SWAP(nums[j], nums[j + d]);
//                }
//                nums[j + d] = tmp;
//            }
//        }
//    }
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    sort(nums, numsSize);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // Bubble sort is a quadratic sorting algorithm, which is explicitly prohibited.
//#define SWAP(a, b) do {int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//void bubbleSort(int* nums, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = n - 1; j > i; j--)
//        {
//            if (nums[j] < nums[j - 1])
//                SWAP(nums[j], nums[j - 1]);
//        }
//    }
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    bubbleSort(nums, numsSize);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // maxHeap
//#define SWAP(a, b) do {int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0) break;
//    }
//    heap[i] = x;
//}
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j]) j++;
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void push(int* nums, int* n, int x)
//{
//    nums[*n] = x;
//    up(nums, (*n)++);
//}
//void pop(int* nums, int n)
//{
//    SWAP(nums[0], nums[n - 1]);
//    down(nums, 0, n - 1);
//}
//void heapSort(int* nums, int n)
//{
//    int size = 0;
//    for (int i = 0; i < n; i++)
//    {
//        push(nums, &size, nums[i]);
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        pop(nums, n - i);
//    }
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    heapSort(nums, numsSize);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // Selection sort is a quadratic sorting algorithm, which is explicitly prohibited.
//#define SWAP(a, b) do {int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//void SelectSort(int* nums, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        int pos = i;
//        for (int j = i; j < n; j++)
//        {
//            if (nums[j] < nums[pos])
//                pos = j;
//        }
//        SWAP(nums[i], nums[pos]);
//    }
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    SelectSort(nums, numsSize);
//    *returnSize = numsSize;
//    return nums;
//}
//
//// mergeSort
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arr;
//void merge(int* nums, int low, int mid, int high)
//{
//    memcpy(arr + low, nums + low, sizeof(int) * (high - low + 1));
//    int i = low, j = mid + 1, k = low;
//    while (i <= mid && j <= high)
//    {
//        if (arr[i] <= arr[j])
//            nums[k++] = arr[i++];
//        else
//            nums[k++] = arr[j++];
//    }
//    while (i <= mid) nums[k++] = arr[i++];
//    while (j <= high) nums[k++] = arr[j++];
//}
//void mergeSort(int* nums, int low, int high)
//{
//    if (low < high)
//    {
//        int mid = (low + high) / 2;
//        mergeSort(nums, low, mid);
//        mergeSort(nums, mid + 1, high);
//        merge(nums, low, mid, high);
//    }
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    arr = (int*)malloc(sizeof(int) * numsSize);
//    mergeSort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// //baseSort
//typedef struct
//{
//    struct ListNode* dummy;
//    struct ListNode* tail;
//}Queue;
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = numsSize;
//    if (numsSize == 1) return nums;
//    Queue* queues = (Queue*)malloc(sizeof(Queue) * 10);
//    for (int i = 0; i < 10; i++)
//    {
//        queues[i].dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//        queues[i].dummy->next = NULL;
//        queues[i].tail = queues[i].dummy;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = nums[i] + 50000;
//        node->next = NULL;
//        queues[node->val % 10].tail->next = node;
//        queues[node->val % 10].tail = node;
//    }
//    int base = 1;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    while (base <= 100000)
//    {
//        dummy->next = NULL;
//        struct ListNode* tail = dummy;
//        for (int i = 0; i < 10; i++)
//        {
//            if (queues[i].dummy->next)
//            {
//                tail->next = queues[i].dummy->next;
//                tail = queues[i].tail;
//                queues[i].dummy->next = NULL;
//                queues[i].tail = queues[i].dummy;
//            }
//        }
//        base *= 10;
//        struct ListNode* nxt;
//        bool ordered = true;
//        int pre = 0;
//        for (struct ListNode* node = dummy->next; node; node = nxt)
//        {
//            if (node->val < pre) ordered = false;
//            pre = node->val;
//            nxt = node->next;
//            int x = (node->val / base) % 10;
//            queues[x].tail->next = node;
//            queues[x].tail = node;
//            node->next = NULL;
//        }
//        if (ordered) break;
//    }
//    struct ListNode* nxt;
//    int k = 0;
//    for (struct ListNode* cur = dummy->next; cur; cur = nxt)
//    {
//        nxt = cur->next;
//        nums[k++] = cur->val - 50000;
//        free(cur);
//    }
//    free(dummy);
//    for (int i = 0; i < 10; i++)
//    {
//        free(queues[i].dummy);
//    }
//    free(queues);
//    return nums;
//}
//
