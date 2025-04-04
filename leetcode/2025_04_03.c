<<<<<<< HEAD
////2032. 至少在两个数组中出现的值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void get_hash(int* arr, int row, int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[nums[i] - 1] |= 1 << row;
//    }
//}
//int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize)
//{
//    int* h = (int*)malloc(sizeof(int) * 100);
//    memset(h, 0, sizeof(int) * 100);
//    get_hash(h, 0, nums1, nums1Size);
//    get_hash(h, 1, nums2, nums2Size);
//    get_hash(h, 2, nums3, nums3Size);
//    int* ret = (int*)malloc(sizeof(int) * 100);
//    int n = 0;
//    for (int i = 0; i < 100; i++)
//    {
//        if (h[i] & (h[i] - 1))
//            ret[n++] = i + 1;
//    }
//    free(h);
//    returnSize[0] = n;
//    return ret;
//}
//
////1779. 找到最近的有相同 X 或 Y 坐标的点
//
//int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize)
//{
//    int index = -1;
//    int D = INT_MAX;
//    for (int i = 0; i < pointsSize; i++)
//    {
//        int xi = points[i][0], yi = points[i][1];
//        if (x == xi && y == yi)
//            return i;
//        else if (x == xi)
//        {
//            int Di = abs(y - yi);
//            if (Di < D)
//            {
//                index = i;
//                D = Di;
//            }
//        }
//        else if (y == yi)
//        {
//            int Di = abs(x - xi);
//            if (Di < D)
//            {
//                index = i;
//                D = Di;
//            }
//        }
//    }
//    return index;
//}
//
////1974. 使用特殊打字机键入单词的最少时间
//
//int minTimeToType(char* word)
//{
//    char alpha = 'a';
//    int t = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        int dist = abs(word[i] - alpha);
//        alpha = word[i];
//        t += 1 + fmin(26 - dist, dist);
//    }
//    return t;
//}
//
////2006. 差的绝对值为 K 的数对数目
//
//int countKDifference(int* nums, int numsSize, int k)
//{
//    int hash[101] = { 0 };
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > k)
//            cnt += hash[nums[i] - k];
//        if (nums[i] + k <= 100)
//            cnt += hash[nums[i] + k];
//        hash[nums[i]]++;
//    }
//    return cnt;
//}
//
=======
////2032. 至少在两个数组中出现的值
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void get_hash(int* arr, int row, int* nums, int numsSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[nums[i] - 1] |= 1 << row;
//    }
//}
//int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize)
//{
//    int* h = (int*)malloc(sizeof(int) * 100);
//    memset(h, 0, sizeof(int) * 100);
//    get_hash(h, 0, nums1, nums1Size);
//    get_hash(h, 1, nums2, nums2Size);
//    get_hash(h, 2, nums3, nums3Size);
//    int* ret = (int*)malloc(sizeof(int) * 100);
//    int n = 0;
//    for (int i = 0; i < 100; i++)
//    {
//        if (h[i] & (h[i] - 1))
//            ret[n++] = i + 1;
//    }
//    free(h);
//    returnSize[0] = n;
//    return ret;
//}
//
////1779. 找到最近的有相同 X 或 Y 坐标的点
//
//int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize)
//{
//    int index = -1;
//    int D = INT_MAX;
//    for (int i = 0; i < pointsSize; i++)
//    {
//        int xi = points[i][0], yi = points[i][1];
//        if (x == xi && y == yi)
//            return i;
//        else if (x == xi)
//        {
//            int Di = abs(y - yi);
//            if (Di < D)
//            {
//                index = i;
//                D = Di;
//            }
//        }
//        else if (y == yi)
//        {
//            int Di = abs(x - xi);
//            if (Di < D)
//            {
//                index = i;
//                D = Di;
//            }
//        }
//    }
//    return index;
//}
//
////1974. 使用特殊打字机键入单词的最少时间
//
//int minTimeToType(char* word)
//{
//    char alpha = 'a';
//    int t = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        int dist = abs(word[i] - alpha);
//        alpha = word[i];
//        t += 1 + fmin(26 - dist, dist);
//    }
//    return t;
//}
//
////2006. 差的绝对值为 K 的数对数目
//
//int countKDifference(int* nums, int numsSize, int k)
//{
//    int hash[101] = { 0 };
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > k)
//            cnt += hash[nums[i] - k];
//        if (nums[i] + k <= 100)
//            cnt += hash[nums[i] + k];
//        hash[nums[i]]++;
//    }
//    return cnt;
//}
//
