//#define _CRT_SECURE_NO_WARNINGS
//
////1760.袋子里最少数目的球
//
////如果我们知道一个袋子的最大尺寸，那么让我们改变这个问题——你能制作的最小袋子数量是多少
////请注意，随着最大尺寸的增加，最小行李数量减少，因此我们可以对最大尺寸进行二分查找
//int minimumSize(int* nums, int numsSize, int maxOperations)
//{
//    //最大值
//    int max = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (max < nums[i])
//            max = nums[i];
//    }
//
//    //二分法计算
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long n = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < numsSize; i++)
//        {
//            //操作数计算，向下取整
//            if (nums[i] > mid)
//                n += (nums[i] - 1) / mid;
//        }
//        //大于操作数调整下限，反之调整上限
//        if (n > maxOperations)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////2064.分配给商店的最多商品的最小值
//
//int minimizedMaximum(int n, int* quantities, int quantitiesSize)
//{
//    //最大值
//    int max = quantities[0];
//    for (int i = 1; i < quantitiesSize; i++)
//    {
//        if (max < quantities[i])
//            max = quantities[i];
//    }
//
//    //二分法计算
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < quantitiesSize; i++)
//        {
//            //操作数计算，向下取整
//            if (quantities[i] > mid)
//                num += (quantities[i] - 1) / mid;
//        }
//        //大于操作数调整下限，反之调整上限
//        if (num > n - quantitiesSize)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////875.爱吃香蕉的珂珂
//
//int minEatingSpeed(int* piles, int pilesSize, int h)
//{
//    //最大值
//    int max = piles[0];
//    for (int i = 1; i < pilesSize; i++)
//    {
//        if (max < piles[i])
//            max = piles[i];
//    }
//
//    //二分法计算
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < pilesSize; i++)
//        {
//            //操作数计算，向上取整
//            num += (piles[i] - 1 + mid) / mid;
//        }
//        //大于操作数调整下限，反之调整上限
//        if (num > h)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////1011.在D天内送达包裹的能力
//
//int shipWithinDays(int* weights, int weightsSize, int days)
//{
//    //最大值
//    int max = weights[0];
//    int min = weights[0];
//    for (int i = 1; i < weightsSize; i++)
//    {
//        max += weights[i];
//        if (min < weights[i])
//            min = weights[i];
//    }
//
//    //二分法计算
//    int ret = min;
//    while (min <= max)
//    {
//        int mid = min + ((max - min) >> 1);
//        int num = 1;
//        int sum = 0;
//        for (int i = 0; i < weightsSize; i++)
//        {
//            //操作数计算，满一船就换船
//            if (sum + weights[i] > mid)
//            {
//                sum = 0;
//                num++;
//            }
//            sum += weights[i];
//        }
//        //大于操作数调整下限，反之调整上限
//        if (num > days)
//            min = mid + 1;
//        else
//        {
//            max = mid - 1;
//            ret = mid;
//        }
//    }
//
//    return ret;
//}
//
////2226.每个小孩最多能分到多少糖果
//
//int maximumCandies(int* candies, int candiesSize, long long k)
//{
//    //最大值
//    int max = candies[0];
//    for (int i = 1; i < candiesSize; i++)
//    {
//        if (max < candies[i])
//            max = candies[i];
//    }
//
//    //二分法计算
//    int min = 1;
//    int ret = 0;
//    while (min <= max)
//    {
//        long long num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < candiesSize; i++)
//        {
//            //操作数计算，向下取整
//            if (candies[i] >= mid)
//                num += candies[i] / mid;
//        }
//        //大于操作数调整下限，反之调整上限
//        if (num >= k)
//        {
//            min = mid + 1;
//            ret = mid;
//        }
//        else
//            max = mid - 1;
//    }
//
//    return ret;
//}
//
////1870.准时到达的列车最小时速
//
//#define TIMES 100
//int minSpeedOnTime(int* dist, int distSize, double hour)
//{
//    long long h = llround(hour * TIMES);
//    //最快车速能否能到达
//    if (h <= (distSize - 1) * TIMES)
//        return -1;
//    //二分法计算
//    int min = 1;
//    int max = 10000000;
//    while (min <= max)
//    {
//        double num = 0;
//        int mid = min + ((max - min) >> 1);
//        for (int i = 0; i < distSize - 1; i++)
//        {
//            //操作数计算，向上取整
//            num += (dist[i] + mid - 1) / mid;
//        }
//        num *= mid;
//        num += dist[distSize - 1];
//        //大于操作数调整下限，反之调整上限
//        if (num * TIMES > h * mid)
//            min = mid + 1;
//        else
//            max = mid - 1;
//    }
//
//    return min;
//}
//
////2187.完成旅途的最少时间 
//
//long long minimumTime(int* time, int timeSize, int totalTrips)
//{
//    long long max = time[0];
//    for (int i = 1; i < timeSize; i++)
//    {
//        if (time[i] < max)
//            max = time[i];
//    }
//    max *= totalTrips;
//    //二分法计算
//    long long min = 1;
//    while (min < max)
//    {
//        long long num = 0;
//        long long mid = min + ((max - min) >> 1);
//        for (int i = 0; i < timeSize; i++)
//        {
//            //操作数计算，向下取整
//            num += mid / time[i];
//        }
//        //大于等于操作数调整上限，反之调整下限
//        if (num >= totalTrips)
//            max = mid;
//        else
//            min = mid + 1;
//    }
//
//    return min;
//}
//
////1103.分糖果
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* distributeCandies(int candies, int num_people, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * num_people);
//    memset(ans, 0, sizeof(int) * num_people);
//    for (int i = 0; ; i++)
//    {
//        if (candies >= i + 1)
//        {
//            ans[i % num_people] += i + 1;
//            candies -= i + 1;
//        }
//        else
//        {
//            ans[i % num_people] += candies;
//            break;
//        }
//    }
//
//    *returnSize = num_people;
//    return ans;
//}
//
//int* distributeCandies(int candies, int num_people, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * num_people);
//    memset(ans, 0, sizeof(int) * num_people);
//    //按规矩给糖
//    int n = (int)(sqrt(2 * candies + 0.25) - 0.5);
//    //printf("n = %d\n", n);
//    //完整发糖
//    int m = n / num_people;
//    //printf("m = %d\n", m);
//    for (int i = 0; i < num_people; i++)
//    {
//        ans[i] = m * (i + 1) + m * (m - 1) / 2 * num_people;
//    }
//    //剩下的糖，正常发放和发剩下的
//    int left = n % num_people;
//    //printf("left = %d\n", left);
//    for (int i = 0; i < left; i++)
//    {
//        ans[i] += m * num_people + 1 + i;
//    }
//    ans[left] += candies - n * (n + 1) / 2;
//    //printf("ans[%d] = %d\n", left, ans[left]);
//    *returnSize = num_people;
//    return ans;
//}
//
////2591.将钱分给最多的儿童
//
//int distMoney(int money, int children)
//{
//    //每个人必须有至少1美元
//    if (money < children)
//        return -1;
//    //金钱充足，超过每个人平均8美元，则分人数减一个人8美元，剩下的钱都给一个人
//    if (money > children * 8)
//        return children - 1;
//    //剩下的情况，先分每人1美元，再看能分几个人7美元凑成8美元
//    //最后检查是否剩下一个人会因这种分配方案而拿到4美元，有这种情况，就少一个人拿到8美元。
//    money -= children;
//    int n = money / 7;
//    if (3 == money % 7 && n + 1 == children)
//        n--;
//    return n < 1 ? 0 : n;
//}
//
////1716.计算力扣银行的钱
//
//int totalMoney(int n)
//{
//    int week = n / 7;
//    int days = n % 7;
//    return days * (days + 1) / 2 + week * days + 7 * week * (week + 7) / 2;
//}
//
