//// 2336. 无限集中的最小数字
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
//    // i > 0
//    for (int j = (i - 1) / 2; i > 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void down(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j]) j++;
//        if (heap[j] >= x) break;
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void push(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    up(heap, (*n)++);
//}
//
//int pop(int* heap, int* n)
//{
//    int x = heap[0];
//    heap[0] = heap[--(*n)];
//    down(heap, 0, *n);
//    return x;
//}
//
//typedef struct
//{
//    int* heap;
//    bool* exist;
//    int n;
//} SmallestInfiniteSet;
//
//
//SmallestInfiniteSet* smallestInfiniteSetCreate()
//{
//    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
//    obj->heap = (int*)malloc(sizeof(int) * 1000);
//    obj->n = 0;
//    for (int i = 1; i < 1001; i++)
//    {
//        obj->heap[obj->n++] = i;
//    }
//    // 0 exist 1 deleted
//    obj->exist = (bool*)calloc(sizeof(bool), 1000);
//    return obj;
//}
//
//int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj)
//{
//    int x = pop(obj->heap, &obj->n);
//    obj->exist[x - 1] = true;
//    return x;
//}
//
//void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num)
//{
//    if (!obj->exist[num - 1]) return;
//    obj->exist[num - 1] = false;
//    push(obj->heap, &obj->n, num);
//}
//
//void smallestInfiniteSetFree(SmallestInfiniteSet* obj)
//{
//    free(obj->heap);
//    free(obj->exist);
//    free(obj);
//}
//
///**
// * Your SmallestInfiniteSet struct will be instantiated and called as such:
// * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
// * int param_1 = smallestInfiniteSetPopSmallest(obj);
//
// * smallestInfiniteSetAddBack(obj, num);
//
// * smallestInfiniteSetFree(obj);
//*/
//
