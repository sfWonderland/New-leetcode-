////2402. 会议室 III
//
//void up1(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//void up2(long long** heap, int i)
//{
//    long long x = heap[i][0], y = heap[i][1];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if ((heap[j][0] < x) || ((heap[j][0] == x) && heap[j][1] < y))
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i][0] = x;
//    heap[i][1] = y;
//}
//void down1(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void down2(long long** heap, int n, int i)
//{
//    long long x = heap[i][0], y = heap[i][1]; // time, id
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && (heap[j + 1][0] < heap[j][0] || (heap[j + 1][0] == heap[j][0] && heap[j + 1][1] < heap[j][1])))
//            j++;
//
//        if (heap[j][0] > x || ((heap[j][0] == x) && heap[j][1] > y))
//            break;
//
//        heap[i][0] = heap[j][0];
//        heap[i][1] = heap[j][1];
//        i = j;
//    }
//    heap[i][0] = x;
//    heap[i][1] = y;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize)
//{
//    qsort(meetings, meetingsSize, sizeof(int*), cmp);
//    int* cnt = (int*)calloc(sizeof(int), n);
//    int* idle = (int*)malloc(sizeof(int) * n);
//    int idleSize = n;
//    long long** using = (long long**)malloc(sizeof(long long*)* n); // time, id
//    for (int i = 0; i < n; i++)
//    {
//        idle[i] = i;
//        using[i] = (long long*)malloc(sizeof(long long) * 2);
//    }
//    int usingSize = 0;
//    for (int i = 0; i < meetingsSize; i++)
//    {
//        long long start = meetings[i][0], end = meetings[i][1];
//
//        while (usingSize > 0 && using[0][0] <= start)
//        {
//            idle[idleSize++] = using[0][1];
//            up1(idle, idleSize - 1);
//            using[0][0] = using[--usingSize][0];
//            using[0][1] = using[usingSize][1];
//            down2(using, usingSize, 0);
//        }
//
//        int room;
//        if (idleSize > 0)
//        {
//            room = idle[0];
//            idle[0] = idle[--idleSize];
//            down1(idle, idleSize, 0);
//        }
//        else
//        {
//            room = using[0][1];
//            end += using[0][0] - start;
//            using[0][0] = using[--usingSize][0];
//            using[0][1] = using[usingSize][1];
//            down2(using, usingSize, 0);
//        }
//
//        using[usingSize][0] = end;
//        using[usingSize++][1] = room;
//        up2(using, usingSize - 1);
//        cnt[room]++;
//    }
//
//    int max = 0, id = -1;
//    for (int i = 0; i < n; i++)
//    {
//        if (max < cnt[i])
//        {
//            max = cnt[i];
//            id = i;
//        }
//    }
//    free(cnt);
//    free(idle);
//    for (int i = 0; i < n; i++)
//    {
//        free(using[i]);
//    }
//    free(using);
//    return id;
//}
//
////3767. 选择 K 个任务的最大总分数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxPoints(int* technique1, int technique1Size, int* technique2, int technique2Size, int k)
//{
//    int n = technique1Size;
//    long long sum = 0;
//    int* diff = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        sum += technique1[i];
//        diff[i] = technique1[i] - technique2[i];
//    }
//    qsort(diff, n, sizeof(int), cmp);
//    if (diff[n - 1] >= 0)
//        return sum;
//    for (int i = k; i < n; i++)
//    {
//        if (diff[i] < 0)
//            sum -= diff[i];
//    }
//    return sum;
//}
//
////3513. 不同 XOR 三元组的数目 I
//
//int uniqueXorTriplets(int* nums, int numsSize)
//{
//    if (numsSize <= 2)
//        return numsSize;
//    int n = 32 - __builtin_clz(numsSize);
//    return pow(2, n);
//}
//
////3439. 重新安排会议得到最多空余时间 I
//
//int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize)
//{
//    int n = startTimeSize;
//    int* nums = (int*)malloc(sizeof(int) * (n + 1));
//    int numsSize = 0;
//    nums[numsSize++] = startTime[0];
//    for (int i = 1; i < n; i++)
//    {
//        nums[numsSize++] = startTime[i] - endTime[i - 1];
//    }
//    nums[numsSize++] = eventTime - endTime[n - 1];
//
//    int sum = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//
//        if (i < k)
//            continue;
//
//        ans = fmax(ans, sum);
//        sum -= nums[i - k];
//    }
//    free(nums);
//    return ans;
//}
//
