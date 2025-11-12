////2654. 使数组所有元素变成 1 的最少操作次数
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//int minOperations(int* nums, int numsSize)
//{
//    int len = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        if (x == 1)
//        {
//            int ans = numsSize - 1;
//            for (int j = i + 1; j < numsSize; j++)
//            {
//                ans -= (nums[j] == 1);
//            }
//            return ans;
//        }
//        for (int j = i + 1; j < numsSize; j++)
//        {
//            x = gcd(x, nums[j]);
//            if (x == 1)
//            {
//                len = fmin(len, j - i + 1);
//                break;
//            }
//        }
//    }
//    return len == INT_MAX ? -1 : len - 1 + numsSize - 1;
//}
//
////1521. 找到最接近目标值的函数值
//
//int closestToTarget(int* arr, int arrSize, int target)
//{
//    int ans = abs(arr[0] - target);
//    for (int i = 0; i < arrSize; i++)
//    {
//        ans = fmin(abs(arr[i] - target), ans);
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if ((arr[j] & arr[i]) == arr[j])
//                break;
//
//            arr[j] &= arr[i];
//            ans = fmin(abs(arr[j] - target), ans);
//        }
//    }
//    return ans;
//}
//
////3097. 或值至少为 K 的最短子数组 II
//
//int minimumSubarrayLength(int* nums, int numsSize, int k)
//{
//    int len = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] >= k)
//            return 1;
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if ((nums[j] | nums[i]) == nums[j])
//                break;
//
//            nums[j] |= nums[i];
//            if (nums[j] >= k)
//                len = fmin(len, i - j + 1);
//        }
//    }
//    return len == INT_MAX ? -1 : len;
//}
//
////3209. 子数组按位与值为 K 的数目
//
//long long countSubarrays(int* nums, int numsSize, int k)
//{
//    long long ans = 0;
//    int left = 0, right = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if ((nums[j] & nums[i]) == nums[j])
//                break;
//
//            nums[j] &= nums[i];
//        }
//        while (left <= i && nums[left] < k)
//            left++;
//        while (right <= i && nums[right] <= k)
//            right++;
//
//        ans += right - left;
//    }
//    return ans;
//}
//
//long long countSubarrays(int* nums, int numsSize, int k)
//{
//    long long ans = 0;
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt += (nums[i] == k);
//        for (int j = i - 1; j >= 0; j--)
//        {
//            if ((nums[j] & nums[i]) == nums[j])
//                break;
//            cnt -= (nums[j] == k);
//            nums[j] &= nums[i];
//            cnt += (nums[j] == k);
//        }
//        ans += cnt;
//    }
//    return ans;
//}
//
