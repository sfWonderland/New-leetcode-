////100887. 三元素表达式的最大值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maximizeExpressionOfThree(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return nums[0] + nums[1] - nums[numsSize - 1];
//}
//
////3746. 等量移除后的字符串最小长度
//
//int minLengthAfterRemovals(char* s)
//{
//    int n = strlen(s);
//    int st[n];
//    int i = 0;
//    for (int j = 0; j < n; j++)
//    {
//        if (i > 0 && abs(st[i - 1] - s[j]) == 1)
//            i--;
//        else
//            st[i++] = s[j];
//    }
//    return i;
//}
//
////3747. 统计移除零后不同整数的数目
//
//const long long arr[15] = { 0, 9, 90, 819, 7380, 66429, 597870, 5380839, 48427560, 435848049, 3922632450, 35303692059, 317733228540, 2859599056869, 25736391511830 };
//long long countDistinct(long long n)
//{
//    char* s = (char*)malloc(sizeof(char) * 17);
//    sprintf(s, "%lld", n);
//    int m = strlen(s);
//    long long ans = 0;
//    long long base = pow(9, m - 1);
//    int i = 0;
//    for (; i < m; i++)
//    {
//        if (s[i] == '0')
//            break;
//        ans += base * (s[i] - '0');
//        base /= 9;
//    }
//    if (i < m)
//        ans += arr[m - i - 1];
//    return ans;
//}
//
////1513. 仅含 1 的子串数
//
//const int mod = 1e9 + 7;
//int numSub(char* s)
//{
//    int left = INT_MAX, n = strlen(s);
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '0')
//        {
//            ans += left == INT_MAX ? 0 : 1ll * (i - left) * (i - left + 1) / 2;
//            left = INT_MAX;
//        }
//        else if (left == INT_MAX)
//        {
//            left = i;
//        }
//    }
//    ans += left == INT_MAX ? 0 : 1ll * (n - left) * (n + 1 - left) / 2;
//    return ans % mod;
//}
//
