//// 662. 二叉树最大宽度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//typedef struct
//{
//    struct TreeNode* key;
//    unsigned long long val;
//}Pair;
//int widthOfBinaryTree(struct TreeNode* root)
//{
//    int ans = 1;
//    Pair queue[3000];
//    int top = 0, bottom = 0;
//    queue[top].key = root;
//    queue[top++].val = 1ll;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int i = start; i < bottom; i++)
//        {
//            if (queue[i].key->left)
//            {
//                queue[top].key = queue[i].key->left;
//                queue[top++].val = 2 * queue[i].val;
//            }
//            if (queue[i].key->right)
//            {
//                queue[top].key = queue[i].key->right;
//                queue[top++].val = 2 * queue[i].val + 1;
//            }
//        }
//        ans = fmax(ans, queue[bottom - 1].val - queue[start].val + 1);
//    }
//    return ans;
//}
//
