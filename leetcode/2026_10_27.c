//// 1845. 座位预约管理系统
//
//void up(int* heap, int i)
//{
//    int x = heap[i];
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
//int pop(int* heap, int* n)
//{
//    int x = heap[0];
//    heap[0] = heap[--(*n)];
//    down(heap, 0, *n);
//    return x;
//}
//
//void push(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    up(heap, (*n)++);
//}
//
//typedef struct
//{
//    int* heap;
//    bool* valid;
//    int n;
//} SeatManager;
//
//
//SeatManager* seatManagerCreate(int n)
//{
//    SeatManager* obj = (SeatManager*)malloc(sizeof(SeatManager));
//    obj->heap = (int*)malloc(sizeof(int) * n);
//    obj->valid = (bool*)calloc(sizeof(bool), n);
//    for (int i = 0; i < n; i++)
//    {
//        obj->heap[i] = i + 1;
//    }
//    obj->n = n;
//    return obj;
//}
//
//int seatManagerReserve(SeatManager* obj)
//{
//    int x = pop(obj->heap, &obj->n);
//    obj->valid[x - 1] = true;
//    return x;
//}
//
//void seatManagerUnreserve(SeatManager* obj, int seatNumber)
//{
//    if (!obj->valid[seatNumber - 1]) return;
//    push(obj->heap, &obj->n, seatNumber);
//    obj->valid[seatNumber - 1] = false;
//}
//
//void seatManagerFree(SeatManager* obj)
//{
//    free(obj->heap);
//    free(obj->valid);
//}
//
///**
// * Your SeatManager struct will be instantiated and called as such:
// * SeatManager* obj = seatManagerCreate(n);
// * int param_1 = seatManagerReserve(obj);
//
// * seatManagerUnreserve(obj, seatNumber);
//
// * seatManagerFree(obj);
//*/
//
