//// 25. K 个一组翻转链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverse(struct ListNode* head)
//{
//    struct ListNode* pre = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* nxt = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = nxt;
//    }
//    return pre;
//}
//struct ListNode* reverseKGroup(struct ListNode* head, int k)
//{
//    struct ListNode* cur = head;
//    int k0 = k;
//    while (--k && cur)
//    {
//        cur = cur->next;
//    }
//    // printf("%d ", cur ? cur -> val : -1);
//    if (!cur) return head;
//    struct ListNode* res = cur->next;
//    cur->next = NULL;
//    struct ListNode* tail = head; // It's just used for prompt
//    head = reverse(head);
//    tail->next = reverseKGroup(res, k0);
//    return head;
//}
//
