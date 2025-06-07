////1657. 确定两个字符串是否接近
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//bool closeStrings(char* word1, char* word2)
//{
//    int m = strlen(word1), n = strlen(word2);
//    if (m != n)
//        return false;
//    //printf("!\n");
//    int hash1[26] = { 0 };
//    int hash2[26] = { 0 };
//    for (int i = 0; word1[i]; i++)
//    {
//        hash1[word1[i] - 'a']++;
//        hash2[word2[i] - 'a']++;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        int a = (hash1[i] > 0), b = (hash2[i] > 0);
//        if (!(a ^ b))
//            continue;
//
//        return false;
//    }
//    //printf("!\n");
//    qsort(hash1, 26, sizeof(int), cmp);
//    qsort(hash2, 26, sizeof(int), cmp);
//    for (int i = 0; i < 26; i++)
//    {
//        if (hash1[i] != hash2[i])
//            return false;
//    }
//    //printf("!\n");
//    return true;
//}
//
////942. 增减字符串匹配
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* diStringMatch(char* s, int* returnSize)
//{
//    int n = strlen(s), left = 0, right = n;
//    int* ret = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        ret[i] = (s[i] == 'I') ? left++ : right--;
//    }
//    ret[n] = left;
//    *returnSize = n + 1;
//    return ret;
//}
//
////1968. 构造元素不等于两相邻元素平均值的数组
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
// // int cmp(const void* e1, const void* e2)
// // {
// //     return *(int*)e1 - *(int*)e2;
// // }
// // void swap(int* a, int* b)
// // {
// //     int tmp = *a;
// //     *a = *b;
// //     *b = tmp;
// // }
// // int* rearrangeArray(int* nums, int numsSize, int* returnSize) 
// // {
// //     qsort(nums, numsSize, sizeof(int), cmp);
// //     for(int i = 1; i < numsSize - 1; i += 2)
// //     {
// //         swap(&nums[i], &nums[i + 1]);
// //     }
// //     *returnSize = numsSize;
// //     return nums;    
// // }
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* rearrangeArray(int* nums, int numsSize, int* returnSize)
//{
//    int t = 1;
//    while (t)
//    {
//        t = 0;
//        for (int i = 1; i < numsSize - 1; i++)
//        {
//            if (nums[i] == (nums[i - 1] + nums[i + 1]) / 2)
//            {
//                int tmp = nums[i];
//                nums[i] = nums[i + 1];
//                nums[i + 1] = tmp;
//                t = 1;
//            }
//        }
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////1253. 重构 2 行二进制矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes)
//{
//    int sum = upper + lower, min = fmin(upper, lower);
//    for (int i = 0; i < colsumSize; i++)
//    {
//        sum -= colsum[i];
//        min -= (colsum[i] == 2);
//    }
//    if (sum || min < 0)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//
//    int** ret = (int**)malloc(sizeof(int*) * 2);
//    *returnSize = 2;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < 2; i++)
//    {
//        ret[i] = (int*)calloc(colsumSize, sizeof(int));
//        (*returnColumnSizes)[i] = colsumSize;
//    }
//    for (int i = 0; i < colsumSize; i++)
//    {
//        if (colsum[i] == 2)
//        {
//            ret[0][i] = 1; ret[1][i] = 1;
//            upper--; lower--;
//        }
//        else if (colsum[i] == 0)
//        {
//            ret[0][i] = 0; ret[1][i] = 0;
//        }
//    }
//    for (int i = 0; i < colsumSize; i++)
//    {
//        if (colsum[i] == 1)
//        {
//            if (upper > 0)
//            {
//                ret[0][i] = 1; ret[1][i] = 0;
//                upper--;
//            }
//            else
//            {
//                ret[0][i] = 0; ret[1][i] = 1;
//            }
//        }
//    }
//    return ret;
//}
//
