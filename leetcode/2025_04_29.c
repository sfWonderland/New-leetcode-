////1461. 检查一个字符串是否包含所有长度为 K 的二进制子串
//
//bool hasAllCodes(char* s, int k)
//{
//    int hash[1 << k];
//    memset(hash, 0, sizeof(hash));
//    int num = 0;
//    int t = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        t <<= 1;
//        t += s[i] - '0';
//        if (i < k - 1)
//            continue;
//
//        if (hash[t] == 0)
//        {
//            hash[t]++;
//            num++;
//        }
//        t -= (s[i - k + 1] - '0') << (k - 1);
//        //printf("%d %d\n", num, t);
//    }
//    return num == 1 << k;
//}
//
////3. 无重复字符的最长子串
//
//int lengthOfLongestSubstring(char* s)
//{
//    int ans = 0, left = 0;
//    int cnt[128] = { 0 };
//    for (int right = 0; s[right]; right++)
//    {
//        cnt[s[right]]++;
//
//        while (cnt[s[right]] > 1)
//        {
//            cnt[s[left]]--;
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////2962. 统计最大元素出现至少 K 次的子数组
//
//long long countSubarrays(int* nums, int numsSize, int k)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(nums[i], max);
//    }
//    long long ans = 0;
//    int cnt = 0, left = 0;
//    for (int right = 0; right < numsSize; right++)
//    {
//        cnt += (nums[right] == max);
//
//        while (cnt == k)
//        {
//            cnt -= nums[left] == max;
//            left++;
//        }
//        ans += left;
//    }
//    return ans;
//}
//
////3090. 每个字符最多出现两次的最长子字符串
//
//int maximumLengthSubstring(char* s)
//{
//    int hash[26] = { 0 };
//    int left = 0, ans = 0;
//    for (int right = 0; s[right]; right++)
//    {
//        hash[s[right] - 'a']++;
//
//        while (hash[s[right] - 'a'] == 3)
//        {
//            hash[s[left] - 'a']--;
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//        //printf("%d %c %d %c\n", left, s[left], right, s[right]);
//    }
//    return ans;
//}
//
