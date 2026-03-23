////2849. 判断能否在给定时间到达单元格
//
//bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
//{
//    int tmin = fmax(abs(fx - sx), abs(fy - sy));
//    return tmin == 0 ? t != 1 : t >= tmin;
//}
//
////2865. 美丽塔 I
//
//long long maximumSumOfHeights(int* heights, int heightsSize)
//{
//    int arr[heightsSize];
//    long long ans = 0;
//    for (int i = 0; i < heightsSize; i++)
//    {
//        memcpy(arr, heights, sizeof(arr));
//        long long sum = arr[i];
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if (arr[j] > arr[j + 1])
//                arr[j] = arr[j + 1];
//
//            sum += arr[j];
//        }
//        for (int j = i + 1; j < heightsSize; j++)
//        {
//            if (arr[j] > arr[j - 1])
//                arr[j] = arr[j - 1];
//
//            sum += arr[j];
//        }
//        if (ans < sum) ans = sum;
//    }
//    return ans;
//}
//
//long long maximumSumOfHeights(int* heights, int heightsSize)
//{
//    int n = heightsSize;
//    long long suf[n + 1];
//    suf[n] = 0;
//    int st[n + 1];
//    int pos = 0;
//    st[pos++] = n;
//    long long sum = 0;
//    for (int i = n - 1; i > 0; i--)
//    {
//        int x = heights[i];
//        while (pos > 1 && x < heights[st[pos - 1]])
//        {
//            pos--;
//            sum -= 1ll * (st[pos - 1] - st[pos]) * heights[st[pos]];
//        }
//        sum += 1ll * x * (st[pos - 1] - i);
//        suf[i] = sum;
//        st[pos++] = i;
//    }
//    long long ans = 0, pre = 0;
//    pos = 0;
//    st[pos++] = -1;
//    for (int i = 0; i < n; i++)
//    {
//        int x = heights[i];
//        while (pos > 1 && x < heights[st[pos - 1]])
//        {
//            pos--;
//            pre -= 1ll * (st[pos] - st[pos - 1]) * heights[st[pos]];
//        }
//        pre += 1ll * x * (i - st[pos - 1]);
//        ans = fmax(ans, pre + suf[i + 1]);
//        st[pos++] = i;
//    }
//    return ans;
//}
//
////2869. 收集元素的最少操作次数
//
//int minOperations(int* nums, int numsSize, int k)
//{
//    bool exist[k + 1];
//    memset(exist, 0, sizeof(exist));
//    int cnt = 0;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (nums[i] > k)
//            continue;
//        if (exist[nums[i]] == false)
//            cnt++;
//        if (cnt == k)
//            return numsSize - i;
//        exist[nums[i]] = true;
//    }
//    return -1;
//}
//
////2906. 构造乘积矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int MOD = 12345;
//int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    int** suf = (int**)malloc(sizeof(int*) * m);
//    for (int i = m - 1; i >= 0; i--)
//    {
//        suf[i] = (int*)malloc(sizeof(int) * n);
//
//        if (i == m - 1)
//            suf[i][n - 1] = 1;
//        else
//            suf[i][n - 1] = grid[i + 1][0] % MOD * suf[i + 1][0] % MOD;
//
//        for (int j = n - 2; j >= 0; j--)
//        {
//            suf[i][j] = grid[i][j + 1] % MOD * suf[i][j + 1] % MOD;
//        }
//    }
//
//    long long pre = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            suf[i][j] = pre * suf[i][j] % MOD;
//            pre = grid[i][j] * pre % MOD;
//        }
//    }
//    *returnSize = gridSize;
//    *returnColumnSizes = gridColSize;
//    return suf;
//}
//
