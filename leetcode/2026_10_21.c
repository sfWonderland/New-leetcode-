//// 912. ÅÅÐòÊý×é
//
//// MergeSort
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arr;
//void Merge(int* nums, int left, int mid, int right)
//{
//    memcpy(arr + left, nums + left, sizeof(int) * (right - left + 1));
//    int i = left, j = mid + 1, k = left;
//    while (i <= mid && j <= right)
//    {
//        if (arr[i] <= arr[j])
//            nums[k++] = arr[i++];
//        else
//            nums[k++] = arr[j++];
//    }
//    while (i <= mid) nums[k++] = arr[i++];
//    while (j <= right) nums[k++] = arr[j++];
//}
//void MergeSort(int* nums, int left, int right)
//{
//    if (left >= right) return;
//    int mid = (left + right) / 2;
//    MergeSort(nums, left, mid);
//    MergeSort(nums, mid + 1, right);
//    Merge(nums, left, mid, right);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    arr = (int*)malloc(sizeof(int) * numsSize);
//    MergeSort(nums, 0, numsSize - 1);
//    free(arr);
//    *returnSize = numsSize;
//    return nums;
//}
//
////    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int fun(int* nums, int left, int right)
//{
//    int pivot = rand() % (right - left + 1) + left;
//    int x = nums[pivot];
//    nums[pivot] = nums[left];
//    int i = left, j = right;
//    while (i < j)
//    {
//        while (i < j && nums[j] >= x) j--;
//        nums[i] = nums[j];
//
//        while (i < j && nums[i] <= x) i++;
//        nums[j] = nums[i];
//
//    }
//
//    nums[j] = x;
//    return i;
//}
//void QuickSort(int* nums, int left, int right)
//{
//    bool ordered = true;
//    for (int i = left; i < right && ordered; i++)
//    {
//        if (nums[i] > nums[i + 1])
//            ordered = false;
//    }
//    if (ordered) return;
//    int pivot = fun(nums, left, right);
//    QuickSort(nums, left, pivot - 1);
//    QuickSort(nums, pivot + 1, right);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    srand(time(NULL));
//    QuickSort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//#define SWAP(a, b) do{int tmp = (a); (a) = (b); (b) = tmp;} while(0)
//int partition(int* nums, int left, int right)
//{
//    int pivot = rand() % (right - left + 1) + left;
//    int x = nums[pivot];
//    SWAP(nums[left], nums[pivot]);
//    int i = left + 1, j = right;
//    while (1)
//    {
//        while (i <= j && nums[i] < x) i++;
//        while (i <= j && nums[j] > x) j--;
//        if (i >= j) break;
//        SWAP(nums[i], nums[j]);
//        i++; j--;
//    }
//    SWAP(nums[j], nums[left]);
//    return j;
//}
//void QuickSort(int* nums, int left, int right)
//{
//    bool ordered = true;
//    for (int i = left; i < right && ordered; i++)
//    {
//        if (nums[i] > nums[i + 1])
//            ordered = false;
//    }
//    if (ordered) return;
//    int pivot = partition(nums, left, right);
//    QuickSort(nums, left, pivot - 1);
//    QuickSort(nums, pivot + 1, right);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize)
//{
//    srand(time(NULL));
//    QuickSort(nums, 0, numsSize - 1);
//    *returnSize = numsSize;
//    return nums;
//}
//
//
