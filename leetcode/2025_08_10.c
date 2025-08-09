////869. 重新排序得到 2 的幂
//
//int search[9][4] = {
//                    {1, 2, 4, 8},
//                    {16, 32, 64, 0},
//                    {128, 256, 512, 0},
//                    {1024, 2048, 4096, 8192},
//                    {16384, 32768, 65536, 0},
//                    {131072, 262144, 524288, 0},
//                    {1048576, 2097152, 4194304, 8388608},
//                    {16777216, 33554432, 67108864, 0},
//                    {134217728, 268435456, 536870912, 0}
//};
//bool reorderedPowerOf2(int n)
//{
//    char digit[10] = { 0 };
//    int cnt = -1;
//    while (n)
//    {
//        digit[n % 10]++;
//        cnt++;
//        n /= 10;
//    }
//    if (cnt > 8)
//        return false;
//    for (int i = 0; i < 4 && search[cnt][i]; i++)
//    {
//        char tmp[10] = { 0 };
//        int m = search[cnt][i];
//        while (m)
//        {
//            tmp[m % 10]++;
//            m /= 10;
//        }
//        if (memcmp(tmp, digit, 10) == 0)
//            return true;
//    }
//    return false;
//}
//
////1080. 根到叶路径上的不足节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* node, int limit)
//{
//    if (node == NULL)
//        return true;
//    if (node->left == NULL && node->right == NULL)
//        return limit - node->val > 0;
//
//    int n = node->val;
//    bool l = dfs(node->left, limit - n);
//    bool r = dfs(node->right, limit - n);
//    if (l) node->left = NULL;
//    if (r) node->right = NULL;
//    return l && r;
//}
//struct TreeNode* sufficientSubset(struct TreeNode* root, int limit)
//{
//    if (dfs(root, limit))
//        return NULL;
//
//    return root;
//}
//
////1372. 二叉树中的最长交错路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int max;
//void dfs(struct TreeNode* node, int left, int right) //orient : 0 -> left, 1 -> right
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left, 0, left + 1);
//    dfs(node->right, right + 1, 0);
//    max = fmax(left + right, max);
//}
//int longestZigZag(struct TreeNode* root)
//{
//    max = 0;
//    dfs(root, 0, 0);
//    return max;
//}
//
////530. 二叉搜索树的最小绝对差
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int pre, mn;
//void dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return;
//    dfs(node->left);
//    mn = fmin(mn, node->val - pre);
//    pre = node->val;
//    dfs(node->right);
//}
//int getMinimumDifference(struct TreeNode* root)
//{
//    pre = -100001;
//    mn = 100000;
//    dfs(root);
//    return mn;
//}
//
