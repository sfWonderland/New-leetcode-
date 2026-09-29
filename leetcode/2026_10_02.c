//// 971. 翻转二叉树以匹配先序遍历
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
//int* ans;
//int ansSize;
//
//int* path;
//int pathSize;
//int idx;
//
//void dfs(struct TreeNode* node)
//{
//    if (!node) return;
//    if (node->val != path[idx++])
//    {
//        ansSize = 0;
//        ans[ansSize++] = -1;
//        return;
//    }
//    struct TreeNode* first = node->left;
//    struct TreeNode* second = node->right;
//    if (first && first->val != path[idx])//
//    {
//        ans[ansSize++] = node->val;
//        first = node->right;
//        second = node->left;
//    }
//    dfs(first);
//    dfs(second);
//}
//
//int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize)
//{
//    ans = (int*)malloc(sizeof(int) * voyageSize);
//    ansSize = 0, idx = 0, pathSize = voyageSize;
//    path = voyage;
//
//    dfs(root);
//    *returnSize = ans[0] == -1 ? 1 : ansSize;
//    return ans;
//}
//
//// 965. 单值二叉树    
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* node, int x)
//{
//    if (!node) return true;
//    if (node->val != x) return false;
//    return dfs(node->left, x) & dfs(node->right, x);
//}
//bool isUnivalTree(struct TreeNode* root)
//{
//    return dfs(root, root->val);
//}
//
//// 100. 相同的树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == q) return true;
//    if (!p || !q) return false;
//    return p->val == q->val && isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
//}
//
//// 101. 对称二叉树
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
//    if (left == right) return true;
//    if (!left || !right) return false;
//    return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
//}
//bool isSymmetric(struct TreeNode* root)
//{
//    return dfs(root->left, root->right);
//}
//
