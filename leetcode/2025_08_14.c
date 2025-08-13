////3592. 硬币面值还原
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findCoins(int* numWays, int numWaysSize, int* returnSize)
//{
//    *returnSize = 0;
//    int t = 0, n = numWaysSize;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 1; i <= n; i++)
//    {
//        if (numWays[i - 1] == 0)
//            continue;
//        else if (numWays[i - 1] == 1)
//        {
//            ans[t++] = i;
//            for (int j = n - 1; j >= i; j--)
//            {
//                numWays[j] -= numWays[j - i];
//            }
//            numWays[i - 1] = 0;
//        }
//        else
//            return NULL;
//    }
//    *returnSize = t;
//    return ans;
//}
//
////2222. 选择建筑的方案数
//
//long long numberOfWays(char* s)
//{
//    int n = 0, t1 = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        n++;
//        t1 += s[i] - '0';
//    }
//    int c1 = 0;
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] - '0')
//        {
//            ans += 1ll * (i - c1) * (n - t1 - i + c1);
//            c1++;
//        }
//        else
//            ans += 1ll * c1 * (t1 - c1);
//    }
//    return ans;
//}
//
////92. 反转链表 II
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
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = NULL;
//    struct ListNode* p = head;
//    while (p != NULL)
//    {
//        struct ListNode* next = p->next;
//        p->next = dummy->next;
//        dummy->next = p;
//        p = next;
//    }
//    return dummy->next;
//}
//struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* p = dummy;
//    struct ListNode* l1 = NULL, * l2 = NULL;
//    struct ListNode* r1 = NULL, * r2 = NULL;
//    for (int i = 0; p; i++)
//    {
//        if (i == left - 1)
//        {
//            l1 = p;
//            l2 = p->next;
//        }
//        else if (i == right)
//        {
//            r2 = p;
//            r1 = p->next;
//        }
//        p = p->next;
//    }
//    r2->next = NULL;
//    r2 = reverseList(l2);
//    l1->next = r2;
//    l2->next = r1;
//    return dummy->next;
//}
//
////25. K 个一组翻转链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverseKGroup(struct ListNode* head, int k)
//{
//    int n = 0;
//    for (struct ListNode* cur = head; cur; cur = cur->next)
//        n++;
//
//    struct ListNode dummy = { 0, head };
//    struct ListNode* p = &dummy;
//    struct ListNode* pre = NULL;
//    struct ListNode* cur = head;
//
//    for (; n >= k; n -= k)
//    {
//        for (int i = 0; i < k; i++)
//        {
//            struct ListNode* tmp = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = tmp;
//        }
//
//        struct ListNode* t = p->next;
//        p->next->next = cur;
//        p->next = pre;
//        p = t;
//    }
//
//    return dummy.next;
//}
//
