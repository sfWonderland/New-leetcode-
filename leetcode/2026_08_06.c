//// 23. 合并 K 个升序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void up(struct ListNode** heap, int i)
//{
//    struct ListNode* node = heap[i];
//    int x = node ? node->val : INT_MAX;
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        int y = heap[j] ? heap[j]->val : INT_MAX;
//        if (y <= x)
//            break;
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = node;
//}
//void down(struct ListNode** heap, int i, int n)
//{
//    struct ListNode* node = heap[i];
//    int x = node ? node->val : INT_MAX;
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        int y = heap[j] ? heap[j]->val : INT_MAX;
//        if (j < n - 1)
//        {
//            int y1 = heap[j + 1] ? heap[j + 1]->val : INT_MAX;
//            if (y1 < y)
//            {
//                j++;
//                y = y1;
//            }
//        }
//        if (y >= x)
//            break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = node;
//}
//void push(struct ListNode** heap, struct ListNode* list, int i)
//{
//    heap[i] = list;
//    up(heap, i);
//}
//struct ListNode* pop(struct ListNode** heap, int n)
//{
//    struct ListNode* res = heap[0];
//    heap[0] = res->next;
//    res->next = NULL;
//    down(heap, 0, n);
//    return res;
//}
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    int n = listsSize;
//    if (n == 0) return NULL;
//    struct ListNode** heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        push(heap, lists[i], i);
//    }
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    while (heap[0])
//    {
//        struct ListNode* node = pop(heap, n);
//        cur->next = node;
//        cur = node;
//    }
//    struct ListNode* ans = dummy->next;
//    free(heap);
//    free(dummy);
//    return ans;
//}
//
