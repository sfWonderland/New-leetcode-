//// 450. 删除二叉搜索树中的节点
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* deleteNode(struct TreeNode* root, int key)
//{
//    if (root == NULL)
//        return NULL;
//
//    if (root->val > key)
//        root->left = deleteNode(root->left, key);
//    else if (root->val == key)
//    {
//        if (root->left)
//        {
//            struct TreeNode* cur = root->left;
//            while (cur->right)
//            {
//                cur = cur->right;
//            }
//            cur->right = root->right;
//            root->right = NULL;
//            root = root->left;
//        }
//        else
//            root = root->right;
//    }
//    else
//        root->right = deleteNode(root->right, key);
//    return root;
//}
//
