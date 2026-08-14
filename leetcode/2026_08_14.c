//// 1106. 解析布尔表达式
//
//bool parseBoolExpr(char* expression)
//{
//    int n = strlen(expression);
//    char* st = (char*)malloc(sizeof(char) * n);
//    bool* num = (bool*)malloc(sizeof(bool) * n);
//    int topS = 0, topN = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (expression[i] == ',' || expression[i] == '(' || expression[i] == ')')
//            st[topS++] = expression[i];
//        else if (expression[i] == 't' || expression[i] == 'f')
//            num[topN++] = (expression[i] == 't');
//        else
//        {
//            if (expression[i] == '!')
//            {
//                --topS;
//                num[topN - 1] ^= 1;
//                --topS;
//            }
//            else if (expression[i] == '|')
//            {
//                bool x = num[topN - 1];
//                while (st[--topS] != ')')
//                {
//                    x |= num[--topN];
//                }
//                num[topN++] = x;
//            }
//            else
//            {
//                bool x = num[topN - 1];
//                while (st[--topS] != ')')
//                {
//                    x &= num[--topN];
//                }
//                num[topN++] = x;
//            }
//        }
//    }
//    return num[0];
//}
//
