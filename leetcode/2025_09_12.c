////1020. 飞地的数量
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int dfs(int** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col)
//        return -30000;
//
//    if (!grid[x][y])
//        return 0;
//
//    int sum = 1;
//    grid[x][y] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dfs(grid, mx, my);
//    }
//    return sum;
//}
//int numEnclaves(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = gridColSize[0];
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j])
//                ans += fmax(dfs(grid, i, j), 0);
//        }
//    }
//    return ans;
//}
//
////1254. 统计封闭岛屿的数目
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//bool dfs(int** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col)
//        return false;
//
//    if (grid[x][y])
//        return true;
//
//    grid[x][y] = 1;
//    bool ret = true;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        ret &= dfs(grid, mx, my);
//    }
//    return ret;
//}
//int closedIsland(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = gridColSize[0];
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (!grid[i][j])
//                ans += dfs(grid, i, j);
//        }
//    }
//    return ans;
//}
//
////130. 被围绕的区域
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//void dfs(char** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != 'O')
//        return;
//
//    grid[x][y] = 'A';
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        dfs(grid, mx, my);
//    }
//}
//void solve(char** board, int boardSize, int* boardColSize)
//{
//    row = boardSize;
//    col = boardColSize[0];
//    for (int i = 0; i < row; i++)
//    {
//        dfs(board, i, 0);
//        dfs(board, i, col - 1);
//    }
//    for (int i = 0; i < col; i++)
//    {
//        dfs(board, 0, i);
//        dfs(board, row - 1, i);
//    }
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (board[i][j] == 'A')
//                board[i][j] = 'O';
//            else if (board[i][j] == 'O')
//                board[i][j] = 'X';
//        }
//    }
//}
//
////1905. 统计子岛屿
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//bool dfs(int** grid, int x, int y)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] < 2)
//        return true;
//
//    if (grid[x][y] == 2)
//        return false;
//
//    grid[x][y] = 0;
//    int tmp = true;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        tmp &= dfs(grid, mx, my);
//    }
//    return tmp;
//}
//int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize)
//{
//    row = grid1Size;
//    col = grid1ColSize[0];
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            grid1[i][j] += 2 * grid2[i][j];
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid1[i][j] == 3)
//                ans += dfs(grid1, i, j);
//        }
//    }
//    return ans;
//}
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//void dfs(int** grid1, int** grid2, int x, int y, bool* flag)
//{
//    if (x < 0 || x >= row || y < 0 || y >= col || grid2[x][y] == 0)
//        return;
//
//    if (grid1[x][y] == 0)
//        *flag = false;
//
//    grid2[x][y] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        dfs(grid1, grid2, mx, my, flag);
//    }
//}
//int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize)
//{
//    row = grid1Size;
//    col = grid1ColSize[0];
//    int ans = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid2[i][j])
//            {
//                bool flag = true;
//                dfs(grid1, grid2, i, j, &flag);
//                ans += flag;
//            }
//        }
//    }
//    return ans;
//}
//
