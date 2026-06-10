//// 592. 分数加减运算
//
//int prime(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//void toString(char* s, int* n, int x)
//{
//    int k = *n;
//    int left = k;
//    if (x == 0)
//        s[k++] = '0';
//    while (x)
//    {
//        s[k++] = x % 10 + '0';
//        x /= 10;
//    }
//    reverse(s, left, k - 1);
//    *n = k;
//}
//char* fractionAddition(char* expression)
//{
//    int nume = 0, denom = 1;
//    bool sym = false;
//    if (expression[0] == '-')
//    {
//        sym = true;
//        expression++;
//    }
//    int t = 0;
//    while (expression[t])
//    {
//        char* s = expression + t;
//        // printf("%s\n", s);
//        while (expression[t] && expression[t] != '+' && expression[t] != '-')
//        {
//            t++;
//        }
//        int n = 10, m = 10;
//        if (s[1] == '/')
//        {
//            n = s[0] & 15;
//            m = s[3] == '0' ? 10 : s[2] & 15;
//        }
//        else
//            m = s[4] == '0' ? 10 : s[3] & 15;
//        // printf("%d %d\n", n, m);
//        if (sym)
//            n = -n;
//        if (denom % m)
//        {
//            n *= denom;
//            denom *= m;
//            nume = nume * m + n;
//        }
//        else
//        {
//            n *= denom / m;
//            nume += n;
//        }
//        if (expression[t])
//        {
//            sym = expression[t] == '+' ? false : true;
//            t++;
//        }
//        // printf("%d %d\n", nume, denom);
//    }
//    int d = prime(abs(nume), denom);
//    // printf("%d ", d);
//    nume /= d;
//    denom /= d;
//    char* ans = (char*)malloc(sizeof(char) * 16);
//    int k = 0;
//    if (nume < 0)
//    {
//        ans[k++] = '-';
//        nume = -nume;
//    }
//    toString(ans, &k, nume);
//    ans[k++] = '/';
//    toString(ans, &k, denom);
//    ans[k] = '\0';
//    return ans;
//}
//
