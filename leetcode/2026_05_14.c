//// 面试题 08.06. 汉诺塔问题
//
//void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize)
//{
//    *CSize = ASize;
//    *C = (int*)malloc(sizeof(int) * ASize);
//    B = (int*)malloc(sizeof(int) * ASize);
//    void move(int a, int* A, int* B, int* C)
//    {
//        if (a == 1)
//        {
//            C[0] = A[0];
//            return;
//        }
//
//        move(a - 1, A, C, B); // A -> B
//        C[a - 1] = A[a - 1];
//        move(a - 1, B, A, C); // B -> C
//    }
//    move(ASize, A, B, *C);
//}
//
//// 面试题 08.08. 有重复字符串的排列组合  
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//void trace(char** ans, char* S, int n, char* path, int k, int* ansSize)
//{
//    if (k == n)
//    {
//        path[n] = '\0';
//        ans[*ansSize] = (char*)malloc(sizeof(char) * (n + 1));
//        strcpy(ans[*ansSize], path);
//        (*ansSize)++;
//        return;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (S[i] == 0 || i > 0 && S[i] == S[i - 1])
//            continue;
//        path[k] = S[i];
//        char tmp = S[i];
//        S[i] = '\0';
//        trace(ans, S, n, path, k + 1, ansSize);
//        S[i] = tmp;
//    }
//}
//char** permutation(char* S, int* returnSize)
//{
//    int n = strlen(S);
//    int m = 1;
//    int tmp = n;
//    while (tmp)
//    {
//        m *= tmp--;
//    }
//    qsort(S, n, sizeof(char), cmp);
//    char** ans = (char**)malloc(sizeof(char*) * m);
//    char* path = (char*)malloc(sizeof(char) * (n + 1));
//    *returnSize = 0;
//    trace(ans, S, n, path, 0, returnSize);
//    return ans;
//}
//
//// 面试题 08.10. 颜色填充
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//void dfs(int** image, int m, int n, int x, int y, int c, int new_c)
//{
//    image[x][y] = new_c;
//    for (int i = 0; i < 4; i++)
//    {
//        int mx = dir[i][0] + x;
//        int my = dir[i][1] + y;
//        if (mx < 0 || mx >= m || my < 0 || my >= n || image[mx][my] != c)
//            continue;
//        dfs(image, m, n, mx, my, c, new_c);
//    }
//}
//int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = imageSize;
//    *returnColumnSizes = imageColSize;
//    if (image[sr][sc] == newColor)
//        return image;
//    dfs(image, imageSize, imageColSize[0], sr, sc, image[sr][sc], newColor);
//
//    return image;
//}
//
//// 面试题 08.11. 硬币
//
//#define MOD 1000000007
//const int cents[4] = { 25, 10, 5, 1 };
//int waysToChange(int n)
//{
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int cent = cents[i];
//        for (int j = cent; j <= n; j++)
//        {
//            f[j] = (f[j] + f[j - cent]) % MOD;
//        }
//    }
//    return f[n];
//}
//
//#define MOD 1000000007
//const int cents[4] = { 25, 10, 5, 1 };
//int waysToChange(int n)
//{
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[0] = 1;
//    for (int i = 0; i < 4; i++)
//    {
//        int cent = cents[i];
//        for (int j = cent; j <= n; j++)
//        {
//            f[j] = (f[j] + f[j - cent]) % MOD;
//        }
//    }
//    return f[n];
//}
//
//#define MOD 1000000007
//int waysToChange(int n)
//{
//    int ans = 0;
//    for (int i = 0; i * 25 <= n; i++)
//    {
//        int rest = n - 25 * i;
//        int a = rest / 10;
//        int b = rest % 10 / 5;
//        ans = (ans + 1ll * (a + 1) * (a + b + 1)) % MOD;
//    }
//    return ans;
//}
//
