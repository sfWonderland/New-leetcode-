////145. 二叉树的后序遍历
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
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//void postorder(struct TreeNode* root, int* arr, int* n)
//{
//    if (root == NULL)
//        return;
//    postorder(root->left, arr, n);
//    postorder(root->right, arr, n);
//    arr[(*n)++] = root->val;
//}
//int* postorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 100);
//    *returnSize = 0;
//    postorder(root, ans, returnSize);
//    return ans;
//}
//
////168. Excel 表列名称
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char t = s[left];
//        s[left++] = s[right];
//        s[right--] = t;
//    }
//}
//char* convertToTitle(int columnNumber)
//{
//    char* ret = malloc(8);
//    int n = 0;
//    while (columnNumber)
//    {
//        --columnNumber;
//        ret[n++] = columnNumber % 26 + 'A';
//        columnNumber /= 26;
//        //printf("%d ",columnNumber);
//    }
//    ret[n] = '\0';
//    reverse(ret, 0, n - 1);
//    return ret;
//}
//
////222. 完全二叉树的节点个数
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int getHeight(struct TreeNode* root)
//{
//    int height = 0;
//    while (root)
//    {
//        root = root->left;
//        height++;
//    }
//    return height;
//}
//int countNodes(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//    int leftHeight = getHeight(root->left);
//    int rightHeight = getHeight(root->right);
//    if (leftHeight == rightHeight)
//        // 左子树高度 = 右子树高度，则左子树必定是满二叉树
//        return (1 << leftHeight) + countNodes(root->right);
//    else
//        // 左子树高度 > 右子树高度，说明右子树必定是满二叉树
//        return (1 << rightHeight) + countNodes(root->left);
//}
//
////405. 数字转换为十六进制数
//
//void reverse(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = s[left];
//        s[left++] = s[right];
//        s[right--] = tmp;
//    }
//}
//char* toHex(int num)
//{
//    if (num == 0)
//        return "0";
//    char* ans = malloc(9);
//    int n = 0;
//    while (num)
//    {
//        int t = num & 15;
//        ans[n++] = t > 9 ? t + 87 : t + 48;
//        num = (unsigned int)num >> 4;
//    }
//    ans[n] = '\0';
//    reverse(ans, 0, n - 1);
//    return ans;
//}
//
