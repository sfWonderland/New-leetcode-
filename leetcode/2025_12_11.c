////3531. 统计被覆盖的建筑
//
//int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize)
//{
//    int* row_min = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        row_min[i] = n + 1;
//    }
//    int* row_max = (int*)calloc(sizeof(int), n + 1);
//    int* col_min = (int*)malloc(sizeof(int) * (n + 1));
//    for (int i = 0; i < n; i++)
//    {
//        col_min[i] = n + 1;
//    }
//    int* col_max = (int*)calloc(sizeof(int), n + 1);
//
//    for (int i = 0; i < buildingsSize; i++)
//    {
//        int x = buildings[i][0];
//        int y = buildings[i][1];
//        row_min[y] = fmin(row_min[y], x);
//        row_max[y] = fmax(row_max[y], x);
//        col_min[x] = fmin(col_min[x], y);
//        col_max[x] = fmax(col_max[x], y);
//    }
//
//    int ans = 0;
//    for (int i = 0; i < buildingsSize; i++)
//    {
//        int x = buildings[i][0];
//        int y = buildings[i][1];
//        if (x > row_min[y] && x < row_max[y] && y > col_min[x] && y < col_max[x])
//            ans++;
//    }
//    return ans;
//}
//
////1002. 查找共用字符
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** commonChars(char** words, int wordsSize, int* returnSize)
//{
//    int n = wordsSize;
//    int cnt[n][26];
//    memset(cnt, 0, sizeof(cnt));
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int m = strlen(words[i]);
//        for (int j = 0; j < m; j++)
//        {
//            cnt[i][words[i][j] - 'a']++;
//        }
//        sum += m;
//    }
//    char** ans = (char**)malloc(sizeof(char*) * sum);
//    int k = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        int m = 100;
//        for (int j = 0; j < n; j++)
//        {
//            m = fmin(m, cnt[j][i]);
//        }
//        for (int j = 0; j < m; j++)
//        {
//            ans[k] = (char*)malloc(sizeof(char) * 2);
//            ans[k][0] = i + 'a';
//            ans[k++][1] = '\0';
//        }
//    }
//    *returnSize = k;
//    return ans;
//}
//
////1200. 最小绝对差
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
//int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
//{
//    qsort(arr, arrSize, sizeof(int), cmp);
//    int d = 2000000, n = 0;
//    for (int i = 1; i < arrSize; i++)
//    {
//        int x = arr[i] - arr[i - 1];
//        if (x < d)
//        {
//            d = x;
//            n = 1;
//        }
//        else if (x == d)
//            n++;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    int k = 0;
//    for (int i = 1; i < arrSize; i++)
//    {
//        int x = arr[i] - arr[i - 1];
//        if (x == d)
//        {
//            ans[k] = (int*)malloc(sizeof(int) * 2);
//            ans[k][0] = arr[i - 1];
//            ans[k][1] = arr[i];
//            (*returnColumnSizes)[k++] = 2;
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////1636. 按照频率将数组升序排序
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* cnt;
//int cmp(const void* e1, const void* e2)
//{
//    int a = *(int*)e1;
//    int b = *(int*)e2;
//    return cnt[a + 100] == cnt[b + 100] ? b - a : cnt[a + 100] - cnt[b + 100];
//}
//int* frequencySort(int* nums, int numsSize, int* returnSize)
//{
//    cnt = (int*)calloc(sizeof(int), 201);
//    for (int i = 0; i < numsSize; i++)
//    {
//        cnt[nums[i] + 100]++;
//    }
//    qsort(nums, numsSize, sizeof(int), cmp);
//    *returnSize = numsSize;
//    return nums;
//}
//
