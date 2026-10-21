//// 844. 比较含退格的字符串
//
//bool backspaceCompare(char* s, char* t)
//{
//    int top1 = 0, top2 = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] != '#')
//            s[top1++] = s[i];
//        else if (top1 > 0)
//            top1--;
//    }
//    s[top1] = '\0';
//    for (int i = 0; t[i]; i++)
//    {
//        if (t[i] != '#')
//            t[top2++] = t[i];
//        else if (top2 > 0)
//            top2--;
//    }
//    t[top2] = '\0';
//    return strcmp(s, t) == 0;
//}
//
