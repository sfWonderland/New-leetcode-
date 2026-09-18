//// 1401. 圆和矩形是否有重叠
//
//bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
//{
//    // 数学：在圆边界的点与圆心距离为r，在圆内距离小于r，在圆外距离大于r
//    // 点与圆的位置关系：看其与圆心距离，与r进行比较
//    // 其他平面图形与圆的位置关系：转化为图形上的点到圆心的距离
//    // 本题目标：找出矩形里距离圆心最近的点坐标，与r进行比较
//    int x = fmax(x1, fmin(xCenter, x2));
//    int y = fmax(y1, fmin(yCenter, y2));
//    return (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius;
//}
//
//// 1669. 合并两个链表   
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
//struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
//    struct ListNode* end2 = list2;
//    while (end2->next)
//    {
//        end2 = end2->next;
//    }
//    int i = 0;
//    struct ListNode* cur = list1;
//    while (i < a - 1)
//    {
//        cur = cur->next;
//        i++;
//    }
//    struct ListNode* del = cur->next;
//    cur->next = list2;
//    cur = del;
//    while (i < b - 1)
//    {
//        cur = cur->next;
//        i++;
//    }
//    end2->next = cur->next;
//    cur->next = NULL;
//    while (del)
//    {
//        struct ListNode* node = del;
//        del = del->next;
//        free(node);
//    }
//    return list1;
//}
//
//// 2487. 从链表中移除节点
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
//    struct ListNode* next = NULL;
//    while (head->next)
//    {
//        struct ListNode* node = head;
//        head = head->next;
//        node->next = next;
//        next = node;
//    }
//    head->next = next;
//    return head;
//}
//struct ListNode* removeNodes(struct ListNode* head)
//{
//    head = reverse(head);
//    struct ListNode* slow = head;
//    struct ListNode* fast = head->next;
//    while (fast)
//    {
//        if (slow->val <= fast->val)
//        {
//            slow = slow->next;
//            slow->val = fast->val;
//        }
//        fast = fast->next;
//    }
//    struct ListNode* del = slow->next;
//    slow->next = NULL;
//    head = reverse(head);
//    while (del)
//    {
//        struct ListNode* node = del;
//        del = del->next;
//        free(node);
//    }
//    return head;
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeNodes(struct ListNode* head)
//{
//    if (head->next == NULL) return head;
//    head->next = removeNodes(head->next);
//    return head->val >= head->next->val ? head : head->next;
//}
//
//// 237. 删除链表中的节点
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
//    struct ListNode* next = node->next;
//    node->next = next->next;
//    node->val = next->val;
//    free(next);
//}
//
