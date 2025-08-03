////110. 平衡二叉树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* s)
//{
//    if (s == NULL)
//        return 0;
//
//    int a = dfs(s->left);
//    int b = dfs(s->right);
//
//    return abs(a - b) > 1 ? -10000 : fmax(a, b) + 1;
//}
//bool isBalanced(struct TreeNode* root)
//{
//    return dfs(root) >= 0;
//}
//
////112. 路径总和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* s, int x)
//{
//    int n = s->val;
//    if (s->left || s->right)
//    {
//        bool a = s->left ? dfs(s->left, x - n) : false;
//        bool b = s->right ? dfs(s->right, x - n) : false;
//        return a | b;
//    }
//    return x == n;
//}
//bool hasPathSum(struct TreeNode* root, int targetSum)
//{
//    if (root == NULL)
//        return false;
//    return dfs(root, targetSum);
//}
//
////45. 跳跃游戏 II
//
//int dfs(int i, int n, int* nums)
//{
//    if (i == n - 1)
//        return 0;
//    int res = 1001;
//    for (int j = i + 1; j < fmin(n, i + 1 + nums[i]); j++)
//    {
//        res = fmin(res, dfs(j, n, nums));
//    }
//    return res + 1;
//}
//int jump(int* nums, int numsSize)
//{
//    return dfs(0, numsSize, nums);
//}
//
//int jump(int* nums, int numsSize)
//{
//    int f[numsSize];
//    f[numsSize - 1] = 0;
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        f[i] = 10001;
//        for (int j = i + 1; j < fmin(numsSize, i + 1 + nums[i]); j++)
//        {
//            f[i] = fmin(f[i], f[j]);
//        }
//        f[i]++;
//    }
//    return f[0];
//}
//
//int jump(int* nums, int numsSize)
//{
//    int ans = 0;
//    int cur_right = 0, next_right = 0;
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        next_right = fmax(next_right, i + nums[i]);
//        if (i == cur_right)
//        {
//            cur_right = next_right;
//            ans++;
//        }
//    }
//    return ans;
//}
//
////3040. 相同分数的最大操作数目 II
//
//int* arr;
//int dfs(int l, int r, int x)
//{
//    if (l >= r)
//        return 0;
//    int res = 0;
//    if (arr[l] + arr[l + 1] == x)
//        res = fmax(res, dfs(l + 2, r, x) + 1);
//    if (arr[r] + arr[r - 1] == x)
//        res = fmax(res, dfs(l, r - 2, x) + 1);
//    if (arr[l] + arr[r] == x)
//        res = fmax(res, dfs(l + 1, r - 1, x) + 1);
//    return res;
//}
//int maxOperations(int* nums, int numsSize)
//{
//    if (numsSize == 2)
//        return 1;
//
//    arr = nums;
//    int res1 = dfs(0, numsSize - 3, nums[numsSize - 1] + nums[numsSize - 2]);
//    int res2 = dfs(2, numsSize - 1, nums[0] + nums[1]);
//    int res3 = dfs(1, numsSize - 2, nums[0] + nums[numsSize - 1]);
//    return fmax(res1, fmax(res2, res3)) + 1;
//}
//
//int* arr;
//int n;
//int dfs(int l, int r, int x)
//{
//    int f[n + 1][n + 1];
//    for (int i = 0; i <= n; i++)
//    {
//        memset(f[i], 0, sizeof(f[i]));
//    }
//    for (int i = r - 1; i >= l; i--)
//    {
//        for (int j = i + 1; j <= r; j++)
//        {
//            if (arr[i] + arr[i + 1] == x)
//                f[i][j + 1] = fmax(f[i][j + 1], f[i + 2][j + 1] + 1);
//            if (arr[j] + arr[j - 1] == x)
//                f[i][j + 1] = fmax(f[i][j + 1], f[i][j - 1] + 1);
//            if (arr[i] + arr[j] == x)
//                f[i][j + 1] = fmax(f[i][j + 1], f[i + 1][j] + 1);
//        }
//    }
//
//    return f[l][r + 1];
//}
//int maxOperations(int* nums, int numsSize)
//{
//    n = numsSize;
//    arr = nums;
//    int res1 = dfs(0, n - 3, nums[n - 1] + nums[n - 2]);
//    int res2 = dfs(2, n - 1, nums[0] + nums[1]);
//    int res3 = dfs(1, n - 2, nums[0] + nums[n - 1]);
//    return fmax(res1, fmax(res2, res3)) + 1;
//}
//
