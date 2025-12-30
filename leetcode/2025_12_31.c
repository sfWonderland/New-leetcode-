////1012. 至少有 1 位重复的数字
//
//int numDupDigitsAtMostN(int n)
//{
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int memo[m][1 << 10];
//    for (int i = 0; i < m; i++)
//    {
//        memset(memo[i], -1, sizeof(int) * (1 << 10));
//    }
//    int dfs(int i, int mask, bool limit)
//    {
//        if (i == m)
//            return mask > 0;
//
//        if (!limit && mask && memo[i][mask] != -1)
//            return memo[i][mask];
//        int ret = 0;
//        if (!mask)
//            ret = dfs(i + 1, mask, false);
//
//        int up = limit ? s[i] - '0' : 9;
//        for (int j = 1 - (mask > 0); j <= up; j++)
//        {
//            if ((mask >> j) & 1)
//                continue;
//
//            ret += dfs(i + 1, mask | (1 << j), limit && j == up);
//        }
//        if (!limit && mask)
//            memo[i][mask] = ret;
//        return ret;
//    }
//    return n - dfs(0, 0, true);
//}
//
////2376. 统计特殊整数
//
//int countSpecialNumbers(int n)
//{
//    char* s = (char*)malloc(sizeof(char) * 11);
//    sprintf(s, "%d", n);
//    int m = strlen(s);
//    int** memo = (int**)malloc(sizeof(int*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        memo[i] = (int*)malloc(sizeof(int) * (1 << 10));
//        memset(memo[i], -1, sizeof(int) * (1 << 10));
//    }
//    int dfs(int i, int mask, bool limit)
//    {
//        if (i == m)
//            return mask > 0;
//
//        if (mask && !limit && memo[i][mask] != -1)
//            return memo[i][mask];
//
//        int res = 0;
//        if (!mask)
//            res = dfs(i + 1, mask, false);
//
//        int up = limit ? s[i] - '0' : 9;
//        for (int j = 1 - (mask > 0); j <= up; j++)
//        {
//            if (mask >> j & 1)
//                continue;
//
//            res += dfs(i + 1, mask | (1 << j), limit && j == up);
//        }
//        if (!limit && mask)
//            memo[i][mask] = res;
//        return res;
//    }
//    return dfs(0, 0, true);
//}
//
////600. 不含连续1的非负整数
//
//int findIntegers(int n)
//{
//    int m = 32 - __builtin_clz(n);
//    int** memo = (int**)malloc(sizeof(int*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        memo[i] = (int*)malloc(sizeof(int) * 2);
//        memo[i][0] = memo[i][1] = -1;
//    }
//    int dfs(int i, bool limit, bool pre)
//    {
//        if (i < 0)
//            return 1;
//
//        if (!limit && memo[i][pre] != -1)
//            return memo[i][pre];
//
//
//        int up = limit ? n >> i & 1 : 1;
//        int res = dfs(i - 1, limit && up == 0, false); // 填0
//
//        if (!pre && up) // 可以填1
//            res += dfs(i - 1, limit, true); // 填1
//
//        if (!limit)
//            memo[i][pre] = res;
//
//        return res;
//    }
//    return dfs(m - 1, true, false); // 从高到低
//}
//
/// 1970. 你能穿过矩阵的最后一天
//
//const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize)
//{
//    // 0：水
//    // 1：陆地（未被感染）
//    // 2：陆地（已被感染）
//    int** state = (int**)malloc(sizeof(int*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        state[i] = (int*)calloc(sizeof(int), col);
//    }
//    // 能否从第一行到达 (r, c)
//    bool can_reach_from_top(int x, int y)
//    {
//        if (x == 0) // 已经是第一行
//            return true;
//
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = dir[i][0] + x;
//            int my = dir[i][1] + y;
//            if (mx >= 0 && mx < row && my >= 0 && my < col && state[mx][my] == 2)
//                return true;
//        }
//        return false;
//    }
//    // 从 (r, c) 出发，能否到达最后一行
//    bool dfs(int x, int y)
//    {
//        if (x == row - 1)
//            return true;
//
//        state[x][y] = 2; // 感染
//        // 传播病毒到未被感染的陆地
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = dir[i][0] + x;
//            int my = dir[i][1] + y;
//            if (mx >= 0 && mx < row && my >= 0 && my < col && state[mx][my] == 1 && dfs(mx, my))
//                return true;
//        }
//        return false;
//    }
//    for (int i = cellsSize - 1; i >= 0; i--)
//    {
//        // 改成从 0 开始的下标
//        int x = cells[i][0] - 1;
//        int y = cells[i][1] - 1;
//        // 未被感染的陆地
//        state[x][y] = 1;
//        if (can_reach_from_top(x, y) && dfs(x, y))
//            return i;
//    }
//    return cellsSize;
//}
//
