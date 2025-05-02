////790. 多米诺和托米诺平铺
//
//#define MOD 1000000007
//int numTilings(int n)
//{
//    long long arr[3] = { 1, 2, 5 };
//    if (n < 4)
//        return arr[n - 1];
//
//    for (int i = 3; i < n; ++i)
//    {
//        long long t = (2 * arr[2] + arr[0]) % MOD;
//        arr[0] = arr[1];
//        arr[1] = arr[2];
//        arr[2] = t;
//    }
//    return arr[2];
//}
//
////209. 长度最小的子数组
//
//int minSubArrayLen(int target, int* nums, int numsSize)
//{
//    int ans = numsSize + 1, left = 0, sum = 0;
//    for (int right = 0; right < numsSize; ++right)
//    {
//        sum += nums[right];
//
//        while (sum >= target)
//        {
//            ans = fmin(ans, right - left + 1);
//            sum -= nums[left];
//            ++left;
//        }
//    }
//    return ans > numsSize ? 0 : ans;
//}
//
////1358. 包含所有三种字符的子字符串数目
//
//int numberOfSubstrings(char* s)
//{
//    int arr[3] = { 0 };
//    int ans = 0, left = 0;
//    for (int right = 0; s[right]; ++right)
//    {
//        ++arr[s[right] - 'a'];
//
//        while (arr[0] && arr[1] && arr[2])
//        {
//            --arr[s[left] - 'a'];
//            ++left;
//        }
//        ans += left;
//    }
//    return ans;
//}
//
////930. 和相同的二元子数组
//
//int numSubarraysWithSum(int* nums, int numsSize, int goal)
//{
//    int ans[2] = { 0 }, left[2] = { 0 }, sum[2] = { 0 };
//    for (int right = 0; right < numsSize; ++right)
//    {
//        sum[0] += nums[right];
//        sum[1] += nums[right];
//
//        while (left[0] <= right && sum[0] >= goal)
//        {
//            sum[0] -= nums[left[0]];
//            ++left[0];
//        }
//        ans[0] += left[0];
//        while (left[1] <= right && sum[1] > goal)
//        {
//            sum[1] -= nums[left[1]];
//            ++left[1];
//        }
//        ans[1] += left[1];
//    }
//    return ans[0] - ans[1];
//}
//
