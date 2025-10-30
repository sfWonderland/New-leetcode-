////2055. 蜡烛之间的盘子
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* platesBetweenCandles(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int n = strlen(s);
//    int sum[n + 1]; // sum[i] 表示 s[:i] 中盘子的个数
//    int left[n]; // left[i] 表示 i 左侧最近蜡烛位置
//    sum[0] = 0;
//    int p = -1;
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = sum[i];
//        if (s[i] == '|')
//            p = i;
//        else
//            sum[i + 1]++;
//
//        left[i] = p;
//    }
//    int right[n]; // right[i] 表示 i 右侧最近蜡烛位置
//    p = n;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (s[i] == '|')
//            p = i;
//
//        right[i] = p;
//    }
//
//    int* ans = (int*)calloc(sizeof(int), queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int l = right[queries[i][0]], r = left[queries[i][1]];
//        if (l < r)
//            ans[i] = sum[r] - sum[l];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* canEat(int* candiesCount, int candiesCountSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int n = candiesCountSize;
//    long long sum[n + 1];
//    sum[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = sum[i] + candiesCount[i];
//    }
//    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        long long max = 1ll * (queries[i][1] + 1) * queries[i][2];
//        if (sum[queries[i][0]] < max && sum[queries[i][0] + 1] > queries[i][1])
//            ans[i] = true;
//        else
//            ans[i] = false;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////3453. 分割正方形 I
//
//bool check(int** squares, int n, long long area, double y)
//{
//    double sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += 1.0 * squares[i][2] * fmin(fmax(y - squares[i][1], 0), squares[i][2]);
//    }
//    return sum >= area / 2.0;
//}
//double separateSquares(int** squares, int squaresSize, int* squaresColSize)
//{
//    long long t_area = 0;
//    int max_y = 0;
//    for (int i = 0; i < squaresSize; i++)
//    {
//        t_area += 1ll * squares[i][2] * squares[i][2];
//        max_y = fmax(max_y, squares[i][1] + squares[i][2]);
//    }
//    double left = 0, right = max_y;
//    for (int i = 0; i < 47; i++) // 2 ^ 47 > 10 ^ 5 * 10 ^ 9
//    {
//        double mid = (right + left) / 2;
//        if (check(squares, squaresSize, t_area, mid))
//            right = mid;
//        else
//            left = mid;
//    }
//    return (right + left) / 2;
//}
//
////2381. 字母移位 II
//
//char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize)
//{
//    int n = strlen(s);
//    int dx[n + 1];
//    memset(dx, 0, sizeof(dx));
//    for (int i = 0; i < shiftsSize; i++)
//    {
//        int d = shifts[i][2] ? 1 : -1;
//        dx[shifts[i][0]] += d;
//        dx[shifts[i][1] + 1] -= d;
//    }
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum = (sum + dx[i]) % 26 + 26;
//        s[i] = (s[i] - 'a' + sum) % 26 + 'a';
//    }
//    return s;
//}
//
