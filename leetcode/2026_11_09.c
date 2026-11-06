//// 1614. 括号的最大嵌套深度
//
//int maxDepth(char* s)
//{
//    int ans = 0, cnt = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '(')
//        {
//            cnt++;
//            ans = ans >= cnt ? ans : cnt;
//        }
//        else if (s[i] == ')')
//            cnt--;
//    }
//    return ans;
//}
//
