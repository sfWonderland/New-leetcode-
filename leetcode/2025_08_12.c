////337. 打家劫舍 III
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//typedef struct SubtreeStatus
//{
//    int rob;
//    int not_rob;
//}sub;
//sub dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return (sub) { 0, 0 };
//
//    sub l = dfs(node->left);
//    sub r = dfs(node->right);
//    int rob = l.not_rob + r.not_rob + node->val;
//    int not_rob = fmax(l.rob, l.not_rob) + fmax(r.rob, r.not_rob);
//    return (sub) { rob, not_rob };
//}
//int rob(struct TreeNode* root)
//{
//    sub ans = dfs(root);
//    return fmax(ans.rob, ans.not_rob);
//}
//
////124. 二叉树中的最大路径和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (node == NULL)
//        return 0;
//
//    int l = dfs(node->left, ans);
//    int r = dfs(node->right, ans);
//    *ans = fmax(*ans, l + r + node->val);
//    return fmax(fmax(l, r) + node->val, 0);
//}
//int maxPathSum(struct TreeNode* root)
//{
//    int ans = INT_MIN;
//    dfs(root, &ans);
//    return ans;
//}
//
////687. 最长同值路径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (node == NULL)
//        return -1;
//
//    int l = dfs(node->left, ans) + 1;
//    int r = dfs(node->right, ans) + 1;
//    if (node->left && node->left->val != node->val) l = 0;
//    if (node->right && node->right->val != node->val) r = 0;
//    *ans = fmax(*ans, l + r);
//    return fmax(l, r);
//}
//int longestUnivaluePath(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
////289. 生命游戏
//
//int pos[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1} };
//void gameOfLife(int** board, int boardSize, int* boardColSize)
//{
//    int** nums = (int**)malloc(sizeof(int*) * boardSize);
//    for (int i = 0; i < boardSize; i++)
//    {
//        nums[i] = (int*)malloc(sizeof(int) * boardColSize[0]);
//        for (int j = 0; j < boardColSize[0]; j++)
//        {
//            nums[i][j] = 0;
//            for (int k = 0; k < 8; k++)
//            {
//                int x = pos[k][0], y = pos[k][1];
//                if (x + i < 0 || x + i >= boardSize)
//                    continue;
//                if (y + j < 0 || y + j >= boardColSize[0])
//                    continue;
//
//                nums[i][j] += board[i + x][j + y];
//            }
//        }
//    }
//    for (int i = 0; i < boardSize; i++)
//    {
//        for (int j = 0; j < boardColSize[0]; j++)
//        {
//            if (nums[i][j] < 2 || nums[i][j] > 3)
//                board[i][j] = 0;
//            else if (nums[i][j] == 3)
//                board[i][j] = 1;
//        }
//    }
//}
//
