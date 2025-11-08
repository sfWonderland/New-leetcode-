////3740. 三个相等元素之间的最小距离 I
//
//int minimumDistance(int* nums, int numsSize)
//{
//    int arr[numsSize + 1][numsSize + 1];
//    int cnt[numsSize + 1];
//    memset(cnt, 0, sizeof(cnt));
//    int ans = 10000;
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[nums[i]][cnt[nums[i]]] = i;
//        if (cnt[nums[i]] >= 2)
//        {
//            ans = fmin(ans, 2 * (i - arr[nums[i]][cnt[nums[i]] - 2]));
//        }
//        cnt[nums[i]]++;
//    }
//    return ans == 10000 ? -1 : ans;
//}
//
////3741. 三个相等元素之间的最小距离 II
//
//int minimumDistance(int* nums, int numsSize)
//{
//    int arr[numsSize + 1][2];
//    int cnt[numsSize + 1];
//    memset(cnt, 0, sizeof(cnt));
//    int ans = INT_MAX;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (cnt[nums[i]] >= 2)
//        {
//            ans = fmin(ans, 2 * (i - arr[nums[i]][cnt[nums[i]] % 2]));
//        }
//        arr[nums[i]][cnt[nums[i]] % 2] = i;
//        cnt[nums[i]]++;
//    }
//    return ans == INT_MAX ? -1 : ans;
//}
//
////3742. 网格中得分最大的路径
//
//int maxPathScore(int** grid, int gridSize, int* gridColSize, int k)
//{
//    int m = gridSize, n = gridColSize[0];
//    int f[m + 1][n + 1][k + 1];
//    for (int i = 0; i <= m; i++)
//    {
//        for (int j = 0; j <= k; j++)
//        {
//            f[i][0][j] = INT_MIN / 2;
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= k; j++)
//        {
//            f[0][i][j] = INT_MIN / 2;
//        }
//    }
//    memset(f[1][0], 0, sizeof(f[1][0]));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int x = grid[i][j];
//            bool pt = x > 0;
//            for (int t = 0; t <= k; t++)
//            {
//                if (pt > t)
//                    f[i + 1][j + 1][t] = INT_MIN / 2;
//                else
//                {
//                    f[i + 1][j + 1][t] = fmax(f[i][j + 1][t - pt], f[i + 1][j][t - pt]) + x;
//                }
//            }
//        }
//    }
//    return f[m][n][k] < 0 ? -1 : f[m][n][k];
//}
//
////870. 优势洗牌
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* arr;
//int cmp1(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int cmp2(const void* e1, const void* e2)
//{
//    return arr[*(int*)e1] - arr[*(int*)e2];
//}
//int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    int n = nums1Size;
//    qsort(nums1, n, sizeof(int), cmp1);
//    arr = nums2;
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    qsort(idx, n, sizeof(int), cmp2);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int left = 0, right = n - 1;
//    for (int i = 0; i < n; i++)
//    {
//        int j = nums1[i] > nums2[idx[left]] ? idx[left++] : idx[right--];
//        ans[j] = nums1[i];
//    }
//    *returnSize = n;
//    return ans;
//}
//
