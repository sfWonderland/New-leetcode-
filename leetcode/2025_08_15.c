////236. 二叉树的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == NULL || root == p || root == q)
//        return root;
//    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left && right)
//        return root;
//
//    return left ? left : right;
//}
//
////235. 二叉搜索树的最近公共祖先
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
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
//{
//    if (root == p || root == q)
//        return root;
//
//    int x = root->val;
//    int a = p->val;
//    int b = q->val;
//    if (x > a && x > b)
//        return lowestCommonAncestor(root->left, p, q);
//    if (x < a && x < b)
//        return lowestCommonAncestor(root->right, p, q);
//
//    return root;
//}
//
////1123. 最深叶节点的最近公共祖先
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return fmax(dfs(root->left), dfs(root->right)) + 1;
//}
//struct TreeNode* postorder(struct TreeNode* root, int i, int depth)
//{
//    if (root == NULL || i == depth)
//        return root;
//
//    struct TreeNode* left = postorder(root->left, i + 1, depth);
//    struct TreeNode* right = postorder(root->right, i + 1, depth);
//
//    if (left && right)
//        return root;
//    return left ? left : right;
//}
//struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
//{
//    int n = dfs(root);
//    return postorder(root, 1, n);
//}
//
////2096. 从二叉树一个节点到另一个节点每一步的方向
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int startValue, int destValue)
//{
//    if (root == NULL || root->val == startValue || root->val == destValue)
//        return root;
//
//    struct TreeNode* left = lowestCommonAncestor(root->left, startValue, destValue);
//    struct TreeNode* right = lowestCommonAncestor(root->right, startValue, destValue);
//
//    if (left && right)
//        return root;
//
//    return left ? left : right;
//}
//struct TreeNode* dfs(struct TreeNode* root, int n, bool start, char* ans, int* t)
//{
//    if (root == NULL || root->val == n)
//        return root;
//
//    struct TreeNode* left = dfs(root->left, n, start, ans, t);
//    struct TreeNode* right = dfs(root->right, n, start, ans, t);
//    if (left)
//    {
//        ans[(*t)++] = start ? 'U' : 'L';
//        return left;
//    }
//    else if (right)
//    {
//        ans[(*t)++] = start ? 'U' : 'R';
//        return right;
//    }
//    return NULL;
//}
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* getDirections(struct TreeNode* root, int startValue, int destValue)
//{
//    struct TreeNode* anc = lowestCommonAncestor(root, startValue, destValue);
//    char* ans = (char*)malloc(sizeof(char) * 100005);
//    int t = 0;
//    dfs(anc, startValue, 1, ans, &t);
//    int tmp = t;
//    dfs(anc, destValue, 0, ans, &t);
//    reverse(ans, tmp, t - 1);
//    ans[t] = '\0';
//    return ans;
//}
//
