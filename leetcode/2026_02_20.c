////761. 特殊的二进制字符串
//
//int cmp(const void* e1, const void* e2)
//{
//    char* s1 = *(char**)e1;
//    char* s2 = *(char**)e2;
//    return strcmp(s2, s1);
//}
//char* makeLargestSpecial(char* s)
//{
//    int n = strlen(s);
//    if (n <= 2)
//        return s;
//
//    char** subStrings = (char**)malloc(sizeof(char*) * n / 2);
//    int idx = 0;
//    int diff = 0, start = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '1')
//            diff++;
//        else if (--diff == 0)
//        {
//            subStrings[idx] = (char*)malloc(sizeof(char) * (n + 1));
//            char tmp = s[i];
//            s[i] = '\0';
//            sprintf(subStrings[idx++], "%d%s%d", 1, makeLargestSpecial(s + start + 1), 0);
//            s[i] = tmp;
//            start = i + 1;
//        }
//    }
//    qsort(subStrings, idx, sizeof(char*), cmp);
//    char* ans = (char*)malloc(sizeof(char) * (n + 1));
//    ans[0] = '\0';
//    for (int i = 0; i < idx; i++)
//    {
//        strcat(ans, subStrings[i]);
//    }
//    return ans;
//}
//
////1222. 可以攻击国王的皇后    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
//int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes)
//{
//    bool queenPos[8][8] = { 0 };
//    for (int i = 0; i < queensSize; i++)
//    {
//        int x = queens[i][0];
//        int y = queens[i][1];
//        queenPos[x][y] = true;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * 8);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 8);
//    *returnSize = 0;
//    int kx = king[0], ky = king[1];
//    for (int i = 0; i < 8; i++)
//    {
//        int x = kx + dir[i][0], y = ky + dir[i][1];
//        while (x >= 0 && x < 8 && y >= 0 && y < 8)
//        {
//            if (queenPos[x][y])
//            {
//                ans[*returnSize] = (int*)malloc(sizeof(int) * 2);
//                ans[*returnSize][0] = x, ans[*returnSize][1] = y;
//                (*returnColumnSizes)[(*returnSize)++] = 2;
//                break;
//            }
//            x += dir[i][0];
//            y += dir[i][1];
//        }
//    }
//    return ans;
//}
//
////1267. 统计参与通信的服务器
//
//const int dir[8][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
//int countServers(int** grid, int gridSize, int* gridColSize)
//{
//    int dfs(int x, int y)
//    {
//        int cnt = -1;
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dir[i][0], my = y + dir[i][1];
//            while (mx >= 0 && mx < gridSize && my >= 0 && my < gridColSize[0])
//            {
//                if (grid[mx][my])
//                {
//                    cnt = fmax(0, cnt);
//                    cnt += grid[mx][my] == 1;
//                    grid[mx][my] = 2;
//                }
//                mx += dir[i][0];
//                my += dir[i][1];
//            }
//        }
//        return cnt;
//    }
//    int ans = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridColSize[0]; j++)
//        {
//            if (grid[i][j] == 1)
//            {
//                int cnt = dfs(i, j);
//                if (cnt >= 0)
//                {
//                    grid[i][j] = 2;
//                    ans += cnt + 1;
//                }
//            }
//        }
//    }
//    return ans;
//}
//
////1276. 不浪费原料的汉堡制作方案
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
//{
//    *returnSize = 0;
//    if (tomatoSlices % 2 == 1 || cheeseSlices * 2 > tomatoSlices || cheeseSlices * 4 < tomatoSlices)
//        return NULL;
//
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = tomatoSlices / 2 - cheeseSlices;
//    ans[1] = cheeseSlices - ans[0];
//    *returnSize = 2;
//    return ans;
//}
//
