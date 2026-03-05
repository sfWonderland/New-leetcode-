////2477. 到达首都的最少油耗
//
//long long minimumFuelCost(int** roads, int roadsSize, int* roadsColSize, int seats)
//{
//    int n = roadsSize;
//    int** grid = (int**)malloc(sizeof(int*) * (n + 1));
//    int len[n + 1];
//    int capacity[n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        capacity[i] = 8;
//        len[i] = 0;
//        grid[i] = (int*)calloc(sizeof(int), capacity[i]);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int x = roads[i][0], y = roads[i][1];
//        grid[x][len[x]++] = y;
//        grid[y][len[y]++] = x;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//    }
//    long long ans = 0;
//    int dfs(int x, int fa)
//    {
//        int size = 1;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            if (y != fa)
//                size += dfs(y, x);
//        }
//        if (x)
//            ans += (size - 1) / seats + 1;
//
//        return size;
//    }
//    dfs(0, -1);
//    return ans;
//}
//
////2681. 英雄的力量    
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//const int MOD = 1e9 + 7;
//int sumOfPower(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long ans = 0, s = 0;
//    // 比如有从小到大排序的五个数a, b, c, d, e
//    // 取d为最大值，则有以下四种情况：
//    // 1）只取d，最大最小值都为d，对答案的贡献为d*d*d
//    // 2）取c为最小值，只有一种情况，对答案的贡献为d*d*c*2^0
//    // 3）取b为最小值，则c取不取都不影响最大最小值，共2种情况，对答案的贡献为d*d*b*2^1
//    // 4) 取a为最小值，则b, c取不取都不影响最大最小值，共2^2种情况，对答案的贡献为d*d*a*2^2
//    // 综上所述，取d为最大值对答案的贡献为d*d*(d+c*2^0+b*2^1+a*2^2);
//    // 令s=(c*2^0+b*2^1+a*2^2),则有d*d*(d+s)
//    // 若取e为最大值，同理可得取e为最大值对答案的贡献为e*e*(e+d*2^0+c*2^1+b*2^2+a*2^3)
//    // 即e*e*(e+d+2*(c*2^0+b*2^1+a*2^2))=e*e*(e+d+2*s)
//    // 令s'=d+2*s,则原式=e*e*(e+s')，从而得到s递推式s=2*s+x;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans = (ans + (s + nums[i]) * nums[i] % MOD * nums[i]) % MOD;
//        s = (2 * s + nums[i]) % MOD;
//    }
//    return ans;
//}
//
////3786. 树组的交互代价总和
//
//long long interactionCosts(int n, int** edges, int edgesSize, int* edgesColSize, int* group, int groupSize)
//{
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int* len = (int*)calloc(sizeof(int), n);
//    int* capacity = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//    }
//    for (int i = 0; i < edgesSize; i++)
//    {
//        int x = edges[i][0], y = edges[i][1];
//        grid[x][len[x]++] = y;
//        grid[y][len[y]++] = x;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//        if (len[y] >= capacity[y])
//        {
//            capacity[y] *= 2;
//            grid[y] = (int*)realloc(grid[y], sizeof(int) * capacity[y]);
//        }
//    }
//    int max = 0;
//    for (int i = 0; i < groupSize; i++)
//    {
//        max = fmax(max, group[i]);
//    }
//    int total[max + 1];
//    memset(total, 0, sizeof(total));
//    for (int i = 0; i < groupSize; i++)
//    {
//        total[group[i]]++;
//    }
//
//    long long ans = 0;
//    int* dfs(int x, int fa)
//    {
//        int* cnt_x = (int*)calloc(sizeof(int), max + 1);
//        cnt_x[group[x]]++;
//        for (int i = 0; i < len[x]; i++)
//        {
//            int y = grid[x][i];
//            if (y == fa)
//                continue;
//
//            int* cnt_y = dfs(y, x);
//            for (int j = 0; j <= max; j++)
//            {
//                int c = cnt_y[j];
//                ans += 1ll * c * (total[j] - c);
//                cnt_x[j] += c;
//            }
//        }
//
//        return cnt_x;
//    }
//    dfs(0, -1);
//    return ans;
//}
//
////891. 子序列宽度之和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//const int MOD = 1e9 + 7;
//int sumSubseqWidths(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long ans = 0, s = 0, t = 0;
//    // 比如有从小到大排序的五个数a, b, c, d, e
//    // 取d为最大值，则有以下四种情况：
//    // 1）只取d，最大最小值都为d，对答案的贡献为0
//    // 2）取c为最小值，只有一种情况，对答案的贡献为(d-c)*2^0
//    // 3）取b为最小值，则c取不取都不影响最大最小值，共2种情况，对答案的贡献为(d-b)*2^1
//    // 4) 取a为最小值，则b, c取不取都不影响最大最小值，共2^2种情况，对答案的贡献为(d-a)*2^2
//    // 综上所述，取d为最大值对答案的贡献为d*(2^0+2^1+2^2)-(c*2^0+b*2^1+a*2^2);
//    // 令s=(2^0+2^1+2^2),t=(c*2^0+b*2^1+a*2^2),则有d*s-t
//    // 若取e为最大值，同理可得取e为最大值对答案的贡献为e*(2^0+2^1+2^2+2^3)-(d*2^0+c*2^1+b*2^2+a*2^3);
//    // 令s'=2*s+1,t'=2*t+d,则原式=e*s'-t'，从而得到s递推式s=2*s+1，t递推式t=2*t+x;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ans = (ans + nums[i] * s - t) % MOD;
//        s = (2 * s + 1) % MOD;
//        t = (2 * t + nums[i]) % MOD;
//    }
//    return ans;
//}
//
