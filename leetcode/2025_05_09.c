////1750. 删除字符串两端相同字符后的最短长度
//
//int minimumLength(char* s)
//{
//    int n = strlen(s);
//    int left = 0, right = n - 1;
//    while (left < right && s[left] == s[right])
//    {
//        char t = s[left];
//        while (left < right && t == s[left])
//            left++;
//        while (left <= right && t == s[right])
//            right--;
//    }
//    return right - left + 1;
//}
//
////1471. 数组中的 k 个最强值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* getStrongest(int* arr, int arrSize, int k, int* returnSize)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int m = (arrSize - 1) / 2;
//    int* ans = (int*)calloc(k, sizeof(int));
//    int n = 0, left = 0, right = arrSize - 1;
//    while (n < k)
//    {
//        int l = abs(arr[left] - arr[m]);
//        int r = abs(arr[right] - arr[m]);
//        if (l > r)
//        {
//            ans[n++] = arr[left];
//            left++;
//        }
//        else
//        {
//            ans[n++] = arr[right];
//            right--;
//        }
//    }
//    *returnSize = k;
//    return ans;
//}
//
////167. 两数之和 II - 输入有序数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
//{
//    int* ans = (int*)calloc(2, sizeof(int));
//    int left = 0, right = numbersSize - 1;
//    *returnSize = 2;
//    while (left < right)
//    {
//        if (numbers[left] + numbers[right] == target)
//        {
//            ans[0] = left + 1; ans[1] = right + 1;
//            return ans;
//        }
//        else if (numbers[left] + numbers[right] > target)
//            right--;
//        else
//            left++;
//    }
//    ans[0] = -1; ans[1] = -1;
//    return ans;
//}
//
////15. 三数之和
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
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = numsSize;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int** ans = (int**)malloc(sizeof(int*) * n * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n * n);
//    int m = 0;
//    for (int i = 0; i < n - 2; i++)
//    {
//        int x = nums[i];
//        if (i > 0 && x == nums[i - 1]) continue;
//        if (x + nums[i + 1] + nums[i + 2] > 0) break;
//        if (x + nums[n - 2] + nums[n - 1] < 0) continue;
//        int left = i + 1, right = n - 1;
//        while (left < right)
//        {
//            int s = x + nums[left] + nums[right];
//            if (s < 0)
//                left++;
//            else if (s > 0)
//                right--;
//            else
//            {
//                ans[m] = (int*)malloc(sizeof(int) * 3);
//                ans[m][0] = x; ans[m][1] = nums[left]; ans[m][2] = nums[right];
//                (*returnColumnSizes)[m++] = 3;
//
//                for (left++; left < right && nums[left] == nums[left - 1]; left++);
//                for (right--; left < right && nums[right] == nums[right + 1]; right--);
//            }
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
