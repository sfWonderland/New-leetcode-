////1967. 作为子字符串出现在单词中的字符串数目
//
//int numOfStrings(char** patterns, int patternsSize, char* word)
//{
//    int ans = 0;
//    for (int i = 0; i < patternsSize; i++)
//    {
//        if (strstr(word, patterns[i]))
//            ans++;
//    }
//    return ans;
//}
//
////2415. 反转二叉树的奇数层
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* left, struct TreeNode* right, bool odd)
//{
//    if (left == NULL)
//        return;
//    if (odd)
//    {
//        int tmp = left->val;
//        left->val = right->val;
//        right->val = tmp;
//    }
//    dfs(left->left, right->right, !odd);
//    dfs(right->left, left->right, !odd);
//}
//struct TreeNode* reverseOddLevels(struct TreeNode* root)
//{
//    dfs(root->left, root->right, 1);
//    return root;
//}
//
////590. N 叉树的后序遍历
//
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     int numChildren;
// *     struct Node** children;
// * };
// */
//
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//void dfs(struct Node* root, int* ans, int* idx)
//{
//    if (root == NULL)
//        return;
//    for (int i = 0; i < root->numChildren; i++)
//    {
//        dfs(root->children[i], ans, idx);
//    }
//    ans[(*idx)++] = root->val;
//}
//int* postorder(struct Node* root, int* returnSize)
//{
//    int* ans = (int*)malloc(sizeof(int) * 10000);
//    int idx = 0;
//    dfs(root, ans, &idx);
//    *returnSize = idx;
//    return ans;
//}
//
////面试题 05.02. 二进制数转字符串
//
//char* printBin(double num)
//{
//    char* ans = (char*)malloc(sizeof(char) * 9);
//    ans[0] = '0'; ans[1] = '.';
//    for (int i = 0; i < 6; i++)
//    {
//        num *= 2;
//        if (num < 1)
//            ans[i + 2] = '0';
//        else
//        {
//            ans[i + 2] = '1';
//            if (--num == 0)
//            {
//                ans[i + 3] = '\0';
//                return ans;
//            }
//        }
//    }
//    return "ERROR";
//}
//
