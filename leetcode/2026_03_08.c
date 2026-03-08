////769. 最多能完成排序的块
//
//int maxChunksToSorted(int* arr, int arrSize)
//{
//    int n = arrSize, ans = 0;
//    for (int i = 0, j = 0, min = n, max = -1; i < n; i++)
//    {
//        min = fmin(min, arr[i]);
//        max = fmax(max, arr[i]);
//        // 根据其在 [0, n - 1] 范围内的整数的排列性质，最大最小值都在范围内，可以拆分后按序重新排列
//        if (j == min && i == max)
//        {
//            ans++;
//            j = i + 1;
//            min = n;
//            max = -1;
//        }
//    }
//    return ans;
//}
//
////101010. 容量最小的箱子    
//
//int minimumIndex(int* capacity, int capacitySize, int itemSize)
//{
//    int idx = -1, cap = 101;
//    for (int i = 0; i < capacitySize; i++)
//    {
//        if (capacity[i] < cap && capacity[i] >= itemSize)
//        {
//            idx = i;
//            cap = capacity[i];
//        }
//    }
//    return idx;
//}
//
////101003. 找出最小平衡下标
//
//int smallestBalancedIndex(int* nums, int numsSize)
//{
//    long long suf[numsSize + 1];
//    suf[numsSize] = 1;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        double test = 1.0 * suf[i + 1] * nums[i];
//        suf[i] = test <= 1e14 + 1 ? suf[i + 1] * nums[i] : 1e14 + 1;
//    }
//    long long pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        //printf("%lld\n", suf[i + 1]);
//        if (pre == suf[i + 1])
//            return i;
//        pre += nums[i];
//    }
//    return -1;
//}
//
////100991. 将一个字符串排序的最小操作次数
//
//int minOperations(char* s)
//{
//    int n = strlen(s);
//    if (n == 1)
//        return 0;
//    if (n == 2)
//        return s[0] <= s[1] ? 0 : -1;
//    char mx = 'a' - 1, mn = 'z' + 1;
//    // 中间有mn或mx就要记录
//    int idx1 = -1, idx2 = -1;
//    bool flag = true;
//    for (int i = 0; i < n; i++)
//    {
//        if (mx <= s[i])
//        {
//            mx = s[i];
//            idx1 = i;
//        }
//        if (mn > s[i])
//        {
//            mn = s[i];
//            idx2 = i;
//        }
//        if (flag && i > 0 && s[i] < s[i - 1])
//            flag = false;
//    }
//    if (s[n - 1] == mx || s[0] == mn)
//        return 1 - flag;
//
//    if (s[n - 1] == mn && s[0] == mx)
//        return 2 + (idx1 == 0 && idx2 == n - 1);
//
//    return 2;
//}
//
