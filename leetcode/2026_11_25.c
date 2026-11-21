//// 445. 两数相加 II
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
//struct ListNode* addNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* pre = dummy;
//    struct ListNode* cur1 = l1;
//    struct ListNode* cur2 = l2;
//    int upgrade = 0;
//    while (cur1 || cur2)
//    {
//        int x = 0, y = 0;
//        if (cur1)
//        {
//            x = cur1->val;
//            cur1 = cur1->next;
//        }
//        if (cur2)
//        {
//            y = cur2->val;
//            cur2 = cur2->next;
//        }
//
//        int sum = x + y + upgrade;
//        upgrade = sum / 10;
//
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = sum % 10;
//        node->next = NULL;
//
//        pre->next = node;
//        pre = node;
//    }
//    if (upgrade)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = upgrade;
//        node->next = NULL;
//
//        pre->next = node;
//    }
//    struct ListNode* head = dummy->next;
//    free(dummy);
//    return head;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    l1 = reverse(l1);
//    l2 = reverse(l2);
//    return reverse(addNumbers(l1, l2));
//}
//
