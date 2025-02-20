//#define _CRT_SECURE_NO_WARNINGS
//
////2595.��żλ��
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* evenOddBit(int n, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    memset(ret, 0, sizeof(int) * 2);
//    while (n)
//    {
//        int t = n & 3;
//        if (t & 1)
//            ret[0]++;
//        if (t & 2)
//            ret[1]++;
//        n >>= 2;
//    }
//    *returnSize = 2;
//    return ret;
//}
//
////1732.�ҵ���ߺ���
//
//int largestAltitude(int* gain, int gainSize)
//{
//    int altitude = 0;
//    int max = 0;
//    for (int i = 0; i < gainSize; i++)
//    {
//        altitude += gain[i];
//        if (altitude > max)
//            max = altitude;
//    }
//    return max;
//}
//
////189.��ת����
//
//// 1. ʹ�ö�������
//void rotate(int* nums, int numsSize, int k)
//{
//    int* copy = (int*)malloc(sizeof(int) * numsSize * 2);
//    for (int i = 0; i < numsSize * 2; i++)
//    {
//        copy[i] = nums[i % numsSize];
//    }
//    k = k % numsSize;
//    for (int i = numsSize - k; i < numsSize * 2 - k; i++)
//    {
//        nums[i - numsSize + k] = copy[i];
//    }
//}
//// 2. ���鷭ת
//void reverse(int* nums, int numsSize)
//{
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k)
//{
//    k = k % numsSize;
//    reverse(nums, numsSize);
//    reverse(nums, k);
//    reverse(nums + k, numsSize - k);
//}
//
////1736.�滻�������ֵõ�������ʱ��
//
//char* maximumTime(char* time)
//{
//    if (time[0] == '?')
//        time[0] = (time[1] < '4' || time[1] == '?') ? '2' : '1';
//    if (time[1] == '?')
//        time[1] = (time[0] < '2') ? '9' : '3';
//    if (time[3] == '?')
//        time[3] = '5';
//    if (time[4] == '?')
//        time[4] = '9';
//    return time;
//}
//
////2437. ��Чʱ�����Ŀ
//
//int countTime(char* time)
//{
//    int ret = 1;
//    if ((time[0] == '?') && (time[1] == '?'))
//        ret *= 24;
//    else if (time[0] == '?')
//        ret *= (time[1] < '4') ? 3 : 2;
//    else if (time[1] == '?')
//        ret *= (time[0] < '2') ? 10 : 4;
//    if (time[3] == '?')
//        ret *= 6;
//    if (time[4] == '?')
//        ret *= 10;
//    return ret;
//}
//
////3114.�滻�ַ����Եõ�������ʱ��
//
//char* findLatestTime(char* s)
//{
//    if (s[0] == '?')
//        s[0] = (s[1] < '2' || s[1] == '?') ? '1' : '0';
//    if (s[1] == '?')
//        s[1] = (s[0] < '1') ? '9' : '1';
//    if (s[3] == '?')
//        s[3] = '5';
//    if (s[4] == '?')
//        s[4] = '9';
//    return s;
//}
//
////949. ������������ɵ����ʱ��
//
//char* largestTimeFromDigits(int* arr, int arrSize)
//{
//    char* time = (char*)malloc(sizeof(char) * 6);
//    memset(time, 0, sizeof(char) * 6);
//    time[2] = ':';
//    int t = -1;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            if (i == j)
//                continue;
//            for (int k = 0; k < 4; k++)
//            {
//                if (k == j || k == i)
//                    continue;
//                int l = 6 - i - j - k;
//                //printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);
//                int hours = arr[i] * 10 + arr[j];
//                int mins = arr[k] * 10 + arr[l];
//                //printf("hours = %d, mins = %d\n", hours, mins);
//                if (hours < 24 && mins < 60)
//                {
//                    int tmp = 60 * hours + mins;
//                    t = t > tmp ? t : tmp;
//                }
//            }
//        }
//    }
//    if (t >= 0)
//    {
//        int hours = t / 60;
//        int mins = t % 60;
//        time[0] = hours / 10 + 48;
//        time[1] = hours % 10 + 48;
//        time[3] = mins / 10 + 48;
//        time[4] = mins % 10 + 48;
//    }
//    return time;
//}
//
////1560.Բ�������Ͼ���������������
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize)
//{
//    int h[n];
//    memset(h, 0, sizeof(int) * n);
//    h[rounds[0] - 1]++;
//    for (int i = 1; i < roundsSize; i++)
//    {
//        int end = rounds[i] > rounds[i - 1] ? rounds[i] : rounds[i] + n;
//        for (int j = rounds[i - 1] + 1; j <= end; j++)
//            h[(j - 1) % n]++;
//    }
//    int max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        //printf("h[%d] = %d\n", i, h[i]);
//        if (max < h[i])
//            max = h[i];
//    }
//    int* ret = (int*)malloc(sizeof(int) * n);
//    int j = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (max == h[i])
//        {
//            ret[j++] = i + 1;
//        }
//    }
//    *returnSize = j;
//    return ret;
//}
//
////1672.��пͻ����ʲ�����
//
//int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
//{
//    int m = accountsSize;
//    int n = *accountsColSize;
//    int max = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int sum = 0;
//        for (int j = 0; j < n; j++)
//            sum += accounts[i][j];
//        if (sum > max)
//            max = sum;
//    }
//    return max;
//}
//
////2114.�����е���൥����
//
//int mostWordsFound(char** sentences, int sentencesSize)
//{
//    int max = 0;
//    for (int i = 0; i < sentencesSize; i++)
//    {
//        int num = 1;
//        for (int j = 0; sentences[i][j]; j++)
//        {
//            if (sentences[i][j] == ' ')
//                num++;
//        }
//        if (num > max)
//            max = num;
//    }
//    return max;
//}
//
