////3823. 反转一个字符串里的字母后反转特殊字符
//
//char* reverseByType(char* s)
//{
//    int n = strlen(s);
//    int left1 = 0, right1 = n - 1;
//    int left2 = 0, right2 = n - 1;
//    while (left1 < right1)
//    {
//        while (left1 < right1 && (s[left1] < 'a' || s[left1] > 'z'))
//            left1++;
//        while (left1 < right1 && (s[right1] < 'a' || s[right1] > 'z'))
//            right1--;
//
//        int tmp = s[left1];
//        s[left1++] = s[right1];
//        s[right1--] = tmp;
//    }
//    while (left2 < right2)
//    {
//        while (left2 < right2 && (s[left2] >= 'a' && s[left2] <= 'z'))
//            left2++;
//        while (left2 < right2 && (s[right2] >= 'a' && s[right2] <= 'z'))
//            right2--;
//
//        int tmp = s[left2];
//        s[left2++] = s[right2];
//        s[right2--] = tmp;
//    }
//    return s;
//}
//
////3824. 减小数组使其满足条件的最小 K 值    
//
//bool check(int* nums, int numsSize, int k)
//{
//    long long t = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        t += (nums[i] + k - 1) / k;
//    }
//    return t <= 1ll * k * k;
//}
//int binary_search(int* nums, int numsSize, int left, int right)
//{
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (check(nums, numsSize, mid))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int minimumK(int* nums, int numsSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        max = fmax(nums[i], max);
//    }
//    int left = pow(max, 1.0 / 3);
//    if (pow(max, 1.0 / 3) > left)
//        left++;
//    int right = fmax(max, numsSize);
//    //printf("%lld %lld\n", left, right);
//    return binary_search(nums, numsSize, left, right);
//}
//
////3825. 按位与结果非零的最长上升子序列
//
//int lower_bound(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int longestSubsequence(int* nums, int numsSize)
//{
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (max < nums[i])
//            max = nums[i];
//    }
//
//    if (!max) return 0;
//
//    int w = 32 - __builtin_clz(max);
//    int ans = 0;
//    int* f = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < w; i++)
//    {
//        int size = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if ((nums[j] >> i & 1) == 0)
//                continue;
//
//            int k = lower_bound(f, size, nums[j]);
//            f[k] = nums[j];
//
//            if (k == size)
//                size++;
//        }
//        ans = fmax(size, ans);
//    }
//    return ans;
//}
//
////3612. 用特殊操作处理字符串 I
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* processStr(char* s)
//{
//    int n = strlen(s);
//    int capacity = n + 1;
//    char* ans = (char*)malloc(sizeof(char) * capacity);
//    int k = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] >= 'a' && s[i] <= 'z')
//            ans[k++] = s[i];
//        else if (s[i] == '*' && k)
//            k--;
//        else if (s[i] == '#')
//        {
//            strncpy(ans + k, ans, k);
//            k *= 2;
//        }
//        else
//            reverse(ans, 0, k - 1);
//
//        if (k >= capacity / 2)
//        {
//            capacity *= 2;
//            ans = realloc(ans, sizeof(char) * capacity);
//        }
//    }
//    ans[k] = '\0';
//    return ans;
//}
//
