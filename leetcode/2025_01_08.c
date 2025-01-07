////#define _CRT_SECURE_NO_WARNINGS
////
////#include <stdio.h>
////#include <stdlib.h>
////#include <stdbool.h>
////#include <string.h>
////
//////14.最长公共前缀
////
////char* longestCommonPrefix(char** strs, int strsSize)
////{
////    int len = strlen(strs[0]);
////    int len0 = len;
////    for (int i = 1; i < strsSize; i++)
////    {
////        int tmp = strlen(strs[i]);
////        if (tmp < len)
////            len0 = tmp;
////    }
////    if (len0 < len)
////    {
////        strs[0][len0] = '\0';
////    }
////    int flag = 0;
////    //字符顺序
////    for (int i = 0; i < len0; i++)
////    {
////        //字符串顺序
////        for (int j = 1; j < strsSize; j++)
////        {
////            if (strs[j][i] != strs[0][i])
////            {
////                flag = 1;
////                break;
////            }
////        }
////        if (flag)
////        {
////            strs[0][i] = '\0';
////            break;
////        }
////    }
////    return strs[0];
////}
////
//////2996.大于等于顺序前缀的和的最小缺失整数
////
////int missingInteger(int* nums, int numsSize)
////{
////    int ret = nums[0];
////    int tmp = 0;
////    //得出顺序前缀及其和
////    for (int i = 0; i < numsSize - 1; i++)
////    {
////        if (nums[i + 1] != nums[i] + 1)
////        {
////            tmp = i;
////            break;
////        }
////        ret += nums[i + 1];
////    }
////
////    //使返回值未出现在数组中
////    for (int i = tmp; i < numsSize; i++)
////    {
////        if (ret == nums[i])
////        {
////            ret++;
////            i = tmp;
////        }
////    }
////    return ret;
////}
////
//////202.快乐数
////
////int happy_num(int n)
////{
////    int cul = 0;
////    while (n)
////    {
////        cul += (n % 10) * (n % 10);
////        n /= 10;
////    }
////    return cul;
////}
////
////bool isHappy(int n)
////{
////    if (n == 1)
////        return true;
////    else
////    {
////        while (n != 1)
////        {
////            n = happy_num(n);
////            if (n == 89)
////                break;
////        }
////        if (1 == n)
////            return true;
////        else
////            return false;
////    }
////}
////
//////258.各位相加
////
////int plus_num(int n)
////{
////    int cul = 0;
////    while (n)
////    {
////        cul += n % 10;
////        n /= 10;
////    }
////    return cul;
////}
////
////int addDigits(int num)
////{
////    while (num > 9)
////    {
////        num = plus_num(num);
////        if (num <= 9)
////            break;
////    }
////    return num;
////}
////
//////1945.字符串转化后的各位数字之和
////
////int plus_num(int n)
////{
////    int cul = 0;
////    while (n)
////    {
////        cul += n % 10;
////        n /= 10;
////    }
////    return cul;
////}
////int getLucky(char* s, int k) 
////{
////    int ret = 0;
////    int len = strlen(s);
////    //至少转换一次
////    for (int i = 0; i < len; i++)
////    {
////        ret += plus_num(s[i] - 96);
////    }
////
////    //继续转换
////    if (ret > 9 && k > 1)
////    {
////        for (int i = 1; i < k; i++)
////        {
////            ret = plus_num(ret);
////            //小于10直接退出循环
////            if (ret <= 9)
////            {
////                break;
////            }
////        }
////    }
////    return ret;
////}
////
//////263.丑数
////
////bool exact_div(int n, int m)
////{
////    if (n % m == 0)
////        return true;
////    else
////        return false;
////}
////bool isUgly(int n)
////{
////    if (n <= 0)
////        return false;
////    else
////    {
////        int flag = 0;
////        while (n != 1)
////        {
////            if (exact_div(n, 2) || exact_div(n, 3) || exact_div(n, 5))
////            {
////                if (exact_div(n, 2))
////                    n /= 2;
////                if (exact_div(n, 3))
////                    n /= 3;
////                if (exact_div(n, 5))
////                    n /= 5;
////            }
////            else
////                break;
////        }
////        if (n != 1)
////            return false;
////        else
////            return true;
////    }
////}
////
//////2180.统计各位数字之和为偶数的的整数个数
////
////int plus_num(int n)
////{
////    int cul = 0;
////    while (n)
////    {
////        cul += n % 10;
////        n /= 10;
////    }
////    return cul;
////}
////int countEven(int num)
////{
////    int count = 0;
////    for (int i = 2; i <= num; i++)
////    {
////        if (plus_num(i) % 2 == 0)
////        {
////            count++;
////        }
////    }
////    return count;
////}
//
//#include <stdio.h>
//#include <math.h>
//int get_prime(int i)
//{
//	if (0 == i % 2)
//		return 0;
//	int j;
//	for (j = 3; j <= sqrt(i); j += 2)
//	{
//		if (0 == i % j)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i = 101;
//	for (i = 101; i <= 199; i += 2)
//	{
//		int prime = get_prime(i);
//		if (prime)
//			printf("%d ", i);
//	}
//	return 0;
//}
//
////204.计数质数
//
//int countPrimes(int n) {
//    //埃拉托色尼筛法 (Sieve of Eratosthenes)
//    if (n <= 2)
//        return 0;
//    else
//    {
//        //涂满色
//        int arr[n - 2];
//        //2~n-1
//        for (int i = 0; i < n - 2; i++)
//        {
//            arr[i] = 1;
//        }
//        //去掉合数的色
//        //2~n-1
//        for (int i = 2; i < sqrt(n); i++)
//        {
//            if (arr[i - 2])
//            {
//                for (int j = i * i; j < n; j += i)
//                {
//                    arr[j - 2] = 0;
//                    //printf("false: %d\n", j);
//                }
//            }
//        }
//        int count = 0;
//        for (int i = 0; i < n - 2; i++)
//        {
//            if (arr[i])
//            {
//                count++;
//            }
//        }
//        return count;
//    }
//}
//
////2427.公因子的数目
//
//int commonFactors(int a, int b)
//{
//    if (a < b)
//    {
//        int tmp = a;
//        a = b;
//        b = tmp;
//    }
//    int count = 0;
//    for (int i = 1; i <= b; i++)
//    {
//        if ((!(a % i)) && (!(b % i)))
//            count++;
//    }
//    return count;
//}
//
////2240.买钢笔和铅笔的方案数
//
//void cost_line(int* cost1, int* cost2)
//{
//    if (*cost1 < *cost2)
//    {
//        int tmp = *cost1;
//        *cost1 = *cost2;
//        *cost2 = tmp;
//    }
//}
//long long waysToBuyPensPencils(int total, int cost1, int cost2) {
//    cost_line(&cost1, &cost2);
//    long long  count = 0;
//    //钢笔的价格和铅笔的成比例，钱与贵者价格成比例
//    if (0 == cost1 % cost2 && 0 == total % cost1)
//    {
//        //能买的便宜笔数量*（能买的贵笔数量 + 1）/ 2 + （能买的贵笔数量 + 1）
//        count = (long long)(total / cost2 + 2) * (total / cost1 + 1) / 2;
//    }
//    else
//    {
//        //i：钢笔数
//        for (int i = 0; i <= total / cost1; i++)
//        {
//            count += (total - i * cost1) / cost2 + 1;
//        }
//    }
//    return count;
//}
//
////264.丑数II
//
//int min(int a, int b)
//{
//    if (a > b)
//        return b;
//    else
//        return a;
//}
//int nthUglyNumber(int n)
//{
//    int ugly[1690];
//    ugly[0] = 1;
//    int i2 = 0;
//    int i3 = 0;
//    int i5 = 0;
//    for (int i = 1; i < n; i++)
//    {
//        int l2 = ugly[i2] * 2;
//        int l3 = ugly[i3] * 3;
//        int l5 = ugly[i5] * 5;
//        ugly[i] = min(min(l2, l3), l5);
//        if (ugly[i] == l2) i2++;
//        if (ugly[i] == l3) i3++;
//        if (ugly[i] == l5) i5++;
//    }
//    return ugly[n - 1];
//}
