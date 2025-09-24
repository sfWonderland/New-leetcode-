////面试题 16.10. 生存人数
//
//int maxAliveYear(int* birth, int birthSize, int* death, int deathSize)
//{
//    int age[102] = { 0 };
//    for (int i = 0; i < birthSize; i++)
//    {
//        age[birth[i] - 1900]++;
//        if (death[i] <= 2000)
//            age[death[i] - 1899]--;
//    }
//    int max = age[0], yr = 1900;
//    for (int i = 1; i <= 100; i++)
//    {
//        age[i] += age[i - 1];
//        if (age[i] > max)
//        {
//            max = age[i];
//            yr = i;
//        }
//    }
//    return yr + 1900;
//}
//
////3153. 所有数对中数位差之和
//
//long long sumDigitDifferences(int* nums, int numsSize)
//{
//    int n = 1, x = nums[0];
//    while (x > 9)
//    {
//        n++;
//        x /= 10;
//    }
//    int cnt[n][10];
//    for (int i = 0; i < n; i++)
//    {
//        memset(cnt[i], 0, sizeof(int) * 10);
//    }
//
//    long long ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        for (int j = 0; x; x /= 10, j++)
//        {
//            ans += i - cnt[j][x % 10]++;
//        }
//    }
//    return ans;
//}
//
////2568. 最小无法得到的或值
//
//int minImpossibleOR(int* nums, int numsSize)
//{
//    int mask = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & (nums[i] - 1))
//            continue;
//        mask |= nums[i];
//    }
//    mask = ~mask;
//    return mask & -mask;
//}
//
////3644. 排序排列
//
//int sortPermutation(int* nums, int numsSize)
//{
//    int mask = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i == nums[i])
//            continue;
//        mask = mask & nums[i];
//    }
//    return mask == INT_MAX ? 0 : mask;
//}
//
