////970. 强整数
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int* powerfulIntegers(int x, int y, int bound, int* returnSize)
//{
//    if (x == 1 || y == 1)
//    {
//        if (x + y == 2)
//        {
//            int* ans = (int*)malloc(sizeof(int));
//            *returnSize = 0;
//            if (bound >= 2)
//                ans[(*returnSize)++] = 2;
//            return ans;
//        }
//        x = fmax(x, y);
//        int* ans = (int*)malloc(sizeof(int) * 20);
//        int i = 0;
//        for (int k = 1; k < bound - 1; k *= x)
//        {
//            ans[i++] = k + 1;
//        }
//        *returnSize = i;
//        return ans;
//    }
//    int arr1[20], arr2[20];
//    int arr1Size = 0, arr2Size = 0;
//    for (int i = 1; i < bound; i *= x)
//    {
//        arr1[arr1Size++] = i;
//    }
//    for (int i = 1; i < bound; i *= y)
//    {
//        arr2[arr2Size++] = i;
//    }
//    HashItem* vis = NULL;
//    int* ans = (int*)malloc(sizeof(int) * arr1Size * arr2Size);
//    int idx = 0;
//    for (int i = 0; i < arr1Size; i++)
//    {
//        int j = arr2Size - 1;
//        while (arr2[j] + arr1[i] > bound)
//            j--;
//
//        for (int k = 0; k <= j; k++)
//        {
//            int x = arr2[k] + arr1[i];
//            HashItem* p1 = NULL;
//            HASH_FIND_INT(vis, &x, p1);
//            if (p1)
//                continue;
//
//            p1 = (HashItem*)malloc(sizeof(HashItem));
//            p1->key = x;
//            HASH_ADD_INT(vis, key, p1);
//            ans[idx++] = x;
//        }
//    }
//    HashItem* cur = NULL, * tmp = NULL;
//    HASH_ITER(hh, vis, cur, tmp)
//    {
//        HASH_DEL(vis, cur);
//        free(cur);
//    }
//    *returnSize = idx;
//    return ans;
//}
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    UT_hash_handle hh;
//}HashItem;
//int* powerfulIntegers(int x, int y, int bound, int* returnSize)
//{
//    HashItem* vis = NULL;
//    int n = 0;
//    for (int i = 1; i < bound; i *= x)
//    {
//        for (int j = 1; j <= bound - i; j *= y)
//        {
//            int x = i + j;
//            HashItem* p1 = NULL;
//            HASH_FIND_INT(vis, &x, p1);
//            if (p1 == NULL)
//            {
//                p1 = (HashItem*)malloc(sizeof(HashItem));
//                p1->key = x;
//                HASH_ADD_INT(vis, key, p1);
//                n++;
//            }
//            if (y == 1) break;
//        }
//        if (x == 1) break;
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    *returnSize = 0;
//    HashItem* cur = NULL, * tmp = NULL;
//    HASH_ITER(hh, vis, cur, tmp)
//    {
//        ans[(*returnSize)++] = cur->key;
//        HASH_DEL(vis, cur);
//        free(cur);
//    }
//    return ans;
//}
//
////799. 香槟塔    
//
//double champagneTower(int poured, int query_row, int query_glass)
//{
//    int n = query_row, m = query_glass;
//    double f[n + 2][n + 2];
//    memset(f, 0, sizeof(f));
//    f[0][0] = poured;
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            if (f[i][j] <= 1) continue;
//            double x = (f[i][j] - 1) / 2.0;
//            f[i + 1][j] += x;
//            f[i + 1][j + 1] += x;
//        }
//    }
//    return fmin(f[n][m], 1);
//}
//
////830. 较大分组的位置
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes)
//{
//    int n = strlen(s);
//    int** ans = (int**)malloc(sizeof(int*) * (n / 3));
//    *returnColumnSizes = (int*)malloc(sizeof(int) * (n / 3));
//    char cur = 0;
//    int left = -1, ansSize = 0;
//    for (int i = 0; i <= n; i++)
//    {
//        if (i == n || cur != s[i])
//        {
//            if (i - left >= 3)
//            {
//                ans[ansSize] = (int*)malloc(sizeof(int) * 2);
//                ans[ansSize][0] = left, ans[ansSize][1] = i - 1;
//                (*returnColumnSizes)[ansSize++] = 2;
//            }
//            cur = s[i];
//            left = i;
//        }
//    }
//    *returnSize = ansSize;
//    return ans;
//}
//
////848. 字母移位
//
//char* shiftingLetters(char* s, int* shifts, int shiftsSize)
//{
//    for (int i = shiftsSize - 2; i >= 0; i--)
//    {
//        shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
//    }
//    for (int i = 0; i < shiftsSize; i++)
//    {
//        s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
//    }
//    return s;
//}
//
