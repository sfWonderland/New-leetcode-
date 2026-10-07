//// 538. 把二叉搜索树转换为累加树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int sum;
//void dfs(struct TreeNode* node)
//{
//    if (node == NULL) return;
//    dfs(node->right);
//    sum += node->val;
//    node->val = sum;
//    dfs(node->left);
//}
//struct TreeNode* convertBST(struct TreeNode* root)
//{
//    sum = 0;
//    dfs(root);
//    return root;
//}
//
//// 865. 具有所有最深节点的最小子树    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int getDepth(struct TreeNode* node)
//{
//    if (node == NULL) return 0;
//    return fmax(getDepth(node->left), getDepth(node->right)) + 1;
//}
//struct TreeNode* getFather(struct TreeNode* node, int depth, int mx)
//{
//    if (node == NULL) return NULL;
//    if (depth == mx) return node;
//    struct TreeNode* left = getFather(node->left, depth + 1, mx);
//    struct TreeNode* right = getFather(node->right, depth + 1, mx);
//    if (left || right)
//    {
//        if (left && right) return node;
//        return left ? left : right;
//    }
//    return NULL;
//}
//struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
//{
//    int mx_depth = getDepth(root);
//    return getFather(root, 1, mx_depth);
//}
//
//// 543. 二叉树的直径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, ans);
//    int right = dfs(node->right, ans);
//    *ans = fmax(*ans, left + right); // number of nodes - 1 == path
//    return left > right ? left + 1 : right + 1;
//}
//int diameterOfBinaryTree(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
//// 687. 最长同值路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, ans);
//    int right = dfs(node->right, ans);
//    left = left && node->left->val == node->val ? left : 0;
//    right = right && node->right->val == node->val ? right : 0;
//    *ans = fmax(*ans, left + right); // number of nodes - 1 == path
//    return left > right ? left + 1 : right + 1;
//}
//int longestUnivaluePath(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
