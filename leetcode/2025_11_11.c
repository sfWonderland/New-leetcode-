////474. 一和零
//
//int count_zeros(char* s)
//{
//    int ret = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        ret += '1' - s[i];
//    }
//    return ret;
//}
//int findMaxForm(char** strs, int strsSize, int m, int n)
//{
//    int f[m + 1][n + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        memset(f[i], 0, sizeof(f[i]));
//    }
//    int sum0 = 0, sum1 = 0;
//    for (int k = 0; k < strsSize; k++)
//    {
//        int len = strlen(strs[k]);
//        int cnt0 = count_zeros(strs[k]);
//        int cnt1 = len - cnt0;
//        sum0 = fmin(cnt0 + sum0, m);
//        sum1 = fmin(cnt1 + sum1, n);
//        for (int i = sum0; i >= cnt0; i--)
//        {
//            for (int j = sum1; j >= cnt1; j--)
//            {
//                f[i][j] = fmax(f[i][j], f[i - cnt0][j - cnt1] + 1);
//            }
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i <= m; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            ans = fmax(ans, f[i][j]);
//        }
//    }
//    return ans;
//}
//
////2171. 拿出最少数目的魔法豆
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long minimumRemoval(int* beans, int beansSize)
//{
//    qsort(beans, beansSize, sizeof(int), cmp);
//    long long sum = 0, max_save = 0;
//    for (int i = 0; i < beansSize; i++)
//    {
//        sum += beans[i];
//        max_save = fmax(max_save, 1ll * (beansSize - i) * beans[i]);
//    }
//    return sum - max_save;
//}
//
////1054. 距离相等的条形码
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(int* arr, int i, int j)
//{
//    int tmp = arr[i];
//    arr[i] = arr[j];
//    arr[j] = tmp;
//}
//int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
//{
//    for (int i = 0; i < barcodesSize - 1; i++)
//    {
//        if (barcodes[i] == barcodes[i + 1])
//        {
//            int j = i + 2;
//            while (j < barcodesSize&& barcodes[j] == barcodes[i])
//                j++;
//
//            if (j == barcodesSize)
//                break;
//            swap(barcodes, i + 1, j);
//        }
//    }
//    for (int i = barcodesSize - 1; i > 0; i--)
//    {
//        if (barcodes[i] == barcodes[i - 1])
//        {
//            int j = i - 2;
//            while (j >= 0 && barcodes[j] == barcodes[i])
//                j--;
//
//            swap(barcodes, i - 1, j);
//        }
//    }
//    *returnSize = barcodesSize;
//    return barcodes;
//}
//
////2856. 删除数对后的最小数组长度
//
//int Binary_search(int* nums, int l, int r, int x, bool dir)
//{
//    while (l <= r)
//    {
//        int mid = (l + r) / 2;
//        if (nums[mid] > x)
//            r = mid - 1;
//        else if (nums[mid] == x)
//        {
//            if (dir)
//                l = mid + 1;
//            else
//                r = mid - 1;
//        }
//        else
//            l = mid + 1;
//    }
//    return l;
//}
//int minLengthAfterRemovals(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int x = nums[n / 2];
//    int l = Binary_search(nums, 0, n / 2, x, 0);
//    int r = Binary_search(nums, n / 2 + 1, n - 1, x, 1);
//    return fmax((r - l) * 2 - n, n % 2);
//}
//
////34. 在排序数组中查找元素的第一个和最后一个位置
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int BinarySearch(int* nums, int left, int right, int x, bool dir)
//{
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] == x)
//        {
//            if (dir)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        else if (nums[mid] > x)
//            right = mid - 1;
//        else
//            left = left + 1;
//    }
//    return left;
//}
//int* searchRange(int* nums, int numsSize, int target, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = -1; ans[1] = -1;
//    *returnSize = 2;
//
//    if (numsSize == 0)
//        return ans;
//
//    int pt = BinarySearch(nums, 0, numsSize - 1, target, 0);
//    if (pt == numsSize || nums[pt] != target)
//        return ans;
//
//    ans[0] = BinarySearch(nums, 0, pt, target, 0);
//    ans[1] = BinarySearch(nums, pt, numsSize - 1, target, 1) - 1;
//
//    return ans;
//}
//
////1953. 你可以工作的最大周数
//
//int BinarySearch(long long* nums, int left, int right, long long x)
//{
//    while (left <= right)
//    {
//        int mid = left + ((right - left) >> 1);
//        if (nums[mid] > x)
//            right = mid - 1;
//        else
//            left = left + 1;
//    }
//    return left;
//}
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//long long numberOfWeeks(int* milestones, int milestonesSize)
//{
//    if (milestonesSize == 1)
//        return 1;
//    int n = milestonesSize;
//    qsort(milestones, n, sizeof(int), cmp);
//    long long* sum = (long long*)malloc(sizeof(long long) * (n + 1));
//    sum[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum[i + 1] = sum[i] + milestones[i];
//    }
//    int p = BinarySearch(sum, 0, n, (sum[n] + 1) / 2);
//    //printf("%d ", p);
//    long long m = sum[p] - sum[p - 1];
//    //printf("%d ", m);
//    return fmin((sum[n] - m) * 2 + 1, sum[n]);
//}
//
//long long numberOfWeeks(int* milestones, int milestonesSize)
//{
//    long long sum = 0;
//    int m = 0;
//    for (int i = 0; i < milestonesSize; i++)
//    {
//        sum += milestones[i];
//        m = fmax(m, milestones[i]);
//    }
//    return fmin((sum - m) * 2 + 1, sum);
//}
//
