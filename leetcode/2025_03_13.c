////1903. 字符串中的最大奇数
//
//char* largestOddNumber(char* num)
//{
//    int len = strlen(num);
//    int i = len - 1;
//    for (; i > -1; i--)
//    {
//        if ((num[i] - '0') % 2)
//            break;
//    }
//    num[i + 1] = '\0';
//    return num;
//}
//
////2264. 字符串中最大的 3 位相同数字
//
//char* largestGoodInteger(char* num)
//{
//    char s = '\0';
//    int cnt = 1;
//    for (int i = 1; num[i]; i++)
//    {
//        if (num[i] == num[i - 1])
//        {
//            if (cnt < 2)
//                cnt++;
//            else
//            {
//                s = fmax(s, num[i]);
//                cnt = 1;
//            }
//        }
//        else
//            cnt = 1;
//    }
//    char* ret = (char*)malloc(sizeof(char) * 4);
//    memset(ret, s, sizeof(char) * 3);
//    ret[3] = '\0';
//    return ret;
//}
//
////1897. 重新分配字符使所有字符串都相等
//
//bool makeEqual(char** words, int wordsSize)
//{
//    int alpha[26] = { 0 };
//    for (int i = 0; i < wordsSize; i++)
//    {
//        for (int j = 0; words[i][j]; j++)
//        {
//            alpha[words[i][j] - 'a']++;
//        }
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (alpha[i] % wordsSize)
//            return false;
//    }
//    return true;
//}
//
////1893. 检查是否区域内所有整数都被覆盖
//
//bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right)
//{
//    int row = rangesSize;
//    int delta[52] = { 0 }; // 差分数组
//    for (int i = 0; i < row; i++)
//    {
//        delta[ranges[i][0]]++;
//        delta[ranges[i][1] + 1]--;
//    }
//    // 前缀和
//    int cnt = 0;
//    for (int i = 0; i <= right; i++)
//    {
//        cnt += delta[i];
//        if (i >= left && 0 == cnt)
//            return false;
//    }
//    return true;
//}
//
