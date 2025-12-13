////559. N 叉树的最大深度
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     int numChildren;
// *     struct Node** children;
// * };
// */
//int dfs(struct Node* node)
//{
//    if (node == NULL)
//        return 0;
//
//    int max = 0;
//    for (int i = 0; i < node->numChildren; i++)
//    {
//        int depth = dfs(node->children[i]);
//        max = fmax(max, depth);
//    }
//    return max + 1;
//}
//int maxDepth(struct Node* root)
//{
//    return dfs(root);
//}
//
////566. 重塑矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
//{
//    int m = matSize, n = matColSize[0];
//    if (r * c != m * n)
//    {
//        *returnSize = m;
//        *returnColumnSizes = (int*)malloc(sizeof(int) * m);
//        for (int i = 0; i < m; i++)
//        {
//            (*returnColumnSizes)[i] = n;
//        }
//        return mat;
//    }
//    int** ans = (int**)malloc(sizeof(int*) * r);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
//    for (int i = 0; i < r; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * c);
//        (*returnColumnSizes)[i] = c;
//    }
//    int cnt = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            ans[cnt / c][cnt % c] = mat[i][j];
//            cnt++;
//        }
//    }
//    *returnSize = r;
//    return ans;
//}
//
////492. 构造矩形
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
// // 牛顿迭代法
// // 利用f(x) = x ^ 2 ? n 函数切线与x 轴交点，不断逼近f(x) = 0的根，从而求得平方根。
// // 切线方程为
// // y = f(xk)+f′(xk)(x?xk)
// // y = 0, x = xk - f(xk) / f'(xk);
// // 代入f(x) = x ^ 2 - n, 得到x(k + 1) = x(k) - x(k) / 2 + n / 2 / x(k);
// // 即x(k + 1) = (x(k) + n / x(k)) / 2;
//int* constructRectangle(int area, int* returnSize)
//{
//    double eps = 1e-8;
//    double pre = 0, cur = area;
//    while (abs(pre - cur) > eps)
//    {
//        pre = cur;
//        cur = (cur + area / cur) / 2;
//    }
//    int sqrt = cur;
//    while (area % sqrt)
//        sqrt--;
//
//    *returnSize = 2;
//    int* ans = (int*)malloc(sizeof(int) * 2);
//    ans[0] = area / sqrt; ans[1] = sqrt;
//    return ans;
//}
//
////824. 山羊拉丁文
//
//char* toGoatLatin(char* sentence)
//{
//    // 方便判断字母是否为元音字母
//    bool vowels[256] = { 0 };
//    vowels['a'] = 1; vowels['e'] = 1; vowels['i'] = 1; vowels['o'] = 1; vowels['u'] = 1;
//    vowels['A'] = 1; vowels['E'] = 1; vowels['I'] = 1; vowels['O'] = 1; vowels['U'] = 1;
//
//    // 最坏情况：全是单个字母的单词，总和75（字母） + 74（空格） + 75（m） + （76 + 2）* 75 / 2（a)
//    // 总计 42 * 75 - 1 = 3149
//    char* ans = (char*)malloc(sizeof(char) * 3200);
//    int n = strlen(sentence), cnt = 1, pos = 0; // cnt : a的个数
//    for (int i = 0; i < n; )
//    {
//        // 找到单词末尾
//        int j = i;
//        while (j < n && sentence[j] != ' ')
//            j++;
//
//        // 加上空格
//        cnt++;
//        if (cnt > 2)
//            ans[pos++] = ' ';
//
//        // 根据首字母是否为元音字母，调整单词位置加入返回字符串
//        if (vowels[sentence[i]])
//        {
//            memcpy(ans + pos, sentence + i, sizeof(char) * (j - i));
//            pos += j - i;
//        }
//        else
//        {
//            memcpy(ans + pos, sentence + i + 1, sizeof(char) * (j - i - 1));
//            pos += j - i - 1;
//            ans[pos++] = sentence[i];
//        }
//
//        // 加入山羊拉丁文
//        ans[pos++] = 'm';
//        memset(ans + pos, 'a', sizeof(char) * cnt);
//        pos += cnt;
//
//        // 准备下一个循环
//        i = j + 1;
//    }
//
//    ans[pos] = '\0';
//    return ans;
//}
//
