////LCR 046. 二叉树的右视图
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
//
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* rightSideView(struct TreeNode* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    memset(ans, 0x3f3f3f3f, sizeof(int) * 100);
//    *returnSize = 0;
//    void dfs(struct TreeNode* node, int floor)
//    {
//        if (node == NULL)
//            return;
//
//        *returnSize = fmax(*returnSize, floor + 1);
//
//        dfs(node->right, floor + 1);
//        if (ans[floor] == 0x3f3f3f3f)
//            ans[floor] = node->val;
//        dfs(node->left, floor + 1);
//    }
//    dfs(root, 0);
//    return ans;
//}
//
//// LCR 047. 二叉树剪枝   
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
//bool dfs(struct TreeNode* node)
//{
//    if (node->left)
//        node->left = dfs(node->left) ? node->left : NULL;
//
//    if (node->right)
//        node->right = dfs(node->right) ? node->right : NULL;
//
//    return node->left || node->right || node->val;
//}
//struct TreeNode* pruneTree(struct TreeNode* root)
//{
//    return dfs(root) ? root : NULL;
//}
//
//// LCR 049. 求根节点到叶节点数字之和
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
//int dfs(struct TreeNode* node, int pre)
//{
//    int x = pre * 10 + node->val;
//    if (!node->left && !node->right)
//        return x;
//
//    int sum = 0;
//    if (node->left)
//        sum += dfs(node->left, x);
//    if (node->right)
//        sum += dfs(node->right, x);
//
//    return sum;
//}
//
//int sumNumbers(struct TreeNode* root)
//{
//    return dfs(root, 0);
//}
//
//// LCR 050. 路径总和 III
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
//int dfs(struct TreeNode* node, int targetSum, long long sum)
//{
//    if (node == NULL)
//        return 0;
//
//    sum += node->val;
//
//    return (sum == targetSum) + dfs(node->left, targetSum, sum) + dfs(node->right, targetSum, sum);
//}
//
//int pathSum(struct TreeNode* root, int targetSum)
//{
//    if (root == NULL)
//        return 0;
//
//    return dfs(root, targetSum, 0ll) + pathSum(root->right, targetSum) + pathSum(root->left, targetSum);
//}
//
