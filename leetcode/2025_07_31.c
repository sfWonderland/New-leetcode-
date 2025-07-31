////2140. 解决智力问题
//
//int** nums;
//int n;
//long long* f;
//long long dfs(int i)
//{
//    if (i >= n)
//        return 0;
//
//    if (f[i] != -1)
//        return f[i];
//
//    long long skip = dfs(i + 1);
//
//    long long y = nums[i][1];
//    long long res = nums[i][0];
//    if (i + y + 1 <= n)
//        res += dfs(i + y + 1);
//
//
//    f[i] = fmax(skip, res);
//    return f[i];
//}
//long long mostPoints(int** questions, int questionsSize, int* questionsColSize)
//{
//    nums = questions;
//    n = questionsSize;
//    f = (long long*)malloc(sizeof(long long) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        f[i] = -1;
//    }
//    return dfs(0);
//}
//
//long long mostPoints(int** questions, int questionsSize, int* questionsColSize)
//{
//    int n = questionsSize;
//    long long f[n + 1];
//    f[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        long long skip = f[i + 1];
//        long long y = questions[i][1];
//        long long res = questions[i][0];
//        if (i + y + 1 <= n)
//            res += f[i + y + 1];
//
//        f[i] = fmax(skip, res);
//    }
//    return f[0];
//}
//
////3259. 超级饮料的最大强化能量
//
//int** nums;
//int n;
//long long dfs(int i, bool side)
//{
//    if (i == n)
//        return 0;
//
//    return fmax(dfs(i + 1, side) + nums[side][i], dfs(i + 1, side ^ 1));
//}
//long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize)
//{
//    nums = (int**)malloc(sizeof(int*) * 2);
//    nums[0] = energyDrinkA, nums[1] = energyDrinkB;
//    n = energyDrinkASize;
//
//    return fmax(dfs(0, 0), dfs(0, 1));
//}
//
//long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize)
//{
//    int** nums = (int**)malloc(sizeof(int*) * 2);
//    nums[0] = energyDrinkA, nums[1] = energyDrinkB;
//    int n = energyDrinkASize;
//    long long f[n + 1][2];
//    f[n][0] = f[n][1] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        f[i][0] = fmax(f[i + 1][0] + nums[0][i], f[i + 1][1]);
//        f[i][1] = fmax(f[i + 1][1] + nums[1][i], f[i + 1][0]);
//    }
//    return fmax(f[0][0], f[0][1]);
//}
//
//long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize)
//{
//    long long f0 = 0, f1 = 0;
//    for (int i = energyDrinkASize - 1; i >= 0; i--)
//    {
//        long long pre = f0;
//        f0 = fmax(f0 + energyDrinkA[i], f1);
//        f1 = fmax(f1 + energyDrinkB[i], pre);
//    }
//    return fmax(f0, f1);
//}
//
////2708. 一个小组的最大实力值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long maxStrength(int* nums, int numsSize)
//{
//    if (numsSize == 1)
//        return nums[0];
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int recent = 1;
//    long long str = 1;
//    int i = 0, n = 0;
//    for (; i < numsSize && nums[i] < 0; i++)
//    {
//        str *= nums[i];
//        recent = nums[i];
//        n++;
//    }
//    if (str < 0)
//    {
//        str /= recent;
//        n--;
//    }
//    for (; i < numsSize; i++)
//    {
//        if (nums[i] == 0)
//            continue;
//        str *= nums[i];
//        n++;
//    }
//    return n ? str : 0;
//}
//
//long long maxStrength(int* nums, int numsSize)
//{
//    long long mn = nums[0], mx = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        long long x = nums[i], tmp = mn;
//        mn = fmin(fmin(mn, x), fmin(mn * x, mx * x));
//        mx = fmax(fmax(mx, x), fmax(tmp * x, mx * x));
//    }
//    return mx;
//}
//
////2639. 查询网格图中每一列的宽度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * gridColSize[0]);
//    for (int i = 0; i < gridColSize[0]; i++)
//    {
//        int mx = 0;
//        for (int j = 0; j < gridSize; j++)
//        {
//            int n = 0;
//            if (grid[j][i] <= 0)
//            {
//                n++;
//                grid[j][i] = -grid[j][i];
//            }
//            while (grid[j][i])
//            {
//                n++;
//                grid[j][i] /= 10;
//            }
//            mx = fmax(mx, n);
//        }
//        ans[i] = mx;
//    }
//    *returnSize = gridColSize[0];
//    return ans;
//}
//
