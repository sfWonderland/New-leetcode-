////LCR 122. 路径加密
//
//char* pathEncryption(char* path)
//{
//    for (int i = 0; path[i]; i++)
//    {
//        if (path[i] == '.')
//            path[i] = ' ';
//    }
//    return path;
//}
//
//
////LCR 182. 动态口令
//
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        int t = *(s + l);
//        *(s + l) = *(s + r);
//        *(s + r) = t;
//        l++;
//        r--;
//    }
//}
//char* dynamicPassword(char* password, int target)
//{
//    int len = strlen(password);
//    reverse(password, 0, len - 1);
//    reverse(password, 0, len - target - 1);
//    reverse(password, len - target, len - 1);
//    return password;
//}
//
////LCR 134. Pow(x, n)
//
//double myPow(double x, int n)
//{
//    if (0 == x)
//        return 0;
//    long long t = n;
//    if (n < 0)
//    {
//        t *= -1;
//        x = 1 / x;
//    }
//    double ret = 1;
//    while (t)
//    {
//        if (t & 1)
//            ret *= x;
//
//        x = x * x;
//        t >>= 1;
//    }
//    return ret;
//}
//
////LCR 135.报数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* countNumbers(int cnt, int* returnSize)
//{
//    int n = 1;
//    while (cnt)
//    {
//        n *= 10;
//        cnt--;
//    }
//    int* ret = (int*)malloc(sizeof(int) * (n - 1));
//    for (int i = 1; i < n; i++)
//        ret[i - 1] = i;
//    *returnSize = n - 1;
//    return ret;
//}
