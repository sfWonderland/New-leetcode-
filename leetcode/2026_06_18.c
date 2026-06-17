//// 885. ÂİĞı¾ØÕó III
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // ÓÒÏÂ×óÉÏ
//int** spiralMatrixIII(int rows, int cols, int rStart, int cStart, int* returnSize, int** returnColumnSizes)
//{
//    int blocks = rows * cols;
//    int** ans = (int**)malloc(sizeof(int*) * blocks);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * blocks);
//    *returnSize = 0;
//    int r = rStart, c = cStart;
//    int d = 0, step = 1;
//    while ((*returnSize) < blocks)
//    {
//        for (int i = 0; i < 2; i++)
//        {
//            for (int j = 0; j < step; j++)
//            {
//                if (r >= 0 && r < rows && c >= 0 && c < cols)
//                {
//                    ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
//                    ans[*returnSize][0] = r;
//                    ans[*returnSize][1] = c;
//                    (*returnColumnSizes)[(*returnSize)++] = 2;
//                }
//
//                r += dir[d][0];
//                c += dir[d][1];
//            }
//            d = (d + 1) % 4;
//        }
//        step++;
//    }
//    return ans;
//}
//
