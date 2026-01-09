////2760. 最长奇偶子数组
//
//int longestAlternatingSubarray(int* nums, int numsSize, int threshold)
//{
//    int ans = 0, i = 0;
//    while (i < numsSize)
//    {
//        if (nums[i] % 2 || nums[i] > threshold)
//        {
//            i++;
//            continue;
//        }
//
//        int start = i++;
//        while (i < numsSize && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2)
//        {
//            i++;
//        }
//        ans = fmax(i - start, ans);
//    }
//    return ans;
//}
//
////1759. 统计同质子字符串的数目    
//
//const int MOD = 1e9 + 7;
//int countHomogenous(char* s)
//{
//    int i = 0, ans = 0, n = strlen(s);
//    while (i < n)
//    {
//        int start = i++;
//        while (i < n && s[i] == s[i - 1])
//            i++;
//
//        ans = (1ll * (i - start + 1) * (i - start) / 2 + ans) % MOD;
//    }
//    return ans;
//}
//
////1839. 所有元音按顺序排布的最长子字符串
//
//// 用一个整型int映射bool字母集，元音字母全部存在时，整形映射为0x104111
//int longestBeautifulSubstring(char* word)
//{
//    int i = 0, ans = 0, n = strlen(word);
//    while (i < n)
//    {
//        int start = i++, mask = 1 << (word[start] - 'a');
//        //printf("%c ", word[i - 1]);
//        while (i < n && word[i] >= word[i - 1])
//        {
//            mask |= 1 << (word[i] - 'a');
//            i++;
//        }
//        //printf("%x ", mask);
//        if (mask == 0x104111)
//            ans = fmax(ans, i - start);
//    }
//    return ans;
//}
//
////2765. 最长交替子数组
//
//int alternatingSubarray(int* nums, int numsSize)
//{
//    int i = 0, ans = 0;
//    while (i < numsSize)
//    {
//        int start = i++;
//        while (i < numsSize && nums[i] == nums[start] + (i - start) % 2)
//        {
//            i++;
//        }
//        ans = fmax(ans, i - start);
//        if (i < numsSize&& nums[i - 1] + 1 == nums[i])
//            i--;
//    }
//    return ans > 1 ? ans : -1;
//}
//
