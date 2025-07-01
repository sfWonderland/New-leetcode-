////3307. 找出第 K 个字符 II
//
//char kthCharacter(long long k, int* operations, int operationsSize)
//{
//    k = k - 1;
//    int sum = 0, i = 0;
//    while (k)
//    {
//        if (k & 1)
//            sum += operations[i];
//        i++;
//        k >>= 1;
//    }
//    return sum % 26 + 'a';
//}
//
////1414. 和为 K 的最少斐波那契数字数目
//
//int findMinFibonacciNumbers(int k)
//{
//    int dp[48] = { 0 };
//    dp[1] = 1;
//    int ans = 0;
//    while (k)
//    {
//        int i = 2;
//        for (; dp[i - 1] <= k; i++)
//        {
//            if (0 == dp[i])
//                dp[i] = dp[i - 1] + dp[i - 2];
//        }
//        k -= dp[i - 2];
//        ans++;
//    }
//    return ans;
//}
//
////3468. 可行数组的数目
//
//int countArrays(int* original, int originalSize, int** bounds, int boundsSize, int* boundsColSize)
//{
//    int left = INT_MIN, right = INT_MAX;
//    for (int i = 0; i < originalSize; i++)
//    {
//        left = fmax(left, bounds[i][0] - original[i]);
//        right = fmin(right, bounds[i][1] - original[i]);
//    }
//    int ans = right - left + 1;
//    return ans > 0 ? ans : 0;
//}
//
////2310. 个位数字为 K 的整数之和
//
//int minimumNumbers(int num, int k)
//{
//    if (0 == num)
//        return 0;
//    for (int i = 1; i <= 10 && num - k * i >= 0; i++)
//    {
//        if (0 == (num - k * i) % 10)
//            return i;
//    }
//    return -1;
//}
//
