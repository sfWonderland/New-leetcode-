////1493. 删掉一个元素以后全为 1 的最长子数组
//
//int longestSubarray(int* nums, int numsSize)
//{
//    int ans = 0, zeros = 0, left = 0;
//    for (int right = 0; right < numsSize; right++)
//    {
//        zeros += (nums[right] == 0);
//
//        while (zeros > 1)
//        {
//            zeros -= (nums[left] == 0);
//            left++;
//        }
//        ans = fmax(ans, right - left);
//    }
//    return ans;
//}
//
////1208. 尽可能使字符串相等
//
//int equalSubstring(char* s, char* t, int maxCost)
//{
//    int ans = 0, cost = 0, left = 0;
//    for (int right = 0; s[right]; ++right)
//    {
//        cost += abs(s[right] - t[right]);
//
//        while (cost > maxCost)
//        {
//            cost -= abs(s[left] - t[left]);
//            left++;
//        }
//        ans = fmax(right - left + 1, ans);
//    }
//    return ans;
//}
//
////904. 水果成篮
//
//int totalFruit(int* fruits, int fruitsSize)
//{
//    int hash[fruitsSize];
//    memset(hash, 0, sizeof(hash));
//    int ans = 0, types = 0, left = 0;
//    for (int right = 0; right < fruitsSize; ++right)
//    {
//        types += (hash[fruits[right]] == 0);
//        ++hash[fruits[right]];
//
//        while (types > 2)
//        {
//            --hash[fruits[left]];
//            types -= (hash[fruits[left]] == 0);
//            left++;
//        }
//        ans = fmax(ans, right - left + 1);
//    }
//    return ans;
//}
//
////1695. 删除子数组的最大得分
//
//int maximumUniqueSubarray(int* nums, int numsSize)
//{
//    int hash[10001] = { 0 };
//    int ans = 0, sum = 0, left = 0;
//    for (int right = 0; right < numsSize; ++right)
//    {
//        sum += nums[right];
//        ++hash[nums[right]];
//
//        while (hash[nums[right]] > 1)
//        {
//            sum -= nums[left];
//            --hash[nums[left]];
//            ++left;
//        }
//        ans = fmax(ans, sum);
//    }
//    return ans;
//}
//
