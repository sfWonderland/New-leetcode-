////3697. 计算十进制表示
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(int* arr, int l, int r)
//{
//    while (l < r)
//    {
//        int tmp = arr[l];
//        arr[l++] = arr[r];
//        arr[r--] = tmp;
//    }
//}
//int* decimalRepresentation(int n, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 10);
//    int idx = 0;
//    long long base = 1;
//    while (n)
//    {
//        if (n % 10)
//            ans[idx++] = n % 10 * base;
//        base *= 10;
//        n /= 10;
//    }
//    reverse(ans, 0, idx - 1);
//    *returnSize = idx;
//    return ans;
//}
//
////3698. 分割数组得到最小绝对差
//
//long long splitArray(int* nums, int numsSize)
//{
//    bool flag = 0;
//    long long suml = nums[0], sumr = 0;
//    int max = -1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (!flag)
//        {
//            if (nums[i] <= nums[i - 1])
//            {
//                flag = 1;
//                if (nums[i] < nums[i - 1] && i > 1)
//                    max = nums[i - 1];
//                sumr = nums[i];
//            }
//            else
//                suml = suml + nums[i];
//        }
//        else
//        {
//            if (nums[i] >= nums[i - 1])
//                return -1;
//            else
//                sumr = sumr + nums[i];
//        }
//    }
//    if (!flag)
//        return fabs(2 * nums[numsSize - 1] - suml);
//    long long a = fabs(suml - sumr);
//    long long b = LLONG_MAX;
//    if (max > 0)
//    {
//        suml -= max;
//        sumr += max;
//        b = fabs(suml - sumr);
//    }
//    return fmin(a, b);
//}
//
////1329. 将矩阵按对角线排序
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = matSize, n = matColSize[0];
//    int len = fmin(m, n);
//    int* line = (int*)malloc(sizeof(int) * len);
//    for (int i = 1 - m; i < n; i++)
//    {
//        int idx = 0;
//        for (int j = 0; j < m; j++)
//        {
//            if (i + j < 0)
//                continue;
//            if (i + j >= n)
//                break;
//            line[idx++] = mat[j][i + j];
//        }
//        qsort(line, idx, sizeof(int), cmp);
//        for (int j = 0; j < m; j++)
//        {
//            if (i + j < 0)
//                continue;
//            if (i + j >= n)
//                break;
//            mat[j][i + j] = line[--idx];
//        }
//    }
//    *returnSize = m;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//    }
//    return mat;
//}
//
////2711. 对角线上不同值的数量差
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** differenceOfDistinctValues(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    for (int i = 1 - m; i < n; i++)
//    {
//        int left[51] = { 0 };
//        int suf = 0;
//        for (int j = 0; j < m; j++)
//        {
//            if (i + j < 0)
//                continue;
//            if (i + j >= n)
//                break;
//
//            if (!left[grid[j][i + j]])
//                suf++;
//
//            left[grid[j][i + j]]++;
//        }
//        int right[51] = { 0 };
//        int pre = 0;
//        for (int j = m - 1; j >= 0; j--)
//        {
//            if (i + j >= n)
//                continue;
//            if (i + j < 0)
//                break;
//
//            int x = grid[j][i + j];
//            left[x]--;
//            if (!left[x]) suf--;
//
//            grid[j][i + j] = abs(suf - pre);
//
//            if (!right[x]) pre++;
//            right[x]++;
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
