//// 264. 丑数 II
//
//static int init = 0;
//static int ugly[1690];
//int nthUglyNumber(int n)
//{
//    if (init == 0)
//    {
//        ugly[0] = 1;
//        int i2 = 0;
//        int i3 = 0;
//        int i5 = 0;
//        for (int i = 1; i < 1690; i++)
//        {
//            int l2 = ugly[i2] * 2;
//            int l3 = ugly[i3] * 3;
//            int l5 = ugly[i5] * 5;
//            ugly[i] = fmin(fmin(l2, l3), l5);
//            if (ugly[i] == l2) i2++;
//            if (ugly[i] == l3) i3++;
//            if (ugly[i] == l5) i5++;
//        }
//        init = 1;
//    }
//    return ugly[n - 1];
//}
//
//// 378. 有序矩阵中第 K 小的元素   
//
//// maxHeap
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
//
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
//bool push(int* heap, int* n, int k, int x)
//{
//    if (*n < k)
//    {
//        heap[*n] = x;
//        up(heap, (*n)++);
//        return true;
//    }
//    if (heap[0] > x)
//    {
//        heap[0] = x;
//        down(heap, 0, k);
//        return true;
//    }
//    return false;
//}
//int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
//{
//    int heap[k];
//    int n = 0;
//    for (int i = 0; i < matrixSize; i++)
//    {
//        for (int j = 0; j < matrixColSize[i]; j++)
//        {
//            if (!push(heap, &n, k, matrix[i][j])) break;
//        }
//    }
//    return heap[0];
//}
//
//// minHeap
//
//void down(int** heap, int* heapSize, int i, int n)
//{
//    int* tmp = heap[i];
//    int x = heapSize[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heapSize[j + 1] && heap[j + 1][0] < heap[j][0]) j++;
//        if (!heapSize[j] || heap[j][0] >= tmp[0]) break;
//        heapSize[i] = heapSize[j];
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = tmp;
//    heapSize[i] = x;
//}
//
//int pop(int** heap, int* heapSize, int* n)
//{
//    int x = heap[0][0];
//    heapSize[0]--;
//    heap[0]++;
//    if (!heapSize[0])
//    {
//        heap[0] = heap[--(*n)];
//        heapSize[0] = heapSize[*n];
//    }
//    down(heap, heapSize, 0, *n);
//    return x;
//}
//int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
//{
//    int n = matrixSize;
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(matrix, matrixColSize, i, n);
//    }
//    int x;
//    while (k)
//    {
//        x = pop(matrix, matrixColSize, &n);
//        k--;
//    }
//    return x;
//}
//
//// 23. 合并 K 个升序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void down(struct ListNode** heap, int i, int n)
//{
//    struct ListNode* tmp = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1]->val < heap[j]->val) j++;
//        if (heap[j]->val >= tmp->val) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = tmp;
//}
//
//struct ListNode* pop(struct ListNode** heap, int* n)
//{
//    struct ListNode* x = heap[0];
//    heap[0] = heap[0]->next;
//    if (!heap[0])
//        heap[0] = heap[--(*n)];
//    down(heap, 0, *n);
//    return x;
//}
//
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    int n = 0;
//    for (int i = 0; i < listsSize; i++)
//    {
//        if (lists[i]) lists[n++] = lists[i];
//    }
//    if (n == 0) return NULL;
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(lists, i, n);
//    }
//    if (!lists[0]) return NULL;
//    struct ListNode* head = pop(lists, &n);
//    struct ListNode* cur = head;
//    while (lists[0])
//    {
//        cur->next = pop(lists, &n);
//        cur = cur->next;
//    }
//    return head;
//}
//
