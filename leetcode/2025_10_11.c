////173. 二叉搜索树迭代器
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
//typedef struct
//{
//    int* nums;
//    int numsSize;
//    int top;
//} BSTIterator;
//
//int getTreeNum(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return getTreeNum(root->left) + getTreeNum(root->right) + 1;
//}
//
//void dfs(struct TreeNode* root, int* nums, int* n)
//{
//    if (root == NULL)
//        return;
//
//    dfs(root->left, nums, n);
//    nums[(*n)++] = root->val;
//    dfs(root->right, nums, n);
//}
//
//BSTIterator* bSTIteratorCreate(struct TreeNode* root)
//{
//    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
//    obj->numsSize = 0;
//    obj->nums = (int*)malloc(sizeof(int) * getTreeNum(root));
//    dfs(root, obj->nums, &obj->numsSize);
//    obj->top = 0;
//    return obj;
//}
//
//int bSTIteratorNext(BSTIterator* obj)
//{
//    return obj->nums[obj->top++];
//}
//
//bool bSTIteratorHasNext(BSTIterator* obj)
//{
//    return obj->top < obj->numsSize;
//}
//
//void bSTIteratorFree(BSTIterator* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your BSTIterator struct will be instantiated and called as such:
// * BSTIterator* obj = bSTIteratorCreate(root);
// * int param_1 = bSTIteratorNext(obj);
//
// * bool param_2 = bSTIteratorHasNext(obj);
//
// * bSTIteratorFree(obj);
//*/
//
////654. 最大二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
//{
//    //printf("%d %d\n", nums[0], numsSize);
//    if (numsSize <= 0)
//        return NULL;
//    int max = -1, val = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (max < nums[i])
//        {
//            max = nums[i];
//            val = i;
//        }
//    }
//    //printf("%d %d\n", max, val);
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = nums[val];
//    root->left = constructMaximumBinaryTree(nums, val);
//    root->right = constructMaximumBinaryTree(nums + val + 1, numsSize - val - 1);
//    return root;
//}
//
////2161. 根据给定数字划分数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[i] = pivot;
//    }
//    int L = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] < pivot)
//            ans[L++] = nums[i];
//    }
//    int R = numsSize - 1;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (nums[i] > pivot)
//            ans[R--] = nums[i];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
////2482. 行和列中一和零的差值
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    int sumR[m], sumC[n];
//    for (int i = 0; i < m; i++)
//    {
//        sumR[i] = 0;
//        for (int j = 0; j < n; j++)
//        {
//            sumR[i] += grid[i][j] ? 1 : -1;
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        sumC[i] = 0;
//        for (int j = 0; j < m; j++)
//        {
//            sumC[i] += grid[j][i] ? 1 : -1;
//        }
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            grid[i][j] = sumR[i] + sumC[j];
//        }
//    }
//    *returnSize = m;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//    }
//    return grid;
//}
//
