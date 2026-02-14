////3842. 灯泡开关
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* toggleLightBulbs(int* bulbs, int bulbsSize, int* returnSize)
//{
//    bool vis[101] = { 0 };
//    for (int i = 0; i < bulbsSize; i++)
//    {
//        vis[bulbs[i]] ^= 1;
//    }
//    int* ans = (int*)malloc(sizeof(int) * bulbsSize);
//    *returnSize = 0;
//    for (int i = 0; i < 101; i++)
//    {
//        if (vis[i])
//            ans[(*returnSize)++] = i;
//    }
//    return ans;
//}
//
////3843. 频率不同的第一个元素    
//
//int firstUniqueFreq(int* nums, int numsSize)
//{
//    int cnt[100001] = { 0 };
//    int freq[100001] = { 0 };
//    int front = 0, rear = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//        freq[cnt[nums[i]] - 1]--;
//        freq[cnt[nums[i]]]++;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (freq[cnt[nums[i]]] == 1)
//            return nums[i];
//    }
//    return -1;
//}
//
////5. 最长回文子串
//
//char* longestPalindrome(char* s)
//{
//    int n = strlen(s);
//    int ans_left = 0, ans_right = 0;
//
//    // 奇回文串
//    for (int i = 0; i < n; i++)
//    {
//        int l = i, r = i;
//        while (l >= 0 && r < n && s[l] == s[r])
//        {
//            l--;
//            r++;
//        }
//        if (r - l - 1 > ans_right - ans_left)
//        {
//            // 左闭右开
//            ans_left = l + 1;
//            ans_right = r;
//        }
//    }
//
//    // 偶回文串
//    for (int i = 0; i < n - 1; i++)
//    {
//        int l = i, r = i + 1;
//        while (l >= 0 && r < n && s[l] == s[r])
//        {
//            l--;
//            r++;
//        }
//        if (r - l - 1 > ans_right - ans_left)
//        {
//            // 左闭右开
//            ans_left = l + 1;
//            ans_right = r;
//        }
//    }
//
//    s[ans_right] = '\0';
//    return s + ans_left;
//}
//
//char* longestPalindrome(char* s)
//{
//    int n = strlen(s);
//    int ans_left = 0, ans_right = 0;
//
//
//    for (int i = 0; i < 2 * n - 1; i++)
//    {
//        int l = i / 2, r = (i + 1) / 2;
//        while (l >= 0 && r < n && s[l] == s[r])
//        {
//            l--;
//            r++;
//        }
//        if (r - l - 1 > ans_right - ans_left)
//        {
//            // 左闭右开
//            ans_left = l + 1;
//            ans_right = r;
//        }
//    }
//
//    s[ans_right] = '\0';
//    return s + ans_left;
//}
//
//char* longestPalindrome(char* s)
//{
//    int n = strlen(s);
//    int m = 2 * n + 3;
//    char t[m + 1];
//
//    t[0] = '^';
//    for (int i = 0; i < n; i++)
//    {
//        t[i * 2 + 1] = '#';
//        t[i * 2 + 2] = s[i];
//    }
//    t[2 * n + 1] = '#';
//    t[2 * n + 2] = '$';
//    t[2 * n + 3] = '\0';
//    int halfL[m - 2];
//    memset(halfL, 0, sizeof(halfL));
//    halfL[1] = 1;
//    int halfM = 0, halfR = 0, max_i = 0;
//    for (int i = 2; i < m - 2; i++)
//    {
//        int hl = 1;
//        if (i < halfR)
//            hl = fmin(halfL[halfM * 2 - i], halfR - i);
//
//        while (t[i - hl] == t[i + hl])
//            hl++;
//
//        halfM = i;
//        halfR = i + hl;
//
//        halfL[i] = hl;
//        if (hl > halfL[max_i])
//            max_i = i;
//    }
//    //printf("%c %d %d", t[max_i], max_i, halfL[max_i]);
//    int hl = halfL[max_i];
//    int left = (max_i - hl) / 2, right = (max_i + hl) / 2 - 1;
//    s[right] = '\0';
//    return s + left;
//}
//
////3844. 最长的准回文子字符串
//
//int almostPalindromic(char* s)
//{
//    int n = strlen(s), ans = 0;
//    void expand(int l, int r)
//    {
//        while (l >= 0 && r < n && s[l] == s[r])
//        {
//            l--;
//            r++;
//        }
//        ans = fmax(ans, r - l - 1);
//    }
//    for (int i = 0; i < 2 * n - 1 && ans < n; i++)
//    {
//        int l = i / 2, r = (i + 1) / 2;
//        while (l >= 0 && r < n && s[l] == s[r])
//        {
//            l--;
//            r++;
//        }
//        expand(l - 1, r); // 删除s[l]，继续向外拓展
//        expand(l, r + 1); // 删除s[r]，继续向外拓展
//    }
//    return ans;
//}
//
