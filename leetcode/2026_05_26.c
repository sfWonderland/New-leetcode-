//// 372. ³¬¼¶´Î·½
//
//#define MOD 1337
//int qpow(int x, int n)
//{
//    int res = 1;
//    while (n)
//    {
//        if (n & 1)
//            res = 1ll * res * x % MOD;
//        x = 1ll * x * x % MOD;
//        n >>= 1;
//    }
//    return res;
//}
//int superPow(int a, int* b, int bSize)
//{
//    int ans = 1;
//    for (int i = bSize - 1; i >= 0; i--)
//    {
//        ans = 1ll * ans * qpow(a, b[i]) % MOD;
//        a = qpow(a, 10);
//    }
//    return ans;
//}
//
