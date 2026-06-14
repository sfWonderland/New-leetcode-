//// 481. ÉñÆæ×Ö·û´®
//
//int magicalString(int n)
//{
//    if (n <= 3)
//        return 1;
//
//    char* s = (char*)malloc(sizeof(char) * n);
//    s[0] = 1, s[1] = 2, s[2] = 2;
//    int ans = 1, x = 1;
//    for (int i = 2, j = 3; j < n; i++)
//    {
//        int m = fmin(s[i], n - j);
//        if (m == 1)
//            s[j++] = x;
//        else
//        {
//            s[j++] = x;
//            s[j++] = x;
//        }
//        // printf("%d %s\n", m, s);
//        ans += (x == 1) * m;
//        x ^= 3;
//    }
//    free(s);
//    return ans;
//}
//
