////2207. 字符串中最多数目的子序列
//
//long long maximumSubsequenceCount(char* text, char* pattern)
//{
//    long long ans = 0;
//    int sumA = 0, sumB = 0;
//    for (int i = 0; text[i]; i++)
//    {
//        if (text[i] == pattern[1])
//        {
//            sumB++;
//            ans += sumA;
//        }
//        sumA += text[i] == pattern[0];
//    }
//    return ans + fmax(sumA, sumB);
//}
//
////2243. 计算字符串的数字和    
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//void exchange(char* s, int* summary, int* len)
//{
//    int m = *len, sum = *summary;
//    if (sum == 0)
//    {
//        s[m++] = '0';
//        *len = m;
//        return;
//    }
//    int left = m;
//    while (sum)
//    {
//        s[m++] = (sum % 10) | '0';
//        sum /= 10;
//    }
//    reverse(s, left, m - 1);
//    *len = m;  *summary = 0;
//}
//char* digitSum(char* s, int k)
//{
//    int n = strlen(s);
//    while (n > k)
//    {
//        int m = 0, sum = 0;
//        for (int i = 0; i < n; i++)
//        {
//            sum += s[i] & 15;
//            if ((i + 1) % k == 0)
//                exchange(s, &sum, &m);
//        }
//        if (n % k)
//            exchange(s, &sum, &m);
//        n = m;
//    }
//    s[n] = '\0';
//    return s;
//}
//
////2248. 多个数组求交集
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize)
//{
//    int cnt[1001] = { 0 };
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < numsColSize[i]; j++)
//        {
//            int x = nums[i][j];
//            if (cnt[x] == i)
//                cnt[x] = i + 1;
//        }
//    }
//    int* ans = (int*)malloc(sizeof(int) * numsColSize[0]);
//    *returnSize = 0;
//    for (int i = 0; i < numsColSize[0]; i++)
//    {
//        int x = nums[0][i];
//        if (cnt[x] == numsSize)
//            ans[(*returnSize)++] = x;
//    }
//    qsort(ans, (*returnSize), sizeof(int), cmp);
//    return ans;
//}
//
////1727. 重新排列后的最大子矩阵
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//}
//int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int height[n];
//    memset(height, 0, sizeof(height));
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            height[j] = matrix[i][j] ? height[j] + 1 : 0;
//        }
//        int copy[n];
//        memcpy(copy, height, sizeof(height));
//        qsort(copy, n, sizeof(int), cmp);
//        for (int k = 0; k < n && copy[k]; k++)
//        {
//            ans = fmax(ans, (k + 1) * copy[k]);
//        }
//    }
//    return ans;
//}
//
//int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    int height[n], idx[n], non_zeros[n];
//    memset(height, 0, sizeof(height));
//    for (int i = 0; i < n; i++) idx[i] = i;
//    int ans = 0;
//    for (int i = 0; i < m; i++)
//    {
//        int p = 0, q = 0;
//        for (int j = 0; j < n; j++)
//        {
//            int k = idx[j];
//            if (matrix[i][k] == 0)
//            {
//                height[k] = 0;
//                idx[p++] = k;
//            }
//            else
//            {
//                height[k]++;
//                non_zeros[q++] = k;
//            }
//        }
//
//        for (int j = p; j < n; j++)
//        {
//            idx[j] = non_zeros[j - p];
//            ans = fmax(ans, (n - j) * height[idx[j]]);
//        }
//    }
//    return ans;
//}
//
