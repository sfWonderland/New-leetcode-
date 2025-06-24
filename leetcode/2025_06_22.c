////2138. ���ַ������Ϊ���ɳ���Ϊ k ����
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** divideString(char* s, int k, char fill, int* returnSize)
//{
//    int m = strlen(s);
//    int remainder = m % k;
//    int n = m;
//    if (remainder)
//        n = m + k - remainder;
//    char* copy = (char*)malloc(sizeof(char) * (n + 1));
//    strcpy(copy, s);
//    if (remainder)
//    {
//        for (int i = m; i < n; i++)
//        {
//            copy[i] = fill;
//        }
//        copy[n] = '\0';
//    }
//    int d = n / k;
//    char** ret = (char**)malloc(sizeof(char*) * d);
//    for (int i = 0; i < d; i++)
//    {
//        ret[i] = (char*)malloc(sizeof(char) * (k + 1));
//        strncpy(ret[i], copy + i * k, k);
//        ret[i][k] = '\0';
//    }
//    *returnSize = d;
//    return ret;
//}
//
////3019. ��������Ĵ���
//
//int countKeyChanges(char* s)
//{
//    int shift = 0;
//    s[0] = tolower(s[0]);
//    for (int i = 1; s[i]; i++)
//    {
//        s[i] = tolower(s[i]);
//        if (s[i] == s[i - 1])
//            continue;
//
//        shift++;
//    }
//    return shift;
//}
//
////LCP 06. ��Ӳ��
//
//int minCount(int* coins, int coinsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < coinsSize; i++)
//    {
//        ans += (coins[i] + 1) >> 1;
//    }
//    return ans;
//}
//
////2574. ����Ԫ�غ͵Ĳ�ֵ
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* leftRightDifference(int* nums, int numsSize, int* returnSize)
//{
//    int left[numsSize], right[numsSize];
//    memset(left, 0, numsSize * sizeof(int));
//    memset(right, 0, numsSize * sizeof(int));
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        left[i + 1] = left[i] + nums[i];
//    }
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        right[i] = right[i + 1] + nums[i + 1];
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans[i] = abs(left[i] - right[i]);
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
