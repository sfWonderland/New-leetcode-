//// 4043. 恰好有 K 对相等相邻字符的循环移位数量
//
//int countRotations(char* s, int k)
//{
//    int n = strlen(s);
//    int ans = 0, score = 0;
//    for (int i = 1; i < n; i++)
//    {
//        score += (s[i] == s[i - 1]);
//    }
//    ans += (score == k);
//    if (s[0] == s[n - 1])
//        score++;
//    for (int i = 1; i < n; i++)
//    {
//        int score_i = score;
//        if (s[i - 1] == s[i])
//            score_i--;
//
//        ans += (score_i == k);
//    }
//    return ans;
//}
//
