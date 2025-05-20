////LCR 191. 按规则计算统计结果
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* statisticalResult(int* arrayA, int arrayASize, int* returnSize)
//{
//    if (arrayASize == 0)
//    {
//        *returnSize = 0;
//        return arrayA;
//    }
//    int* arrayB = (int*)malloc(sizeof(int) * arrayASize);
//    arrayB[0] = 1;
//    for (int i = 0; i < arrayASize - 1; i++)
//    {
//        arrayB[i + 1] = arrayB[i] * arrayA[i];
//    }
//    int tmp = 1;
//    for (int i = arrayASize - 1; i > 0; i--)
//    {
//        tmp *= arrayA[i];
//        arrayB[i - 1] *= tmp;
//    }
//    *returnSize = arrayASize;
//    return arrayB;
//}
//
////3355. 零数组变换 I
//
//bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
//{
//    int hash[numsSize + 1];
//    for (int i = 0; i < numsSize + 1; i++)
//    {
//        hash[i] = 0;
//    }
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int l = queries[i][0], r = queries[i][1];
//        hash[l]++; hash[r + 1]--;
//    }
//    for (int i = 1; i < numsSize + 1; i++)
//    {
//        hash[i] = hash[i - 1] + hash[i];
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (hash[i] < nums[i])
//            return false;
//    }
//
//    return true;
//}
//
////34. 在排序数组中查找元素的第一个和最后一个位置
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int BinarySearch(int* nums, int left, int right, int x)
//{
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] == x)
//            return mid;
//        else if (nums[mid] > x)
//            right = mid - 1;
//        else
//            left = left + 1;
//    }
//    return -1;
//}
//int* searchRange(int* nums, int numsSize, int target, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    *returnSize = 2;
//
//    int point = BinarySearch(nums, 0, numsSize - 1, target);
//    if (point == -1)
//        return ans;
//
//    ans[1] = point;
//    int l = BinarySearch(nums, ans[1] + 1, numsSize - 1, target);
//    while (l > ans[1])
//    {
//        ans[1] = l;
//        l = BinarySearch(nums, ans[1] + 1, numsSize - 1, target);
//    }
//
//    ans[0] = point;
//    int r = BinarySearch(nums, 0, ans[0], target);
//    while (r < ans[0])
//    {
//        ans[0] = r;
//        r = BinarySearch(nums, 0, ans[0], target);
//    }
//    return ans;
//}
//
////1283. 使结果不超过阈值的最小除数
//
//bool check(int* nums, int numsSize, int div, int x)
//{
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += (nums[i] + div - 1) / div;
//        if (sum > x)
//            return false;
//    }
//    return true;
//}
//int smallestDivisor(int* nums, int numsSize, int threshold)
//{
//    int left = 0, right = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        right = fmax(nums[i], right);
//    }
//
//    while (left + 1 < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (check(nums, numsSize, mid, threshold))
//            right = mid;
//        else
//            left = mid;
//    }
//    return right;
//}
//
