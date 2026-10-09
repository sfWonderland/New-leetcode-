//// 1123. 最深叶节点的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//#define MAX(a, b) ((b) > (a) ? (b) : (a))
//struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
//{
//    struct TreeNode* ans = NULL;
//    int max_depth = 0;
//    int dfs(struct TreeNode* node, int depth)
//    {
//        if (node == NULL)
//        {
//            max_depth = MAX(max_depth, depth);
//            return depth;
//        }
//        int left_max_depth = dfs(node->left, depth + 1);
//        int right_max_depth = dfs(node->right, depth + 1);
//        if (left_max_depth == right_max_depth && left_max_depth == max_depth)
//            ans = node;
//        return MAX(left_max_depth, right_max_depth);
//    }
//    dfs(root, 0);
//    return ans;
//}
//
//// 700. 二叉搜索树中的搜索
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* searchBST(struct TreeNode* root, int val)
//{
//    if (root == NULL || root->val == val) return root;
//
//    return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
//}
//
//// 530. 二叉搜索树的最小绝对差
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//#define GET_MIN(a, b) ((a) > (b) ? (b) : (a))
//int getMinimumDifference(struct TreeNode* root)
//{
//    struct TreeNode* cur = root;
//    struct TreeNode* st[5000];
//    int top = 0, pre = INT_MIN / 2, ans = INT_MAX;
//    while (cur || top > 0)
//    {
//        if (cur)
//        {
//            st[top++] = cur;
//            cur = cur->left;
//        }
//        else
//        {
//            cur = st[--top];
//            ans = GET_MIN(ans, cur->val - pre);
//            pre = cur->val;
//            cur = cur->right;
//        }
//    }
//
//    return ans;
//}
//
//// 938. 二叉搜索树的范围和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int rangeSumBST(struct TreeNode* root, int low, int high)
//{
//    if (root == NULL) return 0;
//    if (root->val < low) return rangeSumBST(root->right, low, high);
//    if (root->val > high) return rangeSumBST(root->left, low, high);
//    return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
//}
//
