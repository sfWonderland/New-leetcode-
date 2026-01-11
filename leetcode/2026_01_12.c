////3722. 反转后字典序最小的字符串
//
//// 从左到右找出最小字母及其坐标，比首字母相同甚至更小的字母，遇到更小的字母一定可以反转成字典序更小的字符串，直接可以记录，如果相等则需要与已经记录的相等的进行比较，判断反转后能否变得字典序更小。
//// 再从右向左找出最前面不小于末尾字母的字母，判断从该字母反转后能否使已经记录的字符串变得字典序更小。
//// 两者都找不到，字符串单调不减，只改一位等于没改。
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* lexSmallest(char* s)
//{
//    int n = strlen(s);
//    if (n == 1)
//        return s;
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    strcpy(ans, s);
//    char min = s[0];
//    for (int i = 1; i < n; i++)
//    {
//        if (min >= s[i])
//        {
//            char* s1 = (char*)malloc(sizeof(char) * (n + 1));
//            strcpy(s1, s);
//            reverse(s1, 0, i);
//            if (min > s[i] || strcmp(s1, ans) < 0)
//            {
//                strcpy(ans, s1);
//            }
//            min = s[i];
//        }
//    }
//    //printf("%s\n", ans);
//    for (int i = n - 2; i > 0; i--)
//    {
//        if (s[n - 1] <= s[i])
//        {
//            char* s1 = (char*)malloc(sizeof(char) * (n + 1));
//            strcpy(s1, s);
//            reverse(s1, i, n - 1);
//            //printf("%s\n", s1);
//            if (strcmp(s1, ans) < 0)
//            {
//                strcpy(ans, s1);
//            }
//        }
//        // printf("%d %s\n", i, ans);
//    }
//    //printf("%s\n", ans);
//    return ans;
//}
//
////890. 查找和替换模式    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize)
//{
//    int fl[26];
//    bool appeared[26];
//    char** ans = (char**)malloc(sizeof(char*) * wordsSize);
//    *returnSize = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        memset(fl, 0, sizeof(int) * 26);
//        memset(appeared, 0, sizeof(bool) * 26);
//        bool flag = true;
//        for (int j = 0; words[i][j]; j++)
//        {
//            if (fl[pattern[j] - 'a'] == 0)
//            {
//                if (appeared[words[i][j] - 'a'])
//                {
//                    flag = false;
//                    break;
//                }
//                fl[pattern[j] - 'a'] = words[i][j];
//                appeared[words[i][j] - 'a'] = true;
//            }
//            else if (fl[pattern[j] - 'a'] != words[i][j])
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//            ans[(*returnSize)++] = words[i];
//    }
//    return ans;
//}
//
////1247. 交换字符使得字符串相同
//
//int minimumSwap(char* s1, char* s2)
//{
//    int n = strlen(s1);
//    int cnt[2] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        if (s1[i] != s2[i])
//        {
//            cnt[s1[i] % 2]++;
//        }
//    }
//    int d = cnt[0] + cnt[1];
//    return d % 2 ? -1 : d / 2 + cnt[0] % 2;
//}
//
////1630. 等差子数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize)
//{
//    int n = lSize;
//    bool* ans = (bool*)malloc(sizeof(bool) * n);
//    for (int i = 0; i < n; i++)
//    {
//        int left = l[i], right = r[i];
//        int max = -100001, min = 100001;
//        for (int j = left; j <= right; j++)
//        {
//            max = fmax(max, nums[j]);
//            min = fmin(min, nums[j]);
//        }
//        if (max == min)
//        {
//            ans[i] = true;
//            continue;
//        }
//
//        //printf("%d %d\n", max, min);
//        if ((max - min) % (right - left))
//        {
//            ans[i] = false;
//            continue;
//        }
//        int diff = (max - min) / (right - left);
//        ans[i] = true;
//        bool* vis = (bool*)calloc(sizeof(bool), right - left + 1);
//        for (int j = left; j <= right; j++)
//        {
//            if ((nums[j] - min) % diff || vis[(nums[j] - min) / diff])
//            {
//                ans[i] = false;
//                break;
//            }
//
//            vis[(nums[j] - min) / diff] = true;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
