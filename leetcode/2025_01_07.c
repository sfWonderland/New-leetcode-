//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//
//
////171.EXCEL �������
//
//int titleToNumber(char* columnTitle)
//{
//    int len = strlen(columnTitle);
//    int ret = 0;
//    for (int i = 0; i < len; i++)
//    {
//        ret *= 26;
//        ret += columnTitle[i] - 64;
//    }
//    return ret;
//}
//
////190.�ߵ�������λ
//
//unsigned int reverseBits(unsigned int n)
//{
//    unsigned int ret = 0;
//    unsigned int tmp = 0;
//    for (int i = 0; i < 16; i++)
//    {
//        tmp = (n >> i) & 1;
//        tmp <<= (31 - i);
//        ret += tmp;
//        tmp = (n >> (31 - i)) & 1;
//        tmp <<= i;
//        ret += tmp;
//    }
//
//    return ret;
//}
//
////191.λ1�ĸ���
//
//int hammingWeight(int n)
//{
//    int ret = 0;
//    while (n)
//    {
//        if (n & 1)
//            ret++;
//        n >>= 1;
//    }
//    return ret;
//}
//
//int hammingWeight(int n)
//{
//    int ret = 0;
//    while (n)
//    {
//        n &= (n - 1);
//        ret++;
//    }
//    return ret;
//}
//
////231.2����
//
//bool isPowerOfTwo(int n)
//{
//    if (n == 0x80000000)
//        return false;
//    if (!n)
//        return false;
//    if (!(n & (n - 1)))
//        return true;
//    else
//        return false;
//}
//
////326.3����
//
//bool isPowerOfThree(int n)
//{
//    if (n <= 0)
//        return false;
//    if (!(0x4546B3DB % n))
//        return true;
//    else
//        return false;
//}
//
////342.4����
//
//bool isPowerOfFour(int n)
//{
//    if (n <= 0)
//        return false;
//    if (n & (n - 1))
//        return false;
//    if (n & 0x55555555)
//        return true;
//    else
//        return false;
//}
//
////1780. �ж�һ�������Ƿ���Ա�ʾ�������ݵĺ�
//
//bool checkPowersOfThree(int n)
//{
//    int ret = 1;
//    int tmp = 4782969;
//    while (n < tmp)
//    {
//        tmp /= 3;
//    }
//    while (n)
//    {
//        if (n / tmp == 2)
//        {
//            ret = 0;
//            break;
//        }
//        else
//        {
//            n %= tmp;
//            tmp /= 3;
//        }
//    }
//    return ret;
//}
//
////2859.����K��λ�±��ӦԪ�صĺ�
//
//int sumIndicesWithKSetBits(int* nums, int numsSize, int k) 
//{
//    if (!k)
//        return nums[0];
//    int ret = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        int k_t = k;
//        int i_t = i;
//        while (k_t - 1)
//        {
//            i_t &= i_t - 1;
//            if (!i_t)
//                break;
//            k_t--;
//        }
//        if ((1 == k_t) && (!(i_t & (i_t - 1))))
//            ret += nums[i];
//    }
//    return ret;
//}
//
////2119. ��ת���ε�����
//
//bool isSameAfterReversals(int num)
//{
//    if (!num)
//        return true;
//    else if (num % 10)
//        return true;
//    else
//        return false;
//}
//
////2917. �ҳ������е� K-or ֵ
//
//int findKOr(int* nums, int numsSize, int k)
//{
//    int ret = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        int t = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            t += (nums[j] >> i) & 1;
//        }
//        if (t >= k)
//            ret += 1 << i;
//    }
//    return ret;
//}
//
//
//