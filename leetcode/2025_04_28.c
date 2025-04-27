////2461. 长度为 K 子数组中的最大和
//
//long long maximumSubarraySum(int* nums, int numsSize, int k)
//{
//    int hash[100001] = { 0 };
//    long long sum = 0, ans = 0;
//    long long flag = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (hash[nums[i]])
//            flag += nums[i];
//        hash[nums[i]]++;
//        if (i < k - 1)
//            continue;
//
//        if (flag == 0)
//            ans = fmax(ans, sum);
//        sum -= nums[i - k + 1];
//        hash[nums[i - k + 1]]--;
//        if (hash[nums[i - k + 1]])
//            flag -= nums[i - k + 1];
//    }
//    return ans;
//}
//
////1423. 可获得的最大点数
//
//int maxScore(int* cardPoints, int cardPointsSize, int k)
//{
//    int n = cardPointsSize;
//    int sum = 0, sum1 = 0, min = 0x7fffffff;
//    for (int i = 0; i < n; i++)
//    {
//        sum1 += cardPoints[i];
//        sum += cardPoints[i];
//        if (n == k || i < n - k - 1)
//            continue;
//
//        min = fmin(sum1, min);
//        sum1 -= cardPoints[i - n + k + 1];
//    }
//    return min == 0x7fffffff ? sum : sum - min;
//}
//
////1052. 爱生气的书店老板
//
//int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes)
//{
//    int n = customersSize;
//    int max = 0, sum = 0, benefit = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += customers[i] * (grumpy[i] == 0);
//        benefit += customers[i] * grumpy[i];
//        if (i < minutes - 1)
//            continue;
//
//        max = fmax(max, benefit);
//        benefit -= grumpy[i - minutes + 1] * customers[i - minutes + 1];
//    }
//    return max + sum;
//}
//
////2105. 给植物浇水 II
//
//int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB)
//{
//    int times = 0;
//    int left = 0, right = plantsSize - 1;
//    int w1 = capacityA, w2 = capacityB;
//    while (left < right)
//    {
//        if (w1 >= plants[left])
//            w1 -= plants[left];
//        else
//        {
//            ++times;
//            w1 = capacityA - plants[left];
//        }
//        ++left;
//
//        if (w2 >= plants[right])
//            w2 -= plants[right];
//        else
//        {
//            ++times;
//            w2 = capacityB - plants[right];
//        }
//        --right;
//    }
//    if (left == right)
//    {
//        if (fmax(w1, w2) < plants[left])
//            ++times;
//    }
//    return times;
//}
//
