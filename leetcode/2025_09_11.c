////LCS 03. 主题空间
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int dfs(char** grid, int x, int y, char c)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == '0')
//        return -30000;
//
//    if (grid[x][y] != c)
//        return 0;
//
//    grid[x][y] = 'c';
//    int sum = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dfs(grid, mx, my, c);
//    }
//    return sum;
//}
//int largestArea(char** grid, int gridSize)
//{
//    row = gridSize;
//    col = strlen(grid[0]);
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] == '0' || grid[i][j] == 'c')
//                continue;
//
//            int tmp = dfs(grid, i, j, grid[i][j]);
//            ans = fmax(tmp, ans);
//        }
//    }
//    return ans;
//}
//
////2658. 网格图中鱼的最大数目
//
//int row, col;
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//int dfs(int** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0)
//        return 0;
//
//    int sum = grid[x][y];
//    grid[x][y] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dfs(grid, mx, my);
//    }
//    return sum;
//}
//int findMaxFish(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = gridColSize[0];
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j] == 0)
//                continue;
//
//            int tmp = dfs(grid, i, j);
//            ans = fmax(tmp, ans);
//        }
//    }
//    return ans;
//}
//
////1034. 边界着色
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int Row, Col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//bool** vis;
//int dfs(int** grid, int x, int y, int c, int target)
//{
//    if (x < 0 || x >= Row || y < 0 || y >= Col)
//        return 1;
//    if (vis[x][y])
//        return 0;
//    if (grid[x][y] != c)
//        return 1;
//
//    vis[x][y] = true;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        if (dfs(grid, mx, my, c, target))
//            grid[x][y] = target;
//    }
//    return 0;
//}
//int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes)
//{
//    Row = gridSize;
//    Col = gridColSize[0];
//    vis = (bool**)malloc(sizeof(bool*) * Row);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * Row);
//    for (int i = 0; i < Row; i++)
//    {
//        (*returnColumnSizes)[i] = Col;
//        vis[i] = (bool*)calloc(sizeof(bool), Col);
//    }
//    dfs(grid, row, col, grid[row][col], color);
//    *returnSize = Row;
//
//    return grid;
//}
//
////2785. 将字符串中的元音字母排序
//
//bool isVowel(char ch)
//{
//    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//        return true;
//
//    return false;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//char* sortVowels(char* s)
//{
//    int n = strlen(s);
//    int* st = (int*)malloc(sizeof(int) * n);
//    char* sym = (char*)malloc(sizeof(int) * n);
//    int top = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (isVowel(s[i]))
//        {
//            st[top] = i;
//            sym[top++] = s[i];
//        }
//    }
//    qsort(sym, top, sizeof(char), cmp);
//    for (int i = 0; i < top; i++)
//    {
//        s[st[i]] = sym[i];
//    }
//    return s;
//}
//
//#define VOWEL_MASK 0x208222
//char* sortVowels(char* s)
//{
//    int n = strlen(s);
//    int cnt['z' + 1];
//    for (int i = 0; i < n; i++)
//    {
//        if (VOWEL_MASK >> (s[i] & 31) & 1)
//            cnt[s[i]]++;
//    }
//    char j = 'A';
//    for (int i = 0; i < n; i++)
//    {
//        if ((VOWEL_MASK >> (s[i] & 31) & 1) == 0)
//            continue;
//
//        while (cnt[j] == 0)
//            j = j == 'Z' ? 'a' : j + 1;
//
//        s[i] = j;
//        cnt[j]--;
//    }
//    return s;
//}
//
