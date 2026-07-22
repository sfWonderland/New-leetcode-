//// 3992. 重新排列字符串以避免字符对
//
//char* rearrangeString(char* s, char x, char y)
//{
//    int cnt1 = 0, cnt2 = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == x)
//            cnt1++;
//        else if (s[i] == y)
//            cnt2++;
//    }
//    for (int i = 0; s[i] && cnt1; i++)
//    {
//        if (s[i] == x || s[i] == y)
//        {
//            if (cnt2)
//            {
//                if (s[i] == x)
//                    s[i] = y;
//                cnt2--;
//            }
//            else
//            {
//                if (s[i] == y)
//                    s[i] = x;
//                cnt1--;
//            }
//        }
//    }
//    return s;
//}
//
//// 3993. 交替数列的最大元素    
//
//long long maximumValue(int n, int s, int m)
//{
//    n = n / 2 * 2;
//    return 1ll * n / 2 * m - (n - 1) / 2 + s;
//}
//
//// 3994. 划分数组的最少相邻交换次数
//
//const int MOD = 1e9 + 7;
//int minAdjacentSwaps(int* nums, int numsSize, int a, int b)
//{
//    int n = numsSize;
//    int cnt[2] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        if (nums[i] < a)
//            cnt[0]++;
//        else if (nums[i] > b)
//            cnt[1]++;
//    }
//    int left = 0;
//    long long ans = 0;
//    for (int i = 0; i < n && cnt[0]; i++)
//    {
//        if (nums[i] < a)
//        {
//            ans = (ans + i - left) % MOD;
//            left++;
//            cnt[0]--;
//        }
//    }
//    int right = n - 1;
//    for (int i = n - 1; i >= 0 && cnt[1]; i--)
//    {
//        if (nums[i] < a)
//            right--;
//        else if (nums[i] > b)
//        {
//            ans = (ans + right - i) % MOD;
//            cnt[1]--;
//            right--;
//        }
//    }
//    return ans;
//}
//
