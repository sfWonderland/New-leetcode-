////837. 新 21 点
//
//double dfs(int pt, int k, int n, int maxPts, double* cache)
//{
//    if (pt >= k)
//        return pt <= n;
//
//    if (cache[pt] != -1)
//        return cache[pt];
//    double num = 0;
//    for (int i = pt + 1; i <= pt + maxPts; i++)
//    {
//        if (cache[i] == -1)
//            cache[i] = dfs(i, k, n, maxPts, cache);
//        num += cache[i] / maxPts;
//    }
//    cache[pt] = num;
//    return num;
//}
//double new21Game(int n, int k, int maxPts)
//{
//    double* cache = (double*)malloc(sizeof(double) * (k + maxPts));
//    for (int i = 0; i < k + maxPts; i++)
//    {
//        cache[i] = -1;
//    }
//    double t = dfs(0, k, n, maxPts, cache);
//    return t;
//}
//
//double new21Game(int n, int k, int maxPts)
//{
//    if (n >= maxPts + k - 1)
//        return 1;
//    double f[k + maxPts];
//    for (int i = k; i <= n; i++) f[i] = 1;
//    for (int i = n + 1; i < k + maxPts; i++) f[i] = 0;
//    for (int i = k - 1; i >= 0; i--)
//    {
//        f[i] = 0;
//        for (int j = i + 1; j <= i + maxPts; j++)
//            f[i] += f[j] / maxPts;
//    }
//    return f[0];
//}
//
//double new21Game(int n, int k, int maxPts)
//{
//    if (n >= maxPts + k - 1)
//        return 1;
//    double f[k + maxPts];
//    double d = 0;
//    for (int i = k + maxPts - 1; i >= 0; i--)
//    {
//        if (i >= k)
//        {
//            f[i] = i <= n;
//            d += f[i];
//            continue;
//        }
//
//        f[i] = d / maxPts;
//        d += f[i] - f[i + maxPts];
//    }
//    return f[0];
//}
//
//double new21Game(int n, int k, int maxPts)
//{
//    if (n >= maxPts + k - 1)
//        return 1;
//    double f[k + maxPts];
//    double d = 0;
//    for (int i = n; i >= 0; i--)
//    {
//        f[i] = i >= k ? 1 : d / maxPts;
//        d += f[i];
//
//        if (i <= n - maxPts)
//            d -= f[i + maxPts];
//    }
//    return f[0];
//}
//
////2583. 二叉树中的第 K 大层和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int cmp(const void* a, const void* b)
//{
//    long long x = *(long long*)b, y = *(long long*)a;
//    return x > y ? 1 : -1;
//}
//long long kthLargestLevelSum(struct TreeNode* root, int k)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
//    long long ans[100000];
//    int front = 0, rear = 0, n = 0;
//    queue[rear++] = root;
//    while (rear > front)
//    {
//        long long sum = 0;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            sum = sum + queue[i]->val;
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//        ans[n++] = sum;
//    }
//    if (n < k) return -1;
//    qsort(ans, n, sizeof(long long), cmp);
//    return ans[k - 1];
//}
//
////1302. 层数最深叶子节点的和
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int deepestLeavesSum(struct TreeNode* root)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
//    int ans = 0, front = 0, rear = 0;
//    queue[rear++] = root;
//    while (front < rear)
//    {
//        int sum = 0;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            sum += queue[i]->val;
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//        ans = sum;
//    }
//    return ans;
//}
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* root, int d, int* maxDepth, int* ans)
//{
//    if (root == NULL)
//        return;
//
//    if (d > *maxDepth)
//    {
//        *ans = root->val;
//        *maxDepth = d;
//    }
//    else if (d == *maxDepth)
//        *ans += root->val;
//
//    dfs(root->left, d + 1, maxDepth, ans);
//    dfs(root->right, d + 1, maxDepth, ans);
//}
//int deepestLeavesSum(struct TreeNode* root)
//{
//    int maxDepth = -1, ans = 0;
//    dfs(root, 0, &maxDepth, &ans);
//    return ans;
//}
//
////1609. 奇偶树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isEvenOddTree(struct TreeNode* root)
//{
//    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
//    int front = 0, rear = 0;
//    bool even = 0;
//    queue[rear++] = root;
//    while (front < rear)
//    {
//        int x = even ? INT_MAX : INT_MIN;
//        int start = front;
//        front = rear;
//        for (int i = start; i < front; i++)
//        {
//            int t = queue[i]->val;
//            if (t & 1 ^ even)
//            {
//                if (even) { if (t < x) x = t; else return false; }
//                else { if (t > x) x = t; else return false; }
//            }
//            else
//                return false;
//
//            if (queue[i]->left) queue[rear++] = queue[i]->left;
//            if (queue[i]->right) queue[rear++] = queue[i]->right;
//        }
//        even ^= 1;
//    }
//    return true;
//}
//
