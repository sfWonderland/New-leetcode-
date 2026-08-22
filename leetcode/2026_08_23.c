//// 1927. ÇóºÍÓÎÏ·
//
//bool sumGame(char* num)
//{
//    int n = strlen(num);
//    int sumL = 0, sumR = 0;
//    int qL = 0, qR = 0;
//    for (int i = 0; i < n / 2; i++)
//    {
//        if (num[i] == '?')
//            qL++;
//        else
//            sumL += num[i] & 15;
//    }
//    for (int i = n / 2; i < n; i++)
//    {
//        if (num[i] == '?')
//            qR++;
//        else
//            sumR += num[i] & 15;
//    }
//    // printf("%d %d %d %d %d\n", sumL, sumR, qL, qR, 2 * (sumL - sumR) + 9 * (qL - qR));
//    return 2 * (sumL - sumR) + 9 * (qL - qR);
//}
//
