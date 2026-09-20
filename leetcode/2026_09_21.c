//// 92. 反转链表 II
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
//struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = dummy;
//    int idx = 1;
//    while (idx < left)
//    {
//        cur = cur->next;
//        idx++;
//    }
//    struct ListNode* start = cur;
//    while (idx <= right)
//    {
//        cur = cur->next;
//        idx++;
//    }
//    struct ListNode* end = cur->next;
//    cur->next = NULL;
//    struct ListNode* end1 = start->next;
//    start->next = reverseList(end1);
//    end1->next = end;
//    return dummy->next;
//}
//
//// 24. 两两交换链表中的节点   
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
//    struct ListNode* cur = dummy;
//    while (cur->next && cur->next->next)
//    {
//        struct ListNode* nxt = cur->next->next;
//        cur->next->next = nxt->next;
//        nxt->next = cur->next;
//        cur->next = nxt;
//        cur = nxt->next;
//    }
//    return dummy->next;
//}
//
//// 25. K 个一组翻转链表
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
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = dummy;
//    struct ListNode* start = cur;
//    int idx = 0;
//    while (cur)
//    {
//        if (idx == k)
//        {
//            struct ListNode* end = cur->next;
//            cur->next = NULL;
//            struct ListNode* end1 = start->next;
//            // printf("%d %d %d\n", start -> next -> val, end1 -> val, end -> val);
//            start->next = reverseList(end1);
//            // printf("%d %d %d\n", start -> next -> val, end1 -> val, end -> val);
//            end1->next = end;
//            start = end1;
//            cur = start;
//            idx = -1;
//        }
//        else
//            cur = cur->next;
//
//        idx++;
//    }
//    return dummy->next;
//}
//
//// 19. 删除链表的倒数第 N 个结点
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
//    struct ListNode* fast = head;
//    while (n-- && fast)
//    {
//        fast = fast->next;
//    }
//    if (!fast) return head->next;
//    struct ListNode* pre = NULL;
//    struct ListNode* slow = head;
//    while (fast)
//    {
//        pre = slow;
//        slow = slow->next;
//        fast = fast->next;
//    }
//    pre->next = slow->next;
//    free(slow);
//    return head;
//}
//
