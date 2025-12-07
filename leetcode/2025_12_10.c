////2176. 统计数组中相等且可以被整除的数对
//
//int countPairs(int* nums, int numsSize, int k)
//{
//    int hash[101][numsSize + 1];
//    for (int i = 0; i < 101; i++)
//    {
//        for (int j = 0; j <= numsSize; j++)
//        {
//            hash[i][j] = 0;
//        }
//    }
//    int len[101] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i]][len[nums[i]]++] = i;
//    }
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int n = len[nums[i]];
//        if (n == 0)
//            continue;
//
//        for (int j = 0; j < n; j++)
//        {
//            int x = hash[nums[i]][j];
//            for (int m = j + 1; m < n; m++)
//            {
//                int y = hash[nums[i]][m];
//                if (x * y % k == 0)
//                    ans++;
//            }
//        }
//        len[nums[i]] = 0;
//    }
//    return ans;
//}
//
//int countPairs(int* nums, int numsSize, int k)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; j < numsSize; j++)
//        {
//            if ((i * j % k == 0) && nums[i] == nums[j])
//                ans++;
//        }
//    }
//    return ans;
//}
//
////2913. 子数组不同元素数目的平方和 I
//
//int sumCounts(int* nums, int numsSize)
//{
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        bool cnt[101] = { 0 };
//        int sum = 0;
//        for (int j = i; j < numsSize; j++)
//        {
//            if (cnt[nums[j]] == 0)
//            {
//                sum++;
//                cnt[nums[j]] = true;
//            }
//            ans += sum * sum;
//        }
//    }
//
//    return ans;
//}
//
////3736. 最小操作次数使数组元素相等 III
//
//int minMoves(int* nums, int numsSize)
//{
//    int max = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//        {
//            ans += (nums[i] - max) * i;
//            max = nums[i];
//        }
//        else
//            ans += max - nums[i];
//    }
//    return ans;
//}
//
////821. 字符的最短距离
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* shortestToChar(char* s, char c, int* returnSize)
//{
//    int n = strlen(s);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = 10001;
//    }
//    int t = 10001;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == c)
//            t = 0;
//
//        ans[i] = fmin(t, ans[i]);
//        t++;
//    }
//    t = 10001;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (s[i] == c)
//            t = 0;
//
//        ans[i] = fmin(t, ans[i]);
//        t++;
//    }
//    *returnSize = n;
//    return ans;
//}
//
