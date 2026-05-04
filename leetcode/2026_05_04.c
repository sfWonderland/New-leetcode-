//// 面试题 01.03. URL化
//
//char* replaceSpaces(char* S, int length)
//{
//    char* ans = (char*)malloc(sizeof(char) * (3 * length + 1));
//    int size = 0, k = 0;
//    for (int i = 0; S[i] && k < length; i++)
//    {
//        if (S[i] != ' ')
//        {
//            ans[size++] = S[i];
//            k++;
//        }
//        else
//        {
//            ans[size++] = '%';
//            ans[size++] = '2';
//            ans[size++] = '0';
//            k++;
//        }
//    }
//    while (k < length)
//    {
//        ans[size++] = '%';
//        ans[size++] = '2';
//        ans[size++] = '0';
//        k++;
//    }
//    ans[size] = '\0';
//    return ans;
//}
//
//// 面试题 01.04. 回文排列  
//
//bool canPermutePalindrome(char* s)
//{
//    bool cnt[128] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i]] ^= 1;
//    }
//    int n = 0;
//    for (int i = 0; i < 128 && n < 2; i++)
//    {
//        n += cnt[i];
//    }
//    return n < 2;
//}
//
//// 面试题 01.05. 一次编辑
//
//bool check1(char* s1, char* s2, int n)
//{
//    int j = 0;
//    bool flag = true;
//    for (int i = 0; i < n; i++)
//    {
//        if (s1[i] != s2[j])
//        {
//            if (flag)
//                flag = false;
//            else
//                return false;
//        }
//        else
//            j++;
//    }
//    return true;
//}
//bool check2(char* s1, char* s2, int n)
//{
//    bool flag = true;
//    for (int i = 0; i < n; i++)
//    {
//        if (s1[i] != s2[i])
//        {
//            if (flag)
//                flag = false;
//            else
//                return false;
//        }
//    }
//    return true;
//}
//bool oneEditAway(char* first, char* second)
//{
//    int n = strlen(first);
//    int m = strlen(second);
//    if (abs(n - m) > 1)
//        return false;
//    if (n != m)
//        return n > m ? check1(first, second, n) : check1(second, first, m);
//
//    return check2(first, second, n);
//}
//
//// 面试题 01.06. 字符串压缩
//
//char* compressString(char* S)
//{
//    int n = strlen(S);
//    if (n == 0)
//        return S;
//    char* compress = (char*)malloc(sizeof(char) * (2 * n + 1));
//    compress[n - 1] = '\0';
//    int k = 0;
//    for (int i = 0; i < n && k <= n; )
//    {
//        char c = S[i];
//        int j = i;
//        while (S[i] == c)
//            i++;
//        compress[k++] = c;
//        int d = i - j;
//        int left = k;
//        while (d)
//        {
//            compress[k++] = d % 10 + '0';
//            if (k > n)
//                break;
//            d /= 10;
//        }
//        if (k > n)
//            break;
//        int right = k - 1;
//        while (left < right)
//        {
//            char tmp = compress[left];
//            compress[left++] = compress[right];
//            compress[right--] = tmp;
//        }
//    }
//    compress[k++] = '\0';
//    return compress[n - 1] ? S : compress;
//}
//
