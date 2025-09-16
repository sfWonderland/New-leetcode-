////29. 两数相除
//
//long long mul(long long a, long long b)
//{
//    long long ans = 0;
//    while (a)
//    {
//        if (a & 1)
//            ans += b;
//
//        b += b;
//        a >>= 1;
//    }
//    return ans;
//}
//int divide(int dividend, int divisor)
//{
//    bool sym = false;
//    long long a = dividend, b = divisor;
//    if ((a < 0 && b > 0) || (a > 0 && b < 0))
//        sym = true;
//    if (a < 0) a = -a;
//    if (b < 0) b = -b;
//    int ans = 0;
//    long long l = 0, r = a;
//    while (l < r)
//    {
//        long long mid = (l + r + 1) >> 1;
//        if (mul(mid, b) > a)
//            r = mid - 1;
//        else
//            l = mid;
//    }
//    r = sym ? -r : r;
//    if (r > INT_MAX)
//        r = INT_MAX;
//    else if (r < INT_MIN)
//        r = INT_MIN;
//    return r;
//}
//
////988. 从叶结点开始的最小字符串
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//void dfs(struct TreeNode* node, int depth, char* tmp, char** ans)
//{
//    if (!node) return;
//    tmp[depth++] = (node->val) + 'a';
//    if (!node->left && !node->right)
//    {
//        tmp[depth] = '\0';
//        reverse(tmp, 0, depth - 1);
//        if (*ans == NULL || strcmp(tmp, *ans) < 0)
//        {
//            strcpy(*ans, tmp);
//        }
//        reverse(tmp, 0, depth - 1);
//    }
//    dfs(node->left, depth, tmp, ans);
//    dfs(node->right, depth, tmp, ans);
//    depth--;
//}
//char* smallestFromLeaf(struct TreeNode* root)
//{
//    if (!root) return strdup("");
//    char* ans = (char*)malloc(sizeof(char) * 8501);
//    char* tmp = (char*)malloc(sizeof(char) * 8501);
//    dfs(root, 0, tmp, &ans);
//    return ans;
//}
//
////563. 二叉树的坡度
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int dfs(struct TreeNode* node, int* ans)
//{
//    if (!node)
//        return 0;
//
//    int a = dfs(node->left, ans);
//    int b = dfs(node->right, ans);
//
//    *ans += abs(a - b);
//    return a + b + node->val;
//}
//int findTilt(struct TreeNode* root)
//{
//    int ans = 0;
//    dfs(root, &ans);
//    return ans;
//}
//
////606. 根据二叉树创建字符串
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void reverse(char* s, int l, int r)
//{
//    while (l < r)
//    {
//        char tmp = s[l];
//        s[l++] = s[r];
//        s[r--] = tmp;
//    }
//}
//void dfs(struct TreeNode* node, int* idx, char* ans)
//{
//    if (!node) return;
//    int x = node->val;
//    if (x)
//    {
//        if (x < 0)
//        {
//            ans[(*idx)++] = '-';
//            x = -x;
//        }
//        int left = *idx;
//        while (x)
//        {
//            ans[(*idx)++] = x % 10 + '0';
//            x /= 10;
//        }
//        reverse(ans, left, (*idx) - 1);
//    }
//    else
//        ans[(*idx)++] = '0';
//
//    if (node->left || node->right)
//    {
//        ans[(*idx)++] = '(';
//        dfs(node->left, idx, ans);
//        ans[(*idx)++] = ')';
//    }
//    if (node->right)
//    {
//        ans[(*idx)++] = '(';
//        dfs(node->right, idx, ans);
//        ans[(*idx)++] = ')';
//    }
//}
//char* tree2str(struct TreeNode* root)
//{
//    char* ans = (char*)malloc(sizeof(char) * 30000);
//    int idx = 0;
//    dfs(root, &idx, ans);
//    ans[idx] = '\0';
//    return ans;
//}
//
