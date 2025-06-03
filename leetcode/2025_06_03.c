////2384. 最大回文数字
//
//char* largestPalindromic(char* num)
//{
//    int cnt[10] = { 0 };
//    for (int i = 0; num[i]; i++)
//    {
//        cnt[num[i] - '0']++;
//    }
//    int n = 0, odd = -1, zero = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (cnt[i] % 2)
//        {
//            cnt[i] = cnt[i] - cnt[i] % 2;
//            odd = fmax(odd, i);
//        }
//        if (i == 0)
//            zero += cnt[i];
//
//        n += cnt[i];
//    }
//    int flag = (odd >= 0);
//    if (n == zero)
//    {
//        n = 1;
//        cnt[0] = 0;
//    }
//    else
//        n += flag;
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[n] = '\0';
//    if (n % 2) ans[n / 2] = odd >= 0 ? odd + '0' : '0';
//    int j = 0;
//    for (int i = 9; i >= 0; i--)
//    {
//        while (cnt[i])
//        {
//            ans[j] = i + '0';
//            ans[n - 1 - j] = i + '0';
//            j++;
//            cnt[i] -= 2;
//        }
//    }
//    return ans;
//}
//
////LCS 01. 下载插件
//
//int leastMinutes(int n)
//{
//    if (n < 4)
//        return n;
//
//    int num = 4, digit = 3;
//    while (n > num)
//    {
//        digit++;
//        num <<= 1;
//    }
//    return digit;
//}
//
////3091. 执行操作使数据元素之和大于等于 K
//
//int minOperations(int k)
//{
//    if (k == 1)
//        return 0;
//    int t = sqrt(k);
//    //printf("%d\n", t);
//    return k / t + t - 1 - (k % t == 0);
//}
//
////397. 整数替换
//
//int integerReplacement(int n)
//{
//    int ans = 0;
//    long long num = n;
//    while (num > 1)
//    {
//        if ((num & 3) == 3)
//        {
//            if (num == 3)
//                return ans + 2;
//            num++;
//            ans++;
//        }
//        else
//        {
//            ans += 1 + num % 2;
//            num >>= 1;
//        }
//    }
//    return ans;
//}
//
