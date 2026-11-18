//// 2807. 在链表中插入最大公约数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int gcd(int x, int y)
//{
//    while (y)
//    {
//        int tmp = x % y;
//        x = y;
//        y = tmp;
//    }
//    return x;
//}
//struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    while (cur->next)
//    {
//        int x = gcd(cur->val, cur->next->val);
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = x;
//        node->next = cur->next;
//        cur->next = node;
//        cur = node->next;
//    }
//    return head;
//}
//
