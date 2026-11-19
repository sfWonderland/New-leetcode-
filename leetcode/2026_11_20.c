//// 2487. 从链表中移除节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeNodes(struct ListNode* head)
//{
//    if (head->next == NULL) return head;
//    head->next = removeNodes(head->next);
//    return head->val >= head->next->val ? head : head->next;
//}
//
