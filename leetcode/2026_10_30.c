//// 1544. ÕûÀí×Ö·û´®
//
//char* makeGood(char* s)
//{
//    int top = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (top == 0 || abs(s[top - 1] - s[i]) != 32)
//            s[top++] = s[i];
//        else
//            top--;
//    }
//    s[top] = '\0';
//    return s;
//}
//
