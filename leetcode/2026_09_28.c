//// LCP 44. 开幕式焰火
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, bool* vis, int* cnt)
//{
//    if (node == NULL) return;
//    if (!vis[node->val])
//    {
//        vis[node->val] = true;
//        (*cnt)++;
//    }
//    dfs(node->left, vis, cnt);
//    dfs(node->right, vis, cnt);
//}
//int numColor(struct TreeNode* root)
//{
//    bool vis[1001] = { 0 };
//    int ans = 0;
//    dfs(root, vis, &ans);
//    return ans;
//}
//
//// 404. 左叶子之和  
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, bool left)
//{
//    if (!node->left && !node->right)
//        return left ? node->val : 0;
//    int res = 0;
//    if (node->left) res += dfs(node->left, 1);
//    if (node->right) res += dfs(node->right, 0);
//    return res;
//}
//int sumOfLeftLeaves(struct TreeNode* root)
//{
//    return dfs(root, 0);
//}
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
//    if (!node) return 0;
//    int res = dfs(node->left) + dfs(node->right);
//    struct TreeNode* left = node->left;
//    if (left && left->left == NULL && left->right == NULL)
//        res += left->val;
//    return res;
//}
//int sumOfLeftLeaves(struct TreeNode* root)
//{
//    return dfs(root);
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int sumOfLeftLeaves(struct TreeNode* root)
//{
//    if (root == NULL) return 0;
//    int res = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//    struct TreeNode* left = root->left;
//    if (left && left->left == NULL && left->right == NULL)
//        res += left->val;
//    return res;
//}
//
//// 671. 二叉树中第二小的节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int min, sub;
//void dfs(struct TreeNode* node)
//{
//    if (node == NULL) return;
//    dfs(node->left);
//    dfs(node->right);
//    if (node->val == min)
//        return;
//    if (node->val < min)
//    {
//        sub = min;
//        min = node->val;
//    }
//    else if (sub < 0 || node->val < sub)
//        sub = node->val;
//}
//int findSecondMinimumValue(struct TreeNode* root)
//{
//    min = root->val, sub = -1;
//    dfs(root);
//    return sub;
//}
//
//// 104. 二叉树的最大深度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root)
//{
//    if (root == NULL) return 0;
//    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
//}
//
