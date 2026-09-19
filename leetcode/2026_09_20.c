//// 2807. 在链表中插入最大公约数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    while (cur->next)
//    {
//        struct ListNode* nxt = cur->next;
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = gcd(cur->val, nxt->val);
//        cur->next = node;
//        node->next = nxt;
//        cur = nxt;
//    }
//    return head;
//}
//
//// 147. 对链表进行插入排序   
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* insertionSortList(struct ListNode* head)
//{
//    if (!head || !head->next) return head;
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = head;
//    while (cur->next)
//    {
//        struct ListNode* nxt = cur->next;
//        // printf("%d ", nxt -> val);
//        if (nxt->val < cur->val)
//        {
//            struct ListNode* node = nxt;
//            nxt = nxt->next;
//            struct ListNode* pre = dummy;
//            while (pre->next->val < node->val)
//            {
//                pre = pre->next;
//                // printf("%d ", pre -> val);
//            }
//            node->next = pre->next;
//            pre->next = node;
//            cur->next = nxt;
//        }
//        else
//            cur = nxt;
//        // printf("%d\n", cur -> val);
//    }
//    return dummy->next;
//}
//
//// LCR 029. 循环有序列表的插入
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct TreeNode *next;
// * };
// */
//
//struct Node* insert(struct Node* head, int insertVal)
//{
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//    node->val = insertVal;
//    node->next = NULL;
//    if (!head)
//    {
//        node->next = node;
//        return node;
//    }
//    if (head->next == head)
//    {
//        head->next = node;
//        node->next = head;
//        return head;
//    }
//    struct Node* cur = head;
//    while (cur->next != head && cur->val <= cur->next->val)
//        cur = cur->next;
//    if (cur->val > insertVal)
//    {
//        // initial : cur -> next -> val is the minimum number
//        while (cur->next->val < insertVal)
//        {
//            cur = cur->next;
//        }
//    }
//    node->next = cur->next;
//    cur->next = node;
//    return head;
//}
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct TreeNode *next;
// * };
// */
//
//struct Node* insert(struct Node* head, int insertVal)
//{
//    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//    node->val = insertVal;
//    node->next = node;
//    if (!head) return node;
//    if (head->next == head)
//    {
//        head->next = node;
//        node->next = head;
//        return head;
//    }
//    struct Node* cur = head;
//    while (cur->next != head)
//    {
//        if (cur->val <= insertVal && cur->next->val >= insertVal)
//            break;
//        if (cur->val > cur->next->val)
//        {
//            if (cur->val < insertVal || cur->next->val > insertVal)
//                break;
//        }
//        cur = cur->next;
//    }
//    node->next = cur->next;
//    cur->next = node;
//    return head;
//}
//
//// 206. 反转链表
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
