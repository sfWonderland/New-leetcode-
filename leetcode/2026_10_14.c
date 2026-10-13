//// 1046. 最后一块石头的重量
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//        if (j == 0) break;
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
//void buildHeap(int* nums, int n)
//{
//    for (int i = n / 2; i >= 0; i--)
//    {
//        down(nums, i, n);
//    }
//}
//int pop(int* heap, int* n)
//{
//    int x = heap[0];
//    heap[0] = heap[--(*n)];
//    down(heap, 0, *n);
//    return x;
//}
//void push(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    up(heap, (*n)++);
//}
//int lastStoneWeight(int* stones, int stonesSize)
//{
//    buildHeap(stones, stonesSize);
//    while (stonesSize > 1)
//    {
//        int x = pop(stones, &stonesSize);
//        int y = pop(stones, &stonesSize);
//        push(stones, &stonesSize, x - y);
//    }
//    return stones[0];
//}
//
