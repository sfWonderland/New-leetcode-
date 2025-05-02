////567. 字符串的排列
//
//bool cmp(int* nums1, int* nums2, int numsSize)
//{
//    for (int i = 0; i < numsSize; ++i)
//    {
//        if (nums1[i] != nums2[i])
//            return false;
//    }
//    return true;
//}
//bool checkInclusion(char* s1, char* s2)
//{
//    int k = strlen(s1);
//    int n = strlen(s2);
//    if (k > n)
//        return false;
//
//    int hash1[26] = { 0 };
//    for (int i = 0; i < k; ++i)
//    {
//        ++hash1[s1[i] - 'a'];
//    }
//    int hash2[26] = { 0 };
//    int ans = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        ++hash2[s2[i] - 'a'];
//        if (i < k - 1)
//            continue;
//
//        if (cmp(hash1, hash2, 26))
//            return true;
//        --hash2[s2[i - k + 1] - 'a'];
//    }
//    return false;
//}
//
////2653. 滑动子数组的美丽值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int getBeauty(int* nums, int n, int x)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        if (nums[i])
//        {
//            if (x <= nums[i])
//                return i - 50;
//            x -= nums[i];
//        }
//    }
//    return 0;
//}
//int* getSubarrayBeauty(int* nums, int numsSize, int k, int x, int* returnSize)
//{
//    int n = numsSize;
//    int hash[50] = { 0 };
//    int* ans = (int*)malloc(sizeof(int) * (n - k + 1));
//    memset(ans, 0, sizeof(int) * (n - k + 1));
//    for (int i = 0; i < n; ++i)
//    {
//        if (nums[i] < 0)
//            ++hash[nums[i] + 50];
//        if (i < k - 1)
//            continue;
//
//        ans[i - k + 1] = getBeauty(hash, 50, x);
//        if (nums[i - k + 1] < 0)
//            --hash[nums[i - k + 1] + 50];
//    }
//    *returnSize = n - k + 1;
//    return ans;
//}
//
////1007. 行相等的最少多米诺旋转
//
//int cnt(int* nums1, int* nums2, int n, int x)
//{
//    int ret1 = 0, ret2 = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if (nums1[i] != x && nums2[i] != x)
//            return -1;
//        if (nums1[i] != x)
//            ++ret1;
//        if (nums2[i] != x)
//            ++ret2;
//    }
//    return fmin(ret1, ret2);
//}
//int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize)
//{
//    int n = topsSize;
//    int ans = cnt(tops, bottoms, n, tops[0]);
//    if (ans != -1 || tops[0] == bottoms[0]) //half - half || the same
//        return ans;
//    return cnt(tops, bottoms, n, bottoms[0]);
//}
//
////438. 找到字符串中所有字母异位词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findAnagrams(char* s, char* p, int* returnSize)
//{
//    int k = strlen(p);
//    int n = strlen(s);
//    int hash1[26] = { 0 };
//    for (int i = 0; i < k; ++i)
//    {
//        ++hash1[p[i] - 'a'];
//    }
//    int hash2[26] = { 0 };
//    int* ret = (int*)malloc(sizeof(int) * n);
//    int index = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        ++hash2[s[i] - 'a'];
//        if (i < k - 1)
//            continue;
//
//        if (memcmp(hash1, hash2, sizeof(int) * 26) == 0)
//            ret[index++] = i - k + 1;
//        --hash2[s[i - k + 1] - 'a'];
//    }
//    *returnSize = index;
//    return ret;
//}
//
