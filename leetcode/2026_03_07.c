////1888. 使二进制字符串字符交替的最少反转次数
//
//int minFlips(char* s)
//{
//    int n = strlen(s);
//    int ans = n, sum = 0;
//    for (int i = 0; i < 2 * n - 1; i++)
//    {
//        sum += abs(s[i % n] - i % 2 - '0');
//        if (i < n - 1)
//            continue;
//
//        ans = fmin(ans, fmin(sum, n - sum));
//        sum -= abs(s[i - n + 1] - (i - n + 1) % 2 - '0');
//        //printf("%d %d %d\n", i, ans, sum);
//    }
//    return ans;
//}
//
//int minFlips(char* s)
//{
//    int n = strlen(s);
//    int ans = n, sum = 0;
//    for (int i = 0; i < 2 * n - 1; i++)
//    {
//        sum += (s[i % n] ^ i) & 1;
//        int left = i - n + 1;
//        if (left < 0)
//            continue;
//
//        ans = fmin(ans, fmin(sum, n - sum));
//        sum -= (s[left % n] ^ left) & 1;
//        //printf("%d %d %d\n", i, ans, sum);
//    }
//    return ans;
//}
//
////833. 字符串中的查找与替换    
//
//int* arr;
//int cmp(const void* e1, const void* e2)
//{
//    return arr[*(int*)e1] - arr[*(int*)e2];
//}
//char* findReplaceString(char* s, int* indices, int indicesSize, char** sources, int sourcesSize, char** targets, int targetsSize)
//{
//    int n = indicesSize;
//    int* idx = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        idx[i] = i;
//    }
//    arr = indices;
//    qsort(idx, n, sizeof(int), cmp);
//    int capacity = 8;
//    char* ans = (char*)malloc(sizeof(char) * capacity);
//    int k = 0, len = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int j = idx[i];
//        int left = indices[j];
//        int m = strlen(sources[j]);
//        while (len < left)
//        {
//            ans[k++] = s[len++];
//            if (k >= capacity)
//            {
//                capacity *= 2;
//                ans = (char*)realloc(ans, sizeof(char) * capacity);
//            }
//        }
//        if (strncmp(s + left, sources[j], m) == 0)
//        {
//            for (int d = 0; targets[j][d]; d++)
//            {
//                ans[k++] = targets[j][d];
//                if (k >= capacity)
//                {
//                    capacity *= 2;
//                    ans = (char*)realloc(ans, sizeof(char) * capacity);
//                }
//            }
//            len += m;
//        }
//    }
//    while (s[len])
//    {
//        ans[k++] = s[len++];
//        if (k >= capacity)
//        {
//            capacity *= 2;
//            ans = (char*)realloc(ans, sizeof(char) * capacity);
//        }
//    }
//    ans[k] = '\0';
//    return ans;
//}
//
////957. N 天后的牢房
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize)
//{
//    n = (n - 1) % 14 + 1;
//    int* ans = (int*)calloc(sizeof(int), cellsSize);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < cellsSize; j++)
//        {
//            if (j == 0 || j == cellsSize - 1)
//                ans[j] = 0;
//            else
//                ans[j] = cells[j - 1] ^ cells[j + 1] ^ 1;
//        }
//        memcpy(cells, ans, sizeof(int) * cellsSize);
//    }
//    *returnSize = cellsSize;
//    return ans;
//}
//
////1104. 二叉树寻路
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* pathInZigZagTree(int label, int* returnSize)
//{
//    int n = 32 - __builtin_clz(label);
//    int* ans = (int*)malloc(sizeof(int) * n);
//    if (n % 2 == 0)
//        label = (1 << (n - 1)) * 3 - 1 - label;
//    for (int i = 0; i < n; i++)
//    {
//        int x = label >> (n - 1 - i);
//        if (i % 2 == 0)
//            ans[i] = x;
//        else
//            ans[i] = (1 << i) * 3 - 1 - x;
//    }
//    *returnSize = n;
//    return ans;
//}
//
