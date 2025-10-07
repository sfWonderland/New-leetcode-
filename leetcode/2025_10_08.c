////2208. 将数组和减半的最少操作次数
//
//void HeapDown(double* nums, int i, int n)
//{
//    double x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] > nums[j])
//            j++;
//        if (nums[j] <= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void BuildMaxHeap(double* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(double* nums, int n)
//{
//    BuildMaxHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//int halveArray(int* nums, int numsSize)
//{
//    double sum = 0;
//    double* heap = (double*)malloc(sizeof(double) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum = sum + nums[i];
//        heap[i] = (double)nums[i];
//    }
//    HeapSort(heap, numsSize);
//    int ans = 0;
//    double minus = 0;
//    while (minus < sum / 2.0)
//    {
//        ans++;
//        heap[0] = heap[0] / 2.0;
//        minus += heap[0];
//        HeapDown(heap, 0, numsSize);
//    }
//    return ans;
//}
//
////2233. K 次增加后的最大乘积
//
//const int MOD = 1e9 + 7;
//void HeapDown(int* nums, int i, int n)
//{
//    int x = nums[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1] < nums[j])
//            j++;
//        if (nums[j] >= x)
//            break;
//        nums[i] = nums[j];
//        i = j;
//    }
//    nums[i] = x;
//}
//void BuildMinHeap(int* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(int* nums, int n)
//{
//    BuildMinHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//int maximumProduct(int* nums, int numsSize, int k)
//{
//    if (numsSize == 1)
//        return nums[0] + k;
//    if (numsSize == 2)
//    {
//        long long x = fmax(nums[0], nums[1]);
//        long long y = nums[0] + nums[1] - x;
//        if (x - y > k)
//            return x * (y + k) % MOD;
//        else
//        {
//            int sum = nums[0] + nums[1] + k;
//            x = sum / 2;
//            y = sum - x;
//            return x * y % MOD;
//        }
//    }
//    HeapSort(nums, numsSize);
//    while (k)
//    {
//        int nxt = fmin(nums[1], nums[2]);
//        int d = nxt - nums[0];
//        if (k <= d)
//        {
//            nums[0] += k;
//            k = 0;
//        }
//        else
//        {
//            nums[0] += d + 1;
//            k -= d + 1;
//            HeapDown(nums, 0, numsSize);
//        }
//    }
//    long long ans = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        ans = ans * nums[i] % MOD;
//    }
//    return ans;
//}
//
////3296. 移山所需的最少秒数
//
//typedef struct
//{
//    long long key;
//    int val;
//    int base;
//}Heap;
//void HeapDown(Heap* nums, int i, int n)
//{
//    long long x = nums[i].key;
//    int y = nums[i].val;
//    int z = nums[i].base;
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && nums[j + 1].key < nums[j].key)
//            j++;
//        if (nums[j].key >= x)
//            break;
//        nums[i].key = nums[j].key;
//        nums[i].val = nums[j].val;
//        nums[i].base = nums[j].base;
//        i = j;
//    }
//    nums[i].key = x;
//    nums[i].val = y;
//    nums[i].base = z;
//}
//void BuildMinHeap(Heap* nums, int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//    {
//        HeapDown(nums, i, n);
//    }
//}
//void HeapSort(Heap* nums, int n)
//{
//    BuildMinHeap(nums, n);
//    for (int i = n - 1; i > 0; i--)
//    {
//        HeapDown(nums, 0, i);
//    }
//}
//long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize)
//{
//    Heap* heap = (Heap*)malloc(sizeof(Heap) * workerTimesSize);
//    for (int i = 0; i < workerTimesSize; i++)
//    {
//        heap[i].key = (long long)workerTimes[i];
//        heap[i].base = (long long)workerTimes[i];
//        heap[i].val = 1;
//    }
//    HeapSort(heap, workerTimesSize);
//    long long ans = 0;
//    while (mountainHeight--)
//    {
//        heap[0].val++;
//        ans = fmax(heap[0].key, ans);
//        heap[0].key = 1ll * heap[0].base * (heap[0].val + 1) * heap[0].val / 2;
//        //printf("%lld %lld %lld %lld\n", ans, heap[0].key, heap[0].val, heap[0].base);
//        HeapDown(heap, 0, workerTimesSize);
//    }
//    return ans;
//}
//
//bool check(int* nums, int n, int h, long long mid)
//{
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += (-1 + (int)sqrt(1 + 8 * (long long)(mid / nums[i]))) / 2;
//        if (sum >= h)
//            return true;
//    }
//    return false;
//}
//long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize)
//{
//    long long left = 0, right = workerTimes[0];
//    for (int i = 0; i < workerTimesSize; i++)
//    {
//        right = fmax(right, workerTimes[i]);
//    }
//    right = right * mountainHeight * (mountainHeight + 1) / 2;
//    while (left < right)
//    {
//        long long mid = left + (right - left) / 2;
//        if (check(workerTimes, workerTimesSize, mountainHeight, mid))
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return right;
//}
//
////LCR 042. 最近的请求次数
//
//typedef struct
//{
//    int* queue;
//    int top;
//    int bottom;
//} RecentCounter;
//
//
//RecentCounter* recentCounterCreate()
//{
//    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
//    obj->queue = (int*)malloc(sizeof(int) * 10001);
//    obj->top = 0;
//    obj->bottom = 0;
//    return obj;
//}
//
//int recentCounterPing(RecentCounter* obj, int t)
//{
//    obj->queue[obj->top++] = t;
//    while (obj->bottom < obj->top && obj->queue[obj->bottom] < t - 3000)
//        obj->bottom++;
//    return obj->top - obj->bottom;
//}
//
//void recentCounterFree(RecentCounter* obj)
//{
//    free(obj->queue);
//    free(obj);
//}
//
///**
// * Your RecentCounter struct will be instantiated and called as such:
// * RecentCounter* obj = recentCounterCreate();
// * int param_1 = recentCounterPing(obj, t);
//
// * recentCounterFree(obj);
//*/
//
