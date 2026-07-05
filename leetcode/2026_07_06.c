//// 3982. 最大数字范围的整数之和
//
//int maxDigitRange(int* nums, int numsSize)
//{
//    int ans = 0, d = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int min = 9, max = 0, x = nums[i];
//        while (x)
//        {
//            int y = x % 10;
//            min = fmin(min, y);
//            max = fmax(max, y);
//            x /= 10;
//        }
//        if (d < max - min)
//        {
//            d = max - min;
//            ans = nums[i];
//        }
//        else if (d == max - min)
//            ans += nums[i];
//    }
//    return ans;
//}
//
//// 3983. 一次替换后的子序列
//
//bool canMakeSubsequence(char* s, char* t)
//{
//    int n = strlen(s);
//    int m = strlen(t);
//
//    // 如果 s 比 t 长，不可能成为子序列
//    if (n > m) return false;
//
//    int pre[m + 1];
//    pre[0] = 0;
//    for (int i = 0; i < m; ++i)
//    {
//        int j = pre[i];
//        // printf("%d ", j);
//        pre[i + 1] = j + (s[j] == t[i]);
//        // 情况1：无需替换即可成为子序列
//        if (pre[i + 1] == n)
//            return true;
//    }
//
//    int suf[m + 1];
//    suf[m] = n; // 空后缀可以从任意位置开始（这里设为 m 表示结束）
//    for (int i = m - 1; i >= 0; --i)
//    {
//        int j = suf[i + 1];
//        suf[i] = j - (s[j - 1] == t[i]);
//    }
//
//    // 情况2：尝试替换 s 中的每个位置
//    for (int i = 0; i < m; ++i)
//    {
//        // 如果前 i 个字符匹配到的位置不超过后缀开始的位置，则可通过替换第 i 个字符成功
//        // printf("%d %d %d\n", i, pre[i + 1], suf[i]);
//        if (pre[i] + 1 >= suf[i + 1])
//            return true;
//    }
//
//    return false;
//}
//
