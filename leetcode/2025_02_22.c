////2455.可被三整除的偶数的平均值
//
//int averageValue(int* nums, int numsSize)
//{
//    int sum = 0;
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (0 == nums[i] % 6)
//        {
//            sum += nums[i];
//            n++;
//        }
//    }
//    return n ? sum / n : 0;
//}
//
////2644.找出可整除性得分最大的整数
//
//int cmp1(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxDivScore(int* nums, int numsSize, int* divisors, int divisorsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp1);
//    int dup = 0;
//    int maxNum = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] == nums[i - 1] && nums[i] >= maxNum)
//        {
//            dup++;
//            maxNum = nums[i];
//        }
//    }
//    qsort(divisors, divisorsSize, sizeof(int), cmp2);
//    int d[divisorsSize];
//    int dSize = 1;
//    d[0] = divisors[0];
//    for (int i = 1; i < divisorsSize; i++)
//    {
//        if (divisors[i] != divisors[i - 1])
//            d[dSize++] = divisors[i];
//    }
//    int max = -1;
//    int ret = INT_MAX;
//    for (int i = 0; i < dSize; i++)
//    {
//        if (max - dup >= nums[0] / d[i])
//            // 剪枝2： 后继再找不到更合适的
//            break;
//        int n = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (d[i] > nums[j])
//                // 剪枝1： 小于divisor的num无法被整除
//                break;
//            if (0 == nums[j] % d[i])
//                n++;
//        }
//        if (max < n)
//        {
//            max = n;
//            ret = d[i];
//        }
//        else if (max == n)
//            ret = ret < d[i] ? ret : d[i];
//    }
//    return ret;
//}
//
////66.加一
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
// // int* plusOne(int* digits, int digitsSize, int* returnSize) 
// // {
// //     int n = digitsSize - 1;
// //     while(n >= 0 && digits[n] == 9)
// //     {
// //         digits[n] = 0;
// //         n--;
// //     }
//
// //     *returnSize = digitsSize;
// //     if(n >= 0)
// //     {
// //         digits[n]++;
// //         return digits;
// //     }
//
// //     (*returnSize)++;
// //     int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
// //     memset(ret, 0, sizeof(int) * (digitsSize + 1));
// //     ret[0] = 1;
// //     return ret;
//
// // }
//
//int* plusOne(int* digits, int digitsSize, int* returnSize)
//{
//    int n = digitsSize;
//    *returnSize = digitsSize;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (digits[i] != 9)
//        {
//            digits[i]++;
//            for (int j = i + 1; j < n; j++)
//                digits[j] = 0;
//            return digits;
//        }
//    }
//
//    (*returnSize)++;
//    int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
//    memset(ret, 0, sizeof(int) * (digitsSize + 1));
//    ret[0] = 1;
//    return ret;
//
//}
//
////67.二进制求和
//
//char* addBinary(char* a, char* b)
//{
//    int x = strlen(a);
//    int y = strlen(b);
//    int len = 2 + (x > y ? x : y);
//    char* ret = (char*)malloc(sizeof(char) * len);
//    ret[len - 1] = '\0';
//    int i = x - 1;
//    int j = y - 1;
//    int k = len - 2;
//    int c = 0;
//    while (i >= 0 || j >= 0)
//    {
//        int a_bit = i >= 0 ? a[i--] - '0' : 0;
//        int b_bit = j >= 0 ? b[j--] - '0' : 0;
//        int bit_sum = a_bit + b_bit + c;
//
//        ret[k--] = bit_sum % 2 + '0';
//        c = bit_sum >> 1;
//    }
//
//    if (c)
//        ret[k] = '1';
//
//    return ret[0] == '1' ? ret : ret + 1;
//}
