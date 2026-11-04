//// 2187. 完成旅途的最少时间
//
//bool check(int* time, int n, long long timeCost, int totalTrips)
//{
//    long long sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum += timeCost / time[i];
//        if (sum >= totalTrips)
//            return true;
//    }
//    return false;
//}
//long long minimumTime(int* time, int timeSize, int totalTrips)
//{
//    long long left = 0, right = 1e7 * totalTrips;
//    while (left <= right)
//    {
//        long long mid = (left + right) / 2;
//        if (check(time, timeSize, mid, totalTrips))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
