////3731. 找出缺失的元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* findMissingElements(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = 0;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int l = nums[0], r = nums[numsSize - 1];
//    if (l + numsSize - 1 == r)
//        return NULL;
//    int* ans = (int*)malloc(sizeof(int) * (r - l - numsSize + 1));
//    int idx = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (nums[i] != l)
//        {
//            ans[idx++] = l++;
//            //printf("%d ", l);
//        }
//        l++;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
////3732. 一次替换后的三元素最大乘积
//
//long long maxProduct(int* nums, int numsSize)
//{
//    long long max1 = 0, max2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int x = abs(nums[i]);
//        if (x > max1)
//        {
//            max2 = max1;
//            max1 = x;
//        }
//        else if (x > max2)
//        {
//            max2 = x;
//        }
//    }
//    return max1 * max2 * 100000;
//}
//
////3733. 完成所有送货任务的最少时间
//
//bool check(long long l, long long times, int* r, int* d)
//{
//    long long common = times - times / l;
//    long long a_time = times / r[1] - times / l;
//    long long b_time = times / r[0] - times / l;
//    return fmax(a_time, d[0]) + fmax(b_time, d[1]) <= common;
//}
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        a = a % b;
//        int tmp = a;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//long long minimumTime(int* d, int dSize, int* r, int rSize)
//{
//    long long l = 1ll * r[0] / gcd(r[0], r[1]) * r[1];
//    long long left = 1, right = 4e9;
//    while (left < right)
//    {
//        long long mid = (left + right) / 2;
//        if (check(l, mid, r, d))
//            right = mid;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
////2257. 统计网格图中没有被保卫的格子数
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//void dfs(int** grid, int m, int n, int x, int y, int i, int* ans)
//{
//    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2)
//        return;
//
//    if (grid[x][y] == 0)
//    {
//        grid[x][y] = 1;
//        (*ans)--;
//    }
//    int dx = x + dir[i][0];
//    int dy = y + dir[i][1];
//    dfs(grid, m, n, dx, dy, i, ans);
//}
//int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize)
//{
//    int** grid = (int**)malloc(sizeof(int*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        grid[i] = (int*)calloc(sizeof(int), n);
//    }
//    for (int i = 0; i < wallsSize; i++)
//    {
//        grid[walls[i][0]][walls[i][1]] = 2;
//    }
//    for (int i = 0; i < guardsSize; i++)
//    {
//        grid[guards[i][0]][guards[i][1]] = 2;
//    }
//    int ans = m * n - wallsSize - guardsSize;
//    for (int i = 0; i < guardsSize; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            int dx = guards[i][0] + dir[j][0];
//            int dy = guards[i][1] + dir[j][1];
//            dfs(grid, m, n, dx, dy, j, &ans);
//        }
//    }
//    return ans;
//}
//
