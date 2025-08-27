////LCR 145. 判断对称二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* l, struct TreeNode* r)
//{
//    if (l == NULL && r == NULL)
//        return true;
//    if (!l || !r)
//        return false;
//
//    return l->val == r->val ? dfs(l->right, r->left) && dfs(l->left, r->right) : false;
//}
//bool checkSymmetricTree(struct TreeNode* root)
//{
//    if (!root) return true;
//    return dfs(root->left, root->right);
//}
//
////LCR 176. 判断是否为平衡二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    int l = dfs(node->left), r = dfs(node->right);
//    return abs(l - r) > 1 ? -10000 : fmax(l, r) + 1;
//}
//bool isBalanced(struct TreeNode* root)
//{
//    return dfs(root) >= 0;
//}
//
////LCR 166. 珠宝的最高价值
//
//int dfs(int i, int j, int** frame)
//{
//    if (i == 0 && j == 0)
//        return frame[0][0];
//
//    if (i < 0 || j < 0)
//        return INT_MIN / 2;
//
//    return fmax(dfs(i - 1, j, frame), dfs(i, j - 1, frame)) + frame[i][j];
//}
//int jewelleryValue(int** frame, int frameSize, int* frameColSize)
//{
//    return dfs(frameSize - 1, frameColSize[0] - 1, frame);
//}
//
//int jewelleryValue(int** frame, int frameSize, int* frameColSize)
//{
//    int m = frameSize, n = frameColSize[0];
//    int f[m + 1][n + 1];
//    for (int i = 0; i < m + 1; i++)
//    {
//        f[i][0] = INT_MIN / 2;
//    }
//    for (int i = 0; i < n + 1; i++)
//    {
//        f[0][i] = INT_MIN / 2;
//    }
//    f[0][1] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[i + 1][j + 1] = fmax(f[i][j + 1], f[i + 1][j]) + frame[i][j];
//        }
//    }
//    return f[m][n];
//}
//
//int jewelleryValue(int** frame, int frameSize, int* frameColSize)
//{
//    int m = frameSize, n = frameColSize[0];
//    int f[n + 1];
//    for (int i = 1; i < n + 1; i++)
//    {
//        f[i] = INT_MIN / 2;
//    }
//    f[0] = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            f[j + 1] = fmax(f[j + 1], f[j]) + frame[i][j];
//        }
//    }
//    return f[n];
//}
//
////LCR 165. 解密数字
//
//int crackNumber(int ciphertext)
//{
//    int a = 1, b = 1, x, y = ciphertext % 10; //a = f[i - 1], b = f[i - 2];
//    while (ciphertext > 9)
//    {
//        ciphertext /= 10;
//        x = ciphertext % 10;
//        int tmp = x * 10 + y;
//        int c = tmp > 9 && tmp < 26 ? a + b : a;
//        b = a;
//        a = c;
//        y = x;
//    }
//    return a;
//}
//
