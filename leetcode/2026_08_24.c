//// 1268. ËÑË÷ÍÆ¼öÏµÍ³
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return strcmp(*(char**)e1, *(char**)e2);
//}
//char*** suggestedProducts(char** products, int productsSize, char* searchWord, int* returnSize, int** returnColumnSizes)
//{
//    int n = productsSize;
//    qsort(products, n, sizeof(char*), cmp);
//    int cnt[n];
//    memset(cnt, 0, sizeof(cnt));
//    int m = strlen(searchWord);
//    for (int i = 0; i < m; i++)
//    {
//        char c = searchWord[i];
//        for (int j = 0; j < n; j++)
//        {
//            if (cnt[j] < i || products[j][i] != c) continue;
//            cnt[j]++;
//        }
//    }
//    char*** ans = (char***)malloc(sizeof(char**) * m);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (char**)malloc(sizeof(char*) * 3);
//        int len = 0;
//        for (int j = 0; j < n && len < 3; j++)
//        {
//            if (cnt[j] <= i) continue;
//            ans[i][len++] = products[j];
//        }
//        (*returnColumnSizes)[i] = len;
//    }
//    *returnSize = m;
//    return ans;
//}
//
