////1030. 距离顺序排列矩阵单元格
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes)
//{
//    int n = rows * cols;
//    bool vis[rows][cols];
//    memset(vis, 0, sizeof(vis));
//    int queue[n];
//    int front = 0, rear = 0;
//    queue[rear++] = rCenter * 101 + cCenter;
//    vis[rCenter][cCenter] = 1;
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    while (rear > front)
//    {
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int x = queue[i] / 101, y = queue[i] % 101;
//            ans[idx] = (int*)malloc(sizeof(int) * 2);
//            ans[idx][0] = x;
//            ans[idx][1] = y;
//            (*returnColumnSizes)[idx++] = 2;
//            for (int j = 0; j < 4; j++)
//            {
//                int mx = x + dir[j][0];
//                int my = y + dir[j][1];
//                if (mx >= 0 && mx < rows && my >= 0 && my < cols && !vis[mx][my])
//                {
//                    vis[mx][my] = 1;
//                    queue[rear++] = mx * 101 + my;
//                }
//            }
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
////993. 二叉树的堂兄弟节点    
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
//bool isCousins(struct TreeNode* root, int x, int y)
//{
//    int depth = 0;
//    struct TreeNode* father = NULL;
//    bool dfs(struct TreeNode* node, struct TreeNode* fa, int d)
//    {
//        if (node == NULL)
//            return false;
//
//        if (node->val == x || node->val == y)
//        {
//            if (depth)
//                return depth == d && father != fa;
//
//            depth = d;
//            father = fa;
//        }
//        return dfs(node->left, node, d + 1) || dfs(node->right, node, d + 1);
//    }
//
//    return dfs(root, NULL, 1);
//}
//
////991. 坏了的计算器
//
//int brokenCalc(int startValue, int target)
//{
//    if (startValue >= target) return startValue - target;
//    int ans = 0;
//    while (startValue != target)
//    {
//        if (startValue > target) return ans + startValue - target;
//        if (target % 2 == 1)
//        {
//            ans++;
//            target++;
//        }
//        target >>= 1;
//        ans++;
//    }
//    return ans;
//}
//
////1237. 找出给定方程的正整数解
//
///*
// * // This is the definition for customFunction API.
// * // You should not implement it, or speculate about its implementation
// *
// * // Returns f(x, y) for any given positive integers x and y.
// * // Note that f(x, y) is increasing with respect to both x and y.
// * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
// */
//
// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  */
//int** findSolution(int (*customFunction)(int, int), int z, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * 1000);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
//    int idx = 0;
//    int x = 1, y = 1000;
//    while (x <= 1000 && y)
//    {
//        int res = customFunction(x, y);
//        if (res < z)
//            x++;
//        else if (res > z)
//            y--;
//        else
//        {
//            ans[idx] = (int*)malloc(sizeof(int) * 2);
//            ans[idx][0] = x++, ans[idx][1] = y--;
//            (*returnColumnSizes)[idx++] = 2;
//        }
//    }
//    *returnSize = idx;
//    return ans;
//}
//
