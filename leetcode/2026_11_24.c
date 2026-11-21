//// 856. À¨ºÅµÄ·ÖÊý
//
//int scoreOfParentheses(char* s)
//{
//    int* st = (int*)malloc(sizeof(int) * 50);
//    int top = 0;
//    st[top++] = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '(')
//            st[top++] = 0;
//        else
//        {
//            int x = st[--top];
//            if (x) st[top - 1] += 2 * x;
//            else st[top - 1]++;
//        }
//    }
//    return st[0];
//}
//
