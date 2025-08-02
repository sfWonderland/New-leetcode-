////LCR 175. 计算二叉树的深度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s)
//{
//    if (s == NULL)
//        return 0;
//
//    return fmax(dfs(s->left), dfs(s->right)) + 1;
//}
//int calculateDepth(struct TreeNode* root)
//{
//    return dfs(root);
//}
//
////700. 二叉搜索树中的搜索
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* dfs(struct TreeNode* s, int val)
//{
//    if (s == NULL)
//        return NULL;
//
//    if (s->val == val)
//        return s;
//    struct TreeNode* l = dfs(s->left, val);
//    struct TreeNode* r = dfs(s->right, val);
//
//    if (l)
//        return l;
//    if (r)
//        return r;
//    return NULL;
//}
//struct TreeNode* searchBST(struct TreeNode* root, int val)
//{
//    return dfs(root, val);
//}
//
////LCR 144. 翻转二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* s)
//{
//    if (s == NULL)
//        return;
//    dfs(s->left);
//    dfs(s->right);
//    struct TreeNode* tmp = s->left;
//    s->left = s->right;
//    s->right = tmp;
//}
//struct TreeNode* flipTree(struct TreeNode* root)
//{
//    dfs(root);
//    return root;
//}
//
////1305. 两棵二叉搜索树中的所有元素
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
//void dfs(struct TreeNode* s, int* nums, int* n)
//{
//    if (s == NULL)
//        return;
//
//    dfs(s->left, nums, n);
//    dfs(s->right, nums, n);
//    nums[(*n)++] = s->val;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 10000);
//    *returnSize = 0;
//    dfs(root1, ans, returnSize);
//    dfs(root2, ans, returnSize);
//    qsort(ans, *returnSize, sizeof(int), cmp);
//    return ans;
//}
//
