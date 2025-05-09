////16. 最接近的三数之和
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int threeSumClosest(int* nums, int numsSize, int target)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int n = numsSize, ans = 100000;
//    for (int i = 0; i < n - 2; i++)
//    {
//        int j = i + 1, k = n - 1;
//        int t = nums[i] + nums[j] + nums[k];
//        while (j < k)
//        {
//            if (t > target)
//                k--;
//            else if (t < target)
//                j++;
//            else
//                return t;
//
//            ans = abs(t - target) < abs(ans - target) ? t : ans;
//            t = nums[i] + nums[j] + nums[k];
//        }
//    }
//    return ans;
//}
//
////2918. 数组的最小相等和
//
//long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
//    for (int i = 0; i < nums1Size; i++)
//    {
//        sum1 += nums1[i];
//        if (nums1[i] == 0)
//        {
//            zero1++;
//            sum1++;
//        }
//    }
//    for (int i = 0; i < nums2Size; i++)
//    {
//        sum2 += nums2[i];
//        if (nums2[i] == 0)
//        {
//            zero2++;
//            sum2++;
//        }
//    }
//
//    if ((zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2))
//        return -1;
//
//    return sum1 > sum2 ? sum1 : sum2;
//}
//
////18. 四数之和
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
//{
//    int n = numsSize;
//    qsort(nums, n, sizeof(int), cmp);
//    int** ans = (int**)malloc(n * n * sizeof(int*));
//    *returnColumnSizes = (int*)malloc(n * n * sizeof(int));
//    int num = 0;
//    for (int i = 0; i < n - 3; i++)
//    {
//        int x = nums[i];
//        if (i > 0 && x == nums[i - 1]) continue;
//        for (int j = i + 1; j < n - 2; j++)
//        {
//            int y = nums[j];
//            if (j > i + 1 && y == nums[j - 1]) continue;
//            if ((long long)x + y + nums[n - 2] + nums[n - 1] < target) continue;
//            if ((long long)x + y + nums[i + 2] + nums[i + 3] > target) break;
//            int k = j + 1, l = n - 1;
//            while (k < l)
//            {
//                long long t = (long long)x + y + nums[k] + nums[l];
//                if (t > target)
//                    l--;
//                else if (t < target)
//                    k++;
//                else
//                {
//                    ans[num] = (int*)malloc(sizeof(int) * 4);
//                    ans[num][0] = x; ans[num][1] = y;
//                    ans[num][2] = nums[k]; ans[num][3] = nums[l];
//                    (*returnColumnSizes)[num++] = 4;
//                    for (k++; k < l && nums[k] == nums[k - 1]; k++);
//                    for (l--; k < l && nums[l] == nums[l + 1]; l--);
//                }
//            }
//        }
//    }
//    *returnSize = num;
//    return ans;
//}
//
////611. 有效三角形的个数
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int triangleNumber(int* nums, int numsSize)
//{
//    int ans = 0, n = numsSize;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    for (int k = n - 1; k > 1; k--)
//    {
//        int c = nums[k];
//        if (nums[0] + nums[1] > c)
//        {
//            ans += (k + 1) * k * (k - 1) / 6;
//            break;
//        }
//
//        if (nums[k - 2] + nums[k - 1] <= nums[k]) continue;
//        int i = 0, j = k - 1;
//        while (i < j)
//        {
//            if (nums[i] + nums[j] > c)
//            {
//                ans += j - i;
//                j--;
//            }
//            else
//                i++;
//        }
//    }
//    return ans;
//}
//
