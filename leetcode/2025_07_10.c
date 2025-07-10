////3239. 最少翻转次数使二进制矩阵回文 I.
//
//int minFlips(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0];
//    int ans_r = 0, ans_c = 0;
//    for (int i = 0; i < row; i++)
//    {
//        int left = 0, right = col - 1;
//        while (left < right)
//        {
//            if (grid[i][left] != grid[i][right])
//                ans_r++;
//
//            left++; right--;
//        }
//    }
//    for (int i = 0; i < col; i++)
//    {
//        int left = 0, right = row - 1;
//        while (left < right)
//        {
//            if (grid[left][i] != grid[right][i])
//                ans_c++;
//
//            left++; right--;
//        }
//    }
//    return fmin(ans_r, ans_c);
//}
//
////807. 保持城市天际线
//
//int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize)
//{
//    int row = gridSize, col = gridColSize[0], sum = 0;
//    int** ans = (int**)malloc(sizeof(int*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        int max = 0;
//        for (int j = 0; j < col; j++)
//        {
//            max = fmax(max, grid[i][j]);
//            sum += grid[i][j];
//        }
//        ans[i] = (int*)malloc(sizeof(int) * col);
//        for (int k = 0; k < col; k++)
//        {
//            ans[i][k] = max;
//        }
//    }
//    for (int i = 0; i < col; i++)
//    {
//        int max = 0;
//        for (int j = 0; j < row; j++)
//        {
//            max = fmax(max, grid[j][i]);
//        }
//        for (int k = 0; k < row; k++)
//        {
//            ans[k][i] = fmin(max, ans[k][i]);
//        }
//    }
//    int ret = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            ret += ans[i][j];
//        }
//    }
//    free(ans);
//    return ret - sum;
//}
//
////3211. 生成不含相邻零的二进制字符串
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** validStrings(int n, int* returnSize)
//{
//    int m = 1 << n;
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    char* s = (char*)malloc(sizeof(char) * (n + 1));
//    memset(s, '0', sizeof(char) * n);
//    s[n] = '\0';
//    int aSize = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int len = 1, last = i >> (n - 1);
//        s[0] = last + '0';
//        for (int j = n - 2; j >= 0; j--)
//        {
//            int t = (i >> j) & 1;
//            if (t || last) s[len++] = t + '0';
//            else break;
//            last = t;
//        }
//        if (len == n)
//        {
//            ans[aSize] = (char*)malloc(sizeof(char) * (n + 1));
//            for (int k = 0; k < n + 1; k++)
//            {
//                ans[aSize][k] = s[k];
//            }
//            aSize++;
//        }
//    }
//    *returnSize = aSize;
//    return ans;
//}
//
////610. 转换二维数组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int cnt[numsSize + 1];
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        cnt[i] = 0;
//    }
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//        max = fmax(max, cnt[nums[i]]);
//    }
//    int** ans = (int**)malloc(sizeof(int*) * max);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * max);
//    int n = numsSize, t = 0;
//    while (n)
//    {
//        int m = 0;
//        ans[t] = (int*)malloc(sizeof(int) * n);
//        for (int i = 0; i < numsSize; i++)
//        {
//            if (cnt[i + 1])
//            {
//                cnt[i + 1]--;
//                ans[t][m++] = i + 1;
//                n--;
//            }
//        }
//        (*returnColumnSizes)[t++] = m;
//    }
//    *returnSize = t;
//    return ans;
//}
//
