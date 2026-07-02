//// 3974. K 个元素的最大总和    
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//long long maxSum(int* nums, int numsSize, int k, int mul)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    long long ans = 0;
//    for (int i = 0; i < k; i++)
//    {
//        ans += 1ll * fmax(mul, 1) * nums[i];
//        mul--;
//    }
//    return ans;
//}
//
//// 3975. 筛选忙碌区间
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    int* a = *(int**)e1;
//    int* b = *(int**)e2;
//    return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
//}
//int** filterOccupiedIntervals(int** occupiedIntervals, int occupiedIntervalsSize, int* occupiedIntervalsColSize, int freeStart, int freeEnd, int* returnSize, int** returnColumnSizes)
//{
//    qsort(occupiedIntervals, occupiedIntervalsSize, sizeof(int*), cmp);
//    int len = 1;
//    for (int i = 1; i < occupiedIntervalsSize; i++)
//    {
//        int left = occupiedIntervals[i][0], right = occupiedIntervals[i][1];
//        if (left <= occupiedIntervals[len - 1][1] + 1)
//        {
//            occupiedIntervals[len - 1][1] = fmax(occupiedIntervals[len - 1][1], right);
//        }
//        else
//        {
//            occupiedIntervals[len][0] = left;
//            occupiedIntervals[len++][1] = right;
//        }
//    }
//    int** ans = (int**)malloc(sizeof(int*) * (len + 1));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (len + 1));
//    *returnSize = 0;
//    for (int i = 0; i < len; i++)
//    {
//        int left = occupiedIntervals[i][0], right = occupiedIntervals[i][1];
//        if (right < freeStart || left > freeEnd)
//        {
//            ans[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
//            ans[*returnSize][0] = left;
//            ans[*returnSize][1] = right;
//            (*returnColumnSizes)[(*returnSize)++] = 2;
//        }
//        else
//        {
//            if (left < freeStart)
//            {
//                ans[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
//                ans[*returnSize][0] = left;
//                ans[*returnSize][1] = freeStart - 1;
//                (*returnColumnSizes)[(*returnSize)++] = 2;
//            }
//            if (right > freeEnd)
//            {
//                ans[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
//                ans[*returnSize][0] = freeEnd + 1;
//                ans[*returnSize][1] = right;
//                (*returnColumnSizes)[(*returnSize)++] = 2;
//            }
//            else
//                freeStart = fmin(right + 1, freeEnd);
//        }
//    }
//    return ans;
//}
//
