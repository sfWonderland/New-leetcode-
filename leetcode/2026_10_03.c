//// 951. 翻转等价二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (root1 == root2) return true;
//    if (!root1 || !root2) return false;
//    if (root1->val != root2->val) return false;
//
//    return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) || (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
//}
//
//// 110. 平衡二叉树    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left);
//    int right = dfs(node->right);
//    int mx = left > right ? left : right;
//    int mn = left + right - mx;
//    return mx - mn < 2 ? mx + 1 : -10001;
//}
//bool isBalanced(struct TreeNode* root)
//{
//    return dfs(root) >= 0;
//}
//
//// 226. 翻转二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if (root == NULL) return NULL;
//    struct TreeNode* tmp = root->left;
//    root->left = invertTree(root->right);
//    root->right = invertTree(tmp);
//    return root;
//}
//
//// 617. 合并二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (!root1) return root2;
//    if (!root2) return root1;
//    root1->val += root2->val;
//    root1->left = mergeTrees(root1->left, root2->left);
//    root1->right = mergeTrees(root1->right, root2->right);
//    return root1;
//}
//
