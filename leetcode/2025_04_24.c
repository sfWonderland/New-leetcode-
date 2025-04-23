////3386. 按下时间最长的按钮
//
//int buttonWithLongestTime(int** events, int eventsSize, int* eventsColSize)
//{
//    int max = events[0][1];
//    int dura = max;
//    int index = events[0][0];
//    for (int i = 1; i < eventsSize; i++)
//    {
//        int time = events[i][1] - dura;
//        if (time > max)
//        {
//            max = time;
//            index = events[i][0];
//        }
//        else if (time == max)
//            index = fmin(index, events[i][0]);
//        dura = events[i][1];
//    }
//    return index;
//}
//
////2923. 找到冠军 I
//
//int findChampion(int** grid, int gridSize, int* gridColSize)
//{
//    //打擂台
//    int ret = 0;
//    for (int i = 1; i < gridSize; i++)
//    {
//        if (grid[i][ret])
//            ret = i;
//    }
//    return ret;
//}
//
////2965. 找出缺失和重复的数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) 
// // {
// //     int n = gridSize;
// //     int* hash = (int*)malloc(sizeof(int) * (n * n + 1));
// //     memset(hash, 0, sizeof(int) * (n * n + 1));
// //     for(int i = 0; i < gridSize; i++)
// //     {
// //         for(int j = 0; j < gridColSize[0]; j++)
// //         hash[grid[i][j]]++;
// //     }
// //     int* ans = (int*)malloc(sizeof(int) * (n * n));
// //     int num = 0;
// //     for(int i = 1; i < n * n + 1; i++)
// //     {
// //         if(hash[i] > 1)
// //         ans[num++] = i;
// //     }
// //     for(int i = 1; i < n * n + 1; i++)
// //     {
// //         if(0 == hash[i])
// //         ans[num++] = i;
// //     }
// //     *returnSize = num;
// //     return ans;
// // }
//
//int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize)
//{
//    int n = gridSize;
//    int m = n * n;
//    int d1 = -m * (m + 1) / 2;
//    long long d2 = (long long)-m * (m + 1) * (2 * m + 1) / 6;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[0]; j++)
//        {
//            int x = grid[i][j];
//            d1 += x;
//            d2 += x * x;
//        }
//    }
//    int d = d2 / d1;
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    ret[0] = (d + d1) / 2; ret[1] = (d - d1) / 2;
//    *returnSize = 2;
//    return ret;
//}
//
////3005. 最大频率元素计数
//
//int maxFrequencyElements(int* nums, int numsSize)
//{
//    int hash[101] = { 0 };
//    int max = 1;
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        hash[nums[i]]++;
//        if (hash[nums[i]] > max)
//        {
//            max = hash[nums[i]];
//            ans = max;
//        }
//        else if (hash[nums[i]] == max)
//            ans += max;
//    }
//    return ans;
//}
//
