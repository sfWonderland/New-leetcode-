//// 144. 二叉树的前序遍历
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
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    *returnSize = 0;
//    struct TreeNode** st = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = 0;
//    st[top++] = root;
//    while (top > 0)
//    {
//        while (st[top - 1])
//        {
//            ans[(*returnSize)++] = st[top - 1]->val;
//            st[top++] = st[top - 1]->left;
//        }
//        top--;
//        if (top > 0)
//            st[top - 1] = st[top - 1]->right;
//    }
//    return ans;
//}
//
//// 94. 二叉树的中序遍历
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
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    struct TreeNode** st = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = 0;
//    st[top++] = root;
//    while (top > 0)
//    {
//        while (st[top - 1])
//            st[top++] = st[top - 1]->left;
//        --top;
//        if (top > 0)
//        {
//            ans[(*returnSize)++] = st[top - 1]->val;
//            st[top - 1] = st[top - 1]->right;
//        }
//    }
//    return ans;
//}
//
//// 145. 二叉树的后序遍历
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
//int* postorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    struct TreeNode** st = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = 0;
//    st[top++] = root;
//    while (top > 0)
//    {
//        while (st[top - 1] && st[top - 1]->val <= 100)
//            st[top++] = st[top - 1]->left;
//        --top;
//        if (st[top - 1]->right && st[top - 1]->right->val <= 100)
//            st[top++] = st[top - 1]->right;
//        else
//        {
//            ans[(*returnSize)++] = st[--top]->val;
//            st[top]->val += 201;
//        }
//    }
//    return ans;
//}
//
//// 872. 叶子相似的树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, int* nums, int* size)
//{
//    if (node->left || node->right)
//    {
//        if (node->left) dfs(node->left, nums, size);
//        if (node->right) dfs(node->right, nums, size);
//    }
//    else
//        nums[(*size)++] = node->val;
//}
//bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
//{
//    int* nums1 = (int*)malloc(sizeof(int) * 100);
//    int* nums2 = (int*)malloc(sizeof(int) * 100);
//    int size1 = 0, size2 = 0;
//    dfs(root1, nums1, &size1);
//    dfs(root2, nums2, &size2);
//    if (size1 != size2) return false;
//    for (int i = 0; i < size1; i++)
//    {
//        if (nums1[i] != nums2[i])
//            return false;
//    }
//    free(nums1);
//    free(nums2);
//    return true;
//}
//
