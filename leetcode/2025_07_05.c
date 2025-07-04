////2844. 生成特殊数字的最少操作
//
//int minimumOperations(char* num)
//{
//    int n = strlen(num);
//    bool found0 = false, found5 = false;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        char c = num[i];
//        if ((found0 && ('5' == c || '0' == c)) || (found5 && ('2' == c || '7' == c)))
//            return n - i - 2;
//
//        if ('0' == c)
//            found0 = true;
//        else  if ('5' == c)
//            found5 = true;
//    }
//    //printf("%d %d", sum1, sum2);
//    return n - found0;
//}
//
////2541. 使数组中所有元素相等的最小操作数 II
//
//long long minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
//{
//    long long ans = 0, sum = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        nums1[i] -= nums2[i];
//        if (k)
//        {
//            if (nums1[i] % k)
//                return -1;
//            if (nums1[i] > 0)
//                ans += nums1[i] / k;
//
//            sum += nums1[i];
//        }
//        else if (nums1[i])
//            return -1;
//    }
//    return 0 == sum ? ans : -1;
//}
//
////2195. 向数组中追加 K 个整数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long minimalKSum(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    // for(int i = 0; i < numsSize; i++)
//    // {
//    //     printf("%d ", nums[i]);
//    // }
//    if (k < nums[0])
//        return (long long)(1 + k) * k / 2;
//    long long ans = (long long)(1 + k) * k / 2;
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//        if (nums[i] <= k)
//        {
//            k++;
//            ans += k - nums[i];
//        }
//        else
//            break;
//    }
//    return ans;
//}
//
////1017. 负二进制转换
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
//char* baseNeg2(int n)
//{
//    if (0 == n)
//        return "0\0";
//    char* ans = (char*)malloc(sizeof(char) * 33);
//    int t = 0, turn = -1;
//    while (n)
//    {
//        ans[t++] = (n & 1) + '0';
//        if (turn > 0)
//            n += turn;
//        n >>= 1;
//        turn = -turn;
//    }
//    ans[t] = '\0';
//    reverse(ans, 0, t - 1);
//    return ans;
//}
//
