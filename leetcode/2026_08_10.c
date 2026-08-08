//// 1510. 石子游戏 IV
//
//bool winnerSquareGame(int n)
//{
//    int x = sqrt(n);
//    if (x * x == n) return true;
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i <= x; i++)
//    {
//        f[i * i] = true;
//    }
//    for (int i = 0; i <= n; i++)
//    {
//        if (f[i]) continue;
//        int y = sqrt(i);
//        for (int j = 1; j <= y; j++)
//        {
//            f[i] |= f[i - j * j] ^ 1;
//        }
//    }
//    return f[n];
//}
//
//bool winnerSquareGame(int n)
//{
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i <= n; i++)
//    {
//        int y = sqrt(i);
//        for (int j = 1; j <= y; j++)
//        {
//            if (!f[i - j * j])
//            {
//                f[i] = true;
//                break;
//            }
//        }
//    }
//    return f[n];
//}
//
//bool winnerSquareGame(int n)
//{
//    bool f[n + 1];
//    memset(f, 0, sizeof(f));
//    for (int i = 0; i < n; i++)
//    {
//        if (f[i]) continue;
//        for (int x = 1; x * x <= n - i; x++)
//        {
//            f[i + x * x] = true;
//        }
//    }
//    return f[n];
//}
//
//// 4014. 应用折扣后的最低总价    
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//double minPrice(int* prices, int pricesSize, int* discounts, int discountsSize)
//{
//    int n = pricesSize, m = discountsSize;
//    qsort(prices, n, sizeof(int), cmp);
//    qsort(discounts, m, sizeof(int), cmp);
//    double ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        ans += i < m ? prices[i] * (100.0 - discounts[i]) / 100.0 : prices[i];
//    }
//    return ans;
//}
//
//// 4015. 树的加权和
//
//long long weightedSum(int* parent, int parentSize, int* nums, int numsSize)
//{
//    int n = numsSize;
//    int** grid = (int**)malloc(sizeof(int*) * n);
//    int len[n], capacity[n];
//    for (int i = 0; i < n; i++)
//    {
//        capacity[i] = 8;
//        grid[i] = (int*)malloc(sizeof(int) * capacity[i]);
//        len[i] = 0;
//    }
//    for (int i = 1; i < n; i++)
//    {
//        int x = parent[i];
//        grid[x][len[x]++] = i;
//        if (len[x] >= capacity[x])
//        {
//            capacity[x] *= 2;
//            grid[x] = (int*)realloc(grid[x], sizeof(int) * capacity[x]);
//        }
//    }
//    int queue[n];
//    int front = 0, rear = 0, depth = 0;
//    queue[rear++] = 0;
//    long long ans = 0, sum = 0;
//    while (rear > front)
//    {
//        ++depth;
//        int start = front;
//        front = rear;
//        long long s = 0;
//        for (int i = start; i < front; i++)
//        {
//            int k = queue[i];
//            s += nums[k];
//            for (int j = 0; j < len[k]; j++)
//            {
//                queue[rear++] = grid[k][j];
//            }
//        }
//        sum += s;
//        ans -= s * depth;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        free(grid[i]);
//    }
//    free(grid);
//    ans += sum * (depth + 1);
//    return ans;
//}
//
