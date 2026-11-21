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
//    int ansSize = 0;
//    struct TreeNode* st[100];
//    int top = 0;
//    st[top++] = root;
//    while (top > 0)
//    {
//        if (st[top - 1])
//        {
//            ans[ansSize++] = st[top - 1]->val;
//            st[top++] = st[top - 1]->left;
//        }
//        else if (--top > 0)
//            st[top - 1] = st[top - 1]->right;
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
