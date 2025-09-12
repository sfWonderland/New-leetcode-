////529. 扫雷游戏
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int row, col;
//int dx[8] = { 1, -1, 1, -1, 1, -1, 0 ,0 };
//int dy[8] = { 1, -1, -1, 1, 0, 0, 1 ,-1 };
//void dfs(char** grid, int x, int y)
//{
//    int sum = 0;
//    for (int i = 0; i < 8; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        if (mx < 0 || mx >= row || my < 0 || my >= col)
//            continue;
//        sum += grid[mx][my] == 'M';
//    }
//    if (sum)
//        grid[x][y] = sum + '0';
//    else
//    {
//        grid[x][y] = 'B';
//        for (int i = 0; i < 8; i++)
//        {
//            int mx = x + dx[i];
//            int my = y + dy[i];
//            if (mx < 0 || mx >= row || my < 0 || my >= col || grid[mx][my] != 'E')
//                continue;
//            dfs(grid, mx, my);
//        }
//    }
//}
//char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes)
//{
//    row = boardSize;
//    col = boardColSize[0];
//
//    int x = click[0], y = click[1];
//    if (board[x][y] == 'M')
//        board[x][y] = 'X';
//    else
//        dfs(board, x, y);
//
//    *returnSize = row;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
//    for (int i = 0; i < row; i++)
//    {
//        (*returnColumnSizes)[i] = col;
//    }
//    return board;
//}
//
////1391. 检查网格中是否存在有效路径
//
//int row, col;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int Pipe[7][4] = { {-1, -1, -1, -1}, {-1, 1, -1, 3}, {0, -1, 2, -1}, {-1, 0, 3, -1}, {-1, -1, 1, 0}, {3, 2, -1, -1}, {1, -1, -1, 2} };//0代表向下、1代表向右、2代表向上、3代表向左、-1代表不可走
//bool dfs(int** grid, int dir, int x, int y, bool** vis)
//{
//    vis[x][y] = 1;
//    if (x == row - 1 && y == col - 1)
//        return true;
//
//    int mx = x + dx[dir];
//    int my = y + dy[dir];
//    if (mx < 0 || mx >= row || my < 0 || my >= col)
//        return false;
//    int nxt = grid[mx][my];
//    if (Pipe[nxt][dir] != -1 && !vis[mx][my])
//        return dfs(grid, Pipe[nxt][dir], mx, my, vis);
//
//    return false;
//}
//bool hasValidPath(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = gridColSize[0];
//    int start = grid[0][0];
//    bool** vis = (bool**)malloc(sizeof(bool*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        vis[i] = (bool*)calloc(sizeof(bool), col);
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        if (Pipe[start][i] != -1)
//        {
//            if (dfs(grid, Pipe[start][i], 0, 0, vis))
//                return true;
//        }
//    }
//    return false;
//}
//
////1926. 迷宫中离入口最近的出口
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize)
//{
//    int row = mazeSize, col = mazeColSize[0];
//    bool** vis = (bool**)malloc(sizeof(bool*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        vis[i] = (bool*)calloc(sizeof(bool), col);
//    }
//    int** queue = (int**)malloc(sizeof(int*) * row * col);
//    for (int i = 0; i < row * col; i++)
//    {
//        queue[i] = (int*)malloc(sizeof(int) * 2);
//    }
//    int bottom = 0, top = 0;
//    int sx = entrance[0], sy = entrance[1];
//    vis[sx][sy] = true;
//    queue[top][0] = sx;
//    queue[top++][1] = sy;
//    for (int ans = 1; top > bottom; ans++)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int j = start; j < bottom; j++)
//        {
//            for (int i = 0; i < 4; i++)
//            {
//                int x = queue[j][0] + dx[i];
//                int y = queue[j][1] + dy[i];
//                if (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == '.' && !vis[x][y])
//                {
//                    if (x == 0 || x == row - 1 || y == 0 || y == col - 1)
//                        return ans;
//
//                    vis[x][y] = true;
//                    queue[top][0] = x;
//                    queue[top++][1] = y;
//                }
//            }
//        }
//    }
//    return -1;
//}
//
////1091. 二进制矩阵中的最短路径
//
//int dx[8] = { -1, -1, 1, 1, -1, 1, 0, 0 };
//int dy[8] = { -1, 1, -1, 1, 0, 0, -1, 1 };
//int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
//{
//    if (grid[0][0])
//        return -1;
//    if (gridSize == 1 && gridColSize[0] == 1)
//        return 1;
//    int row = gridSize, col = gridColSize[0];
//    bool** vis = (bool**)malloc(sizeof(bool*) * row);
//    for (int i = 0; i < row; i++)
//    {
//        vis[i] = (bool*)calloc(sizeof(bool), col);
//    }
//    int queue[row * col][2];
//    int bottom = 0, top = 0;
//    queue[top][0] = 0;
//    queue[top++][1] = 0;
//    for (int ans = 2; top > bottom; ans++)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int j = start; j < bottom; j++)
//        {
//            for (int i = 0; i < 8; i++)
//            {
//                int x = queue[j][0] + dx[i];
//                int y = queue[j][1] + dy[i];
//                if (x >= 0 && x < row && y >= 0 && y < col && !grid[x][y] && !vis[x][y])
//                {
//                    if (x == row - 1 && y == col - 1)
//                        return ans;
//
//                    vis[x][y] = true;
//                    queue[top][0] = x;
//                    queue[top++][1] = y;
//                }
//            }
//        }
//    }
//    return -1;
//}
//
