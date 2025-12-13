////100933. 最大和最小 K 个元素的绝对差
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int absDifference(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < k; i++)
//    {
//        ans += nums[numsSize - 1 - i] - nums[i];
//    }
//    return ans;
//}
//
////3775. 反转元音数相同的单词
//
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//int vowel(char* s, int l, int* r)
//{
//    int i = l, cnt = 0;
//    for (; s[i] && s[i] != ' '; i++)
//    {
//        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
//            cnt++;
//    }
//    *r = i;
//    return cnt;
//}
//char* reverseWords(char* s)
//{
//    int r = 0, n = strlen(s);
//    int cnt = vowel(s, 0, &r);
//    for (int i = r + 1; i < n; i = r + 1)
//    {
//        if (cnt == vowel(s, i, &r))
//            reverse(s, i, r - 1);
//    }
//    return s;
//}
//
////100797. 使循环数组余额非负的最少移动次数
//
//long long minMoves(int* balance, int balanceSize)
//{
//    int n = balanceSize;
//    long long sum = 0;
//    int x = -1;
//    for (int i = 0; i < n; i++)
//    {
//        sum += balance[i];
//        if (balance[i] < 0)
//            x = i;
//    }
//    if (sum < 0)
//        return -1;
//    if (x < 0)
//        return 0;
//
//    long long ans = 0;
//    for (int i = 1; ; i++)
//    {
//        int r = (x + i) % n, l = (x - i + n) % n;
//        int sum = r == l ? balance[r] : balance[r] + balance[l];
//        if (balance[x] + sum < 0)
//        {
//            ans += 1ll * sum * i;
//            balance[x] += sum;
//        }
//        else
//        {
//            ans -= 1ll * balance[x] * i;
//            break;
//        }
//    }
//    return ans;
//}
//
////2147. 分隔长廊的方案数
//
//int numberOfWays(char* corridor)
//{
//    int n = strlen(corridor);
//    int** vis = (int**)malloc(sizeof(int*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        vis[i] = (int*)malloc(sizeof(int) * 3);
//        vis[i][0] = -1;
//        vis[i][1] = -1;
//        vis[i][2] = -1;
//    }
//    int dfs(int i, int k)
//    {
//        if (i < 0)
//            return k == 2;
//
//        if (vis[i][k] != -1)
//            return vis[i][k];
//
//        if (k < 2)
//            return dfs(i - 1, k + (corridor[i] == 'S'));
//        else if (corridor[i] == 'S')
//            return dfs(i - 1, 1);
//        else
//            return dfs(i - 1, 0) + dfs(i - 1, 2);
//    }
//    return dfs(n - 1, 0);
//}
//
//const int mod = 1e9 + 7;
//int numberOfWays(char* corridor)
//{
//    int n = strlen(corridor);
//    int f[n + 1][3];
//    f[0][0] = 0; f[0][1] = 0; f[0][2] = 1;
//    for (int i = 0; i < n; i++)
//    {
//        f[i + 1][0] = f[i][corridor[i] == 'S'];
//        f[i + 1][1] = f[i][1 + (corridor[i] == 'S')];
//        if (corridor[i] == 'S')
//            f[i + 1][2] = f[i][1];
//        else
//            f[i + 1][2] = (f[i][0] + f[i][2]) % mod;
//    }
//    return f[n][0];
//}
//
//const int mod = 1e9 + 7;
//int numberOfWays(char* corridor)
//{
//    int n = strlen(corridor);
//    long long ans = 1;
//    int cnt_s = 0, last_s = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (corridor[i] == 'S')
//        {
//            cnt_s++;
//            if (cnt_s >= 3 && cnt_s % 2)
//            {
//                ans = ans * (i - last_s) % mod;
//            }
//            last_s = i;
//        }
//    }
//    if (cnt_s == 0 || cnt_s % 2)
//        return 0;
//
//    return ans;
//}
//
