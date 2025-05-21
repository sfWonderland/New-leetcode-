////3074. 重新分装苹果
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize)
//{
//    qsort(capacity, capacitySize, sizeof(int), cmp);
//    int apples = 0;
//    for (int i = 0; i < appleSize; i++)
//    {
//        apples += apple[i];
//    }
//    int volumn = 0;
//    for (int i = 0; i < capacitySize; i++)
//    {
//        volumn += capacity[i];
//        if (volumn >= apples)
//            return i + 1;
//    }
//
//    return -1;
//}
//
////2279. 装满石头的背包的最大数量
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks)
//{
//    for (int i = 0; i < rocksSize; i++)
//    {
//        capacity[i] -= rocks[i];
//    }
//    qsort(capacity, capacitySize, sizeof(int), cmp);
//    for (int i = 0; i < rocksSize; i++)
//    {
//        if (additionalRocks < capacity[i])
//            return i;
//        additionalRocks -= capacity[i];
//    }
//
//    return rocksSize;
//}
//
////1833. 雪糕的最大数量
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maxIceCream(int* costs, int costsSize, int coins)
//{
//    qsort(costs, costsSize, sizeof(int), cmp);
//    for (int i = 0; i < costsSize; i++)
//    {
//        if (coins < costs[i])
//            return i;
//        coins -= costs[i];
//    }
//
//    return costsSize;
//}
//
////3010. 将数组分成最小总代价的子数组 I
//
//int minimumCost(int* nums, int numsSize)
//{
//    int min1 = INT_MAX, min2 = INT_MAX;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] < min1)
//        {
//            min2 = min1;
//            min1 = nums[i];
//        }
//        else if (nums[i] < min2)
//            min2 = nums[i];
//    }
//    return nums[0] + min1 + min2;
//}
//
