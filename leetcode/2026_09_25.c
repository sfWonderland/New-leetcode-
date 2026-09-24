//// 86. 分隔链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* partition(struct ListNode* head, int x)
//{
//    if (!head || !head->next) return head;
//    struct ListNode* dummy1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy1->next = dummy2->next = NULL;
//    struct ListNode* cur = head, * cur1 = dummy1, * cur2 = dummy2;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            cur1->next = cur;
//            cur1 = cur;
//        }
//        else
//        {
//            cur2->next = cur;
//            cur2 = cur;
//        }
//        cur = cur->next;
//    }
//    cur1->next = dummy2->next;
//    head = dummy1->next;
//    cur2->next = NULL;
//    free(dummy1);
//    free(dummy2);
//    return head;
//}
//
//// 160. 相交链表   
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
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    while (curA != curB)
//    {
//        curA = curA ? curA->next : headB;
//        curB = curB ? curB->next : headA;
//    }
//    return curA;
//}
//
//// 2. 两数相加
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* cur1 = l1;
//    struct ListNode* cur2 = l2;
//    bool upgrade = false;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    while (cur1 && cur2)
//    {
//        int x = cur1->val + cur2->val + upgrade;
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->val = x % 10;
//        upgrade = (x >= 10);
//        cur->next = node;
//        cur = node;
//        cur1 = cur1->next;
//        cur2 = cur2->next;
//    }
//    while (cur1)
//    {
//        int x = cur1->val + upgrade;
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->val = x % 10;
//        upgrade = (x >= 10);
//        cur->next = node;
//        cur = node;
//        cur1 = cur1->next;
//    }
//    while (cur2)
//    {
//        int x = cur2->val + upgrade;
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->val = x % 10;
//        upgrade = (x >= 10);
//        cur->next = node;
//        cur = node;
//        cur2 = cur2->next;
//    }
//    if (upgrade)
//    {
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->val = upgrade;
//        cur->next = node;
//        cur = node;
//    }
//    cur->next = NULL;
//    return dummy->next;
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void createNode(int x, struct ListNode** pre, bool* upgrade)
//{
//    struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//    node->val = x % 10;
//    *upgrade = (x >= 10);
//    (*pre)->next = node;
//    *pre = node;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* cur1 = l1;
//    struct ListNode* cur2 = l2;
//    bool upgrade = false;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    while (cur1 || cur2)
//    {
//        int a = cur1 ? cur1->val : 0;
//        int b = cur2 ? cur2->val : 0;
//        createNode(a + b + upgrade, &cur, &upgrade);
//        cur1 = cur1 ? cur1->next : NULL;
//        cur2 = cur2 ? cur2->next : NULL;
//    }
//    if (upgrade)
//        createNode(upgrade, &cur, &upgrade);
//    cur->next = NULL;
//    return dummy->next;
//}
//
//// 445. 两数相加 II
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
//
//void createNode(int x, struct ListNode** pre, bool* upgrade)
//{
//    struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//    node->val = x % 10;
//    *upgrade = (x >= 10);
//    (*pre)->next = node;
//    *pre = node;
//}
//
//struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* cur1 = l1;
//    struct ListNode* cur2 = l2;
//    bool upgrade = false;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* cur = dummy;
//    while (cur1 || cur2)
//    {
//        int a = cur1 ? cur1->val : 0;
//        int b = cur2 ? cur2->val : 0;
//        createNode(a + b + upgrade, &cur, &upgrade);
//        cur1 = cur1 ? cur1->next : NULL;
//        cur2 = cur2 ? cur2->next : NULL;
//    }
//    if (upgrade)
//        createNode(upgrade, &cur, &upgrade);
//    cur->next = NULL;
//    return dummy->next;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    l1 = reverseList(l1);
//    l2 = reverseList(l2);
//    return reverseList(addTwoNumbers1(l1, l2));
//}
//
