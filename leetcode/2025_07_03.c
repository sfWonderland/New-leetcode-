////3304. 找出第 K 个字符 I
//
//char kthCharacter(int k)
//{
//    int n = 0;
//    k--;
//    while (k)
//    {
//        n++;
//        k &= k - 1;
//    }
//    return 'a' + n;
//}
//
////2038. 如果相邻两个颜色均相同则删除当前颜色
//
//bool winnerOfGame(char* colors)
//{
//    int arr[2] = { 0 }, sum = 1, i, j;
//    for (i = 0; colors[i];)
//    {
//        for (j = i + 1; colors[j] == colors[i]; j++)
//            ;
//        arr[colors[i] - 'A'] += fmax(j - i - 2, 0);
//        i = j;
//    }
//    return arr[0] > arr[1];
//}
//
////223. 矩形面积
//
//int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
//{
//    int s_total = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
//    int s_lap = 0;
//    if (!(ax2 < bx1 || ay2 < by1 || bx2 < ax1 || by2 < ay1))
//    {
//        int x1 = fmax(ax1, bx1), y1 = fmax(ay1, by1);
//        int x2 = fmin(ax2, bx2), y2 = fmin(ay2, by2);
//        s_lap = (x2 - x1) * (y2 - y1);
//    }
//    return s_total - s_lap;
//}
//
////2834. 找出美丽数组的最小和.
//
//#define mod 1000000007
//int minimumPossibleSum(int n, int target)
//{
//    long long m = fmin(target / 2, n);
//    return (m * (m + 1) + (-m + 2 * target + n - 1) * (n - m)) / 2 % mod;
//}
//
