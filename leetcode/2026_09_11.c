//// 4040. 构造子集和的最少操作次数 I
//
//int minOperations(int* nums, int numsSize, int sum)
//{
//    int f[sum + 1];
//    memset(f, 0x3f, sizeof(f));
//    f[0] = 0;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        int w = 32 - __builtin_clz(1u * x);
//        for (int j = sum; j >= 0; j--)
//        {
//            for (int a = 0; (x << a) <= j; a++)
//            {
//                f[j] = fmin(f[j], f[j - (x << a)] + a);
//            }
//
//            for (int a = w - 1; a > 0 && (x >> a) <= j; a--)
//            {
//                f[j] = fmin(f[j], f[j - (x >> a)] + a);
//            }
//        }
//    }
//    return f[sum] == 0x3f3f3f3f ? -1 : f[sum];
//}
//
