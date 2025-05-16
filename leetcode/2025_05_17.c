////75. 颜色分类
//
//int Partition(int* nums, int low, int high)
//{
//    int pivot = nums[low];
//    while (low < high)
//    {
//        while (low < high && nums[high] >= pivot)
//        {
//            high--;
//        }
//        nums[low] = nums[high];
//        while (low < high && nums[low] <= pivot)
//        {
//            low++;
//        }
//        nums[high] = nums[low];
//    }
//    nums[low] = pivot;
//    return low;
//}
//void QuickSort(int* nums, int low, int high)
//{
//    if (low < high)
//    {
//        int pivotpos = Partition(nums, low, high);
//        QuickSort(nums, low, pivotpos - 1);
//        QuickSort(nums, pivotpos + 1, high);
//    }
//}
//void sortColors(int* nums, int numsSize)
//{
//    QuickSort(nums, 0, numsSize - 1);
//}
//
////2825. 循环增长使字符串子序列等于另一个字符串
//
//bool canMakeSubsequence(char* str1, char* str2)
//{
//    int i = 0, j = 0;
//    while (str1[i] && str2[j])
//    {
//        if (str1[i] == str2[j] || (str1[i] + 1 - 'a') % 26 + 'a' == str2[j])
//            j++;
//
//        i++;
//    }
//    return str2[j] == '\0';
//}
//
////1023. 驼峰式匹配
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize)
//{
//    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int k = 0;
//        ans[i] = true;
//        for (int j = 0; queries[i][j]; j++)
//        {
//            if (pattern[k] && pattern[k] == queries[i][j])
//                k++;
//            else if (isupper(queries[i][j]))
//            {
//                ans[i] = false;
//                break;
//            }
//        }
//        if (pattern[k])
//            ans[i] = false;
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////3132. 找出与数组相加的整数 II
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    qsort(nums1, nums1Size, sizeof(int), cmp);
//    qsort(nums2, nums2Size, sizeof(int), cmp);
//    for (int i = 2; i >= 0; i--)
//    {
//        int x = nums2[0] - nums1[i];
//        int k = 0;
//        for (int j = i; j < nums1Size; j++)
//        {
//            if (nums1[j] + x == nums2[k] && ++k == nums2Size)
//                return x;
//        }
//    }
//    return nums2[0] - nums1[0];
//}
//
