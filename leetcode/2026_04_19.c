////101046. 最小稳定下标 I
//
//int firstStableIndex(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int suf_min[n + 1];
//    suf_min[n] = INT_MAX;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf_min[i] = fmin(nums[i], suf_min[i + 1]);
//    }
//    int pre_max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        pre_max = fmax(pre_max, nums[i]);
//        int d = pre_max - suf_min[i];
//        if (d <= k)
//            return i;
//    }
//    return -1;
//}
//
////101047. 最小稳定下标 II    
//
//int firstStableIndex(int* nums, int numsSize, int k)
//{
//    int n = numsSize;
//    int suf_min[n + 1];
//    suf_min[n] = INT_MAX;
//    for (int i = n - 1; i >= 0; i--)
//    {
//        suf_min[i] = fmin(nums[i], suf_min[i + 1]);
//    }
//    int pre_max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        pre_max = fmax(pre_max, nums[i]);
//        int d = pre_max - suf_min[i];
//        if (d <= k)
//            return i;
//    }
//    return -1;
//}
//
////101045. 多源洪水灌溉
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cmp(const void* e1, const void* e2)
//{
//    int* a = *(int**)e1;
//    int* b = *(int**)e2;
//    return b[2] - a[2];
//}
//const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//int** colorGrid(int n, int m, int** sources, int sourcesSize, int* sourcesColSize, int* returnSize, int** returnColumnSizes)
//{
//    int** ans = (int**)malloc(sizeof(int*) * n);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        (*returnColumnSizes)[i] = m;
//        ans[i] = (int*)calloc(sizeof(int), m);
//    }
//    qsort(sources, sourcesSize, sizeof(int*), cmp);
//    int* queue[m * n];
//    int top = 0, bottom = 0;
//    for (int i = 0; i < sourcesSize; i++)
//    {
//        // printf("%d\n", sources[i][2]);
//        int x = sources[i][0], y = sources[i][1], c = sources[i][2];
//        ans[x][y] = c;
//        queue[top++] = sources[i];
//    }
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        for (int i = start; i < bottom; i++)
//        {
//            int x = queue[i][0], y = queue[i][1], c = queue[i][2];
//            for (int j = 0; j < 4; j++)
//            {
//                int mx = x + dir[j][0];
//                int my = y + dir[j][1];
//                if (mx < 0 || mx >= n || my < 0 || my >= m || ans[mx][my])
//                    continue;
//
//                ans[mx][my] = c;
//                queue[top] = (int*)malloc(sizeof(int) * 3);
//                queue[top][0] = mx;
//                queue[top][1] = my;
//                queue[top++][2] = c;
//            }
//        }
//    }
//    *returnSize = n;
//    return ans;
//}
//
//// LCR 044. 在每个树行中找最大值
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
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int* largestValues(struct TreeNode* root, int* returnSize)
//{
//    int capacity = 8;
//    int* ans = (int*)malloc(sizeof(int) * capacity);
//    *returnSize = 0;
//    if (root == NULL)
//        return ans;
//    struct TreeNode* queue[10000];
//    int top = 0, bottom = 0;
//    queue[top++] = root;
//    while (top > bottom)
//    {
//        int start = bottom;
//        bottom = top;
//        int max = INT_MIN;
//        for (int i = start; i < bottom; i++)
//        {
//            max = fmax(max, queue[i]->val);
//            if (queue[i]->left) queue[top++] = queue[i]->left;
//            if (queue[i]->right) queue[top++] = queue[i]->right;
//        }
//        ans[(*returnSize)++] = max;
//        if (*returnSize >= capacity)
//        {
//            capacity *= 2;
//            ans = (int*)realloc(ans, sizeof(int) * capacity);
//        }
//    }
//    return ans;
//}
//
//// LCR 052. 递增顺序搜索树
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
//struct TreeNode* increasingBST(struct TreeNode* root)
//{
//    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    dummy->left = NULL;
//    dummy->right = NULL;
//    struct TreeNode* cur = dummy;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL)
//            return;
//
//        dfs(node->left);
//        // printf("%d ", node -> val);
//        node->left = NULL;
//        cur->right = node;
//        cur = node;
//        dfs(node->right);
//    }
//    dfs(root);
//    cur->right = NULL;
//    return dummy->right;
//}
//
