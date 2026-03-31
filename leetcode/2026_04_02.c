////3880. 两个值之间的最小绝对差值
//
//int minAbsoluteDifference(int* nums, int numsSize)
//{
//    int pre1 = -1, pre2 = -1, ans = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 0)
//            continue;
//
//        if (nums[i] == 1)
//        {
//            if (pre2 != -1)
//                ans = fmin(ans, i - pre2);
//
//            pre1 = i;
//        }
//        else
//        {
//            if (pre1 != -1)
//                ans = fmin(ans, i - pre1);
//
//            pre2 = i;
//        }
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
////3881. 恰好看到 K 个人的方向选择    
//
//const int MOD = 1e9 + 7;
//
//// 快速幂：计算a^b % mod（用于求逆元）
//long long pow_mod(long long a, long long b, long long mod)
//{
//    long long res = 1;
//    while (b)
//    {
//        if (b & 1)
//            res = res * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return res;
//}
//
//// 简化版：计算组合数C(n, k) % MOD
//long long combo(int n, int k)
//{
//    k = fmin(k, n - k); // 取较小值，减少计算量（C(n,k)=C(n,n?k)）
//
//    long long numerator = 1;   // 分子：n*(n-1)*…*(n?k+1)
//    long long denominator = 1; // 分母：k! = 1 * 2*…*k
//
//    for (int i = 0; i < k; i++)
//    {
//        numerator = numerator * (n - i) % MOD;
//        denominator = denominator * (i + 1) % MOD;
//    }
//
//    // 费马小定理求分母的逆元：denominator^(MOD-2) % MOD
//    long long inv_den = pow_mod(denominator, MOD - 2, MOD);
//    return numerator * inv_den % MOD;
//}
//int countVisiblePeople(int n, int pos, int k)
//{
//    return (combo(n - 1, k)) * 2 % MOD;
//}
//
////3360. 移除石头游戏
//
//bool canAliceWin(int n)
//{
//    int nums[9] = { 0, 10, 19, 27, 34, 40, 45, 49, 52 };
//    int left = 0, right = 8;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] > n)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left % 2 == 0;
//}
//
////3411. 最长乘积等价子数组
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//int maxLength(int* nums, int numsSize)
//{
//    int ans = 2, mul = 1, left = 0;
//    for (int right = 0; right < numsSize; right++)
//    {
//        while (gcd(mul, nums[right]) > 1)
//        {
//            mul /= nums[left];
//            left++;
//        }
//
//        mul *= nums[right];
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
