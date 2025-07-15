////740. 删除并获得点数
//
//int rob(int n, int* cnt)
//{
//    int f[3] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        f[0] = fmax(f[1], f[2] + cnt[i]);
//        f[2] = f[1];
//        f[1] = f[0];
//    }
//    return f[0];
//}
//int deleteAndEarn(int* nums, int numsSize)
//{
//    int mx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        mx = fmax(mx, nums[i]);
//    }
//
//    int* cnt = (int*)calloc(sizeof(int), mx + 1);
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]] += nums[i];
//    }
//    return rob(mx + 1, cnt);
//}
//
////3201. 找出有效子序列的最大长度 I
//
//int maximumLength(int* nums, int numsSize)
//{
//    int res = 0;
//    int pattern[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
//    for (int i = 0; i < 4; i++)
//    {
//        int cnt = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (nums[j] % 2 == pattern[i][cnt % 2])
//                cnt++;
//        }
//        res = fmax(res, cnt);
//    }
//    return res;
//}
//
////2266. 统计打字方案数
//
//#define mod 1000000007;
//int countTexts(char* pressedKeys)
//{
//    int n = strlen(pressedKeys);
//    long long dp3[100001] = { 1, 1, 2, 4 };
//    long long dp4[100001] = { 1, 1, 2, 4 };
//    for (int i = 4; i <= n; i++) {
//        dp3[i] = (dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % mod;
//        dp4[i] = (dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % mod;
//    }
//    long long ans = 1;
//    int cnt = 1;
//    for (int i = 1; i < n; i++) {
//        if (pressedKeys[i] == pressedKeys[i - 1]) {
//            cnt++;
//        }
//        else {
//            if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
//                ans = (ans * dp4[cnt]) % mod;
//            }
//            else {
//                ans = (ans * dp3[cnt]) % mod;
//            }
//            cnt = 1;
//        }
//    }
//    if (pressedKeys[n - 1] == '7' || pressedKeys[n - 1] == '9') {
//        ans = (ans * dp4[cnt]) % mod;
//    }
//    else {
//        ans = (ans * dp3[cnt]) % mod;
//    }
//    return ans;
//}
//
////2485. 找出中枢整数
//
//int pivotInteger(int n)
//{
//    int sum = (n + 1) * n / 2;
//    int t = sqrt(sum);
//    return t * t == sum ? t : -1;
//}
//
