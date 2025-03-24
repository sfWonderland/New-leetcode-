////LCR 023. �ཻ����
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
//    struct ListNode* pA = headA;
//    struct ListNode* pB = headB;
//    while (pA != pB)
//    {
//        //�����Խӵȳ�
//        pA = pA ? pA->next : headB;
//        pB = pB ? pB->next : headA;
//    }
//    return pA;
//}
//
////LCR 024. ��ת����
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//        return head;
//
//    struct ListNode* p = head;
//    //struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    //dummy -> next = NULL;
//    struct ListNode* prev = NULL;
//    while (p)
//    {
//        struct ListNode* q = p->next;
//        p->next = prev;
//        prev = p;
//        p = q;
//    }
//    return prev;
//}
//
////LCR 027. ��������
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
//    if (head == NULL || head->next == NULL)
//        return head;
//
//    struct ListNode* p = head;
//    struct ListNode* prev = NULL;
//    while (p)
//    {
//        struct ListNode* q = p->next;
//        p->next = prev;
//        prev = p;
//        p = q;
//    }
//    return prev;
//}
//
//bool isPalindrome(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast->next && fast->next->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    slow = reverseList(slow->next);
//    struct ListNode* p = head;
//    while (slow)
//    {
//        if (slow->val != p->val)
//            return false;
//
//        slow = slow->next;
//        p = p->next;
//    }
//    return true;
//}
//
////LCR 136. ɾ������Ľڵ�
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteNode(struct ListNode* head, int val)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* p = dummy;
//    while (p && p->next)
//    {
//        if (p->next->val == val)
//        {
//            struct ListNode* q = p->next;
//            p->next = q->next;
//            free(q);
//        }
//        p = p->next;
//    }
//    return dummy->next;
//}
//
////LCR 171. ѵ���ƻ� V
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
//    struct ListNode* pA = headA;
//    struct ListNode* pB = headB;
//    while (pA != pB)
//    {
//        pA = pA ? pA->next : headB;
//        pB = pB ? pB->next : headA;
//    }
//    return pA;
//}
//
