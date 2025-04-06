////3396. 使数组元素互不相同所需的最少操作次数
//
//int minimumOperations(int* nums, int numsSize)
//{
//    int hash[101] = { 0 };
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (hash[nums[i]]++)
//            return i / 3 + 1;
//    }
//    return 0;
//}
//
////2315. 统计星号
//
//int countAsterisks(char* s)
//{
//    bool valid = true;
//    int stars = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == '|')
//            valid = !valid;
//        else if ('*' == s[i] && valid)
//            stars++;
//    }
//    return stars;
//}
//
////2325. 解密消息
//
//char* decodeMessage(char* key, char* message)
//{
//    int alpha[26] = { 0 };
//    char code[26] = { 0 };
//    int n = 0;
//    for (int i = 0; key[i]; i++)
//    {
//        if (isalpha(key[i]) && 0 == alpha[key[i] - 'a'])
//        {
//            alpha[key[i] - 'a'] = 1;
//            code[key[i] - 'a'] = 'a' + n;
//            n++;
//        }
//    }
//    for (int i = 0; message[i]; i++)
//    {
//        if (isalpha(message[i]))
//            message[i] = code[message[i] - 'a'];
//    }
//    return message;
//}
//
////2335. 装满杯子需要的最短总时长
//
//int fillCups(int* amount, int amountSize)
//{
//    int max = fmax(amount[0], fmax(amount[1], amount[2]));
//    int all = amount[0] + amount[1] + amount[2];
//    return 2 * max > all ? max : (all + 1) / 2;
//}
//
