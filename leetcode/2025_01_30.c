//#define _CRT_SECURE_NO_WARNINGS
//
////883.三维形体投影面积
//
//int projectionArea(int** grid, int gridSize, int* gridColSize)
//{
//    int top = 0;
//    int front = 0;
//    int side = 0;
//
//    for (int x = 0; x < gridSize; x++)
//    {
//        int maxX = 0;
//        for (int y = 0; y < *gridColSize; y++)
//        {
//            //top
//            if (grid[x][y] != 0)
//                top++;
//            //front
//            if (grid[x][y] > maxX)
//                maxX = grid[x][y];
//        }
//        front += maxX;
//    }
//
//    for (int y = 0; y < *gridColSize; y++)
//    {
//        int maxY = 0;
//        for (int x = 0; x < gridSize; x++)
//        {
//            //side
//            if (grid[x][y] > maxY)
//                maxY = grid[x][y];
//        }
//        side += maxY;
//    }
//
//    return top + front + side;
//}
//
////908.最小差值I
//
//int smallestRangeI(int* nums, int numsSize, int k)
//{
//    int max = 0;
//    int min = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//            max = nums[i];
//        if (nums[i] < min)
//            min = nums[i];
//    }
//    int sum = max - min - 2 * k;
//    return sum > 0 ? sum : 0;
//}
//
////1816.截断句子
//
//char* truncateSentence(char* s, int k)
//{
//    int len = strlen(s);
//    int count = 1;
//    int i = 0;
//    while ((count < k + 1) && (i < len))
//    {
//        while (i < len && s[i] != ' ')
//            i++;
//        count++;
//        i++;
//        //printf("s[%d] = %c", i, s[i]);
//    }
//    if (i < len)
//        s[i - 1] = '\0';
//    return s;
//}
//
