////24. 两两交换链表中的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* swapPairs(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* p = dummy;
//    while (p->next && p->next->next)
//    {
//        struct ListNode* s = p->next->next;
//        struct ListNode* t = p->next;
//        t->next = s->next;
//        s->next = t;
//        p->next = s;
//        p = t;
//    }
//    return dummy->next;
//}
//
////19. 删除链表的倒数第 N 个结点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* fast = dummy;
//    struct ListNode* slow = dummy;
//    while (n--)
//        fast = fast->next;
//    while (fast->next)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    fast = slow->next;
//    slow->next = fast ? fast->next : NULL;
//    return dummy->next;
//
//}
//
////61. 旋转链表
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
//    if (head == NULL || head->next == NULL || k == 0)
//        return head;
//    int n = 1;
//    struct ListNode* p = head;
//    while (p->next)
//    {
//        p = p->next;
//        n++;
//    }
//    if (k % n == 0)
//        return head;
//    p->next = head;
//    int add = n - k % n;
//    while (add--)
//        p = p->next;
//    struct ListNode* res = p->next;
//    p->next = NULL;
//    return res;
//}
//
////1721. 交换链表中的节点
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
//    struct ListNode* slow = head;
//    while (--k)
//        fast = fast->next;
//    struct ListNode* s = fast;
//    while (fast->next)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    int tmp = slow->val;
//    slow->val = s->val;
//    s->val = tmp;
//    return head;
//}
//
