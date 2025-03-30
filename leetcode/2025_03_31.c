////2278. 字母在字符串中的百分比
//
//int percentageLetter(char* s, char letter)
//{
//    int len = 0;
//    int n = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == letter)
//            n++;
//        len++;
//    }
//    return (n * 100) / len;
//}
//
////2. 两数相加
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
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->next = p->next;
//        p->next = s;
//        p = p->next;
//        s->val = (sum + upgrade) % 10;
//        upgrade = (sum + upgrade) / 10;
//    }
//    if (upgrade == 1)
//    {
//        struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//        s->next = p->next;
//        p->next = s;
//        s->val = 1;
//    }
//    return dummy->next;
//}
//
////328. 奇偶链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* oddEvenList(struct ListNode* head)
//{
//    if (NULL == head)
//        return head;
//    struct ListNode* evenhead = head->next;
//    struct ListNode* odd = head;
//    struct ListNode* even = evenhead;
//    while (even && even->next)
//    {
//        odd->next = even->next;
//        odd = odd->next;
//        even->next = odd->next;
//        even = even->next;
//    }
//    odd->next = evenhead;
//
//    return head;
//}
//
////86. 分隔链表
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
//    if (NULL == head)
//        return head;
//    struct ListNode* dummy1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy1->next = head;
//    struct ListNode* dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy2->next = NULL;
//    struct ListNode* p = dummy1;
//    struct ListNode* q = dummy2;
//    while (p->next)
//    {
//        if ((p->next->val) >= x)
//        {
//            struct ListNode* s = p->next;
//            p->next = s->next;
//            s->next = q->next;
//            q->next = s;
//            q = s;
//        }
//        else
//            p = p->next;
//    }
//    p->next = dummy2->next;
//
//    return dummy1->next;
//}
//
