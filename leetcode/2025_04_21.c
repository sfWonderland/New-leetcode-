////2145. 统计隐藏数组数目
//
//int numberOfArrays(int* differences, int differencesSize, int lower, int upper)
//{
//    int sum = 0, max = 0, min = 0;
//    for (int i = 0; i < differencesSize; i++)
//    {
//        sum += differences[i];
//        max = max < sum ? sum : max;
//        min = min > sum ? sum : min;
//        if (max - min > upper - lower)
//            return 0;
//    }
//    return (upper - lower) - (max - min) + 1;
//}
//
////500. 键盘行
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** findWords(char** words, int wordsSize, int* returnSize)
//{
//    int hash[26] = { 1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2 };
//    char** result = (char**)malloc(sizeof(char*) * wordsSize);
//    returnSize[0] = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int key = hash[tolower(words[i][0]) - 'a'];
//        int flag = 0;
//        for (int j = 1; words[i][j]; j++)
//        {
//            if (hash[tolower(words[i][j]) - 'a'] != key)
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag)
//            continue;
//        result[*returnSize] = (char*)malloc(strlen(words[i]) + 1);
//        strcpy(result[*returnSize], words[i]);
//        (*returnSize)++;
//    }
//    return result;
//}
//
////1507. 转变日期格式
//
//char* reformatDate(char* date)
//{
//    char* ret = (char*)malloc(sizeof(char) * 11);
//    ret[10] = '\0';
//    ret[4] = '-';
//    ret[7] = '-';
//    int flag = 0;
//    if (isdigit(date[1]))
//    {
//        ret[8] = date[0];
//        ret[9] = date[1];
//        flag = 1;
//    }
//    else
//    {
//        ret[8] = '0';
//        ret[9] = date[0];
//    }
//    switch (date[4 + flag])
//    {
//    case 'A': ret[5] = '0'; if (date[5 + flag] == 'p')ret[6] = '4'; else ret[6] = '8'; break;
//    case 'D': ret[5] = '1'; ret[6] = '2'; break;
//    case 'F': ret[5] = '0'; ret[6] = '2'; break;
//    case 'J': ret[5] = '0'; if (date[5 + flag] == 'a')ret[6] = '1'; else if (date[6 + flag] == 'n')ret[6] = '6'; else ret[6] = '7'; break;
//    case 'M': ret[5] = '0'; if (date[6 + flag] == 'r')ret[6] = '3'; else ret[6] = '5'; break;
//    case 'N': ret[5] = '1'; ret[6] = '1'; break;
//    case 'O': ret[5] = '1'; ret[6] = '0'; break;
//    case 'S': ret[5] = '0'; ret[6] = '9'; break;
//    }
//    for (int i = flag + 8; date[i]; i++)
//    {
//        ret[i - flag - 8] = date[i];
//    }
//    return ret;
//}
//
////2535. 数组元素和与数字和的绝对差
//
//int differenceOfSum(int* nums, int numsSize)
//{
//    int x = 0;
//    int y = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        x += nums[i];
//        int t = nums[i];
//        while (t)
//        {
//            y += t % 10;
//            t /= 10;
//        }
//    }
//    return x - y;
//}
//
