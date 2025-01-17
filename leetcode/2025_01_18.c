//#define _CRT_SECURE_NO_WARNINGS
//
////461.汉明距离
//
//int hammingDistance(int x, int y)
//{
//    x = x ^ y;
//    int n = 0;
//    while (x)
//    {
//        x &= x - 1;
//        n++;
//    }
//    return n;
//}
//
////463.岛屿的周长
//
//int surranding(int** grid, int gridSize, int* gridColSize, int i, int j)
//{
//    int count = 0;
//    if (0 == i || 0 == grid[i - 1][j])
//        count++;
//    if (gridSize - 1 == i || 0 == grid[i + 1][j])
//        count++;
//    if (0 == j || 0 == grid[i][j - 1])
//        count++;
//    if (*gridColSize - 1 == j || 0 == grid[i][j + 1])
//        count++;
//    return count;
//}
//int islandPerimeter(int** grid, int gridSize, int* gridColSize)
//{
//    //printf("gridSize = %d\n", gridSize);//row
//    //printf("gridColSize = %d\n", *gridColSize);//col
//    int perimeter = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < *gridColSize; j++)
//        {
//            if (1 == grid[i][j])
//            {
//                perimeter += surranding(grid, gridSize, gridColSize, i, j);
//                //printf("i = %d, j = %d, perimeter = %d\n", i, j, perimeter);
//            }
//        }
//    }
//    return perimeter;
//}
//
////695.岛屿的面积
//
//void RowOrCol(int** grid, int gridSize, int* gridColSize, int i, int j, int* square);
//void sort(int** grid, int gridSize, int* gridColSize, int i, int j, int* square)
//{
//    grid[i][j] = 0;
//    (*square)++;
//    RowOrCol(grid, gridSize, gridColSize, i, j, square);
//}
//void RowOrCol(int** grid, int gridSize, int* gridColSize, int i, int j, int* square)
//{
//    if (0 != i && 1 == grid[i - 1][j])
//        sort(grid, gridSize, gridColSize, i - 1, j, square);
//    if (gridSize - 1 != i && 1 == grid[i + 1][j])
//        sort(grid, gridSize, gridColSize, i + 1, j, square);
//    if (0 != j && 1 == grid[i][j - 1])
//        sort(grid, gridSize, gridColSize, i, j - 1, square);
//    if (*gridColSize - 1 != j && 1 == grid[i][j + 1])
//        sort(grid, gridSize, gridColSize, i, j + 1, square);
//}
//int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
//{
//    int square = 0;
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < *gridColSize; j++)
//        {
//            if (1 == grid[i][j])
//            {
//                int tmp = 0;
//                RowOrCol(grid, gridSize, gridColSize, i, j, &tmp);
//                if (!tmp)
//                    tmp++;
//                //printf("i = %d, j = %d, tmp = %d\n", i, j, tmp);
//                if (tmp > square)
//                {
//                    square = tmp;
//                    //printf("i = %d, j = %d, square = %d\n", i, j, square);
//                }
//            }
//        }
//    }
//    return square;
//}