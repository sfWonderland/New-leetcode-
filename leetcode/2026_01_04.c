////3798. 最大的偶数
//
//char* largestEven(char* s)
//{
//    int end = 0;
//    for (int i = 0; s[i]; i++)
//    {
//        if (s[i] & 1)
//            continue;
//
//        end = i + 1;
//    }
//    s[end] = '\0';
//    return s;
//}
//
////3799. 单词方块 II    
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    char** a = *(char***)e1;
//    char** b = *(char***)e2;
//    for (int i = 0; i < 4; i++)
//    {
//        int ans = strcmp(a[i], b[i]);
//        if (ans)
//            return ans;
//    }
//    return -1;
//}
//char*** wordSquares(char** words, int wordsSize, int* returnSize, int** returnColumnSizes)
//{
//    char*** ans = (char***)malloc(sizeof(char**) * 100001);
//    int ansSize = 0;
//    for (int i = 0; i < wordsSize; i++)
//    {
//        int top0 = words[i][0], top3 = words[i][3];
//        for (int j = 0; j < wordsSize; j++)
//        {
//            if (j == i || top0 != words[j][0])
//                continue;
//            int left3 = words[j][3];
//            for (int k = 0; k < wordsSize; k++)
//            {
//                if (k == i || k == j || words[k][0] != top3)
//                    continue;
//                int right3 = words[k][3];
//                for (int l = 0; l < wordsSize; l++)
//                {
//                    if (l == i || l == j || l == k || words[l][0] != left3 || words[l][3] != right3)
//                        continue;
//
//                    ans[ansSize] = (char**)malloc(sizeof(char*) * 4);
//                    ans[ansSize][0] = words[i];
//                    ans[ansSize][1] = words[j];
//                    ans[ansSize][2] = words[k];
//                    ans[ansSize++][3] = words[l];
//                }
//            }
//        }
//    }
//    qsort(ans, ansSize, sizeof(char**), cmp);
//    *returnSize = ansSize;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * ansSize);
//    for (int i = 0; i < ansSize; i++)
//    {
//        (*returnColumnSizes)[i] = 4;
//    }
//    return ans;
//}
//
////3800. 使二进制字符串相等的最小成本
//
//// flip : base 仅限s[i] != t[i]
//// cross : flip * 2 仅限s[i] != t[i]
//// swap : flip * 2 仅限s[i] != t[j] && s[i] != t[i] && s[j] != t[j]
//// cross 是使 s 和 t 之间 1 的差减少2， swap则不改变， 如果二者1的个数差值为个数，仍至少flip一次
//long long minimumCost(char* s, char* t, int flipCost, int swapCost, int crossCost)
//{
//    int diff = 0; // 由swap或flip来修正
//    int ones = 0; // 由cross来平衡
//    int n = strlen(s);
//    for (int i = 0; i < n; i++)
//    {
//        diff += abs(s[i] - t[i]);
//        ones += s[i] - t[i];
//    }
//    ones = abs(ones);
//    int zero_diff = diff - ones / 2 * 2;
//    swapCost = fmin(2 * flipCost, swapCost);
//    crossCost = fmin(2 * flipCost, crossCost);
//    long long ans = 1ll * fmin(swapCost + crossCost, 2 * flipCost) * (ones / 2);
//    ans += 1ll * swapCost * (zero_diff / 2);
//    if (diff & 1)
//        ans += flipCost;
//    return ans;
//}
//
////2249. 统计圆内格点数目
//
//int cmp(const void* e1, const void* e2)
//{
//    return (*(int**)e2)[2] - (*(int**)e1)[2];
//}
//int countLatticePoints(int** circles, int circlesSize, int* circlesColSize)
//{
//    qsort(circles, circlesSize, sizeof(int*), cmp);
//    int ans = 0;
//    int min_x = 201, max_x = -1;
//    int min_y = 201, max_y = -1;
//    for (int i = 0; i < circlesSize; i++)
//    {
//        int x = circles[i][0], y = circles[i][1], r = circles[i][2];
//        min_x = fmin(min_x, x - r);
//        min_y = fmin(min_y, y - r);
//        max_x = fmax(max_x, x + r);
//        max_y = fmax(max_y, y + r);
//    }
//    for (int x = min_x; x <= max_x; x++)
//    {
//        for (int y = min_y; y <= max_y; y++)
//        {
//            for (int i = 0; i < circlesSize; i++)
//            {
//                int* c = circles[i];
//                if ((c[0] - x) * (c[0] - x) + (c[1] - y) * (c[1] - y) <= c[2] * c[2])
//                {
//                    ans++;
//                    break;
//                }
//            }
//        }
//    }
//    return ans;
//}
//
