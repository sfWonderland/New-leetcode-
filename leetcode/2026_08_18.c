//// 4020. 电梯请求 I
//
//int elevatorRequests(int n, int* requests, int requestsSize)
//{
//    int sum = requests[0];
//    for (int i = 1; i < requestsSize; i++)
//    {
//        sum += abs(requests[i] - requests[i - 1]);
//    }
//    return sum;
//}
//
//// 4021. 得到旋转回文字符串的最少操作次数 I  
//
//int minOperations(char* s)
//{
//    int n = strlen(s);
//    int ans = INT_MAX;
//    int turn = n & 1 ? n : n / 2;
//    for (int i = 0; i < turn; i++)
//    {
//        int sum = 0, left = i, right = n - 1 + i;
//        // printf("%d\n", i);
//        while (left < right)
//        {
//            char a = s[left % n], b = s[right % n];
//            int d = abs(a - b);
//            sum += fmin(26 - d, d);
//            // printf("%d %d\n", left, right);
//            // printf("%c %c %d %d %d\n", a, b, d, 26 - d, sum);
//            left++; right--;
//        }
//        ans = fmin(ans, sum + i);
//    }
//
//    return ans;
//}
//
//// 4022. 无限字符串里第 K 个数字
//
//int kthDigit(long long k)
//{
//    k--;
//    int len = 1;
//    long long cnt = 9;
//    while (cnt * len <= k)
//    {
//        k -= cnt * len;
//        len++;
//        cnt *= 10;
//    }
//    long long x = k / len + cnt / 9;
//    long long d = x % 10;
//    if ((x / 10) & 1)
//        x += 9 - 2 * d;
//    int pos = len - 1 - k % len;
//    while (pos)
//    {
//        x /= 10;
//        pos--;
//    }
//    return x % 10;
//}
//
