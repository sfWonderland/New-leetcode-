//// 1448. 统计二叉树中好节点的数目
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int ans;
//void dfs(struct TreeNode* node, int mx)
//{
//    if (node->val >= mx)
//    {
//        mx = node->val;
//        ans++;
//    }
//    if (node->left) dfs(node->left, mx);
//    if (node->right) dfs(node->right, mx);
//}
//int goodNodes(struct TreeNode* root)
//{
//    ans = 0;
//    dfs(root, root->val);
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
//int ans;
//void dfs(struct TreeNode* node, int mx)
//{
//    if (node == NULL) return;
//    if (node->val >= mx)
//    {
//        mx = node->val;
//        ans++;
//    }
//    dfs(node->left, mx);
//    dfs(node->right, mx);
//}
//int goodNodes(struct TreeNode* root)
//{
//    ans = 0;
//    dfs(root, root->val);
//    return ans;
//}
//
//// 1315. 祖父节点值为偶数的节点和 
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int ans;
//void dfs(struct TreeNode* node, bool fa, bool gfa)
//{
//    if (node == NULL) return;
//    ans += gfa ? node->val : 0;
//    bool cur = (node->val % 2) == 0;
//    dfs(node->left, cur, fa);
//    dfs(node->right, cur, fa);
//}
//int sumEvenGrandparent(struct TreeNode* root)
//{
//    ans = 0;
//    dfs(root, false, false);
//    return ans;
//}
//
//// 988. 从叶结点开始的最小字符串
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* smallestFromLeaf(struct TreeNode* root)
//{
//    char* res = (char*)malloc(sizeof(char) * 8501);
//    res[0] = '~'; res[1] = '\0';
//    int capacity = 64;
//    char* path = (char*)malloc(sizeof(char) * capacity);
//    int pathSize = 0;
//    void dfs(struct TreeNode* node)
//    {
//        if (node == NULL) return;
//        path[pathSize++] = 'a' + node->val;
//        if (pathSize >= capacity - 1)
//        {
//            capacity *= 2;
//            path = realloc(path, sizeof(char) * capacity);
//        }
//        path[pathSize] = '\0';
//        if (!node->left && !node->right)
//        {
//            path[pathSize] = '\0';
//            reverse(path, 0, pathSize - 1);
//            if (strcmp(path, res) < 0)
//                strcpy(res, path);
//            reverse(path, 0, pathSize - 1);
//        }
//        else
//        {
//            if (node->left) dfs(node->left);
//            if (node->right) dfs(node->right);
//        }
//        pathSize--;
//    }
//    dfs(root);
//    return res;
//}
//
//// 1026. 节点与其祖先之间的最大差值
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int ans;
//void dfs(struct TreeNode* node, int mx, int mn)
//{
//    if (node == NULL) return;
//    mx = fmax(mx, node->val);
//    mn = fmin(mn, node->val);
//    ans = fmax(ans, mx - mn);
//    dfs(node->left, mx, mn);
//    dfs(node->right, mx, mn);
//}
//int maxAncestorDiff(struct TreeNode* root)
//{
//    ans = 0;
//    dfs(root, -1, 100001);
//    return ans;
//}
//
