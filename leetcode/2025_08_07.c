////3363. 最多可收集的水果数目
//
//int dfs(int i, int j, int** fruits, int n, int** cache)
//{
//    if (j < n - 1 - i || j >= n)
//        return 0;
//    if (i == 0)
//        return fruits[i][j];
//    if (cache[i][j] != -1)
//        return cache[i][j];
//    if (cache[i - 1][j - 1] == -1)
//        cache[i - 1][j - 1] = dfs(i - 1, j - 1, fruits, n, cache);
//    if (cache[i - 1][j] == -1)
//        cache[i - 1][j] = dfs(i - 1, j, fruits, n, cache);
//    if (cache[i - 1][j + 1] == -1)
//        cache[i - 1][j + 1] = dfs(i - 1, j + 1, fruits, n, cache);
//    return fmax(fmax(cache[i - 1][j - 1], cache[i - 1][j]), cache[i - 1][j + 1]) + fruits[i][j];
//}
//int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize)
//{
//    int ans = 0, n = fruitsSize;
//    for (int i = 0; i < n; i++)
//    {
//        ans += fruits[i][i];
//    }
//    int** cache = (int**)malloc(sizeof(int*) * (n + 1));
//    for (int i = 0; i < n + 1; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j < n + 1; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    ans += dfs(n - 2, n - 1, fruits, n, cache);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            fruits[j][i] = fruits[i][j];
//        }
//    }
//    for (int i = 0; i < n + 1; i++)
//    {
//        cache[i] = (int*)malloc(sizeof(int) * (n + 1));
//        for (int j = 0; j < n + 1; j++)
//        {
//            cache[i][j] = -1;
//        }
//    }
//    return ans + dfs(n - 2, n - 1, fruits, n, cache);
//}
//
//int helper(int i, int j, int** fruits, int n)
//{
//    int f[n][n + 1];
//    memset(f, 0, sizeof(f));
//    f[0][n - 1] = fruits[0][n - 1];
//    for (int i = 1; i < n - 1; i++)
//    {
//        for (int j = n - 1 - i; j < n; j++)
//        {
//            f[i][j] = fmax(fmax(f[i - 1][j - 1], f[i - 1][j]), f[i - 1][j + 1]) + fruits[i][j];
//        }
//    }
//    return f[n - 2][n - 1];
//}
//int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize)
//{
//    int ans = 0, n = fruitsSize;
//    for (int i = 0; i < n; i++)
//    {
//        ans += fruits[i][i];
//    }
//
//    ans += helper(n - 2, n - 1, fruits, n);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            fruits[j][i] = fruits[i][j];
//        }
//    }
//
//    return ans + helper(n - 2, n - 1, fruits, n);
//}
//
//int helper(int i, int j, int** fruits, int n)
//{
//    int f[n + 1];
//    memset(f, 0, sizeof(f));
//    f[n - 1] = fruits[0][n - 1];
//    for (int i = 1; i < n - 1; i++)
//    {
//        int pre = f[n - 2 - i];
//        for (int j = n - 1 - i; j < n; j++)
//        {
//            int tmp = f[j];
//            f[j] = fmax(fmax(pre, f[j]), f[j + 1]) + fruits[i][j];
//            pre = tmp;
//        }
//    }
//    return f[n - 1];
//}
//int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize)
//{
//    int ans = 0, n = fruitsSize;
//    for (int i = 0; i < n; i++)
//    {
//        ans += fruits[i][i];
//    }
//
//    ans += helper(n - 2, n - 1, fruits, n);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            fruits[j][i] = fruits[i][j];
//        }
//    }
//
//    return ans + helper(n - 2, n - 1, fruits, n);
//}
//
////55. 跳跃游戏
//
//bool dfs(int i, int n, int* nums, int* cache)
//{
//    if (i == n)
//        return true;
//    if (i > n)
//        return false;
//
//    if (cache[i] != -1)
//        return cache[i];
//    for (int k = i + 1; k <= fmin(i + nums[i], n); k++)
//    {
//        if (cache[k] == -1)
//            cache[k] = dfs(k, n, nums, cache);
//
//        if (cache[k])
//            return true;
//    }
//    return false;
//}
//bool canJump(int* nums, int numsSize)
//{
//    int* cache = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        cache[i] = -1;
//    }
//    return dfs(0, numsSize - 1, nums, cache);
//}
//
//bool canJump(int* nums, int numsSize)
//{
//    int f[numsSize];
//    memset(f, 0, sizeof(f));
//    f[numsSize - 1] = true;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        for (int j = i + 1; j < fmin(i + nums[i] + 1, numsSize); j++)
//        {
//            f[i] |= f[j];
//            if (f[i])
//                break;
//        }
//    }
//    return f[0];
//}
//
//bool canJump(int* nums, int numsSize)
//{
//    int n = numsSize;
//    int rightmost = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i <= rightmost)
//            rightmost = fmax(rightmost, i + nums[i]);
//        if (rightmost >= n - 1)
//            return true;
//    }
//    return false;
//}
//
////98. 验证二叉搜索树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* s, long long l, long long r)
//{
//    if (s == NULL)
//        return true;
//
//    long long n = s->val;
//    return l < n && n < r && dfs(s->left, l, n) && dfs(s->right, n, r);
//}
//bool isValidBST(struct TreeNode* root)
//{
//    return dfs(root, LLONG_MIN, LLONG_MAX);
//}
//
////543. 二叉树的直径
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s, int* ans)
//{
//    if (s == NULL)
//        return -1;
//
//    int l = dfs(s->left, ans) + 1;
//    int r = dfs(s->right, ans) + 1;
//    *ans = fmax(*ans, l + r);
//    return fmax(l, r);
//}
//int diameterOfBinaryTree(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
