////3502. 到达每个位置的最小费用
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minCosts(int* cost, int costSize, int* returnSize)
//{
//    int* ret = (int*)malloc(sizeof(int) * costSize);
//    int min = 0x7fffffff;
//    for (int i = 0; i < costSize; i++)
//    {
//        if (min > cost[i])
//        {
//            ret[i] = cost[i];
//            min = cost[i];
//        }
//        else
//            ret[i] = min;
//    }
//    *returnSize = costSize;
//    return ret;
//}
//
////3516. 找到最近的人
//
//int findClosest(int x, int y, int z)
//{
//    int a = abs(x - z);
//    int b = abs(y - z);
//    if (a == b)
//        return 0;
//    else if (a > b)
//        return 2;
//    else
//        return 1;
//}
//
////3226. 使两个整数相等的位更改次数
//
//int minChanges(int n, int k)
//{
//    //printf("%x", n|k);
//    if ((n | k) != n)
//        return -1;
//    int t = n ^ k;
//    int num = 0;
//    while (t)
//    {
//        t &= (t - 1);
//        num++;
//    }
//    return num;
//}
//
////3477. 将水果放入篮子 II
//
//int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize)
//{
//    bool valid[basketsSize];
//    memset(valid, 0, sizeof(bool) * basketsSize);
//    int ans = fruitsSize;
//    for (int i = 0; i < fruitsSize; i++)
//    {
//        for (int j = 0; j < basketsSize; j++)
//        {
//            if (valid[j])
//                continue;
//            if (baskets[j] >= fruits[i])
//            {
//                //printf("%d %d\n", fruits[i], baskets[j]);
//                ans--;
//                valid[j] = true;
//                break;
//            }
//        }
//    }
//    return ans;
//}
//
////1356. 根据数字二进制下 1 的数目排序
//
//// 计算一个整数二进制表示中 1 的个数 
//int getDigit(int n) {
//    int num = 0;
//    while (n) {
//        num++;
//        n &= n - 1;
//    }
//    return num;
//}
//
//// 定义一个结构体来存储整数及其二进制 1 的个数 
//typedef struct {
//    int value;
//    int bitCount;
//} Number;
//
//// 比较函数，先按二进制 1 的个数排序，若相同则按整数本身大小排序 
//int cmp(const void* e1, const void* e2) {
//    Number* num1 = (Number*)e1;
//    Number* num2 = (Number*)e2;
//    if (num1->bitCount != num2->bitCount) {
//        return num1->bitCount - num2->bitCount;
//    }
//    return num1->value - num2->value;
//}
//
//// 主函数，对数组进行排序 
//int* sortByBits(int* arr, int arrSize, int* returnSize) {
//    // 分配存储结构体的内存 
//    Number* numbers = (Number*)malloc(sizeof(Number) * arrSize);
//    if (numbers == NULL) {
//        return NULL;
//    }
//
//    // 填充结构体数组 
//    for (int i = 0; i < arrSize; i++) {
//        numbers[i].value = arr[i];
//        numbers[i].bitCount = getDigit(arr[i]);
//    }
//
//    // 使用 qsort 对结构体数组进行排序 
//    qsort(numbers, arrSize, sizeof(Number), cmp);
//
//    // 分配结果数组的内存 
//    int* ans = (int*)malloc(sizeof(int) * arrSize);
//    if (ans == NULL) {
//        free(numbers);
//        return NULL;
//    }
//
//    // 将排序好的结果复制到结果数组中 
//    for (int i = 0; i < arrSize; i++) {
//        ans[i] = numbers[i].value;
//    }
//
//    // 释放结构体数组的内存 
//    free(numbers);
//
//    // 设置返回数组的大小 
//    *returnSize = arrSize;
//    return ans;
//}
//
