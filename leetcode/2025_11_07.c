////1946. 子字符串突变后可能得到的最大整数
//
//char* maximumNumber(char* num, int* change, int changeSize)
//{
//    int n = strlen(num), i = 0;
//    while (i < n && change[num[i] - '0'] <= num[i] - '0')
//        i++;
//    while (i < n && num[i] - '0' <= change[num[i] - '0'])
//    {
//        num[i] = change[num[i] - '0'] + '0';
//        i++;
//    }
//    return num;
//}
//
////1663. 具有给定数值的最小字符串
//
//char* getSmallestString(int n, int k)
//{
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[n] = '\0';
//    k -= n;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (k >= 25)
//        {
//            ans[i] = 'z';
//            k -= 25;
//        }
//        else if (k > 0)
//        {
//            ans[i] = 'a' + k;
//            k = 0;
//        }
//        else
//            ans[i] = 'a';
//    }
//    return ans;
//}
//
////2259. 移除指定数字得到的最大结果
//
//char* removeDigit(char* number, char digit)
//{
//    bool remove = false;
//    int pos = -1, n = strlen(number);
//    char* ans = (char*)malloc(sizeof(char) * n);
//    ans[n - 1] = '\0';
//    for (int i = 0; i < n; i++)
//    {
//        if (number[i] != digit)
//            continue;
//
//        pos = i;
//        if (number[i] < number[i + 1])
//            break;
//    }
//    int idx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (i != pos)
//            ans[idx++] = number[i];
//    }
//    return ans;
//}
//
////670. 最大交换
//
//int maximumSwap(int num)
//{
//    char* s = (char*)malloc(sizeof(char) * 9);
//    sprintf(s, "%d", num);
//    int n = strlen(s);
//    int max_idx = n - 1, p = -1, q;
//    for (int i = n - 2; i >= 0; i--)
//    {
//        if (s[i] > s[max_idx])
//            max_idx = i;
//        else if (s[i] < s[max_idx])
//        {
//            p = i;
//            q = max_idx;
//        }
//    }
//    if (p == -1)
//        return num;
//    else
//    {
//        char ch = s[p];
//        s[p] = s[q];
//        s[q] = ch;
//    }
//    int ans = atoi(s);
//    return ans;
//}
//
