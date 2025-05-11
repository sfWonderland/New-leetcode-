////3467. 将数组按照奇偶性转化
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* transformArray(int* nums, int numsSize, int* returnSize)
//{
//    int slow = 0;
//    for (int fast = 0; fast < numsSize; fast++)
//    {
//        if ((nums[fast] & 1) == 0)
//            nums[slow++] = 0;
//    }
//    for (; slow < numsSize; slow++)
//    {
//        nums[slow] = 1;
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////442. 数组中重复的数据
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(int* a, int* b)
//{
//    int tmp = a[0];
//    a[0] = b[0];
//    b[0] = tmp;
//}
//int* findDuplicates(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (nums[nums[i] - 1] != nums[i])
//        {
//            swap(&nums[i], &nums[nums[i] - 1]);
//        }
//    }
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != i + 1)
//            ans[n++] = nums[i];
//    }
//    *returnSize = n;
//    return ans;
//}
//
////448. 找到所有数组中消失的数字
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        while (nums[nums[i] - 1] != nums[i])
//            swap(&nums[i], &nums[nums[i] - 1]);
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != i + 1)
//            ans[n++] = i + 1;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////41. 缺失的第一个正数
//
//int firstMissingPositive(int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] <= 0)
//            nums[i] = numsSize + 1;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        int t = abs(nums[i]);
//        if (t <= numsSize)
//        {
//            nums[t - 1] = -abs(nums[t - 1]);
//        }
//    }
//    int ans = numsSize + 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > 0)
//        {
//            ans = i + 1;
//            break;
//        }
//    }
//    return ans;
//}
//
