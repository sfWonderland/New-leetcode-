////1339. 分裂二叉树的最大乘积
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//const int MOD = 1e9 + 7;
//int maxProduct(struct TreeNode* root)
//{
//    int dfs1(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return 0;
//
//        return root->val + dfs1(root->left) + dfs1(root->right);
//    }
//    int tot = dfs1(root);
//    long long ans = 0;
//    int dfs2(struct TreeNode* root)
//    {
//        if (root == NULL)
//            return 0;
//
//        int sum = root->val + dfs2(root->left) + dfs2(root->right);
//        ans = fmax(ans, 1ll * sum * (tot - sum));
//        return sum;
//    }
//    dfs2(root);
//    return ans % MOD;
//}
//
////2946. 循环移位后的矩阵相似检查    
//
//bool areSimilar(int** mat, int matSize, int* matColSize, int k)
//{
//    int m = matSize, n = matColSize[0];
//    k %= n;
//    int factor = 1;
//    for (int i = 0; i < m; i++)
//    {
//        factor *= -1;
//        for (int j = 0; j < n; j++)
//        {
//            if (mat[i][j] != mat[i][(j + n + factor * k) % n])
//                return false;
//        }
//    }
//    return true;
//}
//
////3101. 交替子数组计数
//
//long long countAlternatingSubarrays(int* nums, int numsSize)
//{
//    // 不定长滑动窗口？
//    long long ans = 0;
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (i > 0 && nums[i] != nums[i - 1])
//            cnt++;
//        else
//            cnt = 1;
//
//        ans += cnt;
//    }
//    return ans;
//}
//
////1366. 通过投票对团队排名
//
//int** cnts;
//int n;
//int cmp(const void* e1, const void* e2)
//{
//    char a = *(char*)e1, b = *(char*)e2;
//    for (int i = 0; i < n; i++)
//    {
//        if (cnts[a - 'A'][i] != cnts[b - 'A'][i])
//            return cnts[a - 'A'][i] - cnts[b - 'A'][i];
//    }
//    return a - b;
//}
//char* rankTeams(char** votes, int votesSize)
//{
//    n = strlen(votes[0]);
//    int m = votesSize;
//    cnts = (int**)malloc(sizeof(int*) * 26);
//    for (int i = 0; i < 26; i++)
//    {
//        cnts[i] = (int*)calloc(sizeof(int), n);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cnts[votes[i][j] - 'A'][j]--;
//        }
//    }
//    char* ans = votes[0];
//    qsort(ans, n, sizeof(char), cmp);
//    return ans;
//}
//
////
//
//int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
//{
//    int m = matrixSize, n = matrixColSize[0];
//    bool check(int x)
//    {
//        int cnt = 0, right = n;
//        for (int i = 0; i < m; i++)
//        {
//            for (; right > 0; right--)
//            {
//                if (matrix[i][right - 1] <= x)
//                {
//                    cnt += right;
//                    break;
//                }
//            }
//            if (cnt >= k)
//                break;
//        }
//        return cnt >= k;
//    }
//    int left = matrix[0][0], right = matrix[m - 1][n - 1];
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (check(mid))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    return left;
//}
//
