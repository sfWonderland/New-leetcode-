////808. 分汤
//int arr[4][2] = { {-4, 0}, {-3, -1}, {-2, -2}, {-1, -3} };
//double soupServings(int n)
//{
//    if (n >= 4475) return 1;
//    n = fmin((n + 24) / 25, 200);
//    double f[n + 1][n + 1];
//    f[0][0] = 0.5;
//    for (int i = 1; i <= n; i++) { f[i][0] = 0; f[0][i] = 1; }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            f[i][j] = 0;
//            for (int k = 0; k < 4; k++)
//            {
//                int x = fmax(i + arr[k][0], 0);
//                int y = fmax(j + arr[k][1], 0);
//                f[i][j] += 0.25 * f[x][y];
//            }
//        }
//    }
//    return f[n][n];
//}
//
////36. 有效的数独
//
//bool isValidSudoku(char** board, int boardSize, int* boardColSize)
//{
//    for (int i = 0; i < 9; i++) //行，列验证
//    {
//        bool digit1[10] = { 0 };
//        bool digit2[10] = { 0 };
//        for (int j = 0; j < 9; j++)
//        {
//            if (board[i][j] != '.')
//            {
//                int x = board[i][j] - '0';
//                if (digit1[x])
//                    return false;
//                digit1[x] = true;
//            }
//            if (board[j][i] != '.')
//            {
//                int y = board[j][i] - '0';
//                if (digit2[y])
//                    return false;
//                digit2[y] = true;
//            }
//        }
//    }
//    for (int i = 0; i < 9; i += 3) //方格验证
//    {
//        for (int j = 0; j < 9; j += 3)
//        {
//            bool digit[10] = { 0 };
//            for (int r = i; r < i + 3; r++)
//            {
//                for (int c = j; c < j + 3; c++)
//                {
//                    if (board[r][c] == '.')
//                        continue;
//                    int x = board[r][c] - '0';
//                    if (digit[x])
//                        return false;
//
//                    digit[x] = true;
//                }
//            }
//        }
//    }
//    return true;
//}
//
////134. 加油站
//
//int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
//{
//    int curSum = 0, totalSum = 0, start = 0;
//    for (int i = 0; i < gasSize; i++)
//    {
//        int x = gas[i] - cost[i];
//        curSum += x;
//        totalSum += x;
//        if (curSum < 0)
//        {
//            start = i + 1;
//            curSum = 0;
//        }
//    }
//    if (totalSum < 0) return -1;
//    return start;
//}
//
////179. 最大数
//
//int cmp(const void* a, const void* b)
//{
//    char s[100], s1[100];
//    sprintf(s, "%d%d", *(int*)a, *(int*)b);
//    sprintf(s1, "%d%d", *(int*)b, *(int*)a);
//    return strcmp(s1, s);
//}
//char* largestNumber(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    if (nums[0] == 0)
//        return "0";
//    char* ans = (char*)malloc(sizeof(char) * 11 * numsSize);
//    char* p = ans;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sprintf(p, "%d", nums[i]);
//        p += strlen(p);
//    }
//    return ans;
//}
//
