////861. 翻转矩阵后的得分
//
//int matrixScore(int** grid, int gridSize, int* gridColSize)
//{
//    for (int i = 0; i < gridSize; i++)
//    {
//        if (grid[i][0] == 0)
//        {
//            for (int j = 0; j < gridColSize[0]; j++)
//            {
//                grid[i][j] ^= 1;
//            }
//        }
//    }
//    int ans = gridSize;
//    for (int j = 1; j < gridColSize[0]; j++)
//    {
//        int nums[2] = { 0 };
//        for (int i = 0; i < gridSize; i++)
//        {
//            nums[grid[i][j]]++;
//        }
//        ans <<= 1;
//        ans += fmax(nums[0], nums[1]);
//    }
//    return ans;
//}
//
////1605. 给定行和列的和求可行矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = rowSumSize, n = colSumSize;
//    int** ans = (int**)malloc(sizeof(int*) * m);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (int*)calloc(sizeof(int), n);
//        (*returnColumnSizes)[i] = n;
//    }
//    int i = 0, j = 0;
//    while (i < m && j < n)
//    {
//        if (rowSum[i] >= colSum[j])
//        {
//            rowSum[i] -= colSum[j];
//            ans[i][j] = colSum[j];
//            j++;
//        }
//        else
//        {
//            colSum[j] -= rowSum[i];
//            ans[i][j] = rowSum[i];
//            i++;
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
////3712. 出现次数能被 K 整除的元素总和
//
//int sumDivisibleByK(int* nums, int numsSize, int k)
//{
//    int cnt[101] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (cnt[nums[i]])
//        {
//            if (cnt[nums[i]] % k == 0)
//            {
//                ans += nums[i] * cnt[nums[i]];
//            }
//            cnt[nums[i]] = 0;
//        }
//    }
//    return ans;
//}
//
////108. 将有序数组转换为二叉搜索树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//        return NULL;
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    int mid = numsSize / 2;
//    root->val = nums[mid];
//    root->left = sortedArrayToBST(nums, mid);
//    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
//    return root;
//}
//
