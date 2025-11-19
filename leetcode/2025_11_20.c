////2645. 构造有效字符串的最少插入数
//
//int addMinimum(char* word)
//{
//    char ch = 0;
//    int n = strlen(word);
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (word[i] == ch + 'a')
//        {
//            ch = ch + 1;
//            continue;
//        }
//        else
//        {
//            int x = word[i] - 'a';
//            ans += (x - ch + 3) % 3;
//            ch = x + 1;
//        }
//    }
//    ans += 'c' - word[n - 1];
//    return ans;
//}
//
////2202. K 次操作后最大化顶端元素
//
//int maximumTop(int* nums, int numsSize, int k)
//{
//    if (numsSize == 1)
//    {
//        if (k & 1)
//            return -1;
//
//        return nums[0];
//    }
//
//    int max = 0;
//    int n = fmin(numsSize, k - 1);
//    for (int i = 0; i < n; i++)
//    {
//        max = fmax(nums[i], max);
//    }
//    if (k < numsSize)
//        max = fmax(nums[k], max);
//    return max;
//}
//
////3674. 数组元素相等的最小操作次数
//
//int minOperations(int* nums, int numsSize)
//{
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] != nums[0])
//            return 1;
//    }
//    return 0;
//}
//
////3675. 转换字符串的最小操作次数
//
//int minOperations(char* s)
//{
//    int ans = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == 'b')
//            return 25;
//        if (s[i] != 'a')
//            ans = fmax('z' + 1 - s[i], ans);
//    }
//    return ans;
//}
//
