////1155. 掷骰子等于目标和的方法数
//
//#define MOD 1000000007
//int dfs(int i, int k, int target, int** cache)
//{
//    if (i < 0)
//        return target == 0;
//    if (cache[i + 1][target] != -1)
//        return cache[i][target];
//
//    int sum = 0;
//    for (int j = 1; j <= fmin(k, target); j++)
//    {
//        if (cache[i][target - j] == -1)
//            cache[i][target - j] = dfs(i - 1, k, target - j, cache);
//        sum = (sum + cache[i][target - j]) % MOD;
//    }
//    cache[i + 1][target] = sum;
//    return cache[i + 1][target];
//}
//int numRollsToTarget(int n, int k, int target)
//{
//    int** cache = (int**)malloc(sizeof(int*) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (target + 1));
//        for (int j = 0; j <= target; j++)
//            cache[i][j] = -1;
//    }
//    return dfs(n - 1, k, target, cache);
//}
//
//#define MOD 1000000007
//int numRollsToTarget(int n, int k, int target)
//{
//    if (target < n || n * k < target)
//        return 0;
//
//    int f[n + 1][target - n + 1];
//    memset(f, 0, sizeof(f));
//    f[0][0] = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= target - n; j++)
//        {
//            for (int m = 0; m <= fmin(k - 1, j); m++)
//            {
//                f[i][j] = (f[i][j] + f[i - 1][j - m]) % MOD;
//            }
//        }
//    }
//    return f[n][target - n];
//}
//
//#define MOD 1000000007
//int numRollsToTarget(int n, int k, int target)
//{
//    if (target < n || n * k < target)
//        return 0;
//
//    long long f[target - n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        int max_j = fmin(target - n, i * (k - 1));
//        for (int j = 1; j <= max_j; j++)
//        {
//            f[j] += f[j - 1];
//        }
//        for (int j = max_j; j >= k; j--)
//        {
//            f[j] = (f[j] - f[j - k]) % MOD;
//        }
//    }
//    return f[target - n];
//}
//
////3290. 最高乘法得分
//
//int* nums1, * nums2;
//long long dfs(int i, int j)
//{
//    if (i < 0)
//        return 0;
//    if (j < i)
//        return LLONG_MIN;
//
//    return fmax(dfs(i - 1, j - 1) + nums1[i] * nums2[j], dfs(i, j - 1));
//}
//long long maxScore(int* a, int aSize, int* b, int bSize)
//{
//    nums1 = a, nums2 = b;
//    return dfs(aSize - 1, bSize - 1);
//}
//
//long long maxScore(int* a, int aSize, int* b, int bSize)
//{
//    long long f[aSize + 1][bSize + 1];
//    for (int i = 0; i <= bSize; i++)
//    {
//        f[0][i] = 0;
//    }
//    for (int i = 1; i <= aSize; i++)
//    {
//        f[i][0] = LLONG_MIN / 2;
//    }
//    for (int i = 0; i < aSize; i++)
//    {
//        for (int j = 0; j < bSize; j++)
//        {
//            f[i + 1][j + 1] = fmax(f[i][j] + 1ll * a[i] * b[j], f[i + 1][j]);
//        }
//    }
//    return f[aSize][bSize];
//}
//
//long long maxScore(int* a, int aSize, int* b, int bSize)
//{
//    long long f[aSize + 1];
//    f[0] = 0;
//    for (int i = 1; i <= aSize; i++)
//    {
//        f[i] = LLONG_MIN / 2;
//    }
//    for (int i = 0; i < bSize; i++)
//    {
//        for (int j = aSize - 1; j >= 0; j--)
//        {
//            f[j + 1] = fmax(f[j] + 1ll * a[j] * b[i], f[j + 1]);
//        }
//    }
//    return f[aSize];
//}
//
////300. 最长递增子序列
//
//int binary_search(int* nums, int target, int left, int right)
//{
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] < target)
//            left = mid + 1;
//        else
//            right = mid;
//    }
//    return left;
//}
//int lengthOfLIS(int* nums, int numsSize)
//{
//    int ng = 0, j = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        j = binary_search(nums, nums[i], 0, ng);
//        nums[j] = nums[i];
//        if (j == ng)
//            ng++;
//    }
//    return ng;
//}
//
////2826. 将三个组排序
//
//int bianry_search(int* g, int x, int left, int right)
//{
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (g[mid] > x)
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int minimumOperations(int* nums, int numsSize)
//{
//    int* g = (int*)malloc(sizeof(int) * numsSize);
//    int j = 0, ng = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        j = bianry_search(g, nums[i], 0, ng);
//        if (j == ng)
//            g[ng++] = nums[i];
//        else
//            g[j] = nums[i];
//    }
//    return numsSize - ng;
//}
//
