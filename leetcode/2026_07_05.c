//// 3978. 唯一中间元素
//
//bool isMiddleElementUnique(int* nums, int numsSize)
//{
//    int x = (numsSize - 1) / 2;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i == x)
//            continue;
//        if (nums[x] == nums[i])
//            return false;
//    }
//    return true;
//}
//
//// 3979. 最大有效数对和   
//
//int maxValidPairSum(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int suf[n];
//    suf[n - 1] = nums[n - 1];
//    for (int i = n - 2; i >= k; i--)
//    {
//        suf[i] = fmax(suf[i + 1], nums[i]);
//    }
//    int ans = 0;
//    for (int i = 0; i < n - k; i++)
//    {
//        ans = fmax(ans, nums[i] + suf[i + k]);
//        // printf("%d %d %d %d %d\n", i, i + k, nums[i], suf[i + k], ans);
//    }
//    return ans;
//}
//
//// 3980. 变换二进制字符串的最少操作次数
//
//int minOperations(char* s1, char* s2)
//{
//    int n = strlen(s1);
//    if (n == 1)
//        return s2[0] - s1[0];
//
//    int ans = 0;
//    bool pre = false;
//    for (int i = 0; i < n; i++)
//    {
//        if (pre)
//        {
//            ans += '1' - s1[i] + 1;
//            s1[i] = '0';
//            pre = false;
//        }
//        if (s1[i] == s2[i])
//            continue;
//        if (s1[i] - '0')
//            pre = true;
//        else
//            ans++;
//    }
//    ans += 2 * pre;
//    return ans;
//}
//
