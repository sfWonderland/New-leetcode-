//// 4039. 解码值之和
//
//#define MOD 1000000007
//int qpow(long long x, int y)
//{
//    int res = 1;
//    while (y)
//    {
//        if (y & 1)
//            res = (res * x) % MOD;
//        x = x * x % MOD;
//        y >>= 1;
//    }
//    return res;
//}
//int sumDecoded(long long* nums, int numsSize)
//{
//    int n = numsSize;
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int Xsize = pow(10, nums[i] % 10);
//        long long x = nums[i] / 10;
//        long long base = 10;
//        while (x >= Xsize)
//        {
//            x /= 10;
//            base *= 10;
//        }
//        int y = (nums[i] - x * base) / 10;
//        // printf("%d %d ", x, y);
//        ans = (ans + qpow(x, y)) % MOD;
//        // printf("%lld\n", qpow(x, y));
//    }
//    return ans;
//}
//
