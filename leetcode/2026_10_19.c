//// 2530. 执行 K 次操作后的最大分数
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
//
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = i * 2 + 1; j < n; j = j * 2 + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j]) j++;
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//long long maxKelements(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(nums, i, n);
//    }
//    long long ans = 0;
//    while (k--)
//    {
//        ans += nums[0];
//        nums[0] = (nums[0] + 2) / 3;
//        down(nums, 0, n);
//    }
//    return ans;
//}
//
