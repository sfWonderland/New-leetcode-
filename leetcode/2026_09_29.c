//// 111. 二叉树的最小深度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int minDepth(struct TreeNode* root)
//{
//    if (!root) return 0;
//    if (!root->left && !root->right) return 1;
//    int left = root->left ? minDepth(root->left) + 1 : 100001;
//    int right = root->right ? minDepth(root->right) + 1 : 100001;
//    return fmin(left, right);
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void push(struct TreeNode*** queue, int* capacity, int* front, struct TreeNode* node)
//{
//    (*queue)[(*front)++] = node;
//    if ((*front) == (*capacity))
//    {
//        (*capacity) *= 2;
//        (*queue) = (struct TreeNode**)realloc(*queue, sizeof(struct TreeNode*) * (*capacity));
//    }
//}
//int minDepth(struct TreeNode* root)
//{
//    if (!root) return 0;
//    int capacity = 16;
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
//    int front = 0, rear = 0;
//    queue[front++] = root;
//    int depth = 0;
//    while (front > rear)
//    {
//        depth++;
//        int start = rear;
//        rear = front;
//        for (int i = start; i < rear; i++)
//        {
//            struct TreeNode* node = queue[i];
//            if (!node->left && !node->right)
//            {
//                free(queue);
//                return depth;
//            }
//            if (node->left) push(&queue, &capacity, &front, node->left);
//            if (node->right) push(&queue, &capacity, &front, node->right);
//        }
//    }
//    return -1;
//}
//
//// 112. 路径总和  
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int sum;
//bool dfs(struct TreeNode* node)
//{
//    if (!node) return false;
//    int x = node->val;
//    if (!node->left && !node->right) return sum == x;
//    bool res = false;
//    if (node->left)
//    {
//        sum -= x;
//        if (dfs(node->left)) return true;
//        sum += x;
//    }
//    if (node->right)
//    {
//        sum -= x;
//        if (dfs(node->right)) return true;
//        sum += x;
//    }
//    return false;
//}
//bool hasPathSum(struct TreeNode* root, int targetSum)
//{
//    sum = targetSum;
//    return dfs(root);
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int sum;
//bool dfs(struct TreeNode* node)
//{
//    if (!node) return false;
//    if (!node->left && !node->right) return sum == node->val;
//    sum -= node->val;
//    if (node->left && dfs(node->left)) return true;
//    if (node->right && dfs(node->right)) return true;
//    sum += node->val;
//    return false;
//}
//bool hasPathSum(struct TreeNode* root, int targetSum)
//{
//    sum = targetSum;
//    return dfs(root);
//}
//
//// 129. 求根节点到叶节点数字之和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int ans, pre;
//void dfs(struct TreeNode* node)
//{
//    if (!node->left && !node->right)
//    {
//        ans += pre * 10 + node->val;
//        return;
//    }
//    pre = pre * 10 + node->val;
//    if (node->left) dfs(node->left);
//    if (node->right) dfs(node->right);
//    pre /= 10;
//}
//int sumNumbers(struct TreeNode* root)
//{
//    ans = 0, pre = 0;
//    dfs(root);
//    return ans;
//}
//
//// 199. 二叉树的右视图
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
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* rightSideView(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    struct TreeNode* queue[100];
//    int front = 0, rear = 0;
//    queue[front++] = root;
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    while (front > rear)
//    {
//        int start = rear;
//        rear = front;
//        ans[(*returnSize)++] = queue[start]->val;
//        for (int i = start; i < rear; i++)
//        {
//            struct TreeNode* node = queue[i];
//            if (node->right) queue[front++] = node->right;
//            if (node->left) queue[front++] = node->left;
//        }
//    }
//    return ans;
//}
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
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//void dfs(struct TreeNode* node, int depth, int* ans, int* len)
//{
//    if (node == NULL) return;
//    if (depth == *len)
//        ans[(*len)++] = node->val;
//
//    dfs(node->right, depth + 1, ans, len);
//    dfs(node->left, depth + 1, ans, len);
//}
//int* rightSideView(struct TreeNode* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    *returnSize = 0;
//    dfs(root, 0, ans, returnSize);
//    return ans;
//}
//
