////3866. 找到第一个唯一偶数
//
//int firstUniqueEven(int* nums, int numsSize)
//{
//    int cnt[101] = { 0 };
//    int n = numsSize;
//    int queue[n];
//    int rear = 0, front = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] % 2 == 0)
//        {
//            cnt[nums[i]]++;
//            if (cnt[nums[i]] == 1)
//                queue[rear++] = nums[i];
//        }
//        while (front < rear && cnt[queue[front]] > 1)
//            front++;
//    }
//    return rear == front ? -1 : queue[front];
//}
//
////3867. 数对的最大公约数之和    
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
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long gcdSum(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int prefixGcd[n];
//    int max = 0;
//    for (int i = 0; i < n; i++)
//    {
//        max = fmax(max, nums[i]);
//        prefixGcd[i] = gcd(max, nums[i]);
//    }
//    qsort(prefixGcd, n, sizeof(int), cmp);
//    int left = 0, right = n - 1;
//    long long ans = 0;
//    while (left < right)
//    {
//        ans += gcd(prefixGcd[left++], prefixGcd[right--]);
//    }
//    return ans;
//}
//
////3868. 通过交换使数组相等的最小花费
//
//int minCost(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int n = nums1Size;
//    int index[80001] = { 0 };
//    int diff[2 * n + 1];
//    int size = 1;
//    for (int i = 0; i < n; i++)
//    {
//        int x = nums1[i];
//        if (index[x] == 0)
//        {
//            index[x] = size;
//            diff[size++] = 1;
//        }
//        else
//        {
//            diff[index[x]]++;
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int x = nums2[i];
//        if (index[x] == 0)
//        {
//            index[x] = size;
//            diff[size++] = -1;
//        }
//        else
//        {
//            diff[index[x]]--;
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i < size; i++)
//    {
//        if (diff[i] & 1)
//            return -1;
//        ans += abs(diff[i]) / 2;
//    }
//    return ans / 2;
//}
//
////3334. 数组的最大因子得分
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
//long long lcm(long long a, long long b)
//{
//    long long x = a, y = b;
//    while (b)
//    {
//        long long tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return x / a * y;
//}
//long long maxScore(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int suf_gcd[n + 1];
//    long long suf_lcm[n + 1];
//    suf_gcd[n] = 0; suf_lcm[n] = 1;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf_gcd[i] = gcd(suf_gcd[i + 1], nums[i]);
//        suf_lcm[i] = lcm(suf_lcm[i + 1], nums[i]);
//    }
//    long long ans = suf_lcm[0] * suf_gcd[0];
//    int pre_gcd = 0;
//    long long pre_lcm = 1;
//    for (int i = 0; i < n; i++)
//    {
//        int off_gcd = gcd(pre_gcd, suf_gcd[i + 1]);
//        long long off_lcm = lcm(pre_lcm, suf_lcm[i + 1]);
//        ans = fmax(ans, off_lcm * off_gcd);
//        pre_gcd = gcd(pre_gcd, nums[i]);
//        pre_lcm = lcm(pre_lcm, nums[i]);
//    }
//    return ans;
//}
//
