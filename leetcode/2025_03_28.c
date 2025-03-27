////3217. 从链表中移除在数组中存在的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head)
//{
//    int hash[100000] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i] - 1] = 1;
//    }
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* p = dummy;
//    while (p->next)
//    {
//        if (p->next && hash[(p->next->val) - 1])
//            p->next = p->next->next;
//        else
//            p = p->next;
//    }
//    return dummy->next;
//}
//
////2487. 从链表中移除节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// // 1. 反转链表法
// // struct ListNode* reverseNodes(struct ListNode* head)
// // {
// //     struct ListNode* p = head;
// //     struct ListNode* new_head = NULL;
// //     while(p)
// //     {
// //         struct ListNode* s = p -> next;
// //         p -> next = new_head;
// //         new_head = p;
// //         p = s;
// //     }
// //     return new_head;
// // }
// // struct ListNode* removeNodes(struct ListNode* head) 
// // {
// //     head = reverseNodes(head);
// //     struct ListNode* p = head;
// //     while(p -> next)
// //     {
// //         if(p -> val > p -> next -> val)
// //             p -> next = p -> next -> next;
// //         else
// //             p = p -> next;
// //     }
// //     return reverseNodes(head);
// // }
//
// // 2. 递归
//struct ListNode* removeNodes(struct ListNode* head)
//{
//    if (head == NULL)
//        return head;
//
//    head->next = removeNodes(head->next);
//    if (head->next && head->val < head->next->val)
//        return head->next;
//    else
//        return head;
//}
//
//
////2807. 在链表中插入最大公约数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int commonDivisor(int a, int b)
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
//    struct ListNode* p = head;
//    while (p->next)
//    {
//        struct ListNode* q = p->next;
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->val = commonDivisor(p->val, q->val);
//        p->next = s;
//        s->next = q;
//        p = q;
//    }
//    return head;
//}
//
////LCR 029. 循环有序列表的插入
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
//    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
//    s->val = insertVal;
//    s->next = s;
//    if (head == NULL)
//        return s;
//    struct Node* p = head;
//    while (p->next != head)
//    {
//        if (insertVal >= p->val && insertVal <= p->next->val)
//            break;
//        if (p->val > p->next->val)
//        {
//            if (insertVal > p->val || insertVal < p->next->val)
//                break;
//        }
//        p = p->next;
//    }
//    s->next = p->next;
//    p->next = s;
//    return head;
//}
//
