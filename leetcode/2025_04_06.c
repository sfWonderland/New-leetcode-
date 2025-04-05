////LCR 021. 删除链表的倒数第 N 个结点
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
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* fast = dummy;
//    struct ListNode* slow = dummy;
//    struct ListNode* pre = dummy;
//    while (n--)
//    {
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        pre = slow;
//        slow = slow->next;
//    }
//    pre->next = slow->next;
//    return dummy->next;
//}
//
////LCR 022. 环形链表 II
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* p = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//        {
//            while (slow != p)
//            {
//                p = p->next;
//                slow = slow->next;
//            }
//            return p;
//        }
//    }
//    return NULL;
//}
//
////面试题 02.06. 回文链表
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
//    struct ListNode* p = head;
//    struct ListNode* new_head = NULL;
//    while (p)
//    {
//        struct ListNode* s = p->next;
//        p->next = new_head;
//        new_head = p;
//        p = s;
//    }
//    return new_head;
//}
//bool isPalindrome(struct ListNode* head)
//{
//    if (head == NULL)
//        return true;
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* pre = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        pre = slow;
//        slow = slow->next;
//    }
//    struct ListNode* p = reverse(pre->next);
//    pre->next = NULL;
//    slow = head;
//    while (p && slow)
//    {
//        if (p->val != slow->val)
//            return false;
//        p = p->next;
//        slow = slow->next;
//    }
//    return true;
//}
//
////面试题 02.07. 链表相交
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    if (!(headA && headB))
//        return NULL;
//    struct ListNode* p = headA;
//    struct ListNode* q = headB;
//    while (p != q)
//    {
//        p = p ? p->next : headB;
//        q = q ? q->next : headA;
//    }
//    return p;
//}
//
