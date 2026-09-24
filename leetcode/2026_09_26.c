//// 2816. 翻倍以链表形式表示的数字
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
//struct ListNode* doubleIt(struct ListNode* head)
//{
//    head = reverseList(head);
//    bool upgrade = false;
//    struct ListNode* cur = head;
//    struct ListNode* pre = NULL;
//    while (cur)
//    {
//        int x = cur->val * 2 + upgrade;
//        cur->val = x % 10;
//        upgrade = x / 10;
//        pre = cur;
//        cur = cur->next;
//    }
//    if (upgrade)
//    {
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->val = upgrade;
//        pre->next = node;
//    }
//    return reverseList(head);
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* doubleIt(struct ListNode* head)
//{
//    if (head->val > 4)
//    {
//        struct ListNode* node = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//        node->next = head;
//        head = node;
//    }
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        cur->val = cur->val * 2 % 10;
//        if (cur->next && cur->next->val > 4)
//            cur->val++;
//
//        cur = cur->next;
//    }
//    return head;
//}
//
//// 21. 合并两个有序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (!list1) return list2;
//    if (!list2) return list1;
//    struct ListNode* head = NULL;
//    if (list1->val <= list2->val)
//    {
//        head = list1;
//        list1 = list1->next;
//    }
//    else
//    {
//        head = list2;
//        list2 = list2->next;
//    }
//    struct ListNode* cur = head;
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            cur->next = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            cur->next = list2;
//            list2 = list2->next;
//        }
//        cur = cur->next;
//    }
//    cur->next = list1 ? list1 : list2;
//    return head;
//}
//
//// 23. 合并 K 个升序链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void up(struct ListNode** lists, int i)
//{
//    struct ListNode* cur = lists[i];
//    int x = cur ? cur->val : 10002;
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        int y = lists[j] ? lists[j]->val : 10001;
//        if (y <= x)
//            break;
//        lists[i] = lists[j];
//        i = j;
//        if (j == 0) break;
//    }
//    lists[i] = cur;
//}
//void down(struct ListNode** lists, int i, int n)
//{
//    struct ListNode* cur = lists[i];
//    int x = cur ? cur->val : 10002;
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        int y = lists[j] ? lists[j]->val : 10001;
//        if (j < n - 1)
//        {
//            int y1 = lists[j + 1] ? lists[j + 1]->val : 10001;
//            if (y1 < y)
//            {
//                j++;
//                y = y1;
//            }
//        }
//        if (y >= x)
//            break;
//        lists[i] = lists[j];
//        i = j;
//    }
//    lists[i] = cur;
//}
//void push(struct ListNode** lists, int i, struct ListNode* list)
//{
//    lists[i] = list;
//    up(lists, i);
//}
//struct ListNode* pop(struct ListNode** lists, int n)
//{
//    struct ListNode* node = lists[0];
//    lists[0] = lists[0]->next;
//    down(lists, 0, n);
//    return node;
//}
//void builtHeap(struct ListNode** lists, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        push(lists, i, lists[i]);
//    }
//}
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    if (listsSize == 0) return NULL;
//    int n = listsSize;
//    builtHeap(lists, n);
//    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//    struct ListNode* cur = dummy;
//    while (lists[0])
//    {
//        cur->next = pop(lists, n);
//        cur = cur->next;
//    }
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
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (!list1) return list2;
//    if (!list2) return list1;
//    struct ListNode* head = NULL;
//    if (list1->val <= list2->val)
//    {
//        head = list1;
//        list1 = list1->next;
//    }
//    else
//    {
//        head = list2;
//        list2 = list2->next;
//    }
//    struct ListNode* cur = head;
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            cur->next = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            cur->next = list2;
//            list2 = list2->next;
//        }
//        cur = cur->next;
//    }
//    cur->next = list1 ? list1 : list2;
//    return head;
//}
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    if (listsSize == 0) return NULL;
//    if (listsSize == 1) return lists[0];
//    struct ListNode* left = mergeKLists(lists, listsSize / 2);
//    struct ListNode* right = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
//    return mergeTwoLists(left, right);
//}
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (!list1) return list2;
//    if (!list2) return list1;
//    struct ListNode* head = NULL;
//    if (list1->val <= list2->val)
//    {
//        head = list1;
//        list1 = list1->next;
//    }
//    else
//    {
//        head = list2;
//        list2 = list2->next;
//    }
//    struct ListNode* cur = head;
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            cur->next = list1;
//            list1 = list1->next;
//        }
//        else
//        {
//            cur->next = list2;
//            list2 = list2->next;
//        }
//        cur = cur->next;
//    }
//    cur->next = list1 ? list1 : list2;
//    return head;
//}
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
//{
//    int n = listsSize;
//    if (n == 0) return NULL;
//    for (int step = 1; step < n; step *= 2)
//    {
//        // 两两合并，存储到前面链表的位置
//        // 11 11 11 11
//        // 10 10 10 10
//        // 10 00 10 00
//        // 10 00 00 00
//        for (int i = 0; i < n - step; i += step * 2)
//        {
//            lists[i] = mergeTwoLists(lists[i], lists[i + step]);
//        }
//    }
//    return lists[0];
//}
//
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
//    int n = 0;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        cur = cur->next;
//        n++;
//    }
//    int m = 1;
//    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
//    dummy->next = head;
//    while (n > m)
//    {
//        struct ListNode* pre = dummy;
//        cur = dummy->next;
//        while (cur)
//        {
//            struct ListNode* left = cur;
//            int cntL = m;
//            while (cur && cntL)
//            {
//                cur = cur->next;
//                cntL--;
//            }
//            if (cntL) break;
//            cntL = m;
//
//            struct ListNode* right = cur;
//            int cntR = m;
//            while (cur && cntR)
//            {
//                cur = cur->next;
//                cntR--;
//            }
//            cntR = m - cntR;
//
//            while (cntL && cntR)
//            {
//                if (left->val <= right->val)
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
//            pre->next = cntL ? left : right;
//            while (cntL > 0 || cntR > 0)
//            {
//                pre = pre->next;
//                cntL--; cntR--;
//            }
//            pre->next = cur;
//        }
//        m *= 2;
//    }
//    return dummy->next;
//}
//
