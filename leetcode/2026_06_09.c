//// 3954. 区间内的兼容数字之和 I
//
//int sumOfGoodIntegers(int n, int k)
//{
//    int sum = 0;
//    for (int x = fmax(0, n - k); x <= n + k; x++)
//    {
//        if ((n & x) == 0)
//            sum += x;
//    }
//    return sum;
//}
//
//// 3955. 成本限制的有效二进制字符串    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** ans;
//int ansSize;
//
//char* path;
//int pathSize;
//
//int len;
//
//void dfs(int i, int k)
//{
//    if (i < 0)
//    {
//
//        ans[ansSize] = (char*)malloc(sizeof(char) * (len + 1));
//        strcpy(ans[ansSize++], path);
//        return;
//    }
//
//    if (i <= k)
//    {
//        path[i] = '1';
//        if (i > 0)
//            path[i - 1] = '0';
//        dfs(i - 2, k - i);
//    }
//    path[i] = '0';
//    dfs(i - 1, k);
//}
//
//char** generateValidStrings(int n, int k, int* returnSize)
//{
//    int m = 1 << n;
//    ans = (char**)malloc(sizeof(char*) * m);
//    ansSize = 0;
//
//    len = n;
//
//    path = (char*)malloc(sizeof(char) * (n + 1));
//    path[n] = '\0';
//    pathSize = 0;
//
//    dfs(n - 1, k);
//
//    *returnSize = ansSize;
//    return ans;
//}
//
//// 3956. M 个非重叠子数组最大和 I
//
//long long maximumSum(int* nums, int numsSize, int m, int l, int r)
//{
//    int n = numsSize;
//    long long pre[n + 1];
//    pre[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre[i + 1] = pre[i] + nums[i];
//    }
//
//    long long f[n + 1][m + 1];
//    memset(f, 0, sizeof(f));
//    int deque[n + 1];
//    int front, rear;
//    long long mx = LLONG_MIN;
//    for (int k = 1; k <= m; k++)
//    {
//        front = 0, rear = -1;
//        for (int i = 1; i <= n; i++)
//        {
//            int left = i - r;
//            int right = i - l;
//
//            if (right >= 0)
//            {
//                long long val = f[right][k - 1] - pre[right];
//                while (rear >= front
//                    && (f[deque[rear]][k - 1] - pre[deque[rear]]) <= val)
//                    rear--;
//
//                deque[++rear] = right;
//            }
//
//            while (rear >= front && deque[front] < left)
//                front++;
//
//            f[i][k] = f[i - 1][k];
//            if (rear >= front)
//            {
//                int top = deque[front];
//                long long candidate = f[top][k - 1] - pre[top] + pre[i];
//                f[i][k] = fmax(f[i][k], candidate);
//                mx = fmax(mx, candidate);
//            }
//        }
//    }
//
//    return f[n][m] ? f[n][m] : mx;
//}
//
