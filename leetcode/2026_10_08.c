//// 124. 二叉树中的最大路径和
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
//    if (node == NULL) return 0;
//    int left = dfs(node->left, ans);
//    left = left > 0 ? left : 0;
//    int right = dfs(node->right, ans);
//    right = right > 0 ? right : 0;
//    int sum = node->val + left + right;
//    *ans = *ans >= sum ? *ans : sum;
//    return left > right ? left + node->val : right + node->val;
//}
//int maxPathSum(struct TreeNode* root)
//{
//    int ans = INT_MIN;
//    dfs(root, &ans);
//    return ans;
//}
//
//// 2385. 感染二叉树需要的总时间   
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans, int x)
//{
//    if (node == NULL) return 0;
//    int left = dfs(node->left, ans, x);
//    int right = dfs(node->right, ans, x);
//    if (node->val == x)
//    {
//        *ans = left > right ? left : right;
//        return 100001;
//    }
//    int sum = left + right + 1 - 100001;
//    *ans = sum > *ans ? sum : *ans;
//    return left > right ? left + 1 : right + 1;
//}
//int amountOfTime(struct TreeNode* root, int start)
//{
//    int ans = 0;
//    dfs(root, &ans, start);
//    return ans;
//}
//
//// 257. 二叉树的所有路径
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
//char** binaryTreePaths(struct TreeNode* root, int* returnSize)
//{
//    char** ans = (char**)malloc(sizeof(char*) * 50);
//    *returnSize = 0;
//    char* path = (char*)malloc(sizeof(char) * 601);
//    int pathSize = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (!node) return;
//        int pre = pathSize;
//        int x = node->val;
//        int base = 100;
//        if (x == 0)
//            path[pathSize++] = '0';
//        if (x < 0)
//        {
//            path[pathSize++] = '-';
//            x = -x;
//        }
//        while (x < base)
//            base /= 10;
//        while (base)
//        {
//            int y = x / base;
//            path[pathSize++] = y + '0';
//            x -= base * y;
//            base /= 10;
//        }
//        if (!node->left && !node->right)
//        {
//            path[pathSize] = '\0';
//            // printf("%s\n", path);
//            ans[*returnSize] = (char*)malloc(sizeof(char) * (pathSize + 1));
//            strcpy(ans[*returnSize], path);
//            pathSize = pre;
//            (*returnSize)++;
//            return;
//        }
//
//        path[pathSize++] = '-';
//        path[pathSize++] = '>';
//        path[pathSize] = '\0';
//        // printf("%s\n", path);
//        dfs(node->left);
//        dfs(node->right);
//        pathSize = pre;
//    }
//    dfs(root);
//    free(path);
//    return ans;
//}
//
//// 113. 路径总和 II
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
//int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
//{
//    int capacity = 64;
//    int** ans = (int**)malloc(sizeof(int*) * capacity);
//    *returnSize = 0;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
//    int* path = (int*)malloc(sizeof(int) * 5000);
//    int pathSize = 0;
//    int sum = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL) return;
//        path[pathSize++] = node->val;
//        sum += node->val;
//        if (node->left == NULL && node->right == NULL && sum == targetSum)
//        {
//            ans[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
//            memcpy(ans[*returnSize], path, sizeof(int) * pathSize);
//            (*returnColumnSizes)[(*returnSize)++] = pathSize;
//            if (*returnSize == capacity)
//            {
//                capacity *= 2;
//                ans = (int**)realloc(ans, sizeof(int*) * capacity);
//                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
//            }
//            pathSize--;
//            sum -= node->val;
//            return;
//        }
//        dfs(node->left);
//        dfs(node->right);
//        pathSize--;
//        sum -= node->val;
//    }
//    dfs(root);
//    free(path);
//    return ans;
//}
//
