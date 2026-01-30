////LCR 129. 字母迷宫 
//
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//bool wordPuzzle(char** grid, int gridSize, int* gridColSize, char* target)
//{
//    int m = gridSize, n = gridColSize[0];
//    int len = strlen(target);
//    bool vis[m][n];
//    memset(vis, 0, sizeof(vis));
//    bool dfs(int x, int y, int i)
//    {
//        if (i == len)
//            return true;
//
//        for (int k = 0; k < 4; k++)
//        {
//            int mx = x + dir[k][0];
//            int my = y + dir[k][1];
//            if (mx >= 0 && mx < m && my >= 0 && my < n && grid[mx][my] == target[i] && !vis[mx][my])
//            {
//                vis[mx][my] = true;
//                if (dfs(mx, my, i + 1))
//                    return true;
//                vis[mx][my] = false;
//            }
//        }
//        return false;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (grid[i][j] == target[0])
//            {
//                vis[i][j] = true;
//                if (dfs(i, j, 1))
//                    return true;
//                memset(vis, 0, sizeof(vis));
//            }
//        }
//    }
//    return false;
//}
//
////3379. 转换数组    
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* constructTransformedArray(int* nums, int numsSize, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        int k = ((i + nums[i]) % numsSize + numsSize) % numsSize;
//        ans[i] = nums[k];
//    }
//    *returnSize = numsSize;
//    return ans;
//}
//
////LCR 130. 衣橱整理
//
//int digit(int x)
//{
//    int cnt = 0;
//    while (x)
//    {
//        cnt += x % 10;
//        x /= 10;
//    }
//    return cnt;
//}
//int wardrobeFinishing(int m, int n, int cnt)
//{
//    int vis[m][n];
//    memset(vis, 0, sizeof(vis));
//    int dfs(int x, int y)
//    {
//        if (x >= m || y >= n || vis[x][y])
//            return 0;
//
//        vis[x][y] = 1;
//        return digit(x) + digit(y) > cnt ? 0 : dfs(x + 1, y) + dfs(x, y + 1) + 1;
//    }
//    return dfs(0, 0);
//}
//
////LCR 153. 二叉树中和为目标值的路径
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
//int** ans;
//int ansSize;
//int* len;
//int* path;
//int pathSize;
//int capacity;
//
//void dfs(struct TreeNode* node, int target)
//{
//    path[pathSize++] = node->val;
//    target -= node->val;
//    if (!node->left && !node->right)
//    {
//        if (target == 0)
//        {
//            ans[ansSize] = (int*)malloc(sizeof(int) * pathSize);
//            memcpy(ans[ansSize], path, sizeof(int) * pathSize);
//            len[ansSize++] = pathSize;
//            if (ansSize >= capacity)
//            {
//                capacity *= 2;
//                ans = (int**)realloc(ans, sizeof(int*) * capacity);
//                len = (int*)realloc(len, sizeof(int) * capacity);
//            }
//        }
//    }
//    else
//    {
//        if (node->left) dfs(node->left, target);
//        if (node->right) dfs(node->right, target);
//    }
//
//    pathSize--;
//}
//int getDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return fmax(getDepth(root->left), getDepth(root->right)) + 1;
//}
//int** pathTarget(struct TreeNode* root, int target, int* returnSize, int** returnColumnSizes)
//{
//    *returnSize = 0;
//    if (!root) return NULL;
//    capacity = 64;
//    ans = (int**)malloc(sizeof(int*) * capacity);
//    len = (int*)malloc(sizeof(int) * capacity);
//    ansSize = 0;
//    path = (int*)malloc(sizeof(int) * getDepth(root));
//    pathSize = 0;
//    dfs(root, target);
//    *returnSize = ansSize;
//    *returnColumnSizes = len;
//    return ans;
//}
//
