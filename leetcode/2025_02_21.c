////1018.�ɱ�5�����Ķ�����ǰ׺
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize)
//{
//    bool* ret = (bool*)malloc(sizeof(bool) * numsSize);
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n = (n * 2 + nums[i]) % 5;
//        ret[i] = (0 == n);
//    }
//    *returnSize = numsSize;
//    return ret;
//}
//
////728.�Գ���
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * (right - left + 1));
//    int j = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int n = i;
//        int flag = 1;
//        while (n)
//        {
//            int remainder = n % 10;
//            if (0 == remainder || i % remainder)
//            {
//                flag = 0;
//                break;
//            }
//            n /= 10;
//        }
//        if (flag)
//            ret[j++] = i;
//    }
//    *returnSize = j;
//    return ret;
//}
//
////2283.�ж�һ���������ּ����Ƿ������λ��ֵ
//
//bool digitCount(char* num)
//{
//    int hash[11] = { 0 };
//    for (int i = 0; num[i]; i++)
//    {
//        hash[num[i] - '0']++;
//    }
//    for (int i = 0; num[i]; i++)
//    {
//        if (hash[i] + '0' != num[i])
//            return false;
//    }
//    return true;
//}
//
////2520.ͳ�����������ֵ�λ��
//
//int countDigits(int num)
//{
//    int ret = 0;
//    int n = num;
//    while (n)
//    {
//        if (0 == num % (n % 10))
//            ret++;
//        n /= 10;
//    }
//    return ret;
//}
//
////2457.������������С����
//
//int digitSum(long long n)
//{
//    int sum = 0;
//    while (n)
//    {
//        sum += n % 10;
//        n /= 10;
//    }
//    return sum;
//}
//long long makeIntegerBeautiful(long long n, int target)
//{
//    long long ret = 0;
//    long long factor = 10;
//    long long num = n;
//    while (digitSum(num) > target)
//    {
//        while (0 == num % factor)
//            factor *= 10;
//
//        num = (num / factor + 1) * factor;
//        ret = num - n;
//    }
//    return ret;
//}
//
////2507.ʹ��������֮���滻�����ȡ������Сֵ
//
//int smallestValue(int n)
//{
//    // n -> 2 + n / 2 ���ֵ
//    while (1)
//    {
//        int sum = 0;
//        int x = n;
//        for (int i = 2; i * i <= n; i++)
//        {
//            while (0 == (x % i))
//            {
//                sum += i;
//                x /= i;
//            }
//        }
//        if (x > 1)
//            sum += x;
//
//        if (n == sum)
//            return sum;
//
//        n = sum;
//    }
//    return -1;
//}
