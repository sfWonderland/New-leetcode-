////2739. 总行驶距离
//
//int distanceTraveled(int mainTank, int additionalTank)
//{
//    int used = 0;
//    while (mainTank >= 5)
//    {
//        int groups = mainTank / 5;
//        used += groups * 5;
//        mainTank -= 5 * groups;
//        int add = fmin(groups, additionalTank);
//        additionalTank -= add;
//        mainTank += add;
//    }
//    return (used + mainTank) * 10;
//}
//
////2671. 频率跟踪器  
//
//typedef struct
//{
//    int* nums;
//    int* freq;
//} FrequencyTracker;
//
//
//FrequencyTracker* frequencyTrackerCreate()
//{
//    FrequencyTracker* obj = (FrequencyTracker*)malloc(sizeof(FrequencyTracker));
//    obj->nums = (int*)calloc(sizeof(int), 100001);
//    obj->freq = (int*)calloc(sizeof(int), 200001);
//    return obj;
//}
//
//void frequencyTrackerAdd(FrequencyTracker* obj, int number)
//{
//    //printf("%d %d %d\n", number, obj -> nums[number], obj -> freq[obj -> nums[number]]);
//    if (obj->freq[obj->nums[number]])
//        obj->freq[obj->nums[number]]--;
//    obj->freq[++obj->nums[number]]++;
//    //printf("%d %d %d\n\n", number, obj -> nums[number], obj -> freq[obj -> nums[number]]);
//}
//
//void frequencyTrackerDeleteOne(FrequencyTracker* obj, int number)
//{
//    //printf("%d %d %d\n", number, obj -> nums[number], obj -> freq[obj -> nums[number]]);
//    if (obj->freq[obj->nums[number]])
//        obj->freq[obj->nums[number]]--;
//    if (obj->nums[number])
//        obj->freq[--obj->nums[number]]++;
//    //printf("%d %d %d\n\n", number, obj -> nums[number], obj -> freq[obj -> nums[number]]);
//}
//
//bool frequencyTrackerHasFrequency(FrequencyTracker* obj, int frequency)
//{
//    return obj->freq[frequency];
//}
//
//void frequencyTrackerFree(FrequencyTracker* obj)
//{
//    free(obj->nums);
//    free(obj->freq);
//    free(obj);
//}
//
///**
// * Your FrequencyTracker struct will be instantiated and called as such:
// * FrequencyTracker* obj = frequencyTrackerCreate();
// * frequencyTrackerAdd(obj, number);
//
// * frequencyTrackerDeleteOne(obj, number);
//
// * bool param_3 = frequencyTrackerHasFrequency(obj, frequency);
//
// * frequencyTrackerFree(obj);
//*/
//
////2770. 达到末尾下标所需的最大跳跃次数
//
//int maximumJumps(int* nums, int numsSize, int target)
//{
//    int n = numsSize;
//    int f[n];
//    f[0] = 0;
//    for (int j = 1; j < n; j++)
//    {
//        int res = -1;
//        for (int i = 0; i < j; i++)
//        {
//            if (f[i] >= 0 && abs(nums[j] - nums[i]) <= target)
//            {
//                res = fmax(res, f[i] + 1);
//            }
//        }
//        f[j] = res;
//    }
//    return f[n - 1];
//}
//
////2780. 合法分割的最小下标
//
//int minimumIndex(int* nums, int numsSize)
//{
//    int mode = 0, total = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (total == 0)
//            mode = nums[i];
//
//        total += mode == nums[i] ? 1 : -1;
//    }
//    total = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == mode)
//            total++;
//    }
//    int pre = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        pre += mode == nums[i];
//        if (pre * 2 > i + 1 && (total - pre) * 2 > (numsSize - i - 1))
//            return i;
//    }
//    return -1;
//}
//
