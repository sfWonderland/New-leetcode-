////111. 二叉树的最小深度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int minDepth(struct TreeNode* root)
//{
//    if (!root)
//        return 0;
//    if (root->left && root->right)
//        return 1 + fmin(minDepth(root->left), minDepth(root->right));
//    else if (root->left)
//        return 1 + minDepth(root->left);
//    else if (root->right)
//        return 1 + minDepth(root->right);
//    else
//        return 1;
//}
//
////104. 二叉树的最大深度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root)
//{
//    if (!root)
//        return 0;
//    if (root->left && root->right)
//        return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
//    else if (root->left)
//        return 1 + maxDepth(root->left);
//    else if (root->right)
//        return 1 + maxDepth(root->right);
//    else
//        return 1;
//}
//
////118. 杨辉三角
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** generate(int numRows, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * numRows);
//    *returnSize = numRows;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
//    for (int i = 0; i < numRows; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * (i + 1));
//        ans[i][0] = 1;
//        for (int j = 1; j < i; j++)
//        {
//            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
//        }
//        ans[i][i] = 1;
//        (*returnColumnSizes)[i] = i + 1;
//    }
//    return ans;
//}
//
////119. 杨辉三角 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getRow(int rowIndex, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * (rowIndex + 1));
//    ans[0] = 1;
//    for (int i = 1; i <= rowIndex; i++)
//    {
//        ans[i] = (long)ans[i - 1] * (rowIndex - i + 1) / i;
//    }
//    *returnSize = rowIndex + 1;
//    return ans;
//}
//
