////1186. 删除一次得到子数组最大和
//
//int maximumSum(int* arr, int arrSize)
//{
//    int n = arrSize;
//    int res[n][2];
//    for (int i = 0; i < n; i++)
//    {
//        res[i][0] = INT_MIN;
//        res[i][1] = INT_MIN;
//    }
//    int dfs(int i, bool del)
//    {
//        if (i < 0)
//            return INT_MIN / 2;
//
//        if (res[i][del] != INT_MIN)
//            return res[i][del];
//
//        if (del)
//            res[i][del] = fmax(dfs(i - 1, 1) + arr[i], dfs(i - 1, 0));
//        else
//            res[i][del] = arr[i] + fmax(0, dfs(i - 1, 0));
//
//        return res[i][del];
//    }
//    int ans = INT_MIN;
//    for (int i = 0; i < n; i++)
//    {
//        ans = fmax(ans, fmax(dfs(i, 0), dfs(i, 1)));
//    }
//    return ans;
//}
//
//int maximumSum(int* arr, int arrSize)
//{
//    int n = arrSize;
//    int f[n + 1][2];
//    f[0][0] = f[0][1] = INT_MIN / 2;
//    int ans = INT_MIN;
//    for (int i = 0; i < n; i++)
//    {
//        f[i + 1][0] = fmax(f[i][0], 0) + arr[i];
//        f[i + 1][1] = fmax(f[i][1] + arr[i], f[i][0]);
//        ans = fmax(ans, fmax(f[i + 1][0], f[i + 1][1]));
//    }
//    return ans;
//}
//
//int maximumSum(int* arr, int arrSize)
//{
//    int n = arrSize;
//    int f0 = INT_MIN / 2, f1 = INT_MIN / 2;
//    int ans = INT_MIN;
//    for (int i = 0; i < n; i++)
//    {
//        f1 = fmax(f1 + arr[i], f0);
//        f0 = fmax(f0, 0) + arr[i];
//        ans = fmax(ans, fmax(f0, f1));
//    }
//    return ans;
//}
//
////2501. 数组中最长的方波
//
//int longestSquareStreak(int* nums, int numsSize)
//{
//    int hash[100001][2];
//    memset(hash, 0, sizeof(hash));
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i]][0] = 1;
//    }
//    int dfs(int i)
//    {
//        if (hash[i][0] == 0)
//            return 0;
//
//        if (hash[i][1])
//            return hash[i][0];
//
//        hash[i][0] = 1 + (i > 100000 / i ? 0 : dfs(i * i));
//        return hash[i][0];
//    }
//    int ans = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans = fmax(ans, dfs(nums[i]));
//    }
//    return ans > 1 ? ans : -1;
//}
//
////1218. 最长定差子序列
//
//int longestSubsequence(int* arr, int arrSize, int difference)
//{
//    int hash[40009] = { 0 };
//    int ans = 1;
//    for (int i = 0; i < arrSize; i++)
//    {
//        hash[arr[i] + 20004] = 1 + hash[arr[i] + 20004 - difference];
//        ans = fmax(ans, hash[arr[i] + 20004]);
//    }
//    return ans;
//}
//
////3707. 相等子字符串分数
//
//bool scoreBalance(char* s)
//{
//    int suf = 0, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        suf += s[i] - 'a' + 1;
//    }
//    int pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre += s[i] - 'a' + 1;
//        suf -= s[i] - 'a' + 1;
//        if (pre == suf)
//            return true;
//    }
//    return false;
//}
//
//bool scoreBalance(char* s)
//{
//    int suf = 0, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        suf += s[i] & 31;
//    }
//    int pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre += s[i] & 31;
//        if (pre * 2 == suf)
//            return true;
//    }
//    return false;
//}
//
