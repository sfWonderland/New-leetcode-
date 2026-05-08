//// 1914. 循环轮转矩阵
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//void swap(int** grid, int x1, int y1, int x2, int y2)
//{
//    int tmp = grid[x1][y1];
//    grid[x1][y1] = grid[x2][y2];
//    grid[x2][y2] = tmp;
//}
//int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
//{
//    int m0 = gridSize, n0 = gridColSize[0];
//    int d = fmin(m0 / 2, n0 / 2);
//    for (int i = 0; i < d; i++)
//    {
//        int m = m0 - 1 - 2 * i;
//        int n = n0 - 1 - 2 * i;
//        void index(int p, int* x, int* y)
//        {
//            if (p < n)
//            {
//                *x = i;
//                *y = i + p;
//            }
//            else if (p < n + m)
//            {
//                *x = i + p - n;
//                *y = n + i;
//            }
//            else if (p < 2 * n + m)
//            {
//                *x = i + m;
//                *y = i - p + n * 2 + m;
//            }
//            else
//            {
//                *x = i - p + 2 * m + 2 * n;
//                *y = i;
//            }
//        }
//        void reverse(int left, int right)
//        {
//            while (left < right)
//            {
//                int x1, y1, x2, y2;
//                index(left, &x1, &y1);
//                index(right, &x2, &y2);
//                swap(grid, x1, y1, x2, y2);
//                left++; right--;
//            }
//        }
//        int size = (m + n) * 2;
//        int shift = k % size;
//        reverse(0, shift - 1);
//        reverse(shift, size - 1);
//        reverse(0, size - 1);
//    }
//    *returnSize = m0;
//    *returnColumnSizes = (int*)malloc(sizeof(int) * m0);
//    for (int i = 0; i < m0; i++)
//    {
//        (*returnColumnSizes)[i] = n0;
//    }
//    return grid;
//}
//
//// LCP 77. 符文储备  
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int runeReserve(int* runes, int runesSize)
//{
//    qsort(runes, runesSize, sizeof(int), cmp);
//    int left = 0, ans = 1;
//    for (int i = 1; i < runesSize; i++)
//    {
//        if (runes[i] - runes[i - 1] > 1)
//        {
//            ans = fmax(ans, i - left);
//            left = i;
//        }
//    }
//    ans = fmax(runesSize - left, ans);
//    return ans;
//}
//
//int runeReserve(int* runes, int runesSize)
//{
//    int cnt[10001] = { 0 };
//    for (int i = 0; i < runesSize; i++)
//    {
//        cnt[runes[i]]++;
//    }
//    int ans = 0, sum = 0;
//    for (int i = 0; i < 10001; i++)
//    {
//        if (cnt[i])
//            sum += cnt[i];
//        else
//        {
//            ans = fmax(ans, sum);
//            sum = 0;
//        }
//    }
//    return ans;
//}
//
//// 面试题 04.06. 后继者
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
//struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
//{
//    if (root == NULL)
//        return NULL;
//
//    if (root->val <= p->val)
//        return inorderSuccessor(root->right, p);
//
//    struct TreeNode* ans = inorderSuccessor(root->left, p);
//    return ans ? ans : root;
//}
//
//
////面试题 04.08. 首个共同祖先
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
//    if (root == NULL)
//        return NULL;
//
//    if (root == p || root == q)
//        return root;
//    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left && right)
//        return root;
//
//    return left ? left : right;
//}
//
//
