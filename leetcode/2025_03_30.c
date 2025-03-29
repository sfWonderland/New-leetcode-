////2109. 向字符串添加空格
//
//char* addSpaces(char* s, int* spaces, int spacesSize)
//{
//    int n = strlen(s);
//    char* res = (char*)malloc(sizeof(char) * (n + 1 + spacesSize));
//    int num = 0;
//    int j = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (num < spacesSize && i == spaces[num])
//        {
//            num++;
//            res[j++] = ' ';
//        }
//        res[j++] = s[i];
//    }
//    res[j] = '\0';
//    return res;
//}
//
////2095. 删除链表的中间节点
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
//    if (head == NULL || head->next == NULL)
//        return NULL;
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* pre = NULL;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        pre = slow;
//        slow = slow->next;
//    }
//    pre->next = pre->next->next;
//    return head;
//}
//
////2130. 链表最大孪生和
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//void reverse(struct ListNode* head)
//{
//    struct ListNode* p = head;
//    struct ListNode* s = NULL;
//    while (p)
//    {
//        struct ListNode* next = p->next;
//        p->next = s;
//        s = p;
//        p = next;
//    }
//}
//int pairSum(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* fast = dummy;
//    struct ListNode* slow = dummy;
//    while (fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    reverse(slow->next);
//    slow->next = NULL;
//    slow = head;
//    int max = 0;
//    while (fast)
//    {
//        max = fmax(max, fast->val + slow->val);
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return max;
//}
//
////143. 重排链表
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
//    struct ListNode* p = head;
//    struct ListNode* s = NULL;
//    while (p)
//    {
//        struct ListNode* next = p->next;
//        p->next = s;
//        s = p;
//        p = next;
//    }
//    return s;
//}
//void reorderList(struct ListNode* head)
//{
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* fast = dummy;
//    struct ListNode* slow = dummy;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    fast = reverse(slow->next);
//    slow->next = NULL;
//    slow = head;
//    while (slow && fast)
//    {
//        struct ListNode* s = slow->next;
//        struct ListNode* t = fast->next;
//        slow->next = fast;
//        fast->next = s;
//        slow = s;
//        fast = t;
//    }
//}
//
