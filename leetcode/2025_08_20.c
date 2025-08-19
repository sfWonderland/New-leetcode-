////304. 二维区域和检索 - 矩阵不可变
//
//typedef struct
//{
//    int** grid;
//    int gridSize;
//    int* gridColSize;
//} NumMatrix;
//
//
//NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int** sum = (int**)malloc(sizeof(int*) * (matrixSize + 1));
//    sum[0] = (int*)calloc(sizeof(int), (matrixColSize[0] + 1));
//    for (int i = 0; i < matrixSize; i++)
//    {
//        sum[i + 1] = (int*)calloc(sizeof(int), (matrixColSize[0] + 1));
//        for (int j = 0; j < matrixColSize[0]; j++)
//        {
//            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
//        }
//    }
//    NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
//    obj->grid = sum;
//    obj->gridSize = matrixSize + 1;
//    obj->gridColSize = (int*)malloc(sizeof(int));
//    obj->gridColSize[0] = matrixColSize[0] + 1;
//    return obj;
//}
//
//int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
//{
//    int** matrix = obj->grid;
//    return matrix[row2 + 1][col2 + 1] - matrix[row2 + 1][col1] - matrix[row1][col2 + 1] + matrix[row1][col1];
//}
//
//void numMatrixFree(NumMatrix* obj)
//{
//    for (int i = 0; i < obj->gridSize; i++)
//    {
//        free(obj->grid[i]);
//    }
//    free(obj->grid);
//}
//
///**
// * Your NumMatrix struct will be instantiated and called as such:
// * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
// * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
//
// * numMatrixFree(obj);
//*/
//
////1277. 统计全为 1 的正方形子矩阵
//
//int countSquares(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int ans = 0;
//    for (int i = 0; i < matrixSize; i++)
//    {
//        for (int j = 0; j < matrixColSize[0]; j++)
//        {
//            if (i && j && matrix[i][j])
//                matrix[i][j] = fmin(matrix[i - 1][j], fmin(matrix[i - 1][j - 1], matrix[i][j - 1])) + 1;
//
//            ans += matrix[i][j];
//        }
//    }
//    return ans;
//}
//
////59. 螺旋矩阵 II
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int DIR[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //右上左下
//int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * n);
//        for (int j = 0; j < n; j++)
//        {
//            ans[i][j] = 0;
//        }
//        (*returnColumnSizes)[i] = n;
//    }
//    int i = 0, j = 0, di = 0;
//    for (int val = 1; val <= n * n; val++)
//    {
//        ans[i][j] = val;
//        int x = i + DIR[di][0];
//        int y = j + DIR[di][1];
//        if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y])
//            di = (di + 1) % 4;
//        i += DIR[di][0];
//        j += DIR[di][1];
//    }
//    *returnSize = n;
//    return ans;
//}
//
////48. 旋转图像
//
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void rotate(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int n = matrixSize;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//            swap(&matrix[i][j], &matrix[j][i]);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n / 2; j++)
//            swap(&matrix[i][j], &matrix[i][n - 1 - j]);
//    }
//}
//
