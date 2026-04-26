//// 3908. 有效数字整数
//
//bool validDigit(int n, int x)
//{
//    bool valid = false;
//    while (n >= 10)
//    {
//        if (n % 10 == x)
//        {
//            valid = true;
//        }
//        n /= 10;
//    }
//    return n == x ? false : valid;
//}
//
//// 3909. 比较双调部分的和  
//
//int compareBitonicSums(int* nums, int numsSize)
//{
//    long long sum1 = nums[0], sum2 = 0;
//    int j = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > nums[i - 1])
//        {
//            sum1 += nums[i];
//        }
//        else
//        {
//            j = i - 1;
//            break;
//        }
//    }
//    for (int i = j; i < numsSize; i++)
//    {
//        sum2 += nums[i];
//    }
//    // printf("%d %d\n", sum1, sum2);
//    int d = sum1 - sum2;
//    return d ? sum1 < sum2 : -1;
//}
//
//// 3910. 统计节点和为偶数的连通子图
//
//int evenSumSubgraphs(int* nums, int numsSize, int** edges, int edgesSize, int* edgesColSize)
//{
//    int n = numsSize;
//    bool grid[n][n];
//    memset(grid, 0, sizeof(grid));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][y] = grid[y][x] = true;
//    }
//    int ans = 0;
//    bool vis[n];
//    for (int mask = 1; mask < (1 << n); mask++)
//    {
//        int sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (mask & (1 << i))
//            {
//                sum += nums[i];
//            }
//        }
//        if (sum & 1)
//            continue;
//        int first = -1;
//        for (int i = 0; i < n; i++)
//        {
//            if (mask & (1 << i))
//            {
//                first = i;
//                break;
//            }
//        }
//        memset(vis, 0, sizeof(vis));
//        int queue[n];
//        int front = 0, rear = 0;
//        queue[rear++] = first;
//        vis[first] = true;
//        while (front < rear)
//        {
//            int u = queue[front++];
//            for (int v = 0; v < n; v++)
//            {
//                if (grid[u][v] && (mask & (1 << v)) && !vis[v])
//                {
//                    vis[v] = true;
//                    queue[rear++] = v;
//                }
//            }
//        }
//        bool connected = true;
//        for (int i = 0; i < n; i++)
//        {
//            if (mask & (1 << i) && !vis[i])
//            {
//                connected = false;
//                break;
//            }
//        }
//        ans += connected;
//    }
//    return ans;
//}
//
//// LCR 092. 将字符串翻转到单调递增
//
//int minFlipsMonoIncr(char* s)
//{
//    int n = strlen(s);
//    int suf = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf += '1' - s[i];
//    }
//    int ans = suf;
//    int pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        pre += s[i] - '0';
//        suf -= '1' - s[i];
//        ans = fmin(ans, pre + suf);
//    }
//    return ans;
//}
//
