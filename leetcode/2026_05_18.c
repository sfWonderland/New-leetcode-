//// 面试题 16.13. 平分正方形
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//double* cutSquares(int* square1, int square1Size, int* square2, int square2Size, int* returnSize)
//{
//    double* ans = (double*)malloc(sizeof(double) * 4);
//    *returnSize = 4;
//
//    double d1 = square1[2];
//    double x1 = square1[0] + d1 / 2.0;
//    double y1 = square1[1] + d1 / 2.0;
//
//    double d2 = square2[2];
//    double x2 = square2[0] + d2 / 2.0;
//    double y2 = square2[1] + d2 / 2.0;
//
//    if (x1 == x2)
//    {
//        ans[0] = x1;
//        ans[1] = fmin(square1[1], square2[1]);
//        ans[2] = x1;
//        ans[3] = fmax(square1[1] + d1, square2[1] + d2);
//        return ans;
//    }
//    double k = (y2 - y1) / (x2 - x1);
//    double b = y1 - k * x1;
//    if (fabs(k) > 1)
//    {
//        // 与上下相交
//        ans[1] = fmin(square1[1], square2[1]);
//        ans[0] = (ans[1] - b) / k;
//        ans[3] = fmax(square1[1] + d1, square2[1] + d2);
//        ans[2] = (ans[3] - b) / k;
//    }
//    else
//    {
//        //与左右相交
//        ans[0] = fmin(square1[0], square2[0]);
//        ans[1] = ans[0] * k + b;
//        ans[2] = fmax(square1[0] + d1, square2[0] + d2);
//        ans[3] = ans[2] * k + b;
//    }
//    if (ans[0] > ans[2])
//    {
//        double tmp1 = ans[0], tmp2 = ans[1];
//        ans[0] = ans[2], ans[1] = ans[3];
//        ans[2] = tmp1, ans[3] = tmp2;
//    }
//    return ans;
//}
//
//// 面试题 16.16. 部分排序    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* subSort(int* array, int arraySize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1, ans[1] = -1;
//    *returnSize = 2;
//    if (arraySize == 0)
//        return ans;
//    int max = array[0], last = -1;
//    for (int i = 1; i < arraySize; i++)
//    {
//        if (array[i] < max)
//            last = i;
//        else
//            max = array[i];
//    }
//    int min = array[arraySize - 1], first = -1;
//    for (int i = arraySize - 2; i >= 0; i--)
//    {
//        if (array[i] > min)
//            first = i;
//        else
//            min = array[i];
//    }
//    ans[0] = first, ans[1] = last;
//    return ans;
//}
//
//// 面试题 16.17. 连续数列
//
//int maxSubArray(int* nums, int numsSize)
//{
//    int pre = 0, max_ans = nums[0];
//    for (int i = 0; i < numsSize; i++)
//    {
//        pre = fmax(pre + nums[i], nums[i]);
//        max_ans = fmax(max_ans, pre);
//    }
//    return max_ans;
//}
//
//// 面试题 17.01. 不用加号的加法
//
//int add(int a, int b)
//{
//    while (b != 0)
//    {
//        unsigned int carry = (unsigned int)(a & b) << 1;
//        a = a ^ b;
//        b = carry;
//    }
//    return a;
//}
//
