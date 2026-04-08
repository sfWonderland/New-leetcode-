////LCP 39. 无人机方阵
//
//int minimumSwitchingTimes(int** source, int sourceSize, int* sourceColSize, int** target, int targetSize, int* targetColSize)
//{
//    int map[10001] = { 0 };
//    int n = sourceSize * sourceColSize[0];
//    int colors[2 * n + 1];
//    int idx = 1;
//    for (int i = 0; i < sourceSize; i++)
//    {
//        for (int j = 0; j < sourceColSize[i]; j++)
//        {
//            int x = source[i][j];
//            if (!map[x])
//            {
//                map[x] = idx;
//                colors[idx++] = 0;
//            }
//            colors[map[x]]++;
//        }
//    }
//
//    for (int i = 0; i < targetSize; i++)
//    {
//        for (int j = 0; j < targetColSize[i]; j++)
//        {
//            int x = target[i][j];
//            if (!map[x])
//            {
//                map[x] = idx;
//                colors[idx++] = 0;
//            }
//            colors[map[x]]--;
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i < idx; i++)
//    {
//        if (colors[i] > 0)
//            ans += colors[i];
//    }
//    return ans;
//}
//
////    
//
//int compare(int a, int b)
//{
//    if (a == b)
//        return 0;
//    else
//        return a > b ? 1 : -1;
//}
//int temperatureTrend(int* temperatureA, int temperatureASize, int* temperatureB, int temperatureBSize)
//{
//    int n = temperatureASize;
//    int ans = 0, same = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (compare(temperatureA[i - 1], temperatureA[i]) == compare(temperatureB[i - 1], temperatureB[i]))
//        {
//            same++;
//            ans = fmax(same, ans);
//        }
//        else
//        {
//            same = 0;
//        }
//    }
//    return ans;
//}
//
////LCP 55. 采集果实
//
//int getMinimumTime(int* time, int timeSize, int** fruits, int fruitsSize, int* fruitsColSize, int limit)
//{
//    int ans = 0, n = fruitsSize;
//    for (int i = 0; i < n; i++)
//    {
//        int type = fruits[i][0];
//        int num = fruits[i][1];
//        ans += (num + limit - 1) / limit * time[type];
//        // printf("%d %d %d\n", time[type], (num + limit - 1) / limit, ans);
//    }
//    return ans;
//}
//
////LCP 72. 补给马车
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* supplyWagon(int* supplies, int suppliesSize, int* returnSize)
//{
//    int m = suppliesSize / 2;
//    while (suppliesSize > m)
//    {
//        int j = 1;
//        for (int i = 1; i < suppliesSize; i++)
//        {
//            if (supplies[i] + supplies[i - 1] < supplies[j] + supplies[j - 1])
//            {
//                j = i;
//            }
//        }
//        supplies[j - 1] += supplies[j];
//        suppliesSize--;
//        for (; j < suppliesSize; j++)
//        {
//            supplies[j] = supplies[j + 1];
//        }
//    }
//    *returnSize = m;
//    return supplies;
//}
//
