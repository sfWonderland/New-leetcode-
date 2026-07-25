//// 4000. 给定数位和的最大整数
//
//int largestInteger(int n, int s)
//{
//    if (n * 9 < s)
//        return -1;
//    if (s == 0)
//        return 0;
//    int ans = 0;
//    while (n)
//    {
//        ans *= 10;
//        if (s >= 9)
//        {
//            ans += 9;
//            s -= 9;
//        }
//        else
//        {
//            ans += s;
//            s = 0;
//        }
//        n--;
//    }
//    return ans;
//}
//
//// 4001. 聚合两个时间序列    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** aggregateTimeSeries(int** series1, int series1Size, int* series1ColSize, int** series2, int series2Size, int* series2ColSize, int* returnSize, int** returnColumnSizes)
//{
//    int m = series1Size, n = series2Size;
//    int** ans = (int**)malloc(sizeof(int*) * (m + n));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (m + n));
//    int ansSize = 0;
//    for (int i = 0, j = 0; i < m || j < n;)
//    {
//        int a = i < m ? series1[i][0] : INT_MAX;
//        int b = j < n ? series2[j][0] : INT_MAX;
//        int val1 = i < m ? series1[i][1] : 0;
//        int val2 = j < n ? series2[j][1] : 0;
//        ans[ansSize] = (int*)malloc(sizeof(int) * 2);
//        if (a <= b)
//        {
//            ans[ansSize][0] = a;
//            i++;
//        }
//        if (a >= b)
//        {
//            ans[ansSize][0] = b;
//            j++;
//        }
//        ans[ansSize][1] = val1 + val2;
//        (*returnColumnSizes)[ansSize++] = 2;
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
//// 4002. 统计有效序列数目
//
//const int MOD = 1e9 + 7;
//long long qpow(long long x, long long p)
//{
//    long long res = 1;
//    x %= MOD;
//    while (p)
//    {
//        if (p & 1) res = (res * x) % MOD;
//        x = (x * x) % MOD;
//        p >>= 1;
//    }
//    return res;
//}
//long long modInverse(long long n)
//{
//    return qpow(n, MOD - 2);
//}
//int combo(int n, int k)
//{
//    if (k < 0 || k > n)
//        return 0;
//    if (k == 0 || k == n)
//        return 1;
//    if (k > n - k)
//        k = n - k;
//
//    long long num = 1, den = 1;
//    for (int i = 0; i < k; i++)
//    {
//        den = (den * (i + 1)) % MOD;
//        num = (num * (n - i)) % MOD;
//    }
//    return num * modInverse(den) % MOD;
//}
//// 组合数学（隔板法）问题，可以通过正难则反（容斥原理）解决
//int countValidSequences(int n, int k)
//{
//    if (n < k) return 0;
//    long long total = combo(n - 1, k - 1);
//    long long odd = 0;
//    // sum(2 * xi + 1) = n (i E [1, k])
//    // 2 * sum(xi) + k = n
//    // sum(xi) = (n - k) / 2  
//    if ((n - k) % 2 == 0)
//    {
//        int m = (n - k) / 2;
//        odd = combo(m + k - 1, k - 1);
//    }
//    long long ans = (total - odd + MOD) % MOD;
//    return (int)ans;
//}
//
