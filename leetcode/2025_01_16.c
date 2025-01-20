//#define _CRT_SECURE_NO_WARNINGS
//
////3095.或值至少K的最短子数组I
//int minimumSubarrayLength(int* nums, int numsSize, int k)
//{
//    int ret = 51;
//    for (int i = 0; i < numsSize; i++)
//    {
//        int n = 0;
//        for (int j = i; j < numsSize; j++)
//        {
//            n |= nums[j];
//            if (n >= k)
//            {
//                ret = (ret < j - i + 1) ? ret : j - i + 1;
//                break;
//            }
//        }
//    }
//    if (ret != 51)
//        return ret;
//    else
//        return -1;
//}
//
////217.存在重复元素
//
//int cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool containsDuplicate(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, 4, cmp_int);
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] == nums[i + 1])
//            return true;
//    }
//    return false;
//}
//
////219.存在重复元素II
//
//typedef struct val_index
//{
//    int index;
//    int val;
//}node;
//int cmp_int(const void* e1, const void* e2)
//{
//    return ((node*)e1)->val - ((node*)e2)->val;
//}
//
//bool containsNearbyDuplicate(int* nums, int numsSize, int k)
//{
//    node p[numsSize];
//    for (int i = 0; i < numsSize; ++i)
//    {
//        p[i].index = i;
//        p[i].val = nums[i];
//    }
//    qsort(p, numsSize, sizeof(p[0]), cmp_int);
//    for (int i = 0; i < numsSize - 1; ++i)
//    {
//        if (p[i].val == p[i + 1].val && abs(p[i].index - p[i + 1].index) <= k)
//            return true;
//    }
//    return false;
//}