////3471. 找出最大的几近缺失整数
//
//int largestInteger(int* nums, int numsSize, int k)
//{
//    if (numsSize == k)
//    {
//        int max = 0;
//        for (int i = 0; i < numsSize; i++)
//        {
//            max = fmax(max, nums[i]);
//        }
//        return max;
//    }
//    if (1 == k)
//    {
//        int cnt[51] = { 0 };
//        for (int i = 0; i < numsSize; i++)
//        {
//            cnt[nums[i]]++;
//        }
//        int ans = -1;
//        for (int i = 0; i < 51; i++)
//        {
//            if (cnt[i] == 1)
//                ans = fmax(ans, i);
//        }
//        return ans;
//    }
//    if (nums[0] == nums[numsSize - 1])
//        return -1;
//    int flag1 = 0, flag2 = 0;
//    for (int i = 1; i < numsSize - 1; i++)
//    {
//        flag1 |= (nums[i] == nums[0]);
//        flag2 |= (nums[i] == nums[numsSize - 1]);
//    }
//    //printf("%d %d\n", flag1, flag2);
//    if (flag1 && flag2)
//        return -1;
//    else if (flag1 + flag2)
//        return flag2 * nums[0] + flag1 * nums[numsSize - 1];
//    else
//        return fmax(nums[0], nums[numsSize - 1]);
//}
//
////2546. 执行逐位运算使字符串相等
//
//bool makeStringsEqual(char* s, char* target)
//{
//    bool flag2[2] = { false };
//    bool flag1[2] = { false };
//    for (int i = 0; s[i]; i++)
//    {
//        flag1[s[i] - '0'] = true;
//        flag2[target[i] - '0'] = true;
//    }
//
//    return !flag1[1] ? !flag2[1] : flag2[1];
//}
//
////1503. 所有蚂蚁掉下来前的最后一刻
//
//int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize)
//{
//    int max = 0;
//    for (int i = 0; i < leftSize; i++)
//    {
//        max = fmax(left[i], max);
//    }
//    for (int i = 0; i < rightSize; i++)
//    {
//        max = fmax(n - right[i], max);
//    }
//    return max;
//}
//
////2860. 让所有学生保持开心的分组方法数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int countWays(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = nums[0] > 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] < i + 1 && (i == numsSize - 1 || nums[i + 1] > i + 1))
//            ans++;
//    }
//    return ans;
//}
//
