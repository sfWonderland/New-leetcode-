////206. 反转链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* p = head;
//    while (p != NULL)
//    {
//        struct ListNode* next = p->next;
//        p->next = dummy->next;
//        dummy->next = p;
//        p = next;
//    }
//    return dummy->next;
//}
//
////876. 链表的中间结点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
////.
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool isPalindrome(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* p = slow;
//    while (p != NULL)
//    {
//        struct ListNode* next = p->next;
//        p->next = dummy->next;
//        dummy->next = p;
//        p = next;
//    }
//    p = dummy->next;
//    struct ListNode* q = head;
//    while (p != NULL)
//    {
//        if (q->val != p->val)
//            return false;
//        p = p->next;
//        q = q->next;
//    }
//    return true;
//}
//
////1290. 二进制链表转整数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int getDecimalValue(struct ListNode* head)
//{
//    int n = 0;
//    struct ListNode* p = head;
//    while (p)
//    {
//        n <<= 1;
//        n += p->val;
//        p = p->next;
//    }
//    return n;
//}
//
