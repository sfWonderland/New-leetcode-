//// 101. ¶Ô³Æ¶þ²æÊ÷
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* left, struct TreeNode* right)
//{
//    if (!left) return right == NULL;
//    if (!right) return false;
//    return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
//}
//bool isSymmetric(struct TreeNode* root)
//{
//    return dfs(root->left, root->right);
//}
//
