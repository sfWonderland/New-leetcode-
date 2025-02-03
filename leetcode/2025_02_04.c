//#define _CRT_SECURE_NO_WARNINGS
//
////905.按奇偶排序数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = numsSize;
//    int left = 0;
//    int right = numsSize - 1;
//    while (left < numsSize && right >= 0 && left < right)
//    {
//        while (left < numsSize && 0 == nums[left] % 2)
//            left++;
//        if (left >= numsSize)
//            break;
//
//        while (right >= 0 && nums[right] % 2)
//            right--;
//        if (right < 0)
//            break;
//
//        if (left >= right)
//            break;
//
//        //printf("left = %d, right = %d\n", left, right);
//
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//    //printf("numsSize = %d, *returnSize = %d\n", numsSize, *returnSize);
//    return nums;
//}
//
////922.按奇偶排序数组II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* sortArrayByParityII(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = numsSize;
//    int left = 0;
//    int right = 1;
//    while (left < numsSize && right < numsSize)
//    {
//        while (left < numsSize && 0 == nums[left] % 2)
//            left += 2;
//        if (left >= numsSize)
//            break;
//
//        while (right < numsSize && nums[right] % 2)
//            right += 2;
//        if (right >= numsSize)
//            break;
//
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//    }
//    //printf("numsSize = %d, *returnSize = %d\n", numsSize, *returnSize);
//    return nums;
//}
//
////2164.对奇偶下标分别排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
//int cmp1(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int* sortEvenOdd(int* nums, int numsSize, int* returnSize)
//{
//    *returnSize = numsSize;
//    int copy1[numsSize];
//    int copy2[numsSize];
//    int j1 = 0;
//    int j2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i % 2)
//            copy2[j1++] = nums[i];
//        else
//            copy1[j2++] = nums[i];
//    }
//
//    qsort(copy1, j2, sizeof(int), cmp1);
//    qsort(copy2, j1, sizeof(int), cmp2);
//    j1 = 0;
//    j2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i % 2)
//            nums[i] = copy2[j1++];
//        else
//            nums[i] = copy1[j2++];
//    }
//
//    return nums;
//}