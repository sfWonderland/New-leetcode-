////1545. 找出第 N 个二进制字符串中的第 K 位
//
//void form(char* s, int n)
//{
//    if (n == 1)
//    {
//        s[0] = '0';
//        s[1] = '\0';
//        return;
//    }
//
//    form(s, n - 1);
//    int m = 1 << (n - 1);
//    //printf("%s %d\n", s, m);
//    s[m - 1] = '1';
//    for (int i = 1; i < m; i++)
//    {
//        s[m - 1 + i] = '1' - s[m - 1 - i] + '0';
//    }
//    s[2 * m - 1] = '\0';
//    //printf("%s\n", s);
//}
//char findKthBit(int n, int k)
//{
//    int m = 1 << n;
//    char* s = (char*)malloc(sizeof(char) * m);
//    form(s, n);
//    //printf("%s\n", s);
//    //printf("!");
//    return s[k - 1];
//}
//
////3852. 不同频率的最小数对    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minDistinctFreqPair(int* nums, int numsSize, int* returnSize)
//{
//    int cnt[101] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i]]++;
//    }
//    *returnSize = 2;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = ans[1] = -1;
//    for (int i = 1; i <= 100; i++)
//    {
//        if (cnt[i])
//        {
//            for (int j = i + 1; j <= 100; j++)
//            {
//                if (cnt[j] && cnt[j] != cnt[i])
//                {
//                    ans[0] = i;
//                    ans[1] = j;
//                    return ans;
//                }
//            }
//        }
//    }
//    return ans;
//}
//
////3853. 合并靠近字符
//
//char* mergeCharacters(char* s, int k)
//{
//    int n = strlen(s);
//    int m = n;
//    do
//    {
//        n = m;
//        char* t = (char*)malloc(sizeof(char) * (n + 1));
//        int idx = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int cnt = 0;
//            for (int j = i - 1; j >= 0 && cnt < k; j--)
//            {
//                if (s[j])
//                {
//                    if (s[i] == s[j])
//                    {
//                        //printf("%c %d\n", s[i], j);
//                        s[i] = '\0';
//                        break;
//                    }
//                    else
//                        cnt++;
//                }
//            }
//            if (s[i])
//                t[idx++] = s[i];
//        }
//        m = idx;
//        t[idx] = '\0';
//        s = t;
//        //printf("%s %d %d\n", t, m, n);
//    } while (m != n);
//    return s;
//}
//
////3854. 使数组奇偶交替的最少操作
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int getDiff(int* nums, int numsSize, bool odd)
//{
//    int min = INT_MAX, max = INT_MIN;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int diff = (abs(nums[i]) % 2 == (i + odd) % 2);
//        min = fmin(min, nums[i] + diff);
//        max = fmax(max, nums[i] - diff);
//    }
//    return max - min;
//}
//int* makeParityAlternating(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = ans[1] = 0;
//    *returnSize = 2;
//    if (numsSize == 1)
//        return ans;
//    int m = 0, same = 0; // 先偶后奇
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == nums[0])
//            same++;
//        if (abs(nums[i]) % 2 == i % 2)
//            m++;
//    }
//    if (same == numsSize)
//    {
//        ans[0] = numsSize / 2;
//        ans[1] = 1;
//        return ans;
//    }
//    int n = numsSize - m;
//    int diff = m >= n ? getDiff(nums, numsSize, 1) : getDiff(nums, numsSize, 0);
//    if (m == n)
//        diff = fmin(getDiff(nums, numsSize, 0), diff);
//    ans[0] = m >= n ? n : m;
//    ans[1] = diff;
//    return ans;
//}
//
