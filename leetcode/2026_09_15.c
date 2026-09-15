//// 4048. 统计等间距出现整数数目 I
//
//int countSpecialIntegers(int* nums, int numsSize)
//{
//    int pos[101] = { 0 }; // i
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        if (!pos[x])
//            pos[x] = i + 1;
//        else if (pos[x] > 0)
//        {
//            int d = i + 1 - pos[x];
//            if (i + d < numsSize && nums[i + d] == x)
//            {
//                pos[x] = -1;
//                ans++;
//            }
//            else
//                pos[x] = -3;
//        }
//        else
//        {
//            if (pos[x] == -1)
//                pos[x] = -2;
//            else if (pos[x] == -2)
//            {
//                pos[x] = -3;
//                ans--;
//            }
//        }
//    }
//    return ans;
//}
//
//// 1290. 二进制链表转整数
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//int getDecimalValue(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    int ans = 0;
//    while (cur)
//    {
//        ans <<= 1;
//        ans |= cur->val;
//        cur = cur->next;
//    }
//    return ans;
//}
//
//// 2058. 找出临界点之间的最小和最大距离
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
//int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
//{
//    int pre_val = head->val, start = -1, pre_pos = INT_MIN / 2;
//    int step = 1, min = INT_MAX / 2;
//    for (struct ListNode* cur = head->next; cur->next; cur = cur->next)
//    {
//        int x = cur->val, nxt = cur->next->val;
//        if ((x > pre_val && x > nxt) || (x < pre_val && x < nxt))
//        {
//            if (start == -1) start = step;
//            min = fmin(min, step - pre_pos);
//            pre_pos = step;
//        }
//        pre_val = x;
//        step++;
//    }
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = min > 100000 ? -1 : min;
//    ans[1] = min > 100000 ? -1 : pre_pos - start;
//    *returnSize = 2;
//    return ans;
//}
//
//// 2181. 合并零之间的节点
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeNodes(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    for (struct ListNode* fast = head->next; fast->next; fast = fast->next)
//    {
//        if (!fast->val)
//        {
//            slow = slow->next;
//            slow->val = 0;
//        }
//        else
//            slow->val += fast->val;
//    }
//    slow->next = NULL;
//    return head;
//}
//
