////965. 单值二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* s, int n)
//{
//    if (s == NULL)
//        return true;
//
//    if (s->val != n)
//        return false;
//
//    return dfs(s->left, n) & dfs(s->right, n);
//}
//bool isUnivalTree(struct TreeNode* root)
//{
//    return dfs(root, root->val);
//}
//
////951. 翻转等价二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* s1, struct TreeNode* s2)
//{
//    if (s1 == NULL || s2 == NULL)
//        return s1 == s2;
//
//    if (s1->val != s2->val)
//        return false;
//
//    return (dfs(s1->left, s2->right) & dfs(s1->right, s2->left)) | (dfs(s1->right, s2->right) & dfs(s1->left, s2->left));
//}
//bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2)
//{
//    return dfs(root1, root2);
//}
//
////617. 合并二叉树
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
//    if (root1 == NULL)
//        return root2;
//    if (root2 == NULL)
//        return root1;
//    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node->val = root1->val + root2->val;
//    node->left = mergeTrees(root1->left, root2->left);
//    node->right = mergeTrees(root1->right, root2->right);
//    return node;
//}
//
////1026. 节点与其祖先之间的最大差值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int mn, int mx)
//{
//    if (node == NULL)
//        return 0;
//
//    int n = node->val;
//    if (n > mx)
//        return fmax(fmax(dfs(node->left, mn, n), dfs(node->right, mn, n)), n - mn);
//    if (n < mn)
//        return fmax(fmax(dfs(node->left, n, mx), dfs(node->right, n, mx)), mx - n);
//
//    return fmax(dfs(node->left, mn, mx), dfs(node->right, mn, mx));
//}
//int maxAncestorDiff(struct TreeNode* root)
//{
//    return dfs(root, root->val, root->val);
//}
//
