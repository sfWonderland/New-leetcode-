////3242. 设计相邻元素求和服务
//
//int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
//
//typedef struct
//{
//    int* ATable;
//    int* DTable;
//} NeighborSum;
//
//
//NeighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize)
//{
//    NeighborSum* obj = (NeighborSum*)malloc(sizeof(NeighborSum));
//    obj->ATable = (int*)malloc(sizeof(int) * gridSize * gridSize);
//    obj->DTable = (int*)malloc(sizeof(int) * gridSize * gridSize);
//    for (int i = 0; i < gridSize; i++)
//    {
//        for (int j = 0; j < gridSize; j++)
//        {
//            int x = grid[i][j];
//            obj->ATable[x] = 0;
//            obj->DTable[x] = 0;
//            for (int k = 0; k < 4; k++)
//            {
//                int mx = dx[k] + i;
//                int my = dy[k] + j;
//                if (mx < 0 || mx >= gridSize || my < 0 || my >= gridSize)
//                    continue;
//                obj->ATable[x] += grid[mx][my];
//            }
//            for (int k = 4; k < 8; k++)
//            {
//                int mx = dx[k] + i;
//                int my = dy[k] + j;
//                if (mx < 0 || mx >= gridSize || my < 0 || my >= gridSize)
//                    continue;
//                obj->DTable[x] += grid[mx][my];
//            }
//        }
//    }
//    return obj;
//}
//
//int neighborSumAdjacentSum(NeighborSum* obj, int value)
//{
//    return obj->ATable[value];
//}
//
//int neighborSumDiagonalSum(NeighborSum* obj, int value)
//{
//    return obj->DTable[value];
//}
//
//void neighborSumFree(NeighborSum* obj)
//{
//    free(obj->ATable);
//    free(obj->DTable);
//    free(obj);
//}
//
///**
// * Your NeighborSum struct will be instantiated and called as such:
// * NeighborSum* obj = neighborSumCreate(grid, gridSize, gridColSize);
// * int param_1 = neighborSumAdjacentSum(obj, value);
//
// * int param_2 = neighborSumDiagonalSum(obj, value);
//
// * neighborSumFree(obj);
//*/
//
////3658. 奇数和与偶数和的最大公约数
//
//int gcdOfOddEvenSums(int n)
//{
//    return n;
//}
//
////LCR 085. 括号生成
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** ans;
//int ansSize;
//char* tmp;
//int tmpSize;
//int max;
//void dfs(int depth)
//{
//    if (depth > max || depth < 0)
//        return;
//
//    if (tmpSize == 2 * max)
//    {
//        if (!depth)
//        {
//            ans[ansSize] = (char*)malloc(sizeof(char) * (2 * max + 1));
//            strcpy(ans[ansSize], tmp);
//            ansSize++;
//        }
//        return;
//    }
//
//    tmp[tmpSize++] = '(';
//    dfs(depth + 1);
//    tmpSize--;
//    tmp[tmpSize++] = ')';
//    dfs(depth - 1);
//    tmpSize--;
//}
//char** generateParenthesis(int n, int* returnSize)
//{
//    ans = (char**)malloc(sizeof(char*) * 1500);
//    ansSize = 0;
//    tmp = (char*)malloc(sizeof(char) * (2 * n + 1));
//    tmpSize = 0;
//    max = n;
//    tmp[tmpSize++] = '(';
//    tmp[2 * n] = '\0';
//    dfs(1);
//    *returnSize = ansSize;
//    return ans;
//}
//
////3271. 哈希分割字符串
//
//char* stringHash(char* s, int k)
//{
//    int n = strlen(s);
//    int m = n / k;
//    char* ans = (char*)malloc(sizeof(char) * (m + 1));
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += s[i] - 'a';
//        if (i % k == k - 1)
//        {
//            ans[i / k] = sum % 26 + 'a';
//            sum = 0;
//        }
//    }
//    ans[m] = '\0';
//    return ans;
//}
//
