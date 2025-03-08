////172. 阶乘后的零
//
//int trailingZeroes(int n)
//{
//    int ret = 0;
//    int i = 5;
//    while (i <= n)
//    {
//        int num = i;
//        while (0 == num % 5)
//        {
//            num /= 5;
//            ret++;
//        }
//        i += 5;
//    }
//    return ret;
//}
//
////233. 数字 1 的个数
//
//int countDigitOne(int n)
//{
//    long size = 1;
//    int num = 0;
//    while (size <= n)
//    {
//        int dividend = n / (size * 10);
//        int remainder = n - dividend * size * 10;
//        num += dividend * size + fmin(fmax(remainder - size + 1, 0), size);
//        size *= 10;
//    }
//    return num;
//}
//
////54. 螺旋矩阵
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//const int DIRS[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//右下左上
//
//int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int size = m * n;
//    int* ret = (int*)malloc(sizeof(int) * size);
//    *returnSize = 0;
//    int i = 0, j = -1;
//    for (int di = 0; *returnSize < size; di = (di + 1) % 4)
//    {
//        for (int k = 0; k < n; k++)
//        {
//            i += DIRS[di][0];
//            j += DIRS[di][1];
//            ret[(*returnSize)++] = matrix[i][j];
//        }
//        int tmp = n;
//        n = m - 1;
//        m = tmp;
//    }
//    return ret;
//}
//
