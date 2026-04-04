////3572. 选择不同 X 值三元组使 Y 值之和最大
//
//int* arr;
//int cmp(const void* e1, const void* e2)
//{
//    return arr[*(int*)e2] - arr[*(int*)e1];
//}
//int maxSumDistinctTriplet(int* x, int xSize, int* y, int ySize)
//{
//    int n = xSize;
//    int idx[n];
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    arr = y;
//    qsort(idx, n, sizeof(int), cmp);
//    int m = 1, ans = y[idx[0]];
//    int x0 = x[idx[0]], x1 = -1;
//    for (int i = 1; i < n && m < 3; i++)
//    {
//        int j = idx[i];
//        if (x[j] != x0)
//        {
//            if (m < 2)
//            {
//                ans += y[j];
//                x1 = x[j];
//                m++;
//            }
//            else if (x1 != x[j])
//            {
//                ans += y[j];
//                m++;
//            }
//        }
//    }
//    return m == 3 ? ans : -1;
//}
//
////3582. 为视频标题生成标签    
//
//char* generateTag(char* caption)
//{
//    int n = strlen(caption);
//    char* ans = (char*)malloc(sizeof(char) * (n + 2));
//    ans[0] = '#', ans[1] = '\0';
//    for (char* s = strtok(caption, " "); s; s = strtok(NULL, " "))
//    {
//        s[0] &= 95;
//        for (int i = 1; s[i]; i++)
//        {
//            s[i] |= 32;
//        }
//        strcat(ans, s);
//    }
//    if (ans[1])
//        ans[1] |= 32;
//    if (n + 2 > 100)
//        ans[100] = '\0';
//    return ans;
//}
//
////3633. 最早完成陆地和水上游乐设施的时间 I
//
//int solve(int* StartTimeA, int* DurationA, int ASize, int* StartTimeB, int* DurationB, int BSize)
//{
//    int first_finish = INT_MAX;
//    for (int i = 0; i < ASize; i++)
//    {
//        first_finish = fmin(first_finish, StartTimeA[i] + DurationA[i]);
//    }
//    int res = INT_MAX;
//    for (int i = 0; i < BSize; i++)
//    {
//        res = fmin(res, fmax(first_finish, StartTimeB[i]) + DurationB[i]);
//    }
//    return res;
//}
//int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize)
//{
//    int land_water = solve(landStartTime, landDuration, landDurationSize, waterStartTime, waterDuration, waterDurationSize);
//    int water_land = solve(waterStartTime, waterDuration, waterDurationSize, landStartTime, landDuration, landDurationSize);
//    return fmin(land_water, water_land);
//}
//
////3635. 最早完成陆地和水上游乐设施的时间 II
//
//int solve(int* StartTimeA, int* DurationA, int ASize, int* StartTimeB, int* DurationB, int BSize)
//{
//    int first_finish = INT_MAX;
//    for (int i = 0; i < ASize; i++)
//    {
//        first_finish = fmin(first_finish, StartTimeA[i] + DurationA[i]);
//    }
//    int res = INT_MAX;
//    for (int i = 0; i < BSize; i++)
//    {
//        res = fmin(res, fmax(first_finish, StartTimeB[i]) + DurationB[i]);
//    }
//    return res;
//}
//int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize)
//{
//    int land_water = solve(landStartTime, landDuration, landDurationSize, waterStartTime, waterDuration, waterDurationSize);
//    int water_land = solve(waterStartTime, waterDuration, waterDurationSize, landStartTime, landDuration, landDurationSize);
//    return fmin(land_water, water_land);
//}
//
