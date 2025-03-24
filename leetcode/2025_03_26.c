////2058. 找出临界点之间的最小和最大距离
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int is_peak(int num, int left, int right)
//{
//    return (((num - left) > 0 && (num - right) > 0) || ((num - left) < 0 && (num - right) < 0));
//}
//int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
//{
//    int* res = (int*)malloc(sizeof(int) * 2);
//    res[0] = INT_MAX;
//    res[1] = -1;
//    struct ListNode* pre = head;
//    struct ListNode* p = head->next;
//    struct ListNode* q = p->next;
//    int n = 1;
//    int left = 0;
//    int right = 0;
//    while (q)
//    {
//        if (is_peak(p->val, pre->val, q->val))
//        {
//            if (0 == left)
//                left = n;
//
//            res[0] = right ? fmin(res[0], n - right) : n - left;
//            right = n;
//        }
//
//        pre = p;
//        p = q;
//        q = q->next;
//        n++;
//    }
//    res[1] = right > left ? right - left : -1;
//    returnSize[0] = 2;
//    if (!(left && right))
//        res[0] = -1;
//    return res;
//}
//
////2181. 合并零之间的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeNodes(struct ListNode* head)
//{
//    struct ListNode* fast = head->next;
//    struct ListNode* slow = head;
//    while (fast->next)
//    {
//        if (fast->val)
//            slow->val += fast->val;
//        else
//        {
//            slow = slow->next;
//            slow->val = 0;
//        }
//
//        fast = fast->next;
//    }
//    // struct ListNode* s = slow -> next;
//    // while(s)
//    // {
//    //     struct ListNode* t = s;
//    //     s = s -> next;
//    //     free(t);
//    // }
//    slow->next = NULL;
//    return head;
//}
//
////817. 链表组件
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int numComponents(struct ListNode* head, int* nums, int numsSize)
//{
//    int* h = (int*)malloc(sizeof(int) * 20001);
//    memset(h, 0, sizeof(int) * 20001);
//    for (int i = 0; i < numsSize; i++)
//    {
//        h[nums[i]] = 1;
//    }
//    struct ListNode* p = head;
//    int n = 0;
//    int flag = 0;
//    while (p)
//    {
//        if (flag && 0 == h[p->val])
//        {
//            n++;
//            flag = 0;
//        }
//        else if (0 == flag && h[p->val])
//            flag = 1;
//
//        p = p->next;
//    }
//    free(h);
//    return n + flag;
//}
//
////1669. 合并两个链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
//{
//    struct ListNode* left, * right, * p = list1;
//    int n = 0;
//    while (p)
//    {
//        if (n == a - 1)
//            left = p;
//        if (n == b)
//            break;
//
//        p = p->next;
//        n++;
//    }
//    right = p->next;
//    p = left->next;
//    left->next = list2;
//    // while(p != right)
//    // {
//    //     struct ListNode* s = p;
//    //     p = p -> next;
//    //     free(s);
//    // }
//    while (list2->next)
//    {
//        list2 = list2->next;
//    }
//    list2->next = right;
//    return list1;
//}
//
