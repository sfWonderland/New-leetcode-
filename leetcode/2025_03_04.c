////LCR 190. 加密运算
//
//int encryptionCalculate(int dataA, int dataB)
//{
//    while (dataB)
//    {
//        int t = dataA;
//        dataA = dataA ^ dataB;
//        dataB = ((unsigned int)(t & dataB) << 1);
//    }
//    return dataA;
//}
//
////LCR 188. 买卖芯片的最佳时机
//
//int bestTiming(int* prices, int pricesSize)
//{
//    if (NULL == prices || 1 >= pricesSize)
//        return 0;
//    int max = 0;
//    int keep = prices[pricesSize - 1];
//    for (int i = pricesSize - 1; i > 0; i--)
//    {
//        if (keep >= prices[i - 1])
//            max = max > keep - prices[i - 1] ? max : keep - prices[i - 1];
//        else
//            keep = prices[i - 1];
//    }
//    return max;
//}
//
////1725. 可以形成最大正方形的矩形数目
//
//int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize)
//{
//    int row = rectanglesSize;
//    int max = 0;
//    int cnt = 1;
//    for (int i = 0; i < row; i++)
//    {
//        int t = fmin(rectangles[i][0], rectangles[i][1]);
//        if (max == t)
//            cnt++;
//        else if (max < t)
//        {
//            max = t;
//            cnt = 1;
//        }
//    }
//    return cnt;
//}
//
////1796. 字符串中第二大的数字
//
//int secondHighest(char* s)
//{
//    int first = -1;
//    int second = -1;
//    for (int i = 0; s[i]; i++)
//    {
//        if (isdigit(s[i]))
//        {
//            int num = s[i] - '0';
//            if (num > first)
//            {
//                second = first;
//                first = num;
//            }
//            else if (num < first && num > second)
//                second = num;
//        }
//    }
//    return second;
//}
//
