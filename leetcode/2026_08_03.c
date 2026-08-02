//// 1406. й╞вссно╥ III
//
//char* stoneGameIII(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int memo[n];
//    memset(memo, 0x3f, sizeof(memo));
//    int dfs(int i)
//    {
//        if (i == n)
//            return 0;
//
//        if (memo[i] != 0x3f3f3f3f)
//            return memo[i];
//
//        int sum = 0, res = INT_MIN;
//        for (int j = i; j < fmin(i + 3, n); j++)
//        {
//            sum += stoneValue[j];
//            res = fmax(res, sum - dfs(j + 1));
//        }
//        memo[i] = res;
//        return res;
//    }
//    int diff = dfs(0);
//    if (diff == 0) return "Tie";
//
//    return diff > 0 ? "Alice" : "Bob";
//}
//
//char* stoneGameIII(int* stoneValue, int stoneValueSize)
//{
//    int n = stoneValueSize;
//    int memo[n];
//    memset(memo, 0x3f, sizeof(memo));
//    int f[n + 1];
//    f[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        int sum = 0, res = INT_MIN;
//        for (int j = i; j < fmin(i + 3, n); j++)
//        {
//            sum += stoneValue[j];
//            res = fmax(res, sum - f[j + 1]);
//        }
//        f[i] = res;
//    }
//    if (f[0] == 0) return "Tie";
//
//    return f[0] > 0 ? "Alice" : "Bob";
//}
//
