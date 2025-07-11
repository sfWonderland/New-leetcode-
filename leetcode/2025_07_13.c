////77. 组合
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** conbinations;
//int conbinationsSize;
//
//int* conbination;
//
//int len;
//
//int Combo(int n, int k)
//{
//    long long a = 1, b = 1;
//    for (int i = 1; i <= k; i++)
//    {
//        a *= n + 1 - i;
//        b *= i;
//    }
//    return a / b;
//}
//void dfs(int n, int k)
//{
//    if (k == 0)
//    {
//        conbinations[conbinationsSize] = (int*)malloc(sizeof(int) * len);
//        for (int i = 0; i < len; i++)
//        {
//            conbinations[conbinationsSize][i] = conbination[i];
//        }
//        conbinationsSize++;
//        return;
//    }
//    for (int i = n; i >= k; i--)
//    {
//        conbination[k - 1] = i;
//        dfs(i - 1, k - 1);
//    }
//}
//int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
//{
//    int num = Combo(n, k);
//    conbinations = (int**)malloc(sizeof(int*) * num);
//    conbination = (int*)malloc(sizeof(int) * k);
//
//    conbinationsSize = 0;
//    len = k;
//
//    dfs(n, k);
//    *returnSize = num;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
//    for (int i = 0; i < num; i++)
//    {
//        (*returnColumnSizes)[i] = k;
//    }
//    return conbinations;
//}
//
////22. 括号生成
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** ans;
//char* s;
//
//int ansSize;
//int len;
//
//void dfs(int n, int left)
//{
//    if (n == len * 2)
//    {
//        ans[ansSize] = (char*)malloc(sizeof(char) * (2 * len + 1));
//        for (int j = 0; j < 2 * len; j++)
//        {
//            ans[ansSize][j] = s[j];
//        }
//        ans[ansSize][2 * len] = '\0';
//        ansSize++;
//        return;
//    }
//
//    if (left < len)
//    {
//        s[n] = '(';
//        dfs(n + 1, left + 1);
//    }
//
//    if (n < 2 * left)
//    {
//        s[n] = ')';
//        dfs(n + 1, left);
//    }
//}
//char** generateParenthesis(int n, int* returnSize)
//{
//    int sum = 2 * n;
//    int num = 1;
//    for (int i = sum; i > n; i--)
//    {
//        num = num * i / (sum - i + 1);
//        printf("%d ", num);
//    }
//
//    ans = (char**)malloc(sizeof(char*) * num);
//    s = (char*)malloc(sizeof(char) * (2 * n + 1));
//    s[2 * n] = '\0';
//    len = n, ansSize = 0;
//
//    dfs(0, 0);
//
//    *returnSize = ansSize;
//    return ans;
//}
//
////216. 组合总和 III
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** combinations;
//int combinationsSize;
//
//int* combination;
//int idx;
//
//int len;
//
//void dfs(int d, int n)
//{
//    int num = len - idx;
//    if (n < 0 || n >(2 * d - num + 1) * num / 2)
//        return;
//
//    if (idx == len)
//    {
//        combinations[combinationsSize] = (int*)malloc(sizeof(int) * len);
//        for (int i = 0; i < len; i++)
//        {
//            combinations[combinationsSize][i] = combination[i];
//        }
//        combinationsSize++;
//        return;
//    }
//
//    for (int i = d; i > 0; i--)
//    {
//        combination[idx++] = i;
//        dfs(i - 1, n - i);
//        idx--;
//    }
//}
//
//int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
//{
//    int num = 1;
//    for (int i = 1; i <= k; i++)
//    {
//        num = num * (10 - i) / i;
//    }
//    combinations = (int**)malloc(sizeof(int*) * num);
//    combination = (int*)malloc(sizeof(int) * k);
//
//    combinationsSize = 0, len = k, idx = 0;
//
//    dfs(9, n);
//
//    *returnColumnSizes = (int*)malloc(sizeof(int) * combinationsSize);
//    for (int i = 0; i < combinationsSize; i++)
//    {
//        (*returnColumnSizes)[i] = k;
//    }
//    *returnSize = combinationsSize;
//    return combinations;
//}
//
////90. 子集 II
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
//
//void dfs(int i, int n, int* nums, int** subsets, int* returnSize, int** returnColumnSizes, int* subset, int subsetSize)
//{
//    if (i == n)
//    {
//        subsets[*returnSize] = malloc(sizeof(int) * subsetSize);
//        for (int i = 0; i < subsetSize; i++)
//        {
//            subsets[*returnSize][i] = subset[i];
//        }
//        (*returnColumnSizes)[(*returnSize)++] = subsetSize;
//        return;
//    }
//
//    int x = nums[i];
//    subset[subsetSize] = x;
//    dfs(i + 1, n, nums, subsets, returnSize, returnColumnSizes, subset, subsetSize + 1);
//
//    i++;
//    while (i < n && nums[i] == x)
//        i++;
//    dfs(i, n, nums, subsets, returnSize, returnColumnSizes, subset, subsetSize);
//}
//
//int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//
//    int m = 1 << numsSize;
//    int** subsets = (int**)malloc(sizeof(int*) * m);
//    int* subset = (int*)malloc(sizeof(int) * numsSize);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//
//    *returnSize = 0;
//
//    dfs(0, numsSize, nums, subsets, returnSize, returnColumnSizes, subset, 0);
//
//    return subsets;
//}
//
