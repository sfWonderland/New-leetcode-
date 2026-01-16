////1465. 切割后面积最大的蛋糕
//
//const int MOD = 1e9 + 7;
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int f(int* nums, int numsSize, int n)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int max = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        max = fmax(nums[i] - nums[i - 1], max);
//    }
//    max = fmax(nums[0] - 0, max);
//    max = fmax(n - nums[numsSize - 1], max);
//    return max;
//}
//int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize)
//{
//    return 1ll * f(horizontalCuts, horizontalCutsSize, h) * f(verticalCuts, verticalCutsSize, w) % MOD;
//}
//
////1887. 使数组元素相等的减少操作次数    
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int reductionOperations(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] != nums[i - 1])
//            ans += i;
//    }
//    return ans;
//}
//
////3039. 进行操作使字符串为空
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//char* lastNonEmptyString(char* s)
//{
//    int cnt[26] = { 0 }, last[26] = { 0 };
//    for (int i = 0; s[i]; i++)
//    {
//        cnt[s[i] - 'a']++;
//        last[s[i] - 'a'] = i;
//    }
//    int max = 0, n = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (max < cnt[i])
//        {
//            max = cnt[i];
//            n = 1;
//        }
//        else if (max == cnt[i])
//            n++;
//    }
//    int* idx = (int*)malloc(sizeof(int) * n);
//    int k = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (cnt[i] == max)
//        {
//            idx[k++] = last[i];
//        }
//    }
//    qsort(idx, n, sizeof(int), cmp);
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[n] = '\0';
//    for (int i = 0; i < n; i++)
//    {
//        ans[i] = s[idx[i]];
//    }
//    return ans;
//}
//
////1701. 平均等待时间
//
//double averageWaitingTime(int** customers, int customersSize, int* customersColSize)
//{
//    long long cur = 0, tot = 0;
//    for (int i = 0; i < customersSize; i++)
//    {
//        if (cur < customers[i][0])
//            cur = customers[i][0];
//
//        cur += customers[i][1];
//        tot += cur - customers[i][0];
//    }
//    return 1.0 * tot / customersSize;
//}
//
