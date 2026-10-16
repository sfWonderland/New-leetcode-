//// 2558. 从数量最多的堆取走礼物
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; i > 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j]) j++;
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//long long pickGifts(int* gifts, int giftsSize, int k)
//{
//    int n = giftsSize;
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(gifts, i, n);
//    }
//    while (k--)
//    {
//        gifts[0] = sqrt(gifts[0]);
//        down(gifts, 0, n);
//    }
//    long long ans = 0;
//    for (int i = 0; i < n; i++)
//        ans += gifts[i];
//    return ans;
//}
//
