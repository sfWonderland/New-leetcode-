//// 3936. 将 0 移到末尾的最少交换次数
//
//int minimumSwaps(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int right = n - 1, cnt = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cnt += (nums[i] == 0);
//    }
//    int k = cnt;
//    for (int i = n - 1; i >= n - k; i--)
//    {
//        cnt -= (nums[i] == 0);
//    }
//    return cnt;
//}
//
//// 3937. 使数组变为模交替数组的最少操作次数 I    
//
//int operation(int* nums, int n, bool odd, int j, int k)
//{
//    int sum = 0;
//    for (int i = odd; i < n; i += 2)
//    {
//        //sum += fmin(abs(j + k - nums[i]), abs(j - nums[i]));
//        if (nums[i] >= j)
//        {
//            sum += fmin(nums[i] - j, k + j - nums[i]);
//        }
//        else
//        {
//            sum += fmin(j - nums[i], k - j + nums[i]);
//        }
//    }
//    return sum;
//}
//int minOperations(int* nums, int numsSize, int k)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] %= k;
//    }
//    int ans = INT_MAX;
//    for (int i = 0; i < k; i++)
//    {
//        int sum1 = operation(nums, numsSize, 0, i, k);
//        int sum2 = INT_MAX;
//        for (int j = 0; j < k; j++)
//        {
//            if (j == i)
//                continue;
//            sum2 = fmin(sum2, operation(nums, numsSize, 1, j, k));
//        }
//        ans = fmin(ans, sum1 + sum2);
//    }
//    return ans;
//}
//
//int operation(int* nums, int n, bool odd, int j, int k)
//{
//    int sum = 0;
//    for (int i = odd; i < n; i += 2)
//    {
//        //sum += fmin(abs(j + k - nums[i]), abs(j - nums[i]));
//        if (nums[i] >= j)
//        {
//            sum += fmin(nums[i] - j, k + j - nums[i]);
//        }
//        else
//        {
//            sum += fmin(j - nums[i], k - j + nums[i]);
//        }
//    }
//    return sum;
//}
//int minOperations(int* nums, int numsSize, int k)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] %= k;
//    }
//    int odd[k], even[k];
//    for (int i = 0; i < k; i++)
//    {
//        odd[i] = operation(nums, numsSize, 0, i, k);
//    }
//    for (int i = 0; i < k; i++)
//    {
//        even[i] = operation(nums, numsSize, 1, i, k);
//    }
//    int even2[k];
//    for (int i = 0; i < k; i++)
//    {
//        even2[i] = INT_MAX;
//        for (int j = 0; j < k; j++)
//        {
//            if (i == j)
//                continue;
//            even2[i] = fmin(even2[i], even[j]);
//        }
//    }
//    int ans = INT_MAX;
//    for (int i = 0; i < k; i++)
//    {
//        ans = fmin(ans, odd[i] + even2[i]);
//    }
//    return ans;
//}
//
//// 2698. 求一个整数的惩罚数
//
//bool dfs(int x, int sum, int mod, int i)
//{
//    if (x % mod == x)
//        return sum + x == i;
//
//    return dfs(x, sum, mod * 10, i) | dfs(x /= mod, sum + x % mod, 10, i);
//}
//int punishmentNumber(int n)
//{
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        int x = i * i;
//        if (dfs(x, 0, 10, i))
//            ans += i * i;
//    }
//    return ans;
//}
//
//// 1043. 分隔数组以得到最大和
//
//int maxSumAfterPartitioning(int* arr, int arrSize, int k)
//{
//    int n = arrSize;
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = i, mx = 0; j > i - k && j >= 0; j--)
//        {
//            mx = fmax(mx, arr[j]);
//            f[i + 1] = fmax(f[i + 1], f[j] + (i - j + 1) * mx);
//        }
//    }
//    return f[n];
//}
//
//int maxSumAfterPartitioning(int* arr, int arrSize, int k)
//{
//    int n = arrSize;
//    int f[k];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < n; i++)
//    {
//        int res = 0;
//        for (int j = i, mx = 0; j > i - k && j >= 0; j--)
//        {
//            mx = fmax(mx, arr[j]);
//            res = fmax(res, f[j % k] + (i - j + 1) * mx);
//        }
//        f[(i + 1) % k] = res;
//    }
//    return f[n % k];
//}
//
