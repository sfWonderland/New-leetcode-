//// 3963. 构造恰好一条路径的网格
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** createGrid(int m, int n, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (char*)malloc(sizeof(char) * (n + 1));
//        ans[i][n] = '\0';
//        if (i == 0)
//            memset(ans[i], '.', sizeof(char) * n);
//        else
//        {
//            memset(ans[i], '#', sizeof(char) * (n - 1));
//            ans[i][n - 1] = '.';
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
//// 3964. 照亮道路的最少灯泡数  
//
//int minLights(int* lights, int lightsSize)
//{
//    int n = lightsSize;
//    int dx[n + 1];
//    memset(dx, 0, sizeof(dx));
//    for (int i = 0; i < n; i++)
//    {
//        int x = lights[i];
//        if (x == 0)
//            continue;
//
//        int left = fmax(0, i - x);
//        int right = fmin(n - 1, i + x);
//        dx[left]++;
//        dx[right + 1]--;
//    }
//    for (int i = 1; i < n; i++)
//    {
//        dx[i] += dx[i - 1];
//    }
//    int ans = 0, empty = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        if (i == n || dx[i])
//        {
//            ans += (empty + 2) / 3;
//            empty = 0;
//        }
//        else
//            empty++;
//    }
//    return ans;
//}
//
//// 3965. 任务完成时间 I
//
//struct Nodes
//{
//    int val;
//    struct Nodes** childs;
//    int capacity;
//    int n;
//};
//long long finishTime(int n, int** edges, int edgesSize, int* edgesColSize, int* baseTime, int baseTimeSize)
//{
//    if (n == 1)
//        return baseTime[0];
//    struct Nodes** nodes = (struct Nodes**)malloc(sizeof(struct Node*) * n);
//    memset(nodes, 0, sizeof(struct Nodes*) * n);
//    for (int i = 0; i < n - 1; i++)
//    {
//        int fa = edges[i][0];
//        int child = edges[i][1];
//        if (nodes[fa] == NULL)
//        {
//            nodes[fa] = (struct Nodes*)malloc(sizeof(struct Nodes));
//            nodes[fa]->val = fa;
//            nodes[fa]->capacity = 8;
//            nodes[fa]->childs = (struct Nodes**)calloc(sizeof(struct Nodes*), nodes[fa]->capacity);
//            nodes[fa]->n = 0;
//        }
//        if (nodes[child] == NULL)
//        {
//            nodes[child] = (struct Nodes*)malloc(sizeof(struct Nodes));
//            nodes[child]->val = child;
//            nodes[child]->capacity = 8;
//            nodes[child]->childs = (struct Nodes**)calloc(sizeof(struct Nodes*), nodes[child]->capacity);
//            nodes[child]->n = 0;
//        }
//        nodes[fa]->childs[nodes[fa]->n++] = nodes[child];
//        if (nodes[fa]->n >= nodes[fa]->capacity)
//        {
//            nodes[fa]->capacity *= 2;
//            nodes[fa]->childs = realloc(nodes[fa]->childs, sizeof(struct Nodes*) * nodes[fa]->capacity);
//        }
//    }
//    long long dfs(int x)
//    {
//        if (nodes[x]->n == 0)
//            return baseTime[x];
//
//        long long earliest = LLONG_MAX;
//        long long latest = LLONG_MIN;
//        for (int i = 0; i < nodes[x]->n; i++)
//        {
//            long long val = dfs(nodes[x]->childs[i]->val);
//            earliest = fmin(earliest, val);
//            latest = fmax(latest, val);
//        }
//        return latest + (latest - earliest) + baseTime[x];
//    }
//    long long ans = dfs(0);
//    for (int i = 0; i < n; i++)
//    {
//        if (nodes[i]->n)
//            free(nodes[i]->childs);
//        free(nodes[i]);
//    }
//    free(nodes);
//    return ans;
//}
//
//// 3966. 统计范围内的好整数
//
//long long goodIntegers(long long l, long long r, int k)
//{
//    // 将 r 和 l 转换为字符串
//    char* up = (char*)malloc(sizeof(char) * 17);
//    sprintf(up, "%lld", r);
//    int n = strlen(up);
//
//    char* down = (char*)malloc(sizeof(char) * 17);
//    sprintf(down, "%lld", l);
//    int len_down = strlen(down);
//
//    // 将 down 补前导零，使其长度与 up 相同
//    if (len_down < n)
//    {
//        int shift = n - len_down;
//        for (int i = n - 1; i >= shift; i--)
//        {
//            down[i] = down[i - shift];
//        }
//        for (int i = 0; i < shift; i++)
//        {
//            down[i] = '0';
//        }
//    }
//
//    // 记忆化数组 memo[i][pre]，pre 为 0~9
//    long long** memo = (long long**)malloc(sizeof(long long*) * n);
//    for (int i = 0; i < n; i++)
//    {
//        memo[i] = (long long*)malloc(sizeof(long long) * 10);
//        for (int j = 0; j < 10; j++)
//        {
//            memo[i][j] = -1;
//        }
//    }
//
//    // 数位 DP 递归函数
//    long long dfs(int i, int pre, bool limit_low, bool limit_high, bool isNum)
//    {
//        if (i == n)
//            return isNum ? 1 : 0;
//
//        if (isNum && !limit_low && !limit_high && memo[i][pre] != -1)
//            return memo[i][pre];
//
//
//        int lo = limit_low ? (down[i] - '0') : 0;
//        int hi = limit_high ? (up[i] - '0') : 9;
//        long long res = 0;
//
//        for (int d = lo; d <= hi; d++)
//        {
//            if (!isNum && d == 0)
//                // 前导零阶段，继续不选数字
//                res += dfs(i + 1, pre, limit_low && d == lo, limit_high && d == hi, false);
//            else
//            {
//                // 已经选了数字，检查相邻差
//                if (isNum && abs(d - pre) > k)
//                    continue;
//
//                res += dfs(i + 1, d, limit_low && d == lo, limit_high && d == hi, true);
//            }
//        }
//
//        if (isNum && !limit_low && !limit_high)
//            memo[i][pre] = res;
//
//        return res;
//    }
//
//    long long ans = dfs(0, 0, true, true, false);
//
//    // 释放动态内存
//    for (int i = 0; i < n; i++)
//        free(memo[i]);
//
//    free(memo);
//    free(up);
//    free(down);
//
//    return ans;
//}
//
