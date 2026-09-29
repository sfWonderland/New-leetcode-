//// 958. 二叉树的完全性检验
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isCompleteTree(struct TreeNode* root)
//{
//    struct TreeNode* queue[200];
//    int front = 0, rear = 0;
//    queue[rear++] = root;
//    bool flag = false;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//
//        for (int i = start; i < front; i++)
//        {
//            struct TreeNode* node = queue[i];
//            if (!node)
//            {
//                flag = true;
//                continue;
//            }
//            if (flag) return false;
//            queue[rear++] = node->left;
//            queue[rear++] = node->right;
//        }
//    }
//    return true;
//}
//
//// 1022. 从根到叶的二进制数之和   
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int num;
//int dfs(struct TreeNode* node)
//{
//    if (!node->left && !node->right) return (num << 1) | node->val;
//    num = (num << 1) | node->val;
//    int res = node->left ? dfs(node->left) : 0;
//    res += node->right ? dfs(node->right) : 0;
//    num >>= 1;
//    return res;
//}
//int sumRootToLeaf(struct TreeNode* root)
//{
//    num = 0;
//    return dfs(root);
//}
//
//// 623. 在二叉树中增加一行
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* createNode(int val, struct TreeNode* left, struct TreeNode* right)
//{
//    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node->val = val;
//    node->left = left;
//    node->right = right;
//    return node;
//}
//void dfs(struct TreeNode* node, int val, int remainder)
//{
//    if (!remainder)
//    {
//        node->left = createNode(val, node->left, NULL);
//        node->right = createNode(val, NULL, node->right);
//        return;
//    }
//    if (node->left) dfs(node->left, val, remainder - 1);
//    if (node->right) dfs(node->right, val, remainder - 1);
//}
//struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth)
//{
//    if (depth == 1)
//    {
//        struct TreeNode* node = createNode(val, root, NULL);
//        return node;
//    }
//    dfs(root, val, depth - 2);
//    return root;
//}
//
//// 1372. 二叉树中的最长交错路径
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
//void dfs(struct TreeNode* node, int left, int right)
//{
//    if (node == NULL) return;
//    dfs(node->left, right + 1, 0);
//    dfs(node->right, 0, left + 1);
//    max = fmax(max, left + right); // left + right = fmax(left, right)
//}
//int longestZigZag(struct TreeNode* root)
//{
//    max = 0;
//    dfs(root, 0, 0);
//    return max;
//}
//
