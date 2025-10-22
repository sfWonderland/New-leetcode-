////3461. 判断操作后字符串中的数字是否相等 I
//
//bool hasSameDigits(char* s)
//{
//    int n = strlen(s);
//    while (n > 2)
//    {
//        for (int i = 0; i < n - 1; i++)
//        {
//            s[i] = (s[i] + s[i + 1] - 2 * '0') % 10 + '0';
//        }
//        n--;
//    }
//    return s[0] == s[1];
//}
//
////474. 一和零
//
//int dfs(int** nums, int i, int m, int n)
//{
//    //printf("%d %d %d\n", i, m, n);
//    if (m < 0 || n < 0)
//        return -601;
//
//    if (i < 0)
//        return 0;
//
//    return fmax(1 + dfs(nums, i - 1, m - nums[0][i], n - nums[1][i]), dfs(nums, i - 1, m, n));
//}
//int findMaxForm(char** strs, int strsSize, int m, int n)
//{
//    int** nums = (int**)malloc(sizeof(int*) * 2);
//    nums[0] = (int*)calloc(sizeof(int), strsSize);
//    nums[1] = (int*)calloc(sizeof(int), strsSize);
//    for (int i = 0; i < strsSize; i++)
//    {
//        for (int j = 0; strs[i][j]; j++)
//        {
//            nums[strs[i][j] - '0'][i]++;
//        }
//    }
//    return dfs(nums, strsSize - 1, m, n);
//}
//
//int findMaxForm(char** strs, int strsSize, int m, int n)
//{
//    int len = strsSize;
//    int** nums = (int**)malloc(sizeof(int*) * 2);
//    nums[0] = (int*)calloc(sizeof(int), len);
//    nums[1] = (int*)calloc(sizeof(int), len);
//    for (int i = 0; i < len; i++)
//    {
//        for (int j = 0; strs[i][j]; j++)
//        {
//            nums[strs[i][j] - '0'][i]++;
//        }
//    }
//    int f[len + 1][m + 1][n + 1];
//    memset(f[0], 0, sizeof(f[0]));
//    for (int k = 0; k < len; k++)
//    {
//        int zero = nums[0][k], one = nums[1][k];
//        for (int i = 0; i <= m; i++)
//        {
//            for (int j = 0; j <= n; j++)
//            {
//                int a = f[k][i][j];
//                int b = (i >= zero && j >= one) ? f[k][i - zero][j - one] + 1 : 0;
//                f[k + 1][i][j] = fmax(a, b);
//            }
//        }
//    }
//    return f[len][m][n];
//}
//
////91. 解码方法
//
//int numDecodings(char* s)
//{
//    int n = strlen(s);
//    int f[3] = { 0 };
//    f[0] = 1;
//    int pre = 3;
//    for (int i = 0; i < n; i++)
//    {
//        f[(i + 1) % 3] = 0;
//        int a = s[i] - '0';
//        int b = pre * 10 + s[i] - '0';
//        if (a >= 1 && a <= 9) f[(i + 1) % 3] = f[i % 3];
//        if (b >= 10 && b <= 26) f[(i + 1) % 3] += f[(i - 1) % 3];
//        pre = a;
//    }
//    return f[n % 3];
//}
//
////1041. 困于环中的机器人
//
//const int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; // left
//bool isRobotBounded(char* instructions)
//{
//    int pos[2] = { 0, 0 };
//    int orient = 0;
//    for (int i = 0; instructions[i]; i++)
//    {
//        if (instructions[i] == 'G')
//        {
//            pos[0] += dir[orient][0];
//            pos[1] += dir[orient][1];
//        }
//        else if (instructions[i] == 'L')
//            orient = (orient + 1) % 4;
//        else
//            orient = (orient + 3) % 4;
//    }
//    return (pos[0] == 0 && pos[1] == 0) || orient;
//}
//
