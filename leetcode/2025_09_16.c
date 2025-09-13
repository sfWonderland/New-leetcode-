////671. 二叉树中第二小的节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, long long* first, long long* second)
//{
//    if (node == NULL)
//        return;
//    int x = node->val;
//    if (x < *first)
//    {
//        *second = *first;
//        *first = x;
//    }
//    else if (x != *first && x < *second)
//        *second = x;
//
//    dfs(node->left, first, second);
//    dfs(node->right, first, second);
//}
//int findSecondMinimumValue(struct TreeNode* root)
//{
//    long long first = LLONG_MAX, second = LLONG_MAX;
//    dfs(root, &first, &second);
//    return second;
//}
//
////1457. 二叉树中的伪回文路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, bool* digit)
//{
//    digit[node->val] ^= 1;
//    if (node->left || node->right)
//    {
//        int sum = 0;
//        if (node->left)
//            sum += dfs(node->left, digit);
//        if (node->right)
//            sum += dfs(node->right, digit);
//        digit[node->val] ^= 1;
//        return sum;
//    }
//
//    int n = 0;
//    for (int i = 1; i < 10; i++)
//    {
//        n += digit[i];
//    }
//    digit[node->val] ^= 1;
//    return n <= 1;
//}
//int pseudoPalindromicPaths(struct TreeNode* root)
//{
//    bool* digit = (bool*)calloc(sizeof(bool), 10);
//    return dfs(root, digit);
//}
//
////1022. 从根到叶的二进制数之和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int pre)
//{
//    pre = (pre << 1) + node->val;
//    if (node->left || node->right)
//    {
//        int sum = 0;
//        if (node->left)
//            sum += dfs(node->left, pre);
//        if (node->right)
//            sum += dfs(node->right, pre);
//        return sum;
//    }
//    else
//        return pre;
//}
//int sumRootToLeaf(struct TreeNode* root)
//{
//    return dfs(root, 0);
//}
//
////623. 在二叉树中增加一行
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* node, int cur, int val, int depth)
//{
//    if (cur == depth - 1)
//    {
//        struct TreeNode* LNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        LNode->val = val;
//        LNode->left = node->left;
//        LNode->right = NULL;
//        node->left = LNode;
//
//        struct TreeNode* RNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        RNode->val = val;
//        RNode->left = NULL;
//        RNode->right = node->right;
//        node->right = RNode;
//        return;
//    }
//
//    if (node->left)
//        dfs(node->left, cur + 1, val, depth);
//
//    if (node->right)
//        dfs(node->right, cur + 1, val, depth);
//}
//struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth)
//{
//    if (depth == 1)
//    {
//        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//        node->left = root;
//        node->right = NULL;
//        node->val = val;
//        return node;
//    }
//
//    dfs(root, 1, val, depth);
//    return root;
//}
//
