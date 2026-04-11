////3898. 统计每个顶点的度
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
//{
//    int n = matrixSize, m = matrixColSize[0];
//    int* ans = (int*)calloc(sizeof(int), n);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            ans[i] += matrix[i][j];
//    }
//    *returnSize = n;
//    return ans;
//}
//
////3899. 三角形的内角度数    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void swap(double* a, double* b)
//{
//    double tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//double* internalAngles(int* sides, int sidesSize, int* returnSize)
//{
//    *returnSize = 0;
//    int a = sides[0], b = sides[1], c = sides[2];
//    if (a + b <= c || a + c <= b || b + c <= a)
//        return NULL;
//
//    double* ans = (double*)malloc(sizeof(double) * 3);
//    double sum = a * a + b * b + c * c;
//    double multi = a * b * c;
//    for (int i = 0; i < 3; i++)
//    {
//        double cosA = (sum - sides[i] * sides[i] * 2.0) / (multi / sides[i] * 2);
//        // printf("%lf ", cosA);
//        ans[i] = acos(cosA) * 180 / M_PI;
//    }
//    if (ans[0] > ans[1])
//        swap(&ans[0], &ans[1]);
//    if (ans[0] > ans[2])
//        swap(&ans[0], &ans[2]);
//    if (ans[1] > ans[2])
//        swap(&ans[1], &ans[2]);
//    *returnSize = 3;
//    return ans;
//}
//
////3900. 一次交换后的最长平衡子串
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int f(char* s, int n)
//{
//    HashItem* idx = NULL;
//    HashItem* p = (HashItem*)malloc(sizeof(HashItem));
//    p->key = 0;
//    p->val = -1;
//    HASH_ADD_INT(idx, key, p);
//    int suf_ones = 0, suf_zeros = 0;
//    for (int i = 0; i < n; i++)
//    {
//        suf_ones += s[i] - '0';
//        suf_zeros += '1' - s[i];
//    }
//    if (suf_ones == 0 || suf_zeros == 0)
//        return 0;
//    int ones = 0, zeros = 0, ans = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] & 1)
//            ones++;
//        else
//            zeros++;
//        int d = ones - zeros;
//        if (suf_zeros > zeros)
//        {
//            int d1 = d - 2;
//            HASH_FIND_INT(idx, &d1, p);
//            if (p)
//            {
//                int j = p->val;
//                ans = fmax(i - j, ans);
//            }
//        }
//        if (suf_ones > ones)
//        {
//            int d1 = d + 2;
//            HASH_FIND_INT(idx, &d1, p);
//            if (p)
//            {
//                int j = p->val;
//                ans = fmax(i - j, ans);
//            }
//        }
//        HASH_FIND_INT(idx, &d, p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = d;
//            p->val = i;
//            HASH_ADD_INT(idx, key, p);
//        }
//        else
//        {
//            int j = p->val;
//            ans = fmax(i - j, ans);
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, idx, p, tmp)
//    {
//        HASH_DEL(idx, p);
//        free(p);
//    }
//    return ans;
//}
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//int longestBalanced(char* s)
//{
//    int n = strlen(s);
//    int ans = f(s, n);
//    reverse(s, 0, n - 1);
//    ans = fmax(ans, f(s, n));
//    return ans;
//}
//
////LCR 011. 连续数组
//
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//int findMaxLength(int* nums, int numsSize)
//{
//    HashItem* idx = NULL;
//    HashItem* p = (HashItem*)malloc(sizeof(HashItem));
//    p->key = 0;
//    p->val = -1;
//    HASH_ADD_INT(idx, key, p);
//    int d = 0, ans = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        d += nums[i] ? 1 : -1;
//        HASH_FIND_INT(idx, &d, p);
//        if (p == NULL)
//        {
//            p = (HashItem*)malloc(sizeof(HashItem));
//            p->key = d;
//            p->val = i;
//            HASH_ADD_INT(idx, key, p);
//        }
//        else
//        {
//            int j = p->val;
//            ans = fmax(i - j, ans);
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, idx, p, tmp)
//    {
//        HASH_DEL(idx, p);
//        free(p);
//    }
//    return ans;
//}
//
