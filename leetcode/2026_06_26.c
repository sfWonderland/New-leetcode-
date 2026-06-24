//// 754. 到达终点数字
//
//int reachNumber(int target)
//{
//    target = abs(target);
//    double tmp = (sqrt(8ll * target + 1) - 1.0) / 2.0;
//    int n = (int)tmp;
//    // printf("%lf, %d\n", tmp, n);
//    if (tmp - 1.0 * n > 0)
//        n++;
//    // printf("%lf, %d", tmp, n);
//    return (n * (n + 1) / 2 - target) % 2 == 0 ? n : n + 1 + (n % 2);
//}
//
