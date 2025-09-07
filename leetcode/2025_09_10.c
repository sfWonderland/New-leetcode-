////2762. 不间断子数组
//
//long long continuousSubarrays(int* nums, int numsSize)
//{
//    long long ans = 0;
//    int n = numsSize;
//    int* max_q = (int*)malloc(sizeof(int) * n);
//    int* min_q = (int*)malloc(sizeof(int) * n);
//    int min_bottom = 0, min_top = -1;
//    int max_bottom = 0, max_top = -1;
//    int left = 0;
//    for (int i = 0; i < n; i++)
//    {
//        while (max_bottom <= max_top && nums[max_q[max_top]] <= nums[i])
//            max_top--;
//        max_q[++max_top] = i;
//        while (min_bottom <= min_top && nums[min_q[min_top]] >= nums[i])
//            min_top--;
//        min_q[++min_top] = i;
//        while (nums[max_q[max_bottom]] - nums[min_q[min_bottom]] > 2)
//        {
//            left++;
//            while (max_q[max_bottom] < left)
//                max_bottom++;
//            while (min_q[min_bottom] < left)
//                min_bottom++;
//        }
//        ans += i - left + 1;
//    }
//    return ans;
//}
//
////1733. 需要教语言的最少人数
//
//void add(int u, bool* vis, int* cnt, int** languages, int languagesSize, int* languagesColSize, int* total)
//{
//    if (vis[u])
//        return;
//    vis[u] = true;
//    (*total)++;
//    for (int i = 0; i < languagesColSize[u]; i++)
//    {
//        cnt[languages[u][i]]++;
//    }
//}
//int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize)
//{
//    int m = languagesSize;
//    bool** learned = (bool**)malloc(sizeof(bool*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        learned[i] = (bool*)calloc(sizeof(bool), (n + 1));
//        for (int j = 0; j < languagesColSize[i]; j++)
//            learned[i][languages[i][j]] = true;
//    }
//
//    int total = 0;
//    bool* vis = (bool*)calloc(sizeof(bool), m);
//    int* cnt = (int*)calloc(sizeof(int), (n + 1));
//
//    for (int i = 0; i < friendshipsSize; i++)
//    {
//        int u = friendships[i][0] - 1;
//        int v = friendships[i][1] - 1;
//        bool ok = false;
//        for (int j = 0; j <= n; j++)
//        {
//            if (learned[u][j] && learned[v][j])
//            {
//                ok = true;
//                break;
//            }
//        }
//        if (!ok)
//        {
//            add(u, vis, cnt, languages, languagesSize, languagesColSize, &total);
//            add(v, vis, cnt, languages, languagesSize, languagesColSize, &total);
//        }
//    }
//    int popular = 0;
//    for (int i = 0; i < n + 1; i++)
//    {
//        popular = fmax(popular, cnt[i]);
//    }
//    return total - popular;
//}
//
////3619. 总价值可以被 K 整除的岛屿数目
//
//int row, col;
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//long long dfs(int** grid, int x, int y)
//{
//    if (!(x >= 0 && x < row && y >= 0 && y < col))
//        return 0;
//    if (grid[x][y] == 0)
//        return 0;
//
//    long long sum = grid[x][y];
//    grid[x][y] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dfs(grid, mx, my);
//    }
//    return sum;
//}
//int countIslands(int** grid, int gridSize, int* gridColSize, int k)
//{
//    row = gridSize;
//    col = *gridColSize;
//    int num = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j])
//            {
//                long long sum = dfs(grid, i, j);
//                if (sum % k == 0)
//                    num++;
//            }
//        }
//    }
//    return num;
//}
//
////面试题 16.19. 水域大小
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int row, col;
//int dx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
//int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
//int dfs(int** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y])
//        return 0;
//
//    int sum = 1;
//    grid[x][y] = 1;
//    for (int i = 0; i < 8; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dfs(grid, mx, my);
//    }
//    return sum;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize)
//{
//    row = landSize;
//    col = landColSize[0];
//    int* ans = (int*)malloc(sizeof(int) * landSize * landColSize[0]);
//    int idx = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (land[i][j])
//                continue;
//
//            ans[idx++] = dfs(land, i, j);
//        }
//    }
//    qsort(ans, idx, sizeof(int), cmp);
//    *returnSize = idx;
//    return ans;
//}
//
