////3340. ���ƽ���ַ���
//
//bool isBalanced(char* num)
//{
//    int sum = 0;
//    int sign = 1;
//    for (int i = 0; num[i] != '\0'; i++)
//    {
//        int d = num[i] - '0';
//        sum += d * sign;
//        sign = -sign;
//    }
//    return sum == 0;
//}
//
////1652. ��ը��
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* decrypt(int* code, int codeSize, int k, int* returnSize)
//{
//    returnSize[0] = codeSize;
//    int* newCode = (int*)malloc(sizeof(int) * codeSize * 2);
//    memcpy(newCode, code, sizeof(int) * codeSize);
//    memcpy(newCode + codeSize, code, sizeof(int) * codeSize);
//    int* ret = (int*)malloc(sizeof(int) * codeSize);
//    memset(ret, 0, sizeof(int) * codeSize);
//    if (k == 0)
//        return ret;
//    int l = k > 0 ? 1 : codeSize + k;
//    int r = k > 0 ? k : codeSize - 1;
//    int sum = 0;
//    for (int i = l; i <= r; i++)
//    {
//        sum += newCode[i];
//    }
//    for (int i = 0; i < codeSize; i++)
//    {
//        ret[i] = sum;
//        sum -= newCode[l];
//        sum += newCode[r + 1];
//        l++;
//        r++;
//    }
//    free(newCode);
//    return ret;
//}
//
////2515. ��Ŀ���ַ�������̾���
//
//int closestTarget(char** words, int wordsSize, char* target, int startIndex)
//{
//    int ret = -1;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (0 == strcmp(words[i], target))
//        {
//            int d = abs(startIndex - i);
//            int dmin = fmin(d, wordsSize - d);
//            ret = ret == -1 ? dmin : fmin(ret, dmin);
//        }
//    }
//    return ret;
//}
//
////2490. �ػ���
//
//bool isCircularSentence(char* sentence)
//{
//    int len = strlen(sentence);
//    if (sentence[0] != sentence[len - 1])
//        return false;
//    for (int i = 0; i < len; i++)
//    {
//        if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
//            return false;
//    }
//    return true;
//}
//
