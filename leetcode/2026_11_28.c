//// 1046. 最后一块石头的重量
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
//void push(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    up(heap, (*n)++);
//}
//int pop(int* heap, int* n)
//{
//    int x = heap[0];
//    heap[0] = heap[--(*n)];
//    down(heap, 0, *n);
//    return x;
//}
//void buildMaxHeap(int* nums, int n)
//{
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(nums, i, n);
//    }
//}
//int lastStoneWeight(int* stones, int stonesSize)
//{
//    buildMaxHeap(stones, stonesSize);
//    while (stonesSize > 1)
//    {
//        int x1 = pop(stones, &stonesSize);
//        int x2 = pop(stones, &stonesSize);
//        push(stones, &stonesSize, x1 - x2);
//    }
//    return stones[0];
//}
//
