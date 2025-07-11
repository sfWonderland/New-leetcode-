////1282. 用户分组
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = groupSizesSize;
//    int groups[n][2];
//    for (int i = 0; i < n; i++)
//    {
//        groups[i][0] = groupSizes[i];
//        groups[i][1] = i;
//    }
//    qsort(groups, n, sizeof(int) * 2, cmp);
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    int idx = -1;
//    for (int i = 0; i < n; )
//    {
//        int m = groups[i][0];
//        ans[++idx] = (int*)malloc(sizeof(int) * m);
//        for (int j = i; j < i + m; j++)
//        {
//            ans[idx][j - i] = groups[j][1];
//        }
//        (*returnColumnSizes)[idx] = m;
//        i += m;
//    }
//    *returnSize = idx + 1;
//    return ans;
//}
//
////3314. 构造最小位运算数组 I
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* minBitwiseArray(int* nums, int numsSize, int* returnSize)
//{
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 2)
//            nums[i] = -1;
//        else
//        {
//            int t = 2;
//            while (nums[i] & t)
//                t <<= 1;
//
//            nums[i] -= t >> 1;
//        }
//    }
//    *returnSize = numsSize;
//    return nums;
//}
//
////1021. 删除最外层的括号
//
//char* removeOuterParentheses(char* s)
//{
//    int left = 0, n = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] == ')')
//            n++;
//        if (n)
//            s[left++] = s[i];
//        if (s[i] == '(')
//            n--;
//    }
//    s[left] = '\0';
//    return s;
//}
//
////3536. 两个数字的最大乘积
//
//int maxProduct(int n)
//{
//    int max1 = 0, max2 = 0;
//    while (n)
//    {
//        int t = n % 10;
//        if (t > max1)
//        {
//            max2 = max1;
//            max1 = t;
//        }
//        else if (t > max2)
//        {
//            max2 = t;
//        }
//        n /= 10;
//    }
//    return max1 * max2;
//}
//
