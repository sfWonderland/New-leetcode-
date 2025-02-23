////2469.温度转换
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//double* convertTemperature(double celsius, int* returnSize)
//{
//    double* ret = (double*)malloc(sizeof(double) * 2);
//    ret[0] = celsius + 273.15;
//    ret[1] = celsius * 1.8 + 32;
//    *returnSize = 2;
//    return ret;
//}
//
////2236.判断根结点是否等于子结点值之和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool checkTree(struct TreeNode* root)
//{
//    return root->val == root->left->val + root->right->val;
//}
//
////867.转置矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
//{
//    int row = matrixColSize[0];
//    int col = matrixSize;
//    *returnSize = row;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
//    for (int i = 0; i < row; i++)
//    {
//        (*returnColumnSizes)[i] = col;
//    }
//    int** transposed = (int**)malloc(sizeof(int*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        transposed[i] = (int*)malloc(sizeof(int) * col);
//    }
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//            transposed[i][j] = matrix[j][i];
//    }
//    return transposed;
//}
//
////852.山脉数组的峰顶索引
//
//int peakIndexInMountainArray(int* arr, int arrSize)
//{
//    int left = 0;
//    int right = arrSize - 1;
//    while (left < right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (arr[mid] > arr[mid + 1])
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
////162.寻找峰值
//
//int findPeakElement(int* nums, int numsSize)
//{
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] > nums[mid + 1])
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
