////865. 具有所有最深节点的最小子树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs1(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return fmax(dfs1(root->left), dfs1(root->right)) + 1;
//}
//struct TreeNode* dfs2(struct TreeNode* root, int depth, int maxDepth)
//{
//    if (root == NULL)
//        return NULL;
//
//    if (depth == maxDepth)
//        return root;
//
//    struct TreeNode* left = dfs2(root->left, depth + 1, maxDepth);
//    struct TreeNode* right = dfs2(root->right, depth + 1, maxDepth);
//    if (left && right)
//        return root;
//
//    return left ? left : right;
//}
//struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
//{
//    int maxDepth = dfs1(root);
//    return dfs2(root, 1, maxDepth);
//}
//
////3546. 等和矩阵分割 I    
//
//bool canPartitionGrid(int** grid, int gridSize, int* gridColSize)
//{
//    int m = gridSize, n = gridColSize[0];
//    long long tot = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            tot += grid[i][j];
//        }
//    }
//    if (tot & 1) return false;
//    long long sum = 0;
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            sum += grid[i][j];
//        }
//        if (sum >= tot / 2)
//        {
//            if (sum == tot / 2)
//                return true;
//
//            break;
//        }
//
//    }
//    sum = 0;
//    for (int j = 0; j < n; j++)
//    {
//        for (int i = 0; i < m; i++)
//        {
//            sum += grid[i][j];
//        }
//        if (sum >= tot / 2)
//        {
//            if (sum == tot / 2)
//                return true;
//
//            break;
//        }
//    }
//    return false;
//}
//
////3121. 统计特殊字母的数量 II
//
//int numberOfSpecialChars(char* word)
//{
//    int alpha[26] = { 0 };
//    int ans = 0;
//    for (int i = 0; word[i]; i++)
//    {
//        if (word[i] >= 'a')
//        {
//            if (alpha[word[i] - 'a'] == 0)
//                alpha[word[i] - 'a'] = 1;
//            else if (alpha[word[i] - 'a'] == 2)
//            {
//                ans--;
//                alpha[word[i] - 'a'] = -1;
//            }
//        }
//        else
//        {
//            if (alpha[word[i] - 'A'] == 1)
//            {
//                alpha[word[i] - 'A'] = 2;
//                ans++;
//            }
//            else if (alpha[word[i] - 'A'] == 0)
//                alpha[word[i] - 'A'] = -1;
//        }
//    }
//    return ans;
//}
//
//int numberOfSpecialChars(char* word)
//{
//    int fa[26] = { 0 };
//    int fA[26] = { 0 };
//    memset(fa, -1, sizeof(int) * 26);
//    memset(fA, -1, sizeof(int) * 26);
//    for (int i = 0; word[i]; i++)
//    {
//        if (word[i] >= 'a')
//            fa[word[i] - 'a'] = i;
//        else if (fA[word[i] - 'A'] == -1)
//            fA[word[i] - 'A'] = i;
//    }
//    int ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (fa[i] != -1 && fa[i] < fA[i])
//            ans++;
//    }
//    return ans;
//}
//
////1985. 找出数组中的第 K 大整数
//
//int cmp(const void* e1, const void* e2)
//{
//    int m = strlen(*(char**)e1);
//    int n = strlen(*(char**)e2);
//    return m == n ? strcmp(*(char**)e2, *(char**)e1) : n - m;
//}
//char* kthLargestNumber(char** nums, int numsSize, int k)
//{
//    qsort(nums, numsSize, sizeof(char*), cmp);
//    return nums[k - 1];
//}
//
