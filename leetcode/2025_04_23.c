////3185. 构成整天的下标对数目 II
//
//long long countCompleteDayPairs(int* hours, int hoursSize)
//{
//    int hash[24] = { 0 };
//    long long ret = 0;
//    for (int i = 0; i < hoursSize; i++)
//    {
//        ret += hash[(24 - hours[i] % 24) % 24];
//        hash[hours[i] % 24]++;
//    }
//    return ret;
//}
//
////412. Fizz Buzz
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char** fizzBuzz(int n, int* returnSize)
//{
//    char** ret = (char**)malloc(sizeof(char*) * n);
//    for (int i = 1; i <= n; i++)
//    {
//        if (i % 3 == 0 && i % 5 == 0)
//        {
//            ret[i - 1] = (char*)malloc(sizeof(char) * 9);
//            ret[i - 1] = "FizzBuzz";
//        }
//        else if (i % 3 == 0)
//        {
//            ret[i - 1] = (char*)malloc(sizeof(char) * 5);
//            ret[i - 1] = "Fizz";
//        }
//        else if (i % 5 == 0)
//        {
//            ret[i - 1] = (char*)malloc(sizeof(char) * 5);
//            ret[i - 1] = "Buzz";
//        }
//        else
//        {
//            ret[i - 1] = (char*)malloc(sizeof(char) * 6);
//            int t = i;
//            int j = 0;
//            while (t)
//            {
//                ret[i - 1][j] = t % 10 + '0';
//                t /= 10;
//                j++;
//            }
//            ret[i - 1][j] = '\0';
//            reverse(ret[i - 1], 0, j - 1);
//        }
//    }
//    *returnSize = n;
//    return ret;
//}
//
////415. 字符串相加
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* addStrings(char* num1, char* num2)
//{
//    int len1 = strlen(num1);
//    int len2 = strlen(num2);
//    char* ret = (char*)malloc(sizeof(char) * fmax(len1 + 2, len2 + 2));
//    int upgrade = 0;
//    int i = 0;
//    for (; len1 - i > 0 && len2 - i > 0; i++)
//    {
//        int t = num1[len1 - i - 1] + num2[len2 - i - 1] + upgrade - 2 * '0';
//        //printf("%d ", t);
//        ret[i] = t % 10 + '0';
//        upgrade = t / 10;
//    }
//    while (len1 - i > 0)
//    {
//        int t = num1[len1 - i - 1] + upgrade - '0';
//        //printf("%d ", t);
//        ret[i++] = t % 10 + '0';
//        upgrade = t / 10;
//    }
//    while (len2 - i > 0)
//    {
//        int t = num2[len2 - i - 1] + upgrade - '0';
//        //printf("%d ", t);
//        ret[i++] = t % 10 + '0';
//        upgrade = t / 10;
//    }
//    if (upgrade)
//    {
//        i++;
//        ret[i - 1] = '1';
//        ret[i] = '\0';
//    }
//    else
//        ret[i] = '\0';
//    reverse(ret, 0, i - 1);
//    return ret;
//}
//
////3512. 使数组和能被 K 整除的最少操作次数
//
//int minOperations(int* nums, int numsSize, int k)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        sum %= k;
//    }
//    return sum;
//}
//
