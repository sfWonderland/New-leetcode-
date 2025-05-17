////2367. 等差三元组的数目
//
//int arithmeticTriplets(int* nums, int numsSize, int diff)
//{
//    int hash[201] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i]]++;
//    }
//    int ans = 0;
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        int j = nums[i] - diff;
//        int k = nums[i] + diff;
//        if (j >= 0 && k <= 200 && hash[j] && hash[k])
//            ans++;
//    }
//    return ans;
//}
//
////795. 区间子数组个数
//
//int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right)
//{
//    int ans = 0, l = -1, r = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > right)
//            l = i;
//        if (nums[i] >= left)
//            r = i;
//        ans += r - l;
//    }
//    return ans;
//}
//
////1869. 哪种连续子字符串更长
//
//bool checkZeroOnes(char* s)
//{
//    int nums[2] = { 0 };
//    for (int right = 0; s[right];)
//    {
//        char ch = s[right];
//        int left = right - 1;
//        while (s[right] == ch)
//            right++;
//
//        nums[ch - '0'] = fmax(nums[ch - '0'], right - left);
//    }
//    return nums[1] > nums[0];
//}
//
////2414. 最长的字母序连续子字符串的长度
//
//int longestContinuousSubstring(char* s)
//{
//    int ans = 1, left = 0, right = 1;
//    while (s[right])
//    {
//        if (s[right] != s[right - 1] + 1)
//        {
//            ans = fmax(ans, right - left);
//            left = right;
//        }
//
//        right++;
//    }
//    ans = fmax(ans, right - left);
//    return ans;
//}
//
