//// 230. 二叉搜索树中第 K 小的元素
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, int* pos, int k, int* ans)
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left, pos, k, ans);
//    (*pos)++;
//    if (*pos == k)
//    {
//        *ans = node->val;
//        return;
//    }
//    dfs(node->right, pos, k, ans);
//}
//int kthSmallest(struct TreeNode* root, int k)
//{
//    int pos = 0, ans = 0;
//    dfs(root, &pos, k, &ans);
//    return ans;
//}
//
