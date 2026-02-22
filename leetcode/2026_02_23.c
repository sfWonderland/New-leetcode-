////1395. 统计作战单位数
//
//int numTeams(int* rating, int ratingSize)
//{
//    int ans = 0;
//    for (int j = 1; j < ratingSize - 1; j++)
//    {
//        int iless = 0, imore = 0;
//        int kless = 0, kmore = 0;
//        for (int i = 0; i < j; i++)
//        {
//            if (rating[i] < rating[j])
//                iless++;
//            else if (rating[i] > rating[j])
//                imore++;
//        }
//        for (int k = j + 1; k < ratingSize; k++)
//        {
//            if (rating[k] < rating[j])
//                kless++;
//            else if (rating[k] > rating[j])
//                kmore++;
//        }
//        ans += iless * kmore + imore * kless;
//    }
//    return ans;
//}
//
////1404. 将二进制表示减到 1 的步骤数    
//
//int numSteps(char* s)
//{
//    int n = strlen(s);
//    int ans = n - 1;
//    int i = n - 1;
//    while (s[i] == '0')
//        i--;
//    if (i == 0)
//        return ans;
//
//    for (int j = 1; j < i; j++)
//    {
//        ans += '1' - s[j];
//    }
//    return ans + 2;
//}
//
////1541. 平衡括号字符串的最少插入次数
//
//// 进右括号，记录右括号数
//// 进第一个左括号, 就清算左括号数a和右括号数b，
//// 清算公式 (b + 1) / 2 >= a 右 ：b % 2 左 ：(b + 1) / 2 - a
////         (b + 1) / 2 < a 右 ：b % 2 + (a - (b + 1) / 2) * 2
//// 后续左括号数记录
//int minInsertions(char* s)
//{
//    int n = strlen(s);
//    int sum[2] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(' && sum[1])
//        {
//            if (sum[1] & 1)
//            {
//                ans++;
//                sum[1]++;
//            }
//            int pairs = sum[1] / 2;
//            if (pairs <= sum[0])
//                sum[0] -= pairs;
//            else
//            {
//                ans += pairs - sum[0];
//                sum[0] = 0;
//            }
//            sum[1] = 0;
//        }
//        sum[s[i] - '(']++;
//        //printf("%d %d %d\n", sum[0], sum[1], ans);
//    }
//    int right_pair = (sum[1] + 1) / 2;
//    if (right_pair >= sum[0])
//        ans += sum[1] % 2 + right_pair - sum[0];
//    else
//        ans += sum[1] % 2 + (sum[0] - right_pair) * 2;
//    //printf("%d ", ans);
//    return ans;
//}
//
////1583. 统计不开心的朋友
//
//int unhappyFriends(int n, int** preferences, int preferencesSize, int* preferencesColSize, int** pairs, int pairsSize, int* pairsColSize)
//{
//    int order[n][n];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n - 1; j++)
//        {
//            order[i][preferences[i][j]] = j;
//        }
//    }
//    int match[n];
//    for (int i = 0; i < pairsSize; i++)
//    {
//        match[pairs[i][0]] = pairs[i][1];
//        match[pairs[i][1]] = pairs[i][0];
//    }
//    int unhappyCnt = 0;
//    for (int x = 0; x < n; x++)
//    {
//        int y = match[x];
//        int index = order[x][y];
//        // x 与 u 的亲近程度胜过 x 与 y
//        for (int i = 0; i < index; i++)
//        {
//            int u = preferences[x][i];
//            int v = match[u];
//            // u 与 x 的亲近程度胜过 u 与 v
//            if (order[u][x] < order[u][v])
//            {
//                ++unhappyCnt;
//                break;
//            }
//        }
//    }
//    return unhappyCnt;
//}
//
