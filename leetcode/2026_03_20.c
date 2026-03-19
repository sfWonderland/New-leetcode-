////3567. 子矩阵的最小绝对差
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    int** ans = (int**)malloc(sizeof(int*) * (m - k + 1));
//    *returnSize = m - k + 1;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (m - k + 1));
//    if (k == 1)
//    {
//        for (int i = 0; i <= m - k; i++)
//        {
//            ans[i] = (int*)calloc(sizeof(int), n - k + 1);
//            (*returnColumnSizes)[i] = n - k + 1;
//        }
//        return ans;
//    }
//    int arr[k * k];
//    for (int i = 0; i <= m - k; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * (n - k + 1));
//        (*returnColumnSizes)[i] = n - k + 1;
//        for (int j = 0; j <= n - k; j++)
//        {
//            for (int r = i; r < i + k; r++)
//            {
//                int x = (r - i) * k;
//                for (int c = j; c < j + k; c++)
//                {
//                    arr[x + c - j] = grid[r][c];
//                }
//            }
//            qsort(arr, k * k, sizeof(int), cmp);
//            int res = INT_MAX;
//            for (int d = 1; d < k * k; d++)
//            {
//                int diff = arr[d] - arr[d - 1];
//                if (diff && res > diff)
//                    res = diff;
//            }
//            ans[i][j] = res == INT_MAX ? 0 : res;
//        }
//    }
//    return ans;
//}
//
////2609. 最长平衡子字符串    
//
//int findTheLongestBalancedSubstring(char* s)
//{
//    int zeros = 0, ones = 0;
//    int ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if ('1' - s[i])
//        {
//            if (ones)
//            {
//                ans = fmax(ans, fmin(ones, zeros) * 2);
//                zeros = 1;
//                ones = 0;
//            }
//            else
//                zeros++;
//        }
//        else
//        {
//            ones++;
//        }
//    }
//    ans = fmax(ans, fmin(ones, zeros) * 2);
//    return ans;
//}
//
////2640. 一个数组所有前缀的分数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//long long* findPrefixScore(int* nums, int numsSize, int* returnSize)
//{
//    long long* ans = (long long*)malloc(sizeof(long long) * numsSize);
//    long long pre = 0;
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//            max = nums[i];
//        pre += max + nums[i];
//        ans[i] = pre;
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
////2661. 找出叠涂元素
//
//int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize)
//{
//    int m = matSize, n = matColSize[0];
//    int Pcol[arrSize], Prow[arrSize];
//    int col[n], row[m];
//    memset(col, 0, sizeof(col));
//    memset(row, 0, sizeof(row));
//
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int x = mat[i][j] - 1;
//            Pcol[x] = j;
//            Prow[x] = i;
//        }
//    }
//
//    for (int i = 0; i < arrSize; i++)
//    {
//        int x = Prow[arr[i] - 1], y = Pcol[arr[i] - 1];
//        row[x]++; col[y]++;
//        if (row[x] == n || col[y] == m)
//            return i;
//    }
//    return -1;
//}
//
