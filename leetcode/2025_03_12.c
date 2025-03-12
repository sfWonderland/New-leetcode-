////1880. 检查某单词是否等于两单词之和
//
//int alpha_to_num(char* s)
//{
//    int num = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        num *= 10;
//        num += s[i] - 'a';
//    }
//    return num;
//}
//bool isSumEqual(char* firstWord, char* secondWord, char* targetWord)
//{
//    return alpha_to_num(firstWord) + alpha_to_num(secondWord) == alpha_to_num(targetWord);
//}
//
////1598. 文件夹操作日志搜集器
//
//int minOperations(char** logs, int logsSize)
//{
//    int num = 0;
//    for (int i = 0; i < logsSize; i++)
//    {
//        if (0 == strcmp(logs[i], "../"))
//            num = fmax(num - 1, 0);
//        else if (0 == strcmp(logs[i], "./"))
//            continue;
//        else
//            num++;
//    }
//    return num;
//}
//
////844. 比较含退格的字符串
//
//char* backspace(char* s)
//{
//    int slow = 0;
//    for (int fast = 0; s[fast]; fast++)
//    {
//        if (s[fast] != '#')
//            s[slow++] = s[fast];
//        else
//            slow = fmax(slow - 1, 0);
//    }
//    s[slow] = '\0';
//    return s;
//}
//bool backspaceCompare(char* s, char* t)
//{
//    return strcmp(backspace(s), backspace(t)) == 0;
//}
//
////2390. 从字符串中移除星号
//
//char* removeStars(char* s)
//{
//    int slow = 0;
//    for (int fast = 0; s[fast]; fast++)
//    {
//        if (s[fast] != '*')
//            s[slow++] = s[fast];
//        else
//            slow--;
//    }
//    s[slow] = '\0';
//    return s;
//}
//
////1047. 删除字符串中的所有相邻重复项
//
//char* removeDuplicates(char* s)
//{
//    int slow = 0;
//    for (int fast = 0; s[fast]; fast++)
//    {
//        if ((slow == 0) || (slow > 0 && s[fast] != s[slow - 1]))
//            s[slow++] = s[fast];
//        else
//            slow--;
//    }
//    s[slow] = '\0';
//    return s;
//}
//
////2716. 最小化字符串长度
//
//int minimizedStringLength(char* s)
//{
//    int mask = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        mask |= 1 << (s[i] - 'a');
//    }
//    int n = 0;
//    while (mask)
//    {
//        mask &= mask - 1;
//        n++;
//    }
//    return n;
//}
//
////20. 有效的括号
//
//bool isValid(char* s)
//{
//    int slow = 0;
//    for (int fast = 0; s[fast]; fast++)
//    {
//        if ((slow == 0) || (slow > 0 && (s[fast] <= s[slow - 1] || s[fast] > s[slow - 1] + 2)))
//            s[slow++] = s[fast];
//        else
//            slow--;
//    }
//    s[slow] = '\0';
//    return slow == 0;
//}
//
