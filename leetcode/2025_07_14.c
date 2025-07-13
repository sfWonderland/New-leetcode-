////46. 全排列
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** permutations;
//int permutationsSize;
//
//int* permutation;
//int len;
//
//void dfs(int idx, int* nums, int numsSize, int** returnColumnSizes)
//{
//    if (idx == numsSize)
//    {
//        permutations[permutationsSize] = (int*)malloc(sizeof(int) * numsSize);
//        memcpy(permutations[permutationsSize], permutation, sizeof(int) * numsSize);
//        (*returnColumnSizes)[permutationsSize++] = numsSize;
//        return;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 10)
//            continue;
//
//        permutation[idx] = nums[i];
//        nums[i] += 21;
//        dfs(idx + 1, nums, numsSize, returnColumnSizes);
//        nums[i] -= 21;
//    }
//}
//
//int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n *= i + 1;
//    }
//    permutations = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    permutation = (int*)malloc(sizeof(int) * numsSize);
//
//    permutationsSize = 0;
//
//    dfs(0, nums, numsSize, returnColumnSizes);
//
//    *returnSize = n;
//    return permutations;
//}
//
////47. 全排列 II
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//
//int** permutations;
//int permutationsSize;
//
//int* permutation;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//void dfs(int idx, int* nums, int numsSize, int** returnColumnSizes)
//{
//    if (idx == numsSize)
//    {
//        permutations[permutationsSize] = (int*)malloc(sizeof(int) * numsSize);
//        memcpy(permutations[permutationsSize], permutation, sizeof(int) * numsSize);
//        (*returnColumnSizes)[permutationsSize++] = numsSize;
//        return;
//    }
//
//    for (int i = 0; i < numsSize;)
//    {
//        if (nums[i] > 10)
//        {
//            i++;
//            continue;
//        }
//
//        permutation[idx] = nums[i];
//        nums[i] += 21;
//        dfs(idx + 1, nums, numsSize, returnColumnSizes);
//        nums[i] -= 21;
//        int x = nums[i];
//        i++;
//        while (i < numsSize && nums[i] == x)
//            i++;
//    }
//}
//
//int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//
//    int n = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n *= i + 1;
//    }
//
//    permutations = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    permutation = (int*)malloc(sizeof(int) * numsSize);
//
//    permutationsSize = 0;
//
//    dfs(0, nums, numsSize, returnColumnSizes);
//
//    *returnSize = permutationsSize;
//    return permutations;
//}
//
////51. N 皇后
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//
//char*** NQueens;
//int* col;
//
//bool* on_path;
//bool* positionSum1;
//bool* positionSum2;
//
//int NQueensSize;
//
//void dfs(int row, int n, int** returnColumnSizes)
//{
//    if (row == n)
//    {
//        NQueens[NQueensSize] = (char**)malloc(sizeof(char*) * n);
//        for (int i = 0; i < n; i++)
//        {
//            NQueens[NQueensSize][i] = (char*)malloc(sizeof(char) * (n + 1));
//            for (int j = 0; j < n; j++)
//            {
//                if (j == col[i])
//                    NQueens[NQueensSize][i][j] = 'Q';
//                else
//                    NQueens[NQueensSize][i][j] = '.';
//            }
//            NQueens[NQueensSize][i][n] = '\0';
//        }
//        (*returnColumnSizes)[NQueensSize++] = n;
//        return;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (on_path[i] || positionSum1[row - i + n - 1] || positionSum2[row + i])
//            continue;
//
//        col[row] = i;
//        on_path[i] = positionSum1[row - i + n - 1] = positionSum2[row + i] = true;
//        dfs(row + 1, n, returnColumnSizes);
//        on_path[i] = positionSum1[row - i + n - 1] = positionSum2[row + i] = false;
//    }
//}
//
//char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
//{
//    NQueens = (char***)malloc(sizeof(char**) * 1000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
//    col = (int*)malloc(sizeof(int) * n);
//    on_path = (bool*)malloc(sizeof(bool) * n);
//    for (int i = 0; i < n; i++)
//    {
//        on_path[i] = false;
//    }
//    positionSum1 = (bool*)malloc(sizeof(bool) * (2 * n - 1));
//    positionSum2 = (bool*)malloc(sizeof(bool) * (2 * n - 1));
//    for (int i = 0; i < 2 * n - 1; i++)
//    {
//        positionSum1[i] = false;
//        positionSum2[i] = false;
//    }
//
//    NQueensSize = 0;
//
//    dfs(0, n, returnColumnSizes);
//
//    *returnSize = NQueensSize;
//    return NQueens;
//}
//
////198. 打家劫舍.
//
//int rob(int* nums, int numsSize)
//{
//    int f[3] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        f[0] = fmax(f[1], f[2] + nums[i]);
//        f[2] = f[1];
//        f[1] = f[0];
//    }
//    return f[0];
//}
//
