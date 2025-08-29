////LCR 185. 统计结果概率
//
//double* statisticsProbability(int num, int* returnSize)
//{
//    //逆向考虑不用考虑边界问题
//    int n = num * 5 + 1;
//    int dpSize = 6;
//    double* dp = (double*)malloc(sizeof(double) * dpSize);
//    for (int i = 0; i < 6; i++)
//    {
//        dp[i] = 1.0 / 6.0;
//    }
//    for (int i = 2; i <= num; i++)
//    {
//        double* tmp = (double*)calloc(5 * i + 1, sizeof(double));
//        for (int j = 0; j < dpSize; j++)
//        {
//            for (int k = 0; k < 6; k++)
//            {
//                tmp[j + k] += dp[j] / 6.0;
//            }
//        }
//        dp = tmp;
//        dpSize = 5 * i + 1;
//    }
//    *returnSize = 5 * num + 1;
//    return dp;
//}
//
////3021. Alice 和 Bob 玩鲜花游戏
//
//long long flowerGame(int n, int m)
//{
//    //1.分类讨论
//    // if((m + n) & 1)
//    // return 1ll * (n / 2) * (m / 2) + 1ll * ((n + 1) / 2 ) * ((m + 1) / 2);
//    // else
//    // return 1ll * (n / 2) * ((m + 1) / 2) + 1ll * ((n + 1) / 2 ) * (m / 2);
//    //2.国际象棋棋盘，m, n为棋盘行列，取对应颜色格子数最少的，或者黑白两色数目或相等或差为1
//    return 1ll * m * n / 2;
//}
//
////LCR 131. 砍竹子 I
//
//int cuttingBamboo(int bamboo_len)
//{
//    //推论一： 将竹子 以相等的长度等分为多段 ，得到的乘积最大。
//    //推论二： 尽可能将竹子以长度 3 等分为多段时，乘积最大。
//    if (bamboo_len < 4)
//        return bamboo_len - 1;
//    int n = bamboo_len / 3;
//    if (bamboo_len == n * 3)
//        return pow(3, n);
//    else if (bamboo_len % 3 == 1)
//        return pow(3, n - 1) * 4;
//    else
//        return pow(3, n) * 2;
//}
//
////LCR 132. 砍竹子 II
//
//#define MOD 1000000007
//long long quickPow(long long x, long long n)
//{
//    long long ret = 1;
//    while (n)
//    {
//        if (n & 1)
//            ret = ret * x % MOD;
//        x = x * x % MOD;
//        n >>= 1;
//    }
//    return ret;
//}
//int cuttingBamboo(int bamboo_len)
//{
//    if (bamboo_len < 4)
//        return bamboo_len - 1;
//    int n = bamboo_len / 3;
//    if (bamboo_len == n * 3)
//        return quickPow(3, n);
//    else if (bamboo_len % 3 == 1)
//        return quickPow(3, n - 1) * 4 % MOD;
//    else
//        return quickPow(3, n) * 2 % MOD;
//}
//
