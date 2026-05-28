//// 148. 排序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* sortList(struct ListNode* head)
//{
//    if (!head || !head->next)
//        return head;
//
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* fast = dummy;
//    struct ListNode* slow = dummy;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    struct ListNode* mid = slow->next;
//    slow->next = NULL;
//
//    struct ListNode* left = sortList(head);
//    struct ListNode* right = sortList(mid);
//
//    struct ListNode* cur = dummy;
//    while (left && right)
//    {
//        if (left->val < right->val)
//        {
//            cur->next = left;
//            left = left->next;
//        }
//        else
//        {
//            cur->next = right;
//            right = right->next;
//        }
//        cur = cur->next;
//    }
//    cur->next = left ? left : right;
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
//int getLength(struct ListNode* head)
//{
//    int len = 0;
//    while (head)
//    {
//        head = head->next;
//        len++;
//    }
//    return len;
//}
//struct ListNode* sortList(struct ListNode* head)
//{
//    // 获取链表长度
//    int len = getLength(head);
//    // 分组长度，从1开始
//    int sub = 1;
//    // 创建哨兵节点方便处理
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    // 在不同的分组长度下对链表进行排序，每轮处理后将分组长度乘2，这样时间复杂度O（log(n))
//    while (sub < len)
//    {
//        // 每轮处理从头到尾，将链表分为若干个最大长度为sub的分组两两处理，末尾分组长度可能不足sub
//        struct ListNode* pre = dummy;
//        struct ListNode* cur = dummy->next;
//        // 开始一轮处理，每次处理时间复杂度O(n)
//        while (cur)
//        {
//            // 得到两个链表的长度
//            struct ListNode* left = cur;
//            int i = sub;
//            while (i && cur)
//            {
//                cur = cur->next;
//                i--;
//            }
//            // 链表长度不够组成一个sub长度的链表，一定是末尾的一个，后续没有链表了，不需要再处理
//            if (i) break;
//
//            struct ListNode* right = cur;
//            i = sub;
//            while (i && cur)
//            {
//                cur = cur->next;
//                i--;
//            }
//
//            // 末尾链表出现在第二个链表，可能长度不足sub，需要计算长度
//            int cntL = sub, cntR = sub - i;
//            // 类似递归的情况，将两链表归并排序
//            while (cntL && cntR)
//            {
//                if (left->val < right->val)
//                {
//                    pre->next = left;
//                    left = left->next;
//                    cntL--;
//                }
//                else
//                {
//                    pre->next = right;
//                    right = right->next;
//                    cntR--;
//                }
//                pre = pre->next;
//            }
//            // 剩余元素的链表是后续
//            pre->next = cntL ? left : right;
//            // 将两种情况合并，将pre移除两个链表的范围，方便下一轮处理
//            while (cntL > 0 || cntR > 0)
//            {
//                pre = pre->next;
//                cntL--;
//                cntR--;
//            }
//            pre->next = cur;
//        }
//        // 每轮处理后将分组长度乘2
//        sub *= 2;
//    }
//    return dummy->next;
//}
//
