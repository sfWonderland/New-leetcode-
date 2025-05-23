////3075. 幸福值最大化的选择方案
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maximumHappinessSum(int* happiness, int happinessSize, int k)
//{
//    qsort(happiness, happinessSize, sizeof(int), cmp);
//    long long ans = 0;
//    for (int i = 0; i < k && happiness[i] > i; i++)
//    {
//        ans += happiness[i] - i;
//    }
//    return ans;
//}
//
////2554. 从一个范围内选择最多整数 I
//
//int maxCount(int* banned, int bannedSize, int n, int maxSum)
//{
//    int* hash = (int*)calloc(n + 1, sizeof(int));
//    for (int i = 0; i < bannedSize; i++)
//    {
//        if (banned[i] <= n)
//            hash[banned[i]] = 1;
//    }
//    int num = 0, sum = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (hash[i] == 0)
//        {
//            if (sum + i <= maxSum)
//            {
//                sum += i;
//                num++;
//            }
//            else
//                break;
//        }
//    }
//    return num;
//}
//
////2126. 摧毁小行星
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize)
//{
//    qsort(asteroids, asteroidsSize, sizeof(int), cmp);
//    long long mass1 = mass;
//    for (int i = 0; i < asteroidsSize; i++)
//    {
//        if (mass1 >= asteroids[i])
//            mass1 = mass1 + asteroids[i];
//        else
//            return false;
//    }
//    return true;
//}
//
////2587. 重排数组以得到最大前缀分数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int maxScore(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (sum <= 0)
//            return i;
//    }
//    return numsSize;
//}
//
