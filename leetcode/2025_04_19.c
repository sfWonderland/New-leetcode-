////2563. 统计公平数对的数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//long long countFairPairs(int* nums, int numsSize, int lower, int upper)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long count(int upper)
//    {
//        int left = 0;
//        int right = numsSize - 1;
//        long long sum = 0;
//        while (left < right)
//        {
//            if (nums[left] + nums[right] <= upper)
//            {
//                sum += right - left;
//                left++;
//            }
//            else
//                right--;
//        }
//        return sum;
//    }
//    return count(upper) - count(lower - 1);
//}
//
////2652. 倍数求和
//
//int Sn(int n, int m)
//{
//    //1，n能被m整除的整数组成的等差数列，整除个数为n/m
//    return (m + n / m * m) * (n / m) / 2;
//}
//int sumOfMultiples(int n)
//{
//    //容斥原理
//    return Sn(n, 3) + Sn(n, 5) + Sn(n, 7) - Sn(n, 15) - Sn(n, 21) - Sn(n, 35) + Sn(n, 105);
//}
//
////2651. 计算列车到站时间
//
//int findDelayedArrivalTime(int arrivalTime, int delayedTime)
//{
//    return (arrivalTime + delayedTime) % 24;
//}
//
////2682. 找出转圈游戏输家
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* circularGameLosers(int n, int k, int* returnSize)
//{
//    bool visit[n];
//    memset(visit, 0, sizeof(bool) * n);
//    for (int i = k, step = 0; !visit[step]; i += k)
//    {
//        visit[step] = true;
//        step = (step + i) % n;
//    }
//    int* loser = (int*)malloc(sizeof(int) * n);
//    returnSize[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (!visit[i])
//            loser[returnSize[0]++] = i + 1;
//    }
//    return loser;
//}
//
