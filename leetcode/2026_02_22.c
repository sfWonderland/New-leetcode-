////3847. 计算比赛分数差
//
//int scoreDifference(int* nums, int numsSize)
//{
//    int sum[2] = { 0 }, turn = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & 1)
//            turn ^= 1;
//        if ((i + 1) % 6 == 0)
//            turn ^= 1;
//        sum[turn] += nums[i];
//    }
//    return sum[0] - sum[1];
//}
//
////3848. 阶数数字排列    
//
//const int digitorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
//bool isDigitorialPermutation(int n)
//{
//    int cnt[10] = { 0 };
//    int digits = 0;
//    while (n)
//    {
//        cnt[n % 10]++;
//        n /= 10;
//        digits++;
//    }
//    int sum = 0;
//    for (int i = 0; i < 9; i++)
//    {
//        sum += digitorial[i] * cnt[i];
//    }
//    //printf("%d %d\n", sum, digits);
//    if (sum < pow(10, digits - 1))
//        return false;
//    while (sum)
//    {
//        cnt[sum % 10]--;
//        sum /= 10;
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        if (cnt[i])
//            return false;
//    }
//    return true;
//}
//
////3849. 重新排列后的最大按位异或值
//
//char* maximumXor(char* s, char* t)
//{
//    int cnt[2] = { 0 }, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        cnt[t[i] - '0']++;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int opt = '1' - s[i];
//        if (cnt[opt])
//        {
//            t[i] = '1';
//            cnt[opt]--;
//        }
//        else
//            t[i] = '0';
//    }
//    return t;
//}
//
////3850. 统计结果等于 K 的序列数目
//
//int countSequences(int* nums, int numsSize, long long k)
//{
//    int n = numsSize;
//    int t2 = 0, t3 = 0, t5 = 0;
//    long long temp = k;
//    while (temp % 2 == 0) {
//        t2++;
//        temp /= 2;
//    }
//    while (temp % 3 == 0) {
//        t3++;
//        temp /= 3;
//    }
//    while (temp % 5 == 0) {
//        t5++;
//        temp /= 5;
//    }
//    if (temp != 1) {
//        return 0;
//    }
//    if (t2 > 38 || t3 > 38 || t5 > 38)
//        return 0;
//
//
//    int fac[n][3];
//    for (int i = 0; i < n; i++) {
//        int x = nums[i];
//        if (x == 1) { fac[i][0] = 0; fac[i][1] = 0; fac[i][2] = 0; }
//        else if (x == 2) { fac[i][0] = 1;  fac[i][1] = 0;  fac[i][2] = 0; }
//        else if (x == 3) { fac[i][0] = 0;  fac[i][1] = 1;  fac[i][2] = 0; }
//        else if (x == 4) { fac[i][0] = 2;  fac[i][1] = 0;  fac[i][2] = 0; }
//        else if (x == 5) { fac[i][0] = 0;  fac[i][1] = 0;  fac[i][2] = 1; }
//        else if (x == 6) { fac[i][0] = 1;  fac[i][1] = 1;  fac[i][2] = 0; }
//    }
//
//    int dp[2 * n + 5][2 * n + 5][2 * n + 5];
//    memset(dp, 0, sizeof(dp));
//    int base = n + 2;
//    dp[base][base][base] = 1;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        int fa = fac[i][0];
//        int fb = fac[i][1];
//        int fc = fac[i][2];
//        int next_dp[2 * n + 5][2 * n + 5][2 * n + 5];
//        memset(next_dp, 0, sizeof(next_dp));
//
//        for (int a = base - n - 2; a < base + n + 2; a++)
//        {
//            for (int b = base - n - 2; b < base + n + 2; b++)
//            {
//                for (int c = base - n - 2; c < base + n + 2; c++)
//                {
//                    if (dp[a][b][c] == 0) continue;
//                    int ra = a - base;
//                    int rb = b - base;
//                    int rc = c - base;
//
//                    int na1 = ra + fa;
//                    int nb1 = rb + fb;
//                    int nc1 = rc + fc;
//                    if (na1 >= -base && na1 <= base
//                        && nb1 >= -base && nb1 <= base
//                        && nc1 >= -base && nc1 <= base)
//                    {
//                        int ta1 = na1 + base;
//                        int tb1 = nb1 + base;
//                        int tc1 = nc1 + base;
//                        next_dp[ta1][tb1][tc1] += dp[a][b][c];
//                    }
//
//                    int na2 = ra - fa;
//                    int nb2 = rb - fb;
//                    int nc2 = rc - fc;
//                    if (na2 >= -base && na2 <= base
//                        && nb2 >= -base && nb2 <= base
//                        && nc2 >= -base && nc2 <= base)
//                    {
//                        int ta2 = na2 + base;
//                        int tb2 = nb2 + base;
//                        int tc2 = nc2 + base;
//                        next_dp[ta2][tb2][tc2] += dp[a][b][c];
//                    }
//
//                    next_dp[a][b][c] += dp[a][b][c];
//                }
//            }
//        }
//        memcpy(dp, next_dp, sizeof(dp));
//    }
//
//    int a_idx = t2 + base;
//    int b_idx = t3 + base;
//    int c_idx = t5 + base;
//    if (a_idx < 0 || a_idx > 2 * base
//        || b_idx < 0 || b_idx > 2 * base
//        || c_idx < 0 || c_idx > 2 * base)
//        return 0;
//    return dp[a_idx][b_idx][c_idx];
//}
//
