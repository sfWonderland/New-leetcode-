////3000. 对角线最长的矩形的面积
//
//int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize)
//{
//    int n = dimensionsSize, diagonal = 0, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int tmp = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
//        if (tmp > diagonal)
//        {
//            diagonal = tmp;
//            ans = dimensions[i][0] * dimensions[i][1];
//        }
//        else if (tmp == diagonal)
//            ans = fmax(ans, dimensions[i][0] * dimensions[i][1]);
//    }
//    return ans;
//}
//
////LCR 184. 设计自助结算系统
//
//typedef struct
//{
//    int* queue;
//    int b1;
//    int t1;
//    int* max;
//    int b2;
//    int t2;
//} Checkout;
//
//
//Checkout* checkoutCreate()
//{
//    Checkout* obj = (Checkout*)malloc(sizeof(Checkout));
//    obj->queue = (int*)malloc(sizeof(int) * 10000);
//    obj->b1 = 0, obj->t1 = -1;
//    obj->max = (int*)malloc(sizeof(int) * 10000);
//    obj->b2 = 0, obj->t2 = -1;
//    return obj;
//}
//
//int checkoutGet_max(Checkout* obj)
//{
//    return obj->t2 >= obj->b2 ? obj->max[obj->b2] : -1;
//}
//
//void checkoutAdd(Checkout* obj, int value)
//{
//    obj->queue[++(obj->t1)] = value;
//    while (obj->t2 >= obj->b2 && obj->max[obj->t2] < value)
//        (obj->t2)--;
//    obj->max[++(obj->t2)] = value;
//}
//
//int checkoutRemove(Checkout* obj)
//{
//    if (obj->t1 >= obj->b1)
//    {
//        int x = obj->queue[(obj->b1)++];
//        if (obj->max[obj->b2] == x)
//            (obj->b2)++;
//        return x;
//    }
//    else
//        return -1;
//}
//
//void checkoutFree(Checkout* obj)
//{
//    free(obj->queue);
//    free(obj->max);
//    free(obj);
//}
//
///**
// * Your Checkout struct will be instantiated and called as such:
// * Checkout* obj = checkoutCreate();
// * int param_1 = checkoutGet_max(obj);
//
// * checkoutAdd(obj, value);
//
// * int param_3 = checkoutRemove(obj);
//
// * checkoutFree(obj);
//*/
//
////LCR 146. 螺旋遍历二维数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* spiralArray(int** array, int arraySize, int* arrayColSize, int* returnSize)
//{
//    *returnSize = 0;
//    if (arraySize == 0)
//        return NULL;
//    int m = arraySize, n = arrayColSize[0];
//    int* ans = (int*)malloc(sizeof(int) * m * n);
//    int l = 0, r = n - 1, t = 0, b = m - 1;
//    while (1)
//    {
//        for (int i = l; i <= r; i++) //从左到右
//        {
//            ans[(*returnSize)++] = array[t][i];
//        }
//        if (++t > b) break;
//        for (int i = t; i <= b; i++) //从上到下
//        {
//            ans[(*returnSize)++] = array[i][r];
//        }
//        if (--r < l) break;
//        for (int i = r; i >= l; i--) //从右到左
//        {
//            ans[(*returnSize)++] = array[b][i];
//        }
//        if (--b < t) break;
//        for (int i = b; i >= t; i--) //从下到上
//        {
//            ans[(*returnSize)++] = array[i][l];
//        }
//        if (++l > r) break;
//    }
//    return ans;
//}
//
////LCR 148. 验证图书取出顺序
//
//bool validateBookSequences(int* putIn, int putInSize, int* takeOut, int takeOutSize)
//{
//    int n = putInSize;
//    int* st = (int*)malloc(sizeof(int) * n);
//    int top = -1;
//    int pop = 0;
//    for (int i = 0; i < n; i++)
//    {
//        st[++top] = putIn[i];
//        while (top >= 0 && takeOut[pop] == st[top])
//        {
//            pop++;
//            top--;
//            continue;
//        }
//    }
//    return top < 0;
//}
//
