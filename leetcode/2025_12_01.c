////2141. 同时运行 N 台电脑的最长时间
//
//long long maxRunTime(int n, int* batteries, int batteriesSize)
//{
//    long long tot = 0;
//    for (int i = 0; i < batteriesSize; i++)
//    {
//        tot += batteries[i];
//    }
//    long long left = 0, right = tot / n;
//    while (left <= right)
//    {
//        long long x = (left + right) / 2;
//        long long sum = 0;
//        for (int i = 0; i < batteriesSize; i++)
//        {
//            sum += fmin(batteries[i], x);
//        }
//        if (n * x <= sum)
//            left = x + 1;
//        else
//            right = x - 1;
//    }
//    return left - 1;
//}
//
//long long maxRunTime(int n, int* batteries, int batteriesSize)
//{
//    long long tot = 0;
//    int max = 0;
//    for (int i = 0; i < batteriesSize; i++)
//    {
//        tot += batteries[i];
//        max = fmax(max, batteries[i]);
//    }
//    if (tot >= 1ll * max * n)
//        return tot / n;
//    long long left = 0, right = tot / n;
//    while (left <= right)
//    {
//        long long x = (left + right) / 2;
//        long long sum = 0;
//        int m = n;
//        for (int i = 0; i < batteriesSize; i++)
//        {
//            if (x <= batteries[i])
//                m--;
//            else
//                sum += batteries[i];
//        }
//        if (m * x <= sum)
//            left = x + 1;
//        else
//            right = x - 1;
//    }
//    return left - 1;
//}
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxRunTime(int n, int* batteries, int batteriesSize)
//{
//    long long tot = 0;
//    int max = 0;
//    for (int i = 0; i < batteriesSize; i++)
//    {
//        tot += batteries[i];
//        max = fmax(max, batteries[i]);
//    }
//    if (tot >= 1ll * max * n)
//        return tot / n;
//    qsort(batteries, batteriesSize, sizeof(int), cmp);
//    for (int i = 0; ; i++)
//    {
//        if (batteries[i] <= tot / n)
//            return tot / n;
//
//        tot -= batteries[i];
//        n--;
//    }
//    return -1;
//}
//
////3618. 根据质数下标分割数组
//
//bool f(int x)
//{
//    if (x <= 1)
//        return false;
//
//    for (int i = 2; i * i <= x; i++)
//    {
//        if (x % i == 0)
//            return false;
//    }
//    return true;
//}
//long long splitArray(int* nums, int numsSize)
//{
//    long long sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += f(i) ? -nums[i] : nums[i];
//    }
//    return fabs(sum);
//}
//
//long long splitArray(int* nums, int numsSize)
//{
//    if (numsSize == 1)
//        return fabs(nums[0]);
//
//    long long sum = 1ll * nums[0] + nums[1];
//    bool isPrime[numsSize + 1];
//    memset(isPrime, 1, sizeof(isPrime));
//    for (int i = 2; i < numsSize; i++)
//    {
//        if (isPrime[i])
//        {
//            sum -= nums[i];
//
//            for (int j = i; j <= numsSize / i; j++)
//            {
//                isPrime[i * j] = 0;
//            }
//        }
//        else
//            sum += nums[i];
//    }
//    return fabs(sum);
//}
//
////593. 有效的正方形
//
//int dist(int* p1, int* p2)
//{
//    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
//}
//int cmp(const void* e1, const void* e2)
//{
//    int a = (*(int**)e1)[0] * 10001 + (*(int**)e1)[1];
//    int b = (*(int**)e2)[0] * 10001 + (*(int**)e2)[1];
//    return a - b;
//}
//bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size)
//{
//    int** arr = (int**)malloc(sizeof(int*) * 4);
//    arr[0] = p1; arr[1] = p2;
//    arr[2] = p3; arr[3] = p4;
//    qsort(arr, 4, sizeof(int*), cmp);
//    int nums[4] = { 0 };
//    nums[0] = dist(arr[0], arr[1]);
//    nums[1] = dist(arr[1], arr[3]);
//    nums[2] = dist(arr[0], arr[2]);
//    nums[3] = dist(arr[2], arr[3]);
//    for (int i = 0; i < 3; i++)
//    {
//        if (nums[i] != nums[i + 1] || nums[i] == 0)
//            return false;
//    }
//    int a = dist(arr[0], arr[3]);
//    int b = dist(arr[2], arr[1]);
//    if (sqrt(1ll * a * b) / 2 - nums[0])
//        return false;
//    return true;
//}
//
////3648. 覆盖网格的最少传感器数目
//
//int minSensors(int n, int m, int k)
//{
//    return ((n + 2 * k) / (2 * k + 1)) * ((m + 2 * k) / (2 * k + 1));
//}
//
