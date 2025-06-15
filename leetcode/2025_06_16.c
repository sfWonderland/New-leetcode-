////371. 两整数之和
//
//int getSum(int a, int b)
//{
//    unsigned int m = a, n = b;
//    unsigned int upgrade = 0, sum = 0, t = 0;
//    while (m || n)
//    {
//        int x = m & 1, y = n & 1;
//        sum |= (x ^ y ^ upgrade) << t;
//        if (upgrade) upgrade = x | y;
//        else upgrade = x & y;
//
//        m >>= 1; n >>= 1; t++;
//    }
//    return t < 32 ? sum | (upgrade << t) : sum;
//}
//
////201. 数字范围按位与
//
//int rangeBitwiseAnd(int left, int right)
//{
//    int shift = 0;
//    while (right > left)
//    {
//        right >>= 1;
//        left >>= 1;
//        shift++;
//    }
//
//    return left << shift;
//}
//
////2942. 查找包含给定字符的单词
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * wordsSize);
//    int n = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        if (strchr(words[i], x))
//            ans[n++] = i;
//    }
//    *returnSize = n;
//    return ans;
//}
//
////2545. 根据第 K 场考试的分数排序
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int K;
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e2)[K] - (*(int**)e1)[K];
//}
//int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    K = k;
//    qsort(score, scoreSize, sizeof(int*), cmp);
//    *returnSize = scoreSize;
//    *returnColumnSizes = scoreColSize;
//    return score;
//}
//
