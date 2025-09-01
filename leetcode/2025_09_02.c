////3025. 人员站位的方案数 I
//
//int cmp(const void* e1, const void* e2)
//{
//    int* a = *(int**)e1;
//    int* b = *(int**)e2;
//    return a[0] != b[0] ? a[0] - b[0] : b[1] - a[1];
//}
//int numberOfPairs(int** points, int pointsSize, int* pointsColSize)
//{
//    qsort(points, pointsSize, sizeof(int*), cmp);
//    int ans = 0;
//    for (int i = 0; i < pointsSize; i++)
//    {
//        int y1 = points[i][1];
//        int max_y = INT_MIN;
//        for (int j = i + 1; j < pointsSize; j++)
//        {
//            int y2 = points[j][1];
//            if (y2 <= y1 && y2 > max_y)
//            {
//                max_y = y2;
//                ans++;
//            }
//        }
//    }
//    return ans;
//}
//
////3027. 人员站位的方案数 II
//
//int cmp(const void* e1, const void* e2)
//{
//    int* a = *(int**)e1;
//    int* b = *(int**)e2;
//    return a[0] != b[0] ? a[0] - b[0] : b[1] - a[1];
//}
//int numberOfPairs(int** points, int pointsSize, int* pointsColSize)
//{
//    qsort(points, pointsSize, sizeof(int*), cmp);
//    int ans = 0;
//    for (int i = 0; i < pointsSize; i++)
//    {
//        int y1 = points[i][1];
//        int max_y = INT_MIN;
//        for (int j = i + 1; j < pointsSize; j++)
//        {
//            int y2 = points[j][1];
//            if (y2 <= y1 && y2 > max_y)
//            {
//                max_y = y2;
//                ans++;
//            }
//        }
//    }
//    return ans;
//}
//
////2559. 统计范围内的元音字符串数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool is_vowel(char c)
//{
//    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//}
//int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int n = wordsSize;
//    int prefix[n + 1];
//    prefix[0] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int len = strlen(words[i]);
//        int t = is_vowel(words[i][0]) && is_vowel(words[i][len - 1]);
//        prefix[i + 1] = t + prefix[i];
//    }
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int l = queries[i][0], r = queries[i][1];
//        ans[i] = prefix[r + 1] - prefix[l];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////3152. 特殊数组 II
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int prefix[numsSize + 1];
//    prefix[0] = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        int t = 1;
//        if (i == 0 || (nums[i] + nums[i - 1]) & 1)
//            t = 0;
//        prefix[i] = t + prefix[i - 1];
//    }
//    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int l = queries[i][0], r = queries[i][1];
//        ans[i] = prefix[l] == prefix[r];
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
