////129. 求根节点到叶节点数字之和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s, int n)
//{
//    if (s == NULL)
//        return 0;
//    int tmp = n * 10 + s->val;
//    if (s->left || s->right)
//        return dfs(s->left, tmp) + dfs(s->right, tmp);
//
//    return tmp;
//}
//int sumNumbers(struct TreeNode* root)
//{
//    return dfs(root, 0);
//}
//
////1448. 统计二叉树中好节点的数目
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s, int mx)
//{
//    if (s == NULL)
//        return 0;
//
//    int n = s->val;
//    if (n >= mx)
//        return dfs(s->left, n) + dfs(s->right, n) + 1;
//
//    return dfs(s->left, mx) + dfs(s->right, mx);
//}
//int goodNodes(struct TreeNode* root)
//{
//    return dfs(root, -10001);
//}
//
////101. 对称二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* l, struct TreeNode* r)
//{
//    if (l == NULL && r == NULL)
//        return true;
//
//    if (l != NULL && r != NULL)
//        return l->val == r->val ? dfs(l->left, r->right) & dfs(l->right, r->left) : false;
//
//    return false;
//}
//bool isSymmetric(struct TreeNode* root)
//{
//    return dfs(root->left, root->right);
//}
//
////199. 二叉树的右视图
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
//void dfs(struct TreeNode* s, int depth, int* ans, int* n)
//{
//    if (s == NULL)
//        return;
//
//    if (depth == *n)
//        ans[(*n)++] = s->val;
//
//    dfs(s->right, depth + 1, ans, n);
//    dfs(s->left, depth + 1, ans, n);
//}
//int* rightSideView(struct TreeNode* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    *returnSize = 0;
//    dfs(root, 0, ans, returnSize);
//    return ans;
//}
//
