//#define _CRT_SECURE_NO_WARNINGS
//
////1385.两个数组间的距离值
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int binarySearch(int* arr, int arrSize, int target)
//{
//    int left = 0;
//    int right = arrSize;
//    while (left < right)
//    {
//        int mid = ((right - left) >> 1) + left;
//        //printf("l = %d, r = %d, mid = %d\n", left, right, mid);
//        if (arr[mid] >= target)
//            right = mid;
//        else if (arr[mid] < target)
//            left = mid + 1;
//    }
//    return left;
//}
//int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
//{
//    qsort(arr2, arr2Size, sizeof(int), cmp);
//    int ret = 0;
//    for (int i = 0; i < arr1Size; i++)
//    {
//
//        if (arr2[0] > arr1[i])
//        {
//            if (arr2[0] - arr1[i] > d)
//                ret++;
//        }
//        else if (arr2[arr2Size - 1] < arr1[i])
//        {
//            if (arr1[i] - arr2[arr2Size - 1] > d)
//                ret++;
//        }
//        else
//        {
//            //printf("enter the loop\n");
//            int right = binarySearch(arr2, arr2Size, arr1[i]);
//            //printf("out of the loop\n");
//            int left = right - 1;
//            if (arr2[right] - arr1[i] > d && arr1[i] - arr2[left] > d)
//                ret++;
//        }
//    }
//
//    return ret;
//}
//
////1389.
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
//{
//    int* p = (int*)malloc(sizeof(int) * indexSize);
//
//    for (int i = 0; i < indexSize; i++)
//    {
//        for (int j = i; j > index[i]; j--)
//            p[j] = p[j - 1];
//        p[index[i]] = nums[i];
//    }
//    *returnSize = indexSize;
//    return p;
//}
//
////977.有序数的平方
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sortedSquares(int* nums, int numsSize, int* returnSize)
//{
//    int* p = (int*)malloc(sizeof(int) * numsSize);
//    if (nums[0] >= 0)
//    {
//        for (int i = 0; i < numsSize; i++)
//        {
//            p[i] = nums[i] * nums[i];
//        }
//    }
//    else
//    {
//        int left = 0;
//        int right = numsSize - 1;
//        int n = numsSize - 1;
//        while (n >= 0)
//        {
//            if (nums[left] + nums[right] < 0)
//            {
//                p[n] = nums[left] * nums[left];
//                left++;
//            }
//            else
//            {
//                p[n] = nums[right] * nums[right];
//                right--;
//            }
//            n--;
//        }
//    }
//
//    *returnSize = numsSize;
//    return p;
//}
//
////733.图像渲染
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
// //深度优先搜索
//const int dx[4] = { 0,0,-1,1 };
//const int dy[4] = { 1,-1,0,0 };
//
//int m, n;
//void EnactPaint(int** image, int x, int y, int color, int Newcolor)
//{
//    if (image[x][y] == color)
//    {
//        image[x][y] = Newcolor;
//        for (int i = 0; i < 4; i++)
//        {
//            int mx = x + dx[i];
//            int my = y + dy[i];
//            if (mx >= 0 && mx < n && my >= 0 && my < m)
//                EnactPaint(image, mx, my, color, Newcolor);
//        }
//    }
//}
//int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
//{
//    n = imageSize;
//    m = *imageColSize;
//    *returnSize = imageSize;
//    *returnColumnSizes = malloc(sizeof(int) * (*imageColSize));
//    for (int i = 0; i < imageSize; i++)
//    {
//        (*returnColumnSizes)[i] = imageColSize[0];
//    }
//    if (image[sr][sc] != color)
//        EnactPaint(image, sr, sc, image[sr][sc], color);
//    return image;
//}
//
////广度优先搜索
//const int dx[4] = { 0,0,-1,1 };
//const int dy[4] = { 1,-1,0,0 };
//
//int m, n;
//
//int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
//{
//    n = imageSize;
//    m = *imageColSize;
//    *returnSize = imageSize;
//    *returnColumnSizes = malloc(sizeof(int) * (*imageColSize));
//    for (int i = 0; i < imageSize; i++)
//    {
//        (*returnColumnSizes)[i] = imageColSize[0];
//    }
//    if (image[sr][sc] != color)
//    {
//        int currColor = image[sr][sc];
//        int que[n * m][2];
//        int l = 0;
//        int r = 0;
//        que[r][0] = sr;
//        que[r++][1] = sc;
//        image[sr][sc] = color;
//        while (l < r)
//        {
//            int x = que[l][0];
//            int y = que[l++][1];
//            for (int i = 0; i < 4; i++)
//            {
//                int mx = x + dx[i];
//                int my = y + dy[i];
//                if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor)
//                {
//                    que[r][0] = mx;
//                    que[r++][1] = my;
//                    image[mx][my] = color;
//                }
//            }
//        }
//    }
//    return image;
//}
//
////463.岛屿的周长（改）
//
//int row, col;
//int dfs(int** grid, int i, int j)
//{
//    if (!(i >= 0 && i < row && j >= 0 && j < col))
//        return 1;
//    if (0 == grid[i][j])
//        return 1;
//    if (2 == grid[i][j])
//        return 0;
//    grid[i][j] = 2;
//    return dfs(grid, i - 1, j)
//        + dfs(grid, i + 1, j)
//        + dfs(grid, i, j - 1)
//        + dfs(grid, i, j + 1);
//}
//int islandPerimeter(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = *gridColSize;
//    int perimeter = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (1 == grid[i][j])
//            {
//                return dfs(grid, i, j);
//                //printf("i = %d, j = %d, perimeter = %d\n", i, j, perimeter);
//            }
//        }
//    }
//    return -1;
//}
//
////695.岛屿的最大面积（改）
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int dps(int** grid, int x, int y)
//{
//    if (!(x >= 0 && x < row && y >= 0 && y < col))
//        return 0;
//
//    if (!grid[x][y])
//        return 0;
//    int sum = 1;
//    grid[x][y] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dps(grid, mx, my);
//    }
//    return sum;
//}
//int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = *gridColSize;
//    int square = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (grid[i][j])
//            {
//                int tmp = dps(grid, i, j);
//                if (tmp > square)
//                    square = tmp;
//            }
//        }
//    }
//    return square;
//}
//
////419. 棋盘上的战舰
//
//int countBattleships(char** board, int boardSize, int* boardColSize)
//{
//    int row = boardSize;
//    int col = *boardColSize;
//    int num = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if ('X' == board[i][j])
//            {
//                if (i > 0 && board[i - 1][j] == 'X')
//                    continue;
//                if (j > 0 && board[i][j - 1] == 'X')
//                    continue;
//                num++;
//            }
//        }
//    }
//    return num;
//}
//
////200.岛屿数量
//
//int row, col;
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//void dps(char** grid, int x, int y)
//{
//    if (!(x >= 0 && x < row && y >= 0 && y < col))
//        return;
//    if ('1' != grid[x][y])
//        return;
//
//    grid[x][y]--;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        dps(grid, mx, my);
//    }
//}
//int numIslands(char** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = *gridColSize;
//    int num = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if ('1' == grid[i][j])
//            {
//                dps(grid, i, j);
//                num++;
//            }
//        }
//    }
//    return num;
//}
//
////827.最大人工岛
//
//int row, col;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//int dps(int** grid, int x, int y, int n)
//{
//    if (!(x >= 0 && x < row && y >= 0 && y < col))
//        return 0;
//    if (grid[x][y] != 1)
//        return 0;
//
//    grid[x][y] = n;
//    int sum = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        sum += dps(grid, mx, my, n);
//    }
//    //printf("sum = %d\n", sum);
//    return sum;
//}
//int connect(int** grid, int x, int y, int* arr)
//{
//    int s[4] = { 0 };
//    if (x > 0)
//        s[0] = grid[x - 1][y];
//    if (x < row - 1)
//        s[1] = grid[x + 1][y];
//    if (y > 0)
//        s[2] = grid[x][y - 1];
//    if (y < col - 1)
//        s[3] = grid[x][y + 1];
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = i + 1; j < 4; j++)
//        {
//            if (s[i] && s[i] == s[j])
//                s[i] = 0;
//        }
//    }
//    int sum = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        //printf("s[%d] = %d\n", i, s[i]);
//        //printf("arr[s[%d]] = %d\n", i, arr[s[i]]);
//        sum += arr[s[i]];
//    }
//    //printf("\n");
//    return sum + 1;
//}
//int largestIsland(int** grid, int gridSize, int* gridColSize)
//{
//    row = gridSize;
//    col = *gridColSize;
//    int* arr = (int*)malloc(sizeof(int) * 20000);
//    memset(arr, 0, sizeof(int) * 20000);
//    int n = 2;
//    //遍历陆地
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (1 == grid[i][j])
//            {
//                arr[n] = dps(grid, i, j, n);
//                //printf("arr[%d] = %d\n", n, arr[n]);
//                n++;
//            }
//        }
//    }
//    //遍历海洋
//    int ret = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (0 == grid[i][j])
//            {
//                int tmp = connect(grid, i, j, arr);
//                if (tmp > ret)
//                    ret = tmp;
//            }
//        }
//    }
//
//    free(arr);
//
//    if (!ret)
//        return row * col;
//
//    return ret;
//}
//