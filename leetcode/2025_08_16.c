////102. 二叉树的层序遍历
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//
//    int** ans = (int**)malloc(sizeof(int*) * 2000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
//    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
//    int i = 0, front = 0, rear = 1;
//    q[front] = root;
//    while (rear > front)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * (rear - front));
//        int t = 0;
//        for (int n = rear - front; n > 0; n--)
//        {
//            struct TreeNode* node = q[front++];
//            ans[i][t++] = node->val;
//            if (node->left) q[rear++] = node->left;
//            if (node->right) q[rear++] = node->right;
//        }
//        (*returnColumnSizes)[i++] = t;
//    }
//
//    *returnSize = i;
//    return ans;
//}
//
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//
//    int** ans = (int**)malloc(sizeof(int*) * 2000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
//    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
//    int i = 0, front = 0, rear = 0;
//    q[rear++] = root;
//    while (rear > front)
//    {
//        int len = rear - front;
//        ans[i] = (int*)malloc(sizeof(int) * len);
//        int start = front;
//        front = rear;
//        for (int n = start; n < front; n++)
//        {
//            struct TreeNode* node = q[n];
//            ans[i][n - start] = node->val;
//            if (node->left) q[rear++] = node->left;
//            if (node->right) q[rear++] = node->right;
//        }
//        (*returnColumnSizes)[i++] = len;
//    }
//
//    *returnSize = i;
//    return ans;
//}
//
////103. 二叉树的锯齿形层序遍历
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//void reverse(int* arr, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = arr[left];
//        arr[left++] = arr[right];
//        arr[right--] = tmp;
//    }
//}
//int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//
//    int** ans = (int**)malloc(sizeof(int*) * 2000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
//    struct TreeNode** q = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
//    int i = 0, front = 0, rear = 1;
//    bool even = false;
//    q[front] = root;
//    while (rear > front)
//    {
//        int* vals = (int*)malloc(sizeof(int) * (rear - front));
//        int t = 0;
//        for (int n = rear - front; n > 0; n--)
//        {
//            struct TreeNode* node = q[front++];
//            vals[t++] = node->val;
//            if (node->left) q[rear++] = node->left;
//            if (node->right) q[rear++] = node->right;
//        }
//        if (even)
//            reverse(vals, 0, t - 1);
//        even ^= 1;
//        ans[i] = vals;
//        (*returnColumnSizes)[i++] = t;
//    }
//
//    *returnSize = i;
//    return ans;
//}
//
////513. 找树左下角的值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int findBottomLeftValue(struct TreeNode* root)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    int ans = 0, front = 0, rear = 0;
//    queue[rear++] = root;
//    while (rear > front)
//    {
//        int start = front;
//        ans = queue[start]->val;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            struct TreeNode* node = queue[i];
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//    }
//    return ans;
//}
//
////107. 二叉树的层序遍历 II
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int maxDepth(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return fmax(maxDepth(node->left), maxDepth(node->right)) + 1;
//}
//int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    int n = maxDepth(root);
//    *returnSize = n;
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
//    int front = 0, rear = 0;
//    queue[rear++] = root;
//    while (n > 0)
//    {
//        int len = rear - front;
//        int* vals = (int*)malloc(sizeof(int) * len);
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            struct TreeNode* node = queue[i];
//            vals[i - start] = node->val;
//            if (node->left) queue[rear++] = node->left;
//            if (node->right) queue[rear++] = node->right;
//        }
//        ans[--n] = vals;
//        (*returnColumnSizes)[n] = len;
//    }
//    return ans;
//}
//
