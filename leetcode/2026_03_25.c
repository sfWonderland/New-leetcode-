////2899. 上一个遍历的整数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* lastVisitedIntegers(int* nums, int numsSize, int* returnSize)
//{
//    int n = numsSize;
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int seen[n];
//    int ansSize = 0, pos = 0, k = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//        {
//            seen[pos++] = nums[i];
//            k = 0;
//        }
//        else
//        {
//            if (k < pos)
//                ans[ansSize++] = seen[pos - 1 - k];
//            else
//                ans[ansSize++] = -1;
//
//            k++;
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////2908. 元素和最小的山形三元组 I    
//
//int minimumSum(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int suf[n];
//    suf[n - 1] = nums[n - 1];
//    for (int i = n - 2; i >= 0; i--)
//    {
//        suf[i] = fmin(nums[i], suf[i + 1]);
//    }
//    int pre = nums[0], ans = INT_MAX;
//    for (int j = 1; j < numsSize - 1; j++)
//    {
//        if (pre < nums[j] && nums[j] > suf[j + 1])
//            ans = fmin(ans, pre + nums[j] + suf[j + 1]);
//        pre = fmin(pre, nums[j]);
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
////2932. 找出强数对的最大异或值 I
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int maximumStrongPairXor(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = i + 1; j < numsSize && nums[j] <= 2 * nums[i]; j++)
//        {
//            ans = fmax(ans, nums[i] ^ nums[j]);
//        }
//    }
//    return ans;
//}
//
////2933. 高访问员工
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    char** a = *(char***)e1;
//    char** b = *(char***)e2;
//    int flag = strcmp(a[0], b[0]);
//    return flag == 0 ? strcmp(a[1], b[1]) : flag;
//}
//char** findHighAccessEmployees(char*** access_times, int access_timesSize, int* access_timesColSize, int* returnSize)
//{
//    int n = access_timesSize;
//    qsort(access_times, n, sizeof(char**), cmp);
//    char** ans = (char**)malloc(sizeof(char*) * n / 3);
//    int pos = 0, pre = 0, flag = 0;
//    int minutes[n];
//    for (int i = 0; i < n; i++)
//    {
//        char* s = access_times[i][0];
//        char* time = access_times[i][1];
//        minutes[i] = time[0] * 600 + time[1] * 60 + time[2] * 10 + time[3] - 671 * '0';
//        // printf("%d %s %s %d %d\n", i, s, time, minutes[i], pre);
//        if (i > 0 && strcmp(s, access_times[i - 1][0]) == 0)
//        {
//            while (minutes[i] - minutes[pre] >= 60)
//            {
//                pre++;
//            }
//
//            if (!flag && i - pre >= 2)
//                flag = true;
//        }
//        else
//        {
//            if (flag)
//                ans[pos++] = access_times[i - 1][0];
//
//            flag = false;
//            pre = i;
//        }
//    }
//    if (flag)
//        ans[pos++] = access_times[n - 1][0];
//
//    *returnSize = pos;
//    return ans;
//}
//
