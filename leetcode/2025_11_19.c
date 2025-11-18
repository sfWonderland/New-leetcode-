////2033. 获取单值网格的最小操作数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minOperations(int** grid, int gridSize, int* gridColSize, int x)
//{
//    int m = gridSize, n = gridColSize[0];
//    int len = m * n;
//    int* nums = (int*)malloc(sizeof(int) * len);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if ((grid[i][j] - grid[0][0]) % x)
//                return -1;
//            nums[i * n + j] = grid[i][j];
//        }
//    }
//    qsort(nums, len, sizeof(int), cmp);
//    int mid = nums[(len - 1) / 2];
//    int ans = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int t = abs(mid - nums[i]);
//        ans += t / x;
//    }
//    return ans;
//}
//
////3107. 使数组中位数等于 K 的最少操作数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long minOperationsToMakeMedianK(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int m = numsSize / 2;
//    long long ans = 0;
//    if (nums[m] > k)
//    {
//        for (int i = m; i >= 0 && nums[i] > k; i--)
//        {
//            ans += nums[i] - k;
//        }
//    }
//    else
//    {
//        for (int i = m; i < numsSize && nums[i] < k; i++)
//        {
//            ans += k - nums[i];
//        }
//    }
//    return ans;
//}
//
////2611. 老鼠和奶酪
//
//int* diff;
//int cmp(const void* e1, const void* e2)
//{
//    return diff[*(int*)e2] - diff[*(int*)e1];
//}
//int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k)
//{
//    int n = reward1Size;
//    diff = (int*)malloc(sizeof(int) * n);
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        diff[i] = reward1[i] - reward2[i];
//        idx[i] = i;
//    }
//    qsort(idx, n, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i < k)
//            ans += reward1[idx[i]];
//        else
//            ans += reward2[idx[i]];
//    }
//    return ans;
//}
//
////1029. 两地调度
//
//int* diff;
//int cmp(const void* e1, const void* e2)
//{
//    return diff[*(int*)e1] - diff[*(int*)e2];
//}
//int twoCitySchedCost(int** costs, int costsSize, int* costsColSize)
//{
//    int n = costsSize;
//    diff = (int*)malloc(sizeof(int) * n);
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        diff[i] = costs[i][0] - costs[i][1];
//        idx[i] = i;
//    }
//    qsort(idx, n, sizeof(int), cmp);
//    int m = n / 2, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i < m)
//            ans += costs[idx[i]][0];
//        else
//            ans += costs[idx[i]][1];
//    }
//    return ans;
//}
//
