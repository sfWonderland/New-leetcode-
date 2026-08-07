//// 224. »ù±¾¼ÆËãÆ÷
//
//long long calc(long long x, long long y, char sym)
//{
//    if (sym == '*')
//        return x * y;
//    else if (sym == '/')
//        return x / y;
//    else if (sym == '+')
//        return x + y;
//
//    return x - y;
//}
//int calculate(char* s)
//{
//    int n = strlen(s);
//    int prior[48] = { 0 };
//    prior['*'] = 3; prior['/'] = 3;
//    prior['+'] = 2; prior['-'] = 2;
//    prior['('] = 1;
//    char* sym = (char*)malloc(sizeof(char) * n);
//    long long* num = (long long*)malloc(sizeof(long long) * n);
//    int topS = 0, topN = 0;
//    sym[topS++] = '('; // ÉÚ±ø
//    bool pre = false;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == ' ')
//            continue;
//        if (s[i] >= '0')
//        {
//            if (i > 0 && s[i - 1] >= '0')
//                num[topN - 1] = num[topN - 1] * 10 - '0' + s[i];
//            else
//                num[topN++] = s[i] - '0';
//            pre = true;
//        }
//        else if (s[i] == ')')
//        {
//            while (sym[--topS] != '(')
//            {
//                --topN;
//                num[topN - 1] = calc(num[topN - 1], num[topN], sym[topS]);
//            }
//            pre = true;
//            // printf("%d %d %d %c\n", topN, topS, num[topN - 1], sym[topS - 1]);
//        }
//        else if (s[i] == '(')
//        {
//            sym[topS++] = s[i];
//            pre = false;
//        }
//        else
//        {
//            int p1 = prior[s[i]], p2 = prior[sym[topS - 1]];
//            while (p1 <= p2)
//            {
//                //printf("%d %d %d %c\n", topN, topS, num[topN - 1], sym[topS - 1]);
//                --topN;
//                num[topN - 1] = calc(num[topN - 1], num[topN], sym[--topS]);
//                p2 = prior[sym[topS - 1]];
//            }
//            sym[topS++] = s[i];
//            if (!pre)
//            {
//                pre = true;
//                num[topN++] = 0;
//            }
//        }
//    }
//    while (sym[--topS] != '(')
//    {
//        --topN;
//        num[topN - 1] = calc(num[topN - 1], num[topN], sym[topS]);
//    }
//    int ans = num[0];
//    //for(int i = 0; i < topN; i++) printf("%d ", num[i]);
//    free(num);
//    free(sym);
//    return ans;
//}
//
