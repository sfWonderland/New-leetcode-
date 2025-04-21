////2160. 拆分数位后四位数字的最小和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minimumSum(int num)
//{
//    int nums[4] = { 0 };
//    int n = 0;
//    while (num)
//    {
//        nums[n++] = num % 10;
//        num /= 10;
//    }
//    qsort(nums, 4, sizeof(int), cmp);
//    return (nums[0] + nums[1]) * 10 + nums[2] + nums[3];
//}
//
////2379. 得到 K 个黑块的最少涂色次数
//
////滑动窗口
//int minimumRecolors(char* blocks, int k)
//{
//    int l = 0, r = 0, cnt = 0;
//    while (r < k)
//    {
//        cnt += blocks[r] == 'W' ? 1 : 0;
//        r++;
//    }
//    int res = cnt;
//    int n = strlen(blocks);
//    while (r < n)
//    {
//        cnt += blocks[r] == 'W' ? 1 : 0;
//        cnt -= blocks[l] == 'W' ? 1 : 0;
//        res = fmin(res, cnt);
//        r++;
//        l++;
//    }
//    return res;
//}
//
////2660. 保龄球游戏的获胜者
//
//int isWinner(int* player1, int player1Size, int* player2, int player2Size)
//{
//    int score1 = 0, score2 = 0;
//    int valid1 = 0, valid2 = 0;
//    for (int i = 0; i < player1Size; i++)
//    {
//        score1 += player1[i] * (1 + (valid1 > 0));
//        score2 += player2[i] * (1 + (valid2 > 0));
//        valid1 = valid1 > 0 ? valid1 - 1 : 0;
//        valid2 = valid2 > 0 ? valid2 - 1 : 0;
//        if (player1[i] == 10)
//            valid1 = 2;
//        if (player2[i] == 10)
//            valid2 = 2;
//    }
//    if (score1 == score2)
//        return 0;
//    else
//        return score1 > score2 ? 1 : 2;
//}
//
////2828. 判别首字母缩略词
//
//bool isAcronym(char** words, int wordsSize, char* s)
//{
//    if (strlen(s) != wordsSize)
//        return false;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (words[i][0] != s[i])
//            return false;
//    }
//    return true;
//}
//
