////3423. 循环数组中相邻元素的最大差值
//
//int maxAdjacentDistance(int* nums, int numsSize)
//{
//    int ans = abs(nums[0] - nums[numsSize - 1]);
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        ans = fmax(ans, abs(nums[i + 1] - nums[i]));
//    }
//    return ans;
//}
//
////2265. 统计值等于子树平均值的节点数
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//typedef struct
//{
//    int key;
//    int val;
//}SubTreeInfo;
//SubTreeInfo dfs(struct TreeNode* node, int* ans)
//{
//    SubTreeInfo info = { 0, 0 };
//    if (node == NULL)
//    {
//        return info;
//    }
//    SubTreeInfo left = dfs(node->left, ans);
//    SubTreeInfo right = dfs(node->right, ans);
//    info.key = left.key + right.key + node->val;
//    info.val = left.val + right.val + 1;
//    if (info.key / info.val == node->val)
//    {
//        (*ans)++;
//    }
//    return info;
//}
//int averageOfSubtree(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
////LCR 083. 全排列
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int cnt[7] = { 0, 1, 2, 6, 24, 120, 720 };
//int** ans;
//int ansSize;
//int* tmp;
//int n;
//
//void dfs(int* nums, int k, bool* path)
//{
//    if (k == n)
//    {
//        ans[ansSize] = (int*)malloc(sizeof(int) * n);
//        for (int i = 0; i < n; i++)
//        {
//            ans[ansSize][i] = tmp[i];
//        }
//        ansSize++;
//        return;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (path[i])
//            continue;
//
//        tmp[k] = nums[i];
//        path[i] = true;
//        dfs(nums, k + 1, path);
//        path[i] = false;
//    }
//}
//
//int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//    ans = (int**)malloc(sizeof(int*) * cnt[numsSize]);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * cnt[numsSize]);
//    for (int i = 0; i < cnt[numsSize]; i++)
//    {
//        (*returnColumnSizes)[i] = numsSize;
//    }
//    ansSize = 0;
//    tmp = (int*)malloc(sizeof(int) * numsSize);
//    n = numsSize;
//    bool* path = (bool*)calloc(sizeof(bool), numsSize);
//    dfs(nums, 0, path);
//    *returnSize = ansSize;
//    return ans;
//}
//
////面试题 08.09. 括号
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** ans;
//int ansSize;
//char* tmp;
//int len;
//void dfs(int i, int depth)
//{
//    if (depth > len || depth < 0)
//        return;
//
//    if (i == len)
//    {
//        if (depth)
//            return;
//
//        tmp[len] = '\0';
//        ans[ansSize] = (char*)malloc(sizeof(char) * (len + 1));
//        strcpy(ans[ansSize], tmp);
//        ansSize++;
//        return;
//    }
//
//    tmp[i] = '(';
//    dfs(i + 1, depth + 1);
//    tmp[i] = ')';
//    dfs(i + 1, depth - 1);
//}
//char** generateParenthesis(int n, int* returnSize)
//{
//    ans = (char**)malloc(sizeof(char*) * 1500);
//    ansSize = 0;
//    tmp = (char*)malloc(sizeof(char) * (2 * n + 1));
//    len = 2 * n;
//    dfs(0, 0);
//    *returnSize = ansSize;
//    return ans;
//}
//
