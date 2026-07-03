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
//    bool flag = false;
//    queue[rear++] = root;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            if (!queue[i])
//            {
//                flag = true;
//                continue;
//            }
//            // 本层空结点后续有结点或下一层有结点
//            if (flag) return false;
//            queue[rear++] = queue[i]->left;
//            queue[rear++] = queue[i]->right;
//        }
//    }
//    return true;
//}
//
