//#define _CRT_SECURE_NO_WARNINGS
//
////434.字符串中的单词数
//
//int countSegments(char* s)
//{
//    int len = strlen(s);
//    int num = 0;
//    int i = 0;
//    while (i < len)
//    {
//        while (i < len && ' ' != s[i])
//        {
//            i++;
//        }
//        if (0 != i)
//            num++;
//        while (i < len && ' ' == s[i])
//        {
//            i++;
//        }
//    }
//    return num;
//}
//
////441. 排列硬币
//
//int arrangeCoins(int n)
//{
//    return (int)(2 * (sqrt(0.5 * n + 0.0625) - 0.25));
//}
//
////455. 分发饼干
//
//int cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int findContentChildren(int* g, int gSize, int* s, int sSize)
//{
//    qsort(g, gSize, 4, cmp_int);
//    qsort(s, sSize, 4, cmp_int);
//
//    int count = 0;
//    for (int i = gSize - 1; i >= 0; i--)
//    {
//        if (sSize - 1 - count >= 0 && s[sSize - 1 - count] >= g[i])
//        {
//            count++;
//        }
//    }
//    return count;
//}