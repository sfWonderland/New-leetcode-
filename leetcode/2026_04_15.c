////LCR 015. 找到字符串中所有字母异位词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findAnagrams(char* s, char* p, int* returnSize)
//{
//    int cnt[26] = { 0 };
//    int k = strlen(p), n = strlen(s), diff = 0;
//    *returnSize = 0;
//    if (k > n)
//        return NULL;
//    for (int i = 0; i < k; i++)
//    {
//        diff += (cnt[p[i] - 'a'] == 0);
//        cnt[p[i] - 'a']--;
//    }
//    int left = 0;
//    int* ans = (int*)malloc(sizeof(int) * (n - k + 1));
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//        diff -= (cnt[s[i] - 'a'] == 0);
//        diff += (cnt[s[i] - 'a'] > 0);
//        while (cnt[s[i] - 'a'] > 0)
//        {
//            diff += (cnt[s[left] - 'a'] == 0);
//            cnt[s[left] - 'a']--;
//            diff -= (cnt[s[left] - 'a'] == 0);
//            left++;
//        }
//        if (diff == 0)
//            ans[(*returnSize)++] = i - k + 1;
//    }
//    return ans;
//}
//
////LCR 016. 无重复字符的最长子串    
//
//int lengthOfLongestSubstring(char* s)
//{
//    bool alpha[128] = { 0 };
//    int left = 0, ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        while (alpha[s[i]])
//        {
//            alpha[s[left]] = false;
//            left++;
//        }
//        ans = fmax(i - left + 1, ans);
//        alpha[s[i]] = true;
//    }
//    return ans;
//}
//
////LCR 017. 最小覆盖子串
//
//char* minWindow(char* s, char* t)
//{
//    int cnt[128] = { 0 };
//    int k = strlen(t), n = strlen(s), diff = 0;
//    if (k > n)
//        return "";
//    for (int i = 0; i < k; i++)
//    {
//        diff += (cnt[t[i]] == 0);
//        cnt[t[i]]--;
//    }
//    int left = 0, l = 0, len = n + 1;
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i]]++;
//        diff -= (cnt[s[i]] == 0);
//        while (cnt[s[left]] > 0)
//        {
//            cnt[s[left]]--;
//            left++;
//        }
//        if (diff == 0 && len > i - left + 1)
//        {
//            len = i - left + 1;
//            l = left;
//        }
//    }
//    if (len == n + 1)
//        return "";
//
//    char* ans = (char*)malloc(sizeof(char) * (len + 1));
//    strncpy(ans, s + l, len);
//    ans[len] = '\0';
//    return ans;
//}
//
////LCR 018. 验证回文串
//
//bool isPalindrome(char* s)
//{
//    int left = 0, right = strlen(s) - 1;
//    while (left < right)
//    {
//        while (left < right)
//        {
//            if (s[left] >= '0' && s[left] <= '9')
//            {
//                break;
//            }
//            if (s[left] >= 'a' && s[left] <= 'z')
//            {
//                break;
//            }
//            if (s[left] >= 'A' && s[left] <= 'Z')
//            {
//                s[left] |= 32;
//                break;
//            }
//            left++;
//        }
//        while (left < right)
//        {
//            if (s[right] >= '0' && s[right] <= '9')
//            {
//                break;
//            }
//            if (s[right] >= 'a' && s[right] <= 'z')
//            {
//                break;
//            }
//            if (s[right] >= 'A' && s[right] <= 'Z')
//            {
//                s[right] |= 32;
//                break;
//            }
//            right--;
//        }
//        // printf("%d %c %d %c\n", left, s[left], right, s[right]);
//        if (s[left] != s[right])
//            return false;
//
//        left++;
//        right--;
//    }
//    return true;
//}
//
