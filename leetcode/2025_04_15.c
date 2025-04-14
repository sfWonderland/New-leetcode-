////226. 翻转二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if (root && (root->left || root->right))
//    {
//        struct TreeNode* p = invertTree(root->left);
//        root->left = invertTree(root->right);
//        root->right = p;
//    }
//    return root;
//}
//
////100. 相同的树
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
//    if (p && q)
//        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    else if (p == q)
//        return true;
//    else
//        return false;
//}
//
////144. 二叉树的前序遍历
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
//void preorder(struct TreeNode* root, int* num, int* ans)
//{
//    if (root == NULL)
//        return;
//    ans[num[0]++] = root->val;
//    preorder(root->left, num, ans);
//    preorder(root->right, num, ans);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    returnSize[0] = 0;
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    preorder(root, returnSize, ans);
//    return ans;
//}
//
////404. 左叶子之和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void leftLeaves(struct TreeNode* root, int* n)
//{
//    if (root == NULL)
//        return;
//    if (root->left)
//    {
//        if (root->left->left == NULL && root->left->right == NULL)
//            n[0] += root->left->val;
//        else
//            leftLeaves(root->left, n);
//    }
//    leftLeaves(root->right, n);
//}
//int sumOfLeftLeaves(struct TreeNode* root)
//{
//    int n = 0;
//    leftLeaves(root, &n);
//    return n;
//}
//
