////LCR 168. 丑数
//
//int nthUglyNumber(int n)
//{
//    int ugly[n];
//    ugly[0] = 1;
//    int p2 = 0;
//    int p3 = 0;
//    int p5 = 0;
//    for (int i = 1; i < n; i++)
//    {
//        int num2 = ugly[p2] * 2;
//        int num3 = ugly[p3] * 3;
//        int num5 = ugly[p5] * 5;
//        ugly[i] = fmin(fmin(num2, num3), num5);
//        if (ugly[i] == num2) p2++;
//        if (ugly[i] == num3) p3++;
//        if (ugly[i] == num5) p5++;
//    }
//    return ugly[n - 1];
//}
//
////LCR 163. 找到第 k 位数字
//
//int get_digit(int n, int times)
//{
//    while (times)
//    {
//        times--;
//        n /= 10;
//    }
//    return n % 10;
//}
//int findKthNumber(int k)
//{
//    if (k < 10)
//        return k;
//    int digit = 1;
//    int sum = 9;
//    int initial = 1;
//    if (k > 788888889)
//    {
//        digit = 9;
//        sum = 788888889;
//        initial = 100000000;
//    }
//    else
//    {
//        while (sum < k)
//        {
//            digit++;
//            initial *= 10;
//            sum = (sum + initial) * 10 - 1;
//        }
//        sum = sum / 10 - initial + 1;
//    }
//    int n = (k - sum) / digit + initial;
//    //printf("%d %d %d %d", digit, sum, initial, n);
//    if (0 == (k - sum) % digit)
//        return (n - 1) % 10;
//    int times = digit - (k - sum) % digit;
//    return get_digit(n, times);
//}
//
////2600. K 件物品的最大和
//
//int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
//{
//    if (numOnes > k)
//        return k;
//    else if (numOnes + numZeros > k)
//        return numOnes;
//    else
//        return 2 * numOnes + numZeros - k;
//}
//
////LCR 180. 文件组合
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** fileCombination(int target, int* returnSize, int** returnColumnSizes)
//{
//    int** ret = (int**)malloc(sizeof(int*) * target);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * target);
//    int num = 0;
//    for (int l = 1, r = 2; l < r;)
//    {
//        int sum = (l + r) * (r - l + 1) / 2;
//        if (sum == target)
//        {
//            ret[num] = (int*)malloc(sizeof(int) * (r - l + 1));
//            for (int i = 0; i <= r - l; i++)
//                ret[num][i] = i + l;
//            (*returnColumnSizes)[num++] = r - l + 1;
//            l++;
//        }
//        else if (sum < target)
//            r++;
//        else
//            l++;
//    }
//    *returnSize = num;
//    return ret;
//}
//