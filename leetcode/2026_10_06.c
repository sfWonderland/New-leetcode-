//// 1339. 分裂二叉树的最大乘积
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//const int MOD = 1e9 + 7;
//int maxProduct(struct TreeNode* root)
//{
//    int nums[50000];
//    int n = 0;
//    long long dfs(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return 0;
//        nums[n] = root->val + dfs(root->left) + dfs(root->right);
//        return nums[n++];
//    }
//    long long total = dfs(root);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        long long cur = 1ll * nums[i] * (total - nums[i]);
//        ans = ans > cur ? ans : cur;
//    }
//    return ans % MOD;
//}
//
//// 814. 二叉树剪枝    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* dfs(struct TreeNode* node)
//{
//    if (node == NULL) return NULL;
//    node->left = dfs(node->left);
//    node->right = dfs(node->right);
//    if (node->left || node->right) return node;
//    return node->val ? node : NULL;
//}
//struct TreeNode* pruneTree(struct TreeNode* root)
//{
//    return dfs(root);
//}
//
//// 1325. 删除给定值的叶子节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
//{
//    if (root == NULL) return NULL;
//    root->left = removeLeafNodes(root->left, target);
//    root->right = removeLeafNodes(root->right, target);
//    if (root->left || root->right) return root;
//    return root->val == target ? NULL : root;
//}
//
//// 1110. 删点成林
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
//struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
//{
//    bool delete[1001] = { 0 };
//    for (int i = 0; i < to_deleteSize; i++)
//    {
//        delete[to_delete[i]] = true;
//    }
//    struct TreeNode** ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 500);
//    *returnSize = 0;
//    struct TreeNode* dfs(struct TreeNode* node)
//    {
//        if (node == NULL) return NULL;
//        node->left = dfs(node->left);
//        node->right = dfs(node->right);
//        if (delete[node->val])
//        {
//            if (node->left) ans[(*returnSize)++] = node->left;
//            if (node->right) ans[(*returnSize)++] = node->right;
//            return NULL;
//        }
//        return node;
//    }
//    root = dfs(root);
//    if (root) ans[(*returnSize)++] = root;
//    return ans;
//}
//
