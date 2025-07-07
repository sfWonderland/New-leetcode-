////2373. 矩阵中的局部最大值
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int pos[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
//
//int get_max(int** grid, int x, int y)
//{
//    int max = grid[x][y];
//    for (int i = 0; i < 8; i++)
//    {
//        int xi = pos[i][0] + x;
//        int yi = pos[i][1] + y;
//        max = fmax(grid[xi][yi], max);
//    }
//    return max;
//}
//int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * (gridSize - 2));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (gridSize - 2));
//    for (int i = 0; i < gridSize - 2; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * (gridSize - 2));
//        for (int j = 0; j < gridSize - 2; j++)
//        {
//            ans[i][j] = get_max(grid, i + 1, j + 1);
//        }
//        (*returnColumnSizes)[i] = gridSize - 2;
//    }
//    *returnSize = gridSize - 2;
//    return ans;
//}
//
////3258. 统计满足 K 约束的子字符串数量 I
//
//int countKConstraintSubstrings(char* s, int k)
//{
//    //越短越合法
//    int ans = 0, left = 0, arr[2] = { 0 };
//    for (int right = 0; s[right]; right++)
//    {
//        arr[s[right] & 1]++;
//        while (arr[0] > k && arr[1] > k)
//        {
//            arr[s[left] - '0']--;
//            left++;
//        }
//        ans += right - left + 1;
//    }
//    return ans;
//}
//
////3602. 十六进制和三十六进制转化
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* concatHex36(int n)
//{
//    char* ans = (char*)malloc(sizeof(char) * 14);
//    int a = n * n, b = n * n * n, i = 0, left = 0;
//    while (a)   //16
//    {
//        int t = a % 16;
//        ans[i] = t > 9 ? t - 10 + 'A' : t + '0';
//        a /= 16;
//        i++;
//    }
//    reverse(ans, left, i - 1);
//    left = i;
//    while (b)   //16
//    {
//        int t = b % 36;
//        ans[i] = t > 9 ? t - 10 + 'A' : t + '0';
//        b /= 36;
//        i++;
//    }
//    reverse(ans, left, i - 1);
//    ans[i] = '\0';
//    return ans;
//}
//
////2928. 给小朋友们分糖果 I
//
//int C2(int n)
//{
//    return n > 1 ? n * (n - 1) / 2 : 0;
//}
//int distributeCandies(int n, int limit)
//{
//    return C2(n + 2) - 3 * C2(n - limit + 1) + 3 * C2(n - 2 * limit) - C2(n - 3 * limit - 1);
//}
//
//