//// 2130. 链表最大孪生和
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
//    struct ListNode* fast = head;
//    struct ListNode* pre = NULL;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        pre = slow;
//        slow = slow->next;
//    }
//    return pre;
//}
//
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
//
//int pairSum(struct ListNode* head)
//{
//    struct ListNode* list1 = head;
//    struct ListNode* pre = middleNode(head);
//    struct ListNode* list2 = pre->next;
//    pre->next = NULL;
//    list2 = reverseList(list2);
//    struct ListNode* cur1 = list1, * cur2 = list2;
//    int ans = 0;
//    while (cur1)
//    {
//        ans = fmax(ans, cur1->val + cur2->val);
//        cur1 = cur1->next;
//        cur2 = cur2->next;
//    }
//    return ans;
//}
//
//// 143. 重排链表
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
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
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
//
//void reorderList(struct ListNode* head)
//{
//    struct ListNode* list1 = head;
//    struct ListNode* pre = middleNode(head);
//    struct ListNode* list2 = pre->next;
//    pre->next = NULL;
//    list2 = reverseList(list2);
//    struct ListNode* cur1 = list1, * cur2 = list2;
//    while (cur2)
//    {
//        struct ListNode* nxt1 = cur1->next;
//        struct ListNode* nxt2 = cur2->next;
//        cur1->next = cur2;
//        cur2->next = nxt1;
//        cur1 = nxt1;
//        cur2 = nxt2;
//    }
//}
//
//// 141. 环形链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//            return true;
//    }
//    return false;
//}
//
//// 142. 环形链表 II
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
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            struct ListNode* cur = head;
//            while (slow != cur)
//            {
//                slow = slow->next;
//                cur = cur->next;
//            }
//            return slow;
//        }
//    }
//    return NULL;
//}
//
