////1878. 矩阵中最大的三个菱形和
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    int diag_sum[m + 1][n + 1], anti_sum[m + 1][n + 1];
//    memset(diag_sum, 0, sizeof(diag_sum)); // ↘前缀和
//    memset(anti_sum, 0, sizeof(anti_sum)); // ↙前缀和
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int val = grid[i][j];
//            diag_sum[i + 1][j + 1] = diag_sum[i][j] + val;
//            anti_sum[i + 1][j] = anti_sum[i][j + 1] + val;
//        }
//    }
//    // 从坐标(x, y)开始，k 个数的连续和
//    int query_diagonal(int x, int y, int k) // ↘    
//    {
//        return diag_sum[x + k][y + k] - diag_sum[x][y];
//    }
//    int query_anti_diagonal(int x, int y, int k) // ↙
//    {
//        return anti_sum[x + k][y + 1 - k] - anti_sum[x][y + 1];
//    }
//
//    int x = 0, y = 0, z = 0; // 最大，次大，第三大
//    void update(int val)
//    {
//        if (val > x)
//        {
//            z = y;
//            y = x;
//            x = val;
//        }
//        else if (val < x && val > y) // 三者互不相同
//        {
//            z = y;
//            y = val;
//        }
//        else if (val < y && val > z) // 三者互不相同
//            z = val;
//    }
//
//    // 枚举菱形中心 (i, j)
//    for (int i = 0; i < m; i++)
//    {
//        // i + k <= m - 1 && i - k >= 0  => k <= fmin(i, m - 1 - i);
//        int maxI = fmin(i, m - 1 - i);
//        for (int j = 0; j < n; j++)
//        {
//            update(grid[i][j]); // 一个数也算菱形
//            // j + k <= n - 1 && j - k >= 0  => k <= fmin(j, n - 1 - j);
//            int maxJ = fmin(j, n - 1 - j);
//            int mx = fmin(maxI, maxJ);
//            for (int k = 1; k <= mx; k++)
//            {
//                // 大致3*3图分布如图 aa -> ur, bb -> dl, cc -> ul, dd -> dr
//                // ____aa____
//                // __cc__aa__
//                // cc______dd
//                // __bb__dd__
//                // ____bb____
//                int ur = query_diagonal(i - k, j, k); // 右上
//                int dl = query_diagonal(i + 1, j - k + 1, k); // 左下
//                int ul = query_anti_diagonal(i - k + 1, j - 1, k); // 左上
//                int dr = query_anti_diagonal(i, j + k, k); // 右下
//                update(ur + dl + ul + dr);
//            }
//        }
//    }
//    int* ans = (int*)malloc(sizeof(int) * 3);
//    ans[0] = x, ans[1] = y, ans[2] = z;
//    *returnSize = 3 - (y == 0) - (z == 0);
//    return ans;
//}
//
////2206. 将数组划分成相等数对    
//
//bool divideArray(int* nums, int numsSize)
//{
//    int cnt[501] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (cnt[nums[i]] & 1)
//            return false;
//    }
//    return true;
//}
//
////2225. 找出输掉零场或一场比赛的玩家
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes)
//{
//    int max = 0;
//    for (int i = 0; i < matchesSize; i++)
//    {
//        if (matches[i][0] > max)
//            max = matches[i][0];
//        if (matches[i][1] > max)
//            max = matches[i][1];
//    }
//    int wins[max + 1], loses[max + 1];
//    memset(wins, 0, sizeof(wins));
//    memset(loses, 0, sizeof(loses));
//    for (int i = 0; i < matchesSize; i++)
//    {
//        int x = matches[i][0], y = matches[i][1];
//        wins[x]++; loses[y]++;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * 2);
//    *returnSize = 2;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
//    ans[0] = (int*)malloc(sizeof(int) * max);
//    ans[1] = (int*)malloc(sizeof(int) * max);
//    int len1 = 0, len2 = 0;
//    for (int i = 1; i <= max; i++)
//    {
//        if (wins[i] + loses[i])
//        {
//            if (loses[i] == 0)
//                ans[0][len1++] = i;
//            else if (loses[i] == 1)
//                ans[1][len2++] = i;
//        }
//    }
//    (*returnColumnSizes)[0] = len1;
//    (*returnColumnSizes)[1] = len2;
//    return ans;
//}
//
////2231. 按奇偶性交换后的最大数字
//
//void reverse(bool* bits, int left, int right)
//{
//    while (left < right)
//    {
//        bool tmp = bits[left];
//        bits[left++] = bits[right];
//        bits[right--] = tmp;
//    }
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int largestInteger(int num)
//{
//    int odd[10], even[10];
//    bool* bits = (bool*)malloc(sizeof(char) * 10);
//    int len = 0, idx1 = 0, idx2 = 0;
//    while (num)
//    {
//        if (num % 2)
//        {
//            bits[len++] = 1;
//            odd[idx1++] = num % 10;
//        }
//        else
//        {
//            bits[len++] = 0;
//            even[idx2++] = num % 10;
//        }
//        num /= 10;
//    }
//    reverse(bits, 0, len - 1);
//    qsort(odd, idx1, sizeof(int), cmp);
//    qsort(even, idx2, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < len; i++)
//    {
//        ans *= 10;
//        ans += bits[i] ? odd[--idx1] : even[--idx2];
//    }
//    return ans;
//}
//
