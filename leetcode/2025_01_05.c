#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

////70.爬楼梯
//int climbStairs(int n) 
//{
//    int a = 0;
//    int b = 0;
//    int ret = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (0 == i)
//            ret = 1;
//        else if (1 == i)
//            ret = 2;
//        else
//        {
//            ret = a + b;
//        }
//        b = a;
//        a = ret;
//    }
//    return ret;
//}
//
////746.使用最短花费爬楼梯
//
//int minCostClimbingStairs(int* cost, int costSize) 
//{
//    int dp[1000] = { 0 };
//    int min = 0;
//    for (int i = costSize - 1; i >= 0; i--)
//    {
//        if (i < costSize - 1)
//            min = dp[i + 1] > dp[i + 2] ? dp[i + 2] : dp[i + 1];
//        //printf("min = %d\n", min);
//        dp[i] = cost[i] + min;
//        //printf("dp[%d] = %d\n", i, dp[i]);
//    }
//    //printf("dp[0] = %d, dp[1] = %d\n", dp[0], dp[1]);
//    return (dp[0] > dp[1]) ? dp[1] : dp[0];
//}
//
////509. 斐波那契数
//
//int fib(int n) {
//    int a = 0;
//    int b = 0;
//    int ret = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        b = a;
//        a = ret;
//        if (i <= 1)
//            ret = i;
//        else
//            ret = a + b;
//    }
//    return ret;
//}
//
////1137.第N个泰波那契数
//
//int tribonacci(int n) {
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    int ret = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        c = b;
//        b = a;
//        a = ret;
//        if (i <= 1)
//            ret = i;
//        else
//            ret = a + b + c;
//    }
//    return ret;
//}
//
////88. 合并两个有序数组
//
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
//{
//    while (m && n)
//    {
//        if (nums1[m - 1] > nums2[n - 1])
//        {
//            nums1[m + n - 1] = nums1[m - 1];
//            m--;
//        }
//        else
//        {
//            nums1[m + n - 1] = nums2[n - 1];
//            n--;
//        }
//    }
//    while (n)
//    {
//        nums1[n - 1] = nums2[n - 1];
//        //printf("num1[%d] = %d\n", n - 1, nums1[n - 1]);
//        n--;
//    }
//}