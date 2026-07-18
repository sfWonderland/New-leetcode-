////
//
//int maxActiveSectionsAfterTrade(char* s)
//{
//    int ans = 0, pre = INT_MIN, cnt = 0, max = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        cnt++;
//        if (s[i + 1] != s[i])
//        {
//            if (s[i] - '0')
//                ans += cnt;
//            else
//            {
//                max = fmax(max, pre + cnt);
//                pre = cnt;
//            }
//            cnt = 0;
//        }
//    }
//    return ans + max;
//}
//
