////31. 下一个排列
//
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//        swap(&nums[left++], &nums[right--]);
//}
//void nextPermutation(int* nums, int numsSize)
//{
//    int i = numsSize - 2;
//    while (i >= 0 && nums[i] >= nums[i + 1])
//        i--;
//    if (i >= 0)
//    {
//        int j = numsSize - 1;
//        while (nums[j] <= nums[i])
//            j--;
//        swap(&nums[i], &nums[j]);
//    }
//    reverse(nums, i + 1, numsSize - 1);
//}
//
////3566. 等积子集的划分方案    
//
//bool checkEqualPartitions(int* nums, int numsSize, long long target)
//{
//    bool dfs(int i, long long a, long long b)
//    {
//        if (a > target || b > target)
//            return false;
//
//        if (i < 0)
//            return a == target && b == target;
//
//        return dfs(i - 1, a * nums[i], b) | dfs(i - 1, a, b * nums[i]);
//    }
//    return dfs(numsSize - 1, 1ll, 1ll);
//}
//
////1352. 最后 K 个数的乘积
//
//typedef struct
//{
//    int* pre;
//    int preSize;
//} ProductOfNumbers;
//
//
//ProductOfNumbers* productOfNumbersCreate()
//{
//    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
//    obj->pre = (int*)malloc(sizeof(int) * 40001);
//    obj->preSize = 0;
//    obj->pre[0] = 1;
//    return obj;
//}
//
//void productOfNumbersAdd(ProductOfNumbers* obj, int num)
//{
//    if (!num)
//        obj->preSize = 0;
//    else
//    {
//        obj->pre[++obj->preSize] = num;
//        obj->pre[obj->preSize] *= obj->pre[obj->preSize - 1];
//    }
//}
//
//int productOfNumbersGetProduct(ProductOfNumbers* obj, int k)
//{
//    int len = obj->preSize;
//    if (len < k)
//        return 0;
//    int r = obj->pre[len];
//    int l = obj->pre[len - k];
//    return r / l;
//}
//
//void productOfNumbersFree(ProductOfNumbers* obj)
//{
//    free(obj->pre);
//    free(obj);
//}
//
///**
// * Your ProductOfNumbers struct will be instantiated and called as such:
// * ProductOfNumbers* obj = productOfNumbersCreate();
// * productOfNumbersAdd(obj, num);
//
// * int param_2 = productOfNumbersGetProduct(obj, k);
//
// * productOfNumbersFree(obj);
//*/
//
////LCR 160. 数据流中的中位数
//
//typedef struct
//{
//    int* heapL; // MAXHEAP
//    int lSize;
//    int* heapR; // MINHEAP
//    int rSize;
//} MedianFinder;
//
//void upL(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void upR(int* heap, int i)
//{
//    int x = heap[i];
//    for (int j = (i - 1) / 2; j >= 0; j = (j - 1) / 2)
//    {
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//
//        if (j == 0)
//            break;
//    }
//    heap[i] = x;
//}
//
//void downL(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] > heap[j])
//            j++;
//
//        if (heap[j] <= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void downR(int* heap, int i, int n)
//{
//    int x = heap[i];
//    for (int j = 2 * i + 1; j < n; j = 2 * j + 1)
//    {
//        if (j < n - 1 && heap[j + 1] < heap[j])
//            j++;
//
//        if (heap[j] >= x)
//            break;
//
//        heap[i] = heap[j];
//        i = j;
//    }
//    heap[i] = x;
//}
//
//void emplaceL(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    upL(heap, (*n)++);
//}
//void emplaceR(int* heap, int* n, int x)
//{
//    heap[*n] = x;
//    upR(heap, (*n)++);
//}
//void popL(int* heap, int n, int x)
//{
//    heap[0] = x;
//    downL(heap, 0, n);
//}
//void popR(int* heap, int n, int x)
//{
//    heap[0] = x;
//    downR(heap, 0, n);
//}
///** initialize your data structure here. */
//
//MedianFinder* medianFinderCreate()
//{
//    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
//    obj->heapL = (int*)malloc(sizeof(int) * 25000);
//    obj->lSize = 0;
//    obj->heapR = (int*)malloc(sizeof(int) * 25000);
//    obj->rSize = 0;
//    return obj;
//}
//
//void medianFinderAddNum(MedianFinder* obj, int num)
//{
//    int x = num;
//    if (obj->lSize == obj->rSize)
//    {
//        if (obj->rSize && num > obj->heapR[0])
//        {
//            x = obj->heapR[0];
//            popR(obj->heapR, obj->rSize, num);
//        }
//        emplaceL(obj->heapL, &obj->lSize, x);
//    }
//    else
//    {
//        if (num < obj->heapL[0])
//        {
//            x = obj->heapL[0];
//            popL(obj->heapL, obj->lSize, num);
//        }
//        emplaceR(obj->heapR, &obj->rSize, x);
//    }
//}
//
//double medianFinderFindMedian(MedianFinder* obj)
//{
//    //printf("%d %d %d %d\n", obj -> lSize, obj -> rSize, obj -> heapL[0], obj -> heapR[0]);
//    if (obj->lSize == obj->rSize)
//        return 1.0 * (obj->heapL[0] + obj->heapR[0]) / 2.0;
//    else
//        return obj->heapL[0];
//}
//
//void medianFinderFree(MedianFinder* obj)
//{
//    free(obj->heapL);
//    free(obj->heapR);
//    free(obj);
//}
//
///**
// * Your MedianFinder struct will be instantiated and called as such:
// * MedianFinder* obj = medianFinderCreate();
// * medianFinderAddNum(obj, num);
//
// * double param_2 = medianFinderFindMedian(obj);
//
// * medianFinderFree(obj);
//*/
//
