////3146. 两个字符串的排列差
//
//int findPermutationDifference(char* s, char* t)
//{
//    int hash[26][2] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        hash[s[i] - 'a'][0] = i;
//    }
//    for (int i = 0; t[i]; i++)
//    {
//        hash[t[i] - 'a'][1] = i;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        ans += abs(hash[i][0] - hash[i][1]);
//    }
//    return ans;
//}
//
////3168. 候诊室中的最少椅子数
//
//int minimumChairs(char* s)
//{
//    int ans = 0, sum = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        sum += (s[i] == 'E') ? 1 : -1;
//        ans = fmax(sum, ans);
//    }
//    return ans;
//}
//
////2011. 执行操作后的变量值
//
//int finalValueAfterOperations(char** operations, int operationsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < operationsSize; i++)
//    {
//        if (operations[i][1] == '+')
//            ans++;
//        else
//            ans--;
//    }
//    return ans;
//}
//
////2960. 统计已测试设备
//
//int countTestedDevices(int* batteryPercentages, int batteryPercentagesSize)
//{
//    int ans = 0;
//    for (int i = 0; i < batteryPercentagesSize; i++)
//    {
//        if (batteryPercentages[i] > ans)
//            ans++;
//    }
//    return ans;
//}
//
