////2317. 操作后的最大异或和
//
//int maximumXOR(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans |= nums[i];
//    }
//    return ans;
//}
//
////2588. 统计美丽子数组数目
//
//long long beautifulSubarrays(int* nums, int numsSize)
//{
//    int hash[1100000];
//    memset(hash, 0, sizeof(hash));
//    hash[0] = 1;
//    int pre = 0;
//    long long ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        pre ^= nums[i];
//        ans += hash[pre]++;
//    }
//
//    return ans;
//}
//
////1318. 或运算的最小翻转次数
//
//int minFlips(int a, int b, int c)
//{
//    int or = a | b;
//    if (or == c)
//        return 0;
//
//    int diff = (or ^ c);
//    int and = (a & b);
//    int ans = 0;
//    while (diff)
//    {
//        if (diff & 1)
//            ans += 1 + (and &1);
//
//        diff >>= 1;
//        and >>= 1;
//        or >>= 1;
//        c >>= 1;
//    }
//    return ans;
//}
//
////2871. 将数组分割成最多数目的子数组
//
//int maxSubarrays(int* nums, int numsSize)
//{
//    int n = -1, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        n &= nums[i];
//        if (n == 0)
//        {
//            ans++;
//            n = -1;
//        }
//    }
//    return fmax(ans, 1);
//}
//
