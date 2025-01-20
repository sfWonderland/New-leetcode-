#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

////495.提莫攻击
//
//int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
//{
//    int left = 0;
//    int right = -1;
//    int total = 0;
//    for (int i = 0; i < timeSeriesSize; i++)
//    {
//        left = timeSeries[i];
//        total += duration;
//        if (right >= left)
//            total += left - right - 1;
//        right = left + duration - 1;
//    }
//    return total;
//}
//
////605.种花问题
//bool MayPlaceFlowers(int* flowerbed, int x, int flowerbedSize)
//{
//    //flowerbedSize must be bigger than 1;
//    if (0 == x)
//    {
//        if (flowerbed[1] != 1)
//        {
//            flowerbed[0] = 1;
//            return true;
//        }
//        else
//            return false;
//    }
//    else if (flowerbedSize - 1 == x)
//    {
//        if (flowerbed[flowerbedSize - 2] != 1)
//        {
//            flowerbed[flowerbedSize - 1] = 1;
//            return true;
//        }
//        else
//            return false;
//    }
//    else
//    {
//        if ((flowerbed[x - 1] != 1) && (flowerbed[x + 1] != 1))
//        {
//            flowerbed[x] = 1;
//            return true;
//        }
//        else
//            return false;
//    }
//}
//bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
//{
//    //rough exclude
//    int sum = 0;
//    for (int i = 0; i < flowerbedSize; i++)
//    {
//        sum += flowerbed[i];
//    }
//    if (flowerbedSize < 2 * sum + 2 * n - 2)
//        return false;
//    else
//    {
//        if (1 == flowerbedSize)
//            return true;
//        sum = 0;
//        for (int i = 0; i < flowerbedSize; i++)
//        {
//            if (!flowerbed[i])
//                sum += MayPlaceFlowers(flowerbed, i, flowerbedSize);
//            //printf("i = %d, sum = %d\n", i, sum);
//        }
//        // for(int i = 0; i < flowerbedSize; i++)
//        // {
//        //     printf("%d ",flowerbed[i]);
//        // }
//        return (sum >= n) ? true : false;
//    }
//}
//


// 649.Dota2 参议院

//char* predictPartyVictory(char* senate)
//{
//    int n = strlen(senate);
//
//    int radiant[n];
//    int left_r = 0;
//    int right_r = 0;
//
//    int dire[n];
//    int left_d = 0;
//    int right_d = 0;
//
//    //
//    for (int i = 0; i < n; i++)
//    {
//        if ('R' == senate[i])
//            radiant[right_r++] = i;
//        else
//            dire[right_d++] = i;
//    }
//
//    //原理：左对齐排序比较，次序靠前者继续下一轮，靠后者退出，直至一方所有参议员退出，
//    //这相当于把退出者的权利给胜利者下一次
//    //胜利者一方的数组内整型个数一定与总字符数相等，而失败的一方被淘汰所有参议员
//    //最终一定是赢方right = n, 输方left = right。
//    while (left_r < right_r && left_d < right_d)
//    {
//        if (radiant[left_r] < dire[left_d])
//            radiant[right_r++] = radiant[left_r] + n;
//        else
//            dire[right_d++] = dire[left_d] + n;
//        left_r++;
//        left_d++;
//    }
//
//    //
//    return left_r < right_r ? "Radiant" : "Dire";
//}