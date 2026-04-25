//// 101052. 数组中的有效元素
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findValidElements(int* nums, int numsSize, int* returnSize)
//{
//    if (numsSize <= 2)
//    {
//        *returnSize = numsSize;
//        return nums;
//    }
//    int n = numsSize;
//    int suf[n + 1];
//    suf[n] = 0;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf[i] = fmax(nums[i], suf[i + 1]);
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int ansSize = 0, pre = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (nums[i] > pre || nums[i] > suf[i + 1])
//        {
//            ans[ansSize++] = nums[i];
//        }
//        pre = fmax(pre, nums[i]);
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
//// 101044. 按频率对元音排序   
//
//int cnt[26] = { 0 };
//int fir[26];
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1, b = *(int*)e2;
//    return cnt[b] == cnt[a] ? fir[a] - fir[b] : cnt[b] - cnt[a];
//}
//char* sortVowels(char* s)
//{
//    int n = strlen(s);
//    int pos[n];
//    int size = 0;
//    int idx[26];
//    for (int i = 0; i < 26; i++)
//    {
//        idx[i] = i;
//        fir[i] = n;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
//        {
//            if (fir[s[i] - 'a'] == n)
//                fir[s[i] - 'a'] = i;
//            cnt[s[i] - 'a']++;
//            pos[size++] = i;
//        }
//    }
//    qsort(idx, 26, sizeof(int), cmp);
//    int pos2 = 0;
//    for (int i = 0; i < size; i++)
//    {
//        s[pos[i]] = idx[pos2] + 'a';
//        cnt[idx[pos2]]--;
//        if (cnt[idx[pos2]] == 0)
//            pos2++;
//    }
//    return s;
//}
//
//// 101032. 使数组非递减需要的最小累计值
//
//long long minOperations(int* nums, int numsSize)
//{
//    long long ans = 0;
//    long long max = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (max < ans + nums[i])
//        {
//            max = nums[i] + ans;
//        }
//        else
//        {
//            ans = max - nums[i];
//        }
//    }
//    return ans;
//}
//
//// 1559. 二维网格图中探测环
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//bool dfs(char** grid, int x, int y, int px, int py)
//{
//    grid[x][y] -= 32;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//
//        if (mx == px && my == py)
//            continue;
//
//        if (mx < 0 || mx >= row || my < 0 || my >= col)
//            continue;
//        if (grid[mx][my] == grid[x][y])
//            return true;
//        if (grid[mx][my] != grid[x][y] + 32)
//            continue;
//        if (dfs(grid, mx, my, x, y))
//            return true;
//    }
//    return false;
//}
//bool containsCycle(char** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = gridColSize[0];
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] >= 'a')
//            {
//                if (dfs(grid, i, j, -1, -1))
//                {
//                    // printf("%d %d\n", i, j);
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
