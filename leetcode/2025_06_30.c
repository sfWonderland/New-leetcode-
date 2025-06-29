////594. 最长和谐子序列
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findLHS(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0, left = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (nums[i] - 1 > nums[left])
//        {
//            left++;
//        }
//        if (nums[i] - 1 == nums[left])
//            ans = fmax(ans, i - left + 1);
//    }
//    return ans;
//}
//
////2125. 银行中的激光束数量
//
//int numberOfBeams(char** bank, int bankSize)
//{
//    int ans = 0, upper = 0;
//    for (int i = 0; i < bankSize; i++)
//    {
//        int n = 0;
//        for (int j = 0; bank[i][j]; j++)
//        {
//            n += bank[i][j] - '0';
//        }
//        if (n)
//        {
//            ans += n * upper;
//            upper = n;
//        }
//    }
//    return ans;
//}
//
////3128. 直角三角形
//
//long long numberOfRightTriangles(int** grid, int gridSize, int* gridColSize)
//{
//    long long ans = 0;
//    int col[gridColSize[0]];
//    memset(col, 0, sizeof(col));
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[i]; j++)
//        {
//            col[j] += grid[i][j];
//        }
//    }
//    for (int i = 0; i < gridSize; i++)
//    {
//        int row = -1;
//        for (int j = 0; j < gridColSize[i]; j++)
//        {
//            row += grid[i][j];
//        }
//        for (int j = 0; j < gridColSize[i]; j++)
//        {
//            if (grid[i][j])
//                ans += row * (col[j] - 1);
//        }
//    }
//    return ans;
//}
//
////1573. 分割字符串的方案数
//
//#define mod 1000000007
//int numWays(char* s)
//{
//    int one_sum = 0;
//    long long n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        one_sum += s[i] - '0';
//    }
//    if (0 == one_sum)
//        return (n - 1) * (n - 2) / 2l % mod;
//    if (one_sum % 3)
//        return 0;
//
//
//    int i = 0;
//    int m = one_sum / 3;
//    while (m)
//    {
//        m -= s[i] - '0';
//        i++;
//    }
//    long long a = 1;
//    while (s[i] == '0')
//    {
//        a++;
//        i++;
//    }
//    m = one_sum / 3;
//    while (m)
//    {
//        m -= s[i] - '0';
//        i++;
//    }
//    long long b = 1;
//    while (s[i] == '0')
//    {
//        b++;
//        i++;
//    }
//
//    return a * b % mod;
//}
//
