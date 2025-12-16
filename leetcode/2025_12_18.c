////783. 二叉搜索树节点最小距离
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int pre, mn;
//void dfs(struct TreeNode* node)
//{
//    if (node == NULL)
//        return;
//
//    dfs(node->left);
//    mn = fmin(mn, node->val - pre);
//    pre = node->val;
//    dfs(node->right);
//}
//int minDiffInBST(struct TreeNode* root)
//{
//    pre = -100001;
//    mn = 100000;
//    dfs(root);
//    return mn;
//}
//
////661. 图片平滑器
//
///**
// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
// */
//int row, col;
//int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
//int dy[8] = { -1, 0, 1, -1, 0, 1, 1, -1 };
//int dfs(int** img, int x, int y)
//{
//    int sum = img[x][y];
//    int n = 1;
//    for (int i = 0; i < 8; i++)
//    {
//        int mx = x + dx[i];
//        int my = y + dy[i];
//        if (mx < 0 || mx >= row || my < 0 || my >= col)
//            continue;
//
//        sum += img[mx][my];
//        n++;
//    }
//    return sum / n;
//}
//int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes)
//{
//    row = imgSize;
//    col = imgColSize[0];
//    int** ans = (int**)malloc(sizeof(int*) * row);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
//    for (int i = 0; i < row; i++)
//    {
//        ans[i] = (int*)malloc(sizeof(int) * col);
//        (*returnColumnSizes)[i] = col;
//        for (int j = 0; j < col; j++)
//        {
//            ans[i][j] = dfs(img, i, j);
//        }
//    }
//    *returnSize = row;
//    return ans;
//}
//
////572. 另一棵树的子树
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool dfs(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if (root == NULL)
//        return subRoot == NULL;
//    if (subRoot == NULL)
//        return false;
//    if (root->val != subRoot->val)
//        return false;
//
//    bool l = dfs(root->left, subRoot->left);
//    bool r = dfs(root->right, subRoot->right);
//    return l && r;
//}
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if (root == NULL)
//        return false;
//    if (dfs(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
//
////929. 独特的电子邮件地址
//
//typedef struct
//{
//    char* key;
//    UT_hash_handle hh;
//}HashItem;
//int numUniqueEmails(char** emails, int emailsSize)
//{
//    HashItem* address = NULL;
//    HashItem* pEntry = NULL;
//    int ans = 0;
//    for (int i = 0; i < emailsSize; i++)
//    {
//        int n = strlen(emails[i]);
//        char* p = emails[i];
//        char* s = (char*)malloc(sizeof(char) * (n + 1));
//        int pos = 0, j = 0;
//        for (; p[j] != '@' && p[j] != '+'; j++)
//        {
//            if (p[j] == '.')
//                continue;
//
//            s[pos++] = p[j];
//        }
//        while (p[j] != '@')
//            j++;
//
//        for (; j < n; j++)
//        {
//            s[pos++] = p[j];
//        }
//        s[pos] = '\0';
//
//        HASH_FIND_STR(address, s, pEntry);
//        if (pEntry == NULL)
//        {
//            pEntry = (HashItem*)malloc(sizeof(HashItem));
//            pEntry->key = (char*)malloc(sizeof(char) * (pos + 1));
//            memcpy(pEntry->key, s, sizeof(char) * (pos + 1));
//            HASH_ADD_STR(address, key, pEntry);
//            ans++;
//        }
//    }
//    HashItem* tmp = NULL;
//    HASH_ITER(hh, address, pEntry, tmp)
//    {
//        free(pEntry->key);
//        free(pEntry);
//    }
//    return ans;
//}
//
