////137. 只出现一次的数字 II
//
//int singleNumber(int* nums, int numsSize)
//{
//    unsigned int digit[32] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        int t = 0;
//        unsigned int copy = nums[i];
//        while (copy)
//        {
//            digit[t] += copy & 1;
//            copy >>= 1;
//            t++;
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        //printf("%d", digit[i] % 3);
//        ans |= (digit[i] % 3) << i;
//    }
//    return ans;
//}
//
////274. H 指数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int hIndex(int* citations, int citationsSize)
//{
//    qsort(citations, citationsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (; ans < citationsSize; ans++)
//    {
//        if (citations[ans] < ans + 1)
//            break;
//    }
//    return ans;
//}
//
////275. H 指数 II
//
//int hIndex(int* citations, int citationsSize)
//{
//    int left = 0;
//    int right = citationsSize - 1;
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (citations[citationsSize - 1 - mid] >= mid + 1)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return left;
//}
//
////3033. 修改矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * matrixSize);
//    *returnSize = matrixSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * matrixSize);
//    for (int i = 0; i < matrixSize; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
//        (*returnColumnSizes)[i] = matrixColSize[0];
//    }
//    for (int i = 0; i < matrixColSize[0]; i++)
//    {
//        int max = -1;
//        for (int j = 0; j < matrixSize; j++)
//        {
//            ans[j][i] = matrix[j][i];
//            max = fmax(max, matrix[j][i]);
//        }
//        for (int j = 0; j < matrixSize; j++)
//        {
//            if (matrix[j][i] == -1)
//                ans[j][i] = max;
//        }
//    }
//
//    return ans;
//}
//
