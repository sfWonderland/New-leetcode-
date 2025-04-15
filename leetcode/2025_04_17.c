////2465. 不同的平均值数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int distinctAverages(int* nums, int numsSize)
//{
//    int hash[201] = { 0 };
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = 0;
//    int right = numsSize - 1;
//    int ret = 0;
//    while (left < right)
//    {
//        int sum = nums[left++] + nums[right--];
//        if (hash[sum] == 0)
//        {
//            hash[sum] = 1;
//            ret++;
//        }
//    }
//    return ret;
//}
//
////2446. 判断两个事件是否存在冲突
//
//bool haveConflict(char** event1, int event1Size, char** event2, int event2Size)
//{
//    return !(strcmp(event1[1], event2[0]) < 0 || strcmp(event2[1], event1[0]) < 0);
//}
//
////2441. 与对应负数同时存在的最大正整数
//
//int findMaxK(int* nums, int numsSize)
//{
//    int hash[1001] = { 0 };
//    int ret = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int t = abs(nums[i]);
//        if (hash[t] == 0)
//            hash[t] = nums[i];
//        else if (hash[t] + nums[i] == 0)
//            ret = ret > t ? ret : t;
//    }
//    return ret;
//}
//
////2582. 递枕头
//
//int passThePillow(int n, int time)
//{
//    int turn = (time - 1) / (n - 1);
//    return turn % 2 ? (turn + 1) * (n - 1) + 1 - time : time - (n - 1) * turn + 1;
//}
//
