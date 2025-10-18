////3720. 大于 target 的最小字典序排列
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e2 - *(char*)e1;
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//char* lexGreaterPermutation(char* s, char* target)
//{
//    int cnt[26] = { 0 };
//    int n = strlen(s);
//    qsort(s, n, sizeof(char), cmp);
//    if (strcmp(s, target) <= 0)
//        return "";
//    for (int i = 0; i < n; i++)
//    {
//        cnt[s[i] - 'a']++;
//    }
//    int pre[n];
//    memset(pre, 0, sizeof(pre));
//    for (int i = 0; i < n; i++)
//    {
//        int x = target[i] - 'a';
//        if (cnt[x])
//        {
//            cnt[x]--;
//            s[i] = x + 'a';
//            pre[i] = x;
//        }
//        else
//        {
//            x++;
//            while (x < 26 && cnt[x] == 0)
//            {
//                x++;
//            }
//            while (x > 25)
//            {
//                cnt[pre[--i]]++;
//                x = pre[i] + 1;
//                while (x < 26 && cnt[x] == 0)
//                {
//                    x++;
//                }
//            }
//            s[i++] = x + 'a';
//            cnt[x]--;
//            for (int j = 0; j < 26; j++)
//            {
//                while (cnt[j] > 0)
//                {
//                    s[i++] = j + 'a';
//                    cnt[j]--;
//                }
//            }
//        }
//    }
//    if (strcmp(s, target) == 0)
//    {
//        int i = n - 2;
//        char tmp = s[n - 1];
//        while (s[i] >= tmp)
//        {
//            tmp = s[i--];
//        }
//        int t = i + 1;
//        while (s[t] > s[i])
//            t++;
//        tmp = s[i];
//        s[i] = s[t - 1];
//        s[t - 1] = tmp;
//        qsort(s + i + 1, n - i - 1, sizeof(char), cmp2);
//    }
//    return s;
//}
//
////3718. 缺失的最小倍数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int missingMultiple(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = k;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (ans == nums[i])
//            ans += k;
//    }
//    return ans;
//}
//
////3713. 最长的平衡子串 I
//
//int longestBalanced(char* s)
//{
//    int ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        int cnt[26] = { 0 };
//        int mx = 0, kinds = 0;
//        for (int j = i; s[j]; j++)
//        {
//            if (cnt[s[j] - 'a'] == 0)
//                kinds++;
//            cnt[s[j] - 'a']++;
//            mx = fmax(mx, cnt[s[j] - 'a']);
//            if (kinds * mx == j - i + 1)
//            {
//                ans = fmax(ans, j - i + 1);
//                //printf("%d %d\n", i, j);
//            }
//        }
//    }
//    return ans;
//}
//
////3719. 最长平衡子数组 I
//
//int longestBalanced(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        bool hash[100001] = { 0 };
//        int even = 0, odd = 0;
//        for (int j = i; j < numsSize; j++)
//        {
//            if (hash[nums[j]] == 0)
//            {
//                if (nums[j] & 1)
//                    odd++;
//                else
//                    even++;
//                hash[nums[j]] = 1;
//            }
//            if (even == odd)
//                ans = fmax(ans, j - i + 1);
//        }
//
//    }
//    return ans;
//}
//
