//// 34. 在排序数组中查找元素的第一个和最后一个位置
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int binary_search(int* nums, int n, int x)
//{
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (nums[mid] >= x)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//int* searchRange(int* nums, int numsSize, int target, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    *returnSize = 2;
//    int left = binary_search(nums, numsSize, target);
//    if (left == numsSize || nums[left] != target) return ans;
//    int right = binary_search(nums, numsSize, target + 1) - 1;
//    ans[0] = left; ans[1] = right;
//    return ans;
//}
//
