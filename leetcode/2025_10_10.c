////96. 不同的二叉搜索树
//
//int numTrees(int n)
//{
//    if (n <= 1)
//        return 1;
//
//    int sum = 0;
//    for (int i = 0; i < n / 2; i++)
//    {
//        sum += 2 * numTrees(n - 1 - i) * numTrees(i);
//    }
//    if (n % 2)
//        sum += pow(numTrees((n - 1) / 2), 2);
//    return sum;
//}
//
//int numTrees(int n)
//{
//    int G[n + 1];
//    memset(G, 0, sizeof(G));
//    G[0] = G[1] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 0; j < i; j++)
//            G[i] += G[i - 1 - j] * G[j];
//    }
//    return G[n];
//}
//
////LCR 055. 二叉搜索树迭代器
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
//typedef struct
//{
//    int* nums;
//    int n;
//    int idx;
//} BSTIterator;
//
//int getTreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
//}
//
//void inorder(int* nums, int* n, struct TreeNode* root)
//{
//    if (root == NULL)
//        return;
//
//    inorder(nums, n, root->left);
//    nums[(*n)++] = root->val;
//    inorder(nums, n, root->right);
//}
//
//int* inorderTraversal(int* n, struct TreeNode* root)
//{
//    *n = 0;
//    int* nums = (int*)malloc(sizeof(int) * getTreeSize(root));
//    inorder(nums, n, root);
//    return nums;
//}
//
//BSTIterator* bSTIteratorCreate(struct TreeNode* root)
//{
//    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
//    obj->nums = inorderTraversal(&(obj->n), root);
//    obj->idx = 0;
//    return obj;
//}
//
//int bSTIteratorNext(BSTIterator* obj)
//{
//    return obj->nums[obj->idx++];
//}
//
//bool bSTIteratorHasNext(BSTIterator* obj)
//{
//    return obj->idx != obj->n;
//}
//
//void bSTIteratorFree(BSTIterator* obj)
//{
//    free(obj->nums);
//    free(obj);
//}
//
///**
// * Your BSTIterator struct will be instantiated and called as such:
// * BSTIterator* obj = bSTIteratorCreate(root);
// * int param_1 = bSTIteratorNext(obj);
//
// * bool param_2 = bSTIteratorHasNext(obj);
//
// * bSTIteratorFree(obj);
//*/
//
////LCR 054. 把二叉搜索树转换为累加树
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
//void dfs(struct TreeNode* root, int* sum)
//{
//    if (root == NULL)
//        return;
//
//    dfs(root->right, sum);
//    *sum += root->val;
//    root->val = *sum;
//    dfs(root->left, sum);
//}
//
//struct TreeNode* convertBST(struct TreeNode* root)
//{
//    int sum = 0;
//    dfs(root, &sum);
//    return root;
//}
//
////1557. 可以到达所有点的最少点数目
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize)
//{
//    //只需找出入度为0的点
//    bool into[n];
//    memset(into, 0, sizeof(into));
//    for (int i = 0; i < edgesSize; i++)
//    {
//        into[edges[i][1]] = 1;
//    }
//    int* ans = (int*)malloc(sizeof(int) * n);
//    int idx = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (into[i])
//            continue;
//
//        ans[idx++] = i;
//    }
//    *returnSize = idx;
//    return ans;
//}
//
