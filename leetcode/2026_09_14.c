//// 4. 寻找两个正序数组的中位数
//
//int getKthElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
//{
//    int m = nums1Size, n = nums2Size;
//    int idx1 = 0, idx2 = 0;
//    while (1)
//    {
//        if (idx1 == m) return nums2[idx2 + k - 1];
//        if (idx2 == n) return nums1[idx1 + k - 1];
//        if (k == 1) return fmin(nums1[idx1], nums2[idx2]);
//
//        int new_idx1 = fmin(idx1 + k / 2, m) - 1;
//        int new_idx2 = fmin(idx2 + k / 2, n) - 1;
//        if (nums1[new_idx1] <= nums2[new_idx2])
//        {
//            k -= new_idx1 - idx1 + 1;
//            idx1 = new_idx1 + 1;
//        }
//        else
//        {
//            k -= new_idx2 - idx2 + 1;
//            idx2 = new_idx2 + 1;
//        }
//    }
//}
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int len = nums1Size + nums2Size;
//    if (len % 2 == 1)
//        return getKthElement(nums1, nums1Size, nums2, nums2Size, (len + 1) / 2) * 1.0;
//
//    return (getKthElement(nums1, nums1Size, nums2, nums2Size, len / 2) +
//        getKthElement(nums1, nums1Size, nums2, nums2Size, len / 2 + 1)) / 2.0;
//}
//
//// A.主要思路
//// 用两条分割线将两个数组分别分开，构成左右两个集合，
//// 要求满足：1.左右两集合元素大致相等；2.左集合所有数小于等于右集合的所有数。
//// 此时，中位数就在分割线两侧。
//// 如果规定左集合最多比右集合多一个，在满足上述条件的前提下
//// 左集合比右集合多1个元素时，中位数就是左集合最大元素，也就是分割线左侧临近两元素中最大的那个
//// 两集合元素个数相同时，中位数就是左集合最大元素和右集合最小元素的平均值（取浮点数）
//// 分别是分割线左侧临近两元素中最大的那个和分割线右侧临近两元素中最小的那个。
//// B.用二分查找实现
//// 由于需要满足两个条件，因而需要控制左右两个集合元素大致相等，左集合比右集合最多多一个的前提
//// 因而只要知道一个数组的分割线位置，另一个的就知道了
//// 为减少处理量，可以只二分查找数组长度更短的数组分割线位置
//// 其次要求nums1左的元素小于等于nums2右的元素，nums2左的元素小于等于nums1右的元素
//// 用i, j表示分割线位置，nums1，nums2元素个数分别为m，n，则要求左集合数量为(m + n + 1) / 2
//// 同时要求满足nums1[i - 1] <= nums2[j] && nums1[i] >= nums2[j - 1]，不满足就调整
//// 如果nums1[i - 1] > nums2[j]，说明nums1分割线太靠右了，需要向左调整，right = i - 1;
//// 否则nums2分割线太靠左了,就继续向右调整，left = i + 1
//// C.边界处理
//// 如果分割线在边界上会导致判断数组元素越界，比如i，j = 0或数组长度，此时需要进行边界处理
//// 当i，j = 0时，将分割线左边的元素值定为INT_MIN，就不会再往左移动了
//// 同理，当i，j = 数组长度时，将分割线右边的元素值定为INT_MAX，就不会再往右移动了
//// D.返回结果
//// 当数组总长度为奇数时，只需要返回左集合最大值，否则需要返回左集合最大元素和右集合最小元素的平均值
//// E.性能判断
//// 时间复杂度O(log(min(m,n)))，空间复杂度O(1)
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    // 由于需要满足两个条件，因而需要控制左右两个集合元素大致相等，左集合比右集合最多多一个的前提
//    // 因而只要知道一个数组的分割线位置，另一个的就知道了
//    // 为减少处理量，可以只二分查找数组长度更短的数组分割线位置
//    if (nums1Size > nums2Size)
//        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
//
//    int m = nums1Size, n = nums2Size;
//    int median1 = 0, median2 = 0; // median1：左集合的最大值，median2：右集合的最小值
//    int left = 0, right = m; // 分割线位置
//    while (left <= right)
//    {
//        int i = (left + right) / 2;
//        int j = (m + n + 1) / 2 - i; // 使总长度为奇数长度时，左集合元素多一个
//
//        // 边界处理，越界位置赋值，使之位置固定
//        int l1 = i == 0 ? INT_MIN : nums1[i - 1]; // nums1分割线左元素
//        int l2 = j == 0 ? INT_MIN : nums2[j - 1]; // nums2分割线左元素
//        int r1 = i == m ? INT_MAX : nums1[i]; // nums1分割线右元素
//        int r2 = j == n ? INT_MAX : nums2[j]; // nums2分割线右元素
//
//        // nums1分割线太靠右了，需要向左调整
//        if (l1 > r2)
//            right = i - 1;
//        // 否则nums2分割线太靠左了,就继续向右调整
//        else
//        {
//            median1 = fmax(l1, l2);
//            median2 = fmin(r1, r2);
//            left = i + 1;
//        }
//    }
//    // 当数组总长度为奇数时，只需要返回左集合最大值，否则需要返回左集合最大元素和右集合最小元素的平均值
//    return (m + n) % 2 ? median1 : (median1 + median2) / 2.0;
//}
//
