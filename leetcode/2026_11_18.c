//// 61. Ðý×ªÁ´±í
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* rotateRight(struct ListNode* head, int k)
//{
//    if (!head || !head->next || k == 0) return head;
//    struct ListNode* cur = head;
//    struct ListNode* pre = NULL;
//    int cnt = 0;
//    while (cur)
//    {
//        pre = cur;
//        cur = cur->next;
//        cnt++;
//    }
//    k %= cnt;
//    if (k == 0) return head;
//
//    struct ListNode* tail = pre;
//    tail->next = head;
//    pre = head;
//    k = cnt - k;
//    while (--k)
//    {
//        pre = pre->next;
//    }
//
//    head = pre->next;
//    pre->next = NULL;
//
//    return head;
//}
//
