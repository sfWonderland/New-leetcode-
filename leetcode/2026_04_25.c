//// LCR 082. 组合总和 II
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* len;
//
//int* path;
//int pathSize;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//void backtrack(int* nums, int n, int x, int i)
//{
//    if (x < 0)
//        return;
//
//    if (x == 0)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * pathSize);
//        memcpy(ans[ansSize], path, sizeof(int) * pathSize);
//        len[ansSize++] = pathSize;
//        return;
//    }
//
//    for (int j = i; j < n; )
//    {
//        int y = nums[j];
//        x -= y;
//        path[pathSize++] = y;
//        backtrack(nums, n, x, j + 1);
//        pathSize--;
//        x += y;
//        j++;
//        while (j < n && nums[j] == y)
//        {
//            j++;
//        }
//    }
//}
//
//int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
//{
//    qsort(candidates, candidatesSize, sizeof(int), cmp);
//    pathSize = ansSize = 0;
//    ans = (int**)malloc(sizeof(int*) * 500);
//    len = (int*)malloc(sizeof(int) * 500);
//    path = (int*)malloc(sizeof(int) * candidatesSize);
//
//    backtrack(candidates, candidatesSize, target, 0);
//
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
//// LCR 084. 全排列 II 
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** ans;
//int ansSize;
//int* len;
//
//int* path;
//int pathSize;
//
//bool* vis;
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//void backtrack(int* nums, int n, int i)
//{
//    if (i == n)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * pathSize);
//        memcpy(ans[ansSize], path, sizeof(int) * pathSize);
//        len[ansSize++] = pathSize;
//        return;
//    }
//
//    for (int j = 0; j < n; j++)
//    {
//        if (vis[j] || (j > 0 && nums[j - 1] == nums[j] && !vis[j - 1]))
//            continue;
//
//        path[pathSize++] = nums[j];
//        vis[j] = true;
//        backtrack(nums, n, i + 1);
//        vis[j] = false;
//        pathSize--;
//    }
//}
//
//int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    qsort(nums, numsSize, sizeof(int), cmp);
//    pathSize = ansSize = 0;
//    ans = (int**)malloc(sizeof(int*) * 5000);
//    len = (int*)malloc(sizeof(int) * 5000);
//    path = (int*)malloc(sizeof(int) * numsSize);
//    vis = (bool*)calloc(sizeof(bool), numsSize);
//
//    backtrack(nums, numsSize, 0);
//
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
//// LCR 087. 复原 IP 地址
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//bool valid(char* s, int left, int right)
//{
//    int n = right - left;
//    if (n > 3 || (n > 1 && s[left] == '0'))
//        return false;
//    char tmp = s[right];
//    s[right] = '\0';
//    int x = atoi(s + left);
//    s[right] = tmp;
//    return x <= 255;
//}
//
//void substr(char* dest, char* sr, int* pos, int left, int right)
//{
//    int i = *pos;
//    for (int j = left; j < right; j++)
//    {
//        dest[i++] = sr[j];
//    }
//    *pos = i;
//}
//
//char** restoreIpAddresses(char* s, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * 1000);
//    int ansSize = 0, n = strlen(s);
//    for (int i = 1; i < n && valid(s, 0, i); i++)
//    {
//        for (int j = i + 1; j < n && valid(s, i, j); j++)
//        {
//            for (int k = j + 1; k < n && valid(s, j, k); k++)
//            {
//                if (valid(s, k, n))
//                {
//                    ans[ansSize] = (char*)malloc(sizeof(char) * (n + 4));
//                    int pos = 0;
//                    substr(ans[ansSize], s, &pos, 0, i);
//                    ans[ansSize][pos++] = '.';
//                    substr(ans[ansSize], s, &pos, i, j);
//                    ans[ansSize][pos++] = '.';
//                    substr(ans[ansSize], s, &pos, j, k);
//                    ans[ansSize][pos++] = '.';
//                    substr(ans[ansSize], s, &pos, k, n);
//                    ans[ansSize++][pos++] = '\0';
//                }
//            }
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
//// LCR 088. 使用最小花费爬楼梯
//
//int minCostClimbingStairs(int* cost, int costSize)
//{
//    int f[3] = { 0 };
//    f[0] = f[1] = 0;
//    for (int i = 0; i < costSize; i++)
//    {
//        f[2] = fmin(f[0], f[1]) + cost[i];
//        f[0] = f[1];
//        f[1] = f[2];
//    }
//    return fmin(f[0], f[1]);
//}
//
