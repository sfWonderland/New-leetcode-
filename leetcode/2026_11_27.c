//// 94. 二叉树的中序遍历
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    struct TreeNode* st[100];
//    int top = 0;
//    struct TreeNode* cur = root;
//    while (cur || top > 0)
//    {
//        while (cur)
//        {
//            st[top++] = cur;
//            cur = cur->left;
//        }
//        cur = st[--top];
//        ans[(*returnSize)++] = cur->val;
//        cur = cur->right;
//    }
//    return ans;
//}
//
