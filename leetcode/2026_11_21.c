//// 1721. 交换链表中的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* swapNodes(struct ListNode* head, int k)
//{
//    struct ListNode* fast = head;
//    while (--k)
//    {
//        fast = fast->next;
//    }
//    struct ListNode* left = fast;
//    struct ListNode* slow = head;
//    while (fast->next)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    int tmp = left->val;
//    left->val = slow->val;
//    slow->val = tmp;
//    return head;
//}
//
