////498. 对角线遍历
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize)
//{
//    int m = matSize, n = matColSize[0];
//    int* ans = (int*)malloc(sizeof(int) * m * n);
//    int idx = 0;
//    for (int i = 0; i < m + n - 1; i++)
//    {
//        int min_j = fmax(i - m + 1, 0);
//        int max_j = fmin(i, n - 1);
//        if (i % 2)
//            for (int j = max_j; j >= min_j; j--)
//            {
//                ans[idx++] = mat[i - j][j];
//            }
//        else
//            for (int j = min_j; j <= max_j; j++)
//            {
//                ans[idx++] = mat[i - j][j];
//            }
//    }
//    *returnSize = m * n;
//    return ans;
//}
//
////LCR 125. 图书整理 II
//
//typedef struct
//{
//    int* queue;
//    int bottom;
//    int top;
//} CQueue;
//
//
//CQueue* cQueueCreate()
//{
//    CQueue* obj = (CQueue*)malloc(sizeof(CQueue));
//    obj->queue = (int*)malloc(sizeof(int) * 10000);
//    obj->bottom = 0;
//    obj->top = -1;
//    return obj;
//}
//
//void cQueueAppendTail(CQueue* obj, int value)
//{
//    obj->queue[++(obj->top)] = value;
//}
//
//int cQueueDeleteHead(CQueue* obj)
//{
//    int l = obj->bottom, r = obj->top;
//    if (l > r) return -1;
//    return obj->queue[(obj->bottom)++];
//}
//
//void cQueueFree(CQueue* obj)
//{
//    free(obj->queue);
//    free(obj);
//}
//
///**
// * Your CQueue struct will be instantiated and called as such:
// * CQueue* obj = cQueueCreate();
// * cQueueAppendTail(obj, value);
//
// * int param_2 = cQueueDeleteHead(obj);
//
// * cQueueFree(obj);
//*/
//
////LCR 147. 最小栈
//
//typedef struct
//{
//    int* stack;
//    int top1;
//    int* min;
//    int top2;
//} MinStack;
//
///** initialize your data structure here. */
//
//MinStack* minStackCreate()
//{
//    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
//    obj->stack = (int*)malloc(sizeof(int) * 30000);
//    obj->top1 = -1;
//    obj->min = (int*)malloc(sizeof(int) * 30000);
//    obj->top2 = -1;
//    return obj;
//}
//
//void minStackPush(MinStack* obj, int x)
//{
//    obj->stack[++(obj->top1)] = x;
//    if (obj->top2 < 0 || obj->min[obj->top2] >= x)
//        obj->min[++(obj->top2)] = x;
//}
//
//void minStackPop(MinStack* obj)
//{
//    int x = obj->stack[obj->top1];
//    if (x == obj->min[obj->top2])
//        (obj->top2)--;
//    (obj->top1)--;
//}
//
//int minStackTop(MinStack* obj)
//{
//    return obj->stack[obj->top1];
//}
//
//int minStackGetMin(MinStack* obj)
//{
//    return obj->min[obj->top2];
//}
//
//void minStackFree(MinStack* obj)
//{
//    free(obj->stack);
//    free(obj->min);
//    free(obj);
//}
//
///**
// * Your MinStack struct will be instantiated and called as such:
// * MinStack* obj = minStackCreate();
// * minStackPush(obj, x);
//
// * minStackPop(obj);
//
// * int param_3 = minStackTop(obj);
//
// * int param_4 = minStackGetMin(obj);
//
// * minStackFree(obj);
//*/
//
////LCR 183. 望远镜中最高的海拔
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* maxAltitude(int* heights, int heightsSize, int limit, int* returnSize)
//{
//    *returnSize = 0;
//    if (heightsSize == 0)
//        return NULL;
//    int n = heightsSize;
//    int* ans = (int*)malloc(sizeof(int) * (n - limit + 1));
//    int* queue = (int*)malloc(sizeof(int) * n);
//    int bottom = 0, top = -1;
//    for (int i = 0; i < n; i++)
//    {
//        while (top >= bottom && heights[queue[top]] <= heights[i])
//            top--;
//
//        queue[++top] = i;
//        if (i - queue[bottom] >= limit)
//            bottom++;
//        if (i >= limit - 1)
//            ans[i - limit + 1] = heights[queue[bottom]];
//    }
//    *returnSize = n - limit + 1;
//    return ans;
//}
//
