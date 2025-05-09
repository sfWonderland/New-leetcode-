////1577. 数的平方等于两数乘积的方法数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int cnt(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int ans = 0;
//    long long sum = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        long long x = nums1[i];
//        if (i > 0 && x == nums1[i - 1]) { ans += sum; continue; }
//        long long t1 = x * x - (long long)nums2[0] * nums2[1];
//        if (t1 < 0) continue;
//        long long t2 = x * x - (long long)nums2[nums2Size - 2] * nums2[nums2Size - 1];
//        if (t2 > 0) break;
//        int j = 0, k = nums2Size - 1;
//        sum = 0;
//        while (j < k)
//        {
//            long long tmp = (long long)nums2[j] * nums2[k];
//            if (x * x - tmp < 0)
//                k--;
//            else if (x * x - tmp > 0)
//                j++;
//            else
//            {
//                if (nums2[j] == nums2[k])
//                {
//                    sum += (k - j + 1) * (k - j) / 2;
//                    break;
//                }
//                else
//                {
//                    int numj = 1, numk = 1;
//                    int left = j, right = k;
//                    for (j++; j < right && nums2[j] == nums2[j - 1]; j++) numj++;
//                    for (k--; left < k && nums2[k] == nums2[k + 1]; k--) numk++;
//                    sum += numj * numk;
//                }
//            }
//        }
//        ans += sum;
//    }
//    return ans;
//}
//int numTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    qsort(nums1, nums1Size, sizeof(int), cmp);
//    qsort(nums2, nums2Size, sizeof(int), cmp);
//    int ans = 0;
//    long long sum = 0;
//    if (nums2Size > 1)
//        ans += cnt(nums1, nums1Size, nums2, nums2Size);
//    if (nums1Size > 1)
//        ans += cnt(nums2, nums2Size, nums1, nums1Size);
//    return ans;
//}
//
////923. 三数之和的多种可能
//
//#define MOD 1000000007;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int threeSumMulti(int* arr, int arrSize, int target)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int n = arrSize, ans = 0;
//    long long sum = 0;
//    for (int i = 0; i < n - 2; i++)
//    {
//        int x = arr[i];
//        if (x + arr[n - 2] + arr[n - 1] < target) continue;
//        if (x + arr[i + 1] + arr[i + 2] > target) break;
//        int j = i + 1, k = n - 1;
//        sum = 0;
//        while (j < k)
//        {
//            if (x + arr[j] + arr[k] < target)
//                j++;
//            else if (x + arr[j] + arr[k] > target)
//                k--;
//            else
//            {
//                if (arr[j] == arr[k])
//                {
//                    sum += (k - j + 1) * (k - j) / 2;
//                    break;
//                }
//                else
//                {
//                    int numj = 1, numk = 1;
//                    int left = j, right = k;
//                    for (j++; j < right && arr[j] == arr[j - 1]; j++) numj++;
//                    for (k--; left < k && arr[k] == arr[k + 1]; k--) numk++;
//                    sum += numj * numk;
//                }
//            }
//        }
//        ans = (sum + ans) % MOD;
//    }
//    return ans;
//}
//
////948. 令牌放置
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int bagOfTokensScore(int* tokens, int tokensSize, int power)
//{
//    qsort(tokens, tokensSize, sizeof(int), cmp);
//    int left = 0, right = tokensSize - 1, ans = 0;
//    while (left <= right)
//    {
//        if (power >= tokens[left])
//        {
//            power -= tokens[left];
//            left++; ans++;
//        }
//        else if (ans && left < right)
//        {
//            power += tokens[right];
//            right--; ans--;
//        }
//        else
//            return ans;
//        //printf("%d %d\n", power, ans);
//    }
//    return ans;
//}
//
////42. 接雨水
//
//int trap(int* height, int heightSize)
//{
//    int n = heightSize;
//    int ans = 0, left = 0, right = n - 1;
//    int pre_max = height[left], suf_max = height[right];
//    while (left <= right)
//    {
//        if (pre_max > suf_max)
//        {
//            suf_max = fmax(suf_max, height[right]);
//            ans += suf_max - height[right--];
//        }
//        else
//        {
//            pre_max = fmax(pre_max, height[left]);
//            ans += pre_max - height[left++];
//        }
//    }
//    return ans;
//}
//
