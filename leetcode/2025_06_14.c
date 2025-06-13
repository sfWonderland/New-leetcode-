////2566. 替换一个数字后的最大差值
//
//int minMaxDifference(int num)
//{
//    char s[16], t[16];
//    sprintf(s, "%d", num);
//    strcpy(t, s);
//    int pos = 0;
//    while (s[pos] && s[pos] == '9')
//        pos++;
//    if (s[pos])
//    {
//        char ch = s[pos];
//        for (int i = 0; s[i]; i++)
//        {
//            if (s[i] == ch)
//                s[i] = '9';
//        }
//    }
//    char first = t[0];
//    for (int i = 0; t[i]; i++)
//    {
//        if (t[i] == first)
//            t[i] = '0';
//    }
//    return atoi(s) - atoi(t);
//}
//
////2401. 最长优雅子数组
//
//int longestNiceSubarray(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int right = 0, left = 0, or_ = 0; right < numsSize; right++)
//    {
//        while (or_ & nums[right])
//            or_ ^= nums[left++];
//        or_ |= nums[right];
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////477. 汉明距离总和
//
//int totalHammingDistance(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < 30; i++)
//    {
//        int c = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            c += (nums[j] >> i) & 1;
//        }
//        ans += c * (numsSize - c);
//    }
//    return ans;
//}
//
////2425. 所有数对的异或和
//
//int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int a = 0, b = 0;
//    if (nums1Size & 1)
//    {
//        for (int i = 0; i < nums2Size; i++)
//        {
//            b ^= nums2[i];
//        }
//    }
//
//    if (nums2Size & 1)
//    {
//        for (int i = 0; i < nums1Size; i++)
//        {
//            a ^= nums1[i];
//        }
//    }
//
//    return a ^ b;
//}
//
