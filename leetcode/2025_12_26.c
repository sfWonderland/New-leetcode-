////2483. 商店的最少代价
//
//int bestClosingTime(char* customers)
//{
//    int n = strlen(customers);
//    int cost[n + 1];
//    cost[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        cost[i] = cost[i + 1] + (customers[i] == 'Y');
//    }
//    int ans = n, time = -1, cost2 = 0;;
//    for (int i = 0; i < n; i++)
//    {
//        if (cost[i] + cost2 < ans)
//        {
//            ans = cost[i] + cost2;
//            time = i;
//        }
//        cost2 += customers[i] == 'N';
//    }
//    if (cost2 < ans)
//        time = n;
//    return time;
//}
//
////871. 最低加油次数
//
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize)
//{
//    int n = stationsSize, ans = 0;
//    if (n == 0)
//        return (startFuel >= target) - 1;
//    int* heap = (int*)malloc(sizeof(int) * n); // MaxHeap
//    int j = 0; // heapSize
//    for (int i = 0; i < n; i++)
//    {
//        while (startFuel < stations[i][0])
//        {
//            if (j == 0)
//            {
//                free(heap);
//                return -1;
//            }
//
//            startFuel += heap[0];
//            heap[0] = heap[--j];
//            down(heap, j, 0);
//            ans++;
//        }
//        heap[j++] = stations[i][1];
//        up(heap, j - 1);
//    }
//    if (startFuel >= target)
//    {
//        free(heap);
//        return ans;
//    }
//    while (j > 0)
//    {
//        startFuel += heap[0];
//        heap[0] = heap[--j];
//        down(heap, j, 0);
//        ans++;
//        if (startFuel >= target)
//        {
//            free(heap);
//            return ans;
//        }
//    }
//    free(heap);
//    return -1;
//}
//
////3362. 零数组变换 III
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e1)[0] - (*(int**)e2)[0];
//}
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
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
//void down(int* heap, int n, int i)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//int maxRemoval(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
//{
//    int m = queriesSize, n = numsSize;
//    qsort(queries, m, sizeof(int*), cmp);
//    int* diff = (int*)calloc(sizeof(int), (n + 1));
//    int* heap = (int*)malloc(sizeof(int) * m);
//    int j = 0, k = 0, sum_d = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum_d += diff[i];
//        while (j < m && queries[j][0] <= i)
//        {
//            heap[k++] = queries[j++][1];
//            up(heap, k - 1);
//        }
//
//        while (sum_d < nums[i] && k && heap[0] >= i)
//        {
//            sum_d++;
//            diff[heap[0] + 1]--;
//            heap[0] = heap[--k];
//            down(heap, k, 0);
//        }
//
//        if (sum_d < nums[i])
//            return -1;
//    }
//    return k;
//}
//
////2813. 子序列最大优雅度
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e2)[0] - (*(int**)e1)[0];
//}
//long long findMaximumElegance(int** items, int itemsSize, int* itemsColSize, int k)
//{
//    int n = itemsSize;
//    qsort(items, n, sizeof(int*), cmp);
//    int* st = (int*)malloc(sizeof(int) * k);
//    int j = 0; // stSize;
//    bool* category = (bool*)calloc(sizeof(bool), (n + 1));
//    long long profits = 0, diff = 0, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int x = items[i][0], y = items[i][1];
//        if (i < k)
//        {
//            profits += x;
//            if (!category[y])
//            {
//                diff++;
//                category[y] = true;
//            }
//            else
//                st[j++] = x;
//        }
//        else if (j && !category[y])
//        {
//            category[y] = true;
//            profits += x - st[--j];
//            diff++;
//        }
//        ans = fmax(ans, profits + diff * diff);
//    }
//    return ans;
//}
//
