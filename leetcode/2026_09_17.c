//// 4050. 得到恰好 N 分的最少天数
//
//#define MAX_SIZE 100001
//static int f[MAX_SIZE];
//static int init = 0;
//int minDays(int n)
//{
//    if (init == 0)
//    {
//        memset(f, 0x7f, sizeof(f));
//        f[0] = -1;
//        int sum = 0;
//        for (int i = 0; sum < MAX_SIZE; i++)
//        {
//            sum += i;
//            for (int j = sum; j < MAX_SIZE; j++)
//            {
//                f[j] = fmin(f[j], f[j - sum] + i + 1);
//            }
//        }
//        init = 1;
//    }
//    return f[n];
//}
//
//// 725. 分隔链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
//{
//    struct ListNode** ans = (struct ListNode**)calloc(k, sizeof(struct ListNode*));
//    *returnSize = k;
//    if (!head) return ans;
//    int len = 0;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        len++;
//        cur = cur->next;
//    }
//    int d = len / k, left = len % k;
//    cur = head;
//    int ansSize = 0, cnt = 0, goal = d + (left > 0);
//    ans[ansSize] = head;
//    while (cur->next && ansSize < k)
//    {
//        cnt++;
//        struct ListNode* nxt = cur->next;
//        if (cnt == goal)
//        {
//            cnt = 0;
//            left--;
//            goal = d + (left > 0);
//            cur->next = NULL;
//            ans[++ansSize] = nxt;
//        }
//        cur = nxt;
//    }
//    return ans;
//}
//
//// 817. 链表组件
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int numComponents(struct ListNode* head, int* nums, int numsSize)
//{
//    int n = 0;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        cur = cur->next;
//        n++;
//    }
//    bool exist[n + 1];
//    memset(exist, 0, sizeof(exist));
//    for (int i = 0; i < numsSize; i++)
//    {
//        exist[nums[i]] = true;
//    }
//    exist[n] = true;
//    cur = head->next;
//    int pre = head->val;
//    int ans = exist[pre];
//    while (cur)
//    {
//        int x = cur->val;
//        if (exist[x] && !exist[pre]) ans++;
//        pre = x;
//        cur = cur->next;
//    }
//    return ans;
//}
//
//// 203. 移除链表元素
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    if (!head) return NULL;
//    struct ListNode* cur = head;
//    while (cur && cur->val == val)
//    {
//        struct ListNode* node = cur;
//        cur = cur->next;
//        free(node);
//    }
//    head = cur;
//    while (cur)
//    {
//        if (cur->next && cur->next->val == val)
//        {
//            struct ListNode* nxt = cur->next;
//            cur->next = nxt->next;
//            free(nxt);
//        }
//        else
//            cur = cur->next;
//    }
//    return head;
//}
//
