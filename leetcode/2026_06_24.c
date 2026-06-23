//// 718. 最长重复子数组
//
//int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int n = nums1Size, m = nums2Size;
//    int f[n + 1][m + 1];
//    memset(f, 0, sizeof(f));
//    int ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                f[i + 1][j + 1] = f[i][j] + 1;
//                ans = fmax(ans, f[i + 1][j + 1]);
//            }
//        }
//    }
//    return ans;
//}
//
