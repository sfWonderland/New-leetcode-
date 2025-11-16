////1024. 视频拼接
//
//int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time)
//{
//    int right_most[time + 1];
//    memset(right_most, 0, sizeof(right_most));
//    for (int i = 0; i < clipsSize; i++)
//    {
//        int right = clips[i][1];
//        int left = clips[i][0];
//        if (left <= time)
//            right_most[left] = fmax(right_most[left], right);
//    }
//    int start = 0, nxt = 0, ans = 0;
//    for (int i = 0; i < time; i++)
//    {
//        nxt = fmax(nxt, right_most[i]);
//        if (start == i)
//        {
//            if (i == nxt)
//                return -1;
//
//            start = nxt;
//            ans++;
//        }
//    }
//    return ans;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time)
//{
//    int n = clipsSize;
//    qsort(clips, n, sizeof(int*), cmp);
//    int start = 0, ans = 0;
//    for (int i = 0; start < time && i < n;)
//    {
//        int nxt = start, flag = 0;
//        while (i < n && clips[i][0] <= start)
//        {
//            nxt = fmax(nxt, clips[i][1]);
//            i++;
//            flag = 1;
//        }
//        if (!flag || start >= nxt)
//            break;
//        start = nxt; ans++;
//    }
//    return start >= time ? ans : -1;
//}
//
////1326. 灌溉花园的最少水龙头数目
//
//int minTaps(int n, int* ranges, int rangesSize)
//{
//    int right_most[n + 1];
//    memset(right_most, 0, sizeof(right_most));
//    for (int i = 0; i <= n; i++)
//    {
//        int r = ranges[i];
//        int left = fmax(0, i - r);
//        right_most[left] = fmax(right_most[left], i + r);
//    }
//    int start = 0, nxt = 0, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        nxt = fmax(nxt, right_most[i]);
//        if (i == start)
//        {
//            if (i == nxt)
//                return -1;
//
//            start = nxt;
//            ans++;
//        }
//    }
//    return ans;
//}
//
////1288. 删除被覆盖区间
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] == (*(int**)e2)[0] ? (*(int**)e2)[1] - (*(int**)e1)[1] : (*(int**)e1)[0] - (*(int**)e2)[0];
//    //按左端点升序，右端点降序
//}
//int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
//{
//    int n = intervalsSize;
//    qsort(intervals, n, sizeof(int*), cmp);
//    int ans = 1, l = intervals[0][0], r = intervals[0][1];
//    for (int i = 1; i < n; i++)
//    {
//        if (intervals[i][1] > r)
//        {
//            r = intervals[i][1];
//            ans++;
//        }
//    }
//    return ans;
//}
//
////462. 最小操作次数使数组元素相等 II
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minMoves2(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int mid = nums[(numsSize - 1) / 2];
//    if (numsSize % 2 == 0)
//        mid = (mid + nums[numsSize / 2]) / 2;
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans += abs(nums[i] - mid);
//    }
//    return ans;
//}
//
