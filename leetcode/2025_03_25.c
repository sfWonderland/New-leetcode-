////141. ��������
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
//    //���������ܡ�
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
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
////142. �������� II
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
//    //���������ܡ�
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    struct ListNode* p = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            //���ꡱ���ߵ���ͷ��㵽�뻷��ľ������Ȧ�ص��뻷���ˡ�
//            while (p != slow)
//            {
//                p = p->next;
//                slow = slow->next;
//            }
//            return p;
//        }
//    }
//    return NULL;
//}
//
////160. �ཻ����
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
//    if (headA == NULL || headB == NULL)
//        return NULL;
//    struct ListNode* pA = headA, * pB = headB;
//    while (pA != pB)
//    {
//        pA = pA ? pA->next : headB;
//        pB = pB ? pB->next : headA;
//    }
//    return pA;
//}
//
////������ 02.01. �Ƴ��ظ��ڵ�
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// // 1. ��ʹ����ʱ������;
// // struct ListNode* removeDuplicateNodes(struct ListNode* head) 
// // {
// //     struct ListNode* p = head;
// //     while(p)
// //     {
// //         struct ListNode* fast = p;
// //         int t = p -> val;
// //         while(fast && fast -> next)
// //         {
// //             if(fast -> next -> val == t)
// //             {
// //                 struct ListNode* tmp = fast -> next;
// //                 fast -> next = tmp -> next;
// //                 free(tmp);
// //             }
// //             else
// //             fast = fast -> next;
// //         }
// //         p = p -> next;
// //     }
// //     return head;
// // }
// // 2�� ��ϣ��
//struct ListNode* removeDuplicateNodes(struct ListNode* head)
//{
//    if (head == NULL)
//        return NULL;
//    int h[20001] = { 0 };
//    struct ListNode* p = head;
//    h[head->val] = 1;
//    while (p->next)
//    {
//        if (0 == h[p->next->val])
//        {
//            h[p->next->val] = 1;
//            p = p->next;
//        }
//        else
//            p->next = p->next->next;
//    }
//    p->next = NULL;
//    return head;
//}
//
