////1457. 二叉树中的伪回文路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, bool* digit)
//{
//    digit[node->val] ^= 1;
//    if (node->left || node->right)
//    {
//        int sum = 0;
//        if (node->left) sum += dfs(node->left, digit);
//        if (node->right) sum += dfs(node->right, digit);
//        digit[node->val] ^= 1;
//        return sum;
//    }
//    int diff = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        diff += digit[i];
//    }
//    digit[node->val] ^= 1;
//    return diff <= 1;
//}
//int pseudoPalindromicPaths(struct TreeNode* root)
//{
//    bool* digit = (bool*)calloc(10, sizeof(bool));
//    return dfs(root, digit);
//}
//
//// 437. 路径总和 III
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int x, long long sum)
//{
//    if (node == NULL) return 0;
//
//    sum += node->val;
//    return (sum == x) + dfs(node->left, x, sum) + dfs(node->right, x, sum);
//}
//int pathSum(struct TreeNode* root, int targetSum)
//{
//    if (root == NULL) return 0;
//
//    return dfs(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
//}
//
//// 235. 二叉搜索树的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == NULL || root == p || root == q) return root;
//    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left && right) return root;
//    return left ? left : right;
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
//
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (p->val > q->val)
//    {
//        struct TreeNode* tmp = p;
//        p = q;
//        q = tmp;
//    }
//    if (root->val > q->val)
//        return lowestCommonAncestor(root->left, p, q);
//    else if (root->val < p->val)
//        return lowestCommonAncestor(root->right, p, q);
//    return root;
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
//
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (p->val > q->val)
//    {
//        struct TreeNode* tmp = p;
//        p = q;
//        q = tmp;
//    }
//    while (1)
//    {
//        if (root->val > q->val)
//            root = root->left;
//        else if (root->val < p->val)
//            root = root->right;
//        else
//            break;
//    }
//    return root;
//}
//
//// 236. 二叉树的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == NULL || root == p || root == q) return root;
//    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left && right) return root;
//    return left ? left : right;
//}
//
