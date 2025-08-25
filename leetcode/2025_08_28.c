////3446. 按对角线进行矩阵排序
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* a, const void* b)
//{
//    return *(int*)a - *(int*)b;
//}
//int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
//{
//    int n = gridSize;
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < 2 * n - 1; i++)
//    {
//        int max_j = fmin(n - 1, 2 * n - 2 - i);
//        int min_j = fmax(0, n - 1 - i);
//        if (i < n - 1)
//            for (int j = min_j; j <= max_j; j++)
//            {
//                arr[j - min_j] = grid[j - min_j][j];
//            }
//        else
//        {
//            for (int j = max_j; j >= min_j; j--)
//            {
//                arr[max_j - j] = grid[n - 1 - max_j + j][j];
//            }
//        }
//        qsort(arr, max_j - min_j + 1, sizeof(int), cmp);
//        if (i < n - 1)
//        {
//            for (int j = min_j; j <= max_j; j++)
//            {
//                grid[j - min_j][j] = arr[j - min_j];
//            }
//        }
//        else
//        {
//            for (int j = max_j; j >= min_j; j--)
//            {
//                grid[n - 1 - max_j + j][j] = arr[max_j - j];
//            }
//        }
//    }
//    *returnSize = n;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        (*returnColumnSizes)[i] = n;
//    }
//    return grid;
//}
//
////LCR 193. 二叉搜索树的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == NULL || root == p || root == q)
//        return root;
//    int x = root->val;
//    int a = p->val;
//    int b = q->val;
//    if (x > a && x > b)
//        return lowestCommonAncestor(root->left, p, q);
//    if (x < a && x < b)
//        return lowestCommonAncestor(root->right, p, q);
//
//    return root;
//}
//
////LCR 194. 二叉树的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == NULL || root == p || root == q)
//        return root;
//
//    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left && right) return root;
//
//    return left ? left : right;
//}
//
//
////LCR 167. 招式拆解 I
//
//int dismantlingAction(char* arr)
//{
//    bool cnt[128] = { 0 };
//    int ans = 0, left = 0;
//    for (int i = 0; arr[i]; i++)
//    {
//        while (cnt[arr[i]])
//        {
//            cnt[arr[left++]]--;
//        }
//        cnt[arr[i]]++;
//        ans = fmax(ans, i - left + 1);
//    }
//    return ans;
//}
//
