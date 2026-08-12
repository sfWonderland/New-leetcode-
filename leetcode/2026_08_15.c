//// 1670. 设计前中后队列
//
//typedef struct
//{
//    int* leftQ;
//    int* rightQ;
//    int frontL, frontR, rearL, rearR;
//} FrontMiddleBackQueue;
//
//// 辅助函数：计算队列大小
//int getSize(int rear, int front)
//{
//    return (rear - front + 500) % 500;
//}
//
//void pushL(int* queue, int* front, int val)
//{
//    *front = (*front - 1 + 500) % 500;
//    queue[*front] = val;
//}
//
//void pushR(int* queue, int* rear, int val)
//{
//    queue[*rear] = val;
//    *rear = (*rear + 1) % 500;
//}
//int popL(int* queue, int* front)
//{
//    int val = queue[*front];
//    *front = (*front + 1) % 500;
//    return val;
//}
//int popR(int* queue, int* rear)
//{
//    *rear = (*rear - 1 + 500) % 500;
//    return queue[*rear];
//}
//
//FrontMiddleBackQueue* frontMiddleBackQueueCreate()
//{
//    FrontMiddleBackQueue* obj = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
//    obj->leftQ = (int*)malloc(sizeof(int) * 500);
//    obj->rightQ = (int*)malloc(sizeof(int) * 500);
//    obj->frontL = obj->frontR = obj->rearL = obj->rearR = 0;
//    return obj;
//}
//
//void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    // 将元素压入左队列左端点
//    pushL(obj->leftQ, &obj->frontL, val);
//    // 如果左边比右边多2，需要将左队列右端点移到右队列左端点
//    if (sizeL == sizeR + 1)
//    {
//        int x = popR(obj->leftQ, &obj->rearL);
//        pushL(obj->rightQ, &obj->frontR, x);
//    }
//}
//
//void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    // 如果左边比右边多，需要将左队列右端点移到右队列左端点
//    if (sizeL > sizeR)
//    {
//        int x = popR(obj->leftQ, &obj->rearL);
//        pushL(obj->rightQ, &obj->frontR, x);
//    }
//    pushR(obj->leftQ, &obj->rearL, val);
//}
//
//void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    // 将元素压入右队列右端点
//    pushR(obj->rightQ, &obj->rearR, val);
//    // 如果右边比左边多，需要将右队列左端点移到左队列右端点
//    if (sizeL < sizeR + 1)
//    {
//        int x = popL(obj->rightQ, &obj->frontR);
//        pushR(obj->leftQ, &obj->rearL, x);
//    }
//}
//
//int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    if (sizeL == 0 && sizeR == 0) return -1;
//    // 将左队列左端点弹出
//    int val = popL(obj->leftQ, &obj->frontL);
//    // 如果右边比左边多，需要将右队列左端点移到左队列右端点
//    if (sizeL - 1 < sizeR)
//    {
//        int x = popL(obj->rightQ, &obj->frontR);
//        pushR(obj->leftQ, &obj->rearL, x);
//    }
//
//    return val;
//}
//
//int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    if (sizeL == 0 && sizeR == 0) return -1;
//    // 将左队列右端点弹出
//    int res = popR(obj->leftQ, &obj->rearL);
//    // 如果右边比左边多，需要将右队列左端点移到左队列右端点
//    if (sizeL - 1 < sizeR)
//    {
//        int x = popL(obj->rightQ, &obj->frontR);
//        pushR(obj->leftQ, &obj->rearL, x);
//    }
//
//    return res;
//}
//
//int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj)
//{
//    int sizeL = getSize(obj->rearL, obj->frontL);
//    int sizeR = getSize(obj->rearR, obj->frontR);
//    if (sizeL == 0 && sizeR == 0) return -1;
//    int val;
//    if (sizeR == 0)
//        val = popR(obj->leftQ, &obj->rearL);
//    else
//    {
//        val = popR(obj->rightQ, &obj->rearR);
//        if (sizeL == sizeR + 1)
//        {
//            int x = popR(obj->leftQ, &obj->rearL);
//            pushL(obj->rightQ, &obj->frontR, x);
//        }
//    }
//    return val;
//}
//
//void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj)
//{
//    free(obj->leftQ);
//    free(obj->rightQ);
//    free(obj);
//}
//
///**
// * Your FrontMiddleBackQueue struct will be instantiated and called as such:
// * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
// * frontMiddleBackQueuePushFront(obj, val);
//
// * frontMiddleBackQueuePushMiddle(obj, val);
//
// * frontMiddleBackQueuePushBack(obj, val);
//
// * int param_4 = frontMiddleBackQueuePopFront(obj);
//
// * int param_5 = frontMiddleBackQueuePopMiddle(obj);
//
// * int param_6 = frontMiddleBackQueuePopBack(obj);
//
// * frontMiddleBackQueueFree(obj);
//*/
//
