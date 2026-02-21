////1291. 顺次数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//const int nums[9] = { 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, INT_MAX };
//int* sequentialDigits(int low, int high, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 36);
//    int ansSize = 0, x = 1;
//    for (int i = 0; nums[i] <= high; i++)
//    {
//        x = x * 10 + 1;
//        if (low >= nums[i + 1])
//            continue;
//        for (int j = 0; j < 8 - i; j++)
//        {
//            if (nums[i] + j * x <= high)
//            {
//                if (nums[i] + j * x >= low)
//                    ans[ansSize++] = nums[i] + j * x;
//            }
//            else
//                break;
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////1344. 时钟指针的夹角    
//
//double angleClock(int hour, int minutes)
//{
//    double a = 1.0 * (hour % 12) * 30 + 0.5 * minutes;
//    double b = 6.0 * minutes;
//    double right = fabs(a - b);
//    return fmin(right, 360.0 - right);
//}
//
////1347. 制造字母异位词的最小步骤数
//
//int minSteps(char* s, char* t)
//{
//    int cnt[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    for (int i = 0; t[i]; i++)
//    {
//        cnt[t[i] - 'a']--;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        ans += abs(cnt[i]);
//    }
//    return ans / 2;
//}
//
////1367. 二叉树中的链表
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
//bool isSubPath(struct ListNode* head, struct TreeNode* root)
//{
//    bool dfs(struct ListNode* s, struct TreeNode* root)
//    {
//        if (s == NULL)
//            return true;
//
//        if (root == NULL)
//            return false;
//
//        return s->val == root->val && (dfs(s->next, root->left) || dfs(s->next, root->right)) || s == head && (dfs(head, root->left) || dfs(head, root->right));
//    }
//    return dfs(head, root);
//}
//
