////2438. 二的幂数组中查询范围内的乘积
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//#define MOD 1000000007
//long long pow_mod(long long a, long long b) //a ^ b
//{
//    long long res = 1;
//    while (b)
//    {
//        if (b & 1)
//            res = (res * a) % MOD;
//
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return res;
//}
//int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
//{
//    int powers[30];
//    int t = 0, shift = 0;
//    while (n)
//    {
//        int x = n & 1;
//        if (x)
//            powers[t++] = shift;
//        n >>= 1;
//        shift++;
//    }
//    int prefix[31] = { 0 };
//    for (int i = 0; i < t; i++)
//    {
//        prefix[i + 1] = prefix[i] + powers[i];
//    }
//    int* ans = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int t = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
//        ans[i] = pow_mod(2, t);//快速幂修改
//    }
//    *returnSize = queriesSize;
//    return ans;
//}
//
////2476. 二叉搜索树最近节点查询
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
//int count(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return 1 + count(node->left) + count(node->right);
//}
//void dfs(struct TreeNode* node, int* pos, int* arr)
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left, pos, arr);
//    arr[(*pos)++] = node->val;
//    dfs(node->right, pos, arr);
//}
//int** closestNodes(struct TreeNode* root, int* queries, int queriesSize, int* returnSize, int** returnColumnSizes)
//{
//    int tot = count(root);
//    int* arr = (int*)malloc(sizeof(int) * tot);
//    int pos = 0;
//    dfs(root, &pos, arr);
//    int** ans = (int**)malloc(sizeof(int*) * queriesSize);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * queriesSize);
//    for (int i = 0; i < queriesSize; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * 2);
//        (*returnColumnSizes)[i] = 2;
//    }
//    for (int i = 0; i < queriesSize; i++)
//    {
//        int left = 0, right = tot - 1, x = queries[i];
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (arr[mid] == x)
//            {
//                left = right = mid;
//                break;
//            }
//            else if (arr[mid] < x)
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//        ans[i][0] = right < 0 ? -1 : arr[right], ans[i][1] = left > tot - 1 ? -1 : arr[left];
//    }
//    *returnSize = queriesSize;
//    free(arr);
//    return ans;
//}
//
////230. 二叉搜索树中第 K 小的元素
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int count(struct TreeNode* node)
//{
//    if (node == NULL)
//        return 0;
//
//    return 1 + count(node->left) + count(node->right);
//}
//void dfs(struct TreeNode* node, int* pos, int* arr)
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left, pos, arr);
//    arr[(*pos)++] = node->val;
//    dfs(node->right, pos, arr);
//}
//int kthSmallest(struct TreeNode* root, int k)
//{
//    int tot = count(root);
//    int* arr = (int*)malloc(sizeof(int) * tot);
//    int pos = 0;
//    dfs(root, &pos, arr);
//    int ans = arr[k - 1];
//    free(arr);
//    return ans;
//}
//
////1315. 祖父节点值为偶数的节点和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int gf, int f)
//{
//    if (node == NULL)
//        return 0;
//
//    int n = node->val;
//    int next = dfs(node->left, f, n) + dfs(node->right, f, n);
//    return gf & 1 ? next : next + n;
//}
//int sumEvenGrandparent(struct TreeNode* root)
//{
//    return dfs(root, 1, 1);
//}
//
