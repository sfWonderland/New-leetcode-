////2302. 统计得分小于 K 的子数组数目
//
//long long countSubarrays(int* nums, int numsSize, long long k) 
//{
//    long long ans = 0, sum = 0;
//    int left = 0;
//    for(int right = 0; right < numsSize; right++)
//    {
//        int n = right - left + 1;
//        sum += nums[right];
//
//        while(sum * n >= k)
//        {
//            sum -= nums[left];
//            left++;
//            n--;
//        }
//        ans += n;
//    }
//    return ans;
//}
//
////LCP 68. 美观的花束
//
//#define MOD 1000000007;
//int beautifulBouquet(int* flowers, int flowersSize, int cnt)
//{
//    int hash[100001] = {0};
//    int ans = 0, left = 0;
//    for(int right = 0; right < flowersSize; right++)
//    {
//        hash[flowers[right]]++;
//
//        while(hash[flowers[right]] > cnt)
//        {
//            hash[flowers[left]]--;
//            left++;
//        }
//        ans =  (ans + right - left + 1) % MOD;
//    }
//    return ans;
//}
//
////825. 适龄的朋友
//
//int numFriendRequests(int* ages, int agesSize) 
//{
//    int cnt[121] = {0};
//    for(int i = 0; i < agesSize; i++)
//    {
//        cnt[ages[i]]++;
//    }
//
//    int ans = 0, cnt_windows = 0, age_y = 0; 
//    for(int age_x = 0; age_x < 121; ++age_x)
//    {
//        cnt_windows += cnt[age_x];
//        if(age_y * 2 <= 14 + age_x)
//        {
//            cnt_windows -= cnt[age_y];
//            age_y++;
//        }
//        if(cnt_windows)
//        ans += cnt[age_x] * cnt_windows - cnt[age_x];
//    }
//    return ans;
//}
//
////658. 找到 K 个最接近的元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) 
//{
//    int left = 0, right = arrSize - 1;
//    while(right - left + 1 > k)
//    {
//        int a = abs(arr[left] - x);
//        int b = abs(arr[right] - x);
//
//        if(a > b)
//        left++;
//        else
//        right--;
//    }
//    *returnSize = k;
//    return arr + left;
//}