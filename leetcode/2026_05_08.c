//// LCP 11. 期望个数统计
//
//int expectNumber(int* scores, int scoresSize)
//{
//    bool vis[1000001] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < scoresSize; i++)
//    {
//        if (vis[scores[i]])
//            continue;
//
//        vis[scores[i]] = true;
//        ans++;
//    }
//    return ans;
//}
//
//// LCP 19. 秋叶收藏集   
//
//int minimumOperations(char* leaves)
//{
//    int n = strlen(leaves);
//    int f[n][3];
//    memset(f, 0, sizeof(f));
//    // 状态机dp
//    for (int i = 0; i < n; i++)
//    {
//        bool flag = leaves[i] != 'r';
//        // 全红， 不是红 + 1
//        f[i][0] = i < 1 ? flag : f[i - 1][0] + flag;
//        // 先红后黄， 红黄 + 黄 或者 红 + 黄
//        f[i][1] = i < 1 ? f[i][0] : fmin(f[i - 1][0] + 1 - flag, f[i - 1][1] + 1 - flag);
//        // 红黄红，红黄红 + 红 或者 红黄 + 红
//        f[i][2] = i < 2 ? f[i][1] : fmin(f[i - 1][1] + flag, f[i - 1][2] + flag);
//    }
//
//    return f[n - 1][2];
//}
//
//// 面试题 05.03. 翻转数位
//
//int reverseBits(int num)
//{
//    int cur = 0, insert = 0;
//    int res = 1;
//    for (int i = 0; i < 32; i++)
//    {
//        if (num & (1ll << i))
//        {
//            cur++;
//            insert++;
//        }
//        else
//        {
//            insert = cur + 1;
//            cur = 0;
//        }
//        res = fmax(res, insert);
//    }
//    return res;
//}
//
//// 面试题 05.06. 整数转换
//
//int convertInteger(int A, int B)
//{
//    unsigned int a = A;
//    unsigned int b = B;
//    a ^= b;
//    int ans = 0;
//    while (a)
//    {
//        ans += a & 1;
//        a >>= 1;
//    }
//    return ans;
//}
//
