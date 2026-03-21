////101018. 构造奇偶一致的数组 I
//
//bool uniformArray(int* nums1, int nums1Size)
//{
//    return true;
//}
//
////101020. 构造奇偶一致的数组 II    
//
//bool uniformArray(int* nums1, int nums1Size)
//{
//    int nums[2] = { 0 };
//    int min = INT_MAX;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        int x = nums1[i];
//        nums[x % 2]++;
//        min = fmin(min, x);
//    }
//    if (nums[0] && nums[1] && min % 2 == 0)
//        return false;
//
//    return true;
//}
//
////100873. 达到目标异或值的最少删除次数
//
//int minRemovals(int* nums, int numsSize, int target)
//{
//    int m = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        m |= nums[i];
//    }
//    int k = 0;
//    while (m)
//    {
//        m >>= 1;
//        k++;
//    }
//    int M = 1 << k;
//    int f[M];
//    f[0] = 0;
//    for (int i = 1; i < M; i++)
//    {
//        f[i] = -1;
//    }
//    int new_f[M];
//    for (int i = 0; i < numsSize; i++)
//    {
//        memcpy(new_f, f, sizeof(f));
//        int x = nums[i];
//        for (int j = 0; j < M; j++)
//        {
//            if (f[j] != -1)
//            {
//                int y = x ^ j;
//                if (f[j] + 1 > new_f[y] || new_f[y] == -1)
//                    new_f[y] = f[j] + 1;
//            }
//        }
//        memcpy(f, new_f, sizeof(f));
//    }
//    return target >= M || f[target] == -1 ? -1 : numsSize - f[target];
//}
//
////2784. 检查数组是否是好的
//
//bool isGood(int* nums, int numsSize)
//{
//    bool exist[numsSize];
//    memset(exist, 0, sizeof(exist));
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > numsSize - 1 || (nums[i] != numsSize - 1 && exist[nums[i]]))
//            return false;
//
//        if (nums[i] < numsSize - 1)
//            exist[nums[i]] = true;
//        else
//            cnt++;
//    }
//    return cnt == 2;
//}
//
