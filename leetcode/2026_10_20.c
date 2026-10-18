//// 150. 逆波兰表达式求值
//
//int evalRPN(char** tokens, int tokensSize)
//{
//    int n = tokensSize;
//    int* st = (int*)malloc(sizeof(int) * (n + 1) / 2);
//    int top = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (!tokens[i][1] && !isdigit(tokens[i][0])) // 符号
//        {
//            switch (tokens[i][0])
//            {
//            case '+': --top; st[top - 1] += st[top]; break;
//            case '-': --top; st[top - 1] -= st[top]; break;
//            case '*': --top; st[top - 1] *= st[top]; break;
//            case '/': --top; st[top - 1] /= st[top]; break;
//            }
//        }
//        else
//        {
//            bool neg = tokens[i][0] == '-';
//            int start = neg;
//            int x = 0;
//            for (int j = neg; tokens[i][j]; j++)
//            {
//                x *= 10;
//                x += tokens[i][j] & 15;
//            }
//            if (neg) x = -x;
//            st[top++] = x;
//        }
//    }
//    int ans = st[0];
//    free(st);
//    return ans;
//}
//
