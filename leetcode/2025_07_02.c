////357. 统计各位数字都不同的数字个数
//
//int countNumbersWithUniqueDigits(int n)
//{
//    int ans = 1, factor = 9, t = 9;
//    while (n)
//    {
//        ans += t;
//        t *= factor;
//        factor--;
//        n--;
//    }
//    return ans;
//}
//
////3179. K 秒后第 N 个元素的值
//
//#define mod 1000000007
//
////快速幂
//long long q_pow(long long base, int exp)
//{
//    long long res = 1;
//    for (; exp > 0; exp >>= 1)
//    {
//        if (exp & 1)
//            res = res * base % mod;
//
//        base = base * base % mod;
//    }
//    return res;
//}
////组合数计算
//long long comb(int n, int k)
//{
//    //求阶乘
//    long long fac[n + 1], inv_fac[n + 1];
//    fac[0] = 1;
//    for (int i = 1; i < n + 1; i++)
//    {
//        fac[i] = fac[i - 1] * i % mod;
//    }
//    //求1/n! % mod 逆元，a / b % mod = a * b ^ (mod - 2) % mod
//    inv_fac[n] = q_pow(fac[n], mod - 2);
//    //1/i! % mod 逆元， 1 / (n - 1) ! % mod = 1 / n! * n % mod
//    for (int i = n; i > 0; i--)
//    {
//        inv_fac[i - 1] = inv_fac[i] * i % mod;
//    }
//    // 结果为 n! / (n - k)! / k!
//    return fac[n] * inv_fac[n - k] % mod * inv_fac[k] % mod;
//}
//int valueAfterKSeconds(int n, int k)
//{
//    return comb(n + k - 1, k);
//}
//
////1641. 统计字典序元音字符串的数目
//
//int countVowelStrings(int n)
//{
//    return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
//}
//
////2063. 所有子字符串中的元音
//
//long long countVowels(char* word)
//{
//    int n = strlen(word);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if ('a' == word[i] || 'e' == word[i] || 'i' == word[i] || 'o' == word[i] || 'u' == word[i])
//            ans += (long long)(n - i) * (i + 1);
//    }
//    return ans;
//}
//
