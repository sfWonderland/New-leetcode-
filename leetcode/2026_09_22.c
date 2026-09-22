//// 1721. 交换链表中的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//struct ListNode* swapNodes(struct ListNode* head, int k)
//{
//    struct ListNode* fast = head;
//    while (--k)
//        fast = fast->next;
//    struct ListNode* front = fast;
//    struct ListNode* slow = head;
//    while (fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    swap(&front->val, &slow->val);
//    return head;
//}
//
//// 876. 链表的中间结点
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
//// 2095. 删除链表的中间节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteMiddle(struct ListNode* head)
//{
//    if (!head || !head->next) return NULL;
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* pre = NULL;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        pre = slow;
//        slow = slow->next;
//    }
//    pre->next = slow->next;
//    free(slow);
//    return head;
//}
//
//// 234. 回文链表
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
//    while (head)
//    {
//        struct ListNode* nxt = head->next;
//        head->next = pre;
//        pre = head;
//        head = nxt;
//    }
//    return pre;
//}
//bool isPalindrome(struct ListNode* head)
//{
//    if (!head->next) return true;
//    struct ListNode* fast = head->next;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    // printf("%d %d\n", slow -> val, fast ? fast -> val : -1);
//    struct ListNode* list1 = slow->next;
//    slow->next = NULL;
//    struct ListNode* list2 = reverse(head);
//    if (!fast) list2 = list2->next;
//    // printf("%d %d\n", list1 ? list1 -> val : -1, list2 ? list2 -> val : -1);
//    while (list1)
//    {
//        if (list1->val != list2->val)
//            return false;
//        list1 = list1->next;
//        list2 = list2->next;
//    }
//    return true;
//}
//
