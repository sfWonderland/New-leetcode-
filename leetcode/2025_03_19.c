////83. ɾ�����������е��ظ�Ԫ��
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL)
//        return head;
//    struct ListNode* p = head;
//    while (p->next != NULL)
//    {
//        if (p->val == p->next->val)
//            p->next = p->next->next;
//        else
//            p = p->next;
//    }
//    return head;
//}
//
////82. ɾ�����������е��ظ�Ԫ�� II
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL)
//        return false;
//    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
//    L->next = head;
//    struct ListNode* cur = L;
//    while (cur->next && cur->next->next)
//    {
//        if (cur->next->val == cur->next->next->val)
//        {
//            int x = cur->next->val;
//            while (cur->next && cur->next->val == x)
//            {
//                cur->next = cur->next->next;
//            }
//        }
//        else
//            cur = cur->next;
//    }
//    return L->next;
//}
//
////203. �Ƴ�����Ԫ��
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// // struct ListNode* removeElements(struct ListNode* head, int val) {
// //     if (head == NULL) {
// //         return head;
// //     }
// //     head->next = removeElements(head->next, val);
// //     return head->val == val ? head->next : head;
// // }
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    if (head == NULL)
//        return false;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = dummy;
//    while (cur->next)
//    {
//        if (cur->next->val == val)
//            cur->next = cur->next->next;
//        else
//            cur = cur->next;
//    }
//    return dummy->next;
//}
//
////237. ɾ�������еĽڵ�
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void deleteNode(struct ListNode* node)
//{
//    node->val = node->next->val;
//    struct ListNode* next = node->next;
//    node->next = node->next->next;
//    free(next);
//}
//
