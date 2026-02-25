////3666. 使二进制字符串全为 1 的最少操作次数
//
//int minOperations(char* s, int k)
//{
//    // 计算'0'的个数
//    int z = 0, n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        z += '1' - s[i];
//    }
//    // 没有'0'不用变化
//    if (z == 0)
//        return 0;
//    // k 等于字符串长度 n ，则必须一次变完所有'0'
//    if (k == n)
//        return z == n ? 1 : -1;
//
//    // '0'需要变换奇数次z，'1'需要变换偶数次n - z；
//    // 设总计变换m次，总共变换mk次
//    // mk - z 一定是偶数，mk - z >= 0，故 m >= (z / k)(上界) 
//    // 若m为偶数，z一定是偶数；最大次数z * (m - 1) + (n - z) * m >= mk
//    // m >= (z / (n - k))(上界)
//    // 若m为奇数，z必须与k同奇偶，最大次数z * m * (n - z) * (m - 1) >= mk
//    // m >= ((n - z) / (n - k))(上界)
//    // 上界转下界公式 (a / b)(上界) = ((a + b - 1) / b)(下界)
//    // 若 a % b == 0, 则左 = a / b, 右 = a / b + ((b - 1) / b)(下界) = a / b，成立
//    // 若 a % b > 0, 则左 = a / b + 1, 右 = a / b + 1，成立
//
//    int ans = INT_MAX;
//    // z 为偶数
//    if (z % 2 == 0)
//    {
//        int m = fmax((z + k - 1) / k, (z + n - k - 1) / (n - k));
//        ans = m + m % 2; // 把 m 往上调整为偶数
//    }
//
//    // z 为奇数，k 必须为奇数
//    if (k % 2 == z % 2)
//    {
//        int m = fmax((z + k - 1) / k, (2 * n - z - k - 1) / (n - k));
//        ans = fmin(ans, m | 1); // 把 m 往上调整为奇数
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
////1876. 长度为三且各字符不同的子字符串    
//
//int countGoodSubstrings(char* s)
//{
//    int n = strlen(s), ans = 0;
//    if (n <= 2)
//        return 0;
//    for (int i = 0; i < n - 2; i++)
//    {
//        if (s[i + 1] == s[i + 2])
//        {
//            i++;
//            continue;
//        }
//        if (s[i] != s[i + 1] && s[i] != s[i + 2])
//            ans++;
//    }
//    return ans;
//}
//
////1894. 找到需要补充粉笔的学生编号
//
//int chalkReplacer(int* chalk, int chalkSize, int k)
//{
//    int n = 0;
//    for (int i = 0; i < chalkSize; i++)
//    {
//        n += chalk[i];
//        k -= chalk[i];
//        if (k < 0)
//            return i;
//    }
//    k %= n;
//    for (int i = 0; i < chalkSize; i++)
//    {
//        k -= chalk[i];
//        if (k < 0)
//            return i;
//    }
//    return -1;
//}
//
//int chalkReplacer(int* chalk, int chalkSize, int k)
//{
//    int n = chalkSize;
//    int pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < chalkSize; i++)
//    {
//        pre[i + 1] = pre[i] + chalk[i];
//        k -= chalk[i];
//        if (k < 0)
//            return i;
//    }
//    k %= pre[n];
//    int left = 1, right = n;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (pre[mid] > k)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left - 1;
//}
//
////1910. 删除一个字符串中所有出现的给定子字符串
//
//char* removeOccurrences(char* s, char* part)
//{
//    int n = strlen(s), m = strlen(part);
//    char* st = (char*)malloc(sizeof(char) * (n + 1));
//    int idx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        st[idx++] = s[i];
//        if (idx < m)
//            continue;
//        if (strncmp(st + idx - m, part, m) == 0)
//            idx -= m;
//    }
//    st[idx] = '\0';
//    return st;
//}
//
