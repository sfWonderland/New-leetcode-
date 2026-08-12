//// 2029. 石子游戏 IX
//
//bool check(int x, int y, int zero)
//{
//    // 排除三种情况：不能选，选了会用尽1，2余数的两种排序
//    if (!x || x == y + 1 || x == y + 2) return false;
//    // 其他情况类似击鼓传花，没有余数0，传不出去就自爆
//    return (y > x - 2) ^ zero;
//}
//bool stoneGameIX(int* stones, int stonesSize)
//{
//    int cnt[3] = { 0 };
//    for (int i = 0; i < stonesSize; i++)
//    {
//        cnt[stones[i] % 3]++;
//    }
//    // printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
//    cnt[0] &= 1;
//    if (cnt[1] == 0 && cnt[2] == 0) return false;
//    bool a = check(cnt[1], cnt[2], cnt[0]);
//    bool b = check(cnt[2], cnt[1], cnt[0]);
//    return a | b;
//}
//
