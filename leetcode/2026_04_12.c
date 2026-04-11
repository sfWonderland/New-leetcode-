////101037. 交通信号灯的颜色
//
//char* trafficSignal(int timer)
//{
//    if (timer == 0)
//        return "Green";
//    else if (timer == 30)
//        return "Orange";
//    else if (timer > 30 && timer <= 90)
//        return "Red";
//    else
//        return "Invalid";
//}
//
////101042. 统计数字出现总次数    
//
//int countDigitOccurrences(int* nums, int numsSize, int digit)
//{
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (nums[i])
//        {
//            if (nums[i] % 10 == digit)
//                cnt++;
//
//            nums[i] /= 10;
//        }
//    }
//    return cnt;
//}
//
////101039. 将数组转换为交替质数数组的最少操作次数
//
//#define MX 100004
//int not_prime[MX] = { 0 };
//void sieve()
//{
//    not_prime[1] = 1;
//    for (int i = 2; i * i < MX; i++)
//    {
//        if (!not_prime[i])
//        {
//            for (int j = i * i; j < MX; j += i)
//            {
//                not_prime[j] = 1;
//            }
//        }
//    }
//}
//int minOperations(int* nums, int numsSize)
//{
//    sieve();
//    int ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = nums[i];
//        while (not_prime[x] != i % 2)
//        {
//            x++;
//            ans++;
//        }
//    }
//    return ans;
//}
//
////101040. 连接二进制片段得到的最大值
//
//#define MOD 1000000007
//#define MX 10001
//int pow2[MX] = { 1 };
//// 预处理 2 的幂
//void solve()
//{
//    for (int i = 1; i < MX; i++)
//    {
//        pow2[i] = pow2[i - 1] * 2 % MOD;
//    }
//}
//int* arr1, * arr0;
//// 依次判断：没有 0 的排在最前面，1 多的排前面，0 少的排前面
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1, b = *(int*)e2;
//    if (arr0[a] == 0)
//        return arr0[b] == 0 ? arr1[b] - arr1[a] : -1;
//
//    if (arr0[b] == 0)
//        return 1;
//
//    return arr1[a] == arr1[b] ? arr0[a] - arr0[b] : arr1[b] - arr1[a];
//}
//int maxValue(int* nums1, int nums1Size, int* nums0, int nums0Size)
//{
//    solve();
//    int n = nums1Size;
//    int idx[n];
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    arr1 = nums1, arr0 = nums0;
//    // 依次判断：没有 0 的排在最前面，1 多的排前面，0 少的排前面
//    qsort(idx, n, sizeof(int), cmp);
//
//    long long ans = 0;
//    // 设当前答案为 ans，拼接方法如下：
//    // 1.在 ans 右边拼接 k 个 0，等价于把 ans 左移 k 位，等价于 ans ? 2^k。
//    // 2.在 ans 右边拼接 k 个 1，先左移 k 位（乘以 2^k），再加上 2^k ? 1 
//    //   即 ans ? 2^k + 2^k ? 1 = (ans + 1) ? 2^k ? 1。
//    for (int i = 0; i < n; i++)
//    {
//        int j = idx[i];
//        ans = ((ans + 1) * pow2[nums1[j]] - 1) % MOD * pow2[nums0[j]] % MOD;
//    }
//    return ans;
//}
//
