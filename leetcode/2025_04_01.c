////445. 两数相加 II
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
//struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* p = dummy;
//    int upgrade = 0;
//    while (l1 || l2)
//    {
//        int sum = 0;
//        if (l1)
//        {
//            sum += l1->val;
//            l1 = l1->next;
//        }
//        if (l2)
//        {
//            sum += l2->val;
//            l2 = l2->next;
//        }
//
//        sum += upgrade;
//        upgrade = sum / 10;
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->val = sum % 10;
//        s->next = p->next;
//        p->next = s;
//        p = s;
//    }
//    if (upgrade)
//    {
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->next = p->next;
//        p->next = s;
//        p = s;
//        s->val = 1;
//    }
//    return dummy->next;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* p1 = reverse(l1);
//    struct ListNode* p2 = reverse(l2);
//    struct ListNode* head = addTwoNumbers1(p1, p2);
//    return reverse(head);
//}
//
////2816. 翻倍以链表形式表示的数字
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
//struct ListNode* doubleIt(struct ListNode* head)
//{
//    head = reverse(head);
//    struct ListNode* p = head;
//    int upgrade = 0;
//    while (p)
//    {
//        int n = 2 * (p->val) + upgrade;
//        upgrade = n / 10;
//        p->val = n % 10;
//        p = p->next;
//    }
//    head = reverse(head);
//    if (upgrade)
//    {
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->next = head;
//        s->val = 1;
//        head = s;
//    }
//    return head;
//}
//
////面试题 02.02. 返回倒数第 k 个节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int kthToLast(struct ListNode* head, int k)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (k--)
//        fast = fast->next;
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}
//
////面试题 02.03. 删除中间节点
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
//    node->next = node->next->next;
//}
//
