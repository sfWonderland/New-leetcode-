////2391. 收集垃圾的最少总时间
//
//int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize)
//{
//    int distance[26] = { 0 };
//    int ans = 0, curDis = 0;
//    for (int i = 0; i < garbageSize; i++)
//    {
//        ans += strlen(garbage[i]);
//
//        if (i > 0)
//            curDis += travel[i - 1];
//        for (int j = 0; garbage[i][j]; j++)
//        {
//            distance[garbage[i][j] - 'A'] = curDis;
//        }
//    }
//    for (int i = 0; i < 26; i++)
//        ans += distance[i];
//
//    return ans;
//}
//
//
////1678. 设计 Goal 解析器
//
//char* interpret(char* command)
//{
//    int slow = 0;
//    for (int i = 0; command[i]; i++)
//    {
//        if (isalpha(command[i]))
//            command[slow++] = command[i];
//        else
//        {
//            if (command[i + 1] == ')')
//                command[slow++] = 'o';
//        }
//    }
//    command[slow] = '\0';
//    return command;
//}
//
////LCR 189. 设计机械累加器
//
//int mechanicalAccumulator(int target)
//{
//    return target == 0 ? 0 : target + mechanicalAccumulator(target - 1);
//}
//
////2864. 最大二进制奇数
//
//char* maximumOddBinaryNumber(char* s)
//{
//    int n = strlen(s), ones = -1;
//    for (int i = 0; i < n; i++)
//    {
//        ones += s[i] - '0';
//        s[i] = '0';
//    }
//    s[n - 1] = '1';
//    for (int i = 0; ones > 0; i++)
//    {
//        s[i] = '1';
//        ones--;
//    }
//    return s;
//}
//
//void swap(char* a, char* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//char* maximumOddBinaryNumber(char* s)
//{
//    int n = strlen(s), left = 0;
//    bool flag = s[n - 1] - '0';
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (s[i] - '0')
//        {
//            if (flag)
//            {
//                swap(&s[left], &s[i]);
//                left++;
//            }
//            else
//            {
//                swap(&s[i], &s[n - 1]);
//                flag = true;
//            }
//        }
//    }
//    return s;
//}
//
