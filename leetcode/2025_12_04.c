////1775. 通过最少操作次数使数组的和相等
//
//int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    if (nums1Size > nums2Size * 6 || nums1Size * 6 < nums2Size)
//        return -1;
//
//    int d = 0;
//    for (int i = 0; i < nums1Size; i++) d += nums1[i];
//    for (int i = 0; i < nums2Size; i++) d -= nums2[i];
//
//    //nums1和大，nums2和小
//    if (d < 0)
//    {
//        d = -d;
//        int* tmp = nums1;
//        nums1 = nums2;
//        nums2 = tmp;
//        int t = nums1Size;
//        nums1Size = nums2Size;
//        nums2Size = t;
//    }
//
//    int cnt[6] = { 0 };
//    for (int i = 0; i < nums1Size; i++) cnt[nums1[i] - 1]++;
//    for (int i = 0; i < nums2Size; i++) cnt[6 - nums2[i]]++;
//
//    for (int i = 5, ans = 0; ; i--)
//    {
//        if (i * cnt[i] >= d)
//            return ans + (d + i - 1) / i;
//
//        ans += cnt[i];
//        d -= i * cnt[i];
//    }
//    return -1;
//}
//
////3440. 重新安排会议得到最多空余时间 II
//
//int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime, int endTimeSize)
//{
//    int n = startTimeSize;
//    int get(int i)
//    {
//        if (i == 0)
//            return startTime[0];
//
//        if (i == n)
//            return eventTime - endTime[n - 1];
//
//        return startTime[i] - endTime[i - 1];
//    }
//
//    int a = 0, b = -1, c = -1; // 前三大空位的下标
//    for (int i = 1; i <= n; i++)
//    {
//        int sz = get(i);
//        if (sz > get(a))
//        {
//            c = b; b = a; a = i;
//        }
//        else if (b < 0 || sz > get(b))
//        {
//            c = b; b = i;
//        }
//        else if (c < 0 || sz > get(c))
//            c = i;
//    }
//
//    int ans = 0;
//    //枚举桌子
//    for (int i = 0; i < n; i++)
//    {
//        int sz = endTime[i] - startTime[i];
//        if (i != a && i + 1 != a && sz <= get(a) //移到最大的空区间
//            || i != b && i + 1 != b && sz <= get(b) //移到次大的空区间
//            || sz <= get(c)) // 说明左右是前二大的空区间，移到第三大的空区间
//            ans = fmax(ans, sz + get(i) + get(i + 1)); //能移走，空位大小为桌子大小和左右空位大小之和
//        else
//            ans = fmax(ans, get(i) + get(i + 1)); //不能移走，在左右空位内平移，大小为左右空位大小之和
//    }
//    return ans;
//}
//
//int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime, int endTimeSize)
//{
//    int n = startTimeSize;
//    int get(int i)
//    {
//        if (i == 0)
//            return startTime[0];
//
//        if (i == n)
//            return eventTime - endTime[n - 1];
//
//        return startTime[i] - endTime[i - 1];
//    }
//
//    int* blank = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i <= n; i++)
//    {
//        blank[i] = get(i);
//    }
//    int a = 0, b = -1, c = -1; // 前三大空位的下标
//    for (int i = 1; i <= n; i++)
//    {
//        int sz = blank[i];
//        if (sz > blank[a])
//        {
//            c = b; b = a; a = i;
//        }
//        else if (b < 0 || sz > blank[b])
//        {
//            c = b; b = i;
//        }
//        else if (c < 0 || sz > blank[c])
//            c = i;
//    }
//
//    int ans = 0;
//    //枚举桌子
//    for (int i = 0; i < n; i++)
//    {
//        int sz = endTime[i] - startTime[i];
//        //能移走，空位大小为桌子大小和左右空位大小之和
//        if (i != a && i + 1 != a && sz <= blank[a] //移到最大的空区间
//            || i != b && i + 1 != b && sz <= blank[b] //移到次大的空区间
//            || sz <= blank[c]) // 说明左右是前二大的空区间，移到第三大的空区间
//            ans = fmax(ans, sz + blank[i] + blank[i + 1]);
//        //不能移走，在左右空位内平移，大小为左右空位大小之和
//        else
//            ans = fmax(ans, blank[i] + blank[i + 1]);
//    }
//    free(blank);
//    return ans;
//}
//
////2333. 最小差值平方和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2)
//{
//    int n = nums1Size, k = k1 + k2;
//    long long ans = 0, sum = 0;
//    int* nums = (int*)malloc(sizeof(int) * (1 + n));
//    for (int i = 0; i < n; i++)
//    {
//        nums[i] = abs(nums1[i] - nums2[i]);
//        sum += nums[i];
//        ans += 1ll * nums[i] * nums[i];
//    }
//    if (k >= sum)
//        return 0;
//
//    nums[n] = 0; //哨兵
//    qsort(nums, n + 1, sizeof(int), cmp);
//    for (int i = 0; ; i++)
//    {
//        // j : 下一个元素下标, 当前元素个数； v : 本元素值； 
//        // c : 将从0到i的所有元素改为下一个元素所需的变化次数；
//        long long j = i + 1, v = nums[i], c = j * (v - nums[j]);
//        //撤销之前加和
//        ans -= v * v;
//        //次数允许下，全部变换
//        if (c < k)
//        {
//            k -= c;
//            continue;
//        }
//
//        //次数不允许的条件下，只能变一部分
//        //v : 每个元素最大值；最小值为v - 1；
//        v -= k / j;
//        return ans + k % j * (v - 1) * (v - 1) + (j - k % j) * v * v;
//    }
//    return -1;
//}
//
////1702. 修改后的最大二进制字符串
//
//char* maximumBinaryString(char* binary)
//{
//    int n = strlen(binary), i = 0;
//    while (i < n && binary[i] != '0')
//        i++;
//    if (i == n)
//        return binary;
//
//    int cnt1 = 0;
//    for (; i < n; i++)
//    {
//        cnt1 += binary[i] - '0';
//    }
//    for (int j = 0; j < n; j++)
//    {
//        binary[j] = '1';
//    }
//    binary[n - 1 - cnt1] = '0';
//    return binary;
//}
//
