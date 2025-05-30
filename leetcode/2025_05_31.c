////2405. 子字符串的最优划分
//
//int partitionString(char* s)
//{
//    int h = 0, ans = 1;
//    for (int i = 0; s[i]; i++)
//    {
//        int t = 1 << (s[i] - 'a');
//        if ((t & h) == 0)
//            h |= t;
//        else
//        {
//            h = t;
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2294. 划分数组使最大差为 K
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int partitionArray(int* nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = nums[0], ans = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] - left > k)
//        {
//            left = nums[i];
//            ans++;
//        }
//    }
//    return ans;
//}
//
////2358. 分组的最大数量
//
//int maximumGroups(int* grades, int gradesSize)
//{
//    return (int)((sqrt(8 * gradesSize + 1) - 1) / 2);//x(x + 1) / 2 <= gradesSize
//}
//
////2522. 将字符串分割成值不超过 K 的子字符串
//
//int minimumPartition(char* s, int k)
//{
//    long long tmp = 0;
//    if (s[0] - '0' > k)
//        return -1;
//    int n = strlen(s), ans = 1;
//    for (int i = 0; i < n; i++)
//    {
//        tmp = tmp * 10 + s[i] - '0';
//        if (tmp > k)
//        {
//            tmp = s[i] - '0';
//            ans++;
//            if (tmp > k)
//                return -1;
//        }
//    }
//    return ans;
//}
//
