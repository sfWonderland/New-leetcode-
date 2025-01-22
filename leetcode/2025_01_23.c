//#define _CRT_SECURE_NO_WARNINGS
//
////521.最长特殊序列I
//
//int findLUSlength(char* a, char* b)
//{
//    int len_a = strlen(a);
//    int len_b = strlen(b);
//    if (len_a != len_b)
//        return len_a > len_b ? len_a : len_b;
//    else
//    {
//        int flag = 0;
//        for (int i = 0; i < len_a; i++)
//        {
//            if (a[i] != b[i])
//            {
//                flag = 1;
//                break;
//            }
//        }
//        return flag ? len_a : -1;
//    }
//}
//
////522.最长特殊序列II
//
//int findLUSlength(char** strs, int strsSize)
//{
//    int len[strsSize];
//    int max = 0;
//    int flag = 1;
//    for (int i = 0; i < strsSize; i++)
//    {
//        len[i] = strlen(strs[i]);
//        if (len[i] >= max)
//        {
//            if (len[i] > max) { flag = 1; max = len[i]; }
//            else flag = 0;
//        }
//        //printf("len[%d] = %d\n", i, len[i]);
//    }
//    if (flag) return max;
//
//    max = -1;
//    for (int i = 0; i < strsSize; i++)
//    {
//        flag = 0;
//        for (int j = 0; j < strsSize; j++)
//        {
//            if (i != j && len[j] >= len[i])
//            {
//                for (int k = 0; k < len[j]; k++)
//                {
//                    if (strs[i][flag] == strs[j][k])
//                    {
//                        flag++;
//                    }
//                }
//                if (flag != len[i]) flag = 0;
//                else break;
//            }
//        }
//        if (flag != len[i])
//        {
//            if (len[i] > max)
//                max = len[i];
//            //printf("flag = %d, i = %d, j = %d, max = %d\n", flag, i, max);
//        }
//    }
//
//    return max;
//}
//
////541.反转字符串II
//void ReverseSub(char* sub, int k)
//{
//    int left = 0;
//    int right = k - 1;
//    while (left < right)
//    {
//        char tmp = sub[left];
//        sub[left] = sub[right];
//        sub[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//char* reverseStr(char* s, int k)
//{
//    int len = strlen(s);
//    if (len >= 2 * k)
//    {
//        int i = 0;
//        int limit = len / (2 * k);
//        for (i = 0; i < limit; i++)
//        {
//            //printf("i = %d\n", i);
//            ReverseSub(s + 2 * i * k, k);
//        }
//
//        if (len % (2 * k))
//        {
//            if (len >= k + i * 2 * k)
//                ReverseSub(s + i * 2 * k, k);
//            else
//                ReverseSub(s + i * 2 * k, len - i * 2 * k);
//        }
//    }
//    else if (len >= k)
//        ReverseSub(s, k);
//    else
//        ReverseSub(s, len);
//    return s;
//}
//
////557.反转字符串中的单词
//
//void ReverseSub(char* sub, int k)
//{
//    int left = 0;
//    int right = k - 1;
//    while (left < right)
//    {
//        char tmp = sub[left];
//        sub[left] = sub[right];
//        sub[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//char* reverseWords(char* s)
//{
//    int len = strlen(s);
//    int left = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == ' ')
//        {
//            //printf("i = %d\n", i);
//            ReverseSub(s + left, i - left);
//            left = i + 1;
//        }
//        else if (i == len - 1)
//            ReverseSub(s + left, i - left + 1);
//    }
//    return s;
//}
//
////551.学生出勤记录
//
//bool checkRecord(char* s)
//{
//    int len = strlen(s);
//    int absent = 0;
//    int late = 0;
//    for (int i = 0; i < len; i++)
//    {
//        //absent
//        if (s[i] == 'A')
//            absent++;
//        //late
//        if (s[i] != 'L')
//            late = 0;
//        else
//            late++;
//        //check
//        if (late > 2 || absent > 1)
//            return false;
//    }
//    return true;
//}
//
////2810.故障键盘
//
//void ReverseSub(char* sub, int k)
//{
//    int left = 0;
//    int right = k - 1;
//    while (left < right)
//    {
//        char tmp = sub[left];
//        sub[left] = sub[right];
//        sub[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//char* finalString(char* s)
//{
//    int len = strlen(s);
//    char str[len + 1];
//    int j = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == 'i')
//        {
//            ReverseSub(str, j);
//        }
//        else
//            str[j++] = s[i];
//    }
//    for (; j < len + 1; j++)
//    {
//        str[j] = '\0';
//    }
//    char* p = str;
//    return p;
//}
//
////917.仅仅反转字母
//
//void ReverseSub(char* sub, int k)
//{
//    int left = 0;
//    int right = k - 1;
//    while (left < right)
//    {
//        while ((left < right) && ((sub[left] < 65) || ((sub[left] > 90) && (sub[left] < 97)) || (sub[left] > 122)))
//            left++;
//        while ((left < right) && ((sub[right] < 65) || ((sub[right] > 90) && (sub[right] < 97)) || (sub[right] > 122)))
//            right--;
//        if (left < right)
//        {
//            char tmp = sub[left];
//            sub[left] = sub[right];
//            sub[right] = tmp;
//            left++;
//            right--;
//        }
//    }
//}
//
//char* reverseOnlyLetters(char* s)
//{
//    int len = strlen(s);
//    ReverseSub(s, len);
//    return s;
//}