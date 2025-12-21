////960. 删列造序 III
//
//int minDeletionSize(char** strs, int strsSize)
//{
//    int m = strlen(strs[0]), n = strsSize;
//    int f[m];
//    memset(f, 0, sizeof(int) * m);
//    int max = 1;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (f[j] > f[i])
//            {
//                bool flag = true;
//                for (int k = 0; k < n && flag; k++)
//                {
//                    if (strs[k][i] < strs[k][j])
//                        flag = false;
//                }
//                if (flag)
//                    f[i] = f[j];
//            }
//        }
//        f[i]++;
//        max = fmax(max, f[i]);
//    }
//    return m - max;
//}
//
////187. 重复的DNA序列
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//typedef struct
//{
//    int key;
//    int val;
//    UT_hash_handle hh;
//}HashItem;
//const char code[26] = { 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 };
//const char decode[4] = { 'A', 'C', 'G', 'T' };
//char** findRepeatedDnaSequences(char* s, int* returnSize)
//{
//    HashItem* cnt = NULL;
//    HashItem* pEntry = NULL;
//    int n = strlen(s), x = 0, num = 0;
//    for (int i = 0; i < n; i++)
//    {
//        // 位运算哈希表， A1，C2，G3，T4，一个字母占两位
//        x = (x << 2) | code[s[i] - 'A'];
//        if (i < 9)
//            continue;
//        // 位与1 << 20 - 1，只保留后20位。
//        x &= ((1 << 20) - 1);
//
//        HASH_FIND_INT(cnt, &x, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = x;
//            pEntry->val = 1;
//            HASH_ADD_INT(cnt, key, pEntry);
//        }
//        else
//            pEntry->val++;
//
//        if (pEntry->val == 2)
//            num++;
//    }
//    HashItem* tmp = NULL;
//    char** ans = (char**)malloc(sizeof(char*) * num);
//    *returnSize = 0;
//    HASH_ITER(hh, cnt, pEntry, tmp)
//    {
//        int x = pEntry->key;
//        int n = pEntry->val;
//        free(pEntry);
//        if (n == 1)
//            continue;
//        ans[*returnSize] = (char*)malloc(sizeof(char) * 11);
//        for (int i = 0; i < 10; i++)
//        {
//            char c = decode[x & 3];
//            x >>= 2;
//            ans[*returnSize][9 - i] = c;
//        }
//        ans[(*returnSize)++][10] = '\0';
//    }
//    return ans;
//}
//
////365. 水壶问题
//
//int gcd(int a, int b)
//{
//    while (b)
//    {
//        int tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//    return a;
//}
//
//// 目标水量必须比两桶容积之和小，否则无法达到目标值
//
//// 所有可能操作：
//// 1.把一个桶x/y倒空，里面水可能是满的，也可能是不满的；
//// 2.把一个桶x/y倒满水，里面水可能是满的，也可能是不满的；
//// 3.把一个桶x/y倒的水倒到另一桶y/x里，两桶水量不确定，但最多把x/y桶倒空，或者把y/x倒满;
//
//// 有三种不可能情况：
//// 1. 使两个桶都有水且不满，每次操作都至少使一个桶的水是满的。即最多一个桶有水且不满。
//// 2. 往没满的桶里倒水，这会留下两个满水或是一个满水一个空的情况，等同于在初始状态下把一个或两个桶装满水
//// 3. 把没满的桶里的水倒掉，这会留下两个空桶或是一个满水一个空的情况，等于初始状态或是把一个桶开始时倒满
//
//// 排除不可能情况，获得所有可能情况：
//// 1.把一个桶x/y倒空，倒水前桶x/y是空的；
//// 2.把一个桶x/y倒满水，倒水前桶x/y是满的；
//// 3.把一个桶x/y倒的水倒到另一桶y/x里，倒水前桶x/y是满的，桶y/x是空的;
//
//// 每次操作的总水量变化为0，x，y。
//
//// 由此可以采用《贝祖原理》解决问题
//// ax + by = z, z必为a , b的最大公因数的倍数
//// a >= 0, b >= 0 情况为1.全空；2.满某一桶；3.两桶全满。以上情况一定成立。
//// a < 0 或 b < 0，实际操作就是把一个桶x倒满，把满桶的水倒进空桶y内，把倒过去满了的桶y倒掉
//// 操作(a + b)次后，就是变化了ax + by的水量
//// 根据贝祖原理，只要target是a，b的最大公因数的倍数，则成立，否则不成立。
//bool canMeasureWater(int x, int y, int target)
//{
//    if (x + y < target)
//        return false;
//
//    return target % gcd(x, y) == 0;
//}
//
////1260. 二维网格迁移
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    for (int i = 0; i < m; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//    }
//    for (; k > 0; k--)
//    {
//        int pre = grid[m - 1][n - 1];
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                int tmp = grid[i][j];
//                grid[i][j] = pre;
//                pre = tmp;
//            }
//        }
//    }
//    *returnSize = m;
//    return grid;
//}
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m = gridSize, n = gridColSize[0];
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//    int** ans = (int**)malloc(sizeof(int*) * m);
//    for (int i = 0; i < m; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * n);
//        (*returnColumnSizes)[i] = n;
//    }
//    k = k % (m * n);
//    int sum = k;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int row = sum / n, col = sum % n;
//            ans[row][col] = grid[i][j];
//            sum = (sum + 1) % (m * n);
//        }
//    }
//    *returnSize = m;
//    return ans;
//}
//
