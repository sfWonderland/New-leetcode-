////LCR 185. ͳ�ƽ������
//
//double* statisticsProbability(int num, int* returnSize)
//{
//    //�����ǲ��ÿ��Ǳ߽�����
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
////3021. Alice �� Bob ���ʻ���Ϸ
//
//long long flowerGame(int n, int m)
//{
//    //1.��������
//    // if((m + n) & 1)
//    // return 1ll * (n / 2) * (m / 2) + 1ll * ((n + 1) / 2 ) * ((m + 1) / 2);
//    // else
//    // return 1ll * (n / 2) * ((m + 1) / 2) + 1ll * ((n + 1) / 2 ) * (m / 2);
//    //2.�����������̣�m, nΪ�������У�ȡ��Ӧ��ɫ���������ٵģ����ߺڰ���ɫ��Ŀ����Ȼ��Ϊ1
//    return 1ll * m * n / 2;
//}
//
////LCR 131. ������ I
//
//int cuttingBamboo(int bamboo_len)
//{
//    //����һ�� ������ ����ȵĳ��ȵȷ�Ϊ��� ���õ��ĳ˻����
//    //���۶��� �����ܽ������Գ��� 3 �ȷ�Ϊ���ʱ���˻����
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
////LCR 132. ������ II
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
