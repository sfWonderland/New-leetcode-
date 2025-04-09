////3375. 使数组的值全部为 K 的最少操作次数
//
//int minOperations(int* nums, int numsSize, int k)
//{
//    int hash[101] = { 0 };
//    int n = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] < k)
//            return -1;
//        if (0 == hash[nums[i]] && nums[i] > k)
//        {
//            hash[nums[i]] = 1;
//            n++;
//        }
//    }
//    return n;
//}
//
////1935. 可以输入的最大单词数
//
//int canBeTypedWords(char* text, char* brokenLetters)
//{
//    int alpha = 0;
//    for (int i = 0; brokenLetters[i]; i++)
//    {
//        alpha |= 1 << (brokenLetters[i] - 'a');
//    }
//    int flag = 1;
//    int num = 0;
//    for (int i = 0; text[i]; i++)
//    {
//        if (text[i] == ' ')
//        {
//            num += flag;
//            flag = 1;
//        }
//        else if (isalpha(text[i]) && ((1 << (text[i] - 'a')) & alpha))
//            flag = 0;
//    }
//    return num + flag;
//}
//
////2022. 将一维数组转变成二维数组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes)
//{
//    if (originalSize != m * n)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int** ret = (int**)malloc(sizeof(int*) * m);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ret[i] = (int*)malloc(sizeof(int) * n);
//        memcpy(ret[i], original + i * n, sizeof(int) * n);
//        (*returnColumnSizes)[i] = n;
//    }
//    returnSize[0] = m;
//    return ret;
//}
//
////2089. 找出数组排序后的目标下标
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    int left = -1;
//    int right = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == target)
//        {
//            if (left == -1)
//                left = i;
//
//            right = i;
//        }
//    }
//    if (left == -1)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int* ret = (int*)malloc(sizeof(int) * (right - left + 1));
//    for (int i = left; i <= right; i++)
//    {
//        ret[i - left] = i;
//    }
//    *returnSize = right - left + 1;
//    return ret;
//}
//
