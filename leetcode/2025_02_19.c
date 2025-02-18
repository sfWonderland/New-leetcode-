//#define _CRT_SECURE_NO_WARNINGS
//
////1855.下标对中的最大距离
//
//int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int i = 0;
//    int j = 0;
//    while (i < nums1Size&& j < nums2Size)
//    {
//        if (nums1[i] > nums2[j])
//            i++;
//
//        j++;
//    }
//    return j - i - 1 > 0 ? j - i - 1 : 0;
//}
//
////1624.两个相同字符之间的最长子字符串
//
//int maxLengthBetweenEqualCharacters(char* s)
//{
//    int len = strlen(s);
//    int h[26] = { 0 };
//    int max = -1;
//    for (int i = 0; i < len; i++)
//    {
//        if (h[s[i] - 'a'] == 0)
//            h[s[i] - 'a'] = i + 1;
//        else
//            max = max > i - h[s[i] - 'a'] ? max : i - h[s[i] - 'a'];
//    }
//    return max;
//}
//
////1646.获取生成数组中的最大值
//
//int getMaximumGenerated(int n)
//{
//    if (n < 2)
//        return n;
//    int nums[n + 1];
//    memset(nums, 0, sizeof(int) * (n + 1));
//    nums[1] = 1;
//    int max = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        nums[i] = nums[i / 2] + i % 2 * nums[i - i / 2];
//
//        if (nums[i] > max)
//            max = nums[i];
//    }
//    return max;
//}
//
////1748.唯一元素的和
//
//int sumOfUnique(int* nums, int numsSize)
//{
//    int h[100] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        h[nums[i] - 1]++;
//    }
//    int ret = 0;
//    for (int i = 0; i < 100; i++)
//    {
//        if (h[i] == 1)
//            ret += i + 1;
//    }
//    return ret;
//}
//
