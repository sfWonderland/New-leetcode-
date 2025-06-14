////1432. 改变一个整数能得到的最大差值
//
//int maxDiff(int num)
//{
//    char s[16], t[16];
//    sprintf(s, "%d", num);
//    strcpy(t, s);
//
//    int pos = 0;
//    if (s[0] == '1')
//    {
//        pos++;
//        while (s[pos] && (s[pos] == '0' || s[pos] == '1'))
//            pos++;
//    }
//    if (s[pos])
//    {
//        char ch = s[pos];
//        for (int i = 0; s[i]; i++)
//        {
//            if (s[i] == ch)
//                s[i] = (pos > 0) ? '0' : '1';
//        }
//    }
//
//    pos = 0;
//    while (t[pos] && t[pos] == '9')
//        pos++;
//    if (t[pos])
//    {
//        char ch = t[pos];
//        for (int i = 0; t[i]; i++)
//        {
//            if (t[i] == ch)
//                t[i] = '9';
//        }
//    }
//    printf("%d %d", atoi(t), atoi(s));
//    return atoi(t) - atoi(s);
//}
//
////2275. 按位与结果大于零的最长组合
//
//int largestCombination(int* candidates, int candidatesSize)
//{
//    int cnt[24] = { 0 };
//    for (int i = 0; i < candidatesSize; i++)
//    {
//        int n = 0;
//        while (candidates[i])
//        {
//            cnt[n++] += candidates[i] & 1;
//            candidates[i] >>= 1;
//        }
//    }
//    int max = 0;
//    for (int i = 0; i < 24; i++)
//    {
//        max = fmax(max, cnt[i]);
//    }
//    return max;
//}
//
////2571. 将整数减少到零需要的最少操作数
//
//int minOperations(int n)
//{
//    int ans = 0;
//    while (n)
//    {
//        while (0 == (n & 1))
//            n >>= 1;
//        //printf("%d\n", n);
//        if ((n & 3) == 3)
//        {
//            n++;
//            ans++;
//        }
//        else
//        {
//            n >>= 1;
//            ans++;
//        }
//        //printf("%d\n", n);
//    }
//    return ans;
//}
//
////645. 错误的集合
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findErrorNums(int* nums, int numsSize, int* returnSize)
//{
//    int xor = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        xor ^= (1 + i) ^ nums[i];
//    }
//    //printf("%d\n", xor);
//    int lowBit = xor &(-xor);
//    //printf("%d\n", lowBit);
//    int num1 = 0, num2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if ((i + 1) & lowBit)
//            num1 ^= i + 1;
//        else
//            num2 ^= i + 1;
//
//        if (nums[i] & lowBit)
//            num1 ^= nums[i];
//        else
//            num2 ^= nums[i];
//    }
//    //printf("%d\n", num1);
//    //printf("%d\n", num2);
//    *returnSize = 2;
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = num1, ret[1] = num2;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == num1)
//            return ret;
//    }
//
//    ret[0] = num2, ret[1] = num1;
//    return ret;
//}
//
