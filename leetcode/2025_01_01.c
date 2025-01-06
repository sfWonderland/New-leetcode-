#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//35.ËÑË÷²åÈëÎ»ÖÃ

//int searchInsert(int* nums, int numsSize, int target) {
//    int left = 0;
//    int right = numsSize - 1;
//    int ret = -1;
//    if (target < nums[left])
//        ret = 0;
//    if (target > nums[right])
//        ret = numsSize;
//    while ((left <= right) && (ret + 1 == 0))
//    {
//        int mid = (right - left) / 2 + left;
//        if (nums[mid] > target)
//        {
//            if ((mid != 0) && (nums[mid - 1] < target))
//            {
//                ret = mid;
//                break;
//            }
//            right = mid - 1;
//        }
//        else if (nums[mid] < target)
//        {
//            if ((mid != numsSize - 1) && (nums[mid + 1] > target))
//            {
//                ret = mid + 1;
//                break;
//            }
//            left = mid + 1;
//        }
//        else
//        {
//            ret = mid;
//            break;
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    int nums[] = {1, 3, 5, 6};
//    int target = 2;
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    printf("searchInsert = %d\n", searchInsert(nums, numsSize, target));
//    return 0;
//}

//